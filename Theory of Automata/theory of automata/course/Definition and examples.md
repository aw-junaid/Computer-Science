### **Non-Deterministic Finite Automata (NFA)**

#### **Definition**
A **Non-Deterministic Finite Automaton (NFA)** is a computational model similar to a Deterministic Finite Automaton (DFA), but with the following key differences:

1. **Multiple Transitions**:
   - For a given state and input symbol, the NFA can move to **multiple states** or stay in the current state.
   
2. **Epsilon (ε)-Transitions**:
   - The NFA can transition between states **without consuming any input symbol** using ε-transitions.

3. **Non-Determinism**:
   - The NFA does not require a unique path for processing an input string. It can "guess" the path to acceptance by exploring all possible transitions.

#### **Formal Definition**
An NFA is a 5-tuple $\( M = (Q, \Sigma, \delta, q_0, F) \)$, where:
- $\( Q \)$: Finite set of states.
- $\( \Sigma \)$: Input alphabet (finite set of symbols).
- $\( \delta: Q \times (\Sigma \cup \{\epsilon\}) \to 2^Q \)$: Transition function (maps a state and input symbol to a set of possible next states, including ε-transitions).
- $\( q_0 \in Q \)$: Initial state.
- $\( F \subseteq Q \)$: Set of accepting (final) states.

#### **Language Recognition in NFA**
A string is accepted by the NFA if there exists **at least one path** from the initial state $\( q_0 \)$ to an accepting state $\( q_f \in F \)$ such that all input symbols in the string are consumed.

---

### **Example 1: NFA for Strings Ending with `ab`**

**Language**: Strings over $\( \Sigma = \{a, b\} \)$ that end with `ab`.

#### **NFA Definition**
1. **States**: $\( Q = \{q_0, q_1, q_2\} \)$
   - $\( q_0 \)$: Initial state.
   - $\( q_1 \)$: Matches the input `a`.
   - $\( q_2 \)$: Matches the sequence `ab`.
2. **Alphabet**: $\( \Sigma = \{a, b\} \)$
3. **Transitions (\( \delta \))**:
   - $\( \delta(q_0, a) = \{q_0, q_1\} \)$ (Loop for `a`, transition to $\( q_1 \))$.
   - $\( \delta(q_0, b) = \{q_0\} \)$ (Loop for `b`).
   - $\( \delta(q_1, b) = \{q_2\} \)$ (Transition to $\( q_2 \))$.
   - $\( \delta(q_2, a) = \emptyset \)$, $\( \delta(q_2, b) = \emptyset \)$ (No transitions from $\( q_2 \))$.

4. **Initial State**: $\( q_0 \)$
5. **Accepting State**: $\( F = \{q_2\} \)$

---

#### **Transition Diagram**
```
      a,b       a         b
   (q0) -----> (q1) ----> ((q2))
    |  ^                   
    v  |                  
   (Loop on a,b)
```

#### **Language Recognition Examples**:
1. **Input: `ab`**
   - Start at $\( q_0 \)$.  
   - Read `a`: $\( q_0 \to q_1 \)$.  
   - Read `b`: $\( q_1 \to q_2 \)$.  
   - $\( q_2 \)$ is an accepting state. **Accepted**.

2. **Input: `bab`**
   - Start at $\( q_0 \)$.  
   - Read `b`: $\( q_0 \to q_0 \)$.  
   - Read `a`: $\( q_0 \to q_1 \)$.  
   - Read `b`: $\( q_1 \to q_2 \)$.  
   - $\( q_2 \)$ is an accepting state. **Accepted**.

3. **Input: `aa`**
   - Start at $\( q_0 \)$.  
   - Read `a`: $\( q_0 \to q_0 \)$, $\( q_0 \to q_1 \)$.  
   - Read `a`: $\( q_0 \to q_0 \)$, $\( q_1 \to \emptyset \)$.  
   - No path reaches $\( q_2 \)$. **Rejected**.

---

### **Example 2: NFA with ε-Transitions**
**Language**: Strings over $\( \Sigma = \{a, b\} \)$ containing `a`.

#### **NFA Definition**
1. **States**: $\( Q = \{q_0, q_1, q_2\} \)$
2. **Alphabet**: $\( \Sigma = \{a, b\} \)$
3. **Transitions $(\( \delta \))$**:
   - $\( \delta(q_0, \epsilon) = \{q_1, q_2\} \)$ (Move to $\( q_1 \)$ or $\( q_2 \)$ without consuming input).
   - $\( \delta(q_1, a) = \{q_2\} \)$ (Transition on `a` to $\( q_2 \))$.
   - $\( \delta(q_2, b) = \{q_2\} \)$ (Loop on `b`).

4. **Initial State**: $\( q_0 \)$
5. **Accepting State**: $\( F = \{q_2\} \)$

---

#### **Transition Diagram**
```
     ε        a
   (q0) ---> (q1) ---> ((q2))
     |                     ^
     |___________b_________|
```

#### **Language Recognition Examples**:
1. **Input: `a`**
   - Start at $\( q_0 \)$.  
   - ε-transition: $\( q_0 \to q_1, q_0 \to q_2 \)$.  
   - Read `a`: $\( q_1 \to q_2 \)$.  
   - $\( q_2 \)$ is an accepting state. **Accepted**.

2. **Input: `b`**
   - Start at $\( q_0 \)$.  
   - ε-transition: $\( q_0 \to q_1, q_0 \to q_2 \)$.  
   - Read `b`: $\( q_2 \to q_2 \)$.  
   - $\( q_2 \)$ is an accepting state. **Accepted**.

3. **Input: `bb`**
   - Start at $\( q_0 \)$.  
   - ε-transition: $\( q_0 \to q_1, q_0 \to q_2 \)$.  
   - Read `b`: $\( q_2 \to q_2 \)$.  
   - Read `b`: $\( q_2 \to q_2 \)$.  
   - $\( q_2 \)$ is an accepting state. **Accepted**.

4. **Input: `ba`**
   - Start at $\( q_0 \)$.  
   - ε-transition: $\( q_0 \to q_1, q_0 \to q_2 \)$.  
   - Read `b`: $\( q_2 \to q_2 \)$.  
   - Read `a`: $\( q_2 \to \emptyset \)$.  
   - No path reaches $\( q_2 \)$. **Rejected**.

---

### **Key Points**
- An NFA can have **multiple transitions** for the same input or **no transition** at all.
- **Epsilon-transitions** allow the automaton to move between states without consuming input.
- Every NFA can be converted to an equivalent DFA (but the DFA may have exponentially more states).
