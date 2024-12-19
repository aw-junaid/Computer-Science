In Scala, **partially applied functions** allow you to apply only some of the arguments to a function, resulting in a new function that takes the remaining arguments. This is a powerful concept in functional programming, as it allows for greater flexibility and modularity in function composition.

### What is a Partially Applied Function?

A **partially applied function** is a function that has some arguments fixed (applied) and returns a new function that accepts the remaining arguments. This can be useful when you want to reuse a function with some arguments pre-set, without having to define a new function manually.

### Syntax for Partially Applied Functions

The syntax for partially applying a function is as follows:

```scala
def functionName(arg1: Type, arg2: Type, ..., argN: Type): ReturnType = {
  // function body
}

val partialFunction = functionName(arg1, arg2, ...)
```

By providing some of the arguments and leaving the rest to be supplied later, you create a new function that takes the remaining arguments.

### Example 1: Simple Partially Applied Function

Let's define a function that takes three parameters and returns their sum:

```scala
def add(a: Int, b: Int, c: Int): Int = a + b + c

// Partially applying the 'add' function by fixing the first two arguments
val addFiveAndThree = add(5, 3, _: Int)

// Now, we can apply the remaining argument (7)
println(addFiveAndThree(7))  // Output: 15
```

### Explanation:
- `add(5, 3, _: Int)` partially applies the first two arguments (`5` and `3`) and leaves the third argument to be supplied later (using the placeholder `_: Int`).
- The new function `addFiveAndThree` takes an integer and adds it to `5 + 3`, resulting in the sum of all three arguments.

### Example 2: Partially Applied Function with Multiple Calls

You can apply multiple arguments and reuse the partially applied function in different contexts.

```scala
def multiply(a: Int, b: Int, c: Int): Int = a * b * c

// Partially apply the first two arguments (2 and 3)
val multiplyByTwoAndThree = multiply(2, 3, _: Int)

// Apply the remaining argument (4)
println(multiplyByTwoAndThree(4))  // Output: 24

// Apply the remaining argument (5)
println(multiplyByTwoAndThree(5))  // Output: 30
```

### Explanation:
- The function `multiply` is partially applied with the first two arguments (`2` and `3`), and the resulting function `multiplyByTwoAndThree` takes one remaining argument.
- The partial function can be used multiple times with different values for the remaining argument, leading to different results.

### Example 3: Using Partially Applied Functions in Collections

You can use partially applied functions in methods like `map`, `filter`, or `reduce` for more modular code.

```scala
def multiply(a: Int, b: Int): Int = a * b

// Partially applying the first argument (2)
val multiplyByTwo = multiply(2, _: Int)

val numbers = List(1, 2, 3, 4, 5)
val results = numbers.map(multiplyByTwo)  // Multiply each element by 2

println(results)  // Output: List(2, 4, 6, 8, 10)
```

### Explanation:
- The `multiplyByTwo` function is a partially applied function that multiplies any given number by `2`.
- The `map` method applies `multiplyByTwo` to each element of the `numbers` list, producing a new list where each element is doubled.

### Example 4: Using Partially Applied Functions for Custom Logic

Let's say we want to define a function that formats a greeting message. We can partially apply it to fix some parts of the message and pass in the dynamic parts later.

```scala
def greet(greeting: String, name: String, punctuation: String): String = {
  s"$greeting, $name$punctuation"
}

// Partially apply the first two arguments ('Hello' and 'World')
val greetWorld = greet("Hello", "World", _: String)

// Now, we can provide the punctuation mark
println(greetWorld("!"))  // Output: Hello, World!
println(greetWorld("."))  // Output: Hello, World.
```

### Explanation:
- `greet("Hello", "World", _: String)` creates a partially applied function that fixes the `greeting` as `"Hello"` and the `name` as `"World"`, leaving the punctuation to be passed later.

### Example 5: Partially Applied Functions with Curried Functions

In Scala, functions can also be **curried**, which is another way to work with partially applied functions. A curried function takes its arguments one by one, and each call to the function returns another function until all arguments are provided.

```scala
def add(a: Int)(b: Int)(c: Int): Int = a + b + c

// Partially apply the first argument (5)
val addFive = add(5)_

// Partially apply the second argument (3)
val addFiveAndThree = addFive(3)_

// Finally, apply the third argument (7)
println(addFiveAndThree(7))  // Output: 15
```

### Explanation:
- The curried version of `add` takes three arguments in separate parentheses, and you can apply each argument one by one.
- `add(5)` returns a function that takes `b`, and `addFive(3)` returns a function that takes `c`. Finally, `addFiveAndThree(7)` produces the result.

### Key Points:
1. **Partially Applied Functions** allow you to fix some of the arguments of a function, creating a new function that takes the remaining arguments.
2. **Currying** is a related concept that involves transforming a function into a series of functions, each taking one argument.
3. **Flexibility**: Partially applied functions help create more flexible and reusable code by allowing you to preset some arguments while deferring others.
4. **Common Use Cases**: Partially applied functions are commonly used in operations like `map`, `filter`, `reduce`, and for handling functions with repetitive or default arguments.

### Conclusion:

Partially applied functions in Scala are a powerful tool in functional programming, allowing you to define functions with some arguments pre-applied and others supplied later. This concept is useful for creating more flexible and reusable functions, especially when working with collections or higher-order functions. Additionally, currying provides an elegant way to work with partially applied functions by transforming them into a sequence of function calls.
