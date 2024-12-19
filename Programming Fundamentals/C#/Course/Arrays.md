### C# - Arrays

An **array** in C# is a data structure that stores a fixed-size sequence of elements of the same type. Arrays are useful for storing multiple values in a single variable and allow for efficient access to elements via an index. In C#, arrays are zero-indexed, meaning the first element has an index of 0.

### Key Characteristics of Arrays:
1. **Fixed Size**: Once an array is created, its size cannot be changed.
2. **Indexed**: Each element in an array is accessed via its index.
3. **Same Type**: All elements in an array must be of the same data type (e.g., all integers, all strings, etc.).

### Declaring Arrays
You can declare an array in C# by specifying the type of elements the array will hold, followed by square brackets (`[]`), and optionally initializing it with values.

#### Syntax for Array Declaration:
```csharp
type[] arrayName;
```
or
```csharp
type arrayName[];
```

#### Example:
```csharp
int[] numbers;  // Declare an array of integers
```

### Initializing Arrays
Arrays can be initialized in several ways:

1. **Using an initializer list**:
```csharp
int[] numbers = { 1, 2, 3, 4, 5 };  // Array initialized with values
```

2. **Using the `new` keyword**:
```csharp
int[] numbers = new int[5];  // Declare an array of integers with size 5, elements are initialized to 0
```

3. **Using `new` with initialization**:
```csharp
int[] numbers = new int[] { 1, 2, 3, 4, 5 };  // Declare and initialize at the same time
```

4. **Creating arrays of other types**:
```csharp
string[] names = { "Alice", "Bob", "Charlie" };  // Array of strings
double[] temperatures = { 36.6, 37.2, 38.1 };  // Array of doubles
```

### Accessing Array Elements
Array elements are accessed by using an **index**. The index starts at 0 for the first element.

#### Example:
```csharp
int[] numbers = { 1, 2, 3, 4, 5 };

Console.WriteLine(numbers[0]);  // Output: 1 (First element)
Console.WriteLine(numbers[2]);  // Output: 3 (Third element)
Console.WriteLine(numbers[4]);  // Output: 5 (Fifth element)
```

### Modifying Array Elements
You can modify an element of an array by specifying its index.

#### Example:
```csharp
int[] numbers = { 1, 2, 3, 4, 5 };

numbers[2] = 10;  // Modify the third element (index 2)
Console.WriteLine(numbers[2]);  // Output: 10
```

### Array Length
To get the length (number of elements) of an array, you use the `Length` property.

#### Example:
```csharp
int[] numbers = { 1, 2, 3, 4, 5 };
Console.WriteLine(numbers.Length);  // Output: 5
```

### Iterating Through Arrays
You can iterate over an array using a loop (such as `for`, `foreach`).

#### Example using a `for` loop:
```csharp
int[] numbers = { 1, 2, 3, 4, 5 };

for (int i = 0; i < numbers.Length; i++)
{
    Console.WriteLine(numbers[i]);
}
// Output:
// 1
// 2
// 3
// 4
// 5
```

#### Example using a `foreach` loop:
```csharp
int[] numbers = { 1, 2, 3, 4, 5 };

foreach (int number in numbers)
{
    Console.WriteLine(number);
}
// Output:
// 1
// 2
// 3
// 4
// 5
```

### Multidimensional Arrays
C# supports multidimensional arrays, such as 2D (two-dimensional) arrays.

#### Declaring a 2D array:
```csharp
int[,] matrix = new int[2, 3];  // 2 rows, 3 columns
```

#### Initializing a 2D array:
```csharp
int[,] matrix = { { 1, 2, 3 }, { 4, 5, 6 } };
```

#### Accessing elements in a 2D array:
```csharp
int[,] matrix = { { 1, 2, 3 }, { 4, 5, 6 } };

Console.WriteLine(matrix[0, 0]);  // Output: 1
Console.WriteLine(matrix[1, 2]);  // Output: 6
```

#### Iterating through a 2D array:
```csharp
int[,] matrix = { { 1, 2, 3 }, { 4, 5, 6 } };

for (int i = 0; i < matrix.GetLength(0); i++)  // Loop through rows
{
    for (int j = 0; j < matrix.GetLength(1); j++)  // Loop through columns
    {
        Console.Write(matrix[i, j] + " ");
    }
    Console.WriteLine();
}
// Output:
// 1 2 3
// 4 5 6
```

### Jagged Arrays
A **jagged array** is an array of arrays, where each element can be a different array (allowing for non-rectangular structures).

#### Declaring a jagged array:
```csharp
int[][] jaggedArray = new int[2][];  // Array with 2 rows
jaggedArray[0] = new int[] { 1, 2, 3 };  // First row has 3 elements
jaggedArray[1] = new int[] { 4, 5 };     // Second row has 2 elements
```

#### Initializing a jagged array:
```csharp
int[][] jaggedArray = {
    new int[] { 1, 2, 3 },
    new int[] { 4, 5 }
};
```

#### Accessing elements in a jagged array:
```csharp
int[][] jaggedArray = {
    new int[] { 1, 2, 3 },
    new int[] { 4, 5 }
};

Console.WriteLine(jaggedArray[0][1]);  // Output: 2 (Second element of the first array)
Console.WriteLine(jaggedArray[1][0]);  // Output: 4 (First element of the second array)
```

#### Iterating through a jagged array:
```csharp
int[][] jaggedArray = {
    new int[] { 1, 2, 3 },
    new int[] { 4, 5 }
};

foreach (var row in jaggedArray)
{
    foreach (var element in row)
    {
        Console.Write(element + " ");
    }
    Console.WriteLine();
}
// Output:
// 1 2 3 
// 4 5
```

### Arrays and Common Methods
C# provides a `System.Array` class with several useful methods for working with arrays.

- **`Array.Sort()`**: Sorts an array.
```csharp
int[] numbers = { 5, 3, 8, 1 };
Array.Sort(numbers);
Console.WriteLine(string.Join(", ", numbers));  // Output: 1, 3, 5, 8
```

- **`Array.Reverse()`**: Reverses the elements of an array.
```csharp
Array.Reverse(numbers);
Console.WriteLine(string.Join(", ", numbers));  // Output: 8, 5, 3, 1
```

- **`Array.Copy()`**: Copies elements from one array to another.
```csharp
int[] copy = new int[4];
Array.Copy(numbers, copy, numbers.Length);
Console.WriteLine(string.Join(", ", copy));  // Output: 8, 5, 3, 1
```

- **`Array.IndexOf()`**: Finds the index of an element in the array.
```csharp
int index = Array.IndexOf(numbers, 5);
Console.WriteLine(index);  // Output: 1 (Index of element 5)
```

### Summary of Arrays in C#:
1. **Declaration**: Arrays are declared using the `type[]` syntax.
2. **Initialization**: Arrays can be initialized using an initializer list, the `new` keyword, or both.
3. **Accessing Elements**: Elements are accessed using an index (starting at 0).
4. **Length**: The `Length` property gives the number of elements in the array.
5. **Iteration**: Arrays can be iterated using loops (`for`, `foreach`).
6. **Multidimensional Arrays**: Support for 2D and higher-dimensional arrays.
7. **Jagged Arrays**: Arrays of arrays, where each element can be a different size.
8. **Common Methods**: `Array.Sort()`, `Array.Reverse()`, `Array.Copy()`, etc.

Arrays are fundamental data structures for storing and manipulating collections of elements in C#. They are simple, efficient, and widely used in many programming tasks.
