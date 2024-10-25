**Supervised learning** and **unsupervised learning** are two major categories of machine learning, and they differ primarily in the type of information provided during the training process:

### Supervised Learning:

1. **Definition**:

   - In supervised learning, the model is trained on a labeled dataset, where each training example consists of input data along with the corresponding correct output or target.

2. **Training Process**:

   - The model learns to map the input data to the correct output by minimizing a loss function that quantifies the difference between the predicted output and the true target.

3. **Examples**:

   - Common tasks include regression (predicting a continuous value) and classification (predicting a category or label).

   - Examples:
     - Predicting house prices based on features like square footage, number of bedrooms, etc. (regression).
     - Classifying emails as spam or not spam based on their content (binary classification).

### Unsupervised Learning:

1. **Definition**:

   - In unsupervised learning, the model is given a dataset with input data but without any corresponding output labels or targets.

2. **Training Process**:

   - The model's objective is to find patterns, structures, or groupings in the data without explicit guidance.

3. **Examples**:

   - Common tasks include clustering (grouping similar data points together) and dimensionality reduction (compressing data while preserving important information).

   - Examples:
     - Grouping similar customer profiles based on purchasing behavior without predefined categories (clustering).
     - Reducing the dimensionality of an image dataset while retaining important features (dimensionality reduction).

### Semi-Supervised Learning:

1. **Definition**:

   - Semi-supervised learning is a combination of supervised and unsupervised learning. It involves training a model on a dataset where only a portion of the data is labeled.

2. **Training Process**:

   - The model learns to make predictions on the labeled data while also utilizing the unlabeled data to discover additional patterns or structures.

3. **Examples**:

   - Semi-supervised learning is used when labeling data is expensive or time-consuming, but there's still some labeled data available.

### Key Differences:

- **Supervised Learning**:

   - Requires labeled data with both input features and corresponding output labels.
   - Trains models to make predictions or classifications based on input data.
   - Examples include regression and classification.

- **Unsupervised Learning**:

   - Involves unlabeled data with only input features (no output labels).
   - Focuses on discovering hidden patterns, structures, or groupings in the data.
   - Examples include clustering, dimensionality reduction, and generative modeling.

- **Semi-Supervised Learning**:

   - Utilizes a combination of labeled and unlabeled data for training.
   - Balances the benefits of supervised learning with the insights gained from unsupervised learning.

In summary, the main distinction between supervised and unsupervised learning lies in the availability of labeled data. Supervised learning requires labeled examples for training, while unsupervised learning operates on unlabeled data to discover inherent structures or patterns. Semi-supervised learning bridges the gap by using a mix of labeled and unlabeled data for training.
