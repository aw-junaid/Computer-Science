In Rust, you can associate names to values using variables, constants, and data structures like structs and enums. Here's how you can do it:

1. **Variables**:

Variables allow you to associate a name with a mutable or immutable value. Mutable variables can be changed after they're initially assigned, while immutable variables cannot.

```rust
fn main() {
    let age: i32 = 30;  // Immutable variable
    let mut count = 0;  // Mutable variable

    count = count + 1;

    println!("Age: {}", age);
    println!("Count: {}", count);
}
```

2. **Constants**:

Constants are values that are known at compile time and cannot be changed. They are declared using the `const` keyword and must have a type annotation.

```rust
const MAX_ATTEMPTS: u32 = 3;

fn main() {
    println!("Max attempts: {}", MAX_ATTEMPTS);
}
```

3. **Structs**:

Structs allow you to create custom data types by grouping together values of different types under a single name.

```rust
struct Person {
    name: String,
    age: i32,
}

fn main() {
    let person = Person {
        name: "Alice".to_string(),
        age: 25,
    };

    println!("Name: {}", person.name);
    println!("Age: {}", person.age);
}
```

4. **Enums**:

Enums define a type by enumerating its possible values. Each value can have associated data. Enums are useful when you have a fixed set of related values.

```rust
enum Direction {
    North,
    South,
    East,
    West,
}

fn main() {
    let my_direction = Direction::North;

    match my_direction {
        Direction::North => println!("Heading north"),
        Direction::South => println!("Heading south"),
        Direction::East => println!("Heading east"),
        Direction::West => println!("Heading west"),
    }
}
```

5. **Tuple Structs**:

Tuple structs are similar to regular structs, but they don't have named fields; instead, they have anonymous fields of specific types.

```rust
struct Point(i32, i32);

fn main() {
    let p = Point(3, 5);

    println!("X: {}", p.0);
    println!("Y: {}", p.1);
}
```

These are just a few examples of how you can associate names with values in Rust. Each approach has its own use cases and advantages. Depending on your program's requirements, you can choose the most suitable method for representing and working with your data.
