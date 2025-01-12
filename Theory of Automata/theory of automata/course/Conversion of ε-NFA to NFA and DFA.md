### **Conversion of ε-NFA to NFA and DFA**

An **ε-NFA (Nondeterministic Finite Automaton with ε-moves)** can be converted to an equivalent **NFA** (without ε-moves) and then to a **DFA**. This process ensures that the automaton remains equivalent in recognizing the same language.

---

### **1. Conversion of ε-NFA to NFA (Eliminating ε-Moves)**

#### **Steps to Remove ε-Moves**

1. **Compute ε-closure for Each State**:
   - The ε-closure of a state \( q \) is the set of states reachable from \( q \) using zero or more ε-moves, including \( q \) itself.

2. **Modify Transitions**:
   - For each state \( q \) and input symbol \( a \), determine the new set of transitions by considering all states reachable through $\( \delta(p, a) \)$ for all $\( p \in \epsilon\text{-closure}(q) \)$:
     $\[
     \delta'(q, a) = \bigcup_{p \in \epsilon\text{-closure}(q)} \delta(p, a)
     \]$

3. **Update Accepting States**:
   - A state \( q \) in the new NFA is an accepting state if any state in $\( \epsilon\text{-closure}(q) \)$ is an accepting state in the original ε-NFA.

---

#### **Example of ε-NFA to NFA**

##### ε-NFA Definition:
- States: $\( Q = \{q_0, q_1, q_2\} \)$
- Alphabet: $\( \Sigma = \{a, b\} \)$
- Transitions:
  - $\( \delta(q_0, \epsilon) = \{q_1, q_2\} \)$
  - $\( \delta(q_1, a) = \{q_1\} \)$
  - $\( \delta(q_2, b) = \{q_2\} \)$
- Initial State: $\( q_0 \)$
- Accepting States: $\( F = \{q_2\} \)$

##### Steps:
1. Compute ε-closures:
   - $\( \epsilon\text{-closure}(q_0) = \{q_0, q_1, q_2\} \)$
   - $\( \epsilon\text{-closure}(q_1) = \{q_1\} \)$
   - $\( \epsilon\text{-closure}(q_2) = \{q_2\} \)$

2. Update Transitions:
   - $\( \delta'(q_0, a) = \delta(q_1, a) = \{q_1\} \)$
   - $\( \delta'(q_0, b) = \delta(q_2, b) = \{q_2\} \)$

3. New Accepting States:
   - $\( q_0 \)$ is now an accepting state because $\( \epsilon\text{-closure}(q_0) \)$ includes $\( q_2 \)$.

---

### **2. Conversion of NFA to DFA**

To convert the resulting NFA (from the above step) into a DFA, use the **Subset Construction Algorithm**.

#### **Steps to Convert NFA to DFA**

1. **Define DFA States**:
   - Each DFA state represents a subset of NFA states.

2. **Initial State**:
   - The DFA's initial state is the subset containing the ε-closure of the NFA's initial state.

3. **Transitions**:
   - For a DFA state $\( S \subseteq Q \)$ and input \( a \), the new DFA state is the union of the ε-closures of all states reachable from \( S \) on \( a \).

4. **Accepting States**:
   - Any DFA state that includes an NFA accepting state is an accepting state.

---

#### **Example of NFA to DFA Conversion**

##### NFA Definition (from previous step):
- States: $\( Q = \{q_0, q_1, q_2\} \)$
- Alphabet: $\( \Sigma = \{a, b\} \)$
- Transitions:
  - $\( \delta'(q_0, a) = \{q_1\} \)$
  - $\( \delta'(q_0, b) = \{q_2\} \)$
  - $\( \delta'(q_1, a) = \{q_1\} \)$
  - $\( \delta'(q_2, b) = \{q_2\} \)$
- Initial State: $\( q_0 \)$
- Accepting States: $\( F = \{q_0, q_2\} \)$

##### Subset Construction:
1. DFA States: Subsets of $\( \{q_0, q_1, q_2\} \)$
   - $\( \emptyset, \{q_0\}, \{q_1\}, \{q_2\}, \{q_0, q_1\}, \{q_0, q_2\}, \{q_1, q_2\}, \{q_0, q_1, q_2\} \)$.

2. DFA Transitions:
   - $\( \delta'(\{q_0\}, a) = \{q_1\} \)$
   - $\( \delta'(\{q_0\}, b) = \{q_2\} \)$
   - $\( \delta'(\{q_1\}, a) = \{q_1\} \)$
   - $\( \delta'(\{q_2\}, b) = \{q_2\} \)$

3. Initial State:
   - $\( q_0' = \{q_0\} \)$.

4. Accepting States:
   - Any subset containing $\( q_2 \)$: $\( F' = \{\{q_0\}, \{q_2\}, \{q_0, q_2\}, \{q_0, q_1, q_2\}\} \)$.

---

#### **DFA Transition Table**

| DFA State         | Input `a`           | Input `b`           |
|--------------------|---------------------|---------------------|
| $\( \{q_0\} \)$       | $\( \{q_1\} \)$       | $\( \{q_2\} \)$       |
| $\( \{q_1\} \)$       | $\( \{q_1\} \)$       | $\( \emptyset \)$     |
| $\( \{q_2\} \)$       | $\( \emptyset \)$     | $\( \{q_2\} \)$       |
| $\( \emptyset \)$     | $\( \emptyset \)$     | $\( \emptyset \)$     |

---

### **Key Points**
1. **ε-NFA to NFA**:
   - Eliminate ε-moves by computing ε-closures and updating transitions.
   - Update accepting states based on ε-closures.

2. **NFA to DFA**:
   - Use subset construction to create DFA states and transitions.
   - Ensure DFA recognizes the same language as the original ε-NFA.

3. **Equivalence**:
   - The ε-NFA, resulting NFA, and DFA all recognize the same language.
