### **Conversion of NFA to DFA**

The **conversion of an NFA to an equivalent DFA** involves creating a DFA that recognizes the same language as the NFA. This is done using the **Subset Construction Algorithm (or Powerset Construction)**, which treats each state of the DFA as a subset of states of the NFA.

---

### **Steps for Conversion**

#### **1. Define the NFA**
An NFA is defined as a 5-tuple:
$\[
M = (Q, \Sigma, \delta, q_0, F)
\]$
- \( Q \): Set of states.
- $\( \Sigma \)$: Input alphabet.
- $\( \delta: Q \times (\Sigma \cup \{\epsilon\}) \to 2^Q \)$: Transition function.
- $\( q_0 \in Q \)$: Initial state.
- $\( F \subseteq Q \)$: Set of accepting states.

---

#### **2. Define the DFA**
The DFA will also be a 5-tuple:
$\[
M' = (Q', \Sigma, \delta', q_0', F')
\]$
Where:
- \( Q' \): Each state in \( Q' \) is a subset of states of \( Q \) (the power set of \( Q \)).
- $\( \Sigma \)$: Same alphabet as the NFA.
- $\( \delta': Q' \times \Sigma \to Q' \)$: Transition function constructed from the NFA.
- $\( q_0' \)$: The set of all states reachable from $\( q_0 \)$ in the NFA (including via ε-transitions).
- \( F' \): Any subset of \( Q \) that includes at least one state in \( F \).

---

#### **3. Subset Construction Algorithm**

1. **Start with the initial state \( q_0' \) of the DFA**:
   - $\( q_0' = \epsilon\text{-closure}(q_0) \)$, where $\( \epsilon\text{-closure}(q) \)$ includes \( q \) and all states reachable via ε-transitions.

2. **Compute transitions for each input symbol**:
   - For a state $\( S \subseteq Q \)$ in the DFA, and an input symbol $\( a \in \Sigma \)$, calculate:
     $\[
     T = \bigcup_{q \in S} \delta(q, a)
     \]$
     Then take the $\( \epsilon\text{-closure}(T) \)$.

3. **Repeat until all subsets have been processed**:
   - Add new subsets (DFA states) to \( Q' \) as they are discovered.

4. **Define the accepting states \( F' \) of the DFA**:
   - Any subset $\( S \subseteq Q \)$ is an accepting state in the DFA if $\( S \cap F \neq \emptyset \)$, i.e., if \( S \) contains any accepting state of the NFA.

---

### **Example: NFA to DFA Conversion**

#### **NFA Definition**
Let $\( M = (Q, \Sigma, \delta, q_0, F) \)$ with:
- $\( Q = \{q_0, q_1, q_2\} \)$
- $\( \Sigma = \{a, b\} \)$
- Transitions $\( \delta \)$:
  - $\( \delta(q_0, a) = \{q_0, q_1\} \)$
  - $\( \delta(q_0, b) = \{q_0\} \)$
  - $\( \delta(q_1, b) = \{q_2\} \)$
  - $\( \delta(q_2, a) = \{q_2\} \)$
- $\( q_0 = q_0 \)$
- $\( F = \{q_2\} \)$

---

#### **Step 1: Determine the DFA States**
Each DFA state corresponds to a subset of $\( Q = \{q_0, q_1, q_2\} \)$. The possible subsets are:
$\[
Q' = \{\emptyset, \{q_0\}, \{q_1\}, \{q_2\}, \{q_0, q_1\}, \{q_0, q_2\}, \{q_1, q_2\}, \{q_0, q_1, q_2\}\}.
\]$

---

#### **Step 2: Compute Transitions**

| Current DFA State | Input `a` | Input `b` |
|--------------------|-----------|-----------|
| $\( \{q_0\} \)$       | $\( \{q_0, q_1\} \)$ | $\( \{q_0\} \)$ |
| $\( \{q_0, q_1\} \)$  | $\( \{q_0, q_1\} \)$ | $\( \{q_0, q_2\} \)$ |
| $\( \{q_0, q_2\} \)$  | $\( \{q_0, q_1, q_2\} \)$ | $\( \{q_0, q_2\} \)$ |
| $\( \{q_0, q_1, q_2\} \)$ | $\( \{q_0, q_1, q_2\} \)$ | $\( \{q_0, q_2\} \)$ |

---

#### **Step 3: Initial and Accepting States**
- **Initial State**: $\( q_0' = \{q_0\} \)$.
- **Accepting States**: Any subset containing \( q_2 \):
  -  F' = \{\{q_2\}, $\{q_0, q_2\}$, $\{q_1, q_2\}$, \{q_0, q_1, q_2\} .

---

#### **DFA Transition Table**

| DFA State         | Input `a`           | Input `b`           |
|--------------------|---------------------|---------------------|
| $\( \{q_0\} \)$       | $\( \{q_0, q_1\} \)$  | $\( \{q_0\} \)$       |
| $\( \{q_0, q_1\} \)$  | $\( \{q_0, q_1\} \)$  | $\( \{q_0, q_2\} \)$  |
| $\( \{q_0, q_2\} \)$  | $\( \{q_0, q_1, q_2\} \)$ | $\( \{q_0, q_2\} \)$  |
| $\( \{q_0, q_1, q_2\} \)$ | $\( \{q_0, q_1, q_2\} \)$ | $\( \{q_0, q_2\} \)$ |

---

### **DFA Transition Diagram**

```
       a            b
   ---> {q0} ---------> {q0, q1}
       | ^             |
       b |             a,b
       v |             v
       {q0, q2} <--> {q0, q1, q2}
```

---

### **Key Points**
- **Equivalence**: The resulting DFA recognizes the same language as the original NFA.
- **State Explosion**: The number of DFA states is at most $\( 2^{|Q|} \)$, where \( |Q| \) is the number of NFA states. This is why DFA construction can be computationally expensive.
- **Efficiency**: While DFAs may require more states, they are faster for language recognition because they don’t involve non-deterministic branching.
