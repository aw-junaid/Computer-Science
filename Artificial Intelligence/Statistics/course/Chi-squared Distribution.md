### **Chi-Squared Distribution (χ² Distribution)**

The **Chi-squared distribution** (denoted $\( \chi^2 \))$ is a widely used probability distribution in statistics, primarily used in hypothesis testing and for constructing confidence intervals, particularly in cases where the data involves categorical variables.

### **Definition:**

The chi-squared distribution is a special case of the **gamma distribution**. It is the distribution of a sum of the squares of \( k \) independent standard normal random variables. That is, if $\( Z_1, Z_2, ..., Z_k \)$ are independent random variables that each follow a standard normal distribution (i.e., $\( Z_i \sim N(0, 1) \)$), then the sum of their squares follows a chi-squared distribution:
$\[
\chi^2_k = Z_1^2 + Z_2^2 + \cdots + Z_k^2
\]$
where \( k \) is the number of degrees of freedom (df), which corresponds to the number of independent standard normal variables being summed.

### **Key Properties:**

1. **Degrees of Freedom (df):** 
   The shape of the chi-squared distribution depends on the number of **degrees of freedom (df)**, typically denoted by \( k \). The degrees of freedom are usually related to the number of variables or groups being analyzed.

2. **Shape of the Distribution:**
   - For \( k = 1 \), the chi-squared distribution is **right-skewed**.
   - As \( k \) increases, the distribution becomes less skewed and approaches a **normal distribution** as \( k \) becomes large (according to the **Central Limit Theorem**).
   - For large values of \( k \), the chi-squared distribution is approximately normal with a mean \( k \) and variance \( 2k \).

3. **Mean and Variance:**
   - **Mean** of $\( \chi^2_k \)$: $\( \mu = k \)$
   - **Variance** of $\( \chi^2_k \)$: $\( \sigma^2 = 2k \)$

4. **Skewness and Kurtosis:**
   - The **skewness** of the chi-squared distribution is $\( \frac{2}{\sqrt{k}} \)$, which decreases as the degrees of freedom increase.
   - The **kurtosis** is $\( \frac{12}{k} \)$, meaning that the distribution becomes less peaked as the degrees of freedom increase.

### **Applications of the Chi-Squared Distribution:**

1. **Goodness-of-Fit Test:**
   The chi-squared distribution is commonly used in the **Chi-Squared Goodness-of-Fit Test**, which tests whether a sample data matches a specified distribution. It compares the observed frequencies of a categorical variable with the expected frequencies under the null hypothesis.

   - **Hypothesis Testing**:
     - **Null hypothesis (H₀):** The observed data follows the expected distribution.
     - **Alternative hypothesis (H₁):** The observed data does not follow the expected distribution.

   The test statistic for the chi-squared goodness-of-fit test is:
   $\[
   \chi^2 = \sum \frac{(O_i - E_i)^2}{E_i}
   \]$
   where $\( O_i \)$ is the observed frequency for the $\( i \)$-th category, and $\( E_i \)$ is the expected frequency for the \( i \)-th category.

2. **Chi-Squared Test for Independence:**
   The **Chi-Squared Test for Independence** is used to determine if two categorical variables are independent of each other. It is commonly used in contingency tables to test if the distribution of one variable is independent of another.

   - **Null hypothesis (H₀):** The variables are independent.
   - **Alternative hypothesis (H₁):** The variables are dependent.

   The test statistic is calculated in a similar manner:
   $\[
   \chi^2 = \sum \frac{(O_{ij} - E_{ij})^2}{E_{ij}}
   \]$
   where $\( O_{ij} \)$ is the observed frequency in the \( i \)-th row and \( j \)-th column, and $\( E_{ij} \)$ is the expected frequency for that cell, computed based on the marginal totals.

3. **Confidence Intervals for Variance (Normal Distribution):**
   In cases where the data is normally distributed, the chi-squared distribution is used to construct confidence intervals for the population variance. If a sample has \( n \) observations and sample variance \( s^2 \), the confidence interval for the population variance \( \sigma^2 \) is given by:
   $\[
   \left( \frac{(n-1)s^2}{\chi^2_{\alpha/2, n-1}}, \frac{(n-1)s^2}{\chi^2_{1-\alpha/2, n-1}} \right)
   \]$
   where $\( \chi^2_{\alpha/2, n-1} \)$ and $\( \chi^2_{1-\alpha/2, n-1} \)$ are the critical values of the chi-squared distribution at the desired confidence level.

4. **Model Fitting and Residual Analysis:**
   The chi-squared distribution can also be used in model fitting (such as in **regression analysis**) and residual analysis, especially when examining the fit of observed versus predicted values in statistical models.

### **Properties of the Chi-Squared Distribution:**

- **Non-Negative**: Since it is the sum of squared normal variables, the chi-squared distribution can never take negative values. It is always **right-skewed** unless \( k \) is very large.
  
- **Asymmetry**: The distribution is skewed right for small \( k \), but the skewness decreases as \( k \) increases. As \( k \) grows, the distribution begins to approximate a normal distribution.

- **Critical Values**: The chi-squared distribution is used to define **critical values** for hypothesis tests. For a given level of significance (such as 0.05), the critical value depends on the degrees of freedom.

### **Chi-Squared Distribution Table:**

In practice, chi-squared distributions are often referenced through **chi-squared tables** that list the critical values for various degrees of freedom and significance levels. These tables are used to determine the threshold beyond which we reject the null hypothesis in hypothesis testing.

For example:
- For \( k = 3 \) degrees of freedom and a significance level of 0.05, the critical value is approximately **7.815**. This means that if the calculated chi-squared statistic exceeds 7.815, the null hypothesis would be rejected at the 5% significance level.

### **Example of a Chi-Squared Test for Independence:**

Suppose a study examines whether gender is associated with preference for a particular type of food. The observed frequencies in a 2x2 contingency table are as follows:

|               | Food A | Food B | Total |
|---------------|--------|--------|-------|
| Male          | 30     | 10     | 40    |
| Female        | 20     | 30     | 50    |
| **Total**     | 50     | 40     | 90    |

To test whether gender is independent of food preference, we would use the chi-squared test for independence:

1. Calculate the expected frequencies assuming independence:
   - $\( E_{Male, Food A} = \frac{(40)(50)}{90} = 22.22 \)$
   - $\( E_{Male, Food B} = \frac{(40)(40)}{90} = 17.78 \)$
   - $\( E_{Female, Food A} = \frac{(50)(50)}{90} = 27.78 \)$
   - $\( E_{Female, Food B} = \frac{(50)(40)}{90} = 22.22 \)$

2. Compute the chi-squared statistic:
   $\[
   \chi^2 = \sum \frac{(O_{ij} - E_{ij})^2}{E_{ij}} = \frac{(30 - 22.22)^2}{22.22} + \frac{(10 - 17.78)^2}{17.78} + \frac{(20 - 27.78)^2}{27.78} + \frac{(30 - 22.22)^2}{22.22}
   \]$

   After calculating, you would compare the test statistic to the chi-squared critical value from the table to determine whether to reject the null hypothesis.

### **Conclusion:**

The **Chi-squared distribution** is an essential distribution in statistics, particularly for categorical data analysis and hypothesis testing. It is used in a variety of statistical tests, including tests for goodness-of-fit, tests for independence, and tests related to the variance of a normal distribution. Understanding its properties and applications is crucial for interpreting data in fields such as epidemiology, economics, and social sciences.
