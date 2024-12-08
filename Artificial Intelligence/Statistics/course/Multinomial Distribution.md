### **Multinomial Distribution**

The **Multinomial Distribution** is a generalization of the **Binomial Distribution** for experiments where each trial can result in one of more than two possible outcomes. It models the probabilities of different outcomes when an experiment is repeated a fixed number of times under identical conditions.

---

### **Key Characteristics**

1. **Number of Trials (\(n\))**:
   - The total number of independent trials in the experiment.

2. **Number of Outcomes (\(k\))**:
   - The possible outcomes per trial (e.g., rolling a die has 6 outcomes).

3. **Probability of Each Outcome $(\(p_1, p_2, \dots, p_k\))$**:
   - Each trial has a fixed probability for each outcome, such that:
     $\[
     \sum_{i=1}^{k} p_i = 1
     \]$

4. **Random Variables $(\(X_1, X_2, \dots, X_k\))$**:
   - $\(X_i\)$ represents the number of times outcome \(i\) occurs over \(n\) trials.

---

### **Probability Mass Function (PMF)**

The probability of observing a specific combination of counts $\( (x_1, x_2, \dots, x_k) \), where \( \sum_{i=1}^{k} x_i = n \)$, is given by:

$\[
P(X_1 = x_1, X_2 = x_2, \dots, X_k = x_k) = \frac{n!}{x_1! \, x_2! \, \dots \, x_k!} \prod_{i=1}^{k} p_i^{x_i}
\]$

Where:
- \( n \): Total number of trials.
- $\( x_i \)$: Count of outcome \(i\) (non-negative integers, $\(x_i \geq 0\))$.
- $\( p_i \)$: Probability of outcome \(i\).

---

### **Examples**

#### **Example 1: Rolling a Die**

**Scenario**:
- Roll a fair 6-sided die \( n = 10 \) times.
- Each outcome $(\( 1, 2, 3, 4, 5, 6 \))$ has a probability $\( p_i = \frac{1}{6} \)$.

**Question**:
What is the probability of rolling \( 2 \) ones, \( 3 \) twos, \( 1 \) three, \( 2 \) fours, \( 1 \) five, and \( 1 \) six?

**Solution**:
- $\( x_1 = 2, \, x_2 = 3, \, x_3 = 1, \, x_4 = 2, \, x_5 = 1, \, x_6 = 1 \)$
- $\( p_1 = p_2 = p_3 = p_4 = p_5 = p_6 = \frac{1}{6} \)$
- Substitute into the PMF:
```math
  P = \frac{10!}{2! \, 3! \, 1! \, 2! \, 1! \, 1!} \left( \frac{1}{6} \right)^2 \left( \frac{1}{6} \right)^3 \left( \frac{1}{6} \right)^1 \left( \frac{1}{6} \right)^2 \left( \frac{1}{6} \right)^1 \left( \frac{1}{6} \right)^1
```
  Simplify:
  $\[
  P = \frac{10!}{2! \, 3! \, 1! \, 2! \, 1! \, 1!} \cdot \left( \frac{1}{6} \right)^{10}
  \]$

#### **Example 2: Voting Preferences**

**Scenario**:
- In a survey of \( n = 100 \) people, the probabilities of voting for candidates \( A, B, \) and \( C \) are $\( p_A = 0.5, p_B = 0.3, p_C = 0.2 \)$.

**Question**:
What is the probability that \( 50 \) people vote for \( A \), \( 30 \) for \( B \), and \( 20 \) for \( C \)?

**Solution**:
- $\( x_A = 50, \, x_B = 30, \, x_C = 20 \)$
- $\( p_A = 0.5, \, p_B = 0.3, \, p_C = 0.2 \)$
- Use the PMF:
  $\[
  P = \frac{100!}{50! \, 30! \, 20!} \cdot (0.5)^{50} \cdot (0.3)^{30} \cdot (0.2)^{20}
  \]$

---

### **Properties of the Multinomial Distribution**

1. **Expected Value**:
   $\[
   E(X_i) = n \cdot p_i
   \]$

2. **Variance**:
   $\[
   \text{Var}(X_i) = n \cdot p_i \cdot (1 - p_i)
   \]$

3. **Covariance**:
   For $\( i \neq j \)$,
   $\[
   \text{Cov}(X_i, X_j) = -n \cdot p_i \cdot p_j
   \]$

---

### **Applications**

1. **Market Research**:
   - Modeling the distribution of customer preferences for multiple products.

2. **Genetics**:
   - Analyzing the proportions of different genetic traits in a population.

3. **Elections**:
   - Estimating probabilities of voting outcomes for multiple candidates.

4. **Games of Chance**:
   - Calculating probabilities of outcomes in dice rolls, card games, etc.

---

### **Key Differences from Binomial Distribution**

| **Feature**           | **Binomial Distribution**                           | **Multinomial Distribution**                      |
|-----------------------|----------------------------------------------------|--------------------------------------------------|
| **Outcomes per Trial** | Two (success or failure)                           | More than two                                   |
| **Number of Parameters** | \(n, p\)                                          | $\(n, p_1, p_2, \dots, p_k\)$                     |
| **Random Variables**   | One (count of successes)                          | Multiple (counts for each outcome)              |

---

### **Conclusion**

The **Multinomial Distribution** is essential for modeling probabilities when there are more than two outcomes. Its flexibility and applicability make it a cornerstone in statistics, with uses in fields ranging from genetics to marketing.
