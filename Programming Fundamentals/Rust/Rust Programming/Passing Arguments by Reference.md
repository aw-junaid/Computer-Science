In Rust, passing arguments by reference allows you to avoid making unnecessary copies of data and instead lets you work directly with the original data. References are a fundamental concept in Rust and are used to provide safe and efficient access to data without transferring ownership.

Here's how you can pass arguments by reference using references or borrowing:

```rust
// Define a function that takes an 'i32' reference
fn modify_value(x: &mut i32) {
    *x *= 2; // Modify the value through the reference
}

fn main() {
    let mut number = 5;

    // Pass 'number' by reference to 'modify_value'
    modify_value(&mut number);

    println!("Modified number: {}", number);
}
```

In this example, the `modify_value` function takes an `i32` mutable reference `x`. The `&mut` syntax indicates that you're passing a mutable reference. Inside the function, you use the `*` operator to dereference the reference and modify the value.

You can also pass immutable references:

```rust
// Define a function that takes an 'i32' immutable reference
fn print_value(x: &i32) {
    println!("Value: {}", x);
}

fn main() {
    let number = 42;

    // Pass 'number' by reference to 'print_value'
    print_value(&number);
}
```

In this example, the `print_value` function takes an `i32` immutable reference. Since the reference is immutable, you cannot modify the value within the function.

Passing arguments by reference is useful when you want to avoid copying large data structures or when you want to modify the original data within a function. Rust's borrowing system ensures that references are used safely and that there are no data races or undefined behavior.
