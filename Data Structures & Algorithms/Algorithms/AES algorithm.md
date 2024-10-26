K-Nearest Neighbors (KNN) is a simple and widely used machine learning algorithm for classification and regression tasks. It is a non-parametric and instance-based learning algorithm, meaning it does not make any assumptions about the underlying data distribution and makes predictions based on the nearest neighbors.

Working of KNN algorithm:

1. Load the data: The first step is to load the training data, which consists of labeled examples. Each example contains a set of features and the corresponding class label (for classification) or the target value (for regression).

2. Choose the value of K: K is a hyperparameter that represents the number of nearest neighbors to consider for making predictions. It is important to choose an appropriate value of K to ensure the algorithm performs well on unseen data.

3. Calculate distances: For each data point in the test set, the algorithm calculates the distance between that point and all the data points in the training set. Common distance metrics used are Euclidean distance, Manhattan distance, or Minkowski distance.

4. Find K nearest neighbors: The algorithm selects the K data points with the smallest distances to the test point.

5. Make a prediction: For classification tasks, the class label that occurs most frequently among the K nearest neighbors is assigned as the predicted class for the test point. For regression tasks, the predicted target value is calculated as the average (or weighted average) of the target values of the K nearest neighbors.

6. Evaluate the model: The model's performance is evaluated on a separate test set by comparing the predicted values to the true values.

Examples where KNN algorithm is used:

1. Handwriting recognition: KNN can be used to recognize handwritten digits by comparing the test digit with the nearest neighbors in the training data.

2. Image classification: KNN can be used to classify images based on their features, such as color histograms or texture descriptors.

3. Recommender systems: KNN can be used in collaborative filtering-based recommender systems to recommend products or movies based on the preferences of similar users.

Python implementation of KNN algorithm:

```python
import numpy as np
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score

# Load the Iris dataset
iris = load_iris()
X, y = iris.data, iris.target

# Split the dataset into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Create a KNN classifier with K=3
knn = KNeighborsClassifier(n_neighbors=3)

# Train the classifier on the training data
knn.fit(X_train, y_train)

# Make predictions on the test data
y_pred = knn.predict(X_test)

# Calculate the accuracy of the model
accuracy = accuracy_score(y_test, y_pred)
print("Accuracy:", accuracy)
```

C++ implementation of KNN algorithm:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// Function to calculate the Euclidean distance between two points
double distance(const std::vector<double>& point1, const std::vector<double>& point2)
{
    double sum = 0.0;
    for (size_t i = 0; i < point1.size(); i++)
    {
        sum += std::pow(point1[i] - point2[i], 2);
    }
    return std::sqrt(sum);
}

// Function to find the K nearest neighbors
std::vector<int> kNearestNeighbors(const std::vector<std::vector<double>>& training_data,
                                   const std::vector<double>& test_point,
                                   int k)
{
    std::vector<std::pair<double, int>> distances;
    for (size_t i = 0; i < training_data.size(); i++)
    {
        double dist = distance(training_data[i], test_point);
        distances.emplace_back(dist, i);
    }

    std::sort(distances.begin(), distances.end());

    std::vector<int> neighbors;
    for (int i = 0; i < k; i++)
    {
        neighbors.push_back(distances[i].second);
    }

    return neighbors;
}

// Function to classify the test point based on the K nearest neighbors
int classify(const std::vector<std::vector<double>>& training_data,
             const std::vector<double>& test_point,
             const std::vector<int>& neighbors)
{
    std::vector<int> counts(training_data.size(), 0);
    for (int neighbor : neighbors)
    {
        counts[training_data[neighbor].back()]++;
    }

    int max_count = 0;
    int predicted_class = -1;
    for (size_t i = 0; i < counts.size(); i++)
    {
        if (counts[i] > max_count)
        {
            max_count = counts[i];
            predicted_class = i;
        }
    }

    return predicted_class;
}

int main()
{
    // Sample training data
    std::vector<std::vector<double>> training_data = {{5.1, 3.5, 1.4, 0.2, 0},
                                                      {4.9, 3.0, 1.4, 0.2, 0},
                                                      {7.0

, 3.2, 4.7, 1.4, 1},
                                                      {6.4, 3.2, 4.5, 1.5, 1},
                                                      {6.3, 3.3, 6.0, 2.5, 2},
                                                      {5.8, 2.7, 5.1, 1.9, 2}};

    // Sample test point
    std::vector<double> test_point = {5.0, 3.0, 1.6, 0.2};

    // Find the K nearest neighbors
    int k = 3;
    std::vector<int> neighbors = kNearestNeighbors(training_data, test_point, k);

    // Classify the test point based on the K nearest neighbors
    int predicted_class = classify(training_data, test_point, neighbors);

    std::cout << "Predicted class: " << predicted_class << std::endl;

    return 0;
}
```

Note: The above code is for educational purposes only and may not be suitable for large-scale applications. For better performance and efficiency, it is recommended to use established libraries like scikit-learn in Python and mlpack in C++.
