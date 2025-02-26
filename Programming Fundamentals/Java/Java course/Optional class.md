### **`Optional` Class in Java**
The `Optional<T>` class in Java was introduced in **Java 8** to handle **null values** safely and avoid `NullPointerException (NPE)`. It helps in writing cleaner and more readable code when dealing with values that **may or may not be present**.

---

## **Why Use `Optional`?**
- **Avoids `null` checks**: No need for manual `if (obj != null)` checks.
- **Prevents `NullPointerException`**: Provides a safe way to handle missing values.
- **Encourages Functional Programming**: Works well with Streams and Lambdas.
- **Improves Code Readability**: Clearly indicates that a value may be absent.

---

## **Creating an `Optional` Object**
There are several ways to create an `Optional` instance:

### **1. `Optional.of(value)`** (Throws an exception if value is `null`)
```java
import java.util.Optional;

public class OptionalExample {
    public static void main(String[] args) {
        Optional<String> optionalName = Optional.of("Komugi");
        System.out.println(optionalName.get()); // Output: Komugi
    }
}
```
> 🚨 **Warning:** If you pass `null` to `Optional.of(null)`, it will throw a `NullPointerException`.

---

### **2. `Optional.ofNullable(value)`** (Allows `null` values)
```java
Optional<String> optionalName = Optional.ofNullable(null); // No exception
```
- If `value` is **not null**, `Optional.ofNullable(value)` returns `Optional.of(value)`.
- If `value` is **null**, it returns `Optional.empty()`.

---

### **3. `Optional.empty()`** (Creates an empty `Optional`)
```java
Optional<String> emptyOptional = Optional.empty();
```
- Represents an **absent value** without using `null`.

---

## **Checking if a Value is Present**
### **1. `isPresent()`**
Checks if an `Optional` contains a value.
```java
Optional<String> optional = Optional.ofNullable("Hello");
if (optional.isPresent()) {
    System.out.println(optional.get()); // Output: Hello
}
```

---

### **2. `ifPresent(Consumer<T>)`**
Executes a function if a value is present.
```java
Optional<String> optional = Optional.of("Komugi");
optional.ifPresent(name -> System.out.println("Hello, " + name)); 
// Output: Hello, Komugi
```
- If `optional` is empty, nothing happens.

---

## **Providing a Default Value**
### **1. `orElse(defaultValue)`**
Returns the value if present; otherwise, returns a default.
```java
String name = Optional.ofNullable(null).orElse("Default Name");
System.out.println(name); // Output: Default Name
```

---

### **2. `orElseGet(Supplier<T>)`**
Like `orElse()`, but **lazy evaluation** (executes only if `Optional` is empty).
```java
String name = Optional.ofNullable(null).orElseGet(() -> "Generated Name");
System.out.println(name); // Output: Generated Name
```

---

### **3. `orElseThrow(Supplier<Exception>)`**
Throws an exception if the value is missing.
```java
String name = Optional.ofNullable(null).orElseThrow(() -> new RuntimeException("Value is missing"));
```
> 🚨 This approach is useful when a missing value is considered an **error**.

---

## **Transforming and Filtering Values**
### **1. `map(Function<T, R>)`** – Transforms the value if present.
```java
Optional<String> name = Optional.of("Komugi");
Optional<Integer> length = name.map(String::length);
System.out.println(length.get()); // Output: 6
```

---

### **2. `flatMap(Function<T, Optional<R>>)`** – Flattens nested `Optional` objects.
```java
Optional<String> name = Optional.of("Komugi");
Optional<Optional<Integer>> nestedOptional = name.map(n -> Optional.of(n.length()));
Optional<Integer> flatOptional = name.flatMap(n -> Optional.of(n.length()));
System.out.println(flatOptional.get()); // Output: 6
```

---

### **3. `filter(Predicate<T>)`** – Returns an `Optional` only if it matches the condition.
```java
Optional<String> name = Optional.of("Komugi");
Optional<String> filteredName = name.filter(n -> n.startsWith("K"));
System.out.println(filteredName.isPresent()); // Output: true
```

---

## **Example: Using `Optional` in a Method**
```java
import java.util.Optional;

public class OptionalExample {
    public static Optional<String> getUserName(String id) {
        if ("123".equals(id)) {
            return Optional.of("Komugi");
        }
        return Optional.empty();
    }

    public static void main(String[] args) {
        Optional<String> name = getUserName("123");
        name.ifPresent(n -> System.out.println("User found: " + n)); // Output: User found: Komugi
    }
}
```

---

## **Summary**
| Method | Description |
|--------|-------------|
| `Optional.of(value)` | Creates an `Optional` with a non-null value (throws exception if `null`). |
| `Optional.ofNullable(value)` | Creates an `Optional` that can handle `null`. |
| `Optional.empty()` | Creates an empty `Optional`. |
| `isPresent()` | Checks if a value is present. |
| `ifPresent(Consumer<T>)` | Runs a function if a value is present. |
| `orElse(defaultValue)` | Returns the value or a default. |
| `orElseGet(Supplier<T>)` | Returns the value or generates one. |
| `orElseThrow(Supplier<E>)` | Throws an exception if value is missing. |
| `map(Function<T, R>)` | Transforms the value. |
| `flatMap(Function<T, Optional<R>>)` | Flattens nested `Optional` objects. |
| `filter(Predicate<T>)` | Returns an `Optional` if condition is met. |

---

## **Conclusion**
- `Optional` **reduces the need for null checks** and makes Java code **more readable** and **safe**.
- It is **not a replacement for `null`**, but a better way to handle **optional values**.
- Use `Optional` in **method return types** when a value **might not be present**.
