In Java, sorting and searching are common operations performed on collections like lists, sets, and maps. The Java Collections Framework provides built-in methods and utilities to efficiently sort and search collections. Let’s explore these operations in detail.

---

### **1. Sorting Collections**
Sorting arranges the elements of a collection in a specific order (e.g., ascending or descending). Java provides several ways to sort collections:

#### **a. Using `Collections.sort()`**
The `Collections.sort()` method sorts a `List` in natural order (ascending order for numbers, alphabetical order for strings).

#### **Example**:
```java
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Integer> numbers = new ArrayList<>();
        numbers.add(5);
        numbers.add(2);
        numbers.add(8);
        numbers.add(1);

        // Sort in natural order
        Collections.sort(numbers);
        System.out.println("Sorted List: " + numbers);
    }
}
```
**Output**:
```
Sorted List: [1, 2, 5, 8]
```

#### **b. Using a Custom Comparator**
You can sort a collection in a custom order by providing a `Comparator`.

#### **Example**:
```java
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<String> fruits = new ArrayList<>();
        fruits.add("Apple");
        fruits.add("Banana");
        fruits.add("Cherry");

        // Sort in descending order
        Collections.sort(fruits, Comparator.reverseOrder());
        System.out.println("Sorted List (Descending): " + fruits);
    }
}
```
**Output**:
```
Sorted List (Descending): [Cherry, Banana, Apple]
```

#### **c. Using `List.sort()`**
The `List` interface provides a `sort()` method that can be used with a `Comparator`.

#### **Example**:
```java
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<String> fruits = new ArrayList<>();
        fruits.add("Apple");
        fruits.add("Banana");
        fruits.add("Cherry");

        // Sort using List.sort()
        fruits.sort(Comparator.naturalOrder());
        System.out.println("Sorted List: " + fruits);
    }
}
```
**Output**:
```
Sorted List: [Apple, Banana, Cherry]
```

---

### **2. Searching Collections**
Searching involves finding the position of an element in a collection. Java provides methods like `Collections.binarySearch()` for efficient searching.

#### **a. Using `Collections.binarySearch()`**
The `Collections.binarySearch()` method performs a binary search on a sorted list. It returns the index of the element if found, or a negative value if not found.

#### **Example**:
```java
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Integer> numbers = new ArrayList<>();
        numbers.add(1);
        numbers.add(2);
        numbers.add(5);
        numbers.add(8);

        // Binary search on a sorted list
        int index = Collections.binarySearch(numbers, 5);
        System.out.println("Index of 5: " + index); // 2

        index = Collections.binarySearch(numbers, 10);
        System.out.println("Index of 10: " + index); // -5 (not found)
    }
}
```
**Output**:
```
Index of 5: 2
Index of 10: -5
```

#### **b. Using `List.indexOf()`**
The `List.indexOf()` method returns the index of the first occurrence of an element in a list. It returns `-1` if the element is not found.

#### **Example**:
```java
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<String> fruits = new ArrayList<>();
        fruits.add("Apple");
        fruits.add("Banana");
        fruits.add("Cherry");

        // Search for an element
        int index = fruits.indexOf("Banana");
        System.out.println("Index of Banana: " + index); // 1

        index = fruits.indexOf("Mango");
        System.out.println("Index of Mango: " + index); // -1
    }
}
```
**Output**:
```
Index of Banana: 1
Index of Mango: -1
```

---

### **3. Sorting and Searching Custom Objects**
You can sort and search collections of custom objects by implementing the `Comparable` interface or providing a `Comparator`.

#### **a. Using `Comparable`**
The `Comparable` interface defines the natural ordering of objects.

#### **Example**:
```java
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Person implements Comparable<Person> {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public int compareTo(Person other) {
        return this.age - other.age; // Sort by age
    }

    @Override
    public String toString() {
        return name + " (" + age + ")";
    }
}

public class Main {
    public static void main(String[] args) {
        List<Person> people = new ArrayList<>();
        people.add(new Person("Alice", 30));
        people.add(new Person("Bob", 25));
        people.add(new Person("Charlie", 35));

        // Sort by age (natural order)
        Collections.sort(people);
        System.out.println("Sorted People: " + people);
    }
}
```
**Output**:
```
Sorted People: [Bob (25), Alice (30), Charlie (35)]
```

#### **b. Using `Comparator`**
You can define custom sorting logic using a `Comparator`.

#### **Example**:
```java
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class Person {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    @Override
    public String toString() {
        return name + " (" + age + ")";
    }
}

public class Main {
    public static void main(String[] args) {
        List<Person> people = new ArrayList<>();
        people.add(new Person("Alice", 30));
        people.add(new Person("Bob", 25));
        people.add(new Person("Charlie", 35));

        // Sort by name using a Comparator
        Collections.sort(people, Comparator.comparing(Person::getName));
        System.out.println("Sorted People by Name: " + people);

        // Sort by age using a Comparator
        Collections.sort(people, Comparator.comparingInt(Person::getAge));
        System.out.println("Sorted People by Age: " + people);
    }
}
```
**Output**:
```
Sorted People by Name: [Alice (30), Bob (25), Charlie (35)]
Sorted People by Age: [Bob (25), Alice (30), Charlie (35)]
```

---

### **4. Example Program**
Here’s a complete example demonstrating sorting and searching with custom objects:

```java
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class Person implements Comparable<Person> {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    @Override
    public int compareTo(Person other) {
        return this.age - other.age; // Sort by age
    }

    @Override
    public String toString() {
        return name + " (" + age + ")";
    }
}

public class Main {
    public static void main(String[] args) {
        List<Person> people = new ArrayList<>();
        people.add(new Person("Alice", 30));
        people.add(new Person("Bob", 25));
        people.add(new Person("Charlie", 35));

        // Sort by age (natural order)
        Collections.sort(people);
        System.out.println("Sorted People by Age: " + people);

        // Sort by name using a Comparator
        Collections.sort(people, Comparator.comparing(Person::getName));
        System.out.println("Sorted People by Name: " + people);

        // Binary search by age
        int index = Collections.binarySearch(people, new Person("Alice", 30));
        System.out.println("Index of Alice (30): " + index); // 1
    }
}
```
**Output**:
```
Sorted People by Age: [Bob (25), Alice (30), Charlie (35)]
Sorted People by Name: [Alice (30), Bob (25), Charlie (35)]
Index of Alice (30): 1
```

---

### **5. Conclusion**
Sorting and searching are fundamental operations in Java that can be performed efficiently using the `Collections` utility class and the `Comparator` interface. By understanding these tools, you can manipulate collections effectively and write clean, maintainable code. Whether you're working with primitive types or custom objects, Java provides powerful features to handle sorting and searching with ease.
