### Python - Linear Regression

**Linear Regression** is a statistical method used to model the relationship between a dependent variable (target) and one or more independent variables (predictors). In simple terms, linear regression tries to find the best-fitting line through the data points.

- **Simple Linear Regression**: Involves one independent variable.
- **Multiple Linear Regression**: Involves two or more independent variables.

The goal of linear regression is to find the best-fit line that minimizes the difference between the observed values and the predicted values.

### 1. **Simple Linear Regression Formula**

In the case of simple linear regression (one predictor), the relationship is modeled as:

$\[
y = \beta_0 + \beta_1 \cdot x + \epsilon
\]$

Where:
- \(y\) is the dependent variable (target).
- \(x\) is the independent variable (predictor).
- $\(\beta_0\)$ is the y-intercept (the value of \(y\) when \(x = 0\)).
- $\(\beta_1\)$ is the slope of the line (the change in \(y\) for a unit change in \(x\)).
- $\(\epsilon\)$ is the error term.

### 2. **Multiple Linear Regression**

In multiple linear regression (more than one predictor), the equation becomes:

$\[
y = \beta_0 + \beta_1 \cdot x_1 + \beta_2 \cdot x_2 + \dots + \beta_n \cdot x_n + \epsilon
\]$

Where:
- \(y\) is the dependent variable.
- $\(x_1, x_2, \dots, x_n\)$ are the independent variables.
- $\(\beta_0, \beta_1, \dots, \beta_n\)$ are the regression coefficients.

### 3. **Linear Regression Using Python**

To perform linear regression in Python, the most commonly used library is **`scikit-learn`**, which provides an easy-to-use API for performing both simple and multiple linear regression.

#### Example: Simple Linear Regression

Let's use **`scikit-learn`** to perform simple linear regression with some sample data.

```python
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split

# Sample data (e.g., advertising spend vs sales)
X = np.array([1, 2, 3, 4, 5]).reshape(-1, 1)  # Independent variable (reshape to 2D array)
y = np.array([1, 2, 2.5, 3.5, 5])  # Dependent variable

# Split data into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Create a linear regression model
model = LinearRegression()

# Train the model on the training data
model.fit(X_train, y_train)

# Print the coefficients
print(f"Intercept (β₀): {model.intercept_}")
print(f"Slope (β₁): {model.coef_}")

# Predict on test data
y_pred = model.predict(X_test)

# Plotting the data and the regression line
plt.scatter(X, y, color='blue', label='Data Points')
plt.plot(X, model.predict(X), color='red', label='Regression Line')
plt.xlabel('X')
plt.ylabel('y')
plt.title('Simple Linear Regression')
plt.legend()
plt.show()

# Evaluate model on test data
print(f"Predictions: {y_pred}")
```

#### Explanation:
- **`X`** is the independent variable, which is reshaped into a 2D array (required by `scikit-learn`).
- **`y`** is the dependent variable (the target).
- **`train_test_split()`** splits the data into training and test sets.
- **`model.fit()`** fits the linear regression model to the training data.
- **`model.intercept_`** gives the y-intercept (β₀), and **`model.coef_`** gives the slope (β₁).
- **`model.predict()`** predicts the dependent variable based on the test set.

#### Output:
- **Intercept (β₀)**: The value of \( y \) when \( x = 0 \).
- **Slope (β₁)**: The rate of change of \( y \) with respect to \( x \).
- **Predictions**: The predicted values of \( y \) based on the model for the test set.

---

### 4. **Multiple Linear Regression Example**

For multiple predictors, we can expand the number of independent variables.

```python
from sklearn.linear_model import LinearRegression

# Sample data (e.g., hours studied and previous grades vs final score)
X = np.array([[1, 2], [2, 3], [3, 4], [4, 5], [5, 6]])  # Independent variables
y = np.array([3, 4, 5, 6, 7])  # Dependent variable

# Create and train the model
model = LinearRegression()
model.fit(X, y)

# Print coefficients
print(f"Intercept (β₀): {model.intercept_}")
print(f"Coefficients (β₁, β₂): {model.coef_}")

# Predict
y_pred = model.predict(X)

print(f"Predictions: {y_pred}")
```

In this case:
- **`X`** is a 2D array with multiple independent variables (e.g., hours studied and previous grades).
- **`model.coef_`** will output an array of coefficients for each predictor.

---

### 5. **Model Evaluation**

After training a regression model, it’s important to evaluate its performance. The following metrics are commonly used:

1. **R² (Coefficient of Determination)**: It tells us how well the model explains the variation in the target variable.
   - **R² = 1** indicates perfect fit.
   - **R² = 0** indicates that the model does not explain any variance.

   In **scikit-learn**, you can compute R² using the `.score()` method.

   ```python
   r2 = model.score(X_test, y_test)
   print(f"R²: {r2}")
   ```

2. **Mean Absolute Error (MAE)**: Measures the average magnitude of the errors in a set of predictions, without considering their direction.
   ```python
   from sklearn.metrics import mean_absolute_error
   mae = mean_absolute_error(y_test, y_pred)
   print(f"Mean Absolute Error: {mae}")
   ```

3. **Mean Squared Error (MSE)**: Similar to MAE but penalizes larger errors more heavily.
   ```python
   from sklearn.metrics import mean_squared_error
   mse = mean_squared_error(y_test, y_pred)
   print(f"Mean Squared Error: {mse}")
   ```

4. **Root Mean Squared Error (RMSE)**: The square root of MSE, providing an estimate of the magnitude of error in the same units as the target variable.
   ```python
   rmse = np.sqrt(mse)
   print(f"Root Mean Squared Error: {rmse}")
   ```

---

### 6. **Assumptions of Linear Regression**

Linear regression relies on the following assumptions:
- **Linearity**: The relationship between independent and dependent variables is linear.
- **Independence**: The observations should be independent of each other.
- **Homoscedasticity**: The variance of errors is constant across all levels of the independent variable(s).
- **Normality of Errors**: The errors should be normally distributed.

These assumptions can be checked using diagnostic plots like residual plots, Q-Q plots, etc.

---

### Conclusion

Linear regression is a fundamental machine learning technique used to predict a continuous target variable from one or more predictors. In Python, you can easily implement linear regression using **scikit-learn**, and evaluate the model's performance using metrics like R², MAE, MSE, and RMSE.
