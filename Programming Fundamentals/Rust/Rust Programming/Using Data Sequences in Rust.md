In Rust, data sequences are typically represented using collections. Rust provides a variety of collection types that you can use to store and manipulate sequences of data. Here are some of the common collection types and how to use them:

1. **Arrays**:

Arrays have a fixed size at compile time and hold elements of the same type. They are stored on the stack.

```rust
fn main() {
    let numbers: [i32; 5] = [1, 2, 3, 4, 5];
    println!("First element: {}", numbers[0]); // Accessing array elements
}
```

2. **Vectors**:

Vectors are similar to arrays but have a dynamic size that can change at runtime. They are stored on the heap.

```rust
fn main() {
    let mut fruits = Vec::new(); // Creating an empty vector

    fruits.push("apple");
    fruits.push("banana");
    fruits.push("cherry");

    println!("Fruits: {:?}", fruits); // Printing the vector
}
```

3. **Slices**:

Slices allow you to reference a portion of an array or vector without copying the data.

```rust
fn main() {
    let numbers = [1, 2, 3, 4, 5];
    let slice = &numbers[1..4]; // Slice from index 1 to 3 (inclusive)

    println!("Slice: {:?}", slice);
}
```

4. **Strings**:

Rust's `String` type is used to store text data in a flexible and resizable way.

```rust
fn main() {
    let greeting = String::from("Hello, world!");

    println!("Greeting: {}", greeting);
}
```

5. **HashMaps**:

HashMaps store key-value pairs, allowing you to associate values with unique keys.

```rust
use std::collections::HashMap;

fn main() {
    let mut scores = HashMap::new();

    scores.insert("Alice", 100);
    scores.insert("Bob", 85);
    scores.insert("Charlie", 90);

    println!("Alice's score: {:?}", scores.get("Alice"));
}
```

6. **Iterating Over Sequences**:

You can use loops and iterators to iterate over elements in a collection.

```rust
fn main() {
    let numbers = [1, 2, 3, 4, 5];

    for num in &numbers {
        println!("Number: {}", num);
    }

    let fruits = vec!["apple", "banana", "cherry"];

    for fruit in &fruits {
        println!("Fruit: {}", fruit);
    }
}
```

These are just a few examples of the collection types available in Rust. Each collection type has its own use cases and advantages, and you can choose the appropriate one based on your program's requirements. Rust's ownership system ensures that collections are managed safely and efficiently, without causing memory leaks or data races.
