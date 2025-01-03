### **Using Getter and Setter Methods in Rust**

In Rust, **getter** and **setter** methods are used to control access to the fields of a struct. While Rust does not have the concept of public fields by default (fields are private by default), getter and setter methods allow you to encapsulate access to struct fields, ensuring that the internal state is properly controlled.

---

### **1. Getter Methods**

A **getter** method allows you to retrieve the value of a private field. It is typically implemented as a method with no parameters, returning the value of a field.

#### Example: Getter Method
```rust
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    // Getter method for `width`
    pub fn width(&self) -> u32 {
        self.width
    }

    // Getter method for `height`
    pub fn height(&self) -> u32 {
        self.height
    }
}

fn main() {
    let rect = Rectangle {
        width: 30,
        height: 50,
    };

    println!("Width: {}", rect.width()); // Accessing the width via getter method
    println!("Height: {}", rect.height()); // Accessing the height via getter method
}
```

Here:
- `width` and `height` are private fields of the `Rectangle` struct.
- The getter methods `width()` and `height()` allow access to these fields outside the struct.

---

### **2. Setter Methods**

A **setter** method allows you to modify the value of a private field. It usually takes one parameter and mutates the internal state of the struct. Rust enforces strict ownership and borrowing rules, so setter methods typically require the struct to be mutable if you want to change its state.

#### Example: Setter Method
```rust
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    // Getter method for `width`
    pub fn width(&self) -> u32 {
        self.width
    }

    // Getter method for `height`
    pub fn height(&self) -> u32 {
        self.height
    }

    // Setter method for `width`
    pub fn set_width(&mut self, width: u32) {
        self.width = width;
    }

    // Setter method for `height`
    pub fn set_height(&mut self, height: u32) {
        self.height = height;
    }
}

fn main() {
    let mut rect = Rectangle {
        width: 30,
        height: 50,
    };

    println!("Original width: {}", rect.width());
    rect.set_width(40); // Using setter to change width
    println!("Updated width: {}", rect.width());

    println!("Original height: {}", rect.height());
    rect.set_height(60); // Using setter to change height
    println!("Updated height: {}", rect.height());
}
```

In this example:
- The `set_width()` and `set_height()` setter methods modify the `width` and `height` fields, respectively.
- The struct is made mutable (`let mut rect`) so that the setter methods can modify its state.

---

### **3. Using Getter and Setter for Validation**

You can use setter methods to enforce validation, ensuring that only valid values are set. This is particularly useful when you need to enforce constraints on the data.

#### Example: Setter with Validation
```rust
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    // Getter method for `width`
    pub fn width(&self) -> u32 {
        self.width
    }

    // Getter method for `height`
    pub fn height(&self) -> u32 {
        self.height
    }

    // Setter method with validation for `width`
    pub fn set_width(&mut self, width: u32) {
        if width > 0 {
            self.width = width;
        } else {
            println!("Width must be greater than 0.");
        }
    }

    // Setter method with validation for `height`
    pub fn set_height(&mut self, height: u32) {
        if height > 0 {
            self.height = height;
        } else {
            println!("Height must be greater than 0.");
        }
    }
}

fn main() {
    let mut rect = Rectangle {
        width: 30,
        height: 50,
    };

    rect.set_width(0); // Invalid width, won't change
    rect.set_height(40); // Valid height

    println!("Updated width: {}", rect.width()); // Should remain 30
    println!("Updated height: {}", rect.height()); // Should be 40
}
```

In this example:
- The setter methods for `width` and `height` include simple validation to ensure that the values being set are greater than 0.
- If an invalid value is provided (like `0` for `width`), the setter prints an error message and does not change the value.

---

### **4. Using `get` and `set` for Encapsulation**

Getter and setter methods are commonly used in Rust to encapsulate data and ensure that internal fields cannot be modified directly by other parts of the code. This approach is useful for protecting the integrity of your data and enforcing business rules.

#### Example: Encapsulation with Getter and Setter
```rust
struct BankAccount {
    balance: u32,
}

impl BankAccount {
    // Getter for `balance`
    pub fn balance(&self) -> u32 {
        self.balance
    }

    // Setter for `balance` with validation
    pub fn deposit(&mut self, amount: u32) {
        if amount > 0 {
            self.balance += amount;
        } else {
            println!("Deposit amount must be greater than 0.");
        }
    }

    // Setter for `balance` with validation
    pub fn withdraw(&mut self, amount: u32) {
        if amount > 0 && self.balance >= amount {
            self.balance -= amount;
        } else {
            println!("Insufficient funds or invalid withdrawal amount.");
        }
    }
}

fn main() {
    let mut account = BankAccount { balance: 100 };

    println!("Initial balance: {}", account.balance());

    account.deposit(50);
    println!("Balance after deposit: {}", account.balance());

    account.withdraw(30);
    println!("Balance after withdrawal: {}", account.balance());

    account.withdraw(200); // Error: insufficient funds
    println!("Final balance: {}", account.balance());
}
```

Here:
- The `BankAccount` struct encapsulates the `balance` field, making it private.
- The `deposit()` and `withdraw()` methods act as setters and control the modifications to the `balance` field, ensuring that deposits and withdrawals are valid.
- The getter method `balance()` allows for reading the current balance without exposing the internal state directly.

---

### **5. Conclusion**

Getter and setter methods in Rust provide a way to encapsulate struct fields and control access to them, following the principles of **encapsulation** and **data integrity**. By using these methods, you can:

- Control how fields are accessed and modified.
- Enforce validation rules when setting values.
- Ensure that internal fields remain private while providing necessary access through public methods.

This approach allows you to design Rust structs with well-defined APIs, maintaining the flexibility to adjust the internal state while keeping it safe from unintended modifications.
