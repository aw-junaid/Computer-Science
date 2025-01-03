### **Practical Examples of Encapsulation in Rust**

Encapsulation is one of the core principles of object-oriented programming, and in Rust, it is primarily achieved through the use of **private fields** and **getter/setter methods**. By controlling the visibility of data and methods, we can hide the internal implementation details from external access, which leads to safer and more maintainable code.

Here are some practical examples of how **encapsulation** can be implemented in Rust:

---

### **1. Managing Bank Accounts**

A good example of encapsulation in Rust is the management of sensitive data, such as the balance in a bank account. Instead of directly accessing the balance, getter and setter methods are used to control the modification and reading of the balance.

#### Example: Bank Account with Encapsulation
```rust
struct BankAccount {
    balance: u32,
}

impl BankAccount {
    // Getter for balance
    pub fn balance(&self) -> u32 {
        self.balance
    }

    // Setter for deposit
    pub fn deposit(&mut self, amount: u32) {
        if amount > 0 {
            self.balance += amount;
        } else {
            println!("Deposit amount must be greater than 0.");
        }
    }

    // Setter for withdraw with validation
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

    // Making valid and invalid transactions
    account.deposit(50);
    println!("Balance after deposit: {}", account.balance());

    account.withdraw(30);
    println!("Balance after withdrawal: {}", account.balance());

    account.withdraw(200); // Invalid withdrawal attempt
    println!("Final balance: {}", account.balance());
}
```

**Encapsulation in Action:**
- The `balance` field is private to the `BankAccount` struct and cannot be accessed directly from outside.
- Getter (`balance()`) and setter (`deposit()`, `withdraw()`) methods allow controlled access to the balance, and validation is performed before modifying it.
- The balance field is protected from direct modification, ensuring its integrity.

---

### **2. Implementing a User Profile**

Another example of encapsulation can be seen in the management of user profiles. Here, we might want to hide the user's password and only expose relevant profile information like the username and email address. We can use getter and setter methods to control access to the sensitive fields.

#### Example: User Profile with Encapsulation
```rust
struct UserProfile {
    username: String,
    email: String,
    password: String,
}

impl UserProfile {
    // Getter for username
    pub fn username(&self) -> &str {
        &self.username
    }

    // Getter for email
    pub fn email(&self) -> &str {
        &self.email
    }

    // Setter for updating email with validation
    pub fn update_email(&mut self, new_email: String) {
        if new_email.contains('@') {
            self.email = new_email;
        } else {
            println!("Invalid email format.");
        }
    }

    // Setter for password (should only allow strong passwords)
    pub fn update_password(&mut self, new_password: String) {
        if new_password.len() >= 8 {
            self.password = new_password;
        } else {
            println!("Password must be at least 8 characters long.");
        }
    }

    // Private method for validating password strength
    fn validate_password(&self) -> bool {
        self.password.len() >= 8
    }
}

fn main() {
    let mut user = UserProfile {
        username: String::from("john_doe"),
        email: String::from("john@example.com"),
        password: String::from("securepassword"),
    };

    // Accessing the public fields using getters
    println!("Username: {}", user.username());
    println!("Email: {}", user.email());

    // Updating email and password using setters
    user.update_email(String::from("john.doe@domain.com"));
    println!("Updated email: {}", user.email());

    // Trying to set an invalid password
    user.update_password(String::from("weak"));
    user.update_password(String::from("strongpassword"));
    println!("Password successfully updated!");
}
```

**Encapsulation in Action:**
- The `password` field is kept private, and validation is done via a setter method to ensure it adheres to security requirements.
- The `email` field is validated for a correct format before it is updated.
- The getter methods expose only the necessary fields (username and email) without directly accessing the private password.

---

### **3. Controlling Access to Configuration Settings**

In real-world applications, you may need to store configuration settings that should not be directly modified by external code. Encapsulation ensures that these settings can only be modified through controlled access points.

#### Example: Configuration Settings
```rust
struct Config {
    max_connections: u32,
    timeout: u32, // in seconds
    is_enabled: bool,
}

impl Config {
    // Getter for `max_connections`
    pub fn max_connections(&self) -> u32 {
        self.max_connections
    }

    // Getter for `timeout`
    pub fn timeout(&self) -> u32 {
        self.timeout
    }

    // Getter for `is_enabled`
    pub fn is_enabled(&self) -> bool {
        self.is_enabled
    }

    // Setter for `max_connections`
    pub fn set_max_connections(&mut self, value: u32) {
        if value > 0 {
            self.max_connections = value;
        } else {
            println!("Max connections must be greater than 0.");
        }
    }

    // Setter for `timeout`
    pub fn set_timeout(&mut self, value: u32) {
        if value > 0 {
            self.timeout = value;
        } else {
            println!("Timeout must be greater than 0.");
        }
    }

    // Setter for `is_enabled`
    pub fn toggle_enabled(&mut self) {
        self.is_enabled = !self.is_enabled;
    }
}

fn main() {
    let mut config = Config {
        max_connections: 100,
        timeout: 30,
        is_enabled: true,
    };

    println!("Max connections: {}", config.max_connections());
    println!("Timeout: {} seconds", config.timeout());
    println!("Is Enabled: {}", config.is_enabled());

    // Updating configuration settings using setter methods
    config.set_max_connections(200);
    config.set_timeout(60);
    config.toggle_enabled();

    println!("Updated Max Connections: {}", config.max_connections());
    println!("Updated Timeout: {} seconds", config.timeout());
    println!("Is Enabled: {}", config.is_enabled());
}
```

**Encapsulation in Action:**
- The configuration settings (`max_connections`, `timeout`, and `is_enabled`) are kept private.
- The setter methods control how these settings are modified, including validation and toggling functionality.
- External code can interact with the `Config` struct via getter and setter methods, ensuring safe and controlled changes to configuration.

---

### **4. Creating a Product Catalog**

In an e-commerce system, encapsulation can be used to manage a product's properties. This ensures that only valid changes can be made to the product's price and stock, protecting the integrity of the product catalog.

#### Example: Product with Encapsulation
```rust
struct Product {
    name: String,
    price: f64,
    stock: u32,
}

impl Product {
    // Getter for product name
    pub fn name(&self) -> &str {
        &self.name
    }

    // Getter for product price
    pub fn price(&self) -> f64 {
        self.price
    }

    // Getter for product stock
    pub fn stock(&self) -> u32 {
        self.stock
    }

    // Setter for updating product price
    pub fn update_price(&mut self, new_price: f64) {
        if new_price >= 0.0 {
            self.price = new_price;
        } else {
            println!("Price cannot be negative.");
        }
    }

    // Setter for updating stock
    pub fn update_stock(&mut self, new_stock: u32) {
        if new_stock >= 0 {
            self.stock = new_stock;
        } else {
            println!("Stock cannot be negative.");
        }
    }
}

fn main() {
    let mut product = Product {
        name: String::from("Laptop"),
        price: 999.99,
        stock: 50,
    };

    println!("Product: {}", product.name());
    println!("Price: ${}", product.price());
    println!("Stock: {}", product.stock());

    // Update product price and stock
    product.update_price(1099.99);
    product.update_stock(45);

    println!("Updated Price: ${}", product.price());
    println!("Updated Stock: {}", product.stock());
}
```

**Encapsulation in Action:**
- The `Product` struct encapsulates its fields, making `price` and `stock` private.
- Getter and setter methods control how the price and stock are accessed and modified.
- Validation ensures that only non-negative prices and stock values are allowed.

---

### **Conclusion**

These examples demonstrate how **encapsulation** in Rust can be used to manage the internal state of a struct and expose only controlled access to its fields. The core idea is to:

- Use **private fields** to protect the integrity of the struct.
- Use **getter and setter methods** to provide controlled access to the data.
- Perform **validation** in setter methods to ensure the correctness and safety of changes.

Encapsulation in Rust helps in writing robust, maintainable, and secure code by preventing unintended or malicious modification of data and exposing only the necessary functionality.
