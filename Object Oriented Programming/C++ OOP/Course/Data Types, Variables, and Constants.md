### **Data Types, Variables, and Constants in C++**

C++ provides various **data types** to define the kind of data a variable can hold, along with mechanisms for declaring **variables** and **constants**.

---

### **1. Data Types**
Data types determine the type of data a variable can store.

#### **Basic Data Types**
| **Type**    | **Description**                        | **Size** (Typical)   | **Example**        |
|-------------|----------------------------------------|----------------------|--------------------|
| `int`       | Integer numbers                       | 4 bytes             | `int x = 10;`      |
| `float`     | Floating-point numbers                | 4 bytes             | `float pi = 3.14;` |
| `double`    | Double-precision floating-point numbers | 8 bytes             | `double pi = 3.14159;` |
| `char`      | Single character                      | 1 byte              | `char grade = 'A';` |
| `bool`      | Boolean values (`true` or `false`)    | 1 byte              | `bool isOn = true;` |
| `void`      | Represents no value                   | N/A                 | Used in functions like `void functionName()` |
| `wchar_t`   | Wide character                        | 2 or 4 bytes        | `wchar_t c = L'@';` |

#### **Derived Data Types**
- **Arrays**: Collection of elements of the same type (e.g., `int arr[5] = {1, 2, 3, 4, 5};`).
- **Pointers**: Stores memory address of another variable (e.g., `int* p = &x;`).
- **Functions**: Block of code performing specific tasks.
- **References**: Alias for another variable.

#### **User-Defined Data Types**
- **Structures** (`struct`): Group related variables (e.g., `struct Point { int x, y; };`).
- **Classes** (`class`): Encapsulate data and methods.
- **Enumerations** (`enum`): Define a set of named values (e.g., `enum Color { Red, Green, Blue };`).

---

### **2. Variables**
A **variable** is a named storage location in memory to hold data.

#### **Declaration and Initialization**
- Declaration:
  ```cpp
  int age;
  ```
- Initialization:
  ```cpp
  int age = 25; // Declare and initialize
  ```

#### **Rules for Naming Variables**
1. Must start with a letter or underscore (`_`).
2. Can contain letters, numbers, and underscores.
3. Case-sensitive (e.g., `Age` and `age` are different).
4. Cannot use reserved keywords (e.g., `int`, `class`).

#### **Example**
```cpp
#include <iostream>
using namespace std;

int main() {
    int age = 20;         // Integer variable
    float temperature = 36.6; // Floating-point variable
    char grade = 'A';     // Character variable
    bool isStudent = true; // Boolean variable

    cout << "Age: " << age << endl;
    cout << "Temperature: " << temperature << endl;
    cout << "Grade: " << grade << endl;
    cout << "Is student: " << isStudent << endl;

    return 0;
}
```

**Output**:
```
Age: 20
Temperature: 36.6
Grade: A
Is student: 1
```

---

### **3. Constants**
A **constant** is a variable whose value cannot change during the program's execution.

#### **Types of Constants**
1. **Literal Constants**:
   - Numbers (`123`, `3.14`).
   - Characters (`'A'`, `'@'`).
   - Strings (`"Hello"`).

2. **`const` Keyword**:
   ```cpp
   const double pi = 3.14159;
   ```

3. **`#define` Preprocessor Directive**:
   ```cpp
   #define PI 3.14159
   ```

4. **Enumerated Constants**:
   ```cpp
   enum Color { Red, Green, Blue };
   ```

#### **Example with Constants**
```cpp
#include <iostream>
using namespace std;

#define PI 3.14159

int main() {
    const int daysInWeek = 7;
    float radius = 5.0;

    float area = PI * radius * radius;

    cout << "Area of circle: " << area << endl;
    cout << "Days in a week: " << daysInWeek << endl;

    return 0;
}
```

**Output**:
```
Area of circle: 78.5398
Days in a week: 7
```

---

### **Key Differences Between Variables and Constants**
| **Feature**    | **Variable**                       | **Constant**                     |
|----------------|------------------------------------|----------------------------------|
| **Value**      | Can change during execution       | Fixed, cannot change after definition |
| **Declaration**| `int x = 10;`                     | `const int x = 10;`              |
| **Usage**      | General purpose                   | For fixed or predefined values   |

---

