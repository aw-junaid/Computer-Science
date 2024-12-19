In Scala, **nested functions** are functions defined inside other functions. This allows you to create functions that are only relevant within the scope of the containing function, promoting better encapsulation and modularity.

### Key Characteristics of Nested Functions:
1. **Local Scope**: A nested function is only visible within the body of the outer function and cannot be accessed from outside.
2. **Closure**: Nested functions can access the parameters and variables of the outer function, creating a concept known as a **closure**.
3. **Recursion**: Nested functions can call themselves recursively, which can be useful for implementing recursive logic in a localized scope.

### Syntax for Nested Functions

```scala
def outerFunction(param1: Type, param2: Type): ReturnType = {
  // outer function body
  
  def innerFunction(innerParam: Type): ReturnType = {
    // inner function body
  }
  
  // You can call innerFunction here
}
```

### Example 1: Basic Nested Functions

Here’s a simple example where an inner function is defined within an outer function.

```scala
def outerFunction(x: Int, y: Int): Int = {
  def innerFunction(a: Int, b: Int): Int = a + b
  
  innerFunction(x, y)  // Calling the inner function
}

// Example usage:
val result = outerFunction(3, 4)  // Output: 7
println(result)
```

### Explanation:
- `innerFunction` is defined inside `outerFunction` and is used to add the two input parameters `a` and `b`.
- The `outerFunction` calls `innerFunction` and returns the result.
- The `innerFunction` is only accessible within `outerFunction`.

### Example 2: Nested Functions with Closures

One of the key features of nested functions in Scala is that they can access the variables and parameters of their outer function, which is known as a **closure**. This means the inner function can "capture" the environment of the outer function and access its values even after the outer function finishes execution.

```scala
def outerFunction(x: Int): Int => Int = {
  def innerFunction(y: Int): Int = {
    x + y  // 'x' is from the outer scope
  }
  
  innerFunction  // Return the inner function
}

// Example usage:
val addFive = outerFunction(5)  // 'addFive' is now a function that adds 5 to its argument
println(addFive(10))  // Output: 15
```

### Explanation:
- The `outerFunction` takes an `Int` parameter `x` and returns the inner function `innerFunction`.
- The inner function `innerFunction` uses the value of `x` from the outer function's scope.
- When `outerFunction(5)` is called, it returns the `innerFunction` with the captured value of `x = 5`.
- Calling `addFive(10)` results in `15` because the inner function adds `5` (the value captured from the outer function) to `10`.

### Example 3: Nested Recursive Function

You can define a recursive function within another function. For example, a factorial function can be implemented using nested recursion.

```scala
def factorial(n: Int): Int = {
  def recFactorial(x: Int): Int = {
    if (x == 0) 1
    else x * recFactorial(x - 1)
  }
  
  recFactorial(n)  // Call the nested recursive function
}

// Example usage:
println(factorial(5))  // Output: 120
```

### Explanation:
- `recFactorial` is defined inside the `factorial` function and is used to calculate the factorial recursively.
- The recursion is encapsulated within the `factorial` function, and `recFactorial` is only accessible within `factorial`.
- The result is computed by calling the nested `recFactorial` function with `n`.

### Example 4: Passing Functions to Nested Functions

You can also pass functions as arguments to nested functions. Here’s an example where a nested function accepts another function as a parameter.

```scala
def applyOperation(a: Int, b: Int, operation: (Int, Int) => Int): Int = {
  def innerFunction(): Int = operation(a, b)
  
  innerFunction()  // Call the nested function that uses the passed function
}

// Example usage:
val sum = (x: Int, y: Int) => x + y
val result = applyOperation(5, 3, sum)  // Output: 8
println(result)
```

### Explanation:
- The `applyOperation` function accepts two integers `a` and `b` and a function `operation` that takes two `Int` values and returns an `Int`.
- The `innerFunction` is a nested function that calls the passed `operation` function with `a` and `b` as arguments.
- The result is computed by invoking the nested `innerFunction`, which calls the passed `sum` function.

### Example 5: Using Nested Functions for Functional Composition

Nested functions can also be used to implement function composition, where one function is applied to the result of another function.

```scala
def composeFunctions(): Int => Int = {
  def addTwo(x: Int): Int = x + 2
  def multiplyByThree(x: Int): Int = x * 3
  
  def composedFunction(x: Int): Int = multiplyByThree(addTwo(x))
  
  composedFunction  // Return the composed function
}

// Example usage:
val func = composeFunctions()
println(func(5))  // Output: 21 (5 + 2 = 7, 7 * 3 = 21)
```

### Explanation:
- The `composeFunctions` function defines two nested functions, `addTwo` and `multiplyByThree`.
- The `composedFunction` calls `addTwo` first, and then passes the result to `multiplyByThree`.
- The composed function is returned, and calling `func(5)` results in `21`.

### Advantages of Nested Functions:

1. **Encapsulation**: Nested functions allow you to define helper functions that are only relevant within the scope of the outer function. This keeps the code cleaner and more organized.
2. **Closures**: Nested functions can "capture" values from their enclosing scope, which allows you to use external variables without having to pass them explicitly.
3. **Modularity**: Breaking down functionality into smaller, nested functions can make the code more modular and easier to understand.

### Conclusion:

Nested functions in Scala are a powerful feature that allows you to define functions within functions, creating a more modular and encapsulated code structure. These functions can access the outer function’s variables, creating closures, and can also be used for recursion or functional composition. By using nested functions, you can write more compact and flexible code that better reflects the logical structure of your program.
