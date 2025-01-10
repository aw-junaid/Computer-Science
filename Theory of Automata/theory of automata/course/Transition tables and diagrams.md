### Transition Tables and Diagrams in DFA

**Transition tables** and **transition diagrams** are key tools to represent the behavior of a Deterministic Finite Automaton (DFA). Let’s explain their structures and provide examples.

---

### **1. Transition Table**
The **transition table** is a tabular representation of the DFA's transition function $(\( \delta \))$. It lists:
- The current state.
- The input symbols.
- The next states resulting from each state-symbol pair.

#### Structure of a Transition Table:
| **State**   | **Input 1** | **Input 2** | ... | **Input \( n \)** |
|-------------|-------------|-------------|-----|-------------------|
| $\( q_0 \$)   | $\( q_x \)$   | $\( q_y \)$   | ... | $\( q_z \)$         |
| $\( q_1 \)$   | $\( q_a \)$   | $\( q_b \)$   | ... | $\( q_c \)$         |
| ...         | ...         | ...         | ... | ...               |

---

### **2. Transition Diagram**
A **transition diagram** is a graphical representation of the DFA. It consists of:
1. **States**: Represented as circles.
2. **Transitions**: Directed arrows between states, labeled with the input symbol that triggers the transition.
3. **Initial State**: Marked with an incoming arrow pointing to it.
4. **Accepting States**: Represented as double circles.

---

### **Examples**

#### **Example 1: DFA for Strings Ending with `ab`**
**Language**: Strings over $\( \Sigma = \{a, b\} \)$ that end with `ab`.

#### **Transition Table**:

| **State**   | **Input \( a \)** | **Input \( b \)** |
|-------------|-------------------|-------------------|
| $\( q_0 \)$   | $\( q_1 \)$         | $\( q_0 \)$         |
| $\( q_1 \)$   | $\( q_1 \)$         | $\( q_2 \)$         |
| $\( q_2 \)$   | $\( q_1 \)$         | $\( q_0 \)$         |

- $\( q_0 \)$: Initial state (start state).
- $\( q_2 \)$: Accepting state (strings end with `ab`).

#### **Transition Diagram**:

```
      a         b         a
   (q0) --> (q1) --> ((q2))
    ^                   |
    |-------------------|
            b
```

---

#### **Example 2: DFA for Binary Strings Divisible by 3**
**Language**: Binary strings divisible by 3 over $\( \Sigma = \{0, 1\} \)$.

#### **Transition Table**:

| **State**   | **Input \( 0 \)** | **Input \( 1 \)** |
|-------------|-------------------|-------------------|
| $\( q_0 \)$   | $\( q_0 \)$         | $\( q_1 \)$         |
| $\( q_1 \)$   | $\( q_2 \)$         | $\( q_0 \)$         |
| $\( q_2 \)$   | $\( q_1 \)$         | $\( q_2 \)$         |

- $\( q_0 \)$: Represents remainder `0`.
- $\( q_1 \)$: Represents remainder `1`.
- $\( q_2 \)$: Represents remainder `2`.
- $\( q_0 \)$: Accepting state.

#### **Transition Diagram**:

```
      0         1
   (q0) -----> (q1)
     ^          |   
     | 1        v 0
     |------ (q2)
```

---

#### **Example 3: DFA for Strings Containing `101` as a Substring**
**Language**: Binary strings over $\( \Sigma = \{0, 1\} \)$ containing the substring `101`.

#### **Transition Table**:

| **State**   | **Input \( 0 \)** | **Input \( 1 \)** |
|-------------|-------------------|-------------------|
| $\( q_0 \)$   | $\( q_0 \)$         | $\( q_1 \)$         |
| $\( q_1 \)$   | $\( q_2 \)$         | $\( q_1 \)$         |
| $\( q_2 \)$   | $\( q_0 \)$         | $\( q_3 \)$         |
| $\( q_3 \)$   | $\( q_3 \)$         | $\( q_3 \)$         |

- \( q_0 \): Start state.
- \( q_3 \): Accepting state (substring `101` matched).

#### **Transition Diagram**:

```
      1         0         1
   (q0) --> (q1) --> (q2) --> ((q3))
    ^        |         ^        |
    |        v         |        v
    ---------> 1       |--------> 0
```

---

### Key Points:
1. **Transition Table**:
   - Compact and precise.
   - Useful for implementation and algorithms.
2. **Transition Diagram**:
   - Visual and intuitive.
   - Helps in understanding state transitions at a glance.

Both representations are interchangeable and complement each other for designing and analyzing DFAs.
