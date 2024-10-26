In Rust, you can define and invoke functions to encapsulate blocks of code that perform specific tasks. Functions are an essential building block of Rust programs, helping you organize and modularize your code.

Here's how you can define and invoke a function in Rust:

```rust
// Define a function named 'greet' that takes a 'name' parameter
fn greet(name: &str) {
    println!("Hello, {}!", name);
}

fn main() {
    // Invoke the 'greet' function
    greet("Alice");
    greet("Bob");
}
```

In this example, we define a function named `greet` that takes a parameter `name` of type `&str` (a string slice). Inside the function, we use the `println!` macro to print a greeting message using the provided name.

To invoke a function, simply provide the required arguments within parentheses and separate them by commas.

Function parameters can have different types, and functions can also return values:

```rust
// Define a function named 'add' that takes two 'i32' parameters and returns an 'i32'
fn add(a: i32, b: i32) -> i32 {
    a + b
}

fn main() {
    let result = add(10, 20);
    println!("Result: {}", result);
}
```

In this example, the `add` function takes two `i32` parameters and returns an `i32`. We call the `add` function and store the result in the `result` variable, which is then printed using the `println!` macro.

Rust also supports closures (anonymous functions) and function pointers for more advanced use cases.

Remember that function names should follow Rust's naming conventions (snake_case) and should be descriptive of the purpose of the function. Functions play a crucial role in breaking down code into smaller, manageable pieces, promoting code reuse and maintainability.
