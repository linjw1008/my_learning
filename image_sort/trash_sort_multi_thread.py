import time
import cv2
from multiprocessing import Pool, Queue
from vision import camera
from trash import trashDetect
from trash import trashType

# 配置参数
class configs(object):
    def __init__(self):
        self.src = 'http://admin:admin@192.168.0.102:8081'
        self.num_workers = 3
        self.queue_size = 10
        self.video_source = 0
        self.width = 720
        self.height = 490
        self.type_dir = 'D:\GitHub\my_learning\image_sort/trash_type.txt'

args = configs()


if __name__ == "__main__":
    frame_q = Queue(maxsize = args.queue_size)
    result_q = Queue(maxsize = args.queue_size)
    pool = Pool(args.num_workers, trashDetect.worker, (frame_q, result_q, args.type_dir))

    video_capture = camera.WebcamVideoStream(src=args.src).start()


    i = 0
    while True:
        
        i = i+1

        if(i == 20):
            begin_time = time.time()

            #ret, frame = video_capture.read()
            frame = video_capture.read()
            frame_q.put(frame)
            result, trash_type, frame = result_q.get()
            i = 0;
            cv2.imshow('Video', frame)

            print("The result is %s." % result)
            print("The type is %s." % trash_type)

            end_time = time.time();
            
            fps = 1 / (end_time - begin_time)
            
            print("FPS: %s....\n" % fps)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    pool.terminate()
    video_capture.stop()
    cv2.destroyAllWindows()
