Constructing Deterministic Finite Automata (DFA) for different problems. Each example includes the language to recognize, formal DFA components, and a transition diagram.

---

### **Example 1: DFA for Binary Strings Divisible by 2**

#### **Language**:  
Set of binary strings over $\( \Sigma = \{0, 1\} \)$ where the number represented by the string is divisible by 2 (i.e., strings ending with `0`).

#### **Formal Definition**:
1. $\( Q = \{q_0, q_1\} \)$  
   - $\( q_0 \)$: Strings ending with `0` (divisible by 2).  
   - $\( q_1 \)$: Strings ending with `1` (not divisible by 2).  
2. $\( \Sigma = \{0, 1\} \)$.  
3. Transition function $\( \delta \)$:

| Current State | Input 0 | Input 1 |
|---------------|---------|---------|
| $\( q_0 \)$     | $\( q_0 \)$ | $\( q_1 \)$ |
| $\( q_1 \)$     | $\( q_0 \)$ | $\( q_1 \)$ |

4. $\( q_0 \): Initial state.  
5. $\( F = \{q_0\} \)$: Accepting state.

---

#### **Explanation**:
- Start at $\( q_0 \)$.  
- Read each symbol:
  - Move to $\( q_1 \)$ if a `1` is read.
  - Stay in $\( q_0 \)$ if a `0` is read.  

---

#### **Diagram**:

```
      0
   (q0) -------> (q1)
     ^            |
     |            v
     0 <--------- 1
```

- $\( q_0 \)$: Accepting state (double circle).  
- $\( q_1 \)$: Non-accepting state.

---

### **Example 2: DFA for Strings Containing `101` as a Substring**

#### **Language**:  
Set of binary strings over $\( \Sigma = \{0, 1\} \)$ that contain the substring `101`.

#### **Formal Definition**:
1. $\( Q = \{q_0, q_1, q_2, q_3\} \)$:  
   - $\( q_0 \)$: Start state.  
   - $\( q_1 \)$: First `1` matched.  
   - $\( q_2 \)$: `10` matched.  
   - $\( q_3 \)$: `101` matched (accepting state).  
2. $\( \Sigma = \{0, 1\} \)$.  
3. Transition function $\( \delta \)$:

| Current State | Input 0 | Input 1 |
|---------------|---------|---------|
| $\( q_0 \) $    | $\( q_0 \)$ | $\( q_1 \)$ |
| $\( q_1 \)$     | $\( q_2 \)$ | $\( q_1 \)$ |
| $\( q_2 \)$     | $\( q_0 \)$ | $\( q_3 \)$ |
| $\( q_3 \)$     | $\( q_3 \)$ | $\( q_3 \)$ |

4. $\( q_0 \)$: Initial state.  
5. $\( F = \{q_3\} \)$: Accepting state.

---

#### **Explanation**:
- Start at $\( q_0 \)$.  
- Move to $\( q_1 \)$ after reading `1`.  
- Move to $\( q_2 \)$ after reading `0` from $\( q_1 \)$.  
- Move to $\( q_3 \)$ after reading `1` from $\( q_2 \)$ (substring `101` matched).  

---

#### **Diagram**:

```
      1         0         1
   (q0) --> (q1) --> (q2) --> ((q3))
    ^        |         ^        |
    |        v         |        v
    ---------> 1       |--------> 0
```

- $\( q_3 \)$: Accepting state (double circle).

---

### **Example 3: DFA for Strings Over \( \{a, b\} \) Ending with `ab`**

#### **Language**:  
Set of strings over $\( \Sigma = \{a, b\} \)$ that end with `ab`.

#### **Formal Definition**:
1. $\( Q = \{q_0, q_1, q_2\} \)$:  
   - $\( q_0 \)$: Start state (no characters matched).  
   - $\( q_1 \)$: Last character was `a`.  
   - $\( q_2 \)$: Last two characters were `ab` (accepting state).  
2. $\( \Sigma = \{a, b\} \)$.  
3. Transition function \( \delta \):

| Current State | Input \( a \) | Input \( b \) |
|---------------|---------------|---------------|
| $\( q_0 \)$     | $\( q_1 \)$     | $\( q_0 \)$     |
| $\( q_1 \)$     | $\( q_1 \)$     | $\( q_2 \)$     |
| $\( q_2 \)$     | $\( q_1 \)$     | $\( q_0 \)$     |

4. $\( q_0 \)$: Initial state.  
5. $\( F = \{q_2\} \)$: Accepting state.

---

#### **Explanation**:
- Start at $\( q_0 \)$.  
- Move to $\( q_1 \)$ on `a`.  
- Move to $\( q_2 \)$ on `b` if the previous state was $\( q_1 \)$.  

---

#### **Diagram**:

```
      a         b         a
   (q0) --> (q1) --> ((q2))
    ^                   |
    |-------------------|
            b
```

- $\( q_2 \)$: Accepting state (double circle).

---

### Summary
These examples illustrate how to construct DFAs for specific problems. Each DFA:
1. Starts with an **initial state**.
2. Uses **transitions** to move between states based on the input.
3. Ends in an **accepting state** if the input satisfies the language criteria.
