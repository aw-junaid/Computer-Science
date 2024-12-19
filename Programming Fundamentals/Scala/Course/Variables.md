In Scala, **variables** are used to store values, and the language provides two primary ways to define variables: **immutable** and **mutable**. Scala encourages the use of **immutable variables** (`val`), but you can also use **mutable variables** (`var`) when necessary.

### 1. **Immutable Variables (`val`)**

An immutable variable is one whose value cannot be changed after it has been initialized. Once a value is assigned to a `val`, you cannot reassign it.

#### Syntax:

```scala
val variableName: Type = value
```

- `val`: Keyword used to declare an immutable variable.
- `variableName`: The name of the variable.
- `Type`: The type of the variable (optional, as Scala can infer it).
- `value`: The value assigned to the variable.

#### Example:

```scala
val age: Int = 25
val name = "Scala"  // Scala infers that name is a String
```

Once `val` is initialized, you cannot reassign its value:

```scala
// This will cause a compilation error
age = 30  // Error: reassignment to val
```

### 2. **Mutable Variables (`var`)**

A mutable variable is one whose value can be changed after it has been initialized. This is useful when you need to update the value of a variable over time.

#### Syntax:

```scala
var variableName: Type = value
```

- `var`: Keyword used to declare a mutable variable.
- `variableName`: The name of the variable.
- `Type`: The type of the variable (optional).
- `value`: The value assigned to the variable.

#### Example:

```scala
var counter: Int = 0
counter = counter + 1  // This is valid as counter is mutable
```

You can change the value of `counter` as many times as needed:

```scala
println(counter)  // Output: 1
counter = 10
println(counter)  // Output: 10
```

### 3. **Type Inference**

Scala supports **type inference**, meaning you do not always have to explicitly specify the type of a variable. The compiler can infer the type from the assigned value.

#### Example:

```scala
val number = 42   // The compiler infers that 'number' is of type Int
val greeting = "Hello"  // The compiler infers that 'greeting' is a String
```

However, if you want to be explicit or the compiler can't infer the type, you can specify it:

```scala
val price: Double = 19.99  // Explicitly defined as Double
```

### 4. **Constant Variables (`val`)**

In Scala, constants are often defined using `val` because the values are fixed. These constants are immutable and their values are usually known at compile-time.

#### Example:

```scala
val PI = 3.14159
val MAX_LIMIT = 100
```

### 5. **Lazy Variables (`lazy val`)**

In Scala, you can define a **lazy variable** using the `lazy val` keyword. A lazy variable is evaluated only when it is accessed for the first time, which can be useful for performance optimization in some cases.

#### Syntax:

```scala
lazy val variableName: Type = value
```

#### Example:

```scala
lazy val expensiveComputation = {
  println("Performing expensive computation...")
  42  // Just a dummy computation
}

println("Before accessing lazy value")
println(expensiveComputation)  // The expensive computation happens here
```

In this example, the message `"Performing expensive computation..."` will be printed only the first time the `expensiveComputation` variable is accessed.

### 6. **Naming Variables**

Scala follows typical naming conventions for variables:

- Variable names should begin with a lowercase letter (e.g., `val age = 25`).
- You can use underscores and other characters in variable names (e.g., `val first_name = "Alice"`).
- Scala supports Unicode characters in variable names, so you can use non-English characters if needed.

### 7. **Variable Scope**

Variables in Scala have a scope, meaning they can be accessed only within certain parts of the program:

- **Local Variables**: Declared within a method or block, they are accessible only within that method/block.
- **Global Variables**: Declared at the top level, accessible throughout the entire program.

#### Example of Local Scope:

```scala
def exampleMethod(): Unit = {
  val localVariable = 10  // Local to exampleMethod
  println(localVariable)   // Output: 10
}

println(localVariable)  // Error: not accessible outside the method
```

### 8. **Multiple Variable Assignments**

You can assign values to multiple variables in a single line using tuple syntax:

```scala
val (x, y, z) = (10, 20, 30)
println(x)  // Output: 10
println(y)  // Output: 20
println(z)  // Output: 30
```

### 9. **Reassigning Variables**

- For **mutable** variables (`var`), you can reassign values freely.
- For **immutable** variables (`val`), reassignment is not allowed once a value is assigned.

### 10. **Null and Default Values**

In Scala, `null` can be assigned to any reference type variable (`AnyRef`), but not to primitive types like `Int`, `Double`, etc.

```scala
val str: String = null  // Reference type
// val num: Int = null  // Compilation error: cannot assign null to primitive type
```

If you want a default value for a variable, you can use `Option` to represent a value that may or may not exist (i.e., null values).

```scala
val optValue: Option[Int] = None  // Represents a missing value
```

### Summary of Scala Variable Types:

| **Keyword**   | **Description**                                   | **Example**                                |
|---------------|---------------------------------------------------|--------------------------------------------|
| **val**       | Immutable (constant) variable                     | `val age = 25`                             |
| **var**       | Mutable variable (value can be changed)           | `var counter = 0; counter += 1`            |
| **lazy val**  | Lazy initialization (evaluated on first access)   | `lazy val result = expensiveComputation()` |
| **val/var**   | Type inference allows Scala to deduce type       | `val greeting = "Hello"`                   |
| **null**      | Reference type with no value                      | `val str: String = null`                   |

### Best Practices:

1. **Prefer `val` over `var`**: To maintain immutability and avoid side effects, prefer using `val` for variables that don't need to change.
2. **Use `lazy val` for performance optimization**: When dealing with expensive computations that may not always be used.
3. **Avoid using `null`**: Use `Option` for nullable values to represent the presence or absence of data more explicitly.
