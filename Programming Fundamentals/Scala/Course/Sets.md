In Scala, **Sets** are collections that store unique elements. Sets do not allow duplicate values, and the order of elements is not guaranteed. There are two main types of sets in Scala: **immutable** and **mutable**.

### Key Features of Scala Sets:
- **Uniqueness**: Sets store only unique elements (no duplicates).
- **Unordered**: The elements in a set do not have any specific order.
- **Immutable and Mutable**: Scala provides both immutable and mutable sets, with the immutable set being the default.
- **Efficient Operations**: Sets support fast lookups, additions, and deletions, especially when implemented using hash-based data structures like `HashSet`.

### Types of Sets in Scala
1. **Immutable Set**: By default, the `Set` collection in Scala is immutable, meaning once created, you cannot modify it (no adding, removing, or updating elements).
   
2. **Mutable Set**: A mutable set allows for modification (elements can be added, removed, or changed after it is created).

### 1. **Immutable Set**

An immutable set is created using the `Set` companion object.

```scala
val set1 = Set(1, 2, 3, 4)
val set2 = Set("apple", "banana", "cherry")

println(set1)  // Output: Set(1, 2, 3, 4)
println(set2)  // Output: Set(apple, banana, cherry)
```

#### **Operations on Immutable Sets**

- **Adding elements**: You cannot modify the set in place, but you can create a new set with additional elements.

```scala
val set = Set(1, 2, 3)
val newSet = set + 4  // Adds 4 to the set (returns a new set)
println(newSet)  // Output: Set(1, 2, 3, 4)
```

- **Removing elements**: You can also remove elements, which returns a new set.

```scala
val set = Set(1, 2, 3, 4)
val newSet = set - 3  // Removes 3 from the set
println(newSet)  // Output: Set(1, 2, 4)
```

- **Checking membership**: You can check if an element is part of the set using `contains`.

```scala
val set = Set(1, 2, 3, 4)
println(set.contains(2))  // Output: true
println(set.contains(5))  // Output: false
```

- **Union of Sets**: You can combine two sets using the `++` operator.

```scala
val set1 = Set(1, 2, 3)
val set2 = Set(3, 4, 5)
val unionSet = set1 ++ set2  // Combines the sets (union)
println(unionSet)  // Output: Set(1, 2, 3, 4, 5)
```

- **Intersection of Sets**: You can find the common elements between two sets using the `&` operator.

```scala
val set1 = Set(1, 2, 3, 4)
val set2 = Set(3, 4, 5, 6)
val intersectionSet = set1 & set2  // Finds the common elements (intersection)
println(intersectionSet)  // Output: Set(3, 4)
```

- **Difference of Sets**: You can find elements in one set that are not in the other using the `--` operator.

```scala
val set1 = Set(1, 2, 3, 4)
val set2 = Set(3, 4, 5, 6)
val differenceSet = set1 -- set2  // Elements in set1 but not in set2
println(differenceSet)  // Output: Set(1, 2)
```

### 2. **Mutable Set**

A mutable set allows modification of the set after it is created, such as adding, removing, or updating elements.

To create a mutable set, use the `mutable.Set` from the `scala.collection.mutable` package.

```scala
import scala.collection.mutable.Set

val mutableSet = Set(1, 2, 3, 4)
println(mutableSet)  // Output: Set(1, 2, 3, 4)
```

#### **Operations on Mutable Sets**

- **Adding elements**: You can directly add elements to the set.

```scala
val mutableSet = Set(1, 2, 3)
mutableSet += 4  // Adds 4 to the set
println(mutableSet)  // Output: Set(1, 2, 3, 4)
```

- **Removing elements**: You can directly remove elements from the set.

```scala
val mutableSet = Set(1, 2, 3, 4)
mutableSet -= 3  // Removes 3 from the set
println(mutableSet)  // Output: Set(1, 2, 4)
```

- **Clearing the set**: You can clear all elements from a mutable set.

```scala
val mutableSet = Set(1, 2, 3)
mutableSet.clear()  // Removes all elements
println(mutableSet)  // Output: Set()
```

### 3. **Common Operations on Sets**

- **Size of a Set**: You can find the number of elements in a set using `size`.

```scala
val set = Set(1, 2, 3, 4)
println(set.size)  // Output: 4
```

- **IsEmpty**: Check if a set is empty using `isEmpty`.

```scala
val set = Set()
println(set.isEmpty)  // Output: true
```

- **Iterating over a Set**: You can iterate over the elements of a set using `foreach`.

```scala
val set = Set(1, 2, 3, 4)
set.foreach(println)  // Output: 1 2 3 4
```

- **Set Equality**: You can check if two sets are equal using the `==` operator. This checks whether they have the same elements (ignoring order).

```scala
val set1 = Set(1, 2, 3)
val set2 = Set(3, 2, 1)
println(set1 == set2)  // Output: true
```

- **Set Operations and Methods**
  - **`union`**: Combines two sets.
  - **`intersect`**: Finds common elements.
  - **`diff`**: Returns the difference between sets.
  - **`contains`**: Checks for the presence of an element.
  - **`map`**: Transforms each element.

Example:

```scala
val set1 = Set(1, 2, 3)
val set2 = Set(2, 3, 4)

val unionSet = set1.union(set2)  // Set(1, 2, 3, 4)
val intersectionSet = set1.intersect(set2)  // Set(2, 3)
val diffSet = set1.diff(set2)  // Set(1)
```

### 4. **Set Pattern Matching**

You can use **pattern matching** to work with sets in a similar way as with lists.

```scala
val set = Set(1, 2, 3)

set match {
  case Set(1, 2, 3) => println("Matched: Set(1, 2, 3)")  // Will match
  case Set(4, 5, 6) => println("Not matched")  // Will not match
}
```

### 5. **Performance of Sets**

- **Immutable Sets**: Generally, immutable sets are backed by hash tables (`HashSet` or `TreeSet`), providing average constant time complexity (O(1)) for `contains`, `+`, and `-` operations.
  
- **Mutable Sets**: Mutable sets offer similar time complexities but allow you to modify the set in place without creating a new set each time.

### 6. **Use Cases of Sets**
- **Unordered Collections**: Use sets when you need to ensure uniqueness of elements without caring about their order.
- **Efficient Lookups**: Sets are perfect when you need to frequently check for the presence of an element or perform set operations like union, intersection, and difference.

---

### Example Code: Immutable and Mutable Sets

```scala
// Immutable Set
val immutableSet = Set(1, 2, 3, 4)
println(immutableSet)  // Output: Set(1, 2, 3, 4)

val newImmutableSet = immutableSet + 5  // Adding an element
println(newImmutableSet)  // Output: Set(1, 2, 3, 4, 5)

// Mutable Set
import scala.collection.mutable.Set
val mutableSet = Set(1, 2, 3)
mutableSet += 4  // Adding an element
println(mutableSet)  // Output: Set(1, 2, 3, 4)

mutableSet -= 2  // Removing an element
println(mutableSet)  // Output: Set(1, 3, 4)
```

### Conclusion

- **Sets** are a powerful and flexible collection type in Scala that ensures uniqueness and provides efficient operations for adding, removing, and checking elements.
- They can be **immutable** (default) or **mutable**, depending on whether you need to modify the collection after it is created.
- Sets are ideal for tasks where the uniqueness of elements is crucial, and they provide a rich set of methods for functional operations.
