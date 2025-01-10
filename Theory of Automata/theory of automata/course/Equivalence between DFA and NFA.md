### **Equivalence between DFA and NFA**

One of the fundamental results in **Automata Theory** is that **Deterministic Finite Automata (DFA)** and **Non-Deterministic Finite Automata (NFA)** are **equivalent** in terms of the languages they can recognize, meaning they recognize the same class of languages, known as **regular languages**.

In other words, for every **NFA**, there exists an equivalent **DFA** that accepts the same language, and vice versa. However, the construction of a DFA from an NFA is typically more complex and may involve an **exponential increase in the number of states**.

### **Key Concepts of Equivalence**

- **DFA**: For each state and input symbol, there is a **unique** next state.
- **NFA**: For each state and input symbol, there can be **multiple possible next states** or even **no transition** (in the case of ε-transitions).
  
Despite these differences, any language that can be recognized by an NFA can also be recognized by a DFA. This is guaranteed by the **Subset Construction Algorithm (also called Powerset Construction)**, which converts an NFA to an equivalent DFA.

### **Subset Construction Algorithm (Powerset Construction)**
This algorithm is used to convert an NFA into an equivalent DFA. It works by taking subsets of states of the NFA and treating them as states in the DFA.

#### **Steps to Convert NFA to DFA**:
1. **Define the DFA States**:
   - Each state in the DFA corresponds to a **subset** of the states of the NFA. Since an NFA may have multiple possible transitions for the same input, each subset represents all the states the NFA could be in after reading a sequence of input symbols.

2. **Initial State of DFA**:
   - The initial state of the DFA corresponds to the set of all NFA states that can be reached from the initial state of the NFA using ε-transitions (if any).

3. **Transition Function**:
   - For each subset of states in the DFA, for each input symbol, compute the set of NFA states that can be reached from any of the NFA states in the subset using the input symbol (this includes ε-transitions).
   
4. **Accepting States**:
   - Any subset of NFA states that contains an accepting state of the NFA becomes an accepting state in the DFA.

5. **Final DFA**:
   - Once all subsets of states have been explored, the DFA is complete, and its states correspond to the various subsets of the NFA states.

---

### **Example: Converting an NFA to a DFA**

Consider the following NFA:

- **States**: $\( Q = \{q_0, q_1, q_2\} \)$
- **Alphabet**: $\( \Sigma = \{a, b\} \)$
- **Transitions**:
  - $\( \delta(q_0, a)$ = $\{q_0, q_1\} \)$
  - $\( \delta(q_1, b)$ = $\{q_2\} \)$
  - $\( \delta(q_2, a)$ = $\{q_0\} \)$
  - $\( \delta(q_2, b)$ = $\{q_1\} \)$
- **Initial State**: $\( q_0 \)$
- **Accepting States**: $\( F = \{q_1\} \)$

#### **Step 1: Define DFA States**
- Each DFA state is a subset of NFA states. The possible subsets are:
  - $\( \{q_0\} \)$
  - $\( \{q_1\} \)$
  - $\( \{q_2\} \)$
  - $\( \{q_0, q_1\} \)$
  - $\( \{q_1, q_2\} \)$
  - $\( \{q_0, q_2\} \)$
  - $\( \{q_0, q_1, q_2\} \)$

#### **Step 2: Initial State of DFA**
- The initial state of the DFA corresponds to the set of states reachable from $\( q_0 \)$ using ε-transitions (if any). Since there are no ε-transitions, the initial state is just $\( \{q_0\} \)$.

#### **Step 3: Transition Function of DFA**
- The transition function of the DFA is computed by considering all possible transitions for each input symbol from each subset of NFA states.

For example:
- From $\( \{q_0\} \)$ on input `a`, the NFA can move to $\( \{q_0, q_1\} \)$.
- From $\( \{q_1\} \)$ on input `b`, the NFA can move to $\( \{q_2\} \)$.

#### **Step 4: Accepting States**
- Any subset containing $\( q_1 \)$ (the accepting state of the NFA) becomes an accepting state in the DFA.
  - So, the accepting states of the DFA would be:
    - $\( \{q_1\} \)$
    - $\( \{q_0, q_1\} \)$
    - $\( \{q_1, q_2\} \)$
    - $\( \{q_0, q_1, q_2\} \)$

#### **Step 5: Final DFA**
After applying the subset construction algorithm, we get the following DFA:

- **States**:   $\{q_0\}$, $\{q_1\}$, $\{q_2\}$, $\{q_0, q_1\}$, $\{q_1, q_2\}$, $\{q_0, q_2\}$, $\{q_0, q_1, q_2\}$
- **Initial State**: $\( \{q_0\} \)$
- **Accepting States**: $\( \{q_1\}$, $\{q_0, q_1\}$, $\{q_1, q_2\}$, $\{q_0, q_1, q_2\} \)$
- **Transitions**:
  - From $\( \{q_0\} \)$ on `a`: $\( \{q_0, q_1\} \)$
  - From $\( \{q_0\} \)$ on `b`: $\( \{q_0\} \)$
  - From $\( \{q_1\} \)$ on `b`: $\( \{q_2\} \)$
  - From $\( \{q_2\} \)$ on `a`: $\( \{q_0\} \)$
  - and so on...

---

### **Key Takeaways**:
- **Equivalence**: Every NFA can be converted to an equivalent DFA, which means both recognize the same class of regular languages.
- **Subset Construction**: This method is used to convert an NFA into a DFA, but the resulting DFA may have exponentially more states than the original NFA.
- **Determinism vs. Non-Determinism**: While DFAs are deterministic (one path for each input), NFAs allow for multiple possible transitions or no transitions at all, making them more flexible in representation but requiring the subset construction for practical use.
