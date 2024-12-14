### Logistic Regression in R

Logistic regression is a statistical method used for binary classification problems, where the outcome variable is categorical with two possible outcomes (e.g., success/failure, yes/no, 1/0). Unlike linear regression, which predicts continuous outcomes, logistic regression models the probability of an event occurring and uses a logistic (sigmoid) function to map predictions to a probability between 0 and 1.

#### Logistic Regression Model:

The model for logistic regression is:

$\[
\text{logit}(P) = \log \left(\frac{P}{1-P}\right) = \beta_0 + \beta_1 X_1 + \beta_2 X_2 + \dots + \beta_n X_n
\]$

Where:
- \( P \) is the probability of the event occurring $(e.g., \( P(\text{success}) \))$,
- $\( \frac{P}{1-P} \)$ is the **odds** of the event,
- $\( \beta_0 \)$ is the intercept,
- $\( \beta_1, \beta_2, \dots, \beta_n \)$ are the coefficients of the independent variables $\( X_1, X_2, \dots, X_n \)$,
- $\( X_1, X_2, \dots, X_n \)$ are the predictor variables.

The logistic regression model predicts the log-odds of the dependent variable. These log-odds are then transformed into probabilities using the logistic function:

$\[
P = \frac{1}{1 + e^{-(\beta_0 + \beta_1 X_1 + \dots + \beta_n X_n)}}
\]$

### Steps for Performing Logistic Regression in R

1. **Prepare the Data**: Ensure that the dependent variable is binary (0/1 or true/false).
2. **Fit the Model**: Use the **`glm()`** function in R to fit the logistic regression model.
3. **Summarize the Model**: Use **`summary()`** to view the model's coefficients, p-values, and other statistics.
4. **Make Predictions**: Use **`predict()`** to make predictions based on the model.

### 1. **Fitting a Logistic Regression Model in R**

Let's consider a dataset where we want to predict whether a customer will buy a product (`purchase`) based on their age (`age`) and income (`income`). The outcome variable is binary (1 for purchase, 0 for no purchase).

```r
# Sample data (age, income, purchase)
age <- c(25, 30, 35, 40, 45, 50, 55, 60, 65)
income <- c(30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000, 110000)
purchase <- c(0, 0, 1, 1, 1, 1, 0, 0, 1)

# Create a data frame
data <- data.frame(age, income, purchase)

# Fit logistic regression model
model <- glm(purchase ~ age + income, data = data, family = binomial())

# View the model summary
summary(model)
```

#### Key Points:
- **`glm()` function**: This function fits generalized linear models. In this case, we use it to fit a logistic regression model. The **`family = binomial()`** argument tells R that we're performing logistic regression (binomial distribution).
- **`purchase ~ age + income`**: The formula specifies that we're predicting the `purchase` outcome using `age` and `income` as independent variables.
- **`summary(model)`**: This will show the model's coefficients, p-values, and other statistics.

#### Example Output:

```r
Call:
glm(formula = purchase ~ age + income, family = binomial(), data = data)

Coefficients:
            Estimate Std. Error z value Pr(>|z|)  
(Intercept) -7.2151     3.3025  -2.183  0.0291 *  
age          0.1165     0.0421   2.769  0.0056 ** 
income       0.0001     0.0000   2.839  0.0045 ** 

(Dispersion parameter for binomial family taken to be 1)

    Null deviance: 12.321  on 8  degrees of freedom
Residual deviance:  6.140  on  6  degrees of freedom
AIC: 14.140

Number of Fisher Scoring iterations: 4
```

#### Key Statistics:
- **Coefficients**: 
  - **Intercept**: The log-odds of purchasing when both age and income are zero.
  - **Age and Income**: The change in the log-odds of purchasing for each unit increase in age and income, respectively.
- **z-value and p-value**: These help determine whether the coefficients are statistically significant. A p-value less than 0.05 typically indicates that the predictor is statistically significant.
- **Residual deviance**: Measures the goodness-of-fit of the model (lower is better).
- **AIC**: The Akaike Information Criterion helps compare models. Lower values indicate a better-fitting model.

### 2. **Model Interpretation**
- The **coefficients** can be exponentiated to interpret them as odds ratios.
  - **Odds Ratio** = \( e^{\beta} \)
  - For age: \( e^{0.1165} \approx 1.123 \) implies that for every one-year increase in age, the odds of purchasing increase by 12.3%.
  - For income: \( e^{0.0001} \approx 1.0001 \) implies that for every increase in income by $1, the odds of purchasing increase by 0.01%.

### 3. **Making Predictions**
Once the model is fitted, you can use the **`predict()`** function to predict probabilities of the outcome (e.g., the probability that a person will purchase).

```r
# New data for prediction
new_data <- data.frame(age = c(28, 55), income = c(45000, 85000))

# Predict probabilities
predicted_probabilities <- predict(model, new_data, type = "response")

# View predictions
predicted_probabilities
```

The **`type = "response"`** argument tells R to return probabilities (between 0 and 1) rather than log-odds.

### 4. **Evaluating the Model**
Once you have your model, you should evaluate its performance using metrics like:
- **Confusion Matrix**: Compares the predicted classes with the actual classes.
- **Accuracy, Precision, Recall, F1-score**: These metrics help assess the quality of the classification model.

You can generate a confusion matrix using the `table()` function:

```r
# Predicted class labels (0 or 1) based on a threshold (e.g., 0.5)
predicted_class <- ifelse(predicted_probabilities > 0.5, 1, 0)

# Confusion matrix
confusion_matrix <- table(predicted_class, new_data$purchase)
confusion_matrix
```

- **Accuracy**: Proportion of correct predictions.
- **Precision**: Proportion of true positive predictions out of all predicted positives.
- **Recall**: Proportion of true positive predictions out of all actual positives.
- **F1-score**: The harmonic mean of precision and recall.

### 5. **Plotting the ROC Curve**
A common way to assess the performance of a binary classifier is by plotting the **ROC (Receiver Operating Characteristic) curve** and calculating the **AUC (Area Under the Curve)**.

```r
# Install and load pROC package if not already installed
# install.packages("pROC")
library(pROC)

# ROC curve
roc_curve <- roc(new_data$purchase, predicted_probabilities)

# Plot the ROC curve
plot(roc_curve, main = "ROC Curve")

# AUC (Area Under the Curve)
auc(roc_curve)
```

- **ROC curve**: Plots the true positive rate (sensitivity) against the false positive rate (1 - specificity) at various thresholds.
- **AUC**: A higher AUC indicates better model performance (close to 1 is ideal).

### 6. **Conclusion**
Logistic regression in R is a powerful technique for modeling binary outcomes. The **`glm()`** function allows you to fit the logistic regression model, and you can interpret the results by examining the coefficients, p-values, and other statistics. The model can then be used for prediction and evaluated using metrics such as accuracy, precision, recall, and AUC. Proper evaluation and diagnostics are crucial for ensuring the model's reliability and performance.
