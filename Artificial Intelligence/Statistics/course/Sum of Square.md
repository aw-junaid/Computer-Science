### **Sum of Squares (SS)**

In statistics, the **sum of squares (SS)** is a measure of the total variation or dispersion in a set of data points. It plays a key role in many statistical analyses, particularly in **variance analysis (ANOVA)**, **regression analysis**, and **standard deviation calculations**. The sum of squares helps to assess how far the observed data points deviate from the mean or other reference points.

### **Formula for Sum of Squares**

The general formula for sum of squares depends on the context of the analysis, but the most common formula is for calculating **total sum of squares (SSₜ)**, which quantifies the total variation in a data set.

#### 1. **Total Sum of Squares (SSₜ)**

The **total sum of squares (SSₜ)** measures the total variation in the observed data from the overall mean $(\( \bar{x} \))$.

$\[
SS_t = \sum_{i=1}^{n} (x_i - \bar{x})^2
\]$
Where:
- $\( x_i \)$ = individual data points
- $\( \bar{x} \)$ = mean of the data
- \( n \) = number of data points

#### 2. **Sum of Squares Between Groups (SSB)**

In **ANOVA** (Analysis of Variance), the **sum of squares between groups (SSB)** measures how much the group means deviate from the overall mean.

$\[
SS_B = \sum_{k=1}^{g} n_k (\bar{x}_k - \bar{x})^2
\]$
Where:
- \( g \) = number of groups
- $\( n_k \)$ = number of data points in group \( k \)
- $\( \bar{x}_k \)$ = mean of group \( k \)
- $\( \bar{x} \)$ = overall mean

#### 3. **Sum of Squares Within Groups (SSW)**

The **sum of squares within groups (SSW)** measures the variation within each group (i.e., how much individual data points deviate from their respective group means).

$\[
SS_W = \sum_{k=1}^{g} \sum_{i=1}^{n_k} (x_{ik} - \bar{x}_k)^2
\]$
Where:
- $\( x_{ik} \)$ = individual data points in group \( k \)
- $\( \bar{x}_k \)$ = mean of group \( k \)
- $\( n_k \)$ = number of data points in group \( k \)

#### 4. **Sum of Squares for Regression (SSR)**

In **linear regression**, the **sum of squares for regression (SSR)** measures the variation explained by the regression model. It is the difference between the predicted values and the overall mean.

$\[
SS_R = \sum_{i=1}^{n} (\hat{y}_i - \bar{y})^2
\]$
Where:
- $\( \hat{y}_i \)$ = predicted values
- $\( \bar{y} \)$ = mean of the observed data
- \( n \) = number of data points

#### 5. **Residual Sum of Squares (SSE)**

The **residual sum of squares (SSE)**, also known as the **sum of squared errors**, measures the unexplained variation by the model. It is the sum of the squared differences between observed and predicted values.

$\[
SS_E = \sum_{i=1}^{n} (y_i - \hat{y}_i)^2
\]$
Where:
- \( y_i \) = observed data points
- $\( \hat{y}_i \)$ = predicted values

---

### **Key Points about Sum of Squares**

1. **Measures of Variation**: 
   - The sum of squares represents the variation in data. A larger sum of squares indicates more variability in the data.
  
2. **Total Sum of Squares (SSₜ)**: 
   - This represents the total variation in the data from the overall mean and is decomposed into other components (e.g., SSB, SSW) in analyses like ANOVA or regression.

3. **Decomposition in ANOVA**: 
   - In **Analysis of Variance (ANOVA)**, the total variation in the data is broken into variation due to the factors being tested (SSB) and error (SSW). This helps assess whether the factors contribute significantly to the overall variation.

4. **Regression Analysis**: 
   - In **linear regression**, the total variation is decomposed into the explained variation (SSR) and the unexplained variation (SSE). The proportion of variation explained by the model is a key metric in assessing the goodness of fit (e.g., **R²**).

---

### **Example of Sum of Squares Calculation**

Suppose we have the following data for five students' test scores:

- Data: \( 70, 75, 80, 85, 90 \)

#### Step 1: Calculate the Mean $(\( \bar{x} \))$

$\[
\bar{x} = \frac{70 + 75 + 80 + 85 + 90}{5} = \frac{400}{5} = 80
\]$

#### Step 2: Calculate the Total Sum of Squares (SSₜ)

$\[
SS_t = (70 - 80)^2 + (75 - 80)^2 + (80 - 80)^2 + (85 - 80)^2 + (90 - 80)^2
\]$

$\[
SS_t = (-10)^2 + (-5)^2 + (0)^2 + (5)^2 + (10)^2
\]$

$\[
SS_t = 100 + 25 + 0 + 25 + 100 = 250
\]$

So, the **Total Sum of Squares (SSₜ)** is 250.

#### Step 3: Further Analysis in ANOVA or Regression

In ANOVA or regression, this total variation (250) would be further broken down into the variation explained by the model (e.g., between-group variation in ANOVA or explained by regression) and the unexplained variation (e.g., within-group variation in ANOVA or residual variation in regression).

---

### **Conclusion**

The **sum of squares** is a fundamental concept in statistics, measuring the variation or dispersion within a dataset. It is used in various statistical methods, such as ANOVA, regression analysis, and hypothesis testing, to assess the significance of data differences and model fits. By understanding and calculating the sum of squares, you can analyze how much of the variability is due to specific factors and how much is due to random chance or errors.
