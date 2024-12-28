### **Using Encapsulation and Inheritance to Manage Books and Members in C**

In C, we can simulate **encapsulation** and **inheritance** (core principles of object-oriented programming) using **structures** and **function pointers**. We'll build a simple system to manage a **library** where books and library members are treated as **objects**. We will model a **Book** and a **Member** with encapsulation (hiding internal data) and inheritance (deriving specific types from a common base structure).

### **Key Concepts**
1. **Encapsulation**: Using structures to group related data together, along with providing functions to access and modify this data.
2. **Inheritance**: Deriving one structure from another by embedding the base structure inside a derived structure and adding or modifying its functionality.

---

### **1. Define Base Structure (`Item`)**

The base structure `Item` will encapsulate common properties of both books and members, like ID and name. For polymorphism (and simulating inheritance), we’ll define some common functions for these entities (such as `displayInfo`).

### **Header File for Base (`Item.h`)**

```c
// Item.h
#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>

typedef struct {
    int id;
    char name[100];

    // Function pointer for displaying item info (polymorphism simulation)
    void (*displayInfo)(void*);
} Item;

// Function declarations for Item
void initializeItem(Item* item, int id, const char* name);
void displayItemInfo(void* obj);

#endif  // ITEM_H
```

### **Base Structure Implementation (`Item.c`)**

```c
// Item.c
#include <stdio.h>
#include <string.h>
#include "Item.h"

// Initialize the common properties of any Item
void initializeItem(Item* item, int id, const char* name) {
    item->id = id;
    strncpy(item->name, name, sizeof(item->name) - 1);
    item->name[sizeof(item->name) - 1] = '\0';

    // Default implementation of displayInfo
    item->displayInfo = displayItemInfo;
}

// Display information about the Item
void displayItemInfo(void* obj) {
    Item* item = (Item*)obj;
    printf("ID: %d, Name: %s\n", item->id, item->name);
}
```

---

### **2. Define Derived Structure for `Book`**

A **Book** is a specific type of **Item** that has extra information such as author, genre, and year of publication. We'll inherit from the `Item` structure by embedding it in `Book` and add additional properties.

### **Header File for Book (`Book.h`)**

```c
// Book.h
#ifndef BOOK_H
#define BOOK_H

#include "Item.h"

// Define the Book structure, which inherits from Item
typedef struct {
    Item base;           // Base class Item
    char author[100];
    int year;
} Book;

// Function declarations for Book
void initializeBook(Book* book, int id, const char* name, const char* author, int year);
void displayBookInfo(void* obj);

#endif  // BOOK_H
```

### **Book Structure Implementation (`Book.c`)**

```c
// Book.c
#include <stdio.h>
#include <string.h>
#include "Book.h"

// Initialize the Book with its specific properties
void initializeBook(Book* book, int id, const char* name, const char* author, int year) {
    initializeItem(&book->base, id, name);  // Initialize the base class Item
    strncpy(book->author, author, sizeof(book->author) - 1);
    book->author[sizeof(book->author) - 1] = '\0';
    book->year = year;

    // Override displayInfo to display Book-specific info
    book->base.displayInfo = displayBookInfo;
}

// Display information specific to the Book
void displayBookInfo(void* obj) {
    Book* book = (Book*)obj;
    printf("Book Info:\n");
    printf("ID: %d\n", book->base.id);
    printf("Name: %s\n", book->base.name);
    printf("Author: %s\n", book->author);
    printf("Year: %d\n", book->year);
}
```

---

### **3. Define Derived Structure for `Member`**

A **Member** is a specific type of **Item** that has additional properties such as membership level, date of membership, and borrowed books.

### **Header File for Member (`Member.h`)**

```c
// Member.h
#ifndef MEMBER_H
#define MEMBER_H

#include "Item.h"

// Define the Member structure, which inherits from Item
typedef struct {
    Item base;           // Base class Item
    char membershipLevel[50];
    char dateJoined[20];
} Member;

// Function declarations for Member
void initializeMember(Member* member, int id, const char* name, const char* level, const char* date);
void displayMemberInfo(void* obj);

#endif  // MEMBER_H
```

### **Member Structure Implementation (`Member.c`)**

```c
// Member.c
#include <stdio.h>
#include <string.h>
#include "Member.h"

// Initialize the Member with its specific properties
void initializeMember(Member* member, int id, const char* name, const char* level, const char* date) {
    initializeItem(&member->base, id, name);  // Initialize the base class Item
    strncpy(member->membershipLevel, level, sizeof(member->membershipLevel) - 1);
    member->membershipLevel[sizeof(member->membershipLevel) - 1] = '\0';
    strncpy(member->dateJoined, date, sizeof(member->dateJoined) - 1);
    member->dateJoined[sizeof(member->dateJoined) - 1] = '\0';

    // Override displayInfo to display Member-specific info
    member->base.displayInfo = displayMemberInfo;
}

// Display information specific to the Member
void displayMemberInfo(void* obj) {
    Member* member = (Member*)obj;
    printf("Member Info:\n");
    printf("ID: %d\n", member->base.id);
    printf("Name: %s\n", member->base.name);
    printf("Membership Level: %s\n", member->membershipLevel);
    printf("Date Joined: %s\n", member->dateJoined);
}
```

---

### **4. Main File (`main.c`)**

In `main.c`, we will create instances of `Book` and `Member` and demonstrate polymorphism by calling their `displayInfo` method via the common `Item` interface.

```c
// main.c
#include <stdio.h>
#include "Book.h"
#include "Member.h"

int main() {
    // Create and initialize a Book
    Book book1;
    initializeBook(&book1, 101, "The C Programming Language", "Dennis Ritchie", 1978);

    // Create and initialize a Member
    Member member1;
    initializeMember(&member1, 201, "John Doe", "Gold", "2023-01-15");

    // Use polymorphism to display information of different types
    Item* itemPtr = (Item*)&book1;
    itemPtr->displayInfo(itemPtr);  // Book's displayInfo

    itemPtr = (Item*)&member1;
    itemPtr->displayInfo(itemPtr);  // Member's displayInfo

    return 0;
}
```

### **Explanation of `main.c`**:

- **Creating Objects**: We create a `Book` and a `Member` object and initialize them using their respective initialization functions.
- **Polymorphic Behavior**: By assigning the `Item` pointer to both `Book` and `Member` objects, we can use polymorphism to call their respective `displayInfo` methods through the common `Item` interface.

### **Compiling and Running the Code**

To compile and run the program, use the following command:

```bash
gcc -o library_program main.c Book.c Member.c Item.c
```

Then run the program:

```bash
./library_program
```

### **Output:**

```
Book Info:
ID: 101
Name: The C Programming Language
Author: Dennis Ritchie
Year: 1978
Member Info:
ID: 201
Name: John Doe
Membership Level: Gold
Date Joined: 2023-01-15
```

---

### **Key Takeaways**

1. **Encapsulation**: The structures (`Item`, `Book`, `Member`) encapsulate data and functions. The internal data of each structure is not directly accessible from outside, ensuring data integrity and controlled access via functions.
   
2. **Inheritance**: We simulate inheritance by embedding the `Item` structure within `Book` and `Member`. Both derived structures inherit the properties of `Item` and can add their own specific data (e.g., author for `Book`, membership level for `Member`).

3. **Polymorphism**: The `displayInfo` function pointer in the base structure (`Item`) allows polymorphism, where different `displayInfo` methods are called depending on the type of object (book or member).

---

### **Conclusion**

Using **encapsulation** and **inheritance** with **structures** and **callbacks** in C can provide a powerful way to manage objects like books and library members. By organizing data and behavior in a modular and extensible way, you can simulate object-oriented principles in C, making your code more maintainable and scalable.
