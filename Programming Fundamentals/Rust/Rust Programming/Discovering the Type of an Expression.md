In Rust, you can use the `std::any::type_name` function from the standard library to discover the type of an expression at runtime. This function returns a string representation of the type's name. However, please note that the exact output might vary depending on the compiler and optimizations being used.

Here's how you can use `type_name` to discover the type of an expression:

```rust
use std::any::type_name;

fn main() {
    let x = 42;
    let type_of_x = type_name::<typeof(x)>();
    println!("Type of x: {}", type_of_x);
}
```

In this example, we import the `type_name` function from the `std::any` module. We then use the `typeof` keyword to get the type of the expression `x`, and we pass that type as a type argument to the `type_name` function.

Keep in mind that `type_name` provides a human-readable name for the type, but it might not be suitable for pattern matching or programmatic type checking due to potential variations in its output. It's mainly useful for debugging and diagnostic purposes.

For more advanced type introspection and pattern matching based on types, you might want to explore Rust's built-in reflection capabilities, macros, or consider using third-party libraries that provide more powerful type-related functionality.
