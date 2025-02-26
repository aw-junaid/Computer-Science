### **Introduction to Lambda Expressions**

**Lambda expressions** are one of the most significant features introduced in **Java 8**. They provide a clear and concise way to represent **anonymous functions** (functions without a name) and enable functional programming in Java. Lambda expressions are primarily used to implement **functional interfaces** (interfaces with a single abstract method).

---

### **Key Features of Lambda Expressions**

1. **Concise Syntax**:
   - Lambda expressions reduce boilerplate code by eliminating the need for anonymous inner classes.

2. **Functional Interfaces**:
   - Lambda expressions can be used to implement functional interfaces.

3. **Type Inference**:
   - The Java compiler can infer the types of parameters in lambda expressions.

4. **Method References**:
   - Lambda expressions can be replaced with method references for even more concise code.

---

### **Syntax of Lambda Expressions**

The general syntax of a lambda expression is:
```java
(parameters) -> expression
```
or
```java
(parameters) -> { statements; }
```

- **Parameters**: The input parameters for the lambda expression.
- **Arrow (`->`)**: Separates the parameters from the body.
- **Body**: The implementation of the lambda expression (can be a single expression or a block of code).

---

### **Example: Lambda Expressions**

#### **1. Implementing a Functional Interface**

A functional interface is an interface with a single abstract method (SAM). Lambda expressions can be used to implement such interfaces.

```java
@FunctionalInterface
interface MyFunctionalInterface {
    void myMethod();
}

public class LambdaExample {
    public static void main(String[] args) {
        // Using a lambda expression to implement the functional interface
        MyFunctionalInterface obj = () -> System.out.println("Hello, Lambda!");
        obj.myMethod();
    }
}
```

---

#### **2. Lambda with Parameters**

Lambda expressions can take parameters.

```java
@FunctionalInterface
interface MathOperation {
    int operate(int a, int b);
}

public class LambdaExample {
    public static void main(String[] args) {
        // Lambda expression with parameters
        MathOperation addition = (a, b) -> a + b;
        System.out.println("Addition: " + addition.operate(5, 3));

        MathOperation subtraction = (a, b) -> a - b;
        System.out.println("Subtraction: " + subtraction.operate(5, 3));
    }
}
```

---

#### **3. Lambda with Multiple Statements**

If the lambda body contains multiple statements, use curly braces `{}`.

```java
@FunctionalInterface
interface StringProcessor {
    String process(String str);
}

public class LambdaExample {
    public static void main(String[] args) {
        // Lambda expression with multiple statements
        StringProcessor processor = (str) -> {
            String result = str.toUpperCase();
            return "Processed: " + result;
        };

        System.out.println(processor.process("hello"));
    }
}
```

---

### **Functional Interfaces in Java 8**

Java 8 introduced several built-in functional interfaces in the `java.util.function` package. Some commonly used ones include:

| Interface            | Method Signature       | Description                                  |
|----------------------|------------------------|----------------------------------------------|
| `Consumer<T>`        | `void accept(T t)`     | Accepts a single input and returns no result.|
| `Supplier<T>`        | `T get()`              | Supplies a result of type `T`.               |
| `Function<T, R>`     | `R apply(T t)`         | Accepts an input of type `T` and returns `R`.|
| `Predicate<T>`       | `boolean test(T t)`    | Tests a condition on an input of type `T`.   |

---

#### **Example: Using Built-in Functional Interfaces**

```java
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.function.Supplier;

public class FunctionalInterfaceExample {
    public static void main(String[] args) {
        // Consumer example
        Consumer<String> printMessage = (message) -> System.out.println("Message: " + message);
        printMessage.accept("Hello, Consumer!");

        // Supplier example
        Supplier<Double> randomValue = () -> Math.random();
        System.out.println("Random Value: " + randomValue.get());

        // Function example
        Function<String, Integer> stringLength = (str) -> str.length();
        System.out.println("Length of 'Java': " + stringLength.apply("Java"));

        // Predicate example
        Predicate<Integer> isEven = (num) -> num % 2 == 0;
        System.out.println("Is 4 even? " + isEven.test(4));
    }
}
```

---

### **Method References**

Method references provide a way to refer to methods without invoking them. They are a shorthand notation for lambda expressions.

#### **Types of Method References**
1. **Static Method Reference**: `ClassName::staticMethod`
2. **Instance Method Reference**: `instance::instanceMethod`
3. **Constructor Reference**: `ClassName::new`

---

#### **Example: Method References**

```java
import java.util.function.Function;

public class MethodReferenceExample {
    public static void main(String[] args) {
        // Static method reference
        Function<String, Integer> stringLength = String::length;
        System.out.println("Length of 'Java': " + stringLength.apply("Java"));

        // Instance method reference
        String str = "Hello";
        Function<String, String> toUpperCase = str::toUpperCase;
        System.out.println("Uppercase: " + toUpperCase.apply("world"));

        // Constructor reference
        Function<String, Integer> parseInt = Integer::new;
        System.out.println("Parsed Integer: " + parseInt.apply("123"));
    }
}
```

---

### **Best Practices**

1. **Use Lambda Expressions for Concise Code**:
   - Replace anonymous inner classes with lambda expressions for cleaner code.

2. **Leverage Built-in Functional Interfaces**:
   - Use interfaces from `java.util.function` for common use cases.

3. **Use Method References**:
   - Replace lambda expressions with method references when possible for better readability.

4. **Avoid Overusing Lambdas**:
   - Use lambda expressions judiciously to maintain code readability.

5. **Test Lambda Expressions**:
   - Ensure that lambda expressions are tested thoroughly, especially in complex scenarios.

---

### **Example: Combining Lambda Expressions and Streams**

Lambda expressions are often used with the **Stream API** introduced in Java 8 for processing collections.

```java
import java.util.Arrays;
import java.util.List;

public class StreamExample {
    public static void main(String[] args) {
        List<String> names = Arrays.asList("Alice", "Bob", "Charlie", "David");

        // Use lambda expressions with streams
        names.stream()
             .filter(name -> name.startsWith("C")) // Filter names starting with "C"
             .map(String::toUpperCase)             // Convert to uppercase
             .forEach(System.out::println);        // Print each name
    }
}
```

---

By mastering lambda expressions, you can write more concise, readable, and functional code in Java. They are a powerful tool for modern Java development and are widely used in frameworks like Spring and libraries like Stream API.
