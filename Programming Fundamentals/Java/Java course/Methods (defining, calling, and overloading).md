In Java, **methods** are blocks of code that perform a specific task. They are defined within a class and can be called to execute their functionality. Methods help in organizing code, improving reusability, and making programs easier to understand. Let’s explore how to define, call, and overload methods in Java.

---

### **1. Defining Methods**
A method is defined with a name, a return type, parameters (optional), and a body.

#### **Syntax**:
```java
returnType methodName(parameterList) {
    // Method body
    return value; // Optional (if returnType is not void)
}
```
- **`returnType`**: The data type of the value returned by the method. Use `void` if the method does not return a value.
- **`methodName`**: The name of the method (should follow Java naming conventions).
- **`parameterList`**: A comma-separated list of parameters (optional).
- **`return`**: Used to return a value (if the return type is not `void`).

#### **Example**:
```java
class Calculator {
    // Method to add two numbers
    int add(int a, int b) {
        return a + b;
    }

    // Method to display a message
    void displayMessage(String message) {
        System.out.println(message);
    }
}
```

---

### **2. Calling Methods**
To call a method, use the method name followed by parentheses `()` and pass the required arguments (if any).

#### **Syntax**:
```java
objectName.methodName(arguments);
```
- **`objectName`**: The object of the class containing the method (for instance methods).
- **`methodName`**: The name of the method.
- **`arguments`**: The values passed to the method (if any).

#### **Example**:
```java
public class Main {
    public static void main(String[] args) {
        Calculator calc = new Calculator();

        // Call the add method
        int result = calc.add(5, 10);
        System.out.println("Sum: " + result);

        // Call the displayMessage method
        calc.displayMessage("Hello, Java!");
    }
}
```
**Output**:
```
Sum: 15
Hello, Java!
```

---

### **3. Method Overloading**
Method overloading allows you to define multiple methods with the same name but different parameter lists (different number or types of parameters). The correct method is chosen based on the arguments passed during the method call.

#### **Rules for Method Overloading**:
1. Methods must have the same name.
2. Methods must have different parameter lists (different number or types of parameters).
3. The return type can be the same or different (return type alone is not sufficient for overloading).

#### **Example**:
```java
class Calculator {
    // Method to add two integers
    int add(int a, int b) {
        return a + b;
    }

    // Overloaded method to add three integers
    int add(int a, int b, int c) {
        return a + b + c;
    }

    // Overloaded method to add two doubles
    double add(double a, double b) {
        return a + b;
    }
}
```

#### **Calling Overloaded Methods**:
```java
public class Main {
    public static void main(String[] args) {
        Calculator calc = new Calculator();

        // Call the add method with two integers
        int result1 = calc.add(5, 10);
        System.out.println("Sum (int): " + result1);

        // Call the add method with three integers
        int result2 = calc.add(5, 10, 15);
        System.out.println("Sum (int): " + result2);

        // Call the add method with two doubles
        double result3 = calc.add(5.5, 10.5);
        System.out.println("Sum (double): " + result3);
    }
}
```
**Output**:
```
Sum (int): 15
Sum (int): 30
Sum (double): 16.0
```

---

### **4. Static Methods**
Static methods belong to the class rather than an instance of the class. They can be called using the class name.

#### **Syntax**:
```java
class ClassName {
    static returnType methodName(parameterList) {
        // Method body
    }
}
```

#### **Example**:
```java
class MathUtils {
    // Static method to calculate square
    static int square(int num) {
        return num * num;
    }
}
```

#### **Calling Static Methods**:
```java
public class Main {
    public static void main(String[] args) {
        // Call the static method using the class name
        int result = MathUtils.square(5);
        System.out.println("Square: " + result);
    }
}
```
**Output**:
```
Square: 25
```

---

### **5. Best Practices**
1. **Use Descriptive Names**: Choose meaningful names for methods that describe their purpose.
2. **Keep Methods Short**: Methods should perform a single task and be easy to understand.
3. **Avoid Overloading Confusion**: Ensure overloaded methods have clearly distinct parameter lists.
4. **Use Static Methods Wisely**: Use static methods for utility functions that don’t depend on instance variables.

---

### **6. Example Program**
Here’s a complete example demonstrating method definition, calling, and overloading:

```java
class Calculator {
    // Method to add two integers
    int add(int a, int b) {
        return a + b;
    }

    // Overloaded method to add three integers
    int add(int a, int b, int c) {
        return a + b + c;
    }

    // Overloaded method to add two doubles
    double add(double a, double b) {
        return a + b;
    }

    // Static method to multiply two numbers
    static int multiply(int a, int b) {
        return a * b;
    }
}

public class Main {
    public static void main(String[] args) {
        Calculator calc = new Calculator();

        // Call the add method with two integers
        int result1 = calc.add(5, 10);
        System.out.println("Sum (int): " + result1);

        // Call the add method with three integers
        int result2 = calc.add(5, 10, 15);
        System.out.println("Sum (int): " + result2);

        // Call the add method with two doubles
        double result3 = calc.add(5.5, 10.5);
        System.out.println("Sum (double): " + result3);

        // Call the static multiply method
        int result4 = Calculator.multiply(5, 10);
        System.out.println("Product: " + result4);
    }
}
```
**Output**:
```
Sum (int): 15
Sum (int): 30
Sum (double): 16.0
Product: 50
```

---

### **Conclusion**
Methods are a fundamental part of Java programming. By defining, calling, and overloading methods, you can write modular, reusable, and efficient code. Whether you're performing calculations, displaying messages, or organizing logic, methods are essential tools for building robust Java applications. 🚀
