### **Access Modifiers in C++**

In C++, **access modifiers** are keywords that define the accessibility of class members (data members and member functions). These modifiers control how and where the members of a class can be accessed, ensuring data encapsulation and security.

There are three main types of access modifiers in C++:

1. **`public`**
2. **`private`**
3. **`protected`**

Each of these modifiers defines different levels of access control for the members of a class.

---

### **1. `public` Access Modifier**

Members declared as `public` are accessible from anywhere, both inside and outside the class. This means you can access or modify the public members of a class directly through an object or a pointer.

#### **Syntax:**

```cpp
class ClassName {
public:
    dataType memberName;
    void memberFunction() {
        // function code
    }
};
```

#### **Example:**

```cpp
#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;

    // Public function to display person details
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Person p;
    p.name = "Alice";  // Accessing public member directly
    p.age = 25;
    p.display();  // Calling public function

    return 0;
}
```

**Output:**
```
Name: Alice, Age: 25
```

In this example, the `name` and `age` members, as well as the `display()` function, are **public** and can be accessed from anywhere in the program.

---

### **2. `private` Access Modifier**

Members declared as `private` are **only accessible within the class**. They cannot be accessed directly from outside the class. This ensures that the internal state of the object remains hidden and protected from outside interference.

#### **Syntax:**

```cpp
class ClassName {
private:
    dataType memberName;
    void memberFunction() {
        // function code
    }
};
```

#### **Example:**

```cpp
#include <iostream>
using namespace std;

class Account {
private:
    double balance;  // Private member

public:
    // Constructor to initialize balance
    Account(double bal) {
        balance = bal;
    }

    // Public function to display balance
    void displayBalance() {
        cout << "Balance: $" << balance << endl;
    }

    // Public function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
};

int main() {
    Account acc(1000.0);
    acc.displayBalance();
    acc.deposit(500.0);  // Can access deposit() as it is public
    acc.displayBalance();
    
    // Error: balance cannot be accessed directly since it is private
    // cout << acc.balance << endl;  // Uncommenting this line will cause a compile-time error

    return 0;
}
```

**Output:**
```
Balance: $1000
Balance: $1500
```

In this example, the `balance` member is **private** and cannot be accessed directly outside the class. The public member functions `deposit()` and `displayBalance()` are used to modify and display the balance.

---

### **3. `protected` Access Modifier**

Members declared as `protected` are similar to **private** members in that they are **not accessible outside the class**, but they can be accessed in **derived (child) classes**. This allows derived classes to interact with the base class's data without exposing it to the outside world.

#### **Syntax:**

```cpp
class ClassName {
protected:
    dataType memberName;
    void memberFunction() {
        // function code
    }
};
```

#### **Example:**

```cpp
#include <iostream>
using namespace std;

class Animal {
protected:
    string species;  // Protected member

public:
    Animal(string s) {
        species = s;
    }

    // Public function to display species
    void displaySpecies() {
        cout << "Species: " << species << endl;
    }
};

class Dog : public Animal {  // Inheriting from Animal
public:
    Dog(string s) : Animal(s) {}  // Calling base class constructor

    void showDetails() {
        cout << "Dog's species: " << species << endl;  // Accessing protected member
    }
};

int main() {
    Dog d("Bulldog");
    d.showDetails();  // Can access protected member in derived class
    d.displaySpecies();  // Can also access public method of base class

    // Error: Cannot access species directly since it is protected in the base class
    // cout << d.species << endl;  // Uncommenting this line will cause a compile-time error

    return 0;
}
```

**Output:**
```
Dog's species: Bulldog
Species: Bulldog
```

In this example, `species` is a **protected** member of the `Animal` class. It is accessible inside the `Dog` class (which is derived from `Animal`), but it cannot be accessed directly outside the class.

---

### **4. Summary of Access Modifiers**

| Modifier   | Description | Access |
|------------|-------------|--------|
| **`public`**    | Members are accessible from anywhere (inside and outside the class) | Accessible from anywhere |
| **`private`**   | Members are only accessible within the class | Not accessible from outside the class |
| **`protected`** | Members are accessible within the class and by derived classes | Accessible within the class and derived classes |

---

### **5. Default Access Level for Classes**

- For **structs**, members are `public` by default.
- For **classes**, members are `private` by default.

```cpp
struct MyStruct {
    int data;  // Public by default
};

class MyClass {
    int data;  // Private by default
};
```

---

### **6. Access Modifiers in Practice: Example**

```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    // Constructor to initialize account
    BankAccount(string accNum, double bal) {
        accountNumber = accNum;
        balance = bal;
    }

    // Public method to access private data
    void displayAccount() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }

    // Public method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "$" << amount << " deposited." << endl;
        }
    }
};

int main() {
    BankAccount account("123456", 1000.0);

    account.displayAccount();
    account.deposit(500.0);
    account.displayAccount();

    // Error: Cannot access private members directly
    // cout << account.accountNumber << endl;

    return 0;
}
```

**Output:**
```
Account Number: 123456
Balance: $1000
$500 deposited.
Account Number: 123456
Balance: $1500
```

---

### **7. Summary**

- **`public`**: Members are accessible from anywhere (outside the class or in other classes).
- **`private`**: Members are accessible only within the class.
- **`protected`**: Members are accessible within the class and its derived classes, but not from outside.

