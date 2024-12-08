### **Logistic Regression**

**Logistic regression** is a statistical technique used for modeling binary, ordinal, or multinomial dependent variables. It predicts the probability of an outcome based on one or more independent variables. Unlike linear regression, logistic regression is designed for situations where the response variable is categorical and particularly useful for binary classification problems.

---

### **1. Logistic Regression Model**

For a binary dependent variable, logistic regression models the probability of one of the two possible outcomes (e.g., success/failure, yes/no, 1/0). The relationship between the predictors \( x \) and the probability \( p \) of the outcome is modeled using the logistic (sigmoid) function:

$\[
p = \frac{1}{1 + e^{-(\beta_0 + \beta_1 x_1 + \beta_2 x_2 + \cdots + \beta_k x_k)}}
\]$

Where:
- \( p \): Probability of the dependent variable taking the value 1 (e.g., success).
- $\( \beta_0 \)$: Intercept term.
- $\( \beta_1, \beta_2, \dots, \beta_k \)$: Coefficients for the independent variables $\( x_1, x_2, \dots, x_k \)$.
- $\( x_1, x_2, \dots, x_k \)$: Independent variables.

The model can be rewritten in terms of the **log-odds (logit transformation)**:

$\[
\log \left( \frac{p}{1-p} \right) = \beta_0 + \beta_1 x_1 + \beta_2 x_2 + \cdots + \beta_k x_k
\]$

- The **logit function** maps probabilities $(\( p \))$ to a linear combination of the predictors, which can take any real value.

---

### **2. Types of Logistic Regression**

1. **Binary Logistic Regression**:
   - Dependent variable has two possible outcomes (e.g., 0/1, pass/fail).
   - Example: Predicting whether a customer will buy a product (yes/no).

2. **Multinomial Logistic Regression**:
   - Dependent variable has three or more unordered categories.
   - Example: Predicting the type of transport a person will use (car, bike, bus).

3. **Ordinal Logistic Regression**:
   - Dependent variable has three or more ordered categories.
   - Example: Predicting the level of customer satisfaction (low, medium, high).

---

### **3. Assumptions of Logistic Regression**

For logistic regression to provide reliable results, the following assumptions should hold:

1. **Dependent Variable is Binary or Categorical**:
   - Logistic regression is primarily used when the response variable is binary or has categorical outcomes.

2. **Independence of Observations**:
   - Observations in the dataset should be independent of one another.

3. **Linearity of Predictors and Logit**:
   - The relationship between the independent variables and the logit of the dependent variable should be linear.

4. **No Multicollinearity**:
   - Independent variables should not be highly correlated with one another.

5. **Large Sample Size**:
   - Logistic regression performs better with a sufficiently large sample size, especially when there are many predictors.

---

### **4. Estimation of Coefficients**

The coefficients $\( \beta_0, \beta_1, \dots, \beta_k \)$ are estimated using **maximum likelihood estimation (MLE)**. This method finds the parameter values that maximize the likelihood of observing the given data under the model.

- The **likelihood function** is:
  $\[
  L(\beta) = \prod_{i=1}^{n} p_i^{y_i} (1 - p_i)^{1-y_i}
  \]$
  Where:
  - $\( p_i \)$: Predicted probability for observation \( i \).
  - $\( y_i \)$: Observed outcome (0 or 1) for observation \( i \).

- The goal is to maximize $\( \log(L(\beta)) \)$, the log-likelihood function, to find the best-fitting coefficients.

---

### **5. Evaluation of Model Performance**

1. **Accuracy**:
   - The proportion of correctly classified observations.

2. **Confusion Matrix**:
   - A table showing the counts of true positives (TP), true negatives (TN), false positives (FP), and false negatives (FN).

3. **Precision, Recall, and F1-Score**:
   - **Precision**: $\( \text{TP} / (\text{TP} + \text{FP}) \)$
   - **Recall (Sensitivity)**: $\( \text{TP} / (\text{TP} + \text{FN}) \)$
   - **F1-Score**: Harmonic mean of precision and recall.

4. **Receiver Operating Characteristic (ROC) Curve**:
   - Plots the true positive rate (sensitivity) against the false positive rate (1 - specificity).
   - The area under the ROC curve (AUC) measures the model's discriminative ability.

5. **Log-Loss**:
   - A measure of error for probabilistic predictions:
     $\[
     \text{Log-Loss} = -\frac{1}{n} \sum_{i=1}^{n} \left[ y_i \log(p_i) + (1-y_i) \log(1-p_i) \right]
     \]$

---

### **6. Applications of Logistic Regression**

1. **Medical Research**:
   - Predicting disease presence (e.g., cancer diagnosis: yes/no).
   
2. **Marketing and Business**:
   - Predicting customer churn or purchase likelihood.

3. **Social Sciences**:
   - Analyzing survey responses with binary outcomes.

4. **Finance**:
   - Modeling credit risk (default/non-default).

---

### **7. Example of Logistic Regression**

**Problem**: Predict whether a customer will purchase a product based on their annual income (\( x \)).

**Dataset**:
| Annual Income (\$) | Purchased (1 = Yes, 0 = No) |
|--------------------|-----------------------------|
| 30,000             | 0                           |
| 50,000             | 0                           |
| 70,000             | 1                           |
| 90,000             | 1                           |
| 110,000            | 1                           |

**Logistic Model**:
$\[
p = \frac{1}{1 + e^{-(\beta_0 + \beta_1 x)}}
\]$

Using MLE, suppose we estimate:
- $\( \beta_0 = -5 \)$
- $\( \beta_1 = 0.0001 \)$

The probability of purchase for a customer earning $80,000 is:
```math
p = \frac{1}{1 + e^{-(-5 + 0.0001 \times 80000)}} = \frac{1}{1 + e^{3}} \approx 0.047
```

Thus, the model predicts a low probability (~4.7%) of purchase.

---

### **Conclusion**

Logistic regression is a robust and widely used method for modeling binary and categorical outcomes. Its interpretability, efficiency, and ability to handle probabilistic predictions make it a cornerstone in statistics and machine learning, with applications across diverse domains.
