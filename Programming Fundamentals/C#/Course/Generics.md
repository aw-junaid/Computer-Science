### C# - Generics

Generics in C# provide a way to create classes, methods, interfaces, and delegates that can work with any data type without sacrificing type safety or performance. By using generics, you can define a type or method that works with any data type while ensuring type safety at compile time. This allows for the reuse of code without needing to specify the data type ahead of time.

Generics are part of the **System.Collections.Generic** namespace and are frequently used in C# to create type-safe collections, algorithms, and data structures.

### Benefits of Generics:

1. **Type Safety**: Generics enable compile-time checking of types, eliminating the need for type casting and reducing the chance of runtime errors.
2. **Code Reusability**: Generics allow you to write a single implementation of a class or method that works with different data types.
3. **Performance**: Generics avoid the performance overhead associated with boxing and unboxing (when using non-generic collections like `ArrayList`).

### Generic Types in C#

#### 1. **Generic Classes**

A **generic class** is a class that works with different types. You can define a placeholder type parameter that can later be replaced with any type when creating an instance of the class.

#### Example: Generic Class

```csharp
using System;

public class Box<T>
{
    private T _value;

    public void SetValue(T value)
    {
        _value = value;
    }

    public T GetValue()
    {
        return _value;
    }
}

class Program
{
    static void Main()
    {
        // Create a Box for an integer
        Box<int> intBox = new Box<int>();
        intBox.SetValue(100);
        Console.WriteLine(intBox.GetValue());  // Output: 100

        // Create a Box for a string
        Box<string> strBox = new Box<string>();
        strBox.SetValue("Hello, Generics!");
        Console.WriteLine(strBox.GetValue());  // Output: Hello, Generics!
    }
}
```

- `T` is the **type parameter**. When creating an instance of the class, you specify the type you want to use (e.g., `int` or `string`).
- The type parameter `T` is replaced by the actual type at compile time.

#### 2. **Generic Methods**

A **generic method** allows you to define a method that can work with different types without having to specify the type beforehand.

#### Example: Generic Method

```csharp
using System;

class Program
{
    // Generic method that works with any type
    public static void Print<T>(T item)
    {
        Console.WriteLine(item);
    }

    static void Main()
    {
        // Call generic method with an integer
        Print(42);  // Output: 42

        // Call generic method with a string
        Print("Hello, World!");  // Output: Hello, World!
    }
}
```

- The method `Print<T>` can work with any type `T`. You don't need to define a separate method for each type.

#### 3. **Generic Interfaces**

Interfaces can also be generic, allowing you to define common behavior for various types.

#### Example: Generic Interface

```csharp
using System;

public interface IContainer<T>
{
    void AddItem(T item);
    T GetItem();
}

public class StringContainer : IContainer<string>
{
    private string _item;

    public void AddItem(string item)
    {
        _item = item;
    }

    public string GetItem()
    {
        return _item;
    }
}

class Program
{
    static void Main()
    {
        // Create a container for strings
        IContainer<string> container = new StringContainer();
        container.AddItem("Generics are powerful!");
        Console.WriteLine(container.GetItem());  // Output: Generics are powerful!
    }
}
```

- The interface `IContainer<T>` can be implemented by any class that specifies a type for `T`, making it reusable with different types.

#### 4. **Generic Constraints**

C# allows you to apply **constraints** on the type parameters of generic types or methods. Constraints restrict the types that can be used with a generic type.

Common constraints include:
- `where T : struct` – restricts `T` to value types (like `int`, `float`, etc.).
- `where T : class` – restricts `T` to reference types.
- `where T : new()` – restricts `T` to types that have a public parameterless constructor.
- `where T : SomeClass` – restricts `T` to types that derive from a specific class.
- `where T : IComparable` – restricts `T` to types that implement the `IComparable` interface.

#### Example: Generic Method with Constraints

```csharp
using System;

public class Calculator
{
    // Generic method with constraints
    public static T Add<T>(T a, T b) where T : struct
    {
        dynamic x = a;
        dynamic y = b;
        return x + y;
    }
}

class Program
{
    static void Main()
    {
        // Add integers
        Console.WriteLine(Calculator.Add(10, 20));  // Output: 30

        // Add doubles
        Console.WriteLine(Calculator.Add(10.5, 20.5));  // Output: 31
    }
}
```

- The `Add<T>` method is constrained to work only with value types (`struct`).
- The `dynamic` keyword allows arithmetic operations on `T` by at runtime, enabling flexibility in the method.

### 5. **Generic Collections**

The .NET Framework provides several generic collections in the `System.Collections.Generic` namespace, which are designed to work with specific types.

#### Example: List<T> (Generic Collection)

```csharp
using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        // Create a List of integers
        List<int> numbers = new List<int>();

        // Add elements to the list
        numbers.Add(1);
        numbers.Add(2);
        numbers.Add(3);

        // Loop through the list and print each element
        foreach (int number in numbers)
        {
            Console.WriteLine(number);
        }
    }
}
```

- **List<T>** is a dynamic collection that stores elements of type `T`. It provides methods like `Add()`, `Remove()`, and `Contains()`, and is more efficient than non-generic collections like `ArrayList`.

### 6. **Generic Delegates**

A **generic delegate** allows you to define a delegate type that can operate on any data type.

#### Example: Generic Delegate

```csharp
using System;

public delegate T Add<T>(T a, T b);

class Program
{
    static void Main()
    {
        // Create a delegate for adding integers
        Add<int> addIntegers = (a, b) => a + b;
        Console.WriteLine(addIntegers(10, 20));  // Output: 30

        // Create a delegate for adding doubles
        Add<double> addDoubles = (a, b) => a + b;
        Console.WriteLine(addDoubles(10.5, 20.5));  // Output: 31
    }
}
```

- The delegate `Add<T>` can be used with any data type, making it reusable for different operations.

### 7. **Variance in Generics**

**Variance** allows you to use more specific (derived) or more general (base) types than the ones declared in a generic type. This is most commonly used with **delegates** and **interfaces**.

- **Covariant**: You can use a more derived type than specified by the generic type parameter. This is used with **out** parameters.
- **Contravariant**: You can use a more general type than specified by the generic type parameter. This is used with **in** parameters.

#### Example: Covariance and Contravariance with Generics

```csharp
using System;
using System.Collections.Generic;

public class Animal { }
public class Dog : Animal { }

class Program
{
    static void Main()
    {
        // Covariant (using out) – can assign to a more derived type
        IEnumerable<Dog> dogs = new List<Dog>();
        IEnumerable<Animal> animals = dogs;  // Covariance

        // Contravariant (using in) – can assign to a more general type
        Action<Animal> animalAction = a => Console.WriteLine(a.GetType());
        Action<Dog> dogAction = animalAction;  // Contravariance
        dogAction(new Dog());  // Output: Dog
    }
}
```

- Covariant (`out`) allows a more derived type (e.g., `Dog`) to be assigned to a base type (`Animal`).
- Contravariant (`in`) allows a more general type (e.g., `Animal`) to be assigned to a derived type (`Dog`).

### Summary

1. **Generics** provide type safety, code reusability, and improved performance by eliminating the need for type casting and reducing boxing/unboxing.
2. **Generic classes, methods, interfaces, and delegates** allow you to define reusable code that works with any data type.
3. **Constraints** allow you to apply restrictions on the types used with generics, such as requiring value types or types that implement a specific interface.
4. **Generic collections** (e.g., `List<T>`, `Dictionary<TKey, TValue>`) are more efficient and type-safe than non-generic collections.
5. **Variance** enables more flexibility when using generic types in interfaces and delegates.

Generics are a powerful feature in C# that allows for safer, more efficient, and more flexible code. By using generics, you can write reusable algorithms and data structures without losing type safety.
