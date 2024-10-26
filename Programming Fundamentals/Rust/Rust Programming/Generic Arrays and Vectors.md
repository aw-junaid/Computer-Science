In Rust, you can work with generic arrays and vectors using Rust's built-in array and vector types. Generics allow you to create arrays and vectors that can hold elements of any type. Arrays have a fixed size at compile time, while vectors are dynamically resizable.

**Generic Arrays**:

Arrays in Rust have a fixed size determined at compile time. To create a generic array, you can use a `[T; N]` syntax, where `T` represents the element type and `N` represents the array length.

Here's an example of a generic array:

```rust
fn main() {
    let numbers: [i32; 5] = [1, 2, 3, 4, 5];

    for num in &numbers {
        println!("{}", num);
    }
}
```

In this example, we create a generic array of type `i32` with a length of 5. You can access elements using indexing, such as `numbers[0]`.

**Generic Vectors**:

Vectors in Rust are dynamically resizable arrays. To create a generic vector, you can use the `Vec<T>` type.

Here's an example of a generic vector:

```rust
fn main() {
    let mut numbers: Vec<i32> = Vec::new();

    numbers.push(1);
    numbers.push(2);
    numbers.push(3);

    for num in &numbers {
        println!("{}", num);
    }
}
```

In this example, we create a generic vector of type `i32` and use the `push` method to add elements to it dynamically.

Generics allow you to create collections that work with different types, providing flexibility and code reusability. Both arrays and vectors can be used with generics to create data structures that fit your specific needs.
