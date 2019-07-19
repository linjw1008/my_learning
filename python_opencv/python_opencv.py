import numpy as np
import cv2

cap = cv2.VideoCapture('E:\迅雷下载\爱、死亡与机器人.Love.Death.and.Robots.S01E01.中英字幕.WEBrip.720P-人人影视.mp4')

while(True):
    ret, image = cap.read()

    img_color = cv2.cvtColor(image, 0)

    cv2.imshow('window', img_color)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()

cv2.destoryAllWindows()
