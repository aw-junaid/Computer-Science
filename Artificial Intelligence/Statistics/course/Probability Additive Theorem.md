### **Additive Theorem of Probability**

The **Additive Theorem of Probability** (also known as the **Addition Rule**) is a fundamental concept in probability theory. It provides a way to calculate the probability of the union of two or more events. The addition rule is used to determine the probability that either one event or another event (or both) will occur.

The addition rule applies to both **mutually exclusive events** and **non-mutually exclusive events**.

---

### **1. Addition Rule for Mutually Exclusive Events**

When two events are **mutually exclusive**, they cannot occur at the same time. If one event happens, the other cannot.

#### **Formula**:
$\[
P(A \cup B) = P(A) + P(B)
\]$

- **\(P(A \cup B)\)**: Probability that either event \(A\) or event \(B\) (or both) will occur.
- **\(P(A)\)**: Probability that event \(A\) occurs.
- **\(P(B)\)**: Probability that event \(B\) occurs.

**Example**:
- Rolling a die, and we want the probability of getting a 2 or a 5.
  - The probability of rolling a 2: $\(P(\text{2}) = \frac{1}{6}\)$.
  - The probability of rolling a 5: $\(P(\text{5}) = \frac{1}{6}\)$.
  
Since rolling a 2 and rolling a 5 are mutually exclusive (you can't get both at the same time), the total probability is:
$\[
P(\text{2 or 5}) = P(\text{2}) + P(\text{5}) = \frac{1}{6} + \frac{1}{6} = \frac{2}{6} = \frac{1}{3}
\]$

---

### **2. Addition Rule for Non-Mutually Exclusive Events**

When two events are **non-mutually exclusive**, they can occur at the same time. For example, drawing a card that is both red and a face card (such as the King of Hearts).

In this case, we need to subtract the overlap between the two events, because it is counted twice if we simply add their individual probabilities.

#### **Formula**:
$\[
P(A \cup B) = P(A) + P(B) - P(A \cap B)
\]$

- **$\(P(A \cup B)\)$**: Probability that either event \(A\) or event \(B\) (or both) will occur.
- **$\(P(A)\)$**: Probability that event \(A\) occurs.
- **$\(P(B)\)$**: Probability that event \(B\) occurs.
- **$\(P(A \cap B)\)$**: Probability that both events \(A\) and \(B\) occur simultaneously (the intersection of \(A\) and \(B\)).

**Example**:
- A deck of 52 cards: We want the probability of drawing either a red card or a face card.
  - The probability of drawing a red card (hearts or diamonds): $\(P(\text{Red}) = \frac{26}{52} = \frac{1}{2}\)$.
  - The probability of drawing a face card (Jack, Queen, King in each suit): $\(P(\text{Face Card}) = \frac{12}{52} = \frac{3}{13}\)$.
  - The probability of drawing a red face card (either Jack, Queen, or King of hearts or diamonds): $\(P(\text{Red Face Card}) = \frac{6}{52} = \frac{3}{26}\)$.

Using the addition rule:
$\[
P(\text{Red or Face Card}) = P(\text{Red}) + P(\text{Face Card}) - P(\text{Red Face Card})
\]$

$\[
P(\text{Red or Face Card}) = \frac{1}{2} + \frac{3}{13} - \frac{3}{26}
\]$
To calculate the result, first express all terms with a common denominator:
$\[
P(\text{Red or Face Card}) = \frac{13}{26} + \frac{6}{26} - \frac{3}{26} = \frac{16}{26} = \frac{8}{13}
\]$

---

### **Generalization for Multiple Events**

The additive theorem can be extended to more than two events. For three events \(A\), \(B\), and \(C\), the addition rule becomes:

$\[
P(A \cup B \cup C) = P(A) + P(B) + P(C) - P(A \cap B) - P(A \cap C) - P(B \cap C) + P(A \cap B \cap C)
\]$

This formula accounts for all possible overlaps between the events.

---

### **Conclusion**

The **Additive Theorem of Probability** is a powerful tool to calculate the probability of the union of two or more events. For **mutually exclusive events**, we simply add the probabilities of the individual events. For **non-mutually exclusive events**, we subtract the probability of their intersection to avoid double-counting the overlapping outcomes. This theorem is essential for a wide range of problems in probability and statistics, particularly in areas like card games, dice rolls, and surveys.
