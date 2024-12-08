### **Normal Distribution**

The **Normal Distribution**, also known as the **Gaussian Distribution**, is one of the most important probability distributions in statistics. It models a wide range of natural phenomena and forms the basis for many statistical methods.

---

### **Key Characteristics**

1. **Symmetrical Shape**:
   - The distribution is bell-shaped and symmetric about its mean.

2. **Parameters**:
   - **Mean $(\(\mu\))$**: The central location of the distribution.
   - **Standard Deviation $(\(\sigma\))$**: Controls the spread or dispersion of the distribution.
   - Variance is $\(\sigma^2\)$.

3. **Probability Density Function (PDF)**:
   - The PDF is given by:
     $\[
     f(x; \mu, \sigma) = \frac{1}{\sqrt{2 \pi \sigma^2}} e^{-\frac{(x - \mu)^2}{2 \sigma^2}}
     \]$
     Where:
     - \(x\): The variable of interest.
     - $\(\mu\)$: Mean.
     - $\(\sigma\)$: Standard deviation.

4. **Total Area Under the Curve**:
   - The total area under the curve is 1, representing the total probability.

5. **68-95-99.7 Rule** (Empirical Rule):
   - Approximately 68% of data lies within 1 standard deviation $(\(\mu \pm \sigma\))$.
   - About 95% lies within 2 standard deviations $(\(\mu \pm 2\sigma\))$.
   - Nearly 99.7% lies within 3 standard deviations $(\(\mu \pm 3\sigma\))$.

---

### **Properties**

1. **Symmetry**:
   - The distribution is perfectly symmetric around the mean \(\mu\).

2. **Mean, Median, and Mode**:
   - For a normal distribution, these are all equal and located at \(\mu\).

3. **Asymptotic**:
   - The tails of the distribution approach the x-axis but never touch it.

4. **Standard Normal Distribution**:
   - A special case where $\(\mu = 0\)$ and $\(\sigma = 1\)$.

---

### **Cumulative Distribution Function (CDF)**

The CDF gives the probability that a random variable \(X\) is less than or equal to a value \(x\):
$\[
F(x; \mu, \sigma) = \int_{-\infty}^{x} f(t; \mu, \sigma) \, dt
\]$
For practical purposes, CDF values are often obtained using statistical tables or software.

---

### **Standard Normal Distribution**

To simplify calculations, any normal distribution can be transformed into the **standard normal distribution** using the **Z-score**:
$\[
Z = \frac{X - \mu}{\sigma}
\]$
Where:
- \(Z\): Standardized value.
- \(X\): Random variable.
- $\(\mu\)$: Mean.
- $\(\sigma\)$: Standard deviation.

---

### **Applications**

1. **Natural Phenomena**:
   - Heights, weights, test scores, and measurement errors often follow a normal distribution.

2. **Statistical Inference**:
   - The normal distribution underpins many statistical methods, including hypothesis testing and confidence intervals.

3. **Finance**:
   - Models stock price returns and risk.

4. **Quality Control**:
   - Used to monitor process variability and performance.

---

### **Examples**

#### **Example 1: Heights of Individuals**

**Scenario**:
- Assume the heights of adult males follow a normal distribution with $\(\mu = 175 \, \text{cm}\) and \(\sigma = 10 \, \text{cm}\)$.

**Question**:
What percentage of adult males are between 165 cm and 185 cm?

**Solution**:
1. Convert to Z-scores:
   $\[
   Z_1 = \frac{165 - 175}{10} = -1, \quad Z_2 = \frac{185 - 175}{10} = 1
   \]$
2. Use the standard normal table or software to find probabilities:
   - $\(P(Z \leq 1) = 0.8413\)$
   - $\(P(Z \leq -1) = 0.1587\)$
3. Subtract:
   $\[
   P(165 \leq X \leq 185) = 0.8413 - 0.1587 = 0.6826
   \]$
   About 68.26% of males are within this height range.

---

#### **Example 2: SAT Scores**

**Scenario**:
- SAT scores follow a normal distribution with $\(\mu = 1050\)$ and $\(\sigma = 200\)$.

**Question**:
What is the probability of scoring above 1300?

**Solution**:
1. Convert to Z-score:
   $\[
   Z = \frac{1300 - 1050}{200} = 1.25
   \]$
2. Find \(P(Z > 1.25)\) using the standard normal table:
   - $\(P(Z > 1.25) = 1 - P(Z \leq 1.25)\)$
   - $\(P(Z \leq 1.25) = 0.8944\)$
   $\[
   P(Z > 1.25) = 1 - 0.8944 = 0.1056
   \]$
   About 10.56% of students score above 1300.

---

### **Key Features of the Normal Curve**

1. **Symmetry**:
   - Perfectly symmetrical around the mean $\(\mu\)$.

2. **Peak at the Mean**:
   - The highest point occurs at $\(x = \mu\)$.

3. **Tails Extend Infinitely**:
   - The probability decreases but never reaches zero.

---

### **Limitations**

- The normal distribution is often an approximation and assumes:
  1. Data is continuous.
  2. Symmetry, which may not hold for skewed data.
- Outliers or non-normal data require alternative models.

---

### **Conclusion**

The **Normal Distribution** is a cornerstone of statistics, with applications across various disciplines. Its simplicity and mathematical properties make it a fundamental tool for modeling and analyzing data.
