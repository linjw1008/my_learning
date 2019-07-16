import os
import cv2
import numpy as np
from multiprocessing import Pool, Queue
from threading import Thread
import tensorflow as tf

# 多线程读取视频
class WebcamVideoStream(object):
    def __init__(self, src, width, height):
        self.stream = cv2.VideoCapture(src)
        self.stream.set(cv2.CAP_PROP_FRAME_WIDTH, width)
        self.stream.set(cv2.CAP_PROP_FRAME_HEIGHT, height)
        (self.grabbed, self.frame) = self.stream.read()

        self.stopped = False

    def start(self):
        Thread(target = self.update, args = ()).start()
        return self
    
    def update(self):
        while True:
            if self.stopped:
                return
            (self.grabbed, self.frame) = self.stream.read()
    
    def read(self):
        return self.frame

    def stop(self):
        self.stopped = True

# 配置参数
class configs(object):
    def __init__(self):
        self.num_workers = 1
        self.queue_size = 4
        self.video_source = 0
        self.width = 720
        self.height = 490

args = configs()

# 多进程加载物体识别模型
def worker(frame_q, result_q):
    image = frame_q.get()
    
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
        print('use cpu')

    # 载入图
    with tf.gfile.FastGFile('output_graph.pb', 'rb') as f:
        graph_def = tf.GraphDef()
        graph_def.ParseFromString(f.read())
        tf.import_graph_def(graph_def, name = '')


    gpu_options = tf.GPUOptions(per_process_gpu_memory_fraction=0.5)

    with tf.Session(config=tf.ConfigProto(gpu_options=gpu_options)) as sess:
        softmax_tensor = sess.graph.get_tensor_by_name("final_result:0")

        while(True):
            image_ = tf.image.encode_jpeg(image).eval()
            predictions = sess.run(softmax_tensor, {'DecodeJpeg/contents:0': image_})
            predictions = np.squeeze(predictions)
            top_k = predictions.argsort()[::-1]
            for node_id in top_k:
                uid = id_to_string(node_id, uid_to_human)
                score = predictions[node_id]
                print('%s (score = %.5f)' % (uid, score))
            print('------------------')
            result = id_to_string(top_k[0], uid_to_human)
            result_q.put(result)
    
    print("Closing sess. %s" % os.getpid())
    sess.close()                


if __name__ == "__main__":
    frame_q = Queue(maxsize = args.queue_size)
    result_q = Queue(maxsize = args.queue_size)
    pool = Pool(args.num_workers, worker, (frame_q, result_q))

    '''
    video_capture = WebcamVideoStream(src = args.video_source,
                                        width = args.width,
                                        height = args.height).start()
    '''

    video_capture = cv2.VideoCapture('http://admin:admin@192.168.1.109:8081')

    i = 0;
    result = 0
    while True:
        i = i+1;
        ret, frame = video_capture.read()
        
        if(i == 20):
            frame_q.put(frame)
            result = result_q.get()
            i = 0;

        #cv2.imshow('Video', frame)
        print("The result is %s." % result)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    pool.terminate()
    video_capture.stop()
    cv2.destroyAllWindows()
