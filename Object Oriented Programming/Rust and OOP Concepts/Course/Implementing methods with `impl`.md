In Rust, methods associated with a struct are defined within an `impl` (short for **implementation**) block. This is where you can add functionality to your custom data types, such as constructors, instance methods, and associated functions. Here's a detailed guide to implementing methods with `impl`:

---

### **1. What is an `impl` Block?**
An `impl` block allows you to associate functions with a struct, enabling the struct to have behaviors (methods) along with its data (fields). 

- **Instance Methods**: Operate on a specific instance of the struct.
- **Associated Functions**: Do not operate on an instance of the struct (e.g., constructors like `new`).

---

### **2. Adding Methods to a Struct**
#### Example: Basic `impl` Block
```rust
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    // Instance method
    fn area(&self) -> u32 {
        self.width * self.height
    }

    // Associated function
    fn new(width: u32, height: u32) -> Self {
        Self { width, height }
    }
}

fn main() {
    let rect = Rectangle::new(30, 50);
    println!("Area: {}", rect.area());
}
```

---

### **3. Key Features of Methods**
#### a. **The `self` Parameter**
- Instance methods must include a parameter called `self`, which represents the current instance.
- Variants:
  - `&self`: Borrow the instance immutably.
  - `&mut self`: Borrow the instance mutably.
  - `self`: Take ownership of the instance.

#### Examples:
```rust
impl Rectangle {
    // Immutable borrow
    fn width(&self) -> u32 {
        self.width
    }

    // Mutable borrow
    fn scale(&mut self, factor: u32) {
        self.width *= factor;
        self.height *= factor;
    }

    // Ownership
    fn destroy(self) {
        println!("Rectangle destroyed: {}x{}", self.width, self.height);
        // Ownership is taken, so `self` cannot be used afterward.
    }
}

fn main() {
    let mut rect = Rectangle::new(10, 20);

    println!("Width: {}", rect.width()); // Immutable borrow
    rect.scale(2); // Mutable borrow
    rect.destroy(); // Ownership
}
```

---

#### b. **Associated Functions**
Associated functions do not require `self` and are called on the type itself, not an instance. These are often used as constructors.

#### Example:
```rust
impl Rectangle {
    fn square(size: u32) -> Self {
        Self {
            width: size,
            height: size,
        }
    }
}

fn main() {
    let square = Rectangle::square(20);
    println!("Square area: {}", square.area());
}
```

---

### **4. Using Multiple `impl` Blocks**
You can define multiple `impl` blocks for the same struct. This can be useful for organizing code.

#### Example:
```rust
impl Rectangle {
    fn perimeter(&self) -> u32 {
        2 * (self.width + self.height)
    }
}

impl Rectangle {
    fn diagonal(&self) -> f64 {
        ((self.width.pow(2) + self.height.pow(2)) as f64).sqrt()
    }
}

fn main() {
    let rect = Rectangle::new(3, 4);
    println!("Perimeter: {}", rect.perimeter());
    println!("Diagonal: {:.2}", rect.diagonal());
}
```

---

### **5. Method Chaining**
Methods that return `self` or a reference to `self` can be chained together for clean and expressive code.

#### Example:
```rust
impl Rectangle {
    fn set_width(&mut self, width: u32) -> &mut Self {
        self.width = width;
        self
    }

    fn set_height(&mut self, height: u32) -> &mut Self {
        self.height = height;
        self
    }
}

fn main() {
    let mut rect = Rectangle::new(10, 20);

    rect.set_width(15).set_height(25);
    println!("Updated Rectangle: {}x{}", rect.width, rect.height);
}
```

---

### **6. Example: Full Implementation**
```rust
struct Circle {
    radius: f64,
}

impl Circle {
    // Associated function (constructor)
    fn new(radius: f64) -> Self {
        Self { radius }
    }

    // Instance method
    fn area(&self) -> f64 {
        3.14159 * self.radius * self.radius
    }

    // Instance method with mutable borrow
    fn grow(&mut self, scale: f64) {
        self.radius *= scale;
    }

    // Instance method with ownership
    fn destroy(self) {
        println!("Circle with radius {} is destroyed.", self.radius);
    }
}

fn main() {
    let mut circle = Circle::new(5.0);
    println!("Area: {:.2}", circle.area());
    circle.grow(2.0);
    println!("New area: {:.2}", circle.area());
    circle.destroy();
}
```

---

### **7. Benefits of `impl`**
- **Encapsulation**: Combines data (struct) and behavior (methods).
- **Reusability**: Easily extendable with additional functionality.
- **Organization**: Keeps related code together, improving readability.

By using `impl` blocks, Rust allows you to define methods for structs in a clean and modular way while maintaining full control over ownership, borrowing, and safety.
