### **McNemar Test**

The **McNemar test** is a non-parametric statistical test used to determine whether there is a significant difference between paired proportions. It is typically applied to data in a 2x2 contingency table format and is used for repeated measures or matched pairs, such as before-and-after studies or case-control studies.

---

### **1. Purpose of the McNemar Test**

- It is designed to evaluate the consistency or change in responses for paired categorical data.
- The test is used when the same subjects are measured twice under different conditions (e.g., treatment vs. control) or when there are matched pairs in the data (e.g., twins or matched case-control pairs).

---

### **2. When to Use the McNemar Test**

- **Paired categorical data**: Both measures are binary (e.g., yes/no, success/failure, 0/1).
- **2x2 contingency table**: The data should be organized as follows:

|               | Condition B = 1 | Condition B = 0 | Total |
|---------------|-----------------|-----------------|-------|
| **Condition A = 1** | \( a \)             | \( b \)             | \( a + b \) |
| **Condition A = 0** | \( c \)             | \( d \)             | \( c + d \) |
| **Total**     | \( a + c \)       | \( b + d \)       | \( n \)     |

Where:
- \( a \) and \( d \) are agreements (both conditions give the same result).
- \( b \) and \( c \) are disagreements (differences between the two conditions).

The McNemar test focuses on the off-diagonal elements (\( b \) and \( c \)) to assess if there is a significant difference.

---

### **3. Test Hypotheses**

- **Null Hypothesis $(\( H_0 \))$**:
  The proportions of disagreements are equal. Mathematically:
  $\[
  H_0: p_b = p_c
  \]$

- **Alternative Hypothesis $(\( H_a \))$**:
  The proportions of disagreements are not equal. Mathematically:
  $\[
  H_a: p_b \neq p_c
  \]$

---

### **4. Test Statistic**

The McNemar test statistic is based on the off-diagonal elements of the table:

$\[
\chi^2 = \frac{(b - c)^2}{b + c}
\]$

Where:
- \( b \): Number of cases where Condition A = 1 and Condition B = 0.
- \( c \): Number of cases where Condition A = 0 and Condition B = 1.

This statistic follows a **chi-squared distribution** with 1 degree of freedom.

---

### **5. Assumptions**

1. The data are **paired or matched**.
2. The outcomes for each pair are **binary**.
3. The test is most reliable when $\( b + c \geq 10 \)$. For smaller sample sizes, use the **exact McNemar test**, which employs a binomial distribution.

---

### **6. Steps to Perform the McNemar Test**

1. Construct a **2x2 contingency table** from the paired data.
2. Identify the counts \( b \) and \( c \) from the table.
3. Calculate the test statistic:
   $\[
   \chi^2 = \frac{(b - c)^2}{b + c}
   \]$
4. Compare the test statistic to the critical value from the chi-squared distribution with 1 degree of freedom at the desired significance level (e.g., $\( \alpha = 0.05 \))$.
   - Critical value at $\( \alpha = 0.05 \)$ is approximately \( 3.841 \).
5. If $\( \chi^2 \)$ is greater than the critical value, reject \( H_0 \), indicating a significant difference.

---

### **7. Exact McNemar Test (Binomial Test)**

For small sample sizes $(\( b + c < 10 \))$, the exact McNemar test is used. The test is based on the binomial distribution:

```math
p = 2 \times \text{min}\left\{P(X \geq b | b+c), P(X \leq b | b+c)\right\}
```

Where $\( X \sim \text{Binomial}(n = b+c, p = 0.5) \)$.

---

### **8. Example**

**Scenario**: A medical researcher wants to evaluate if a new treatment affects recovery rates. A group of 100 patients is assessed before and after the treatment, and the results are as follows:

|               | After Recovery (Yes) | After Recovery (No) | Total |
|---------------|-----------------------|----------------------|-------|
| **Before Recovery (Yes)** | 40                    | 10                   | 50    |
| **Before Recovery (No)**  | 30                    | 20                   | 50    |
| **Total**       | 70                    | 30                   | 100   |

Here:
- \( b = 10 \): Patients who recovered before but not after.
- \( c = 30 \): Patients who didn’t recover before but recovered after.

**Step 1**: Calculate the test statistic:
$\[
\chi^2 = \frac{(b - c)^2}{b + c} = \frac{(10 - 30)^2}{10 + 30} = \frac{400}{40} = 10
\]$

**Step 2**: Compare to the critical value $(\( 3.841 \)$ for $\( \alpha = 0.05 \))$.

**Conclusion**:
Since $\( 10 > 3.841 \)$, reject $\( H_0 \)$. There is a significant difference in recovery rates before and after the treatment.

---

### **9. Applications of the McNemar Test**

1. **Medical Studies**:
   - Comparing pre- and post-treatment outcomes in patients.
   
2. **Marketing Research**:
   - Evaluating customer preferences before and after a campaign.

3. **Behavioral Sciences**:
   - Assessing changes in attitudes or behaviors over time.

4. **Education**:
   - Measuring changes in students’ performance before and after an intervention.

---

### **10. Limitations**

1. Requires **paired data** and cannot be used for independent samples.
2. Assumes a relatively large number of discordant pairs $(\( b + c \geq 10 \))$.
3. For unbalanced data or small sample sizes, the exact McNemar test is preferable.

---

### **Conclusion**

The McNemar test is a simple yet powerful tool for analyzing changes in paired categorical data. By focusing on discordant pairs, it provides a straightforward method to evaluate whether an intervention or condition has a statistically significant effect on outcomes.
