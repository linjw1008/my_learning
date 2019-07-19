import time
import cv2
from multiprocessing import Pool, Queue
from vision import camera
from trash import trashDetect
from trash import trashType

# 配置参数
class configs(object):
    def __init__(self):
        #self.src = 'http://admin:admin@192.168.0.102:8081'
        self.src = 'rtsp://admin:3764141801wei@192.168.0.101:554/Streaming/Channels/1'
        self.num_workers = 3
        self.queue_size = 10
        self.video_source = 0
        self.width = 720
        self.height = 490
        self.type_dir_en = 'D:\GitHub\my_learning\image_sort/trash_type.txt'
        self.type_dir_cn = 'D:\GitHub\my_learning\image_sort/trash_type_in_Chinese.txt'
        self.save_video_dir = 'D:\GitHub\my_learning\image_sort'
        self.save_video_name = 'result.avi'

if __name__ == "__main__":
    args = configs()
    frame_q = Queue(maxsize = args.queue_size)
    result_q = Queue(maxsize = args.queue_size)
    pool = Pool(args.num_workers, trashDetect.worker, (frame_q, result_q, args.type_dir_en, args.type_dir_cn))

    #读取视频
    video_capture = camera.WebcamVideoStream(src=args.src).start()
    #保存视频
    fourcc = cv2.VideoWriter_fourcc(*'XVID')
    video_out = cv2.VideoWriter(args.save_video_dir + '/' + args.save_video_name, fourcc, 20.0, (640,480))

    i = 0
    detect = False
    record = False
    screenshot = False
    while True:
        
        i = i+1

        if(i == 20):
            begin_time = time.time()

            #ret, frame = video_capture.read()
            frame = video_capture.read()
            
            if(detect):            
                frame_q.put(frame)
                result, trash_type, frame = result_q.get()
                print("The result is %s." % result)
                print("The type is %s." % trash_type)

            i = 0;
            cv2.imshow('Video', frame)
            
            if(record):
                video_out.write(frame)
            
            if(screenshot):
                cv2.imwrite('./' + str(begin_time) +'.jpg', frame)
                screenshot = False
            
            end_time = time.time();
            
            if(detect):
                fps = 1 / (end_time - begin_time)
                print("FPS: %s....\n" % fps)


        k = cv2.waitKey(1) & 0xFF
        if k == ord('d'):
            detect = ~detect
        if k == ord('r'):
            record = ~record
        if k == ord('s'):
            screenshot = True
        if k == ord('q'):
            break

    pool.terminate()
    video_capture.stop()
    video_out.release()
    cv2.destroyAllWindows()
