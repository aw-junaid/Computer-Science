### **Statistics: Essential Formulas**

Statistics encompasses a wide range of concepts and calculations. Below are key formulas grouped by their categories:

---

### **1. Measures of Central Tendency**

- **Arithmetic Mean**:
  $\[
  \bar{x} = \frac{\sum x_i}{n}
  \]$
  Where:
  - $\(x_i\)$: Individual data points.
  - \(n\): Number of data points.

- **Median (for Sorted Data)**:
```math
  \text{Median} =
  \begin{cases} 
  x_{\frac{n+1}{2}}, & \text{if } n \text{ is odd} \\
  \frac{x_{\frac{n}{2}} + x_{\frac{n}{2} + 1}}{2}, & \text{if } n \text{ is even}
  \end{cases}
```

- **Mode**:
  - The value(s) that appear most frequently.

---

### **2. Measures of Dispersion**

- **Range**:
  $\[
  \text{Range} = \text{Maximum Value} - \text{Minimum Value}
  \]$

- **Variance**:
  $\[
  \sigma^2 = \frac{\sum (x_i - \mu)^2}{N} \quad \text{(Population)}
  \]$
  
  $\[
  s^2 = \frac{\sum (x_i - \bar{x})^2}{n-1} \quad \text{(Sample)}
  \]$

- **Standard Deviation**:
  $\[
  \sigma = \sqrt{\sigma^2}, \quad s = \sqrt{s^2}
  \]$

- **Coefficient of Variation (CV)**:
  $\[
  \text{CV} = \frac{\text{Standard Deviation}}{\text{Mean}} \times 100
  \]$

---

### **3. Probability**

- **Probability of an Event**:
  $\[
  P(A) = \frac{\text{Number of favorable outcomes}}{\text{Total number of outcomes}}
  \]$

- **Addition Rule**:
  $\[
  P(A \cup B) = P(A) + P(B) - P(A \cap B)
  \]$

- **Multiplication Rule**:
  $\[
  P(A \cap B) = P(A) \cdot P(B | A)
  \]$

- **Bayes' Theorem**:
  $\[
  P(A | B) = \frac{P(B | A) \cdot P(A)}{P(B)}
  \]$

---

### **4. Hypothesis Testing**

- **Z-Score**:
  $\[
  Z = \frac{X - \mu}{\sigma}
  \]$

- **T-Statistic**:
  $\[
  t = \frac{\bar{x} - \mu}{\frac{s}{\sqrt{n}}}
  \]$

- **Chi-Square Statistic**:
  $\[
  \chi^2 = \sum \frac{(O_i - E_i)^2}{E_i}
  \]$

- **Pooled Variance $(\(t\)-test)$**:
  $\[
  s_p^2 = \frac{(n_1 - 1)s_1^2 + (n_2 - 1)s_2^2}{n_1 + n_2 - 2}
  \]$

---

### **5. Correlation and Regression**

- **Pearson Correlation Coefficient**:
  $\[
  r = \frac{\sum (x_i - \bar{x})(y_i - \bar{y})}{\sqrt{\sum (x_i - \bar{x})^2 \cdot \sum (y_i - \bar{y})^2}}
  \]$

- **Linear Regression Equation**:
  $\[
  Y = a + bX
  \]$
  Where:
  - $\(b = \frac{n\sum (x_i y_i) - \sum x_i \sum y_i}{n\sum x_i^2 - (\sum x_i)^2}\)$
  - $\(a = \bar{y} - b\bar{x}\)$

---

### **6. Probability Distributions**

- **Binomial Distribution**:
  $\[
  P(X = k) = \binom{n}{k} p^k (1-p)^{n-k}
  \]$

- **Normal Distribution (PDF)**:
  $\[
  f(x) = \frac{1}{\sigma \sqrt{2\pi}} e^{-\frac{(x - \mu)^2}{2\sigma^2}}
  \]$

- **Poisson Distribution**:
  $\[
  P(X = k) = \frac{\lambda^k e^{-\lambda}}{k!}
  \]$

- **Exponential Distribution (PDF)**:
  $\[
  f(x) = \lambda e^{-\lambda x}, \quad x \geq 0
  \]$

---

### **7. Sampling and Confidence Intervals**

- **Standard Error (SE)**:
  $\[
  SE = \frac{s}{\sqrt{n}}
  \]$

- **Confidence Interval for Mean $(\(Z\)-Based)$**:
  $\[
  \bar{x} \pm Z \cdot \frac{\sigma}{\sqrt{n}}
  \]$

---

### **8. Miscellaneous**

- **Skewness**:
  $\[
  \text{Skewness} = \frac{\frac{1}{n}\sum (x_i - \bar{x})^3}{\left(\frac{1}{n}\sum (x_i - \bar{x})^2\right)^{3/2}}
  \]$

- **Kurtosis**:
  $\[
  \text{Kurtosis} = \frac{\frac{1}{n}\sum (x_i - \bar{x})^4}{\left(\frac{1}{n}\sum (x_i - \bar{x})^2\right)^2} - 3
  \]$

---

These formulas form the foundation of statistics and are widely used in data analysis, probability theory, and inferential statistics. Let me know if you'd like a deeper explanation or application of any specific formula!
