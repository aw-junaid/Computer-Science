The **Stream API** in Java is a powerful feature introduced in **Java 8** that allows functional-style operations on collections of data. It enables processing sequences of elements efficiently using **functional programming techniques**.

---

## **Key Features of Stream API:**
1. **Declarative** – Code is more readable and concise.
2. **Functional** – Uses lambda expressions and method references.
3. **Lazy Execution** – Intermediate operations are executed only when a terminal operation is invoked.
4. **Parallel Processing** – Streams can be processed in parallel using `.parallelStream()`, improving performance.

---

## **How to Create a Stream?**
Streams can be created from:
- **Collections** (`List`, `Set`, etc.)
- **Arrays**
- **Streams.of()**
- **Files**
- **Random numbers**

### **Example: Creating a Stream from a List**
```java
import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

public class StreamExample {
    public static void main(String[] args) {
        List<String> names = Arrays.asList("Alice", "Bob", "Charlie");

        // Creating a stream
        Stream<String> nameStream = names.stream();
        
        // Processing the stream
        nameStream.forEach(System.out::println);
    }
}
```

---

## **Stream Operations**
### **1. Intermediate Operations (Return a Stream)**
These operations **do not execute immediately**; they build a pipeline of processing.

| Operation | Description |
|-----------|------------|
| **`filter(Predicate<T>)`** | Filters elements based on a condition. |
| **`map(Function<T, R>)`** | Transforms each element. |
| **`sorted(Comparator<T>)`** | Sorts elements. |
| **`distinct()`** | Removes duplicates. |
| **`limit(n)`** | Limits the number of elements. |
| **`skip(n)`** | Skips the first `n` elements. |

### **Example: Using `filter` and `map`**
```java
import java.util.Arrays;
import java.util.List;

public class StreamIntermediateExample {
    public static void main(String[] args) {
        List<String> names = Arrays.asList("Alice", "Bob", "Charlie", "David");

        names.stream()
             .filter(name -> name.startsWith("C")) // Only names starting with 'C'
             .map(String::toUpperCase) // Convert to uppercase
             .forEach(System.out::println);
    }
}
```
**Output:**
```
CHARLIE
```

---

### **2. Terminal Operations (Trigger Execution)**
These operations **execute the stream pipeline** and return a result.

| Operation | Description |
|-----------|------------|
| **`forEach(Consumer<T>)`** | Performs an action on each element. |
| **`collect(Collectors.toList())`** | Collects elements into a list, set, or map. |
| **`count()`** | Returns the count of elements. |
| **`reduce(BinaryOperator<T>)`** | Reduces elements to a single value. |
| **`allMatch(Predicate<T>)`** | Returns `true` if all elements match a condition. |
| **`anyMatch(Predicate<T>)`** | Returns `true` if any element matches a condition. |
| **`noneMatch(Predicate<T>)`** | Returns `true` if no element matches a condition. |

### **Example: Collecting Stream Results**
```java
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class StreamCollectExample {
    public static void main(String[] args) {
        List<String> names = Arrays.asList("Alice", "Bob", "Charlie", "David");

        List<String> filteredNames = names.stream()
                                          .filter(name -> name.length() > 3) // Only names longer than 3 characters
                                          .collect(Collectors.toList());

        System.out.println(filteredNames);
    }
}
```
**Output:**
```
[Alice, Charlie, David]
```

---

## **Parallel Streams**
To improve performance, you can process elements in parallel using `.parallelStream()`.

### **Example: Using Parallel Streams**
```java
import java.util.Arrays;
import java.util.List;

public class ParallelStreamExample {
    public static void main(String[] args) {
        List<String> names = Arrays.asList("Alice", "Bob", "Charlie", "David");

        names.parallelStream()
             .forEach(System.out::println); // May print in any order due to parallel execution
    }
}
```

---

## **Conclusion**
- **Stream API** provides a functional way to process data collections efficiently.
- It supports **lazy evaluation**, **pipelining**, and **parallel processing**.
- Intermediate operations **transform** the data, while terminal operations **produce results**.
