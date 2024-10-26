Structs (short for "structures") are one of the fundamental custom data types in Rust. They allow you to create your own composite types by grouping together values of different types under a single name. Structs are used to define custom data structures that represent real-world entities, objects, or concepts in your code.

Here's how you can define and use structs in Rust:

```rust
// Define a struct named 'Person'
struct Person {
    name: String,
    age: u32,
}

fn main() {
    // Create an instance of the 'Person' struct
    let person1 = Person {
        name: String::from("Alice"),
        age: 30,
    };

    // Access struct fields using dot notation
    println!("Name: {}", person1.name);
    println!("Age: {}", person1.age);
}
```

In this example, we define a struct named `Person` with two fields: `name` of type `String` and `age` of type `u32`. We then create an instance of the `Person` struct and access its fields using dot notation.

Structs can also have methods associated with them:

```rust
struct Rectangle {
    width: f64,
    height: f64,
}

impl Rectangle {
    // Method to calculate the area of the rectangle
    fn area(&self) -> f64 {
        self.width * self.height
    }
}

fn main() {
    let rectangle = Rectangle {
        width: 10.0,
        height: 5.0,
    };

    println!("Rectangle area: {}", rectangle.area());
}
```

In this example, we define a struct named `Rectangle` and implement a method `area` for it. The method takes a reference to `self` (the instance of the struct) and calculates the area using the `width` and `height` fields.

You can also use the "field init shorthand" to create instances of structs and initialize fields based on variables with the same name:

```rust
let name = String::from("Bob");
let age = 25;

let person2 = Person { name, age };
```

Structs in Rust provide a powerful way to define custom data types that match the needs of your application. They allow you to group related data together and define behavior through methods, contributing to the organization and clarity of your code.
