### Scala - Closures

A **closure** in Scala (and other programming languages) refers to a function or lambda that captures and retains access to variables from its surrounding scope, even after the scope in which they were defined has finished executing. In simpler terms, a closure is a function that can "remember" and use variables from the environment in which it was created.

Closures allow a function to "close over" its environment, i.e., it can access variables that are not passed explicitly as parameters but are available in the surrounding scope.

### Key Characteristics of Closures
- **Function with External Variables**: A closure is a function that uses variables declared outside its scope.
- **Retention of Variable Values**: Even if the function is passed around and invoked outside its original scope, it retains access to those variables.
- **Enclosing Scope**: Closures have access to the variables in their enclosing scope at the time of their creation.

### Example of a Closure in Scala

In the following example, the function `makeMultiplier` returns a function that multiplies its argument by a factor defined outside the function.

```scala
def makeMultiplier(factor: Int) = {
  // This function is a closure because it uses the `factor` variable from the enclosing scope.
  (x: Int) => x * factor
}

val multiplyBy2 = makeMultiplier(2)
val multiplyBy3 = makeMultiplier(3)

println(multiplyBy2(5))  // Output: 10
println(multiplyBy3(5))  // Output: 15
```

In this example:
- The `makeMultiplier` function returns another function that captures the value of `factor` from the surrounding scope.
- The function `multiplyBy2` captures the value `2` from the scope when `makeMultiplier(2)` is called, and it uses that value when invoked.
- Similarly, `multiplyBy3` captures the value `3`.

### How Closures Work

In the example above, when the `multiplyBy2` and `multiplyBy3` functions are created, they both remember the value of `factor` from their respective environments.

1. `multiplyBy2` "closes over" the `factor` variable and remembers it as `2`.
2. `multiplyBy3` "closes over" the `factor` variable and remembers it as `3`.
3. Even after the `makeMultiplier` function has finished executing, both `multiplyBy2` and `multiplyBy3` still have access to their respective `factor` values.

### Closures with Mutable Variables

Closures can also capture mutable variables. Here's an example that demonstrates how closures behave with mutable state:

```scala
def counter(increment: Int) = {
  var count = 0
  // Closure that updates the `count` variable.
  () => {
    count += increment
    count
  }
}

val counterBy2 = counter(2)
println(counterBy2())  // Output: 2
println(counterBy2())  // Output: 4

val counterBy3 = counter(3)
println(counterBy3())  // Output: 3
println(counterBy3())  // Output: 6
```

In this case:
- The `counter` function returns a closure that remembers the `count` variable.
- The returned function (closure) increments and returns the `count` every time it is called.
- Even though `count` is defined inside the `counter` function, it is captured and remembered by the closures `counterBy2` and `counterBy3`.

### Closures and Lexical Scoping

The power of closures comes from the fact that they capture variables from the **lexical scope** (the scope in which they were defined), not from the scope in which they are called.

This means that a closure can access variables even if those variables are no longer in scope when the closure is invoked. The closure "remembers" the environment in which it was created.

```scala
val x = 10

val closure = (y: Int) => {
  println(x + y)  // `x` is captured from the surrounding scope
}

val result = closure(5)  // Output: 15
```

Here, the closure captures the value of `x` from the surrounding scope when it is created, even though the scope of `x` no longer exists when the closure is invoked.

### Advantages of Using Closures

1. **Encapsulation**: Closures allow for encapsulating state within functions. For example, in the counter example, the `count` variable is kept private to each closure, which can modify it without exposing it to other parts of the program.
2. **Functional Programming**: Closures are common in functional programming paradigms because they allow functions to retain state and create more flexible and reusable code.
3. **Deferred Execution**: Closures can be passed around as objects and invoked later, potentially with access to the environment in which they were created.

### Example: Closures in Event Handling

In event-driven programming (such as GUI programming or callbacks), closures are used to handle events and retain the state of the environment when the event occurs.

```scala
var state = "Initial State"

val eventHandler = () => {
  println(s"Event triggered! State is: $state")
  state = "State changed"
}

eventHandler()  // Output: Event triggered! State is: Initial State
eventHandler()  // Output: Event triggered! State is: State changed
```

Here, the closure retains access to the variable `state`, which allows it to update and print the state across multiple invocations.

### Conclusion

- **Closures** in Scala are functions that capture variables from their surrounding scope and retain access to them after the scope has finished executing.
- Closures allow functions to "remember" the environment they were created in and can access and modify variables even after the original scope is gone.
- They are useful for creating functions with encapsulated state, such as counters or event handlers, and are a powerful feature in functional programming.

Closures provide a mechanism for functions to retain and operate on their environment, making them an essential tool for many functional programming tasks and techniques in Scala.
