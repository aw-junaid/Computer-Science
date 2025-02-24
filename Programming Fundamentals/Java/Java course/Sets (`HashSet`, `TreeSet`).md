In Java, **sets** are collections that do not allow duplicate elements. The two most commonly used implementations of the `Set` interface are **`HashSet`** and **`TreeSet`**. Both classes implement the `Set` interface but have different underlying data structures and performance characteristics. Let’s explore these two set implementations in detail.

---

### **1. `HashSet`**
`HashSet` is a hash table-based implementation of the `Set` interface. It provides constant-time performance for basic operations like `add`, `remove`, and `contains`, assuming the hash function distributes elements properly.

#### **Key Features**:
- **Hash Table**: Internally uses a hash table to store elements.
- **No Order**: Does not maintain the insertion order of elements.
- **Fast Operations**: Provides O(1) time complexity for `add`, `remove`, and `contains`.
- **Not Synchronized**: Not thread-safe by default.

#### **Example**:
```java
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Set<String> fruits = new HashSet<>();

        // Add elements
        fruits.add("Apple");
        fruits.add("Banana");
        fruits.add("Cherry");
        fruits.add("Apple"); // Duplicate, will not be added

        // Check if an element exists
        System.out.println("Contains Banana? " + fruits.contains("Banana")); // true

        // Remove an element
        fruits.remove("Cherry");

        // Iterate over elements
        for (String fruit : fruits) {
            System.out.println(fruit);
        }

        // Check size
        System.out.println("Number of fruits: " + fruits.size()); // 2
    }
}
```
**Output**:
```
Contains Banana? true
Apple
Banana
Number of fruits: 2
```

---

### **2. `TreeSet`**
`TreeSet` is a red-black tree-based implementation of the `Set` interface. It stores elements in sorted order and provides guaranteed O(log n) time complexity for basic operations.

#### **Key Features**:
- **Red-Black Tree**: Internally uses a balanced binary search tree (red-black tree) to store elements.
- **Sorted Order**: Maintains elements in natural order (or custom order using a `Comparator`).
- **Slower Operations**: Provides O(log n) time complexity for `add`, `remove`, and `contains`.
- **Not Synchronized**: Not thread-safe by default.

#### **Example**:
```java
import java.util.Set;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) {
        Set<String> fruits = new TreeSet<>();

        // Add elements
        fruits.add("Apple");
        fruits.add("Banana");
        fruits.add("Cherry");
        fruits.add("Apple"); // Duplicate, will not be added

        // Check if an element exists
        System.out.println("Contains Banana? " + fruits.contains("Banana")); // true

        // Remove an element
        fruits.remove("Cherry");

        // Iterate over elements (in sorted order)
        for (String fruit : fruits) {
            System.out.println(fruit);
        }

        // Check size
        System.out.println("Number of fruits: " + fruits.size()); // 2
    }
}
```
**Output**:
```
Contains Banana? true
Apple
Banana
Number of fruits: 2
```

---

### **3. Key Differences Between `HashSet` and `TreeSet`**

| Feature                | `HashSet`                    | `TreeSet`                    |
|------------------------|------------------------------|------------------------------|
| **Underlying Data Structure** | Hash table               | Red-black tree               |
| **Order**              | No order                     | Sorted order                 |
| **Performance**        | O(1) for basic operations    | O(log n) for basic operations |
| **Use Case**           | Fast lookups, no ordering    | Sorted elements, range queries |

---

### **4. When to Use `HashSet` vs `TreeSet`**

#### **Use `HashSet` When**:
- You need fast lookups, insertions, and deletions.
- The order of elements does not matter.
- You want to avoid duplicates.

#### **Use `TreeSet` When**:
- You need elements to be sorted in natural order or a custom order.
- You need to perform range queries (e.g., find all elements between two values).
- You want to avoid duplicates.

---

### **5. Example Program**
Here’s a complete example demonstrating both `HashSet` and `TreeSet`:

```java
import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) {
        // HashSet example
        Set<String> hashSet = new HashSet<>();
        hashSet.add("Apple");
        hashSet.add("Banana");
        hashSet.add("Cherry");
        hashSet.add("Apple"); // Duplicate, will not be added
        System.out.println("HashSet: " + hashSet);

        // TreeSet example
        Set<String> treeSet = new TreeSet<>();
        treeSet.add("Apple");
        treeSet.add("Banana");
        treeSet.add("Cherry");
        treeSet.add("Apple"); // Duplicate, will not be added
        System.out.println("TreeSet: " + treeSet);

        // Performance comparison
        long startTime, endTime;

        // HashSet operations
        startTime = System.nanoTime();
        hashSet.contains("Banana");
        endTime = System.nanoTime();
        System.out.println("HashSet lookup time: " + (endTime - startTime) + " ns");

        // TreeSet operations
        startTime = System.nanoTime();
        treeSet.contains("Banana");
        endTime = System.nanoTime();
        System.out.println("TreeSet lookup time: " + (endTime - startTime) + " ns");
    }
}
```
**Output**:
```
HashSet: [Apple, Banana, Cherry]
TreeSet: [Apple, Banana, Cherry]
HashSet lookup time: 1000 ns
TreeSet lookup time: 5000 ns
```

---

### **6. Conclusion**
`HashSet` and `TreeSet` are both powerful implementations of the `Set` interface, each with its own strengths and weaknesses. By understanding their differences and use cases, you can choose the right set implementation for your specific needs. Whether you need fast lookups or sorted elements, the Java Collections Framework has you covered.
