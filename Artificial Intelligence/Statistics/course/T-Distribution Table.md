### **T-Distribution Table**

The **T-distribution** (also called the Student’s T-distribution) is a probability distribution used in statistics when the sample size is small or the population standard deviation is unknown. It is similar to the normal distribution but has thicker tails, making it more appropriate for situations where there's more variability or uncertainty in estimating population parameters.

The **T-distribution table** helps in determining the **critical t-value** needed to calculate confidence intervals and conduct hypothesis testing for small sample sizes.

#### **Key Properties of the T-distribution**
1. **Shape**: Symmetrical and bell-shaped like the normal distribution, but with **heavier tails**. This allows for greater variability in small samples.
2. **Degrees of Freedom (df)**: The shape of the t-distribution depends on the **degrees of freedom (df)**, which typically is equal to \( n - 1 \) for a single sample, where \( n \) is the sample size.
3. **Usage**: The T-distribution is primarily used for:
   - **Confidence intervals** for the population mean (when the population standard deviation is unknown and the sample size is small).
   - **Hypothesis testing**, especially for small sample sizes or when population parameters are unknown.
   
---

### **Structure of the T-Distribution Table**

The table usually provides the **critical t-values** for different **degrees of freedom (df)** and **significance levels (α)**, typically for a one-tailed or two-tailed test.

#### **How to Use the T-Distribution Table**

1. **Identify Degrees of Freedom (df)**: 
   - For a one-sample t-test or paired t-test: $\( \text{df} = n - 1 \)$, where \( n \) is the sample size.
   - For an independent two-sample t-test: $\( \text{df} = n_1 + n_2 - 2 \)$, where \( n_1 \) and \( n_2 \) are the sizes of the two samples.

2. **Choose Significance Level (α)**:
   - For **two-tailed tests**: You would split α in half, using $\( \frac{\alpha}{2} \)$ for each tail of the distribution.
   - For **one-tailed tests**: Use α for the one tail.

3. **Find the Critical t-value**: 
   - Locate the corresponding **degrees of freedom** and **significance level** in the T-distribution table to find the critical t-value (denoted as $\( t_{\alpha/2} \) or \( t_{\alpha} \))$.

---

### **Example of a T-Distribution Table Layout**

| **df** | **0.10 (one-tailed)** | **0.05 (one-tailed)** | **0.025 (one-tailed)** | **0.10 (two-tailed)** | **0.05 (two-tailed)** | **0.025 (two-tailed)** |
|--------|----------------------|-----------------------|------------------------|-----------------------|-----------------------|------------------------|
| 1      | 6.314                | 12.706                | 31.821                 | 12.706                | 63.657                | 127.321                |
| 2      | 2.920                | 4.303                 | 6.205                  | 4.303                 | 9.925                 | 14.089                 |
| 3      | 2.353                | 3.182                 | 4.177                  | 3.182                 | 5.841                 | 6.943                  |
| 4      | 2.132                | 2.776                 | 3.495                  | 2.776                 | 4.604                 | 5.598                  |
| 5      | 2.015                | 2.571                 | 3.163                  | 2.571                 | 4.032                 | 4.773                  |
| 6      | 1.943                | 2.447                 | 2.933                  | 2.447                 | 3.707                 | 4.317                  |
| 7      | 1.895                | 2.365                 | 2.828                  | 2.365                 | 3.499                 | 4.029                  |
| 8      | 1.860                | 2.306                 | 2.750                  | 2.306                 | 3.355                 | 3.746                  |
| 9      | 1.833                | 2.262                 | 2.685                  | 2.262                 | 3.249                 | 3.499                  |
| 10     | 1.812                | 2.228                 | 2.636                  | 2.228                 | 3.169                 | 3.249                  |
| 20     | 1.725                | 2.086                 | 2.528                  | 2.086                 | 2.845                 | 3.164                  |

#### **Explanation of Columns**:
- **df** = degrees of freedom
- **0.10 (one-tailed)**, **0.05 (one-tailed)**, etc., represent the significance levels (α) for one-tailed or two-tailed tests.
- **Two-tailed** values are used when you want to test both extremes (e.g., $\( H_0: \mu = \mu_0 \) vs \( H_1: \mu \neq \mu_0 \))$.
- **One-tailed** values are used when testing a direction (e.g., $\( H_0: \mu \leq \mu_0 \)$ vs $\( H_1: \mu > \mu_0 \))$.

---

### **Example Calculation Using the T-Distribution Table**

Suppose you are conducting a **two-tailed t-test** at a significance level of **0.05** with a sample size of **10**.

1. **Degrees of Freedom (df)**:
   - $\( df = n - 1 = 10 - 1 = 9 \)$

2. **Significance Level**:
   - For a **two-tailed test** with \( \alpha = 0.05 \), we use **0.025** for each tail.

3. **Critical t-value**:
   - Using the T-distribution table for $\( df = 9 \)$ and $\( \alpha/2 = 0.025 \)$, the critical t-value is **2.262**.

Thus, if your calculated t-statistic is **greater than 2.262** or **less than -2.262**, you would reject the null hypothesis.

---

### **Conclusion**

The **T-distribution table** is an essential tool in hypothesis testing and confidence interval estimation, particularly for small sample sizes. It helps determine critical t-values based on the degrees of freedom and the chosen significance level. By comparing your calculated t-statistic with the critical value from the table, you can make decisions about statistical significance.
