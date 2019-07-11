import tensorflow as tf
import os
import numpy as np
import re
from PIL import Image
import matplotlib.pyplot as plt
import cv2

# cap = cv2.VideoCapture('E:\迅雷下载\爱、死亡与机器人.Love.Death.and.Robots.S01E01.中英字幕.WEBrip.720P-人人影视.mp4')
# cap = cv2.VideoCapture('D:\GitHub\my_learning\image_sort\data_set/test_set\WeChat_20190711214631.mp4')
cap = cv2.VideoCapture('http://admin:admin@192.168.1.113:8081')

if cap.isOpened():
    print('open camera')

image_dir = 'D:\GitHub\my_learning\image_sort\data_set/test_set/chicken.jpg'

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

# 载入图
with tf.gfile.FastGFile('output_graph.pb', 'rb') as f:
    graph_def = tf.GraphDef()
    graph_def.ParseFromString(f.read())
    tf.import_graph_def(graph_def, name = '')


# 会话
'''
while(True):
    ret, image = cap.read()
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

    cv2.imshow('window', image)

    with tf.Session() as sess:
        softmax_tensor = sess.graph.get_tensor_by_name("final_result:0")
        image_data = tf.gfile.FastGFile(image_dir, 'rb').read()
        image_ = tf.image.encode_jpeg(image).eval()
        # print(image_)
        # predictions = sess.run(softmax_tensor, {'DecodeJpeg/contents:0': image_data})
        # size = (image.shape[0], image.shape[1])
        # image = image.resize(size[0], size[1], Image.ANTIALIAS)
        # image_array = np.array(image)[:, :, 0:3]
        predictions = sess.run(softmax_tensor, {'DecodeJpeg/contents:0': image_})
        predictions = np.squeeze(predictions)
        top_k = predictions.argsort()[::-1]
        print(top_k)
        for node_id in top_k:
            uid = id_to_string(node_id, uid_to_human)
            score = predictions[node_id]
            print('%s (score = %.5f)' % (uid, score))
'''

with tf.device('/GPU:0'):
    print('use gpu')

with tf.Session() as sess:
    softmax_tensor = sess.graph.get_tensor_by_name("final_result:0")

    i = 0

    while(True):
        i += 1
        ret, image = cap.read()
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
        cv2.imshow('window', image)
        if i==20:
            image_ = tf.image.encode_jpeg(image).eval()
        # print(image_)
        # predictions = sess.run(softmax_tensor, {'DecodeJpeg/contents:0': image_data})
        # size = (image.shape[0], image.shape[1])
        # image = image.resize(size[0], size[1], Image.ANTIALIAS)
        # image_array = np.array(image)[:, :, 0:3]
            predictions = sess.run(softmax_tensor, {'DecodeJpeg/contents:0': image_})
            predictions = np.squeeze(predictions)
            top_k = predictions.argsort()[::-1]
            print(top_k)
            for node_id in top_k:
                uid = id_to_string(node_id, uid_to_human)
                score = predictions[node_id]
                print('%s (score = %.5f)' % (uid, score))
            print('------------------')
            i = 0
 

cap.release()
cv2.destoryAllWindows()