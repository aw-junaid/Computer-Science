### **Language Recognition by DFA**

A **Deterministic Finite Automaton (DFA)** is used to recognize whether a given string belongs to a particular language. The process of **language recognition** involves reading an input string and determining if the DFA ends in an **accepting state**.

---

### **Key Concepts in DFA Language Recognition**
1. **Input Alphabet $(\( \Sigma \))$**:
   - The DFA can only process strings formed from its alphabet.

2. **State Transitions $(\( \delta \))$**:
   - The DFA moves from one state to another based on the current state and the input symbol.

3. **Acceptance**:
   - A string is accepted if, after reading the entire string, the DFA ends in an **accepting state**.
   - If the DFA ends in a non-accepting state or encounters no valid transition, the string is **rejected**.

4. **Language of a DFA $(\( L(M) \))$**:
   - The set of all strings accepted by a DFA \( M \) is the **language recognized by the DFA**.

---

### **Steps for Language Recognition by a DFA**

1. **Start at the Initial State $(\( q_0 \))$**:
   - Begin computation from the designated start state.

2. **Process Input Symbols**:
   - Read each symbol in the input string sequentially.
   - Use the transition function $\( \delta \)$ to move to the next state based on the current state and input symbol.

3. **Check the Final State**:
   - If the DFA ends in an **accepting state** after processing the string, the string is **accepted**.
   - Otherwise, it is **rejected**.

---

### **Examples**

#### **Example 1: DFA for Strings Ending with `01`**
**Language**: Strings over $\( \Sigma = \{0, 1\} \)$ that end with `01`.

**DFA Definition**:
1. $\( Q = \{q_0, q_1, q_2\} \)$  
2. $\( \Sigma = \{0, 1\} \)$  
3. Transition Table:

| **State** | **Input 0** | **Input 1** |
|-----------|-------------|-------------|
| $\( q_0 \)$ | $\( q_0 \)$   | $\( q_1 \)$   |
| $\( q_1 \)$ | $\( q_2 \)$   | $\( q_1 \)$   |
| $\( q_2 \)$ | $\( q_0 \)$   | $\( q_1 \)$   |

4. $\( q_0 \)$: Initial state.  
5. $\( F = \{q_2\} \)$: Accepting state.

#### **Language Recognition**:
- **Input: `101`**  
   - Start at $\( q_0 \)$.  
   - Read `1`: $\( q_0 \to q_1 \)$.  
   - Read `0`: $\( q_1 \to q_2 \)$.  
   - Read `1`: $\( q_2 \to q_1 \)$.  
   - $\( q_1 \)$ is not an accepting state. **Rejected**.

- **Input: `1001`**  
   - Start at $\( q_0 \)$.  
   - Read `1`: $\( q_0 \to q_1 \)$.  
   - Read `0`: $\( q_1 \to q_2 \)$.  
   - Read `0`: $\( q_2 \to q_0 \)$.  
   - Read `1`: $\( q_0 \to q_1 \)$.  
   - $\( q_1 \)$ is not an accepting state. **Rejected**.

- **Input: `001`**  
   - Start at $\( q_0 \)$.  
   - Read `0`: $\( q_0 \to q_0 \)$.  
   - Read `0`: $\( q_0 \to q_0 \)$.  
   - Read `1`: $\( q_0 \to q_1 \)$.  
   - $\( q_1 \)$ is not an accepting state. **Rejected**.

#### Example 2 DFA EXAMPLES

Let's continue with **Example 2** for DFA-based language recognition.

---

### **Example 2: DFA for Strings Containing `101` as a Substring**
**Language**: Binary strings over $\( \Sigma = \{0, 1\} \)$ that contain the substring `101`.

#### **DFA Definition**:
1. **States**:
   - $\( Q = \{q_0, q_1, q_2, q_3\} \)$  
     - $\( q_0 \)$: Start state (no characters matched).  
     - $\( q_1 \)$: Substring starts with `1`.  
     - $\( q_2 \)$: Substring starts with `10`.  
     - $\( q_3 \)$: Substring `101` matched (accepting state).  

2. **Alphabet**:
   - $\( \Sigma = \{0, 1\} \)$.

3. **Transition Table**:

| **State**   | **Input \( 0 \)** | **Input \( 1 \)** |
|-------------|-------------------|-------------------|
| $\( q_0 \)$   | $\( q_0 \)$         | $\( q_1 \)$         |
| $\( q_1 \)$   | $\( q_2 \)$         | $\( q_1 \)$         |
| $\( q_2 \)$   | $\( q_0 \)$         | $\( q_3 \)$         |
| $\( q_3 \)$   | $\( q_3 \)$         | $\( q_3 \)$         |

4. **Initial State**:
   - $\( q_0 \)$.

5. **Accepting State**:
   - $\( q_3 \)$.

---

#### **Language Recognition Process**:
- **Input: `101`**  
  - Start at $\( q_0 \)$.  
  - Read `1`: $\( q_0 \to q_1 \)$.  
  - Read `0`: $\( q_1 \to q_2 \)$.  
  - Read `1`: $\( q_2 \to q_3 \)$.  
  - $\( q_3 \)$ is an accepting state. **Accepted**.

- **Input: `1101`**  
  - Start at $\( q_0 \)$.  
  - Read `1`: $\( q_0 \to q_1 \)$.  
  - Read `1`: $\( q_1 \to q_1 \)$.  
  - Read `0`: $\( q_1 \to q_2 \)$.  
  - Read `1`: $\( q_2 \to q_3 \)$.  
  - $\( q_3 \)$ is an accepting state. **Accepted**.

- **Input: `1000`**  
  - Start at $\( q_0 \)$.  
  - Read `1`: $\( q_0 \to q_1 \)$.  
  - Read `0`: $\( q_1 \to q_2 \)$.  
  - Read `0`: $\( q_2 \to q_0 \)$.  
  - Read `0`: $\( q_0 \to q_0 \)$.  
  - $\( q_0 \)$ is not an accepting state. **Rejected**.

---

### **Example 3: DFA for Strings with Even Number of 0s**
**Language**: Binary strings with an even number of `0`s over $\( \Sigma = \{0, 1\} \)$

#### **DFA Definition**:
1. **States**:
   - $\( Q = \{q_0, q_1\} \)$:  
     - $\( q_0 \)$: Even number of `0`s (accepting state).  
     - $\( q_1 \)$: Odd number of `0`s.

2. **Alphabet**:
   - $\( \Sigma = \{0, 1\} \)$.

3. **Transition Table**:

| **State**   | **Input \( 0 \)** | **Input \( 1 \)** |
|-------------|-------------------|-------------------|
| $\( q_0 \)$   | $\( q_1 \)$         | $\( q_0 \)$         |
| $\( q_1 \)$   | $\( q_0 \)$         | $\( q_1 \)$         |

4. **Initial State**:
   - $\( q_0 \)$.

5. **Accepting State**:
   - $\( q_0 \)$.

---

#### **Language Recognition Process**:
- **Input: `1001`**  
  - Start at $\( q_0 \)$.  
  - Read `1`: $\( q_0 \to q_0 \)$.  
  - Read `0`: $\( q_0 \to q_1 \)$.  
  - Read `0`: $\( q_1 \to q_0 \)$.  
  - Read `1`: $\( q_0 \to q_0 \)$.  
  - $\( q_0 \)$ is an accepting state. **Accepted**.

- **Input: `1010`**  
  - Start at $\( q_0 \)$.  
  - Read `1`: $\( q_0 \to q_0 \)$.  
  - Read `0`: $\( q_0 \to q_1 \)$.  
  - Read `1`: $\( q_1 \to q_1 \)$.  
  - Read `0`: $\( q_1 \to q_0 \)$.  
  - $\( q_0 \)$ is an accepting state. **Accepted**.

- **Input: `1111`**  
  - Start at $\( q_0 \)$.  
  - Read `1`: $\( q_0 \to q_0 \)$.  
  - Read `1`: $\( q_0 \to q_0 \)$.  
  - Read `1`: $\( q_0 \to q_0 \)$.  
  - Read `1`: $\( q_0 \to q_0 \)$.  
  - $\( q_0 \)$ is an accepting state. **Accepted**.

---

### **Summary**
- The DFA recognizes a language by evaluating whether an input string ends in an **accepting state**.
- Transition tables and diagrams are used to systematically analyze state transitions.
- The set of all strings that lead to an accepting state constitutes the **language recognized by the DFA**.
