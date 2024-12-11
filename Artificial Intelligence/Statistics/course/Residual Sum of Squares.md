### **Residual Sum of Squares (RSS)**

The **Residual Sum of Squares (RSS)**, also known as the **Sum of Squared Residuals (SSR)** or **Sum of Squared Errors (SSE)**, is a key measure in regression analysis that quantifies the discrepancy between the observed values and the values predicted by a regression model. It represents the portion of the total variation in the dependent variable that is not explained by the regression model.

### **Formula for Residual Sum of Squares (RSS)**

The Residual Sum of Squares is calculated as the sum of the squared residuals for all data points:

$\[
\text{RSS} = \sum_{i=1}^{n} (y_i - \hat{y}_i)^2
\]$

Where:
- $\( y_i \)$ = observed value of the dependent variable for the \(i\)-th data point
- $\( \hat{y}_i \)$ = predicted value of the dependent variable for the \(i\)-th data point
- \( n \) = number of data points

### **Interpretation of RSS**

- **Low RSS**: A lower RSS indicates that the regression model fits the data well, as the predicted values $(\( \hat{y}_i \))$ are close to the observed values $(\( y_i \))$.
- **High RSS**: A higher RSS suggests that the model does not explain much of the variation in the dependent variable, indicating a poor fit.

### **Relationship with Total Sum of Squares (TSS) and Explained Sum of Squares (ESS)**

In regression analysis, the **Total Sum of Squares (TSS)** measures the total variation in the dependent variable, while the **Explained Sum of Squares (ESS)** measures the variation explained by the regression model. The **RSS** represents the portion of the total variation that is unexplained by the model. These three quantities are related by the following equation:

$\[
\text{TSS} = \text{ESS} + \text{RSS}
\]$

Where:
- **TSS** (Total Sum of Squares) is the total variation in the dependent variable:
  $\[
  \text{TSS} = \sum_{i=1}^{n} (y_i - \bar{y})^2
  \]$
  where $\( \bar{y} \)$ is the mean of the observed values.

- **ESS** (Explained Sum of Squares) is the variation explained by the regression model:
  $\[
  \text{ESS} = \sum_{i=1}^{n} (\hat{y}_i - \bar{y})^2
  \]$

### **RSS and the Coefficient of Determination $(\( R^2 \))$**

The **coefficient of determination** $\( R^2 \)$ is a measure of how well the regression model explains the variation in the dependent variable. It is related to the RSS, TSS, and ESS by the following formula:

$\[
R^2 = 1 - \frac{\text{RSS}}{\text{TSS}}
\]$

- **$\( R^2 \)$ close to 1**: This indicates that most of the variation in the dependent variable is explained by the model, and the residual sum of squares is small.
- **$\( R^2 \)$ close to 0**: This indicates that the model does not explain much of the variation in the dependent variable, and the residual sum of squares is large.

### **Minimizing RSS in Regression**

In linear regression, the goal is to minimize the RSS by adjusting the model's parameters (such as the slope and intercept in simple linear regression) to find the best-fitting line. The method of **Ordinary Least Squares (OLS)** is commonly used for this purpose, which minimizes the RSS by finding the parameter estimates that minimize the sum of squared residuals.

### **Conclusion**

The Residual Sum of Squares (RSS) is a critical measure in assessing the fit of a regression model. It reflects how much of the variation in the dependent variable is not captured by the model. Lower RSS values indicate better model performance, while higher values suggest a poor fit. RSS is central to key regression metrics like $\( R^2 \)$ and is crucial for diagnostics and model improvement.
