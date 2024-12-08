### **Linear Regression**

**Linear regression** is a fundamental statistical method used for modeling the relationship between a dependent variable (also called the response or output) and one or more independent variables (also known as predictors, features, or inputs). In its simplest form, **simple linear regression** deals with a relationship between a single independent variable and the dependent variable, while **multiple linear regression** involves multiple independent variables.

Linear regression is primarily used to make predictions, understand relationships, and estimate the parameters that define the best-fit line or hyperplane.

---

### **1. Simple Linear Regression (SLR)**

In simple linear regression, the relationship between the dependent variable \( y \) and the independent variable \( x \) is modeled as a straight line:

$\[
y = \beta_0 + \beta_1 x + \epsilon
\]$

Where:
- \( y \) is the dependent variable (response).
- \( x \) is the independent variable (predictor).
- $\( \beta_0 \)$ is the intercept (the value of \( y \) when \( x = 0 \)).
- $\( \beta_1 \)$ is the slope (the change in \( y \) for a one-unit increase in \( x \)).
- $\( \epsilon \)$ is the error term (the difference between the predicted and observed values of \( y \)).

**Goal**: The goal of linear regression is to estimate the coefficients $\( \beta_0 \)$ (intercept) and $\( \beta_1 \)$ (slope) in such a way that the error term $\( \epsilon \)$ is minimized.

---

### **2. Multiple Linear Regression (MLR)**

In multiple linear regression, we model the relationship between the dependent variable and multiple independent variables $\( x_1, x_2, \dots, x_k \)$:

$\[
y = \beta_0 + \beta_1 x_1 + \beta_2 x_2 + \dots + \beta_k x_k + \epsilon
\]$

Where:
- \( y \) is the dependent variable.
- $\( x_1, x_2, \dots, x_k \)$ are the independent variables (predictors).
- $\( \beta_0 \)$ is the intercept.
- $\( \beta_1, \beta_2, \dots, \beta_k \)$ are the coefficients for each of the independent variables.
- $\( \epsilon \)$ is the error term.

**Goal**: The goal is to estimate the coefficients $\( \beta_0, \beta_1, \dots, \beta_k \)$ that minimize the sum of squared errors between the predicted and actual values of \( y \).

---

### **3. Assumptions of Linear Regression**

For linear regression to provide reliable results, several assumptions about the data and the model must hold:

1. **Linearity**: The relationship between the independent and dependent variables must be linear.
2. **Independence**: The residuals (errors) must be independent. This assumption is especially important in time-series data.
3. **Homoscedasticity**: The variance of the residuals must be constant across all levels of the independent variable(s).
4. **Normality**: The residuals should be normally distributed, particularly for hypothesis testing.
5. **No multicollinearity** (in multiple linear regression): The independent variables should not be highly correlated with each other.

---

### **4. Least Squares Method**

The most common method for estimating the coefficients $\( \beta_0 \)$ and $\( \beta_1 \)$ (or $\( \beta_1, \beta_2, \dots, \beta_k \)$ in multiple regression) is the **least squares method**. The idea is to minimize the **sum of squared residuals** (the squared differences between the observed values and the predicted values). Mathematically, this is:

$\[
\text{Minimize} \quad \sum_{i=1}^{n} (y_i - \hat{y}_i)^2
\]$

Where:
- $\( y_i \)$ is the observed value.
- $\( \hat{y}_i \)$ is the predicted value from the model.

This optimization process gives the best-fitting line (or hyperplane in the case of multiple variables).

---

### **5. Interpreting the Coefficients**

- **Intercept $\( \beta_0 \)$**: This is the expected value of \( y \) when all the independent variables are zero. In some contexts, it may not have a meaningful interpretation (e.g., when zero values for predictors do not make sense).
  
- **Slope $\( \beta_1, \dots, \beta_k \)$**: These are the estimated changes in the dependent variable for a one-unit increase in the corresponding independent variable, while holding other variables constant. In simple linear regression, \( \beta_1 \) tells how much \( y \) changes for a unit increase in \( x \).

---

### **6. Evaluating the Model**

Several metrics are used to evaluate the performance of a linear regression model:

1. **R-squared $(\( R^2 \))$**: This is the proportion of variance in the dependent variable that is explained by the independent variable(s). $\( R^2 \)$ ranges from 0 to 1, with higher values indicating better model fit.

```math
   R^2 = 1 - \frac{\sum_{i=1}^{n} (y_i - \hat{y}_i)^2}{\sum_{i=1}^{n} (y_i - \bar{y})^2}
```

   Where:
   - $\( \bar{y} \)$ is the mean of the observed values.

2. **Adjusted R-squared**: This adjusts the $\( R^2 \)$ value for the number of predictors in the model. It is particularly useful in multiple linear regression, where adding more predictors can artificially increase \( R^2 \).

3. **Mean Squared Error (MSE)**: This is the average of the squared residuals, and it is used to measure the quality of the model. A lower MSE indicates a better fit.

   $\[
   MSE = \frac{1}{n} \sum_{i=1}^{n} (y_i - \hat{y}_i)^2
   \]$

4. **Root Mean Squared Error (RMSE)**: The square root of the MSE, which brings the error measure back to the same units as the dependent variable.

5. **F-test**: Used to test the overall significance of the regression model. It tests whether at least one of the independent variables significantly explains the variation in the dependent variable.

6. **t-test**: Used to test the significance of each individual regression coefficient $(\( \beta_i \))$.

---

### **7. Example**

Consider a simple linear regression model where we are predicting a person's weight (\( y \)) based on their height (\( x \)):

$\[
\text{Weight} = \beta_0 + \beta_1 \times \text{Height} + \epsilon
\]$

- **Data**: Suppose we have the following pairs of height (\( x \)) and weight (\( y \)) for five people:

| Height (x) | Weight (y) |
|------------|------------|
| 60         | 115        |
| 65         | 130        |
| 70         | 150        |
| 75         | 170        |
| 80         | 190        |

- **Fit the model**: Using the least squares method, we estimate the parameters $\( \beta_0 \)$ and $\( \beta_1 \)$.
  - Suppose the fitted regression equation turns out to be:
  $\[
  \text{Weight} = 100 + 1.2 \times \text{Height}
  \]$
  
  This means that for each additional inch of height, a person's weight is expected to increase by 1.2 pounds, and the baseline weight (when height is zero) is 100 pounds.

---

### **Conclusion**

Linear regression is a powerful and widely-used technique for modeling relationships between variables and making predictions. It forms the basis for many other advanced statistical and machine learning methods. While simple in concept, linear regression requires careful attention to assumptions, model diagnostics, and proper evaluation metrics to ensure accurate results.
