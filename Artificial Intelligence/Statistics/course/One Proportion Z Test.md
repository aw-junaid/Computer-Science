### **One Proportion Z-Test**

The **One Proportion Z-Test** is a statistical test used to determine whether the proportion of a single sample significantly differs from a known or hypothesized population proportion. This test is applicable when dealing with categorical data.

---

### **Purpose**

- To test if the observed proportion $(\( \hat{p} \))$ from a sample differs significantly from a hypothesized population proportion $(\( p_0 \))$.
- Common in scenarios like opinion polls, quality control, and medical trials.

---

### **Assumptions**

1. The data is categorical (e.g., success/failure, yes/no).
2. The sample size is large enough to use the normal approximation:
   $\[
   n p_0 \geq 10 \quad \text{and} \quad n (1 - p_0) \geq 10
   \]$
   Where \(n\) is the sample size and \(p_0\) is the hypothesized proportion.
3. Random sampling or independence of observations.

---

### **Hypotheses**

1. **Null Hypothesis (\(H_0\))**:
   $\[
   H_0: p = p_0
   \]$
   The sample proportion is equal to the hypothesized proportion.

2. **Alternative Hypothesis $(\(H_a\))$**:
   - **Two-tailed**: $\(p \neq p_0\)$
   - **One-tailed** (greater): \(p > p_0\)
   - **One-tailed** (less): \(p < p_0\)

---

### **Test Statistic**

The test statistic (\(Z\)) is calculated using the formula:
$\[
Z = \frac{\hat{p} - p_0}{\sqrt{\frac{p_0 (1 - p_0)}{n}}}
\]$
Where:
- $\(\hat{p}\)$: Sample proportion $(\(\hat{p} = \frac{x}{n}\), where \(x\)$ is the number of successes).
- $\(p_0\)$: Hypothesized population proportion.
- \(n\): Sample size.

---

### **Decision Rule**

1. Compute the \(Z\)-statistic.
2. Compare the \(Z\)-statistic to critical values from the standard normal distribution:
   - For a significance level $(\(\alpha\))$ of 0.05:
     - Two-tailed: Critical values are \(-1.96\) and \(1.96\).
     - One-tailed: Critical value is \(1.645\) (for upper-tail) or \(-1.645\) (for lower-tail).
3. Alternatively, calculate the **p-value**:
   - Reject $\(H_0\)$ if \(p\)-value $\(< \alpha\)$.

---

### **Steps for the Test**

1. **State Hypotheses**:
   - Null and alternative hypotheses.

2. **Calculate Sample Proportion**:
   $\[
   \hat{p} = \frac{x}{n}
   \]$
   Where \(x\) is the number of successes.

3. **Compute Test Statistic**:
   Use the formula for \(Z\).

4. **Determine the p-value or Critical Value**:
   Use standard normal tables or statistical software.

5. **Make a Decision**:
   - Reject or fail to reject \(H_0\) based on the p-value or \(Z\)-score.

---

### **Example**

#### **Scenario**:
A survey claims that 60% of people prefer coffee over tea. You conduct a study with 200 participants, and 130 say they prefer coffee. Test the claim at a significance level of 0.05.

#### **Step 1: Hypotheses**:
- $\(H_0: p = 0.6\)$
- $\(H_a: p \neq 0.6\)$ (two-tailed test).

#### **Step 2: Sample Proportion**:
$\[
\hat{p} = \frac{x}{n} = \frac{130}{200} = 0.65
\]$

#### **Step 3: Test Statistic**:
$\[
Z = \frac{\hat{p} - p_0}{\sqrt{\frac{p_0 (1 - p_0)}{n}}} = \frac{0.65 - 0.6}{\sqrt{\frac{0.6 (1 - 0.6)}{200}}}
\]\$

$\[
Z = \frac{0.05}{\sqrt{\frac{0.6 \cdot 0.4}{200}}} = \frac{0.05}{\sqrt{0.0012}} = \frac{0.05}{0.03464} \approx 1.44
\]$

#### **Step 4: Compare to Critical Values**:
- For $\(\alpha = 0.05\)$, critical values are $\(-1.96\)$ and $\(1.96\)$.
- $\(Z = 1.44\)$ lies between $\(-1.96\)$ and $\(1.96\)$.

#### **Step 5: Decision**:
- Fail to reject $\(H_0\)$.
- There is insufficient evidence to claim that the proportion differs from 60%.

---

### **Applications**

1. **Market Research**:
   - Test if a proportion of customers prefers one product over another.

2. **Public Health**:
   - Determine the proportion of the population with a specific health condition.

3. **Quality Control**:
   - Check if the defect rate in a manufacturing process exceeds the acceptable limit.

4. **Elections**:
   - Assess whether the proportion of votes for a candidate meets a specific target.

---

### **Conclusion**

The **One Proportion Z-Test** is a fundamental tool for hypothesis testing with categorical data. It provides a reliable method for comparing sample proportions against a hypothesized value, aiding in decision-making across various fields.
