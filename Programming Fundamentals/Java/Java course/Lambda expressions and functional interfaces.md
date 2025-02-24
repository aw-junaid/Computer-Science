**Lambda expressions** and **functional interfaces** are key features introduced in Java 8 that enable functional programming in Java. They allow you to write concise and expressive code by treating functionality as a method argument or creating anonymous functions. Let’s explore these concepts in detail.

---

### **1. Lambda Expressions**
A lambda expression is a concise way to represent an anonymous function (a function without a name). It consists of:
- A **parameter list**.
- An **arrow token** (`->`).
- A **body** (expression or block of code).

#### **Syntax**:
```java
(parameters) -> expression
```
or
```java
(parameters) -> { statements; }
```

#### **Example**:
```java
// Traditional anonymous class
Runnable runnable = new Runnable() {
    @Override
    public void run() {
        System.out.println("Hello, World!");
    }
};

// Equivalent lambda expression
Runnable runnable = () -> System.out.println("Hello, World!");
```

---

### **2. Functional Interfaces**
A **functional interface** is an interface with exactly one abstract method. Lambda expressions can be used to provide the implementation of this method.

#### **Key Points**:
- Functional interfaces can have default and static methods.
- The `@FunctionalInterface` annotation ensures that the interface has only one abstract method.

#### **Example**:
```java
@FunctionalInterface
interface Greeting {
    void greet(String name);
}

public class Main {
    public static void main(String[] args) {
        // Lambda expression to implement the greet method
        Greeting greeting = (name) -> System.out.println("Hello, " + name);
        greeting.greet("Alice"); // Hello, Alice
    }
}
```

---

### **3. Built-in Functional Interfaces**
Java 8 introduced several built-in functional interfaces in the `java.util.function` package. Some commonly used ones are:

#### **a. `Consumer<T>`**
- Represents an operation that accepts a single input and returns no result.
- Method: `void accept(T t)`

#### **Example**:
```java
import java.util.function.Consumer;

public class Main {
    public static void main(String[] args) {
        Consumer<String> print = (s) -> System.out.println(s);
        print.accept("Hello, World!"); // Hello, World!
    }
}
```

#### **b. `Supplier<T>`**
- Represents a supplier of results.
- Method: `T get()`

#### **Example**:
```java
import java.util.function.Supplier;

public class Main {
    public static void main(String[] args) {
        Supplier<String> supply = () -> "Hello, World!";
        System.out.println(supply.get()); // Hello, World!
    }
}
```

#### **c. `Function<T, R>`**
- Represents a function that accepts one argument and produces a result.
- Method: `R apply(T t)`

#### **Example**:
```java
import java.util.function.Function;

public class Main {
    public static void main(String[] args) {
        Function<String, Integer> length = (s) -> s.length();
        System.out.println(length.apply("Hello")); // 5
    }
}
```

#### **d. `Predicate<T>`**
- Represents a boolean-valued function of one argument.
- Method: `boolean test(T t)`

#### **Example**:
```java
import java.util.function.Predicate;

public class Main {
    public static void main(String[] args) {
        Predicate<String> isLong = (s) -> s.length() > 5;
        System.out.println(isLong.test("Hello")); // false
        System.out.println(isLong.test("Hello, World!")); // true
    }
}
```

---

### **4. Method References**
Method references provide a way to refer to methods or constructors without invoking them. They are shorthand for lambda expressions that call a specific method.

#### **Types of Method References**:
1. **Static Method Reference**: `ClassName::staticMethod`
2. **Instance Method Reference**: `instance::instanceMethod`
3. **Constructor Reference**: `ClassName::new`

#### **Example**:
```java
import java.util.function.Function;

public class Main {
    public static void main(String[] args) {
        // Static method reference
        Function<String, Integer> length = String::length;
        System.out.println(length.apply("Hello")); // 5

        // Instance method reference
        String str = "Hello, World!";
        Function<Integer, Character> charAt = str::charAt;
        System.out.println(charAt.apply(7)); // W

        // Constructor reference
        Function<String, Integer> toInt = Integer::new;
        System.out.println(toInt.apply("123")); // 123
    }
}
```

---

### **5. Example Program**
Here’s a complete example demonstrating lambda expressions, functional interfaces, and method references:

```java
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.function.Supplier;

public class Main {
    public static void main(String[] args) {
        // Lambda expression with Consumer
        Consumer<String> print = (s) -> System.out.println(s);
        print.accept("Hello, World!"); // Hello, World!

        // Lambda expression with Supplier
        Supplier<String> supply = () -> "Hello, World!";
        System.out.println(supply.get()); // Hello, World!

        // Lambda expression with Function
        Function<String, Integer> length = (s) -> s.length();
        System.out.println(length.apply("Hello")); // 5

        // Lambda expression with Predicate
        Predicate<String> isLong = (s) -> s.length() > 5;
        System.out.println(isLong.test("Hello")); // false
        System.out.println(isLong.test("Hello, World!")); // true

        // Method reference with Function
        Function<String, Integer> lengthRef = String::length;
        System.out.println(lengthRef.apply("Hello")); // 5
    }
}
```
**Output**:
```
Hello, World!
Hello, World!
5
false
true
5
```

---

### **6. Conclusion**
Lambda expressions and functional interfaces are powerful features in Java that enable functional programming and make code more concise and expressive. By understanding these concepts, you can write cleaner, more maintainable code and leverage the full potential of Java’s functional programming capabilities. Whether you're working with collections, streams, or custom logic, lambda expressions and functional interfaces are essential tools in your Java programming toolkit.
