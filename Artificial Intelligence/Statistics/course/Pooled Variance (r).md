### **Pooled Variance in Statistics**

In statistics, **pooled variance** is an estimate of the common variance when you are comparing two or more groups that are assumed to have the same variance. It combines the variances from different groups or samples into a single estimate. This is particularly useful when performing hypothesis testing (like t-tests) or analysis of variance (ANOVA) where we assume that the variance across groups is the same.

---

### **Formula for Pooled Variance**

The **pooled variance** is calculated by weighting the variances of each group according to their degrees of freedom. The formula for pooled variance when you have two groups (sample 1 and sample 2) is:

$\[
s_p^2 = \frac{(n_1 - 1)s_1^2 + (n_2 - 1)s_2^2}{n_1 + n_2 - 2}
\]$

Where:
- $\(s_p^2\)$ = pooled variance
- $\(n_1, n_2\)$ = sample sizes of groups 1 and 2, respectively
- $\(s_1^2, s_2^2\)$ = sample variances of groups 1 and 2, respectively
- $\(n_1 - 1\)$ and $\(n_2 - 1\)$ = degrees of freedom for each sample

The degrees of freedom for each sample are \(n_1 - 1\) and \(n_2 - 1\) because the variance is based on the deviation from the sample mean.

---

### **General Formula for Multiple Groups**

When you have more than two groups, the pooled variance is generalized as:

$\[
s_p^2 = \frac{\sum_{i=1}^{k} (n_i - 1) s_i^2}{\sum_{i=1}^{k} (n_i - 1)}
\]$

Where:
- \(k\) = number of groups
- $\(n_i\)$ = sample size of group \(i\)
- $\(s_i^2\)$ = sample variance of group \(i\)

This formula weights the variances of the different groups by their respective degrees of freedom.

---

### **Interpretation of Pooled Variance**

- The pooled variance is a weighted average of the variances from all the groups. Groups with larger sample sizes have more influence on the final pooled variance.
- The pooled variance assumes that the populations from which the samples are drawn have the same variance (homogeneity of variance).

---

### **Example of Pooled Variance Calculation**

Suppose you have two groups with the following data:

| Group | Sample Size (\(n\)) | Sample Variance $(\(s^2\))$ |
|-------|---------------------|--------------------------|
| 1     | 10                  | 4.5                      |
| 2     | 12                  | 5.2                      |

We want to calculate the pooled variance.

1. **Step 1: Calculate the degrees of freedom for each group**:
   - For group 1: $\(n_1 - 1 = 10 - 1 = 9\)$
   - For group 2: $\(n_2 - 1 = 12 - 1 = 11\)$

2. **Step 2: Apply the formula**:

$\[
s_p^2 = \frac{(9)(4.5) + (11)(5.2)}{9 + 11}
\]$

$\[
s_p^2 = \frac{40.5 + 57.2}{20}
\]$

$\[
s_p^2 = \frac{97.7}{20} = 4.885
\]$

So, the pooled variance is **4.885**.

---

### **When to Use Pooled Variance**

Pooled variance is used in situations where you are comparing two or more groups and want to assume that the groups come from populations with the same variance. This assumption is key in tests like the **t-test** (specifically the **two-sample t-test for equal variances**) and **ANOVA**, which rely on the pooled variance for calculating test statistics.

---

### **Assumptions for Pooled Variance**

1. **Equal Variance Assumption**:
   - The primary assumption behind pooling variances is that the populations from which the samples are drawn have the same variance (homoscedasticity). This assumption is tested before performing a pooled variance calculation.
   
2. **Independence of Groups**:
   - The groups or samples should be independent of each other.

3. **Normality**:
   - The data within each group should be approximately normally distributed, although the pooled variance method is somewhat robust to violations of normality when sample sizes are large.

---

### **Conclusion**

**Pooled variance** is a method used to estimate a common variance across multiple groups under the assumption that the groups have the same variance. It is useful for hypothesis testing, particularly when comparing means across groups (e.g., in t-tests or ANOVA). By weighting the variances of each group based on sample size and degrees of freedom, pooled variance provides a more accurate estimate of the population variance when multiple groups are involved.
