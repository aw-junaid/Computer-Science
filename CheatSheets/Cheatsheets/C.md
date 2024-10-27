An extended C language cheat sheet covering essential syntax, concepts, and commands. This includes data types, operators, control structures, functions, pointers, memory management, and more. It’s designed to serve as a quick reference guide for C programming.

---

## **Basic Syntax**

### 1. **Structure of a C Program**

```c
#include <stdio.h>   // Preprocessor directive

int main() {
    // Statements
    printf("Hello, World!\n");
    return 0;
}
```

**Explanation**: Every C program starts with `#include <stdio.h>` for standard I/O functions. The `main` function is the entry point, and `return 0` indicates the program executed successfully.

---

## **Data Types and Variable Declaration**

### 2. **Primitive Data Types**

```c
int age = 25;          // Integer
float salary = 5500.5; // Floating point
double balance = 1.75; // Double precision floating point
char grade = 'A';      // Character
```

**Explanation**: C provides several data types for variables, including `int`, `float`, `double`, and `char`. Use `int` for integers, `float` and `double` for decimals, and `char` for single characters.

### 3. **Modifiers for Data Types**

```c
short int s = 1;       // Short integer
long int l = 123456;   // Long integer
unsigned int u = 25;   // Unsigned integer (positive only)
```

**Explanation**: Modifiers like `short`, `long`, and `unsigned` change the range of the base data types.

### 4. **Constants and `#define` Macro**

```c
#define PI 3.14159     // Preprocessor constant
const int MAX = 100;   // Constant integer
```

**Explanation**: `#define` defines constants at compile-time, while `const` defines constants at run-time. Both prevent modifications to the variable’s value.

---

## **Operators**

### 5. **Arithmetic Operators**

```c
int a = 10 + 5;       // Addition
int b = 10 - 5;       // Subtraction
int c = 10 * 5;       // Multiplication
int d = 10 / 2;       // Division
int e = 10 % 3;       // Modulus (remainder)
```

**Explanation**: Basic arithmetic operators are used for calculations. `%` returns the remainder of division.

### 6. **Relational Operators**

```c
if (a == b) { }       // Equal to
if (a != b) { }       // Not equal to
if (a > b) { }        // Greater than
if (a < b) { }        // Less than
```

**Explanation**: Relational operators are used to compare values, often in conditional statements.

### 7. **Logical Operators**

```c
if (a > 5 && b < 10) { }   // Logical AND
if (a > 5 || b < 10) { }   // Logical OR
if (!(a == b)) { }         // Logical NOT
```

**Explanation**: Logical operators are used to combine multiple conditions in `if` statements.

---

## **Control Structures**

### 8. **If-Else Statements**

```c
if (a > 0) {
    printf("Positive\n");
} else {
    printf("Negative or zero\n");
}
```

**Explanation**: `if-else` statements allow conditional branching in the program based on conditions.

### 9. **Switch Case**

```c
int grade = 'A';
switch (grade) {
    case 'A':
        printf("Excellent\n");
        break;
    case 'B':
        printf("Good\n");
        break;
    default:
        printf("Needs Improvement\n");
}
```

**Explanation**: `switch` is used when multiple possible values for a variable are checked, reducing multiple `if-else` conditions.

### 10. **Loops**

```c
// For loop
for (int i = 0; i < 5; i++) {
    printf("%d ", i);
}

// While loop
int j = 0;
while (j < 5) {
    printf("%d ", j);
    j++;
}

// Do-While loop
int k = 0;
do {
    printf("%d ", k);
    k++;
} while (k < 5);
```

**Explanation**: `for`, `while`, and `do-while` loops are used for iterative operations. The `for` loop is often used when the number of iterations is known.

---

## **Functions**

### 11. **Defining and Calling Functions**

```c
#include <stdio.h>

void greet() {
    printf("Hello!\n");
}

int add(int a, int b) {
    return a + b;
}

int main() {
    greet();                // Calling a function
    printf("%d\n", add(5, 3));
    return 0;
}
```

**Explanation**: Functions in C can return a value or be `void` (no return). Parameters can be passed as arguments, enabling code reuse.

### 12. **Function Prototypes**

```c
// Function prototype
int add(int, int);

int main() {
    printf("%d\n", add(5, 3));
    return 0;
}

int add(int a, int b) {
    return a + b;
}
```

**Explanation**: Function prototypes declare a function before its actual definition, which helps the compiler recognize it when used in `main`.

---

## **Pointers**

### 13. **Basics of Pointers**

```c
int x = 10;
int *p = &x;  // Pointer to an integer

printf("%d\n", *p);  // Dereferencing pointer to get value of x
```

**Explanation**: `&` gives the memory address, and `*` dereferences the pointer to get the value stored at the address.

### 14. **Pointer Arithmetic**

```c
int arr[] = {10, 20, 30};
int *p = arr;
printf("%d\n", *(p + 1));  // Output: 20
```

**Explanation**: Pointers can be incremented or decremented to navigate through contiguous memory locations, like arrays.

---

## **Arrays**

### 15. **Defining Arrays**

```c
int numbers[5] = {1, 2, 3, 4, 5};
printf("%d\n", numbers[0]);  // Accessing array element
```

**Explanation**: Arrays are used to store multiple values of the same data type. Indexing starts from `0`.

### 16. **Multidimensional Arrays**

```c
int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
printf("%d\n", matrix[1][2]);  // Output: 6
```

**Explanation**: Multi-dimensional arrays are arrays of arrays, useful for representing matrices and grids.

---

## **Strings**

### 17. **String Basics**

```c
char str[] = "Hello";
printf("%s\n", str);
```

**Explanation**: Strings in C are arrays of characters ending with a null terminator (`\0`).

### 18. **String Functions**

```c
#include <string.h>

char str1[] = "Hello";
char str2[] = "World";

int len = strlen(str1);        // Length of string
strcpy(str2, str1);            // Copy string
strcat(str1, str2);            // Concatenate strings
int cmp = strcmp(str1, str2);  // Compare strings
```

**Explanation**: The `<string.h>` library provides functions for string manipulation, such as `strlen`, `strcpy`, `strcat`, and `strcmp`.

---

## **Memory Management**

### 19. **Dynamic Memory Allocation**

```c
#include <stdlib.h>

int *arr = (int*) malloc(5 * sizeof(int));  // Allocate memory
free(arr);                                  // Free memory
```

**Explanation**: `malloc` allocates memory on the heap, and `free` releases it. The allocated memory must be type-casted to the appropriate pointer type.

---

## **Structures and Unions**

### 20. **Defining and Using Structures**

```c
struct Person {
    char name[50];
    int age;
};

struct Person person1;
strcpy(person1.name, "Alice");
person1.age = 25;
printf("%s is %d years old.\n", person1.name, person1.age);
```

**Explanation**: `struct` allows grouping different data types. You can access structure members using the dot (`.`) operator.

### 21. **Unions**

```c
union Data {
    int i;
    float f;
    char str[20];
};

union Data data;
data.i = 10;
data.f = 2.5f;
strcpy(data.str, "Hello");
```

**Explanation**: Unions store different data types in the same memory location, meaning only one member holds a value at any time.

---

## **File Handling**

### 22. **File Operations**

```c
#include <stdio.h>

FILE *file = fopen("example.txt", "w"); // Open file for writing
fprintf(file, "Hello, file!\n");        // Write to file
fclose(file);                           // Close file
```

**

Explanation**: `fopen` opens a file in specified mode (like `"w"` for writing), `fprintf` writes data, and `fclose` closes the file.

---

## **Preprocessor Directives**

### 23. **Basic Preprocessor Directives**

```c
#define PI 3.14       // Constant macro
#include <stdio.h>    // Library inclusion
#undef PI             // Undefine macro
```

**Explanation**: Preprocessor directives, starting with `#`, are instructions for the compiler. Common ones include `#define`, `#include`, and `#undef`.

### 24. **Conditional Compilation**

```c
#ifdef DEBUG
    printf("Debug mode\n");
#endif
```

**Explanation**: `#ifdef`, `#ifndef`, and `#endif` conditionally include or exclude code during compilation, often used for debugging or platform-specific code.

---

## **Error Handling**

### 25. **Error Handling with `errno`**

```c
#include <errno.h>
#include <string.h>

FILE *file = fopen("nonexistent.txt", "r");
if (file == NULL) {
    printf("Error: %s\n", strerror(errno));
}
```

**Explanation**: `errno` is a global variable that stores the error code for system-level errors, and `strerror` gives a readable error message.

---

This cheat sheet should provide a quick reference for understanding and writing C programs efficiently. Regular practice with these commands and concepts will help you gain fluency in C programming.
