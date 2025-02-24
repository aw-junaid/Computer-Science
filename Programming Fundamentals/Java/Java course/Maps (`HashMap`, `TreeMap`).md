In Java, **maps** are collections that store key-value pairs. The two most commonly used implementations of the `Map` interface are **`HashMap`** and **`TreeMap`**. Both classes implement the `Map` interface but have different underlying data structures and performance characteristics. Let’s explore these two map implementations in detail.

---

### **1. `HashMap`**
`HashMap` is a hash table-based implementation of the `Map` interface. It provides constant-time performance for basic operations like `put`, `get`, and `remove`, assuming the hash function distributes keys properly.

#### **Key Features**:
- **Hash Table**: Internally uses a hash table to store key-value pairs.
- **No Order**: Does not maintain the insertion order of keys.
- **Fast Operations**: Provides O(1) time complexity for `put`, `get`, and `remove`.
- **Not Synchronized**: Not thread-safe by default.

#### **Example**:
```java
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Map<String, Integer> ageMap = new HashMap<>();

        // Add key-value pairs
        ageMap.put("John", 25);
        ageMap.put("Alice", 30);
        ageMap.put("Bob", 28);

        // Access values
        System.out.println("Age of John: " + ageMap.get("John")); // 25

        // Update values
        ageMap.put("John", 26); // Update John's age

        // Remove key-value pairs
        ageMap.remove("Alice");

        // Iterate over key-value pairs
        for (Map.Entry<String, Integer> entry : ageMap.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }

        // Check size
        System.out.println("Number of entries: " + ageMap.size()); // 2
    }
}
```
**Output**:
```
Age of John: 25
Bob: 28
John: 26
Number of entries: 2
```

---

### **2. `TreeMap`**
`TreeMap` is a red-black tree-based implementation of the `Map` interface. It stores key-value pairs in sorted order (based on the natural order of keys or a custom `Comparator`) and provides guaranteed O(log n) time complexity for basic operations.

#### **Key Features**:
- **Red-Black Tree**: Internally uses a balanced binary search tree (red-black tree) to store key-value pairs.
- **Sorted Order**: Maintains keys in natural order (or custom order using a `Comparator`).
- **Slower Operations**: Provides O(log n) time complexity for `put`, `get`, and `remove`.
- **Not Synchronized**: Not thread-safe by default.

#### **Example**:
```java
import java.util.Map;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) {
        Map<String, Integer> ageMap = new TreeMap<>();

        // Add key-value pairs
        ageMap.put("John", 25);
        ageMap.put("Alice", 30);
        ageMap.put("Bob", 28);

        // Access values
        System.out.println("Age of John: " + ageMap.get("John")); // 25

        // Update values
        ageMap.put("John", 26); // Update John's age

        // Remove key-value pairs
        ageMap.remove("Alice");

        // Iterate over key-value pairs (in sorted order)
        for (Map.Entry<String, Integer> entry : ageMap.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }

        // Check size
        System.out.println("Number of entries: " + ageMap.size()); // 2
    }
}
```
**Output**:
```
Age of John: 25
Bob: 28
John: 26
Number of entries: 2
```

---

### **3. Key Differences Between `HashMap` and `TreeMap`**

| Feature                | `HashMap`                    | `TreeMap`                    |
|------------------------|------------------------------|------------------------------|
| **Underlying Data Structure** | Hash table               | Red-black tree               |
| **Order**              | No order                     | Sorted order                 |
| **Performance**        | O(1) for basic operations    | O(log n) for basic operations |
| **Use Case**           | Fast lookups, no ordering    | Sorted keys, range queries   |

---

### **4. When to Use `HashMap` vs `TreeMap`**

#### **Use `HashMap` When**:
- You need fast lookups, insertions, and deletions.
- The order of keys does not matter.
- You want to avoid duplicates.

#### **Use `TreeMap` When**:
- You need keys to be sorted in natural order or a custom order.
- You need to perform range queries (e.g., find all keys between two values).
- You want to avoid duplicates.

---

### **5. Example Program**
Here’s a complete example demonstrating both `HashMap` and `TreeMap`:

```java
import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) {
        // HashMap example
        Map<String, Integer> hashMap = new HashMap<>();
        hashMap.put("John", 25);
        hashMap.put("Alice", 30);
        hashMap.put("Bob", 28);
        System.out.println("HashMap: " + hashMap);

        // TreeMap example
        Map<String, Integer> treeMap = new TreeMap<>();
        treeMap.put("John", 25);
        treeMap.put("Alice", 30);
        treeMap.put("Bob", 28);
        System.out.println("TreeMap: " + treeMap);

        // Performance comparison
        long startTime, endTime;

        // HashMap operations
        startTime = System.nanoTime();
        hashMap.get("John");
        endTime = System.nanoTime();
        System.out.println("HashMap lookup time: " + (endTime - startTime) + " ns");

        // TreeMap operations
        startTime = System.nanoTime();
        treeMap.get("John");
        endTime = System.nanoTime();
        System.out.println("TreeMap lookup time: " + (endTime - startTime) + " ns");
    }
}
```
**Output**:
```
HashMap: {Alice=30, Bob=28, John=25}
TreeMap: {Alice=30, Bob=28, John=25}
HashMap lookup time: 1000 ns
TreeMap lookup time: 5000 ns
```

---

### **6. Conclusion**
`HashMap` and `TreeMap` are both powerful implementations of the `Map` interface, each with its own strengths and weaknesses. By understanding their differences and use cases, you can choose the right map implementation for your specific needs. Whether you need fast lookups or sorted keys, the Java Collections Framework has you covered.
