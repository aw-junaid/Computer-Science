In Rust, you can define generic functions and structs that work with multiple types. Generics allow you to write code that is flexible and reusable across different data types while maintaining strong type safety.

Here's how you can define generic functions and structs in Rust:

**Generic Functions**:

```rust
// Define a generic function that swaps two values of any type
fn swap<T>(a: T, b: T) -> (T, T) {
    (b, a)
}

fn main() {
    let x = 5;
    let y = 10;

    let (x, y) = swap(x, y);
    println!("x: {}, y: {}", x, y);

    let a = "Hello";
    let b = "World";

    let (a, b) = swap(a, b);
    println!("a: {}, b: {}", a, b);
}
```

In this example, the `swap` function is generic, indicated by the `<T>` after the function name. The `T` is a type parameter that represents any type. You can call the `swap` function with different types, such as integers and strings, and it will work for both.

**Generic Structs**:

```rust
// Define a generic struct named 'Pair' that holds two values of any type
struct Pair<T, U> {
    first: T,
    second: U,
}

fn main() {
    let pair1 = Pair {
        first: 42,
        second: "hello",
    };

    let pair2 = Pair {
        first: 3.14,
        second: true,
    };

    println!("Pair 1: {} - {}", pair1.first, pair1.second);
    println!("Pair 2: {} - {}", pair2.first, pair2.second);
}
```

In this example, we define a generic struct named `Pair` with two type parameters, `T` and `U`. This struct can hold two values of potentially different types. You can create instances of the `Pair` struct with various types for its fields.

Generics allow you to write more flexible and reusable code by abstracting over different data types. They are a powerful tool in Rust's type system that enables you to create versatile functions and data structures.
