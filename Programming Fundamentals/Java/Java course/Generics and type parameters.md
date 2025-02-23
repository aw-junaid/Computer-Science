**Generics** in Java allow you to create classes, interfaces, and methods that operate on **type parameters**. This enables you to write reusable, type-safe code that can work with different data types without sacrificing type checking at compile time. Let’s explore generics and type parameters in detail.

---

### **1. Why Use Generics?**
Generics provide several benefits:
1. **Type Safety**: Ensures that the correct type of data is used, reducing runtime errors.
2. **Code Reusability**: Write generic code that works with multiple types.
3. **Eliminate Casting**: No need to cast objects when retrieving them from generic types.
4. **Improved Readability**: Makes code more readable and maintainable.

---

### **2. Generic Classes**
A generic class is a class that can work with any data type. You define a type parameter (e.g., `T`) that can be replaced with a specific type when the class is instantiated.

#### **Syntax**:
```java
class ClassName<T> {
    // Use T as a type
}
```

#### **Example**:
```java
class Box<T> {
    private T item;

    public void setItem(T item) {
        this.item = item;
    }

    public T getItem() {
        return item;
    }
}

public class Main {
    public static void main(String[] args) {
        Box<String> stringBox = new Box<>();
        stringBox.setItem("Hello");
        System.out.println("String Box: " + stringBox.getItem());

        Box<Integer> integerBox = new Box<>();
        integerBox.setItem(123);
        System.out.println("Integer Box: " + integerBox.getItem());
    }
}
```
**Output**:
```
String Box: Hello
Integer Box: 123
```

---

### **3. Generic Methods**
A generic method is a method that can accept parameters of any type. You define a type parameter (e.g., `T`) before the return type of the method.

#### **Syntax**:
```java
<T> returnType methodName(T parameter) {
    // Method body
}
```

#### **Example**:
```java
class Utils {
    public static <T> void printArray(T[] array) {
        for (T element : array) {
            System.out.println(element);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Integer[] intArray = {1, 2, 3, 4, 5};
        String[] strArray = {"A", "B", "C"};

        Utils.printArray(intArray); // Print integer array
        Utils.printArray(strArray); // Print string array
    }
}
```
**Output**:
```
1
2
3
4
5
A
B
C
```

---

### **4. Bounded Type Parameters**
You can restrict the types that can be used as type arguments by specifying a **bound**. For example, you can ensure that a type parameter extends a specific class or implements a specific interface.

#### **Syntax**:
```java
<T extends SuperClassOrInterface>
```

#### **Example**:
```java
class NumberBox<T extends Number> {
    private T number;

    public void setNumber(T number) {
        this.number = number;
    }

    public T getNumber() {
        return number;
    }
}

public class Main {
    public static void main(String[] args) {
        NumberBox<Integer> intBox = new NumberBox<>();
        intBox.setNumber(123);
        System.out.println("Integer Box: " + intBox.getNumber());

        NumberBox<Double> doubleBox = new NumberBox<>();
        doubleBox.setNumber(45.67);
        System.out.println("Double Box: " + doubleBox.getNumber());

        // NumberBox<String> strBox = new NumberBox<>(); // Error: String is not a subclass of Number
    }
}
```
**Output**:
```
Integer Box: 123
Double Box: 45.67
```

---

### **5. Multiple Type Parameters**
You can define multiple type parameters in a generic class or method.

#### **Syntax**:
```java
class ClassName<T, U> {
    // Use T and U as types
}
```

#### **Example**:
```java
class Pair<T, U> {
    private T first;
    private U second;

    public Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }

    public T getFirst() {
        return first;
    }

    public U getSecond() {
        return second;
    }
}

public class Main {
    public static void main(String[] args) {
        Pair<String, Integer> pair = new Pair<>("Age", 25);
        System.out.println("First: " + pair.getFirst());
        System.out.println("Second: " + pair.getSecond());
    }
}
```
**Output**:
```
First: Age
Second: 25
```

---

### **6. Wildcards in Generics**
Wildcards (`?`) are used to represent an unknown type in generics. They are often used in method parameters to make methods more flexible.

#### **Types of Wildcards**:
1. **Unbounded Wildcard (`?`)**: Represents any type.
2. **Upper Bounded Wildcard (`? extends Type`)**: Represents a type that is a subclass of `Type`.
3. **Lower Bounded Wildcard (`? super Type`)**: Represents a type that is a superclass of `Type`.

#### **Example**:
```java
import java.util.List;

class Utils {
    public static void printList(List<?> list) {
        for (Object element : list) {
            System.out.println(element);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        List<Integer> intList = List.of(1, 2, 3);
        List<String> strList = List.of("A", "B", "C");

        Utils.printList(intList); // Print integer list
        Utils.printList(strList); // Print string list
    }
}
```
**Output**:
```
1
2
3
A
B
C
```

---

### **7. Generic Interfaces**
Interfaces can also be generic, allowing you to define type-safe interfaces.

#### **Syntax**:
```java
interface InterfaceName<T> {
    // Methods using T
}
```

#### **Example**:
```java
interface Pair<K, V> {
    K getKey();
    V getValue();
}

class OrderedPair<K, V> implements Pair<K, V> {
    private K key;
    private V value;

    public OrderedPair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    @Override
    public K getKey() {
        return key;
    }

    @Override
    public V getValue() {
        return value;
    }
}

public class Main {
    public static void main(String[] args) {
        Pair<String, Integer> pair = new OrderedPair<>("Age", 25);
        System.out.println("Key: " + pair.getKey());
        System.out.println("Value: " + pair.getValue());
    }
}
```
**Output**:
```
Key: Age
Value: 25
```

---

### **8. Example Program**
Here’s a complete example demonstrating generics with classes, methods, and interfaces:

```java
class Box<T> {
    private T item;

    public void setItem(T item) {
        this.item = item;
    }

    public T getItem() {
        return item;
    }
}

class Utils {
    public static <T> void printArray(T[] array) {
        for (T element : array) {
            System.out.println(element);
        }
    }
}

interface Pair<K, V> {
    K getKey();
    V getValue();
}

class OrderedPair<K, V> implements Pair<K, V> {
    private K key;
    private V value;

    public OrderedPair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    @Override
    public K getKey() {
        return key;
    }

    @Override
    public V getValue() {
        return value;
    }
}

public class Main {
    public static void main(String[] args) {
        // Generic class
        Box<String> stringBox = new Box<>();
        stringBox.setItem("Hello");
        System.out.println("String Box: " + stringBox.getItem());

        // Generic method
        Integer[] intArray = {1, 2, 3, 4, 5};
        Utils.printArray(intArray);

        // Generic interface
        Pair<String, Integer> pair = new OrderedPair<>("Age", 25);
        System.out.println("Key: " + pair.getKey());
        System.out.println("Value: " + pair.getValue());
    }
}
```
**Output**:
```
String Box: Hello
1
2
3
4
5
Key: Age
Value: 25
```

---

### **Conclusion**
Generics and type parameters are powerful features in Java that enable you to write reusable, type-safe, and flexible code. By understanding how to use generic classes, methods, interfaces, and wildcards, you can create robust and maintainable programs. Whether you're working with collections, custom data structures, or utility methods, generics are an essential tool in your Java programming toolkit.
