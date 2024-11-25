In compiler design, a **top-down parser** is a parsing technique that starts from the **start symbol** of a grammar and tries to derive the input string by breaking it down into smaller components using production rules. The top-down parser works by expanding each non-terminal in the grammar based on the input tokens, attempting to match the input string from left to right. This type of parser is relatively intuitive and is often used for simpler grammars.

### Characteristics of Top-Down Parsers

- **Starts with the Start Symbol**: The parser begins at the root of the parse tree and tries to derive the input string down to its leaves by applying production rules.
- **Predictive in Nature**: The parser predicts which production to use next based on the lookahead token(s).
- **Builds the Parse Tree from Top to Bottom**: It constructs the parse tree in a top-down fashion, starting with the start symbol and expanding it according to the grammar rules.
- **Best for LL Grammars**: LL grammars (Left-to-right scan, Leftmost derivation) are ideal for top-down parsing, especially if they have no left recursion or ambiguity.

### Types of Top-Down Parsers

There are two main types of top-down parsers:

1. **Recursive Descent Parser**
2. **Predictive Parser**

### 1. Recursive Descent Parser

A **recursive descent parser** is a straightforward, recursive approach to parsing that uses a set of recursive functions, each corresponding to a non-terminal in the grammar. Each function tries to match the input tokens with the right-hand side of a production rule.

#### Characteristics

- **Simple to Implement**: Each non-terminal in the grammar has a corresponding function in the parser.
- **Grammar Restrictions**: Recursive descent parsers cannot handle **left recursion** (where a non-terminal on the left side of a production can eventually derive itself on the right side).
- **Backtracking**: Basic recursive descent parsers may use backtracking, where the parser reverts to previous choices when an attempt fails, though this is inefficient.

#### Example Grammar and Recursive Descent Parsing

Consider a simple grammar for arithmetic expressions:

```
Expr → Term + Expr | Term
Term → Factor * Term | Factor
Factor → ( Expr ) | number
```

Here’s how a recursive descent parser might be structured in code (pseudo-code):

```python
def parse_expr():
    parse_term()
    if next_token == '+':
        match('+')
        parse_expr()

def parse_term():
    parse_factor()
    if next_token == '*':
        match('*')
        parse_term()

def parse_factor():
    if next_token == '(':
        match('(')
        parse_expr()
        match(')')
    elif next_token == 'number':
        match('number')
```

In this example:
- `parse_expr()` tries to match `Expr` by calling `parse_term()` and checking for a `+` operator.
- Each function attempts to match a sequence of tokens corresponding to its non-terminal, building the parse tree from the top down.
  
#### Limitation: Left Recursion

Recursive descent parsers cannot handle left recursion, where a non-terminal refers to itself in a leftmost position (e.g., `Expr → Expr + Term`). This can lead to infinite recursion. To use recursive descent, the grammar must be **rewritten** to remove left recursion.

For example:
   ```
   Left Recursive Form:     Expr → Expr + Term | Term
   Non-Left Recursive Form: Expr → Term Expr'
                             Expr' → + Term Expr' | ε
   ```

### 2. Predictive Parser (Non-Recursive, LL(1) Parser)

A **predictive parser** is a type of top-down parser that eliminates the need for backtracking by using a lookahead token (usually one token) to decide which production to apply. Predictive parsers are also known as **LL(1) parsers**, where:
   - **L**: Left-to-right scan of the input.
   - **L**: Leftmost derivation.
   - **1**: One token of lookahead.

#### Characteristics

- **No Backtracking**: Predictive parsers use a lookahead token and a parsing table to eliminate backtracking, making parsing deterministic.
- **LL(1) Grammar**: Predictive parsers require the grammar to be LL(1), meaning that at any point, only one production is applicable based on the lookahead token.
- **Parsing Table**: A parsing table guides the parser in choosing the right production based on the current non-terminal and lookahead token.

#### Steps to Build a Predictive Parser

1. **Remove Left Recursion**: Rewrite any left-recursive productions.
2. **Left-Factoring**: Factor out common prefixes from productions to ensure that the parser can make a single decision based on lookahead.
3. **Construct FIRST and FOLLOW Sets**:
   - **FIRST Set**: For each non-terminal, the FIRST set is the set of terminals that can appear at the beginning of strings derived from that non-terminal.
   - **FOLLOW Set**: For each non-terminal, the FOLLOW set is the set of terminals that can appear immediately to the right of that non-terminal in any valid derivation.
4. **Build Parsing Table**:
   - For each non-terminal and lookahead token, the parsing table entry specifies which production to apply.
   - If the entry is empty, it means there’s no valid production for that combination, indicating a syntax error.

#### Predictive Parsing Table Example

Given the following grammar:
```
Expr → Term Expr'
Expr' → + Term Expr' | ε
Term → Factor Term'
Term' → * Factor Term' | ε
Factor → ( Expr ) | number
```

Constructing **FIRST** and **FOLLOW** sets allows us to build a parsing table, such as:

| Non-Terminal | Lookahead | Production         |
|--------------|-----------|--------------------|
| Expr         | number    | Expr → Term Expr'  |
| Expr         | (         | Expr → Term Expr'  |
| Expr'        | +         | Expr' → + Term Expr' |
| Expr'        | )         | Expr' → ε          |
| Term         | number    | Term → Factor Term'|
| Term'        | *         | Term' → * Factor Term' |
| Factor       | number    | Factor → number    |
| Factor       | (         | Factor → ( Expr )  |

This table enables the parser to decide which production to apply based on the current non-terminal and lookahead symbol.

#### Predictive Parsing Algorithm

1. **Initialize Stack**: Start with the start symbol on the parse stack.
2. **Loop Until Stack is Empty**:
   - If the top of the stack is a terminal and matches the current input token, pop the stack and advance the input.
   - If the top of the stack is a non-terminal, consult the parsing table for the correct production based on the current lookahead token.
   - Replace the non-terminal with the right-hand side of the production in the stack.
3. **Error Handling**: If there’s no valid entry in the parsing table, report a syntax error.

### Advantages and Limitations of Top-Down Parsers

#### Advantages
- **Simplicity**: Top-down parsers are straightforward and easy to implement, especially recursive descent parsers.
- **Intuitive**: They mimic the natural structure of many grammars, starting with the goal (start symbol) and breaking it down.
- **Useful for Simple Languages**: Suitable for small languages or subsets of languages with non-ambiguous, non-left-recursive grammars.

#### Limitations
- **Grammar Restrictions**: Top-down parsers cannot handle left-recursive grammars directly.
- **Limited Power**: They are not suitable for complex or highly ambiguous grammars, as they require an LL(1) structure for predictive parsing.
- **Error Recovery**: Top-down parsers have limited error recovery mechanisms compared to bottom-up parsers.

### Summary

Top-down parsers are parsing techniques that build the parse tree from the start symbol down to the input tokens, expanding non-terminals to match the input. Recursive descent parsers are simple but require grammars without left recursion, while predictive parsers (LL(1)) improve efficiency by using lookahead and a parsing table. Although top-down parsing is simpler and effective for basic grammars, it is not as powerful as bottom-up parsing techniques like LR parsers, which can handle a wider range of grammars commonly used in programming languages.
