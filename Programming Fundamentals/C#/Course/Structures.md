### C# - Structures

A **structure** in C# is a value type that is used to represent a collection of related data items. Unlike classes, which are reference types, structures are stored on the stack, which means that they are typically more efficient in terms of memory allocation. However, structures have limitations compared to classes, such as not supporting inheritance (other than from `System.ValueType`).

### Key Characteristics of Structures:
1. **Value Type**: A structure is a value type, meaning that when you assign a structure to another, a copy of the value is made (as opposed to references in classes).
2. **Cannot Inherit from Other Structures or Classes**: Structures cannot inherit from other structures or classes (except from `System.ValueType`).
3. **Can Implement Interfaces**: Structures can implement interfaces, allowing for polymorphic behavior.
4. **No Default Constructor**: A structure cannot have a default constructor (one with no parameters). It has an implicit parameterless constructor provided by the system.
5. **Smaller Memory Footprint**: Structures are typically smaller in memory than classes because they are allocated on the stack, making them useful for small, frequently used data types.

### Declaring a Structure
A structure is defined using the `struct` keyword followed by the name of the structure. It can contain fields, properties, methods, and constructors.

#### Syntax for Declaring a Structure:
```csharp
struct StructureName
{
    // Fields
    public int field1;
    public string field2;

    // Constructor
    public StructureName(int f1, string f2)
    {
        field1 = f1;
        field2 = f2;
    }

    // Method
    public void Display()
    {
        Console.WriteLine($"Field1: {field1}, Field2: {field2}");
    }
}
```

### Example: Basic Structure
Here’s an example of a simple structure in C# that represents a **Point** with two coordinates, `x` and `y`:

```csharp
using System;

struct Point
{
    public int x;
    public int y;

    // Constructor to initialize the fields
    public Point(int xValue, int yValue)
    {
        x = xValue;
        y = yValue;
    }

    // Method to display point coordinates
    public void Display()
    {
        Console.WriteLine($"Point coordinates: ({x}, {y})");
    }
}

class Program
{
    static void Main(string[] args)
    {
        // Create an instance of the Point structure
        Point p1 = new Point(10, 20);
        p1.Display();  // Output: Point coordinates: (10, 20)

        // Copying the structure (value type, so a copy is made)
        Point p2 = p1;
        p2.x = 30;  // Modifying p2 does not affect p1
        p2.Display();  // Output: Point coordinates: (30, 20)
        p1.Display();  // Output: Point coordinates: (10, 20)
    }
}
```

### Differences Between Classes and Structures
- **Memory Allocation**:
  - Classes are reference types and are stored on the heap.
  - Structures are value types and are stored on the stack.
  
- **Inheritance**:
  - Classes support inheritance, meaning you can derive new classes from base classes.
  - Structures do not support inheritance (other than from `System.ValueType`).
  
- **Default Constructor**:
  - Classes can have custom constructors, including default constructors.
  - Structures cannot define a default constructor (one with no parameters) as it is implicitly provided by the compiler.

- **Nullability**:
  - Classes can be `null` (indicating no instance).
  - Structures cannot be `null`, but you can use **nullable types** (`T?`) to allow a structure to hold `null`.

### Constructors in Structures
- Structures can have constructors with parameters, but **cannot have a parameterless constructor** (i.e., one with no parameters).
- When you create an instance of a structure, the compiler automatically provides a default parameterless constructor that initializes all fields to their default values (e.g., `0` for `int`, `null` for `string`).

#### Example:
```csharp
struct Person
{
    public string Name;
    public int Age;

    // Constructor with parameters
    public Person(string name, int age)
    {
        Name = name;
        Age = age;
    }

    // Method to display the information
    public void Display()
    {
        Console.WriteLine($"Name: {Name}, Age: {Age}");
    }
}

class Program
{
    static void Main(string[] args)
    {
        // Create a structure instance using the constructor
        Person person1 = new Person("Alice", 30);
        person1.Display();  // Output: Name: Alice, Age: 30
    }
}
```

### Structs and Methods

A structure can contain methods, just like classes. These methods can perform operations on the data contained within the structure.

#### Example:
```csharp
struct Rectangle
{
    public int width;
    public int height;

    public Rectangle(int w, int h)
    {
        width = w;
        height = h;
    }

    // Method to calculate the area of the rectangle
    public int Area()
    {
        return width * height;
    }
}

class Program
{
    static void Main(string[] args)
    {
        Rectangle rect = new Rectangle(5, 10);
        Console.WriteLine($"Area of rectangle: {rect.Area()}");  // Output: Area of rectangle: 50
    }
}
```

### Passing Structures to Methods
Structures are passed by value to methods, meaning a copy of the structure is passed. If you modify the structure within the method, it does not affect the original structure.

#### Example:
```csharp
struct Circle
{
    public int radius;

    public Circle(int r)
    {
        radius = r;
    }

    // Method to display radius
    public void Display()
    {
        Console.WriteLine($"Radius: {radius}");
    }
}

class Program
{
    static void ModifyRadius(Circle c)
    {
        c.radius = 20;  // Modify the radius (affects only the local copy)
    }

    static void Main(string[] args)
    {
        Circle circle = new Circle(10);
        circle.Display();  // Output: Radius: 10

        ModifyRadius(circle);
        circle.Display();  // Output: Radius: 10 (unchanged)
    }
}
```

### Nullable Structures
While structures themselves cannot be `null`, you can use **nullable types** (`T?`) to allow a structure to hold a `null` value.

#### Example of Nullable Structures:
```csharp
struct Temperature
{
    public int Value;

    public Temperature(int value)
    {
        Value = value;
    }
}

class Program
{
    static void Main(string[] args)
    {
        Temperature? temp = null;  // Nullable structure
        if (temp == null)
        {
            Console.WriteLine("Temperature is not set.");
        }
    }
}
```

### Summary of Structures in C#
1. **Value Type**: Structures are value types, meaning they are copied by value when assigned or passed to methods.
2. **Cannot Inherit**: Structures cannot inherit from other types, except `System.ValueType`.
3. **Memory**: Structures are stored on the stack, unlike classes, which are stored on the heap.
4. **Efficient for Small Data**: Structures are useful for representing small data types, such as points, colors, and complex numbers.
5. **Cannot Have Default Constructors**: Structures cannot define a parameterless constructor.
6. **Nullable**: Structures can be made nullable using the `?` modifier to represent the absence of a value.

Structures are valuable for encapsulating small groups of related data efficiently while avoiding the overhead of heap allocation. However, they have limitations compared to classes, such as immutability and lack of inheritance support.
