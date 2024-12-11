### **Quadratic Regression Equation**

Quadratic regression is a type of polynomial regression where the relationship between the independent variable \( x \) and the dependent variable \( y \) is modeled by a second-degree polynomial (quadratic function). This form of regression is useful when the data exhibits a **curved pattern** or **non-linear trend** that can be described by a parabola.

The general form of a **quadratic regression equation** is:

$\[
y = ax^2 + bx + c
\]$

Where:
- \( y \) is the dependent variable (the outcome we are trying to predict),
- \( x \) is the independent variable (the input or predictor),
- \( a \), \( b \), and \( c \) are the coefficients to be estimated.

### **Steps for Finding the Quadratic Regression Equation**

1. **Collect Data**: 
   You need a set of data points $\((x_1, y_1), (x_2, y_2), \dots, (x_n, y_n)\)$.

2. **Set Up the Quadratic Equation**:
   The quadratic regression equation can be written as:
   $\[
   y = ax^2 + bx + c
   \]$
   To estimate the coefficients \(a\), \(b\), and \(c\), we use a method called **least squares** to minimize the sum of the squared differences between the observed values \( y_i \) and the predicted values \( \hat{y_i} \).

3. **Perform Regression Analysis**:
   - You can perform quadratic regression using statistical software (like Excel, R, Python, or a graphing calculator). These tools use methods such as the **least squares method** to calculate the values of \(a\), \(b\), and \(c\).
   - The coefficients are calculated to minimize the difference between the predicted and actual values of \(y\), which is represented by the residuals (errors).

4. **Quadratic Regression Model**:
   The coefficients \(a\), \(b\), and \(c\) are estimated based on the dataset. These estimates are found through the following system of normal equations for quadratic regression:

```math
   \begin{aligned}
   \sum y &= n c + b \sum x + a \sum x^2 \\
   \sum x y &= c \sum x + b \sum x^2 + a \sum x^3 \\
   \sum x^2 y &= c \sum x^2 + b \sum x^3 + a \sum x^4
   \end{aligned}
```

   These equations can be solved to find the values of \(a\), \(b\), and \(c\).

### **Example of a Quadratic Regression Equation**

Consider the following data points:

$\[
(1, 2), (2, 4), (3, 7), (4, 13), (5, 21)
\]$

1. **Construct the Quadratic Regression Equation**:
   The general form is $\( y = ax^2 + bx + c \)$.
   Using software (e.g., Excel or R), we can calculate the values of \(a\), \(b\), and \(c\).

2. **Fit the Model**:
   After performing quadratic regression, suppose we obtain:
   $\[
   y = x^2 + x + 1
   \]$

   So, the fitted quadratic regression equation is:
   $\[
   y = 1x^2 + 1x + 1
   \]$

### **Interpretation of Coefficients**

- **\(a\)** (quadratic term): Represents the curvature of the parabola. If \(a > 0\), the parabola opens upwards, and if \(a < 0\), the parabola opens downwards.
- **\(b\)** (linear term): Determines the slope of the curve. It influences the direction of the slope but not the curvature.
- **\(c\)** (constant or intercept): Represents the point where the parabola intersects the \(y\)-axis (i.e., when \(x = 0\)).

### **Applications of Quadratic Regression**

- **Modeling Curved Data**: Quadratic regression is useful when data shows a non-linear trend, such as parabolic growth or decay.
- **Prediction**: Once the quadratic regression equation is obtained, it can be used to predict the value of \(y\) for new values of \(x\), especially in areas like economics, engineering, and natural sciences.

### **Goodness of Fit in Quadratic Regression**

- **R-squared (\( R^2 \))**: The **coefficient of determination** $(\( R^2 \))$ measures the goodness of fit of the model. It tells us how well the quadratic regression line fits the data. An $\( R^2 \)$ value closer to 1 indicates that the quadratic regression model explains most of the variance in the dependent variable \( y \).
  
- **Residual Analysis**: Plotting the residuals (the differences between the observed and predicted values) can also help assess the fit of the quadratic model. Ideally, residuals should show no pattern and be evenly distributed around zero.

### **Conclusion**

Quadratic regression is a powerful tool for modeling data with a curved relationship between variables. By fitting a second-degree polynomial to the data, it provides a way to predict outcomes and understand the underlying trends, especially when the relationship between \(x\) and \(y\) is non-linear.
