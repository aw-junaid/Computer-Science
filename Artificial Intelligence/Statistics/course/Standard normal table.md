### **Standard Normal Table**

The **Standard Normal Table** (also known as the Z-table) is a reference table used in statistics to find the probabilities associated with the standard normal distribution. It provides the cumulative probability (\(P(Z \leq z)\)) for a given \(z\)-score, which represents the number of standard deviations a data point is from the mean.

---

### **Key Features of the Standard Normal Table**

1. **Standard Normal Distribution**:
   - A normal distribution with:
     - Mean $(\(\mu\))$ = 0
     - Standard deviation $(\(\sigma\))$ = 1.

2. **Z-Score**:
   - Represents the number of standard deviations a value is from the mean:
     $\[
     Z = \frac{X - \mu}{\sigma}
     \]$
   - Where:
     - \(X\): Observed value.
     - $\(\mu\)$: Population mean.
     - $\(\sigma\)$: Population standard deviation.

3. **Cumulative Probability**:
   - The table gives the area under the standard normal curve to the left of the \(z\)-score.

---

### **How to Use the Standard Normal Table**

#### **Steps**:
1. **Compute the Z-Score**:
   - Use the formula $\(Z = \frac{X - \mu}{\sigma}\)$.

2. **Locate the Row and Column**:
   - Find the row corresponding to the first two decimal places of the \(z\)-score.
   - Find the column corresponding to the second decimal place.

3. **Read the Cumulative Probability**:
   - The value at the intersection is $\(P(Z \leq z)\)$, the probability to the left of the \(z\)-score.

---

### **Example**

#### Example 1: Find $\(P(Z \leq 1.25)\)$
1. **Z-Score**:
   \(Z = 1.25\).

2. **Locate Row and Column**:
   - Row: \(1.2\).
   - Column: \(0.05\).

3. **Read Value**:
   - From the table, $\(P(Z \leq 1.25) = 0.8944\)$.

#### Example 2: Find $\(P(Z > 1.25)\)$
- Use the complement rule:
  $\[
  P(Z > 1.25) = 1 - P(Z \leq 1.25) = 1 - 0.8944 = 0.1056.
  \]$

---

### **Applications of the Standard Normal Table**

1. **Hypothesis Testing**:
   - Determine p-values to decide whether to reject the null hypothesis.
2. **Confidence Intervals**:
   - Find critical \(z\)-values for confidence levels (e.g., \(Z = 1.96\) for a 95% confidence interval).
3. **Probability Calculations**:
   - Compute probabilities for standard normal or normal distributions.

---

### **Table Structure**

Below is an excerpt of a standard normal table:

| \(Z\) | 0.00   | 0.01   | 0.02   | 0.03   | 0.04   | 0.05   |
|-------|--------|--------|--------|--------|--------|--------|
| 0.0   | 0.5000 | 0.5040 | 0.5080 | 0.5120 | 0.5160 | 0.5199 |
| 0.1   | 0.5398 | 0.5438 | 0.5478 | 0.5517 | 0.5557 | 0.5596 |
| 0.2   | 0.5793 | 0.5832 | 0.5871 | 0.5910 | 0.5948 | 0.5987 |
| 1.2   | 0.8849 | 0.8869 | 0.8888 | 0.8907 | 0.8925 | 0.8944 |

---

### **Tips for Using the Table**

1. For negative \(z\)-scores:
   - Use symmetry: $\(P(Z \leq -z) = 1 - P(Z \leq z)\)$.

2. For cumulative probabilities:
   - Always interpret as the area to the **left** of the \(z\)-score.

3. Online tools:
   - Z-scores can also be computed using statistical software (e.g., Excel, Python, or R).

The **Standard Normal Table** is an essential tool for solving problems related to the normal distribution, offering precise cumulative probabilities based on \(z\)-scores.
