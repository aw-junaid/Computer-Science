### **Formal Definition of a DFA**

A **Deterministic Finite Automaton (DFA)** is formally defined as a 5-tuple:

$\[
M = (Q, \Sigma, \delta, q_0, F)
\]$

Where:
1. **\( Q \):**  
   A finite set of states.  
   Example: $\( Q = \{q_0, q_1, q_2\} \)$.

2. **$\( \Sigma \)$:**  
   A finite set of input symbols, called the alphabet.  
   Example: $\( \Sigma = \{0, 1\} \)$.

3. **$\( \delta \)$:**  
   A transition function $\( \delta: Q \times \Sigma \to Q \)$.  
   This function maps each state and input symbol to a single next state.  
   Example: $\( \delta(q_0, 0) = q_1 \)$.

4. **$\( q_0 \)$:**  
   The initial state, where computation starts.  
   $\( q_0 \in Q \)$.  
   Example: $\( q_0 = q_0 \)$.

5. **\( F \):**  
   A set of accepting (or final) states.  
   $\( F \subseteq Q \)$.  
   Example: $\( F = \{q_2\} \)$.

---

### **Structure of a DFA**
A DFA consists of the following components:

#### 1. **States $(\( Q \))$**
   - Represent different stages of the computation.
   - A DFA has a finite number of states.

#### 2. **Alphabet $(\( \Sigma \))$**
   - Defines the set of symbols that the DFA can read as input.
   - The alphabet must be finite.

#### 3. **Transition Function $(\( \delta \))$**
   - Defines how the DFA moves between states based on the current state and input symbol.
   - For each state $\( q \in Q \)$ and each input symbol $\( a \in \Sigma \)$, $\( \delta(q, a) \)$ is uniquely defined (no ambiguity).

#### 4. **Initial State $(\( q_0 \))$**
   - The starting point of the DFA, where computation begins.

#### 5. **Accepting States (\( F \))**
   - The set of states where, if the DFA halts, the input string is considered accepted.

---

### **Example**
#### Problem: DFA to recognize strings over $\( \Sigma = \{0, 1\} \)$ ending with `01`.

**Formal Definition:**
1. $\( Q = \{q_0, q_1, q_2\} \)$
2. $\( \Sigma = \{0, 1\} \)$
3. $\( \delta \)$ (transition function):

| State | Input \( 0 \) | Input \( 1 \) |
|-------|--------------|--------------|
| $\( q_0 \)$ | $\( q_0 \)$       | $\( q_1 \)$       |
| $\( q_1 \)$ | $\( q_2 \)$       | $\( q_1 \)$       |
| $\( q_2 \)$ | $\( q_0 \)$       | $\( q_1 \)$       |

4. $\( q_0 = q_0 \)$ (initial state)  
5. $\( F = \{q_2\} \)$ (accepting state)

---

### **State Transition Diagram**
- **States:** Represented by circles.
- **Transitions:** Directed arrows between states labeled with input symbols.
- **Initial State:** Arrow pointing to the state.
- **Accepting State:** Double circle.

For this example:

- $\( q_0 \)$: Initial state (loops on $\( 0 \)$, transitions to $\( q_1 \)$ on \( 1 \)).
- $\( q_1 \)$: Transitions to $\( q_2 \)$ on $\( 0 \)$ and stays on $\( q_1 \)$ on \( 1 \).
- $\( q_2 \)$: Accepting state (loops to $\( q_0 \)$ or transitions to $\( q_1 \))$.

This DFA will accept strings like `01`, `101`, `001`, etc., and reject strings like `0`, `11`, `10`. 

