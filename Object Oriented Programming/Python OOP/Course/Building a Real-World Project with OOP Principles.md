### **Building a Real-World Project with OOP Principles**

To understand how object-oriented programming (OOP) principles can be applied in practice, let's walk through building a **real-world project**: a **Library Management System**. This project will demonstrate how to apply various OOP concepts such as classes, inheritance, polymorphism, encapsulation, and abstraction to design and implement a system that models a library environment.

### **Overview of the Project**

The Library Management System will be responsible for:
- **Managing books** (adding, removing, and searching).
- **Managing users** (registering users, checking out and returning books).
- **Managing the borrowing process** (limiting the number of books a user can borrow, tracking borrowed books, etc.).

### **Step-by-Step Development Using OOP Principles**

#### 1. **Define the Core Classes (Encapsulation)**

We'll begin by identifying the key entities that will interact in the system. In this case, we have:
- `Book`
- `User`
- `Library`

Each class will encapsulate relevant data and behavior related to these entities.

##### **Book Class** (Represents a book in the library)
```python
class Book:
    def __init__(self, title, author, isbn):
        self.title = title
        self.author = author
        self.isbn = isbn
        self.is_borrowed = False

    def borrow(self):
        if not self.is_borrowed:
            self.is_borrowed = True
            print(f"Book '{self.title}' borrowed successfully.")
        else:
            print(f"Book '{self.title}' is already borrowed.")

    def return_book(self):
        if self.is_borrowed:
            self.is_borrowed = False
            print(f"Book '{self.title}' returned successfully.")
        else:
            print(f"Book '{self.title}' wasn't borrowed.")

    def __str__(self):
        return f"Book Title: {self.title}, Author: {self.author}, ISBN: {self.isbn}"
```

##### **User Class** (Represents a user of the library)
```python
class User:
    def __init__(self, username, max_books=3):
        self.username = username
        self.max_books = max_books
        self.borrowed_books = []

    def borrow_book(self, book):
        if len(self.borrowed_books) < self.max_books:
            self.borrowed_books.append(book)
            book.borrow()
        else:
            print(f"User '{self.username}' has already borrowed the maximum number of books.")

    def return_book(self, book):
        if book in self.borrowed_books:
            self.borrowed_books.remove(book)
            book.return_book()
        else:
            print(f"User '{self.username}' did not borrow this book.")
```

#### 2. **Inheritance and Extending Functionality**

We can introduce inheritance to add special types of users, such as **Librarians**, who have extra permissions compared to regular users.

##### **Librarian Class** (Extends User)
```python
class Librarian(User):
    def __init__(self, username, max_books=5):
        super().__init__(username, max_books)

    def add_book(self, book, library):
        library.add_book(book)
        print(f"Book '{book.title}' added to the library.")

    def remove_book(self, book, library):
        library.remove_book(book)
        print(f"Book '{book.title}' removed from the library.")
```

#### 3. **Abstracting Common Behavior (Abstraction)**

We might want to have different types of libraries in the future (e.g., online and physical libraries). To keep things flexible, we can create an abstract `Library` class that will be inherited by both the physical and online library classes.

##### **Abstract Library Class**
```python
from abc import ABC, abstractmethod

class Library(ABC):
    @abstractmethod
    def add_book(self, book):
        pass

    @abstractmethod
    def remove_book(self, book):
        pass

    @abstractmethod
    def search_book(self, isbn):
        pass
```

##### **PhysicalLibrary Class** (Concrete implementation of `Library`)
```python
class PhysicalLibrary(Library):
    def __init__(self):
        self.books = []

    def add_book(self, book):
        self.books.append(book)

    def remove_book(self, book):
        if book in self.books:
            self.books.remove(book)

    def search_book(self, isbn):
        for book in self.books:
            if book.isbn == isbn:
                return book
        return None
```

#### 4. **Polymorphism (Method Overriding)**

We can override methods in child classes to provide more specialized behavior. For example, both the `User` and `Librarian` can borrow and return books, but the behavior might be different depending on whether the user is a regular user or a librarian.

##### **Polymorphism Example (Overriding Borrow Method)**

While the `User` class allows borrowing of books with a limit, the `Librarian` class can borrow an unlimited number of books.

```python
class Librarian(User):
    def __init__(self, username):
        super().__init__(username, max_books=10)  # Unlimited borrowing capability

    def borrow_book(self, book):
        print(f"Librarian '{self.username}' borrowing book: {book.title}")
        super().borrow_book(book)
```

#### 5. **Managing Borrowing and Returning Books (Composition)**

In the Library Management System, **Composition** is used, as each `Library` will have a collection of `Book` objects, and a `User` will have a collection of `Book` objects they've borrowed.

```python
# Creating library instance
physical_library = PhysicalLibrary()

# Creating books and adding them to the library
book1 = Book("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565")
book2 = Book("1984", "George Orwell", "9780451524935")

physical_library.add_book(book1)
physical_library.add_book(book2)

# Creating user and librarian
user1 = User("john_doe")
librarian = Librarian("librarian_1")

# Searching for a book in the library
searched_book = physical_library.search_book("9780743273565")
if searched_book:
    print(f"Found: {searched_book}")

# Librarian adding a new book
new_book = Book("Moby Dick", "Herman Melville", "9781503280786")
librarian.add_book(new_book, physical_library)

# User borrowing and returning books
user1.borrow_book(searched_book)
user1.return_book(searched_book)
```

### **OOP Concepts Demonstrated**

1. **Encapsulation**: Each class encapsulates data (attributes) and methods to interact with that data. For instance, the `Book` class manages its own state (`is_borrowed`), and the `User` class manages the books borrowed.
   
2. **Inheritance**: The `Librarian` class extends the `User` class, inheriting its functionality but also providing additional behavior (e.g., unlimited borrowing).

3. **Abstraction**: The abstract `Library` class allows different types of libraries (physical or online) to have a common interface, hiding implementation details.

4. **Polymorphism**: The `borrow_book` method is overridden in the `Librarian` class to allow for unlimited borrowing, demonstrating polymorphism.

5. **Composition**: The `Library` class contains a collection of `Book` objects, and the `User` class contains a collection of borrowed books, showcasing the composition relationship.

### **Conclusion**

This Library Management System project demonstrates how to apply core OOP principles to build a real-world system. By using **encapsulation**, **inheritance**, **abstraction**, **polymorphism**, and **composition**, we can design a flexible, modular, and maintainable system. As you continue to learn and implement more advanced features, you can further refine the design to meet specific needs or scale the system.
