### **Interval Estimation**

**Interval estimation** is a method used in statistics to estimate an unknown population parameter (such as a population mean or proportion) by providing a range of values, called a **confidence interval** (CI), within which the parameter is likely to lie. Instead of giving a single estimate (point estimate), interval estimation gives a range, offering more information about the uncertainty associated with the estimate.

### **Key Concepts in Interval Estimation**

1. **Point Estimate**: A single value used to estimate an unknown population parameter. For example, the sample mean $(\(\bar{x}\))$ is a point estimate for the population mean $(\(\mu\))$.
   
2. **Confidence Interval (CI)**: A range of values, constructed from the sample data, which is believed to contain the true population parameter with a certain level of confidence. The confidence interval is typically expressed as:
   $\[
   \text{CI} = \left[ \text{Lower Bound}, \text{Upper Bound} \right]
   \]$
   
3. **Confidence Level**: The probability that the confidence interval contains the true population parameter. A common confidence level is 95%, meaning there is a 95% probability that the true parameter lies within the interval.

### **General Formula for Confidence Interval**

For many parameters (like the population mean), the confidence interval is calculated using the following general formula:

$\[
\text{Confidence Interval} = \hat{\theta} \pm Z_{\alpha/2} \times \text{Standard Error of } \hat{\theta}
\]$

Where:
- $\(\hat{\theta}\)$ is the point estimate (such as the sample mean $\(\bar{x}\))$.
- $\(Z_{\alpha/2}\)$ is the **Z-value** corresponding to the desired confidence level (for a 95% CI, $\(Z_{\alpha/2} \approx 1.96\))$.
- The **Standard Error** (SE) depends on the type of data and the parameter being estimated. For the mean, the standard error is given by:
  $\[
  SE = \frac{\sigma}{\sqrt{n}}
  \]$
  where $\(\sigma\)$ is the population standard deviation (or sample standard deviation if \(\sigma\) is unknown) and \(n\) is the sample size.

### **Example: Confidence Interval for a Population Mean (Known \(\sigma\))**

Let’s assume a sample of size \(n = 50\) has a sample mean $\(\bar{x} = 100\)$ and a population standard deviation $\(\sigma = 15\)$. We want to calculate the 95% confidence interval for the population mean.

1. **Step 1**: Find the Z-value for a 95% confidence level. For a 95% confidence level, $\(Z_{\alpha/2} = 1.96\)$.

2. **Step 2**: Calculate the standard error:
   $\[
   SE = \frac{15}{\sqrt{50}} = \frac{15}{7.071} \approx 2.121
   \]$

3. **Step 3**: Compute the confidence interval:
   $\[
   \text{CI} = 100 \pm 1.96 \times 2.121 \approx 100 \pm 4.16
   \]$
   So, the confidence interval is approximately:
   $\[
   \left[ 95.84, 104.16 \right]
   \]$

Thus, we are 95% confident that the true population mean lies between 95.84 and 104.16.

### **Confidence Interval for a Population Proportion**

If you're estimating a population proportion \(p\), the confidence interval for \(p\) is calculated differently. The general formula for the confidence interval for a population proportion is:

$\[
\text{CI for } p = \hat{p} \pm Z_{\alpha/2} \times \sqrt{\frac{\hat{p}(1 - \hat{p})}{n}}
\]$

Where:
- $\(\hat{p}\)$ is the sample proportion.
- \(n\) is the sample size.

### **Example: Confidence Interval for a Proportion**

Suppose a survey of 400 people shows that 240 of them favor a certain product, so the sample proportion is:

$\[
\hat{p} = \frac{240}{400} = 0.6
\]$

We want to calculate a 95% confidence interval for the population proportion. For a 95% confidence level, \(Z_{\alpha/2} = 1.96\).

1. **Step 1**: Calculate the standard error:
   $\[
   SE = \sqrt{\frac{0.6(1 - 0.6)}{400}} = \sqrt{\frac{0.24}{400}} = \sqrt{0.0006} \approx 0.0245
   \]$

2. **Step 2**: Compute the confidence interval:
   $\[
   \text{CI} = 0.6 \pm 1.96 \times 0.0245 \approx 0.6 \pm 0.048
   \]$
   So, the confidence interval is:
   $\[
   \left[ 0.552, 0.648 \right]
   \]$

Thus, we are 95% confident that the true population proportion lies between 0.552 and 0.648.

### **Factors Affecting the Width of a Confidence Interval**

The width of a confidence interval is influenced by several factors:
1. **Sample Size (n)**: Larger sample sizes result in narrower confidence intervals because they reduce the standard error.
2. **Confidence Level**: Higher confidence levels (e.g., 99%) lead to wider intervals because we want to be more certain that the interval contains the true parameter.
3. **Population Variability**: Higher variability in the population (larger $\(\sigma\))$ results in wider confidence intervals.

### **Interpretation of Confidence Intervals**

A 95% confidence interval means that if you were to take many samples and construct a confidence interval from each sample, about 95% of those intervals would contain the true population parameter. However, for a given sample, we do not know whether the interval actually contains the true parameter—there’s always some level of uncertainty.

### **Applications of Interval Estimation**

- **Polls and Surveys**: Interval estimation is widely used in political polling and market research to estimate population proportions with a certain degree of confidence.
- **Quality Control**: In manufacturing and quality control, confidence intervals are used to estimate the population mean or proportion of defective items in a production lot.
- **Scientific Research**: Researchers use confidence intervals to estimate population parameters, such as the mean height of a species or the effect of a new treatment.

### **Conclusion**

Interval estimation provides a more informative and reliable way to estimate population parameters than point estimation. By giving a range of values, it accounts for the uncertainty inherent in sampling and helps make more informed decisions based on the data.
