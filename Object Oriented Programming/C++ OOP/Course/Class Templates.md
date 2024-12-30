### **Class Templates in C++**

A **class template** in C++ is similar to a **function template**, but instead of defining a generic function, you define a **generic class** that can work with any data type. Class templates allow you to create classes that can handle objects of different data types without having to write a separate class for each data type.

### **What is a Class Template?**

A **class template** is a blueprint for creating classes that can work with any data type. You can define member variables, functions, and even constructors for a class template, just like you would for a regular class. When you instantiate a class template, the compiler generates the appropriate class code for the specific data type that you provide.

### **Syntax of Class Template**

The general syntax for defining a class template is as follows:

```cpp
template <typename T>
class ClassName {
    // Member variables and functions using the type T
};
```

- `template`: Indicates that we are defining a template.
- `typename T`: Declares a template parameter `T` which represents a generic type that will be used in place of a specific type.
- `ClassName`: The name of the class template.
- The class can have **member functions**, **member variables**, and even **constructors** using the generic type `T`.

### **Example of a Simple Class Template**

```cpp
#include <iostream>
using namespace std;

// Class template for a simple pair
template <typename T>
class Pair {
private:
    T first;
    T second;

public:
    // Constructor
    Pair(T a, T b) : first(a), second(b) {}

    // Function to get the first element
    T getFirst() { return first; }

    // Function to get the second element
    T getSecond() { return second; }
};

int main() {
    // Creating objects of Pair with different data types
    Pair<int> intPair(10, 20);
    Pair<double> doublePair(3.14, 2.71);

    cout << "First integer: " << intPair.getFirst() << ", Second integer: " << intPair.getSecond() << endl;
    cout << "First double: " << doublePair.getFirst() << ", Second double: " << doublePair.getSecond() << endl;

    return 0;
}
```

### **Explanation**:
- The `Pair` class template is defined with a generic type `T`. This type is used for both `first` and `second` data members.
- In `main()`, we create two `Pair` objects:
  - One with `int` as the template argument.
  - One with `double` as the template argument.
- The class template works with both `int` and `double` types, generating the appropriate class code for each type when the objects are created.

### **Class Template with Multiple Parameters**

A class template can accept multiple type parameters, allowing you to create classes that work with more than one data type.

#### **Example of Class Template with Multiple Parameters**:

```cpp
#include <iostream>
using namespace std;

// Class template with two parameters
template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    // Constructor
    Pair(T1 a, T2 b) : first(a), second(b) {}

    // Function to get the first element
    T1 getFirst() { return first; }

    // Function to get the second element
    T2 getSecond() { return second; }
};

int main() {
    // Creating objects with different types for the pair
    Pair<int, double> intDoublePair(10, 3.14);
    Pair<string, int> stringIntPair("Age", 30);

    cout << "First (int, double): " << intDoublePair.getFirst() << ", " << intDoublePair.getSecond() << endl;
    cout << "First (string, int): " << stringIntPair.getFirst() << ", " << stringIntPair.getSecond() << endl;

    return 0;
}
```

### **Explanation**:
- The `Pair` class template now accepts two type parameters: `T1` and `T2`, allowing you to store different types for `first` and `second` in each object.
- We create two objects:
  - One with `int` and `double` types.
  - One with `string` and `int` types.

### **Class Template Specialization**

Just like function templates, you can **specialize** class templates for specific types. Template specialization allows you to define a different implementation for a particular type.

#### **Example of Class Template Specialization**:

```cpp
#include <iostream>
using namespace std;

// General template
template <typename T>
class Box {
private:
    T value;

public:
    Box(T v) : value(v) {}

    void show() {
        cout << "Value: " << value << endl;
    }
};

// Specialization for type 'char'
template <>
class Box<char> {
private:
    char value;

public:
    Box(char v) : value(v) {}

    void show() {
        cout << "Character: " << value << endl;
    }
};

int main() {
    Box<int> intBox(10);
    Box<double> doubleBox(3.14);
    Box<char> charBox('A');

    intBox.show();    // For int type
    doubleBox.show(); // For double type
    charBox.show();   // For char type (specialized)

    return 0;
}
```

### **Explanation**:
- The `Box` class template is specialized for the `char` type. The specialized version of `Box<char>` has a different `show()` function.
- The template is used with `int`, `double`, and `char`, and the appropriate version of `show()` is called for each type.

### **Default Template Parameters**

You can provide **default values** for template parameters in class templates, which will be used unless a specific type is provided.

#### **Example of Default Template Parameters**:

```cpp
#include <iostream>
using namespace std;

// Class template with default type
template <typename T = int>
class Box {
private:
    T value;

public:
    Box(T v) : value(v) {}

    void show() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Box<> defaultBox(100);  // Default type 'int'
    Box<double> doubleBox(3.14);  // Explicit type 'double'

    defaultBox.show();
    doubleBox.show();

    return 0;
}
```

### **Explanation**:
- In this example, the class template `Box` has a default type of `int`.
- If no type is specified when creating an object (like `Box<>`), the default type (`int`) is used. Otherwise, you can explicitly specify a type (`double` in this case).

### **Member Functions in Class Templates**

Class templates can have **member functions** just like regular classes. You can define member functions that use the generic type `T` and perform operations on them.

#### **Example with Member Functions**:

```cpp
#include <iostream>
using namespace std;

template <typename T>
class Calculator {
private:
    T value;

public:
    // Constructor
    Calculator(T val) : value(val) {}

    // Member function to add
    T add(T num) {
        return value + num;
    }

    // Member function to subtract
    T subtract(T num) {
        return value - num;
    }
};

int main() {
    Calculator<int> intCalc(10);
    Calculator<double> doubleCalc(3.14);

    cout << "Add (int): " << intCalc.add(5) << endl;
    cout << "Subtract (int): " << intCalc.subtract(3) << endl;

    cout << "Add (double): " << doubleCalc.add(2.71) << endl;
    cout << "Subtract (double): " << doubleCalc.subtract(1.14) << endl;

    return 0;
}
```

### **Explanation**:
- The `Calculator` class template has member functions `add()` and `subtract()` that work with the generic type `T`.
- We use the `Calculator` class for both `int` and `double` types.

### **Advantages of Class Templates**

1. **Code Reusability**: Class templates allow you to define a single class that can be used with multiple types, avoiding the need to write similar classes for each type.
2. **Type Safety**: The compiler ensures that type mismatches are caught at compile-time, providing type safety.
3. **Cleaner Code**: Class templates allow you to write generic classes without redundant code for each data type.
4. **Extensibility**: You can specialize class templates for specific types and provide custom behavior.

### **Limitations of Class Templates**

1. **Complexity**: Templates can make the code more difficult to understand, especially when templates are highly specialized or deeply nested.
2. **Compilation Time**: Since templates are instantiated at compile time, they can lead to longer compile times, especially for large and complex templates.
3. **Error Messages**: When templates are used incorrectly, error messages can sometimes be hard to decipher, especially with more complex template structures.

---

### **Conclusion**

Class templates are a powerful feature in C++ that allow you to define classes that can operate with any data type. They promote **code reusability**, **type safety**, and **cleaner code** by allowing you to create generic classes. Class templates can be specialized for specific types and can have default template parameters for convenience. However, they can add complexity to the code and increase compilation time, so they should be used judiciously.

