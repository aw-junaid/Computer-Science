To print integer numbers in Rust, you can use the `println!` macro along with the format specifiers. Here are some examples:

1. **Printing a Single Integer**:

```rust
fn main() {
    let num = 42;
    println!("Number: {}", num);
}
```

2. **Printing Multiple Integers**:

```rust
fn main() {
    let num1 = 42;
    let num2 = -17;
    println!("Numbers: {} and {}", num1, num2);
}
```

3. **Formatting Integers**:

You can format integers using various specifiers. For example:

- `{}`: Default formatting
- `{:.2}`: Format with two decimal places (for integers, this affects the width)
- `{:05}`: Format with a minimum width of 5 digits, padding with zeros if necessary

```rust
fn main() {
    let num = 42;
    println!("Decimal: {}", num);
    println!("Decimal with Width: {:05}", num);
    println!("Decimal with Decimals: {:.2}", num);
}
```

4. **Printing Binary, Octal, and Hexadecimal**:

You can use the `{:b}` format specifier to print in binary, `{:o}` for octal, and `{:x}` (or `{:X}` for uppercase) for hexadecimal:

```rust
fn main() {
    let num = 42;
    println!("Binary: {:b}", num);
    println!("Octal: {:o}", num);
    println!("Hexadecimal: {:x}", num);
}
```

Remember, the examples above assume you're working with signed integers. If you're working with unsigned integers, you can use the `u` prefix for format specifiers (e.g., `{:u}`, `{:x}`, etc.).

Feel free to mix and match these techniques to achieve the desired formatting for your integer values. Rust's formatting capabilities are quite powerful and flexible.
