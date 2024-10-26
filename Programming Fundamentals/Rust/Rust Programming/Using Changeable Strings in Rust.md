In Rust, strings are represented using the `String` type, which provides dynamic and changeable string storage. Unlike string literals, which are statically allocated and have a fixed size, `String` objects can grow and shrink as needed. Rust's ownership and borrowing system ensures that string manipulation is done safely and efficiently.

Here's how you can use changeable strings in Rust:

```rust
fn main() {
    // Create an empty String
    let mut my_string = String::new();

    // Append characters to the String
    my_string.push('H');
    my_string.push_str("ello, ");

    // Concatenate strings
    let name = "Alice";
    my_string.push_str(name);

    println!("{}", my_string);

    // Modify the String
    my_string.push('!');
    println!("{}", my_string);

    // Replace part of the String
    my_string.replace_range(7..12, "Bob");
    println!("{}", my_string);
}
```

In this example, we first create an empty `String` using `String::new()`. We then use methods like `push`, `push_str`, and `replace_range` to modify the string. The `mut` keyword before `my_string` indicates that the variable is mutable, allowing us to change its contents.

Here are some common methods you can use to manipulate `String` objects:

- `push(char)` and `push_str(&str)`: Append characters or strings to the `String`.
- `replace_range(range, &str)`: Replace a range of characters with a new string.
- `remove(index)`: Remove a character at a specific index.
- `insert(index, char)` and `insert_str(index, &str)`: Insert characters or strings at a specific index.
- `truncate(len)`: Shorten the `String` to a specified length.
- `clear()`: Remove all characters from the `String`.

Remember that `String` objects in Rust follow Rust's ownership and borrowing rules. For more advanced string manipulation and formatting, you can also use the `format!` macro and other formatting traits provided by Rust's standard library.
