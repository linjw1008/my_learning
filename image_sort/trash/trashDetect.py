import os
import numpy as np
import cv2
from PIL import Image, ImageDraw, ImageFont
import tensorflow as tf
from trash import trashType


# 多进程加载物体识别模型
def worker(frame_q, result_q, trash_type_dir_en, trash_type_dir_cn):

    
    trashtype = trashType.trashType(trash_type_dir_en, trash_type_dir_cn)    

    trash_type_logo = {}
    trash_type_logo_alpha = {}
    trash_type_logo['recyclable trash'] = Image.open('./trash/可回收物.png').resize((150, 150))
    trash_type_logo['dry trash'] = Image.open('./trash/干垃圾.png').resize((150, 150))
    trash_type_logo['wet trash'] = Image.open('./trash/湿垃圾.png').resize((150, 150))
    trash_type_logo['harmful trash'] = Image.open('./trash/有害垃圾.png').resize((150, 150))
    _, _, _, trash_type_logo_alpha['recyclable trash'] = trash_type_logo['recyclable trash'].split()
    _, _, _, trash_type_logo_alpha['dry trash'] = trash_type_logo['dry trash'].split()
    _, _, _, trash_type_logo_alpha['wet trash'] = trash_type_logo['wet trash'].split()
    _, _, _, trash_type_logo_alpha['harmful trash'] = trash_type_logo['harmful trash'].split()

    def id_to_string(node_id, uid):
        if node_id not in uid:
            return ''
        return uid[node_id]

    # 导入标签
    lines = tf.gfile.GFile('output_labels.txt').readlines()
    uid_to_human = {}
    for uid, line in enumerate(lines):
        line  = line.strip('\n')
        uid_to_human[uid] = line

    with tf.device('/GPU:0'):
        print('use Gpu')

    # 载入图
    with tf.gfile.FastGFile('output_graph.pb', 'rb') as f:
        graph_def = tf.GraphDef()
        graph_def.ParseFromString(f.read())
        tf.import_graph_def(graph_def, name = '')

    config = tf.ConfigProto()
    config.gpu_options.per_process_gpu_memory_fraction = 0.1
    
    with tf.Session(config = config) as sess:
        softmax_tensor = sess.graph.get_tensor_by_name("final_result:0")

        while(True):
            image = frame_q.get()
            image_resized = cv2.resize(image, (512, 384))
            image_ = tf.image.encode_jpeg(image_resized).eval()
            
            predictions = sess.run(softmax_tensor, {'DecodeJpeg/contents:0': image_})
            predictions = np.squeeze(predictions)
            top_k = predictions.argsort()[::-1]
            for node_id in top_k:
                uid = id_to_string(node_id, uid_to_human)
                score = predictions[node_id]
                print('%s (score = %.5f)' % (uid, score))
            print('------------------')
            trash_name_en = id_to_string(top_k[0], uid_to_human)
            trash_type_en = trashtype.getTrashType(trash_name_en)
            trash_name_cn = trashtype.getTrashNameInChinese(trash_name_en)
            trash_type_cn = trashtype.getTrashTypeInChinese(trash_type_en)

            # 标注图片
            
            red = (255, 0, 0)
            '''
            font = cv2.FONT_HERSHEY_COMPLEX
            cv2.putText(image, str(trash_name_cn), (int((image.shape)[0]/2), int((image.shape)[1]/2)), font, 1, blue, 1)
            cv2.putText(image, str(trash_type_cn), (int((image.shape)[0]/2), int((image.shape)[1]/2)+20), font, 1, blue, 1)
            #cv2.putText(image, str(trash_name_cn), (int((image.shape)[0]/2), int((image.shape)[1]/2)+20), font, 1, blue, 1)
            '''
            image = Image.fromarray(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
            draw = ImageDraw.Draw(image)
            fontText = ImageFont.truetype("font/simsun.ttc", 30, encoding="utf-8")
            draw.text((40, 380), trash_name_cn, red, font=fontText)
            image.paste(trash_type_logo[trash_type_en],(480, 320),mask = trash_type_logo_alpha[trash_type_en])
            image = cv2.cvtColor(np.asarray(image), cv2.COLOR_RGB2BGR)

            result_out = (trash_name_en, trash_type_en, image)
            result_q.put(result_out)
            
    
    print("Closing sess. %s" % os.getpid())
    sess.close()               