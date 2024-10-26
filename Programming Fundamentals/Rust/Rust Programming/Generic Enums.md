In Rust, you can define generic enums, also known as enum variants with associated data that have generic types. This allows you to create versatile enums that can hold different types of associated data for each variant.

Here's how you can define and use generic enums in Rust:

```rust
// Define a generic enum named 'Result' with two variants
enum Result<T, E> {
    Ok(T),
    Err(E),
}

fn main() {
    // Using the 'Result' enum with different types of associated data
    let success: Result<i32, &str> = Result::Ok(42);
    let failure: Result<i32, &str> = Result::Err("Error occurred");

    match success {
        Result::Ok(value) => println!("Success: {}", value),
        Result::Err(error) => println!("Error: {}", error),
    }

    match failure {
        Result::Ok(value) => println!("Success: {}", value),
        Result::Err(error) => println!("Error: {}", error),
    }
}
```

In this example, we define a generic enum named `Result` with two variants: `Ok` and `Err`. Each variant can hold associated data of different generic types. We then create instances of the `Result` enum with different types of associated data and use pattern matching to handle each variant accordingly.

Generic enums are particularly useful when you want to create flexible data structures that can represent different states or outcomes with associated data of varying types. They provide a way to create reusable and expressive code that adapts to different use cases.
