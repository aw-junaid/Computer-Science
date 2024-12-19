### Scala - Exception Handling

Exception handling in Scala is very similar to other programming languages, such as Java. Scala uses `try`, `catch`, and `finally` blocks to handle exceptions. The main differences between Scala and Java are in syntax and how certain exceptions are handled.

### Basic Syntax

```scala
try {
  // Code that might throw an exception
} catch {
  case e: ExceptionType1 => // Handle exception of type ExceptionType1
  case e: ExceptionType2 => // Handle exception of type ExceptionType2
  // More case blocks can be added for different types of exceptions
} finally {
  // Optional block to execute code that should always run (e.g., cleanup)
}
```

### Example of Exception Handling

```scala
try {
  val result = 10 / 0  // This will throw an ArithmeticException
} catch {
  case e: ArithmeticException => println("ArithmeticException: Division by zero!")
  case e: Exception => println(s"An error occurred: ${e.getMessage}")
} finally {
  println("This will always run, whether or not an exception occurred.")
}
```

### Key Points
- **`try` block**: Contains the code that may throw an exception.
- **`catch` block**: Handles the exception if one is thrown. You can match on different types of exceptions and handle them accordingly.
- **`finally` block**: This block is optional and always runs, regardless of whether an exception is thrown or not. It’s often used for cleanup code (like closing files or database connections).

### Catching Multiple Exceptions

Scala allows you to catch multiple types of exceptions by using multiple `case` clauses inside the `catch` block:

```scala
try {
  val result = "text".toInt  // This will throw a NumberFormatException
} catch {
  case e: NumberFormatException => println("Cannot convert text to number")
  case e: Exception => println(s"General exception: ${e.getMessage}")
}
```

### Handling Multiple Exceptions with `match`

You can also use the `match` keyword to handle exceptions:

```scala
val number = "abc"

try {
  val parsedNumber = number.toInt
} catch {
  case ex: NumberFormatException => println("Error: Not a valid number.")
  case ex: Exception => println("Some other error occurred.")
}
```

### Using `throw` to Throw Exceptions

You can throw an exception explicitly using the `throw` keyword. It is used to signal an error in the program or to throw custom exceptions:

```scala
throw new ArithmeticException("This is an arithmetic error.")
```

You can also throw exceptions conditionally:

```scala
def divide(a: Int, b: Int): Int = {
  if (b == 0) throw new ArithmeticException("Division by zero!")
  else a / b
}

try {
  divide(10, 0)
} catch {
  case e: ArithmeticException => println(e.getMessage)
}
```

### Creating Custom Exceptions

You can define your own exception types by extending `Exception` or its subclasses. Custom exceptions allow you to be more specific about the types of errors in your program.

```scala
class InvalidAgeException(message: String) extends Exception(message)

def checkAge(age: Int): Unit = {
  if (age < 0) throw new InvalidAgeException("Age cannot be negative.")
  else println(s"Age is: $age")
}

try {
  checkAge(-5)
} catch {
  case e: InvalidAgeException => println(e.getMessage)
}
```

### Handling Checked and Unchecked Exceptions

- **Unchecked exceptions**: These are exceptions that extend `RuntimeException`. They do not require explicit handling in code.
- **Checked exceptions**: These extend `Exception` but not `RuntimeException`. In Java, they must be either caught or declared with `throws`. In Scala, there are no checked exceptions (Scala does not force you to declare exceptions).

### Using `try` with Expressions

In Scala, you can also use `try` as an expression that returns a value. The result of the `try` block will depend on whether an exception is thrown or not.

```scala
val result = try {
  val x = 10 / 2
  x  // Result of try block if no exception
} catch {
  case e: ArithmeticException => -1  // Value if exception is caught
}

println(result)  // Output: 5
```

If the code inside the `try` block throws an exception, the corresponding `catch` block is executed, and the value from the `catch` block is returned.

### `Try`, `Success`, and `Failure`

For functional programming approaches, Scala provides the `Try` class in the `scala.util` package. It is an alternative to using `try-catch` blocks and is often used in functional programming to represent operations that may fail.

- **`Try`** can be either a **`Success`** (when the operation succeeds) or a **`Failure`** (when the operation fails).

```scala
import scala.util.{Try, Success, Failure}

val result: Try[Int] = Try(10 / 0)

result match {
  case Success(value) => println(s"Success: $value")
  case Failure(exception) => println(s"Failed with exception: ${exception.getMessage}")
}
```

In this example:
- The `Try` is used to wrap the division operation that may throw an exception.
- If the operation succeeds, it returns `Success(value)`.
- If the operation fails (like division by zero), it returns `Failure(exception)`.

### `Option` and Exception Handling

In functional programming, instead of throwing exceptions, it’s common to use `Option` to represent the possibility of an operation succeeding or failing.

```scala
def safeDivide(a: Int, b: Int): Option[Int] = {
  if (b == 0) None  // Represents failure
  else Some(a / b)  // Represents success
}

val result = safeDivide(10, 0)
result match {
  case Some(value) => println(s"Result: $value")
  case None => println("Division by zero!")
}
```

Here, `None` represents failure (division by zero), and `Some(value)` represents a successful division.

### Conclusion

- **`try`/`catch`**: Used to catch and handle exceptions. You can catch multiple exception types, and the `finally` block always executes.
- **Throwing exceptions**: You can explicitly throw exceptions using `throw`.
- **Custom exceptions**: Scala allows you to create your own exception types by extending `Exception`.
- **Functional alternatives**: `Try`, `Success`, and `Failure` provide a functional way to handle exceptions, avoiding the need for `try-catch` blocks in some scenarios.
