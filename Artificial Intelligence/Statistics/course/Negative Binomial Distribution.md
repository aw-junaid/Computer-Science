### **Negative Binomial Distribution**

The **Negative Binomial Distribution** models the number of trials required to achieve a fixed number of successes in a sequence of independent and identically distributed Bernoulli trials. It is particularly useful when analyzing over-dispersed count data where variance exceeds the mean.

---

### **Key Characteristics**

1. **Trials**:
   - The experiment consists of repeated independent trials.

2. **Outcomes**:
   - Each trial results in either a success or a failure.

3. **Fixed Number of Successes (\(r\))**:
   - The distribution focuses on the number of trials needed to achieve \(r\) successes.

4. **Probability of Success (\(p\))**:
   - Each trial has the same probability of success, \(p\).

5. **Random Variable (\(X\))**:
   - The number of failures before achieving \(r\) successes.

---

### **Probability Mass Function (PMF)**

The probability of observing \(x\) failures before achieving \(r\) successes is given by:

$\[
P(X = x) = \binom{x + r - 1}{x} p^r (1 - p)^x
\]$

Where:
- $\( \binom{x + r - 1}{x} = \frac{(x + r - 1)!}{x! \, (r - 1)!} \)$: Binomial coefficient.
- $\( x \geq 0 \)$: Number of failures.
- $\( r > 0 \)$: Number of successes.
- $\( 0 < p \leq 1 \)$: Probability of success.

---

### **Mean and Variance**

1. **Mean**:
   $\[
   E(X) = \frac{r(1 - p)}{p}
   \]$

2. **Variance**:
   $\[
   \text{Var}(X) = \frac{r(1 - p)}{p^2}
   \]$

---

### **Relationship to Other Distributions**

1. **Binomial Distribution**:
   - The negative binomial distribution is a generalization of the geometric distribution (a special case of the binomial distribution).
   - When \( r = 1 \), it simplifies to the **geometric distribution**.

2. **Poisson Distribution**:
   - When \( r \) is large and \( p \) is small, the negative binomial distribution approximates a **Poisson distribution**.

---

### **Examples**

#### **Example 1: Coin Tosses**

**Scenario**:
- You flip a coin with a probability of heads \( p = 0.5 \).
- You want to observe \( r = 3 \) heads.

**Question**:
What is the probability that you will get exactly \( x = 2 \) tails before achieving 3 heads?

**Solution**:
- Use the PMF:
  $\[
  P(X = 2) = \binom{2 + 3 - 1}{2} (0.5)^3 (1 - 0.5)^2
  \]$
  
  $\[
  P(X = 2) = \binom{4}{2} (0.5)^3 (0.5)^2 = 6 \cdot (0.5)^5 = 0.1875
  \]$

---

#### **Example 2: Customer Complaints**

**Scenario**:
- A customer service center resolves complaints with a success probability \( p = 0.8 \).
- What is the probability that the 5th resolved complaint happens after 3 failed attempts?

**Solution**:
- Here, \( r = 5 \), \( x = 3 \), and \( p = 0.8 \).
- Use the PMF:
  $\[
  P(X = 3) = \binom{3 + 5 - 1}{3} (0.8)^5 (0.2)^3
  \]$
  
  $\[
  P(X = 3) = \binom{7}{3} (0.8)^5 (0.2)^3 = 35 \cdot 0.32768 \cdot 0.008 = 0.0917
  \]$

---

### **Applications**

1. **Over-Dispersed Count Data**:
   - Used in data where the variance exceeds the mean, such as in biological experiments or insurance claims.

2. **Modeling Failures**:
   - Analyze the number of failures before a specific number of successes (e.g., equipment tests).

3. **Epidemiology**:
   - Model the spread of diseases in a population where events (e.g., infection counts) are over-dispersed.

4. **Sports**:
   - Determine the number of games a team must play to achieve a certain number of wins.

---

### **Key Features**

| **Feature**                | **Description**                                      |
|-----------------------------|------------------------------------------------------|
| **Random Variable**         | Number of failures before \(r\) successes           |
| **Shape**                   | Skewed to the right for small \(p\); symmetrical for large \(r\) |
| **Special Case**            | When \(r = 1\), becomes the geometric distribution. |

---

### **Generalization: Negative Binomial as a Counting Distribution**

The negative binomial distribution can also describe the number of successes \(X\) in \(n\) trials if the success probability \(p\) varies over the trials, with a specific mean and variance for \(p\).

This makes it flexible for use in real-world applications where probabilities are not fixed or strictly Bernoulli.

---

### **Conclusion**

The **Negative Binomial Distribution** is a versatile tool for modeling scenarios where trials continue until a fixed number of successes are achieved. Its applications range from quality control to ecological studies, making it essential in both theoretical and applied statistics.
