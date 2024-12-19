In Scala, you can define **default parameter values** for function parameters. This allows you to call a function without providing arguments for all parameters. If an argument is omitted, the function will use the default value specified in the function definition.

### Syntax for Default Parameter Values

```scala
def functionName(param1: Type = defaultValue1, param2: Type = defaultValue2, ...): ReturnType = {
  // function body
}
```

### Example of a Function with Default Parameter Values

Let's define a function `greet` that takes two parameters: a `name` and a `greeting`. We'll provide a default value for the `greeting` parameter.

#### Example:
```scala
def greet(name: String, greeting: String = "Hello"): String = {
  s"$greeting, $name!"
}

println(greet("Alice"))           // Output: Hello, Alice!
println(greet("Bob", "Hi"))       // Output: Hi, Bob!
```

### Explanation:
- The `greeting` parameter has a default value of `"Hello"`. This means if the caller does not provide a value for `greeting`, the function will use `"Hello"` by default.
- The `name` parameter does not have a default value, so it must be provided by the caller.
- In the first call, `greet("Alice")`, only the `name` is provided, so `"Hello"` is used for `greeting`.
- In the second call, `greet("Bob", "Hi")`, both `name` and `greeting` are provided, so `"Hi"` is used as the greeting.

### Default Parameters with Multiple Parameters

You can provide default values for multiple parameters, and the caller can choose to specify values for some or all of them.

#### Example:
```scala
def orderItem(product: String, quantity: Int = 1, price: Double = 10.0): String = {
  s"Ordered $quantity $product(s) at $$price each."
}

println(orderItem("Book"))                 // Output: Ordered 1 Book(s) at $10.0 each.
println(orderItem("Pen", 5))               // Output: Ordered 5 Pen(s) at $10.0 each.
println(orderItem("Laptop", 2, 1200.50))   // Output: Ordered 2 Laptop(s) at $1200.5 each.
```

### Explanation:
- `quantity` has a default value of `1`, and `price` has a default value of `10.0`.
- In the first call, only the `product` is specified, so the function uses the default values for `quantity` and `price`.
- In the second call, the `quantity` is overridden, but the default `price` is used.
- In the third call, both `quantity` and `price` are provided, overriding the defaults.

### Named Arguments with Default Parameters

When you define functions with default parameter values, you can also use **named arguments** to make your function calls more readable and specify which argument to use for each parameter.

#### Example:
```scala
def createUser(username: String, email: String = "example@example.com", active: Boolean = true): String = {
  s"User $username with email $email is active: $active"
}

println(createUser("john_doe"))  // Output: User john_doe with email example@example.com is active: true
println(createUser("alice", active = false))  // Output: User alice with email example@example.com is active: false
```

### Explanation:
- The default values for `email` and `active` are used unless they are explicitly provided using named arguments.
- In the second call, only `username` is required, but `active` is explicitly set to `false` using the named argument.

### Default Parameters in Overloaded Functions

Default parameter values can also be used to create overloaded functions without explicitly defining multiple versions of the same function. Scala will automatically resolve which version of the function to call based on the arguments provided.

#### Example:
```scala
def printMessage(message: String, times: Int = 1): Unit = {
  for (_ <- 1 to times) {
    println(message)
  }
}

printMessage("Hello")        // Output: Hello
printMessage("Hello", 3)     // Output: Hello (printed 3 times)
```

### Explanation:
- The function `printMessage` can print the message once by default, but you can also specify how many times to print it by passing a value for the `times` parameter.

### Key Points:
1. **Default values for parameters** allow the function to be more flexible by making some parameters optional.
2. **Named arguments** can be used to specify default arguments when calling the function.
3. **Multiple default parameters** can be used in a function, allowing for easy overloading without explicitly defining multiple methods.
4. Default parameters must be provided from right to left (i.e., the parameters with default values must come last).

### Conclusion:

Default parameter values in Scala provide a way to write more concise and flexible functions. They reduce the need for multiple overloaded function definitions and allow you to specify only the parameters that need to be changed, while keeping others at their default values.
