import cv2
import multiprocessing
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
        self.num_workers = 2
        self.queue_size = 5
        self.video_source = 0
        self.width = 720
        self.height = 490

args = configs()

# 多进程加载物体识别模型
class worker(input_q, output_q):
    detection_graph = tf.Graph()
    with detection_graph.as_default():
        od_graph_def = tf.GraphDef()
        with tf.gfile.GFile(PATH_TO_CKPT, 'rb') as fid:
            serialized_graph = fid.read()
            od_graph_def.ParseFromString(serialized_graph)
            tf.import_graph_def(od_graph_def, name='')
        sess = tf.Session(graph=detection_graph)
    while True:
        frame = input_q.get()
        output_q.put(detect_objects(frame, sess, detection_graph)) # detect_objects函数 返回一张图片，标记所有被发现的物品
    sess.close()

input_q = Queue(maxsize = args.queue_size)
output_q = Queue(maxsize = args.queue_size)
pool = Pool(args.num_workers, worker, (input_q, output_q))

video_capture = WebcamVideoStream(src = args.video_source,
                                    width = args.width,
                                    height = args.height).start()

while True:
    frame = video_capture.read()
    input_q.put(frame)
    frame = output_q.get()

    cv2.imshow('Video', frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

pool.terminate()
video_capture.stop()
cv2.destroyAllWindows()
