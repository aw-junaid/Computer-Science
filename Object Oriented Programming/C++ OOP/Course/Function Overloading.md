### **Function Overloading in C++**

**Function overloading** in C++ allows multiple functions to have the same name but with different **parameters** (either in the number of parameters, the types of parameters, or both). This enables you to create functions that perform similar tasks but with different input.

#### **Key Points About Function Overloading:**
1. **Same Function Name**: All overloaded functions must have the same function name.
2. **Different Signatures**: The functions must differ in their **parameter types**, **number of parameters**, or both.
3. **Return Type**: Function overloading does **not** depend on the return type. Overloading by return type alone will result in a compilation error.
4. **Best Match**: The compiler selects the most appropriate overloaded function based on the arguments passed during the function call.

---

### **Syntax of Function Overloading**

```cpp
return_type function_name(parameter_list);
```

- The parameter list must be different between overloaded functions, either in the number of parameters or their types.

#### **Example: Function Overloading**

```cpp
#include <iostream>
using namespace std;

class Calculator {
public:
    // Overloaded function to add two integers
    int add(int a, int b) {
        return a + b;
    }

    // Overloaded function to add three integers
    int add(int a, int b, int c) {
        return a + b + c;
    }

    // Overloaded function to add two double values
    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Calculator calc;

    cout << "Sum of 2 integers: " << calc.add(10, 20) << endl;
    cout << "Sum of 3 integers: " << calc.add(10, 20, 30) << endl;
    cout << "Sum of 2 doubles: " << calc.add(10.5, 20.5) << endl;

    return 0;
}
```

**Output**:
```
Sum of 2 integers: 30
Sum of 3 integers: 60
Sum of 2 doubles: 31
```

**Explanation**:
- **`add(int, int)`** adds two integers.
- **`add(int, int, int)`** adds three integers.
- **`add(double, double)`** adds two double values.
- Each overloaded `add` function has a different signature based on the number and type of parameters.

---

### **Overloading Based on Number of Parameters**

You can overload a function by changing the number of parameters:

```cpp
#include <iostream>
using namespace std;

void display(int x) {
    cout << "Integer: " << x << endl;
}

void display(double x) {
    cout << "Double: " << x << endl;
}

void display(int x, double y) {
    cout << "Integer and Double: " << x << " " << y << endl;
}

int main() {
    display(10);      // Calls display(int)
    display(10.5);    // Calls display(double)
    display(10, 20.5); // Calls display(int, double)

    return 0;
}
```

**Output**:
```
Integer: 10
Double: 10.5
Integer and Double: 10 20.5
```

---

### **Overloading Based on Parameter Types**

You can also overload a function by changing the types of its parameters:

```cpp
#include <iostream>
using namespace std;

class Printer {
public:
    // Overloaded function for integer
    void print(int x) {
        cout << "Printing integer: " << x << endl;
    }

    // Overloaded function for string
    void print(string str) {
        cout << "Printing string: " << str << endl;
    }

    // Overloaded function for character
    void print(char c) {
        cout << "Printing character: " << c << endl;
    }
};

int main() {
    Printer p;
    p.print(10);       // Calls print(int)
    p.print("Hello");  // Calls print(string)
    p.print('A');      // Calls print(char)

    return 0;
}
```

**Output**:
```
Printing integer: 10
Printing string: Hello
Printing character: A
```

---

### **Overloading with Default Arguments**

In C++, you can also overload functions using **default arguments**. This means a function can have a default value for some of its parameters, and if these values are not provided when calling the function, the default value is used.

```cpp
#include <iostream>
using namespace std;

class Printer {
public:
    // Function with default argument
    void print(int x, string str = "Default") {
        cout << "Printing: " << x << " " << str << endl;
    }
};

int main() {
    Printer p;
    p.print(10);               // Calls print(int, string) with default string
    p.print(10, "Hello");      // Calls print(int, string) with custom string

    return 0;
}
```

**Output**:
```
Printing: 10 Default
Printing: 10 Hello
```

---

### **Rules of Function Overloading**

1. **Function Overloading is Determined at Compile Time**:
   - The compiler decides which function to call based on the arguments passed at compile time. This is known as **static polymorphism**.
   
2. **Return Type Does Not Count**:
   - You cannot overload functions solely by their return type. The parameter list must be different.

3. **Ambiguity**:
   - If two overloaded functions are too similar (e.g., if you have two functions that could match the same set of arguments), the compiler will throw an **ambiguity error**.
   - Example of ambiguity:
     ```cpp
     void func(int x);
     void func(double x);
     func(10);   // Error: ambiguity because both int and double match the argument
     ```

---

### **Advantages of Function Overloading**
1. **Readability**: Function overloading allows you to use the same name for different functionalities, which can make the code more readable and easier to understand.
2. **Code Reusability**: You can define multiple functions for similar tasks without changing function names.
3. **Improved Maintainability**: Since function names remain the same, it reduces the number of function names you need to remember, simplifying maintenance.

---

### **Conclusion**

- **Function overloading** is a powerful feature in C++ that allows you to use the same function name for different functionalities, depending on the type or number of parameters.
- It enhances code readability and maintainability but requires careful attention to function signatures to avoid ambiguity.

