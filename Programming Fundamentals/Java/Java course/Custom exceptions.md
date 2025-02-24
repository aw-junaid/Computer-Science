**Custom exceptions** in Java allow you to define your own exception types to handle specific errors in your application. By creating custom exceptions, you can provide more meaningful error messages and handle exceptional cases in a way that makes sense for your program. Let’s explore how to create and use custom exceptions in Java.

---

### **1. Why Use Custom Exceptions?**
- **Specific Error Handling**: Custom exceptions allow you to handle specific errors in a way that is relevant to your application.
- **Improved Readability**: Custom exceptions make your code more readable and maintainable by providing meaningful error messages.
- **Better Control**: You can add additional fields, methods, or constructors to your custom exceptions to provide more context about the error.

---

### **2. Creating a Custom Exception**
To create a custom exception, you need to extend the `Exception` class (for checked exceptions) or the `RuntimeException` class (for unchecked exceptions).

#### **Syntax**:
```java
class CustomException extends Exception {
    // Constructors
    public CustomException(String message) {
        super(message);
    }
}
```

---

### **3. Example of a Custom Exception**
Let’s create a custom exception called `InvalidAgeException` that is thrown when an invalid age is provided.

#### **Step 1: Define the Custom Exception**:
```java
class InvalidAgeException extends Exception {
    // Constructor
    public InvalidAgeException(String message) {
        super(message);
    }
}
```

#### **Step 2: Use the Custom Exception**:
```java
class Voter {
    public void validateAge(int age) throws InvalidAgeException {
        if (age < 18) {
            throw new InvalidAgeException("Age must be 18 or older.");
        } else {
            System.out.println("Valid age. You can vote!");
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Voter voter = new Voter();
        try {
            voter.validateAge(15); // Throws InvalidAgeException
        } catch (InvalidAgeException e) {
            System.out.println("Exception caught: " + e.getMessage());
        }
    }
}
```
**Output**:
```
Exception caught: Age must be 18 or older.
```

---

### **4. Adding Additional Fields and Methods**
You can add additional fields and methods to your custom exception to provide more context about the error.

#### **Example**:
```java
class InvalidAgeException extends Exception {
    private int age;

    // Constructor
    public InvalidAgeException(String message, int age) {
        super(message);
        this.age = age;
    }

    // Getter for age
    public int getAge() {
        return age;
    }
}

class Voter {
    public void validateAge(int age) throws InvalidAgeException {
        if (age < 18) {
            throw new InvalidAgeException("Age must be 18 or older. Provided age: " + age, age);
        } else {
            System.out.println("Valid age. You can vote!");
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Voter voter = new Voter();
        try {
            voter.validateAge(15); // Throws InvalidAgeException
        } catch (InvalidAgeException e) {
            System.out.println("Exception caught: " + e.getMessage());
            System.out.println("Provided age: " + e.getAge());
        }
    }
}
```
**Output**:
```
Exception caught: Age must be 18 or older. Provided age: 15
Provided age: 15
```

---

### **5. Custom Unchecked Exception**
If you want to create a custom unchecked exception, extend the `RuntimeException` class instead of `Exception`.

#### **Example**:
```java
class InvalidInputException extends RuntimeException {
    // Constructor
    public InvalidInputException(String message) {
        super(message);
    }
}

class Calculator {
    public int divide(int a, int b) {
        if (b == 0) {
            throw new InvalidInputException("Divisor cannot be zero.");
        }
        return a / b;
    }
}

public class Main {
    public static void main(String[] args) {
        Calculator calculator = new Calculator();
        try {
            int result = calculator.divide(10, 0); // Throws InvalidInputException
            System.out.println("Result: " + result);
        } catch (InvalidInputException e) {
            System.out.println("Exception caught: " + e.getMessage());
        }
    }
}
```
**Output**:
```
Exception caught: Divisor cannot be zero.
```

---

### **6. Best Practices**
1. **Use Meaningful Names**: Name your custom exceptions in a way that clearly describes the error.
2. **Provide Constructors**: Include constructors that allow you to pass error messages and additional context.
3. **Extend the Right Class**: Use `Exception` for checked exceptions and `RuntimeException` for unchecked exceptions.
4. **Add Context**: Include additional fields or methods to provide more information about the error.

---

### **7. Example Program**
Here’s a complete example demonstrating custom exceptions with additional fields and methods:

```java
// Custom checked exception
class InvalidAgeException extends Exception {
    private int age;

    // Constructor
    public InvalidAgeException(String message, int age) {
        super(message);
        this.age = age;
    }

    // Getter for age
    public int getAge() {
        return age;
    }
}

// Custom unchecked exception
class InvalidInputException extends RuntimeException {
    // Constructor
    public InvalidInputException(String message) {
        super(message);
    }
}

class Voter {
    public void validateAge(int age) throws InvalidAgeException {
        if (age < 18) {
            throw new InvalidAgeException("Age must be 18 or older. Provided age: " + age, age);
        } else {
            System.out.println("Valid age. You can vote!");
        }
    }
}

class Calculator {
    public int divide(int a, int b) {
        if (b == 0) {
            throw new InvalidInputException("Divisor cannot be zero.");
        }
        return a / b;
    }
}

public class Main {
    public static void main(String[] args) {
        // Using custom checked exception
        Voter voter = new Voter();
        try {
            voter.validateAge(15); // Throws InvalidAgeException
        } catch (InvalidAgeException e) {
            System.out.println("Exception caught: " + e.getMessage());
            System.out.println("Provided age: " + e.getAge());
        }

        // Using custom unchecked exception
        Calculator calculator = new Calculator();
        try {
            int result = calculator.divide(10, 0); // Throws InvalidInputException
            System.out.println("Result: " + result);
        } catch (InvalidInputException e) {
            System.out.println("Exception caught: " + e.getMessage());
        }
    }
}
```
**Output**:
```
Exception caught: Age must be 18 or older. Provided age: 15
Provided age: 15
Exception caught: Divisor cannot be zero.
```

---

### **Conclusion**
Custom exceptions in Java allow you to handle specific errors in a way that is meaningful for your application. By creating custom exceptions, you can provide more context about errors, improve code readability, and ensure that your programs handle exceptional cases gracefully. Whether you're working with checked or unchecked exceptions, custom exceptions are a powerful tool for building robust and maintainable Java applications.
