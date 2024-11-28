The **XOR problem** is a classic example used to demonstrate the capabilities of neural networks. It is a binary classification task where the output is 1 if the inputs are different (i.e., one is 0 and the other is 1), and 0 if the inputs are the same (i.e., both are 0 or both are 1). The XOR function is not linearly separable, making it an ideal problem to demonstrate the power of neural networks in learning non-linear decision boundaries.

### XOR Truth Table:

| Input 1 | Input 2 | Output (XOR) |
|---------|---------|--------------|
| 0       | 0       | 0            |
| 0       | 1       | 1            |
| 1       | 0       | 1            |
| 1       | 1       | 0            |

### Neural Network Architecture:
To solve the XOR problem, we typically use a **Multi-Layer Perceptron (MLP)**, which has:
- **2 input nodes** (for Input 1 and Input 2),
- **1 hidden layer** with a sufficient number of neurons to learn the non-linear mapping (usually 2 to 3 neurons),
- **1 output node** (binary output for XOR).

### Step-by-Step Implementation in TensorFlow:

We will use TensorFlow and Keras to implement a simple neural network to solve the XOR problem.

#### Step 1: Import Libraries

```python
import numpy as np
import tensorflow as tf
from tensorflow.keras import Sequential
from tensorflow.keras.layers import Dense
```

#### Step 2: Define the XOR Dataset

The XOR dataset consists of 4 training samples with 2 inputs and a corresponding output for each input pair.

```python
# XOR input data (2 inputs)
X = np.array([[0, 0],  # Input 1: 0, Input 2: 0
              [0, 1],  # Input 1: 0, Input 2: 1
              [1, 0],  # Input 1: 1, Input 2: 0
              [1, 1]]) # Input 1: 1, Input 2: 1

# XOR output labels
y = np.array([[0],  # Output for (0, 0)
              [1],  # Output for (0, 1)
              [1],  # Output for (1, 0)
              [0]]) # Output for (1, 1)
```

#### Step 3: Create the Neural Network Model

We’ll create a simple neural network with:
- An input layer with 2 neurons (for the 2 inputs),
- A hidden layer with 2 neurons (this is enough to capture the non-linearity of XOR),
- An output layer with 1 neuron for the binary output.

```python
# Define the model
model = Sequential()

# Add a hidden layer with 2 neurons and ReLU activation function
model.add(Dense(2, input_dim=2, activation='relu'))

# Add the output layer with 1 neuron and sigmoid activation function
model.add(Dense(1, activation='sigmoid'))
```

#### Step 4: Compile the Model

We’ll use the **binary cross-entropy** loss function since it's a binary classification task, and **Adam optimizer** for training.

```python
# Compile the model
model.compile(optimizer='adam', 
              loss='binary_crossentropy', 
              metrics=['accuracy'])
```

#### Step 5: Train the Model

We’ll train the model on the XOR dataset for a few epochs.

```python
# Train the model
model.fit(X, y, epochs=10000, verbose=0)
```

#### Step 6: Evaluate the Model

After training, we can evaluate the model by making predictions on the input data.

```python
# Make predictions
predictions = model.predict(X)

# Print predictions (round the output to 0 or 1 for binary classification)
print("Predictions:")
for i in range(len(X)):
    print(f"Input: {X[i]}, Predicted Output: {np.round(predictions[i])}, True Output: {y[i]}")
```

#### Full Code for XOR Implementation:

```python
import numpy as np
import tensorflow as tf
from tensorflow.keras import Sequential
from tensorflow.keras.layers import Dense

# XOR input data (2 inputs)
X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])

# XOR output labels
y = np.array([[0], [1], [1], [0]])

# Define the model
model = Sequential()

# Add a hidden layer with 2 neurons and ReLU activation function
model.add(Dense(2, input_dim=2, activation='relu'))

# Add the output layer with 1 neuron and sigmoid activation function
model.add(Dense(1, activation='sigmoid'))

# Compile the model
model.compile(optimizer='adam', 
              loss='binary_crossentropy', 
              metrics=['accuracy'])

# Train the model
model.fit(X, y, epochs=10000, verbose=0)

# Make predictions
predictions = model.predict(X)

# Print predictions (round the output to 0 or 1 for binary classification)
print("Predictions:")
for i in range(len(X)):
    print(f"Input: {X[i]}, Predicted Output: {np.round(predictions[i])}, True Output: {y[i]}")
```

### Explanation of Code:
- **Model Architecture**: The neural network consists of one hidden layer with 2 neurons and an output layer with 1 neuron.
  - **ReLU Activation** in the hidden layer allows the network to learn non-linear mappings.
  - **Sigmoid Activation** in the output layer produces a probability between 0 and 1, which is appropriate for binary classification.
- **Training**: The model is trained for 10,000 epochs on the XOR data to learn the relationship between the inputs and the outputs.
- **Prediction**: After training, the model makes predictions, which are rounded to either 0 or 1 (since it’s a binary classification task).

### Expected Output:

After training, the model should accurately predict the XOR values:

```text
Predictions:
Input: [0 0], Predicted Output: [0.], True Output: [0]
Input: [0 1], Predicted Output: [1.], True Output: [1]
Input: [1 0], Predicted Output: [1.], True Output: [1]
Input: [1 1], Predicted Output: [0.], True Output: [0]
```

### Conclusion:

This simple implementation demonstrates how a neural network can be used to solve the XOR problem, which is non-linearly separable. The network uses a hidden layer with a non-linear activation function (ReLU) to model the XOR logic. By training the model for a sufficient number of epochs, it learns to approximate the XOR function and make accurate predictions.
