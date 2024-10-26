Tuple structs in Rust are a hybrid between tuples and traditional structs. They allow you to define a custom type that has named fields similar to a struct, but the fields are accessed using positional indexing like a tuple. Tuple structs are useful when you want to create a new type that encapsulates a set of values without adding named field names.

Here's how you can define and use tuple structs in Rust:

```rust
// Define a tuple struct named 'Point' with two fields
struct Point(i32, i32);

fn main() {
    // Create an instance of the 'Point' tuple struct
    let origin = Point(0, 0);

    // Access fields using positional indexing
    println!("X-coordinate: {}", origin.0);
    println!("Y-coordinate: {}", origin.1);
}
```

In this example, we define a tuple struct named `Point` with two fields of type `i32`. We then create an instance of the `Point` tuple struct and access its fields using positional indexing (e.g., `origin.0` and `origin.1`).

You can also implement methods for tuple structs just like you would for regular structs:

```rust
struct Circle(f64);

impl Circle {
    // Method to calculate the area of the circle
    fn area(&self) -> f64 {
        3.14159 * self.0 * self.0
    }
}

fn main() {
    let radius = 5.0;
    let circle = Circle(radius);

    println!("Circle area: {}", circle.area());
}
```

In this example, we define a tuple struct named `Circle` with one field of type `f64`. We then implement a method `area` for the `Circle` tuple struct, which calculates the area of the circle using the field's value.

Tuple structs are particularly useful when you need to define lightweight types that bundle multiple values together but don't require named fields. They provide a convenient way to group data and functionality while keeping the code concise and readable.
