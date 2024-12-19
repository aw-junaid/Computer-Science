In Scala, **Call-by-Name** is a special parameter-passing mechanism used in functions. It delays the evaluation of an argument until it is actually used inside the function. This is different from the usual **Call-by-Value** parameter passing, where arguments are evaluated before the function is called.

### Call-by-Name: How It Works

In **Call-by-Name**, the argument expression is not evaluated when the function is called. Instead, the argument is passed as a **thunk**, which is a *suspended computation* or an *unevaluated expression*. The expression is only evaluated when it is used inside the function body.

This can be useful in situations where you want to avoid unnecessary computation or implement things like lazy evaluation or infinite data structures.

### Syntax

To define a parameter in a function as **Call-by-Name**, you simply place the parameter type after the argument name with the `=>` symbol.

#### Example Syntax:
```scala
def functionName(arg: => Type): ReturnType = {
  // Function body
}
```

### Example of Call-by-Name

Let's look at an example where we demonstrate **Call-by-Name** behavior.

```scala
def printTwice(x: => String): Unit = {
  println(x)  // First usage
  println(x)  // Second usage
}

printTwice({
  println("Evaluating the argument")
  "Hello, Scala!"
})
```

#### Output:
```
Evaluating the argument
Hello, Scala!
Evaluating the argument
Hello, Scala!
```

### Explanation:
- The function `printTwice` takes a **Call-by-Name** argument `x` of type `String`.
- The argument is an expression: `{ println("Evaluating the argument"); "Hello, Scala!" }`.
- Notice that the expression is **not evaluated when the function is called**. Instead, it is evaluated **each time it is used** inside the function.
- The message `"Evaluating the argument"` is printed twice, once for each usage of `x`.

### Difference Between Call-by-Name and Call-by-Value

#### Call-by-Value:
- In **Call-by-Value**, the argument is evaluated before the function call, and the result is passed to the function.
- If you call a function with a **Call-by-Value** argument, the expression will be evaluated once, and its result will be passed to the function.

#### Example of Call-by-Value:
```scala
def printTwice(x: String): Unit = {
  println(x)
  println(x)
}

printTwice({
  println("Evaluating the argument")
  "Hello, Scala!"
})
```

#### Output:
```
Evaluating the argument
Hello, Scala!
Hello, Scala!
```

### Key Differences:

1. **Evaluation Timing:**
   - **Call-by-Value**: The argument is evaluated before the function call.
   - **Call-by-Name**: The argument is evaluated every time it is used inside the function.

2. **Performance:**
   - **Call-by-Value** may evaluate an argument unnecessarily (if the argument is never used).
   - **Call-by-Name** avoids evaluating an argument if it’s not used, but it might evaluate the argument multiple times if used multiple times.

3. **Use Cases:**
   - **Call-by-Name** is useful when you want to implement **lazy evaluation** (deferred computation) or for defining **infinite data structures**.
   - **Call-by-Value** is more common when you need to pass pre-evaluated values to a function.

### Call-by-Name with Lazy Evaluation Example

One of the most common use cases for **Call-by-Name** is **lazy evaluation**.

#### Example:
```scala
def lazyEvaluation(x: => Int): Unit = {
  println("Before evaluation")
  println(x)  // The argument is evaluated only when used here.
}

lazyEvaluation({
  println("Evaluating the argument")
  5 + 3
})
```

#### Output:
```
Before evaluation
Evaluating the argument
8
```

- In the `lazyEvaluation` function, the argument `x` is not evaluated until the `println(x)` line is reached.
- This is useful in cases where you might want to delay expensive calculations until they are actually needed.

### Summary of Call-by-Name in Scala:

| **Feature**                         | **Call-by-Value**                        | **Call-by-Name**                         |
|-------------------------------------|------------------------------------------|------------------------------------------|
| **Evaluation Timing**               | Evaluated before the function call.      | Evaluated when used inside the function. |
| **Performance**                     | May evaluate unnecessary expressions.    | Avoids evaluation if the argument is unused. |
| **Use Case**                        | For normal functions with pre-evaluated arguments. | For lazy evaluation, infinite data structures, or computations that are expensive and should be deferred. |
| **Default Behavior**                | Default behavior in Scala.               | Needs explicit `=>` to indicate Call-by-Name. |

### Conclusion:
**Call-by-Name** in Scala allows for deferred evaluation of function arguments, which can be useful in scenarios like lazy evaluation or avoiding unnecessary computations. It differs from **Call-by-Value**, where the argument is evaluated before the function call. Understanding the difference can help you optimize performance and handle complex evaluation patterns in your code.
