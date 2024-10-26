To print several lines of text in Rust, you can use the `println!` macro multiple times, each time printing a different line. Alternatively, you can use a single `print!` or `println!` call with a multi-line string (a string with line breaks embedded in it).

Here are examples of both approaches:

1. **Using Multiple `println!` Calls**:

```rust
fn main() {
    println!("Line 1");
    println!("Line 2");
    println!("Line 3");
}
```

Each `println!` call generates a new line of output.

2. **Using a Multi-line String with `println!`**:

```rust
fn main() {
    let multi_line_text = "Line 1
Line 2
Line 3";

    println!("{}", multi_line_text);
}
```

In this example, the `multi_line_text` variable contains a multi-line string with embedded line breaks (`\n`). When you use `println!` with the variable, the entire text will be printed with line breaks preserved.

Remember that Rust allows you to use raw string literals (denoted by `r#`) to simplify embedding special characters like backslashes. For example:

```rust
fn main() {
    let multi_line_text = r#"Line 1
Line 2
Line 3"#;

    println!("{}", multi_line_text);
}
```

Both approaches achieve the same result. Choose the one that best suits your needs and improves the readability of your code.
