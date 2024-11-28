In **TensorFlow**, a computational graph is a way of representing a series of mathematical operations that are executed in a specific sequence. These graphs allow TensorFlow to optimize the execution of operations, which is particularly useful for complex models involving many computations, such as deep neural networks. TensorFlow was originally designed to work with static computational graphs, where the graph is defined first, and then executed. 

In recent versions, TensorFlow has evolved to support **Eager Execution**, which allows for more intuitive, immediate computation (like using Python). However, forming graphs is still a core concept, particularly for performance optimization and deployment in production environments.

### Key Concepts of TensorFlow Computational Graphs:
1. **Nodes**: Represent operations (e.g., addition, multiplication) or variables (e.g., weights, inputs).
2. **Edges**: Represent the flow of data (tensors) between operations.
3. **Tensors**: Multi-dimensional arrays or matrices that flow through the graph, representing data.
4. **Sessions**: In earlier versions of TensorFlow (pre-2.0), a `Session` was used to execute the graph. In TensorFlow 2.0+, eager execution is the default, so graphs are executed immediately as operations are called.

### Steps to Form a Graph in TensorFlow 1.x (Static Graphs)
In TensorFlow 1.x, you explicitly define a computational graph, and then execute it inside a session. Here’s a basic example:

#### Step 1: Import TensorFlow

```python
import tensorflow as tf
```

#### Step 2: Define the Graph

In TensorFlow 1.x, you would define operations as part of a graph. You explicitly create nodes for the operations.

```python
# Create a graph
graph = tf.Graph()

# Define a graph within a context manager
with graph.as_default():
    # Placeholder for input
    x = tf.placeholder(tf.float32, shape=[None], name="x")
    
    # A simple operation (y = 2 * x + 3)
    y = 2 * x + 3
```

#### Step 3: Create a Session

After defining the graph, you create a session that will execute the graph operations.

```python
# Create a session to run the graph
with tf.Session(graph=graph) as sess:
    # Define some data to feed into the placeholder
    input_data = [1, 2, 3, 4]
    
    # Run the graph, feeding data into the placeholder
    result = sess.run(y, feed_dict={x: input_data})
    
    print("Result of y = 2 * x + 3: ", result)
```

### TensorFlow 2.x: Eager Execution (Dynamic Graphs)
Starting from TensorFlow 2.x, **eager execution** is enabled by default, which means you can define and run operations immediately without explicitly creating a graph and session. This is much more intuitive and Pythonic for quick experimentation.

Here's an example of forming a graph using eager execution:

#### Step 1: Import TensorFlow

```python
import tensorflow as tf
```

#### Step 2: Define the Graph and Operations

In eager execution, you don't need to manually build a graph; you can just define operations directly and execute them.

```python
# Define a simple operation: y = 2 * x + 3
x = tf.constant([1, 2, 3, 4], dtype=tf.float32)
y = 2 * x + 3

print("Result of y = 2 * x + 3: ", y.numpy())
```

In TensorFlow 2.x, **TensorFlow automatically uses eager execution**, which allows operations to be executed immediately. The result is a more straightforward and intuitive approach, especially for testing and prototyping.

### Forming a Graph for More Complex Models

Even though TensorFlow 2.x defaults to eager execution, **graph mode** (using `tf.function`) is still available for performance optimization when you are ready to deploy a model. The `tf.function` decorator converts Python functions into TensorFlow graphs, allowing TensorFlow to optimize the execution for better performance.

#### Step 1: Define a Function and Convert It into a Graph

You can define your function normally, and then use `tf.function` to convert it into a computational graph.

```python
@tf.function
def model(x):
    return 2 * x + 3

# Now calling model will run in graph mode
x = tf.constant([1, 2, 3, 4], dtype=tf.float32)
y = model(x)

print("Result of y = 2 * x + 3: ", y.numpy())
```

Here, TensorFlow will optimize the operations by converting the Python function into a graph, which is faster for repeated use or deployment.

### Advantages of Forming Graphs:
1. **Performance Optimization**: TensorFlow can optimize the execution by rearranging operations, parallelizing computations, and more.
2. **Deployment**: Graphs can be saved, serialized, and exported for serving models in production.
3. **Portability**: TensorFlow graphs are platform-independent, meaning they can be executed on various devices (e.g., CPUs, GPUs, TPUs).

### Summary:
- In **TensorFlow 1.x**, graphs were explicitly created, and execution was done in a `Session`.
- In **TensorFlow 2.x**, **eager execution** is the default, which allows operations to run immediately. However, you can still define and optimize a graph using `tf.function`.
- **Graphs** are essential for performance and deployment, especially in production, where TensorFlow can optimize graph execution for different hardware backends (e.g., GPUs, TPUs).

Although TensorFlow 2.x's eager execution provides flexibility, forming and working with computational graphs remains a powerful tool for optimizing and deploying machine learning models efficiently.
