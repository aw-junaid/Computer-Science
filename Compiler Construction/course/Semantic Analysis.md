### Semantic Analysis in Compiler Design

**Semantic analysis** is the phase of compiler design that comes after syntax analysis and ensures that the syntax-generated abstract syntax tree (AST) or intermediate representation (IR) adheres to the **semantic rules** of the programming language. While syntax analysis checks whether the source code follows the grammatical rules, semantic analysis focuses on ensuring that the program makes sense in terms of its meaning.

Semantic errors typically involve incorrect usage of variables, types, functions, or other constructs in a way that violates the semantics of the language (e.g., using a variable before initializing it, assigning incompatible types, or calling a function with the wrong number of arguments).

### Key Goals of Semantic Analysis

1. **Type Checking**: Ensuring that operations are performed on compatible types (e.g., adding an integer to a string is usually a semantic error).
2. **Symbol Table Management**: Maintaining and verifying information about variables, functions, and types used in the program.
3. **Scope and Binding**: Ensuring variables are declared before they are used and handling variable scope (local, global, etc.).
4. **Function Calls**: Verifying correct usage of functions (e.g., ensuring the correct number of arguments and types).
5. **Control Flow Verification**: Ensuring control flow constructs (like loops and conditionals) are semantically correct (e.g., ensuring no unreachable code exists).

### Key Components of Semantic Analysis

1. **Symbol Table**:
   - A **symbol table** is a data structure used to store information about the identifiers (variables, functions, etc.) in the program.
   - It stores metadata about each symbol, such as its name, type, scope, location, and whether it is initialized or defined.
   - The symbol table is used during semantic analysis to check for undeclared variables, duplicate declarations, type mismatches, etc.

2. **Type Checking**:
   - **Type checking** ensures that the types of expressions and variables are consistent with the operations being performed on them.
   - For example, if the language defines `int` and `float` types, an attempt to add an integer to a float might require either type coercion or raise a semantic error if the language does not support automatic conversion.
   - **Type Equivalence**: Ensures that the type of a variable matches the expected type in assignments, function arguments, and return values.
   - **Type Inference**: In some languages, the type of a variable might not be explicitly declared, and the compiler must infer it from context.

3. **Scope Checking**:
   - **Scope** defines the region of the program where a variable or function can be accessed.
   - **Static Scope** (also known as lexical scope): The scope is determined by the structure of the source code, typically at compile time.
   - **Dynamic Scope**: The scope is determined at runtime, which is less common but used in some languages like Lisp.
   - The semantic analysis phase ensures that a variable is not used before it is declared and that there are no conflicts between variables in different scopes.

4. **Control Flow Analysis**:
   - The semantic analysis phase checks if the control flow (such as `if`, `while`, and `for` statements) is correct.
   - For example, it ensures there are no unreachable code paths after a `return` statement or a loop condition.
   - **Unreachable Code**: Code that can never be executed due to control flow rules, such as code after a `return` in a function or a `break` inside a loop.
   - **Infinite Loops**: Checking the conditions of loops to ensure that they will terminate, if applicable.

5. **Function and Method Analysis**:
   - This ensures that function calls are consistent with their declarations.
   - **Arity Checking**: Verifying that the number of arguments passed to a function matches the number expected by its declaration.
   - **Type Checking of Arguments**: Ensuring that the types of the arguments match those expected by the function.
   - **Return Type Checking**: Ensuring that the type of the return value matches the function’s declared return type.

### Example: Semantic Errors

Consider the following code snippet in a hypothetical language:

```c
int x;
float y;
x = "Hello"; // Error: Type mismatch
y = x + 5; // Error: Incompatible types
```

- **Type Checking Error**: The assignment `x = "Hello";` is semantically incorrect because `x` is declared as an `int`, but `"Hello"` is a string. This would result in a type mismatch error.
- **Incompatible Types**: The expression `y = x + 5;` is invalid because `x` is an integer, and `5` is an integer, but `y` is declared as a `float`. Depending on language rules, this could either result in an error or be implicitly converted.

### Semantic Analysis Process

The process of semantic analysis typically involves:

1. **Traversing the Abstract Syntax Tree (AST)**: After syntax analysis, an AST is generated, representing the structure of the program. The semantic analysis phase traverses this tree to check for semantic correctness.
   
2. **Building the Symbol Table**: As the AST is traversed, information about each identifier (variable, function, etc.) is added to the symbol table. If a symbol is used before being declared, an error is reported.

3. **Type Checking**: As expressions and statements are processed, their types are checked to ensure they are compatible with the language's rules. This might involve checking if the left-hand side and right-hand side of assignments have the same type or if function arguments match the declared types.

4. **Scope Checking**: The compiler verifies that each variable is used within its scope, ensuring there are no undeclared variables, and that variables are not re-declared in the same scope (unless shadowing is allowed).

5. **Function Analysis**: When function calls are encountered, the compiler checks whether the function is defined, whether the correct number of arguments are passed, and whether the arguments' types match those expected by the function.

6. **Control Flow Analysis**: This phase checks if there are unreachable statements or infinite loops.

### Example of Symbol Table

For the following code:

```c
int x;
float y;
y = x + 10;
```

The symbol table would look like:

| Identifier | Type   | Scope    | Initialized | Location |
|------------|--------|----------|-------------|----------|
| x          | int    | Global   | Yes         | 0        |
| y          | float  | Global   | Yes         | 1        |

- The compiler would verify that `x` and `y` are used correctly in the expression `y = x + 10`.
- If `x` had not been initialized or declared, the semantic analyzer would flag this as an error.

### Advanced Semantic Analysis

Some advanced features of semantic analysis include:

1. **Polymorphism**: In languages with object-oriented features, semantic analysis handles polymorphism by checking that the method being invoked is applicable to the object’s type.
2. **Overloading**: In languages that support overloading (e.g., function overloading), the semantic analyzer ensures that the correct version of the function is called based on the number and types of arguments.
3. **Type Inference**: In languages like Haskell or TypeScript, where types may not be explicitly declared, the compiler must infer the types of expressions, variables, and functions.

### Example of Type Checking

Consider a language with integer and float types. The semantic analysis would check:

```c
int x;
float y;
x = 10;
y = 2.5;
x = x + y;  // Error: Type mismatch (int + float is not allowed)
```

Here, the semantic analyzer would flag the line `x = x + y;` as an error because `x` is an `int` and `y` is a `float`, and the operation might not be valid unless implicit type conversion is allowed.

### Summary

Semantic analysis is a critical phase in the compilation process, ensuring that the program adheres to the language's semantic rules. It involves:

- **Type checking**: Ensuring that operations and assignments make sense with respect to types.
- **Scope checking**: Ensuring that variables are declared and used within valid scopes.
- **Symbol table management**: Storing and verifying information about variables, functions, and types.
- **Control flow analysis**: Ensuring correct flow of execution without errors like unreachable code or infinite loops.
- **Function analysis**: Ensuring correct function usage, including arguments and return types.

By performing these checks, semantic analysis helps ensure that the program is not only syntactically correct but also logically meaningful, preventing errors that could cause runtime issues.
