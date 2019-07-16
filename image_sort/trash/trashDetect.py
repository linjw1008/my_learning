import os
import numpy as np
import cv2
import tensorflow as tf
from trash import trashType


# 多进程加载物体识别模型
def worker(frame_q, result_q, trash_type_dir):

    
    trashtype = trashType.trashType(trash_type_dir)    


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


    #gpu_options = tf.GPUOptions(per_process_gpu_memory_fraction=0.5)
#gpu_options=gpu_options, 
    config = tf.ConfigProto()
    config.gpu_options.per_process_gpu_memory_fraction = 0.1
    
    with tf.Session(config = config) as sess:
        softmax_tensor = sess.graph.get_tensor_by_name("final_result:0")

        while(True):
            image = frame_q.get()
            print("1")
            image_ = tf.image.encode_jpeg(image).eval()
            print("2")
            predictions = sess.run(softmax_tensor, {'DecodeJpeg/contents:0': image_})
            predictions = np.squeeze(predictions)
            top_k = predictions.argsort()[::-1]
            for node_id in top_k:
                uid = id_to_string(node_id, uid_to_human)
                score = predictions[node_id]
                print('%s (score = %.5f)' % (uid, score))
            print('------------------')
            result = id_to_string(top_k[0], uid_to_human)
            trash_type = trashtype.getTrashType(result)

            # 标注图片
            blue = (255, 0, 0)
            font = cv2.FONT_HERSHEY_COMPLEX
            cv2.putText(image, str(result), (int((image.shape)[0]/2), int((image.shape)[1]/2)), font, 2, blue, 1)
            cv2.putText(image, str(trash_type), (int((image.shape)[0]/2), int((image.shape)[1]/2)+20), font, 2, blue, 1)
            
            result_out = (result, trash_type, image)
            result_q.put(result_out)
            
    
    print("Closing sess. %s" % os.getpid())
    sess.close()               