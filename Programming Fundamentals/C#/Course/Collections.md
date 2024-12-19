### C# - Collections

In C#, **collections** are used to store, retrieve, and manipulate data in a structured way. The .NET Framework provides a variety of collection types, such as arrays, lists, dictionaries, and queues, to cater to different data storage and access needs. Collections are primarily divided into two types: **Non-generic** and **Generic** collections.

- **Non-generic collections**: These collections store objects of any data type, but they require type casting when retrieving items.
- **Generic collections**: These collections are type-safe, meaning that they can only store items of a specified type, making them safer and more efficient.

### Common Collection Types in C#

Here’s an overview of the most commonly used collection types in C#:

### 1. **Arrays**

An array is a fixed-size collection that stores elements of the same type.

#### Example:

```csharp
using System;

class Program
{
    static void Main()
    {
        // Declare and initialize an array
        int[] numbers = { 1, 2, 3, 4, 5 };

        // Accessing elements
        Console.WriteLine(numbers[0]);  // Output: 1
        Console.WriteLine(numbers[2]);  // Output: 3
    }
}
```

- **Length**: You can access the length of the array using the `Length` property (`numbers.Length`).
- **Indexing**: Arrays in C# are zero-based, meaning the first element is at index 0.

### 2. **List<T> (Generic)**

A `List<T>` is a dynamic array that automatically resizes as elements are added. It is part of the **System.Collections.Generic** namespace and is type-safe.

#### Example:

```csharp
using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        // Create a List of integers
        List<int> numbers = new List<int> { 1, 2, 3, 4, 5 };

        // Add an element to the list
        numbers.Add(6);

        // Accessing elements
        Console.WriteLine(numbers[0]);  // Output: 1
        Console.WriteLine(numbers[5]);  // Output: 6

        // Removing an element
        numbers.Remove(3);

        // Loop through the list
        foreach (var number in numbers)
        {
            Console.WriteLine(number);
        }
    }
}
```

- **Add()**: Adds elements to the list.
- **Remove()**: Removes elements from the list by value.
- **Count**: The `Count` property returns the number of elements in the list.

### 3. **Dictionary<TKey, TValue> (Generic)**

A `Dictionary<TKey, TValue>` is a collection that stores key-value pairs. It is useful for when you need to associate unique keys with values.

#### Example:

```csharp
using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        // Create a dictionary with string keys and integer values
        Dictionary<string, int> ageDictionary = new Dictionary<string, int>();

        // Add key-value pairs
        ageDictionary.Add("Alice", 30);
        ageDictionary.Add("Bob", 25);

        // Accessing values by key
        Console.WriteLine(ageDictionary["Alice"]);  // Output: 30

        // Check if a key exists
        if (ageDictionary.ContainsKey("Bob"))
        {
            Console.WriteLine("Bob's age: " + ageDictionary["Bob"]);  // Output: 25
        }

        // Loop through the dictionary
        foreach (var entry in ageDictionary)
        {
            Console.WriteLine($"{entry.Key}: {entry.Value}");
        }
    }
}
```

- **Add()**: Adds key-value pairs.
- **ContainsKey()**: Checks if a key exists in the dictionary.
- **Indexing**: You can access values by their key using `dictionary[key]`.

### 4. **Queue<T> (Generic)**

A `Queue<T>` is a first-in, first-out (FIFO) collection that is typically used when elements need to be processed in the order they were added.

#### Example:

```csharp
using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        // Create a queue
        Queue<string> queue = new Queue<string>();

        // Enqueue elements (add to the end of the queue)
        queue.Enqueue("First");
        queue.Enqueue("Second");
        queue.Enqueue("Third");

        // Dequeue an element (remove from the front of the queue)
        Console.WriteLine(queue.Dequeue());  // Output: First

        // Peek at the first element without removing it
        Console.WriteLine(queue.Peek());  // Output: Second
    }
}
```

- **Enqueue()**: Adds an element to the end of the queue.
- **Dequeue()**: Removes and returns the element at the front of the queue.
- **Peek()**: Returns the element at the front without removing it.

### 5. **Stack<T> (Generic)**

A `Stack<T>` is a last-in, first-out (LIFO) collection that is useful when you need to process elements in reverse order of their addition.

#### Example:

```csharp
using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        // Create a stack
        Stack<string> stack = new Stack<string>();

        // Push elements onto the stack
        stack.Push("First");
        stack.Push("Second");
        stack.Push("Third");

        // Pop an element (remove from the top of the stack)
        Console.WriteLine(stack.Pop());  // Output: Third

        // Peek at the top element without removing it
        Console.WriteLine(stack.Peek());  // Output: Second
    }
}
```

- **Push()**: Adds an element to the top of the stack.
- **Pop()**: Removes and returns the top element.
- **Peek()**: Returns the top element without removing it.

### 6. **HashSet<T> (Generic)**

A `HashSet<T>` is an unordered collection of unique elements. It is commonly used when you need to ensure that no duplicates are present in the collection.

#### Example:

```csharp
using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        // Create a HashSet
        HashSet<string> set = new HashSet<string>();

        // Add elements
        set.Add("Apple");
        set.Add("Banana");
        set.Add("Cherry");

        // Try adding a duplicate element
        set.Add("Apple");

        // Loop through the HashSet
        foreach (var item in set)
        {
            Console.WriteLine(item);
        }
    }
}
```

- **Add()**: Adds an element, but will not add duplicates.
- **Contains()**: Checks if a value exists in the set.

### 7. **SortedList<TKey, TValue> (Generic)**

A `SortedList<TKey, TValue>` stores key-value pairs, and the keys are always sorted in ascending order. It combines the features of both a dictionary and a sorted data structure.

#### Example:

```csharp
using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        // Create a SortedList
        SortedList<int, string> sortedList = new SortedList<int, string>();

        // Add key-value pairs
        sortedList.Add(3, "Three");
        sortedList.Add(1, "One");
        sortedList.Add(2, "Two");

        // Loop through the SortedList (keys are sorted)
        foreach (var entry in sortedList)
        {
            Console.WriteLine($"{entry.Key}: {entry.Value}");
        }
    }
}
```

- **Add()**: Adds key-value pairs.
- **Keys**: The keys in a `SortedList` are always sorted.

### Non-generic Collections

Before C# introduced generic collections, there were **non-generic** collections in the `System.Collections` namespace. These collections store `object` types, meaning you need to cast objects when retrieving them.

- **ArrayList**: A dynamically resizing collection that can hold any type of object.
- **Hashtable**: A collection of key-value pairs, where keys are associated with values.
- **Queue** and **Stack**: Non-generic versions that work similarly to the generic versions but use `object` types.

### Key Differences Between Generic and Non-generic Collections:

- **Type Safety**: Generic collections enforce type safety at compile time, while non-generic collections store `object` types and require casting.
- **Performance**: Generic collections provide better performance because no boxing/unboxing is needed, unlike non-generic collections.
- **Flexibility**: Non-generic collections can store any type of object, but generics are more restrictive and safer by only allowing specified types.

### Summary:

1. **Arrays**: Fixed-size collections of elements of the same type.
2. **List<T>**: Dynamic arrays that can grow and shrink in size.
3. **Dictionary<TKey, TValue>**: Key-value pair collection that provides fast lookups.
4. **Queue<T>**: FIFO (First In, First Out) collection.
5. **Stack<T>**: LIFO (Last In, First Out) collection.
6. **HashSet<T>**: Unordered collection of unique elements.
7. **SortedList<TKey, TValue>**: Key-value pair collection with sorted keys.
8. **Non-generic Collections**: Older collections that work with `object` types but require casting.

C# provides a wide range of collection types to meet the needs of different programming scenarios. Using **generic collections** is generally preferred due to their type safety and performance advantages.
