Rust provides a variety of arithmetic operations that you can perform on numeric data types. Here are some common arithmetic operations you can perform in Rust:

```rust
fn main() {
    let num1 = 10;
    let num2 = 3;

    // Addition
    let sum = num1 + num2;
    println!("Sum: {}", sum);

    // Subtraction
    let difference = num1 - num2;
    println!("Difference: {}", difference);

    // Multiplication
    let product = num1 * num2;
    println!("Product: {}", product);

    // Division
    let quotient = num1 / num2;
    println!("Quotient: {}", quotient);

    // Remainder (Modulo)
    let remainder = num1 % num2;
    println!("Remainder: {}", remainder);

    // Floating-Point Operations
    let float_num1 = 10.5;
    let float_num2 = 2.0;

    let float_sum = float_num1 + float_num2;
    println!("Floating-Point Sum: {}", float_sum);

    // Power (using the pow method from the `num_traits` crate)
    // To use this, add `num-traits = "0.2"` to your Cargo.toml dependencies.
    // Note: The num_traits crate is not part of the Rust standard library.
    // You need to include it as a dependency in your project.
    // use num_traits::pow;
    // let power = pow(num1, num2 as u32);
    // println!("Power: {}", power);
}
```

Keep in mind that the operations you can perform may vary depending on the numeric data types you're working with. For example, integer division (using `/`) truncates the result towards zero, and division by zero will result in a panic at runtime. To perform division that produces a floating-point result, you need to use floating-point numbers.

For exponentiation (raising a number to a power), Rust's standard library doesn't provide an exponentiation operator. If you need to perform exponentiation, you can use the `pow` method from the `num_traits` crate. To use this method, you'll need to add `num-traits = "0.2"` to your `Cargo.toml` dependencies and import the necessary trait and function. Note that the `num_traits` crate is not part of the Rust standard library, so you need to include it as a dependency in your project.

In your actual code, you might use different numeric types and values, but the basic arithmetic operations remain the same.
