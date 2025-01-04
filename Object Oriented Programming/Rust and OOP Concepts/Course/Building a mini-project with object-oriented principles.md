### **Building a Mini-Project with Object-Oriented Principles in Rust**

Rust, while not traditionally an object-oriented programming language like Java or C++, allows you to apply many object-oriented principles such as encapsulation, inheritance, and polymorphism through its unique features like structs, traits, and enums. In this mini-project, we will build a simple "Library Management System" to demonstrate object-oriented design principles in Rust.

---

### **Project Overview:**
The system will model a basic library, where books can be borrowed and returned. We will:
- Define entities such as `Book` and `User`.
- Use `structs` for data representation.
- Implement methods to perform actions like borrowing and returning books.
- Use `traits` to define common behavior (e.g., something that can be checked out or returned).
- Implement encapsulation and modularity through Rust's module system.

---

### **1. Define the `Book` Struct**

We'll start by defining a `Book` struct that contains information about the book, such as its title, author, and whether it is currently borrowed.

```rust
#[derive(Debug)]
struct Book {
    title: String,
    author: String,
    is_borrowed: bool,
}

impl Book {
    fn new(title: &str, author: &str) -> Self {
        Book {
            title: title.to_string(),
            author: author.to_string(),
            is_borrowed: false,
        }
    }

    fn borrow(&mut self) {
        if self.is_borrowed {
            println!("This book is already borrowed.");
        } else {
            self.is_borrowed = true;
            println!("You have borrowed '{}'", self.title);
        }
    }

    fn return_book(&mut self) {
        if !self.is_borrowed {
            println!("This book was not borrowed.");
        } else {
            self.is_borrowed = false;
            println!("You have returned '{}'", self.title);
        }
    }
}
```

- `Book` has a `borrow` and `return_book` method to simulate borrowing and returning books.
- `is_borrowed` tracks whether a book is currently borrowed.

---

### **2. Define the `User` Struct**

Now, let’s create a `User` struct. Each user will have a name and a list of books they have borrowed.

```rust
#[derive(Debug)]
struct User {
    name: String,
    borrowed_books: Vec<Book>,
}

impl User {
    fn new(name: &str) -> Self {
        User {
            name: name.to_string(),
            borrowed_books: Vec::new(),
        }
    }

    fn borrow_book(&mut self, book: &mut Book) {
        if !book.is_borrowed {
            book.borrow();
            self.borrowed_books.push(book.clone());
        } else {
            println!("Sorry, the book '{}' is already borrowed.", book.title);
        }
    }

    fn return_book(&mut self, book: &mut Book) {
        if let Some(pos) = self.borrowed_books.iter().position(|b| b.title == book.title) {
            book.return_book();
            self.borrowed_books.remove(pos);
        } else {
            println!("You haven't borrowed this book.");
        }
    }
}
```

- `borrow_book` allows a user to borrow a book if it is not already borrowed.
- `return_book` allows a user to return a book, removing it from their list of borrowed books.
- The `borrowed_books` vector stores the books the user has borrowed.

---

### **3. Define a Trait for Checkout Behavior**

We'll define a trait `Checkoutable` for types that can be borrowed and returned, providing polymorphism for other types that may need similar behavior (e.g., DVDs, eBooks).

```rust
trait Checkoutable {
    fn borrow(&mut self);
    fn return_item(&mut self);
}

impl Checkoutable for Book {
    fn borrow(&mut self) {
        if self.is_borrowed {
            println!("This book is already borrowed.");
        } else {
            self.is_borrowed = true;
            println!("You have borrowed '{}'", self.title);
        }
    }

    fn return_item(&mut self) {
        if !self.is_borrowed {
            println!("This book was not borrowed.");
        } else {
            self.is_borrowed = false;
            println!("You have returned '{}'", self.title);
        }
    }
}
```

- The `Checkoutable` trait ensures that any object implementing this trait will have `borrow` and `return_item` methods. Here, we've implemented this trait for the `Book` struct.

---

### **4. Organize Code into Modules**

For better code organization, we can split the code into multiple modules, such as `book.rs`, `user.rs`, and `lib.rs`.

#### **File Structure:**

```
src/
├── main.rs
├── book.rs
├── user.rs
└── lib.rs
```

#### **book.rs**

```rust
#[derive(Debug, Clone)]
pub struct Book {
    pub title: String,
    pub author: String,
    pub is_borrowed: bool,
}

impl Book {
    pub fn new(title: &str, author: &str) -> Self {
        Book {
            title: title.to_string(),
            author: author.to_string(),
            is_borrowed: false,
        }
    }
}

pub trait Checkoutable {
    fn borrow(&mut self);
    fn return_item(&mut self);
}

impl Checkoutable for Book {
    fn borrow(&mut self) {
        if self.is_borrowed {
            println!("This book is already borrowed.");
        } else {
            self.is_borrowed = true;
            println!("You have borrowed '{}'", self.title);
        }
    }

    fn return_item(&mut self) {
        if !self.is_borrowed {
            println!("This book was not borrowed.");
        } else {
            self.is_borrowed = false;
            println!("You have returned '{}'", self.title);
        }
    }
}
```

#### **user.rs**

```rust
use crate::book::Book;

#[derive(Debug)]
pub struct User {
    pub name: String,
    pub borrowed_books: Vec<Book>,
}

impl User {
    pub fn new(name: &str) -> Self {
        User {
            name: name.to_string(),
            borrowed_books: Vec::new(),
        }
    }

    pub fn borrow_book(&mut self, book: &mut Book) {
        if !book.is_borrowed {
            book.borrow();
            self.borrowed_books.push(book.clone());
        } else {
            println!("Sorry, the book '{}' is already borrowed.", book.title);
        }
    }

    pub fn return_book(&mut self, book: &mut Book) {
        if let Some(pos) = self.borrowed_books.iter().position(|b| b.title == book.title) {
            book.return_item();
            self.borrowed_books.remove(pos);
        } else {
            println!("You haven't borrowed this book.");
        }
    }
}
```

#### **lib.rs**

```rust
pub mod book;
pub mod user;
```

---

### **5. Main Program**

Finally, we will write a `main.rs` to use these modules and demonstrate the functionality.

```rust
mod lib;
use lib::book::Book;
use lib::user::User;

fn main() {
    // Create books
    let mut book1 = Book::new("The Rust Programming Language", "Steve Klabnik");
    let mut book2 = Book::new("Rust in Action", "Tim McNamara");

    // Create user
    let mut user = User::new("Alice");

    // Borrowing books
    user.borrow_book(&mut book1);
    user.borrow_book(&mut book2);

    // Returning books
    user.return_book(&mut book1);

    // Trying to borrow a returned book
    user.borrow_book(&mut book1);
}
```

### **6. Running the Program**

When running the program, it will simulate a user borrowing and returning books.

**Expected Output:**

```
You have borrowed 'The Rust Programming Language'
You have borrowed 'Rust in Action'
You have returned 'The Rust Programming Language'
You have borrowed 'The Rust Programming Language'
```

---

### **7. Explanation of Object-Oriented Principles Applied**

- **Encapsulation:** We have used `struct` types (`Book` and `User`) to encapsulate related data. Methods like `borrow` and `return_book` are defined within the respective structs, ensuring that the internal state of the struct is controlled and accessed only through these methods.
  
- **Inheritance/Polymorphism:** We used a trait (`Checkoutable`) to abstract the concept of borrowing and returning items, making it possible to apply the same behavior to other types of items in the future (e.g., DVDs, eBooks) without changing the logic of the system.

- **Modularity:** The code is split into modules for `book`, `user`, and `lib`, which helps maintain a clean, modular structure. Each module is responsible for a specific part of the system, making the code easier to maintain and scale.

---

### **8. Conclusion**

This mini-project demonstrates how to apply object-oriented principles in Rust by leveraging `structs`, `traits`, and encapsulation. By using these features, we can build flexible, modular, and maintainable software systems while adhering to Rust's design principles of safety and performance.
