An extended Java cheat sheet that covers essential commands, syntax, and concepts. This cheat sheet includes data types, control structures, classes, interfaces, exception handling, collections, and more.

---

## **Basic Syntax**

### 1. **Hello World Program**

```java
public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
    }
}
```

**Explanation**: Every Java program starts with a class definition. The `main` method is the entry point, and `System.out.println` is used for printing to the console.

---

## **Data Types**

### 2. **Primitive Data Types**

```java
int a = 10;                  // Integer
float b = 3.14f;            // Float
double c = 3.14159;         // Double
char d = 'A';               // Character
boolean e = true;           // Boolean
```

**Explanation**: Java supports various primitive data types, including integers, floats, doubles, characters, and booleans.

### 3. **Strings**

```java
String str = "Hello";       // String
```

**Explanation**: Strings are objects in Java and can be manipulated using various methods available in the `String` class.

---

## **Control Structures**

### 4. **If-Else Statement**

```java
if (a > 10) {
    System.out.println("Greater than 10");
} else if (a < 10) {
    System.out.println("Less than 10");
} else {
    System.out.println("Equal to 10");
}
```

**Explanation**: Java uses `if`, `else if`, and `else` for conditional branching.

### 5. **Switch Statement**

```java
switch (a) {
    case 1:
        System.out.println("One");
        break;
    case 2:
        System.out.println("Two");
        break;
    default:
        System.out.println("Other");
}
```

**Explanation**: The `switch` statement allows multiple conditions and requires `break` to prevent fall-through.

### 6. **For Loop**

```java
for (int i = 0; i < 5; i++) {
    System.out.println(i);
}

for (int value : array) {      // Enhanced for loop
    System.out.println(value);
}
```

**Explanation**: Java provides traditional `for` loops and enhanced for loops (also known as foreach loops) for iterating over arrays and collections.

---

## **Functions (Methods)**

### 7. **Defining Methods**

```java
public static int add(int a, int b) {
    return a + b;
}
```

**Explanation**: Methods are defined with the `public`, `static`, and return type. They can accept parameters and return a value.

### 8. **Method Overloading**

```java
public static int add(int a, int b) {
    return a + b;
}

public static double add(double a, double b) {
    return a + b;
}
```

**Explanation**: Java supports method overloading, allowing multiple methods with the same name but different parameters.

### 9. **Varargs (Variable Arguments)**

```java
public static int sum(int... numbers) {
    int total = 0;
    for (int num : numbers) {
        total += num;
    }
    return total;
}
```

**Explanation**: Varargs allows a method to accept a variable number of arguments.

---

## **Classes and Objects**

### 10. **Defining a Class**

```java
public class Person {
    String name;
    int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
}
```

**Explanation**: Classes are blueprints for objects and can have fields (attributes) and methods.

### 11. **Creating Objects**

```java
Person person = new Person("Alice", 25);  // Create an instance
```

**Explanation**: Use the `new` keyword to create an instance of a class.

### 12. **Access Modifiers**

```java
public class MyClass {
    private int x;          // Accessible only within MyClass
    protected int y;       // Accessible within the same package or subclasses
    public int z;          // Accessible from anywhere
}
```

**Explanation**: Java uses access modifiers (`public`, `private`, `protected`) to control visibility.

---

## **Inheritance and Interfaces**

### 13. **Inheritance**

```java
public class Animal {
    public void speak() {
        System.out.println("Animal speaks");
    }
}

public class Dog extends Animal {
    @Override
    public void speak() {
        System.out.println("Woof!");
    }
}
```

**Explanation**: Classes can inherit from other classes using the `extends` keyword. The `@Override` annotation indicates that a method is being overridden.

### 14. **Interfaces**

```java
public interface Speaker {
    void speak();
}

public class Cat implements Speaker {
    public void speak() {
        System.out.println("Meow!");
    }
}
```

**Explanation**: Interfaces define a contract that classes can implement. Classes use the `implements` keyword to adhere to an interface.

---

## **Exception Handling**

### 15. **Try-Catch Block**

```java
try {
    int result = 10 / 0;  // This will cause an ArithmeticException
} catch (ArithmeticException e) {
    System.out.println("Cannot divide by zero.");
} finally {
    System.out.println("This block always executes.");
}
```

**Explanation**: Use `try` to wrap code that might throw an exception. `catch` handles specific exceptions, and `finally` executes code regardless of whether an exception occurred.

### 16. **Throwing Exceptions**

```java
public void checkAge(int age) throws Exception {
    if (age < 18) {
        throw new Exception("Age must be at least 18.");
    }
}
```

**Explanation**: Use the `throw` keyword to explicitly throw an exception. Methods that can throw exceptions must declare them using `throws`.

---

## **Collections Framework**

### 17. **Using ArrayList**

```java
import java.util.ArrayList;

ArrayList<String> list = new ArrayList<>();
list.add("Apple");               // Add element
list.add("Banana");
String fruit = list.get(0);      // Access element
```

**Explanation**: `ArrayList` is a resizable array implementation of the List interface. It can hold a dynamic number of elements.

### 18. **Using HashMap**

```java
import java.util.HashMap;

HashMap<String, Integer> map = new HashMap<>();
map.put("Alice", 25);            // Insert key-value pair
int age = map.get("Alice");      // Retrieve value by key
```

**Explanation**: `HashMap` is a key-value pair collection. It allows for fast retrieval based on keys.

---

## **Java Streams (Java 8 and later)**

### 19. **Using Streams**

```java
import java.util.Arrays;

int[] numbers = {1, 2, 3, 4, 5};
Arrays.stream(numbers)
      .filter(n -> n % 2 == 0)      // Filter even numbers
      .forEach(System.out::println); // Print each number
```

**Explanation**: Streams provide a functional approach to processing sequences of elements, allowing operations like filtering and mapping.

---

## **File I/O**

### 20. **Reading and Writing Files**

```java
import java.nio.file.Files;
import java.nio.file.Paths;

try {
    String content = new String(Files.readAllBytes(Paths.get("file.txt")));
    System.out.println(content);
} catch (IOException e) {
    e.printStackTrace();
}
```

**Explanation**: Use `Files` and `Paths` for reading and writing files. Wrap file operations in a `try-catch` block for exception handling.

---

## **Multithreading**

### 21. **Creating Threads**

```java
class MyThread extends Thread {
    public void run() {
        System.out.println("Thread is running");
    }
}

MyThread thread = new MyThread();
thread.start();  // Start the thread
```

**Explanation**: Extend the `Thread` class and override the `run` method to define the thread's behavior. Use `start` to execute the thread.

### 22. **Runnable Interface**

```java
class MyRunnable implements Runnable {
    public void run() {
        System.out.println("Runnable thread is running");
    }
}

Thread thread = new Thread(new MyRunnable());
thread.start();  // Start the thread
```

**Explanation**: Implement the `Runnable` interface for more flexibility in defining thread behavior.

---

## **Annotations**

### 23. **Using Annotations**

```java
@Deprecated
public void oldMethod() {
    // This method is deprecated
}

@FunctionalInterface
public interface MyFunction {
    void execute();
}
```

**Explanation**: Annotations provide metadata about the program elements. `@Deprecated` indicates that a method should not be used, while `@FunctionalInterface` denotes an interface intended to have a single abstract method.

---

## **Java Generics**

### 24. **Using Generics**

```java
public class Box<T> {
    private T item;

    public void setItem(T item) {
        this.item = item;
    }

    public T getItem() {
        return item;
    }
}

Box<String> box = new Box<>();
box.setItem("Hello");
String value = box.getItem();   // Type-safe retrieval
``

`

**Explanation**: Generics enable types (classes and interfaces) to be parameters when defining classes, interfaces, and methods, allowing for stronger type checks at compile time.

---

## **Conclusion**

This cheat sheet provides a comprehensive overview of essential commands and concepts in Java. Regular practice with these concepts will help you become proficient in Java programming.
