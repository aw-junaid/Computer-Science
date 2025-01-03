Structs in Rust are a core feature for defining and organizing custom data types. They enable you to group related data into a single entity, making your programs more modular and readable. Here's a detailed guide to defining and using structs in Rust:

---

### **1. What is a Struct?**
A **struct** is a custom data type that allows you to package together multiple related values. Structs are similar to objects in OOP but do not inherently include methods or behaviors (these are defined separately using `impl` blocks).

---

### **2. Types of Structs**
Rust provides three main types of structs:
- **Named Structs**: Each field has a name.
- **Tuple Structs**: Fields are unnamed, but have a fixed order and type.
- **Unit Structs**: Structs with no fields, useful for marker types.

---

### **3. Defining Structs**
#### a. Named Struct
```rust
struct Person {
    name: String,
    age: u32,
    is_student: bool,
}
```

#### b. Tuple Struct
```rust
struct Point(f64, f64, f64);
```

#### c. Unit Struct
```rust
struct Marker;
```

---

### **4. Creating Instances**
You can create instances of a struct using its name and specifying the values for its fields.

#### Example: Named Struct
```rust
let person = Person {
    name: String::from("Alice"),
    age: 30,
    is_student: false,
};
```

#### Example: Tuple Struct
```rust
let origin = Point(0.0, 0.0, 0.0);
```

#### Example: Unit Struct
```rust
let marker = Marker;
```

---

### **5. Accessing and Modifying Fields**
Fields of a struct can be accessed using dot notation.

#### Example:
```rust
println!("Name: {}", person.name);
println!("Age: {}", person.age);
```

For mutable structs, you can modify fields:
```rust
let mut person = Person {
    name: String::from("Alice"),
    age: 30,
    is_student: false,
};

person.age += 1;
println!("Updated Age: {}", person.age);
```

---

### **6. Using Structs with Functions**
You can pass structs as arguments to functions or return them from functions.

#### Example:
```rust
fn print_person(person: &Person) {
    println!("{} is {} years old.", person.name, person.age);
}

fn main() {
    let person = Person {
        name: String::from("Bob"),
        age: 25,
        is_student: true,
    };
    print_person(&person);
}
```

---

### **7. Struct Update Syntax**
You can create a new struct instance using an existing one as a template.

#### Example:
```rust
let person2 = Person {
    name: String::from("Charlie"),
    ..person
};
```

---

### **8. Adding Methods with `impl`**
You can add methods to a struct by implementing an `impl` block.

#### Example:
```rust
impl Person {
    fn greet(&self) {
        println!("Hello, my name is {}.", self.name);
    }

    fn is_adult(&self) -> bool {
        self.age >= 18
    }
}

fn main() {
    let person = Person {
        name: String::from("Dana"),
        age: 20,
        is_student: true,
    };
    
    person.greet();
    println!("Is adult: {}", person.is_adult());
}
```

---

### **9. Structs and Ownership**
Rust enforces ownership rules with structs:
- Struct fields follow the same ownership rules as any other data type.
- Borrowing and lifetimes can be applied to structs to ensure safety.

#### Example:
```rust
fn display_name(person: &Person) {
    println!("Name: {}", person.name);
}

fn main() {
    let person = Person {
        name: String::from("Eva"),
        age: 22,
        is_student: false,
    };

    display_name(&person);
    // Ownership of `person` is not taken, so it's still valid here.
}
```

---

### **10. Example: Complete Program**
Here’s a complete program to illustrate defining and using structs:

```rust
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }

    fn is_square(&self) -> bool {
        self.width == self.height
    }
}

fn main() {
    let rect = Rectangle {
        width: 30,
        height: 50,
    };

    println!("Area: {}", rect.area());
    println!("Is square: {}", rect.is_square());
}
```

---

### **Key Features of Rust Structs**
- **Encapsulation**: Fields are private by default; use `pub` to make them public.
- **Method Implementation**: Use `impl` blocks for functionality.
- **Ownership Rules**: Structs integrate seamlessly with Rust's ownership, borrowing, and lifetimes.
- **Efficient Memory Management**: Structs are stack-allocated by default, ensuring performance.

Structs are fundamental to building complex data types and systems in Rust, offering both flexibility and safety.
