### **Data Types, Variables, and Constants in C**

Understanding **data types**, **variables**, and **constants** is fundamental to programming in C. These concepts define how data is stored, accessed, and manipulated in memory.

---

### **1. Data Types**
Data types in C specify the type of data that a variable can hold. They determine the size and layout of memory for that data and the operations that can be performed on it.

#### **Primary Data Types**
1. **Integer Types**  
   - Used to store whole numbers.
   - Examples: `int`, `short`, `long`, `long long`.
   - **Modifiers:** `signed` (default), `unsigned`.  
   - **Example:**
     ```c
     int a = 10;            // Signed integer
     unsigned int b = 20;   // Unsigned integer
     ```

2. **Floating-Point Types**  
   - Used to store decimal numbers.  
   - Examples: `float`, `double`, `long double`.  
   - **Example:**
     ```c
     float pi = 3.14f;      // Single-precision floating-point
     double e = 2.71828;    // Double-precision floating-point
     ```

3. **Character Type**  
   - Used to store a single character.
   - Example: `char`.  
   - **Example:**
     ```c
     char grade = 'A';
     ```

4. **Void Type**  
   - Represents no data. Used in functions that do not return a value.  
   - **Example:**
     ```c
     void displayMessage() {
         printf("Hello, World!");
     }
     ```

---

#### **Derived Data Types**
1. **Arrays**  
   - Used to store a collection of elements of the same type.
   - **Example:**
     ```c
     int numbers[5] = {1, 2, 3, 4, 5};
     ```

2. **Pointers**  
   - Used to store the address of a variable.  
   - **Example:**
     ```c
     int a = 10;
     int *ptr = &a;         // Pointer to integer
     ```

3. **Structures**  
   - Used to group variables of different types.
   - **Example:**
     ```c
     struct Point {
         int x;
         int y;
     };
     ```

4. **Enumerations**  
   - Used to define a set of named integer constants.
   - **Example:**
     ```c
     enum Day {SUNDAY, MONDAY, TUESDAY};
     ```

---

#### **Type Ranges (Common Values)**

| **Data Type**     | **Size (bytes)** | **Range**                                |
|--------------------|------------------|------------------------------------------|
| `char`            | 1                | `-128 to 127` or `0 to 255` (unsigned)   |
| `int`             | 2 or 4           | `-32,768 to 32,767` or more             |
| `float`           | 4                | ±3.4×10^−38 to ±3.4×10^38               |
| `double`          | 8                | ±1.7×10^−308 to ±1.7×10^308             |

---

### **2. Variables**
A **variable** is a named storage location in memory that holds a value. The value can change during the program's execution.

#### **Declaring Variables**
- Syntax:  
  ```c
  data_type variable_name;
  ```
- Example:
  ```c
  int age;       // Declaration
  age = 25;      // Initialization
  ```

#### **Variable Rules**
1. Variable names must start with a letter or an underscore (`_`).
2. Can only contain letters, digits, and underscores.
3. Cannot use reserved keywords (e.g., `int`, `return`).

---

#### **Types of Variables**
1. **Local Variables**  
   - Declared inside a function or block.
   - Only accessible within that scope.  
   - **Example:**
     ```c
     void func() {
         int localVar = 10;  // Local variable
     }
     ```

2. **Global Variables**  
   - Declared outside all functions.
   - Accessible from any function.  
   - **Example:**
     ```c
     int globalVar = 100;
     ```

3. **Static Variables**  
   - Retain their value between function calls.  
   - **Example:**
     ```c
     void count() {
         static int counter = 0;
         counter++;
         printf("%d\n", counter);
     }
     ```

4. **Register Variables**  
   - Stored in CPU registers for fast access (if possible).  
   - **Example:**
     ```c
     register int count = 0;
     ```

---

### **3. Constants**
A **constant** is a fixed value that cannot be altered during the program's execution.

#### **Types of Constants**
1. **Literal Constants**  
   - Fixed values directly written in the code.  
   - **Example:**
     ```c
     int x = 10;          // Integer literal
     char c = 'A';        // Character literal
     float f = 3.14;      // Floating-point literal
     ```

2. **Symbolic Constants**  
   - Named constants using `#define` or `const`.
   - **Using `#define`:**
     ```c
     #define PI 3.14159
     printf("Value of PI: %f", PI);
     ```
   - **Using `const`:**
     ```c
     const int MAX_USERS = 100;
     ```

3. **Enumerated Constants**  
   - Declared using `enum`.
   - **Example:**
     ```c
     enum Color {RED, GREEN, BLUE};
     ```

---

### **Differences Between Variables and Constants**

| **Feature**     | **Variable**                                | **Constant**                               |
|------------------|--------------------------------------------|-------------------------------------------|
| **Definition**   | Storage location whose value can change.   | Fixed value that cannot be modified.      |
| **Declaration**  | `int x = 10;`                              | `const int x = 10;` or `#define X 10`     |
| **Modifiability**| Can be updated during execution.           | Cannot be altered after initialization.   |

---

### **Best Practices**
1. Use meaningful variable names (`int count` instead of `int c`).
2. Use constants for fixed values to improve readability and prevent accidental modifications.
3. Declare variables close to where they are used.

