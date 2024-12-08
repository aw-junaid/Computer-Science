### **Kolmogorov-Smirnov Test**

The **Kolmogorov-Smirnov (K-S) test** is a non-parametric statistical test used to determine whether a sample comes from a specific distribution (such as the normal distribution) or to compare two samples to see if they come from the same distribution. The test is based on the **Kolmogorov-Smirnov statistic**, which measures the largest difference between the empirical distribution function (EDF) of the sample and the cumulative distribution function (CDF) of the reference distribution, or between the EDFs of two samples.

The K-S test is widely used because it makes no assumptions about the distribution of the data, which makes it very versatile for a variety of applications in hypothesis testing.

### **Types of Kolmogorov-Smirnov Tests**

1. **One-Sample Kolmogorov-Smirnov Test**: This test compares the empirical distribution of a sample to a known theoretical distribution. The null hypothesis is that the sample follows the specified distribution, and the alternative hypothesis is that it does not.

   - **Null Hypothesis (H₀)**: The sample comes from the specified distribution (e.g., normal distribution).
   - **Alternative Hypothesis (H₁)**: The sample does not come from the specified distribution.

2. **Two-Sample Kolmogorov-Smirnov Test**: This test compares the empirical distributions of two independent samples to see if they are drawn from the same distribution. The null hypothesis is that both samples come from the same distribution.

   - **Null Hypothesis (H₀)**: The two samples come from the same distribution.
   - **Alternative Hypothesis (H₁)**: The two samples come from different distributions.

### **Kolmogorov-Smirnov Statistic**

The Kolmogorov-Smirnov statistic measures the maximum difference between the empirical distribution function (EDF) of the sample and the cumulative distribution function (CDF) of the reference distribution (for the one-sample case) or the maximum difference between the EDFs of the two samples (for the two-sample case).

#### For the One-Sample K-S Test:
- Let $\( F(x) \)$ be the CDF of the reference distribution (such as normal, exponential, etc.), and let $\( D_n \)$ be the largest difference between the EDF of the sample, $\( F_n(x) \)$, and the theoretical CDF, \( F(x) \):
  $\[
  D_n = \max_x \left| F_n(x) - F(x) \right|
  \]$

#### For the Two-Sample K-S Test:
- Let $\( F_n(x) \)$ and $\( G_m(x) \)$ be the EDFs of the two samples, and let $\( D_{nm} \)$ be the largest difference between the two EDFs:
  $\[
  D_{nm} = \max_x \left| F_n(x) - G_m(x) \right|
  \]$

### **Test Procedure**

1. **Step 1**: Calculate the Kolmogorov-Smirnov statistic $(\(D_n\)$ for one-sample, or $\(D_{nm}\)$ for two-sample).
2. **Step 2**: Compare the calculated $\(D_n\)$ (or $\(D_{nm}\))$ with the critical value from the K-S distribution table. The critical value depends on the sample size(s) and the chosen significance level (e.g., $\( \alpha = 0.05 \)$).
   - For large sample sizes, the critical value can be approximated using the formula:
     $\[
     D_n = \sqrt{\frac{-\ln(\alpha/2)}{2n}}
     \]$
   where \(n\) is the sample size and $\( \alpha \)$ is the significance level.
3. **Step 3**: Make a decision:
   - If the calculated statistic is greater than the critical value, reject the null hypothesis (i.e., conclude that the sample does not follow the specified distribution or the two samples come from different distributions).
   - If the calculated statistic is less than the critical value, do not reject the null hypothesis.

### **Interpretation**

- If the **p-value** of the test is smaller than the chosen significance level ($\( \alpha \))$, the null hypothesis is rejected, implying that the data do not follow the assumed distribution (in the one-sample case) or the two samples come from different distributions (in the two-sample case).
- If the **p-value** is larger than the significance level, we do not reject the null hypothesis, suggesting that there is insufficient evidence to conclude that the sample differs from the specified distribution (one-sample) or the two samples come from different distributions (two-sample).

### **Example: One-Sample K-S Test**

Suppose you have a sample of 100 observations and want to test if the data follows a normal distribution. You would:
1. Calculate the empirical distribution function (EDF) of your sample.
2. Compare it to the cumulative distribution function (CDF) of the normal distribution using the Kolmogorov-Smirnov statistic.
3. Use the K-S test to calculate the test statistic and compare it with the critical value from the table at a chosen significance level (e.g., $\( \alpha = 0.05 \))$.

If the test statistic is larger than the critical value, you reject the null hypothesis and conclude that the sample does not come from a normal distribution.

### **Example: Two-Sample K-S Test**

Suppose you have two independent samples and want to test if they come from the same distribution. You would:
1. Calculate the empirical distribution functions (EDFs) for both samples.
2. Compare the two EDFs using the Kolmogorov-Smirnov statistic.
3. Calculate the test statistic and compare it with the critical value.

If the test statistic is larger than the critical value, you reject the null hypothesis and conclude that the two samples come from different distributions.

### **Advantages of the Kolmogorov-Smirnov Test**

- **Non-parametric**: The K-S test does not assume any specific distribution for the data, making it very versatile.
- **Works for any continuous distribution**: It can be used for testing any distribution (normal, exponential, uniform, etc.) in the one-sample case or comparing two samples in the two-sample case.

### **Limitations of the Kolmogorov-Smirnov Test**

- **Sensitivity to sample size**: The K-S test can be overly sensitive to small sample sizes and may reject the null hypothesis too easily with large samples.
- **Not suitable for discrete data**: The K-S test is designed for continuous data and is not appropriate for discrete data without modifications.
- **Distributional assumptions**: Although the K-S test is non-parametric, in the one-sample case, it assumes that the parameters of the distribution (such as the mean and variance for a normal distribution) are known or estimated accurately.

### **Conclusion**

The **Kolmogorov-Smirnov test** is a powerful and flexible non-parametric test for assessing whether a sample follows a specific distribution or for comparing two independent samples to see if they come from the same distribution. Its applicability to various distributions and the fact that it does not rely on distributional assumptions make it a widely used tool in statistics, especially in goodness-of-fit testing and comparing empirical data to theoretical models.
