### **Machine Learning - Precision and Recall**

**Precision** and **Recall** are two important performance metrics used to evaluate the effectiveness of classification algorithms, especially when the classes are imbalanced. These metrics focus on the **positive class** (the class of interest) and help assess how well a model is identifying positive instances.

### **Precision**
Precision is the ratio of correctly predicted positive observations to the total predicted positives. It answers the question: **Of all the instances that the model predicted as positive, how many were actually positive?**

$\[
\text{Precision} = \frac{\text{True Positives (TP)}}{\text{True Positives (TP) + False Positives (FP)}}
\]$

Where:
- **True Positives (TP)**: The number of positive instances correctly identified by the model.
- **False Positives (FP)**: The number of negative instances incorrectly classified as positive.

### **Recall**
Recall, also known as **Sensitivity** or **True Positive Rate**, is the ratio of correctly predicted positive observations to all actual positives. It answers the question: **Of all the actual positive instances, how many did the model correctly identify?**

$\[
\text{Recall} = \frac{\text{True Positives (TP)}}{\text{True Positives (TP) + False Negatives (FN)}}
\]$

Where:
- **False Negatives (FN)**: The number of positive instances that were incorrectly classified as negative.

### **Precision vs. Recall**
- **Precision** focuses on the accuracy of positive predictions. If precision is high, it means that when the model predicts a positive outcome, it is usually correct. 
- **Recall**, on the other hand, focuses on capturing all positive instances. If recall is high, it means that the model is good at identifying most of the positive instances, but this may come at the cost of predicting some negative instances as positive (false positives).

### **Precision-Recall Trade-off**
There is often a trade-off between precision and recall. Increasing one tends to decrease the other. For example, if you make the model more stringent in predicting positive classes (e.g., raise the threshold for predicting positive), precision may improve but recall may decrease because the model may miss some positive instances.

### **F1-Score**
To balance between precision and recall, we use the **F1-score**, which is the harmonic mean of precision and recall. It provides a single metric to assess a model's performance when there is an imbalance between precision and recall.

$\[
\text{F1-Score} = 2 \times \frac{\text{Precision} \times \text{Recall}}{\text{Precision} + \text{Recall}}
\]$

The **F1-score** is useful when you need a balance between precision and recall, especially when dealing with imbalanced datasets.

### **Confusion Matrix**
Both precision and recall are derived from the **confusion matrix**, which summarizes the classification results:
```
                    Predicted
                    Positive   Negative
Actual  Positive    TP         FN
        Negative    FP         TN
```
- **TP** (True Positives): Correctly predicted positive instances.
- **TN** (True Negatives): Correctly predicted negative instances.
- **FP** (False Positives): Incorrectly predicted positive instances.
- **FN** (False Negatives): Incorrectly predicted negative instances.

### **Example of Precision and Recall Calculation**

Let’s say you have a binary classification problem (e.g., spam vs. not spam), and you’ve evaluated a model on a test set. The confusion matrix is as follows:

|                | Predicted Positive | Predicted Negative |
|----------------|--------------------|--------------------|
| **Actual Positive**  | 50 (TP)            | 10 (FN)            |
| **Actual Negative**  | 5 (FP)             | 35 (TN)            |

Now, we can compute the **Precision** and **Recall**:

1. **Precision**:
   $\[
   \text{Precision} = \frac{TP}{TP + FP} = \frac{50}{50 + 5} = \frac{50}{55} \approx 0.91
   \]$

2. **Recall**:
   $\[
   \text{Recall} = \frac{TP}{TP + FN} = \frac{50}{50 + 10} = \frac{50}{60} \approx 0.83
   \]$

Thus:
- The **Precision** is 0.91, meaning 91% of the instances predicted as positive were actually positive.
- The **Recall** is 0.83, meaning 83% of the actual positive instances were identified by the model.

### **Precision and Recall in Imbalanced Datasets**

Precision and recall are particularly useful when dealing with **imbalanced datasets**, where one class (e.g., negative class) dominates the other (e.g., positive class). In such cases:
- A high **accuracy** might be misleading because a model that always predicts the majority class (e.g., always predicting negative) could still achieve a high accuracy, but it would fail to detect the minority class.
- **Precision** and **Recall** provide a more meaningful evaluation, especially for the **minority class**.

For example, in a **fraud detection** system (where fraud cases are rare), even if the model correctly predicts most non-fraud transactions, it’s crucial that the model identifies as many fraudulent transactions as possible, even at the cost of false positives.

### **Precision-Recall Curve**
A **Precision-Recall Curve** is a graph showing the trade-off between precision and recall for different threshold values. It helps in visualizing how precision and recall vary with changes in the decision threshold of the classifier.

- **High precision** means fewer false positives.
- **High recall** means fewer false negatives.

### **Python Implementation: Precision and Recall**

Here’s a simple Python code to calculate **Precision**, **Recall**, and **F1-Score** using **`sklearn`**:

```python
from sklearn.metrics import precision_score, recall_score, f1_score, confusion_matrix

# Example true labels and predicted labels
y_true = [1, 0, 1, 1, 0, 1, 0, 0, 1, 0]
y_pred = [1, 0, 1, 1, 0, 0, 0, 1, 1, 0]

# Calculate Precision
precision = precision_score(y_true, y_pred)
print(f'Precision: {precision:.2f}')

# Calculate Recall
recall = recall_score(y_true, y_pred)
print(f'Recall: {recall:.2f}')

# Calculate F1-Score
f1 = f1_score(y_true, y_pred)
print(f'F1-Score: {f1:.2f}')

# Confusion Matrix
cm = confusion_matrix(y_true, y_pred)
print(f'Confusion Matrix:\n{cm}')
```

This code calculates precision, recall, and F1-score and displays the confusion matrix. For the given example:

- **Precision**: Proportion of positive predictions that were correct.
- **Recall**: Proportion of actual positives that were correctly predicted.
- **F1-Score**: Harmonic mean of precision and recall, giving a single metric to balance them.

### **Conclusion**

- **Precision** and **Recall** are critical metrics for classification models, particularly in cases where class imbalance exists.
- **Precision** is useful when the cost of false positives is high, while **Recall** is essential when the cost of false negatives is high.
- The **F1-Score** offers a balanced measure when both precision and recall are important.
- By understanding the trade-offs between precision and recall, you can optimize your model for the specific needs of your application.
