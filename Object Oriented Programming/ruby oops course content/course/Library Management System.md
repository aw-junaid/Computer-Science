### **Design and Implement a Library Management System in Ruby (OOP)**

Let’s design a simple object-oriented Ruby application for managing a library. The system will include the following core features:
1. **Book Management**: Add, view, and delete books.
2. **Member Management**: Register and manage library members.
3. **Borrowing Books**: Allow members to borrow and return books.
4. **Search for Books**: Members can search for books by title and author.

We will break it down into multiple classes to adhere to the principles of OOP.

---

### **1. Define the Classes**

#### **Classes Breakdown**:
- `Book`: Represents a book in the library.
- `Member`: Represents a library member.
- `Library`: Manages the collection of books and members and the borrowing process.

---

### **2. Class Definitions**

#### **Book Class**

```ruby
class Book
  attr_reader :title, :author, :isbn, :availability

  def initialize(title, author, isbn)
    @title = title
    @author = author
    @isbn = isbn
    @availability = true  # Book is available by default
  end

  def borrow
    if @availability
      @availability = false
      puts "#{@title} has been borrowed."
    else
      puts "#{@title} is currently unavailable."
    end
  end

  def return_book
    if !@availability
      @availability = true
      puts "#{@title} has been returned."
    else
      puts "#{@title} was not borrowed."
    end
  end

  def to_s
    "#{@title} by #{@author} (ISBN: #{@isbn})"
  end
end
```

#### **Member Class**

```ruby
class Member
  attr_reader :name, :membership_number, :borrowed_books

  def initialize(name, membership_number)
    @name = name
    @membership_number = membership_number
    @borrowed_books = []
  end

  def borrow_book(book)
    if !@borrowed_books.include?(book) && book.availability
      book.borrow
      @borrowed_books << book
    else
      puts "#{book.title} cannot be borrowed by #{@name}."
    end
  end

  def return_book(book)
    if @borrowed_books.include?(book)
      book.return_book
      @borrowed_books.delete(book)
    else
      puts "#{book.title} was not borrowed by #{@name}."
    end
  end
end
```

#### **Library Class**

```ruby
class Library
  def initialize
    @books = []
    @members = []
  end

  def add_book(book)
    @books << book
  end

  def remove_book(isbn)
    book = @books.find { |b| b.isbn == isbn }
    if book
      @books.delete(book)
      puts "#{book.title} has been removed from the library."
    else
      puts "Book with ISBN #{isbn} not found."
    end
  end

  def register_member(member)
    @members << member
    puts "#{member.name} has been registered as a library member."
  end

  def list_books
    if @books.empty?
      puts "No books available in the library."
    else
      puts "Books in the library:"
      @books.each { |book| puts book }
    end
  end

  def search_books(title = nil, author = nil)
    found_books = @books.select do |book|
      (title.nil? || book.title.include?(title)) && (author.nil? || book.author.include?(author))
    end

    if found_books.empty?
      puts "No books found matching your criteria."
    else
      puts "Search results:"
      found_books.each { |book| puts book }
    end
  end
end
```

---

### **3. Example Usage**

Now, let’s put everything together and see how the application works.

```ruby
# Create a library instance
library = Library.new

# Create some books
book1 = Book.new("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565")
book2 = Book.new("1984", "George Orwell", "9780451524935")
book3 = Book.new("To Kill a Mockingbird", "Harper Lee", "9780061120084")

# Add books to the library
library.add_book(book1)
library.add_book(book2)
library.add_book(book3)

# Create a library member
member = Member.new("John Doe", "M001")

# Register the member with the library
library.register_member(member)

# List all books in the library
library.list_books

# Search for books by title
library.search_books("1984")

# Borrow a book
member.borrow_book(book2)

# Try borrowing the same book again (it should be unavailable)
member.borrow_book(book2)

# List borrowed books
puts "#{member.name}'s borrowed books:"
member.borrowed_books.each { |book| puts book }

# Return a book
member.return_book(book2)

# Try returning a book that wasn't borrowed
member.return_book(book1)

# Remove a book from the library
library.remove_book("9780451524935")
library.list_books
```

---

### **4. Explanation of the Code**

1. **Book Class**:
   - The `Book` class represents individual books. It has attributes such as `title`, `author`, and `isbn`. It also has methods for borrowing and returning books and tracking availability.

2. **Member Class**:
   - The `Member` class represents library members. Each member has a `name`, a `membership_number`, and a list of `borrowed_books`. The methods `borrow_book` and `return_book` manage the member’s interactions with books.

3. **Library Class**:
   - The `Library` class is the core of the system. It manages the collection of books and members. It allows books to be added, removed, and searched. It also registers members and enables borrowing and returning of books.

4. **Example Usage**:
   - We create instances of the `Book`, `Member`, and `Library` classes.
   - Books are added to the library, members are registered, and interactions (borrowing, returning) are tested.

---

### **5. Enhancements & Future Features**

- **Due Dates for Borrowed Books**: Add due dates and calculate late fees for overdue books.
- **Notifications**: Notify members when a borrowed book is due or available for borrowing.
- **Book Categories**: Add categories or genres to books for more advanced searching.
- **Fine System**: Implement fines for late book returns.

---

### **Conclusion**

This simple library management system demonstrates the use of object-oriented principles in Ruby. We designed and implemented classes with clear responsibilities, encapsulated data, and interactions between objects. The system allows for managing books, members, and borrowing actions while adhering to OOP principles such as encapsulation, inheritance, and polymorphism.
