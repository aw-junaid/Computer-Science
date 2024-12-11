### **Multiplicative Theorem of Probability**

The **Multiplicative Theorem of Probability** (also known as the **Multiplication Rule**) is a key concept in probability theory used to determine the probability of the intersection of two or more events. It is often used when we are interested in finding the probability of multiple events happening together.

The multiplication rule applies to both **independent events** and **dependent events**, but the formula differs slightly depending on whether the events are independent or dependent.

---

### **1. Multiplication Rule for Independent Events**

Two events are **independent** if the occurrence of one event does not affect the probability of the other event. In other words, the outcome of one event does not change the probability of the other event happening.

#### **Formula for Independent Events**:
$\[
P(A \cap B) = P(A) \times P(B)
\]$

- **$\(P(A \cap B)\)$**: Probability that both event \(A\) and event \(B\) occur.
- **$\(P(A)\)$**: Probability that event \(A\) occurs.
- **$\(P(B)\)$**: Probability that event \(B\) occurs.

**Example**:
- Suppose we flip a fair coin twice. The probability of getting heads on the first flip is $\(P(\text{Heads}) = \frac{1}{2}\)$, and the probability of getting heads on the second flip is also $\(P(\text{Heads}) = \frac{1}{2}\)$.
  
Since these flips are independent events (the outcome of the first flip does not affect the second flip), the probability of getting heads on both flips is:
$\[
P(\text{Heads on both flips}) = P(\text{Heads on 1st flip}) \times P(\text{Heads on 2nd flip}) = \frac{1}{2} \times \frac{1}{2} = \frac{1}{4}
\]$

---

### **2. Multiplication Rule for Dependent Events**

Two events are **dependent** if the occurrence of one event affects the probability of the other event. For example, drawing cards from a deck without replacement creates dependent events because each card drawn changes the composition of the deck.

#### **Formula for Dependent Events**:
$\[
P(A \cap B) = P(A) \times P(B|A)
\]$
- **$\(P(A \cap B)\)$**: Probability that both event \(A\) and event \(B\) occur.
- **$\(P(A)\)$**: Probability that event \(A\) occurs.
- **\(P(B|A)\)**: Conditional probability that event \(B\) occurs, given that event \(A\) has already occurred.

**Example**:
- Suppose you are drawing two cards from a deck without replacement. The probability of drawing an Ace on the first draw is:
  $\[
  P(\text{Ace on 1st draw}) = \frac{4}{52}
  \]$
  
  After drawing an Ace, there are now only 51 cards left in the deck, and only 3 Aces remaining. The probability of drawing an Ace on the second draw, given that the first card was an Ace, is:
  $\[
  P(\text{Ace on 2nd draw | Ace on 1st}) = \frac{3}{51}
  \]$

  The combined probability of drawing two Aces is:
  $\[
  P(\text{Ace on both draws}) = P(\text{Ace on 1st draw}) \times P(\text{Ace on 2nd draw | Ace on 1st}) = \frac{4}{52} \times \frac{3}{51} = \frac{12}{2652} \approx 0.0045
  \]$

---

### **Generalization for More Than Two Events**

The multiplication rule can be generalized for more than two events. If we have \(n\) events, the probability of all \(n\) events happening together is the product of their individual probabilities, adjusted for the dependencies between the events.

For three events \(A\), \(B\), and \(C\), the formula is:
$\[
P(A \cap B \cap C) = P(A) \times P(B|A) \times P(C|A \cap B)
\]$

- **$\(P(A)\)$**: Probability that event \(A\) occurs.
- **$\(P(B|A)\)$**: Conditional probability that event \(B\) occurs given \(A\) has occurred.
- **$\(P(C|A \cap B)\)$**: Conditional probability that event \(C\) occurs, given both \(A\) and \(B\) have occurred.

For \(n\) events, the general formula is:
$\[
P(A_1 \cap A_2 \cap \dots \cap A_n) = P(A_1) \times P(A_2|A_1) \times P(A_3|A_1 \cap A_2) \times \dots \times P(A_n|A_1 \cap A_2 \cap \dots \cap A_{n-1})
\]$

---

### **Summary**

- **Independent Events**: The probability of both events occurring is simply the product of their individual probabilities:
  $\[
  P(A \cap B) = P(A) \times P(B)
  \]$
  
- **Dependent Events**: The probability of both events occurring depends on the conditional probability of one event given the occurrence of the other:
  $\[
  P(A \cap B) = P(A) \times P(B|A)
  \]$

The multiplication rule is a crucial concept in probability theory used to calculate the probability of the intersection of two or more events, whether they are independent or dependent.
