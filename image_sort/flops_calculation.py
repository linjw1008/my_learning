#coding = utf-8
 
import tensorflow as tf
import tensorflow.contrib.slim as slim
from tensorflow.contrib.slim.nets import vgg
 
def stats_graph(graph):
	flops = tf.profiler.profile(graph, options=tf.profiler.ProfileOptionBuilder.float_operation())
	params = tf.profiler.profile(graph, options=tf.profiler.ProfileOptionBuilder.trainable_variables_parameter())
	print('FLOPs: {};    Trainable params: {}'.format(flops.total_float_ops, params.total_parameters))
 
 
def main():
    with tf.gfile.FastGFile('output_graph.pb', 'rb') as f:
        graph_def = tf.GraphDef()
        graph_def.ParseFromString(f.read())
        tf.import_graph_def(graph_def, name = '')

        with tf.Graph().as_default() as graph:
            inputs = tf.placeholder(dtype = tf.float32, shape = [1, 224, 224, 3])
            with slim.arg_scope(vgg.vgg_arg_scope()):
                _, end_points = vgg.vgg_16(inputs, num_classes=1000, is_training=True, dropout_keep_prob=0.5, spatial_squeeze=False, scope='vgg_16')		
            stats_graph(graph)

if __name__ == '__main__':
	main()