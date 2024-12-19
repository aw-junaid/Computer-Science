### C# - Indexers

An **Indexer** in C# allows instances of a class or struct to be indexed like arrays. Essentially, an indexer enables you to use objects of a class or struct in a manner similar to arrays, where you can access elements using an index (or multiple indices). This feature is particularly useful when you want to provide access to a collection of data within an object, such as a list or array.

### Syntax of Indexers

The syntax for declaring an indexer is as follows:

```csharp
public type this[parameters]
{
    get { ... }
    set { ... }
}
```

- `type`: The type of the value that the indexer will return or accept.
- `this`: The keyword used to define an indexer.
- `parameters`: The index or parameters that you want to use to access the elements.
- `get`: The accessor to retrieve the value for the specified index.
- `set`: The accessor to assign a value to the specified index.

### Basic Example of an Indexer

```csharp
using System;

public class MyCollection
{
    private string[] items = new string[10];

    // Indexer definition
    public string this[int index]
    {
        get { return items[index]; }
        set { items[index] = value; }
    }
}

class Program
{
    static void Main()
    {
        MyCollection collection = new MyCollection();

        // Using the indexer to set values
        collection[0] = "Hello";
        collection[1] = "World";

        // Using the indexer to get values
        Console.WriteLine(collection[0]);  // Output: Hello
        Console.WriteLine(collection[1]);  // Output: World
    }
}
```

### Explanation:
- The `MyCollection` class contains an array of strings (`items`).
- The indexer is defined as `this[int index]`, which means you can access elements of `MyCollection` using an integer index.
- The `get` accessor returns the value at the specified index in the `items` array.
- The `set` accessor assigns a value to the element at the specified index in the `items` array.

### Indexers with Multiple Parameters

You can define indexers with multiple parameters, which is useful when dealing with multi-dimensional data or other complex scenarios.

```csharp
using System;

public class Matrix
{
    private int[,] data = new int[3, 3];

    // Indexer with two parameters (for a 2D array)
    public int this[int row, int col]
    {
        get { return data[row, col]; }
        set { data[row, col] = value; }
    }
}

class Program
{
    static void Main()
    {
        Matrix matrix = new Matrix();

        // Using the indexer with two parameters
        matrix[0, 0] = 1;
        matrix[1, 1] = 2;
        matrix[2, 2] = 3;

        // Accessing values using the indexer
        Console.WriteLine(matrix[0, 0]);  // Output: 1
        Console.WriteLine(matrix[1, 1]);  // Output: 2
        Console.WriteLine(matrix[2, 2]);  // Output: 3
    }
}
```

### Explanation:
- The `Matrix` class defines a 2D array `data`.
- The indexer `this[int row, int col]` allows you to access elements using two indices, representing the row and column.
- The `get` and `set` accessors work with two indices to retrieve and assign values to the `data` array.

### Read-Only Indexer

You can define an indexer that only has a `get` accessor, making it read-only. This can be useful when you want to allow access to the elements without modifying them.

```csharp
using System;

public class ReadOnlyCollection
{
    private string[] items = { "Apple", "Banana", "Cherry" };

    // Read-only indexer
    public string this[int index]
    {
        get { return items[index]; }
    }
}

class Program
{
    static void Main()
    {
        ReadOnlyCollection collection = new ReadOnlyCollection();

        // Using the read-only indexer to get values
        Console.WriteLine(collection[0]);  // Output: Apple
        Console.WriteLine(collection[1]);  // Output: Banana
        Console.WriteLine(collection[2]);  // Output: Cherry
    }
}
```

### Explanation:
- The `ReadOnlyCollection` class defines a read-only indexer that only allows accessing elements via the `get` accessor.
- The indexer allows retrieval of elements from the `items` array, but you cannot modify the array using the indexer.

### Indexer with Custom Logic

You can implement additional logic in the `get` and `set` accessors to manipulate data, validate input, or perform other operations when accessing elements.

```csharp
using System;

public class CustomCollection
{
    private string[] items = new string[10];

    // Indexer with custom logic
    public string this[int index]
    {
        get
        {
            if (index < 0 || index >= items.Length)
                throw new IndexOutOfRangeException("Index is out of bounds.");
            return items[index];
        }
        set
        {
            if (index < 0 || index >= items.Length)
                throw new IndexOutOfRangeException("Index is out of bounds.");
            items[index] = value;
        }
    }
}

class Program
{
    static void Main()
    {
        CustomCollection collection = new CustomCollection();

        // Using the indexer with custom logic
        try
        {
            collection[0] = "Hello";  // Valid
            Console.WriteLine(collection[0]);  // Output: Hello

            collection[10] = "Out of bounds";  // Throws exception
        }
        catch (IndexOutOfRangeException ex)
        {
            Console.WriteLine(ex.Message);  // Output: Index is out of bounds.
        }
    }
}
```

### Explanation:
- The `CustomCollection` class defines an indexer with custom validation logic in both `get` and `set`.
- It checks whether the provided index is within bounds before accessing or assigning values.
- If the index is out of bounds, an `IndexOutOfRangeException` is thrown.

### Indexers and Collections

Indexers are often used in classes that represent collections or containers, such as lists, arrays, or dictionaries, allowing objects of the class to be accessed like arrays.

For example, in a class representing a custom list, an indexer can provide access to elements of the list without exposing the underlying array or collection.

```csharp
using System;
using System.Collections.Generic;

public class MyList
{
    private List<string> items = new List<string>();

    // Indexer for a list
    public string this[int index]
    {
        get { return items[index]; }
        set { items[index] = value; }
    }

    // Add method to add items to the list
    public void Add(string item)
    {
        items.Add(item);
    }
}

class Program
{
    static void Main()
    {
        MyList list = new MyList();
        list.Add("Hello");
        list.Add("World");

        // Using the indexer to access elements
        Console.WriteLine(list[0]);  // Output: Hello
        Console.WriteLine(list[1]);  // Output: World
    }
}
```

### Explanation:
- The `MyList` class encapsulates a `List<string>` and provides access to its elements through an indexer.
- The `Add` method allows adding items to the list, and the indexer allows retrieving or modifying the elements.

### Summary of Key Points:

1. **Basic Syntax**: `public type this[parameters] { get; set; }`
   - `get`: Retrieves the value for the given index.
   - `set`: Assigns a value to the given index.
   
2. **Multi-Parameter Indexers**: You can define indexers with multiple parameters (e.g., for multidimensional arrays or more complex access patterns).
   
3. **Read-Only Indexers**: Indexers can be defined as read-only by omitting the `set` accessor, which allows only retrieving values.

4. **Custom Logic**: Indexers allow custom logic in `get` and `set` accessors to perform actions such as validation or computation.

5. **Use Cases**: Indexers are commonly used in collection classes, such as arrays, lists, and dictionaries, to provide array-like access to objects.

Indexers provide a clean and flexible way to access elements within objects, offering more control than simple field access while maintaining an array-like interface for the users of the class.
