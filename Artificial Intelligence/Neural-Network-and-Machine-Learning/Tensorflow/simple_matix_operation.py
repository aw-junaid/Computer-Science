# Import the TensorFlow library
import tensorflow as tf

# Create a constant tensor 'x' with integer values
x = tf.constant([[2, 5, 3, -5],[0, 3,-2, 5],[4, 3, 5, 3],[6, 1, 4, 0]])

# Create a constant tensor 'y' with integer values
y = tf.constant([[4, -7, 4, -3, 4],[6, 4,-7, 4, 7],[2, 3, 2, 1, 4],[1, 5, 5, 5, 2]])

# Create a constant tensor 'floatx' with floating-point values
floatx = tf.constant([[2., 5., 3., -5.],[0., 3.,-2., 5.],[4., 3., 5., 3.],[6., 1., 4., 0.]])

# Transpose tensor 'x'
transposed_x = tf.transpose(x).numpy()

print(transposed_x)
