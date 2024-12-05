### **F Test Table (Critical Values of the F Distribution)**

The **F Test** is used to compare variances and is commonly used in the context of **Analysis of Variance (ANOVA)** or when comparing two population variances. To perform an F-test, you need to refer to an **F-distribution table** to find the critical value of F for a given **significance level (α)** and **degrees of freedom** for the numerator and denominator.

#### **Key Parameters for F Test Table**

1. **Degrees of Freedom (df)**:
   - **Numerator degrees of freedom $(\(df_1\))$**: The degrees of freedom associated with the variance in the numerator (usually for the group with the larger variance).
   - **Denominator degrees of freedom $(\(df_2\))$**: The degrees of freedom associated with the variance in the denominator (usually for the group with the smaller variance).

2. **Significance Level (α)**: The probability of rejecting the null hypothesis when it is true. Common significance levels are 0.05, 0.01, and 0.10.

3. **Critical F Value $(\(F_{\text{crit}}\))$**: The value that the calculated F-statistic must exceed to reject the null hypothesis.

#### **Steps to Use an F Test Table**

1. **Identify the Degrees of Freedom**:
   - For the numerator: $\(df_1 = n_1 - 1\)$, where $\(n_1\)$ is the sample size of the first group.
   - For the denominator: $\(df_2 = n_2 - 1\)$, where $\(n_2\)$ is the sample size of the second group.

2. **Determine the Significance Level** (\( \alpha \)).

3. **Look up the Critical Value**:
   - Use the F-table with the degrees of freedom $\(df_1\)$ (numerator) and $\(df_2\)$ (denominator), and the desired significance level (usually 0.05 for a 95% confidence level).
   - Find the critical F value corresponding to these degrees of freedom and significance level.

4. **Compare the Calculated F-statistic** to the Critical F Value:
   - If the **calculated F-statistic** is greater than the **critical F value**, reject the null hypothesis.
   - If the **calculated F-statistic** is less than or equal to the **critical F value**, fail to reject the null hypothesis.

#### **F Test Table Example**

Here's a simplified F-test table with degrees of freedom $\(df_1 = 1, 2, 3\)$ (numerator) and $\(df_2 = 1, 2, 3\)$ (denominator) at a significance level of **0.05**:

| **Numerator df** $\(\text{(df}_1\text{)}\)$ / **Denominator df** $\(\text{(df}_2\text{)}\)$ | 1     | 2     | 3     | 4     | 5     |
|-----------------|-------|-------|-------|-------|-------|
| **1**           | 161.45| 199.50| 215.70| 224.60| 230.16|
| **2**           | 18.51 | 19.00 | 19.20 | 19.25 | 19.28 |
| **3**           | 10.13 | 9.55  | 9.28  | 9.13  | 9.06  |
| **4**           | 7.71  | 7.31  | 7.08  | 7.00  | 6.94  |
| **5**           | 6.61  | 6.34  | 6.17  | 6.11  | 6.06  |

#### **Example Use of the F-Test Table**

Suppose you want to test the hypothesis that the variances of two samples are equal. You have:

- Sample 1: $\(n_1 = 10\), \(s_1^2 = 20\)$ (variance for group 1).
- Sample 2: $\(n_2 = 12\), \(s_2^2 = 10\)$ (variance for group 2).
- Significance level $\(\alpha = 0.05\)$.

1. **Degrees of Freedom**:
   - For the numerator $(\(df_1\))$: $\(n_1 - 1 = 10 - 1 = 9\)$.
   - For the denominator $(\(df_2\))$: $\(n_2 - 1 = 12 - 1 = 11\)$.

2. **Look up the critical value for \(df_1 = 9\) and \(df_2 = 11\)** at \(\alpha = 0.05\) (from the F-table). Using statistical software or more detailed F-tables, we find that the critical value is **3.48**.

3. **Calculate the F-statistic**:
   $\[
   F = \frac{s_1^2}{s_2^2} = \frac{20}{10} = 2
   \]$

4. **Compare the calculated F-statistic with the critical value**:
   - Since \(F = 2\) is **less than** the critical value of 3.48, we **fail to reject the null hypothesis** and conclude that there is no significant difference between the variances of the two samples.

#### **Conclusion**

An **F-test table** provides critical F values based on the degrees of freedom for both the numerator and denominator of the F-statistic, and the significance level (\( \alpha \)). By comparing the calculated F-statistic to the critical value from the table, you can determine whether to reject or fail to reject the null hypothesis in variance comparisons or ANOVA tests.
