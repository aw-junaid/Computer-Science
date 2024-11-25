In compiler design, a **bottom-up parser** is a parsing technique that constructs a parse tree for the input string by starting from the leaves (input tokens) and working up to the root (start symbol). Bottom-up parsing is often more powerful than top-down parsing, as it can handle a wider range of grammars, including many that are left-recursive and ambiguous. This type of parser is commonly used for complex grammars in programming languages, such as C and Java.

### Characteristics of Bottom-Up Parsers

- **Reduction-Based**: Bottom-up parsers repeatedly apply **reductions** to transform the input tokens into the start symbol.
- **Shift and Reduce Actions**: Bottom-up parsers often use **shift** and **reduce** operations to process input tokens and build the parse tree.
- **Construct Parse Tree from Leaves to Root**: They start with input symbols (leaves) and combine them progressively until they reach the start symbol (root).
- **Rightmost Derivation in Reverse**: Bottom-up parsers construct a parse tree by performing a rightmost derivation in reverse.

### Types of Bottom-Up Parsers

The main types of bottom-up parsers are **Shift-Reduce Parsers** and **LR Parsers** (where "LR" stands for Left-to-right scan of input, Rightmost derivation in reverse).

### 1. Shift-Reduce Parser

A **shift-reduce parser** is a simple form of a bottom-up parser that uses a stack to hold symbols and a set of actions (shift, reduce, accept, error) to decide how to process the input tokens.

#### Shift-Reduce Actions

- **Shift**: Push the next input token onto the stack and advance the input pointer to the next token.
- **Reduce**: Replace the top elements of the stack with a non-terminal if they match the right-hand side of a production rule.
- **Accept**: Successfully recognize the input string when the start symbol is derived, and the input has been completely processed.
- **Error**: Report an error if no valid action is possible.

#### Example of Shift-Reduce Parsing

Consider a grammar for arithmetic expressions:

```
Expr → Expr + Term
Expr → Term
Term → Term * Factor
Term → Factor
Factor → ( Expr )
Factor → number
```

An input string like `number + number * number` would be parsed with actions such as:

| Step | Stack           | Input              | Action     |
|------|------------------|--------------------|------------|
| 1    | (empty)         | `number + number * number` | Shift `number` |
| 2    | `number`        | `+ number * number` | Reduce by `Factor → number` |
| 3    | `Factor`        | `+ number * number` | Reduce by `Term → Factor`   |
| 4    | `Term`          | `+ number * number` | Reduce by `Expr → Term`    |
| ...  |                 |                    | ...        |

In this example:
- Shift-reduce parsers use pattern matching to detect sequences of symbols on the stack that match the right side of a production rule, then reduce these sequences to the corresponding non-terminal.
- Conflicts, such as **shift-reduce** and **reduce-reduce** conflicts, can arise in ambiguous grammars, making it difficult to decide the next action. 

### 2. LR Parsers

**LR parsers** are a more sophisticated and powerful class of bottom-up parsers that can handle a larger set of grammars, including almost all context-free grammars used in programming languages. LR parsers are deterministic and use lookahead to decide whether to shift or reduce without backtracking.

#### Types of LR Parsers

1. **SLR (Simple LR)**:
   - Uses **FOLLOW sets** to create the parsing table.
   - Simplified and efficient but can handle fewer grammars than other types of LR parsers.
   
2. **CLR (Canonical LR)**:
   - Constructs the parsing table using **LR(1) items**, which include one token of lookahead.
   - More powerful than SLR but requires larger parsing tables, which can be inefficient.
   
3. **LALR (Lookahead LR)**:
   - Combines states in the CLR parsing table with the same core items but different lookaheads to reduce table size.
   - Widely used in real-world compilers as it balances efficiency and parsing power.

### LR Parsing Algorithm

The LR parsing algorithm uses a **stack** and a **parsing table** (Action and Goto table) to determine parsing actions. Here’s a step-by-step outline of the LR parsing process:

1. **Initialize Stack**: Start with the stack containing the start state (often state 0).
2. **Loop Until Acceptance or Error**:
   - Use the current state (top of the stack) and the lookahead token to consult the **Action table**.
   - **Action Table**:
     - **Shift**: Push the next state onto the stack and advance the input pointer.
     - **Reduce**: Pop symbols from the stack according to the right-hand side of the production rule, then push the non-terminal and go to the new state as per the **Goto table**.
     - **Accept**: If the start symbol is derived and the input is exhausted, parsing is successful.
     - **Error**: If no valid action is found, report a syntax error.
3. **Continue** until the input is fully processed or an error is encountered.

#### Example of an LR Parsing Table

Given the following grammar:

```
S → AA
A → aA | b
```

And an input string `aab`, the parsing table might look like this (simplified for clarity):

| State | `a`          | `b`          | `$`          | Goto S | Goto A |
|-------|--------------|--------------|--------------|--------|--------|
| 0     | Shift 2      | Shift 3      |              | 1      | 4      |
| 1     |              |              | Accept       |        |        |
| 2     | Shift 2      | Shift 3      |              |        |        |
| 3     | Reduce `A → b` | Reduce `A → b` |         |        |        |
| 4     | Reduce `A → aA` | Reduce `A → aA` |         |        |        |

In this example:
- The **Action Table** shows shifts, reduces, and accept actions based on the current state and input token.
- The **Goto Table** indicates the next state after a reduction.

### Parsing Table Construction (for LR Parsers)

1. **Compute LR(0) or LR(1) Items**: These represent potential derivations from a given state in the grammar.
2. **Build State Transitions**: For each item, compute transitions based on grammar symbols.
3. **Construct Action and Goto Tables**:
   - **Action Table**: Specifies shift, reduce, accept, or error based on the state and lookahead.
   - **Goto Table**: Used after reductions, specifies the next state for non-terminals.

### Advantages and Limitations of Bottom-Up Parsers

#### Advantages
- **More Powerful**: Bottom-up parsers, especially LR parsers, can handle a larger set of grammars than top-down parsers, including left-recursive grammars.
- **Deterministic Parsing**: LR parsers use deterministic parsing tables, making them efficient and avoiding backtracking.
- **Used in Real-World Compilers**: Many real-world compilers (such as GCC and Java compilers) use bottom-up parsing, particularly LALR parsers.

#### Limitations
- **Complexity**: LR parsers are more complex to construct and understand, especially in building parsing tables.
- **Large Parsing Tables**: Canonical LR parsers (CLR) have large parsing tables, which can be inefficient.
- **Error Recovery**: Bottom-up parsers are less intuitive for error recovery compared to top-down parsers, requiring specialized techniques for graceful error handling.

### Error Handling in Bottom-Up Parsers

1. **Panic Mode**: Skip tokens until a synchronization point (like a semicolon or closing brace).
2. **Phrase-Level Recovery**: Insert or delete tokens to allow parsing to continue, usually done by modifying the parse stack.
3. **Error Productions**: Add special productions to the grammar that detect common errors and handle them gracefully.
4. **Global Correction**: Determines the minimal number of changes required to correct an error, though this approach is computationally intensive and not practical for real-time parsing.

### Summary

Bottom-up parsers are powerful parsing techniques that construct the parse tree starting from the input tokens and moving up to the start symbol. They can handle a broader class of grammars than top-down parsers, making them suitable for most programming languages. Among bottom-up parsers, LR parsers (especially SLR, CLR, and LALR) are widely used in compiler construction for their deterministic behavior and ability to handle complex syntax. However, bottom-up parsers are generally more complex to build and require large parsing tables, though they provide robust solutions for parsing real-world languages.
