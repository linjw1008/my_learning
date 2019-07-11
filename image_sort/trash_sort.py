import tensorflow as tf
import os
import numpy as np
import re
from PIL import Image
import matplotlib.pyplot as plt

image_dir = 'D:\GitHub\my_learning\image_sort\data_set/test_set/chicken.jpg'

def id_to_string(node_id, uid):
    if node_id not in uid:
        return ''
    return uid[node_id]

lines = tf.gfile.GFile('output_labels.txt').readlines()
uid_to_human = {}
for uid, line in enumerate(lines):
    line  = line.strip('\n')
    uid_to_human[uid] = line

with tf.gfile.FastGFile('output_graph.pb', 'rb') as f:
    graph_def = tf.GraphDef()
    graph_def.ParseFromString(f.read())
    tf.import_graph_def(graph_def, name = '')


# tensor_name_list = [tensor.name for tensor in tf.get_default_graph().as_graph_def().node]
# for tensor_name in tensor_name_list:
#     print(tensor_name, '\n')


with tf.Session() as sess:
    softmax_tensor = sess.graph.get_tensor_by_name("final_result:0")
    image_data = tf.gfile.FastGFile(image_dir, 'rb').read()
    predictions = sess.run(softmax_tensor, {'DecodeJpeg/contents:0': image_data})
    predictions = np.squeeze(predictions)
    top_k = predictions.argsort()[::-1]
    print(top_k)
    for node_id in top_k:
        uid = id_to_string(node_id, uid_to_human)
        score = predictions[node_id]
        print('%s (score = %.5f)' % (uid, score))



