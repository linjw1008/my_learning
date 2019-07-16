import cv2
from threading import Thread

# 多线程读取视频
class WebcamVideoStream(object):
    def __init__(self, src):
        self.stream = cv2.VideoCapture(src)
        self.grabbed, self.frame = self.stream.read()
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