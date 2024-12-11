### **Skewness in Statistics**

**Skewness** is a measure of the asymmetry of the probability distribution of a random variable around its mean. It indicates whether the data is symmetrically distributed, skewed to the left, or skewed to the right.

---

### **Types of Skewness**

1. **Symmetric Distribution**:
   - If the data is perfectly symmetric, skewness is \(0\).
   - Example: Normal distribution.

2. **Positive Skewness (Right-Skewed)**:
   - The right tail of the distribution is longer or fatter than the left.
   - Mean > Median > Mode.
   - Example: Income distributions where a few high values dominate.

3. **Negative Skewness (Left-Skewed)**:
   - The left tail of the distribution is longer or fatter than the right.
   - Mean < Median < Mode.
   - Example: Test scores where most students perform well but a few perform poorly.

---

### **Formula for Skewness**

The **sample skewness** is calculated using:

$\[
g_1 = \frac{n}{(n-1)(n-2)} \sum_{i=1}^n \left( \frac{x_i - \bar{x}}{s} \right)^3
\]$

Where:
- $\( g_1 \)$: Skewness of the sample.
- \( n \): Number of data points.
- $\( x_i \)$: Individual data points.
- $\( \bar{x} \)$: Sample mean.
- \( s \): Sample standard deviation.

#### For a population, skewness is given by:

$\[
\text{Skewness} = \frac{\frac{1}{N} \sum_{i=1}^N (x_i - \mu)^3}{\sigma^3}
\]$

Where:
- $\( \mu \)$: Population mean.
- $\( \sigma \)$: Population standard deviation.

---

### **Interpretation of Skewness Values**

- $\( \text{Skewness} = 0 \)$: Symmetric distribution.
- $\( \text{Skewness} > 0 \)$: Positive (right) skew.
- $\( \text{Skewness} < 0 \)$: Negative (left) skew.

The **magnitude** of skewness indicates how asymmetrical the distribution is:
- Near \(0\): Approximately symmetric.
- Far from \(0\): Highly skewed.

---

### **Examples**

#### Example 1: Positive Skew
| Data Points: | 1, 2, 3, 4, 10 |
- Mean \(= 4\), Median \(= 3\), Mode \(= 2\).
- Skewness \(> 0\) (right-skewed).

#### Example 2: Negative Skew
| Data Points: | 1, 2, 6, 7, 8 |
- Mean \(= 4.8\), Median \(= 6\), Mode \(= 7\).
- Skewness \(< 0\) (left-skewed).

---

### **Applications**

1. **Descriptive Statistics**:
   - Identifying data symmetry or asymmetry.
2. **Model Selection**:
   - Skewed data may require non-normal models or transformations.
3. **Financial Analysis**:
   - Used to assess the distribution of asset returns.
4. **Quality Control**:
   - Detecting asymmetries in production processes.

---

### **Skewness and Normality**

- **Skewness Test**:
  - A small skewness value $(\(-0.5 \leq \text{Skewness} \leq 0.5\))$ indicates approximate symmetry.
  - Significant deviation from \(0\) suggests non-normality, requiring transformations for certain analyses.

Skewness provides insight into the shape of a dataset, helping in decision-making, model selection, and data interpretation.
