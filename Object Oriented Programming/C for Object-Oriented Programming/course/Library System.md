A **Library Management System** (LMS) is a software application used to manage library functions such as book management, member management, borrowing and returning books, etc. Here’s an example of how to implement a simple **Library Management System** using object-oriented principles in **Java** and **Python**.

---

### **Library Management System in Java**

In Java, we will use **classes**, **inheritance**, **encapsulation**, and **polymorphism** to manage books, members, and transactions.

#### **Book Class**:
The `Book` class will contain details about a book such as the title, author, and ISBN number.

```java
class Book {
    private String title;
    private String author;
    private String isbn;
    private boolean isAvailable;

    // Constructor
    public Book(String title, String author, String isbn) {
        this.title = title;
        this.author = author;
        this.isbn = isbn;
        this.isAvailable = true;  // Book is available by default
    }

    // Getter methods
    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public String getIsbn() {
        return isbn;
    }

    public boolean isAvailable() {
        return isAvailable;
    }

    // Method to change book availability
    public void borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            System.out.println("You have borrowed the book: " + title);
        } else {
            System.out.println("The book is not available.");
        }
    }

    public void returnBook() {
        if (!isAvailable) {
            isAvailable = true;
            System.out.println("You have returned the book: " + title);
        } else {
            System.out.println("The book was not borrowed.");
        }
    }

    // Method to display book details
    public void displayBookDetails() {
        System.out.println("Title: " + title + ", Author: " + author + ", ISBN: " + isbn + ", Available: " + isAvailable);
    }
}
```

#### **Member Class**:
The `Member` class will represent a library member and store member information like name and ID.

```java
class Member {
    private String name;
    private int memberId;
    private int borrowedBooksCount;

    // Constructor
    public Member(String name, int memberId) {
        this.name = name;
        this.memberId = memberId;
        this.borrowedBooksCount = 0;
    }

    // Getter methods
    public String getName() {
        return name;
    }

    public int getMemberId() {
        return memberId;
    }

    // Methods for borrowing and returning books
    public void borrowBook(Book book) {
        if (book.isAvailable()) {
            book.borrowBook();
            borrowedBooksCount++;
        } else {
            System.out.println("Sorry, the book is not available for borrowing.");
        }
    }

    public void returnBook(Book book) {
        book.returnBook();
        if (borrowedBooksCount > 0) {
            borrowedBooksCount--;
        }
    }

    public void displayMemberDetails() {
        System.out.println("Member Name: " + name + ", Member ID: " + memberId + ", Borrowed Books: " + borrowedBooksCount);
    }
}
```

#### **Library Management System (Main Class)**:
This class will handle the interactions between members and books, such as borrowing and returning books.

```java
import java.util.ArrayList;

public class LibrarySystem {
    public static void main(String[] args) {
        // Creating books
        Book book1 = new Book("1984", "George Orwell", "12345");
        Book book2 = new Book("To Kill a Mockingbird", "Harper Lee", "67890");

        // Creating members
        Member member1 = new Member("Alice", 101);
        Member member2 = new Member("Bob", 102);

        // ArrayList to store books and members
        ArrayList<Book> books = new ArrayList<>();
        books.add(book1);
        books.add(book2);

        ArrayList<Member> members = new ArrayList<>();
        members.add(member1);
        members.add(member2);

        // Display initial state of books and members
        for (Book book : books) {
            book.displayBookDetails();
        }

        for (Member member : members) {
            member.displayMemberDetails();
        }

        // Member borrowing a book
        System.out.println("\nMember borrowing a book...");
        member1.borrowBook(book1);

        // Display updated state
        for (Book book : books) {
            book.displayBookDetails();
        }

        // Member returning a book
        System.out.println("\nMember returning a book...");
        member1.returnBook(book1);

        // Display final state
        for (Book book : books) {
            book.displayBookDetails();
        }
    }
}
```

---

### **Library Management System in Python**

The Python version will be more concise due to the language’s flexible syntax.

#### **Book Class**:
The `Book` class will store information about books and handle the borrowing and returning process.

```python
class Book:
    def __init__(self, title, author, isbn):
        self.title = title
        self.author = author
        self.isbn = isbn
        self.is_available = True

    def borrow_book(self):
        if self.is_available:
            self.is_available = False
            print(f"You have borrowed the book: {self.title}")
        else:
            print("The book is not available.")

    def return_book(self):
        if not self.is_available:
            self.is_available = True
            print(f"You have returned the book: {self.title}")
        else:
            print("The book was not borrowed.")

    def display_book_details(self):
        print(f"Title: {self.title}, Author: {self.author}, ISBN: {self.isbn}, Available: {self.is_available}")
```

#### **Member Class**:
The `Member` class will manage member details and interactions with books.

```python
class Member:
    def __init__(self, name, member_id):
        self.name = name
        self.member_id = member_id
        self.borrowed_books_count = 0

    def borrow_book(self, book):
        if book.is_available:
            book.borrow_book()
            self.borrowed_books_count += 1
        else:
            print("Sorry, the book is not available for borrowing.")

    def return_book(self, book):
        book.return_book()
        if self.borrowed_books_count > 0:
            self.borrowed_books_count -= 1

    def display_member_details(self):
        print(f"Member Name: {self.name}, Member ID: {self.member_id}, Borrowed Books: {self.borrowed_books_count}")
```

#### **Library System (Main Function)**:
This section handles the overall management, including creating books, members, and performing borrowing and returning operations.

```python
def main():
    # Creating books
    book1 = Book("1984", "George Orwell", "12345")
    book2 = Book("To Kill a Mockingbird", "Harper Lee", "67890")

    # Creating members
    member1 = Member("Alice", 101)
    member2 = Member("Bob", 102)

    # List to store books and members
    books = [book1, book2]
    members = [member1, member2]

    # Display initial state of books and members
    for book in books:
        book.display_book_details()

    for member in members:
        member.display_member_details()

    # Member borrowing a book
    print("\nMember borrowing a book...")
    member1.borrow_book(book1)

    # Display updated state
    for book in books:
        book.display_book_details()

    # Member returning a book
    print("\nMember returning a book...")
    member1.return_book(book1)

    # Display final state
    for book in books:
        book.display_book_details()

if __name__ == "__main__":
    main()
```

---

### **Key Features of the System:**
1. **Book Management**: Store and manage book details such as title, author, ISBN, and availability.
2. **Member Management**: Track member information and their borrowed books.
3. **Borrowing and Returning**: Allow members to borrow and return books, with checks on availability.
4. **Polymorphism**: Both the `Book` and `Member` classes provide methods that are common but have different implementations.
5. **Encapsulation**: Each class encapsulates the details of the book or member and exposes only the necessary methods for interaction.

---

### **Expanding the System:**
This basic system can be expanded with additional features:
1. **Search Functionality**: Search for books or members by various criteria (e.g., title, author, member name).
2. **Database Integration**: Store and retrieve data from a database (e.g., MySQL, SQLite) to handle large datasets.
3. **Overdue Book Management**: Add functionality to track overdue books and calculate fines.
4. **Book Reservation**: Allow members to reserve books that are currently unavailable.
5. **Admin Interface**: Provide an interface for admins to add/remove books and members.

This system can serve as a foundational project to understand object-oriented principles like inheritance, encapsulation, and polymorphism in both **Java** and **Python**.
