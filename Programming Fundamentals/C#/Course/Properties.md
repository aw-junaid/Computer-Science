### C# - Properties

**Properties** in C# are members of a class that provide a mechanism to read, write, or compute the value of a private field indirectly. They are similar to fields but provide more control over the access to the underlying data. Properties can be used to enforce validation, modify behavior, or hide implementation details from the outside world while still allowing access to the data.

Properties have two main components:

1. **Getters**: A method (or code block) that retrieves the value of the property.
2. **Setters**: A method (or code block) that assigns a value to the property.

### Basic Syntax for Properties

Properties are declared using the following syntax:

```csharp
public type PropertyName { get; set; }
```

Here:
- `type`: The data type of the property.
- `PropertyName`: The name of the property.
- `get`: Retrieves the value of the property.
- `set`: Assigns a value to the property.

### Example: Basic Property

```csharp
using System;

public class Person
{
    // Private field
    private string name;

    // Property to get and set the name
    public string Name
    {
        get { return name; }  // Getter retrieves the value of the private field
        set { name = value; } // Setter assigns the value to the private field
    }
}

class Program
{
    static void Main()
    {
        Person person = new Person();
        person.Name = "John";  // Set the value using the setter
        Console.WriteLine(person.Name);  // Get the value using the getter
    }
}
```

### Explanation:
- The `Name` property encapsulates access to the private field `name`.
- The `get` accessor retrieves the value of `name`.
- The `set` accessor assigns a value to `name`.

### Read-Only and Write-Only Properties

You can define properties that are either read-only (can only be accessed via `get`) or write-only (can only be set via `set`).

#### Read-Only Property:

```csharp
public class Person
{
    private string name;

    // Read-only property
    public string Name
    {
        get { return name; }
    }

    public Person(string name)
    {
        this.name = name;
    }
}
```

### Explanation:
- The `Name` property can only be read, not modified outside the class.

#### Write-Only Property:

```csharp
public class Person
{
    private string name;

    // Write-only property
    public string Name
    {
        set { name = value; }
    }
}
```

### Explanation:
- The `Name` property can only be set, not read outside the class.

### Auto-Implemented Properties

C# allows for auto-implemented properties where the compiler automatically creates a private field to back the property. You don't need to explicitly declare a private field.

```csharp
public class Person
{
    // Auto-implemented property
    public string Name { get; set; }
}
```

### Explanation:
- The `Name` property is automatically backed by a private, compiler-generated field.
- Auto-implemented properties are useful when you don't need to perform any additional logic in the `get` or `set` methods.

### Read-Only Auto-Implemented Properties

In C# 6.0 and later, you can also define read-only auto-implemented properties, where the property can only be set in the constructor and is read-only elsewhere.

```csharp
public class Person
{
    // Read-only auto-implemented property
    public string Name { get; }

    public Person(string name)
    {
        Name = name;  // Set the value in the constructor
    }
}
```

### Explanation:
- The `Name` property is automatically read-only, and its value is set via the constructor.

### Computed Properties

You can use properties to compute values based on other data in the class.

```csharp
public class Rectangle
{
    private double width;
    private double height;

    public double Width
    {
        get { return width; }
        set { width = value; }
    }

    public double Height
    {
        get { return height; }
        set { height = value; }
    }

    // Computed property to get the area of the rectangle
    public double Area
    {
        get { return width * height; }
    }
}
```

### Explanation:
- The `Area` property calculates the area of the rectangle based on its width and height.
- It has only a `get` accessor since it is computed dynamically.

### Property Access Modifiers

You can apply access modifiers to the `get` and `set` accessors separately, allowing different levels of access.

```csharp
public class Person
{
    private string name;

    // The get is public, but the set is private
    public string Name
    {
        get { return name; }
        private set { name = value; }  // Private setter
    }
}
```

### Explanation:
- The `get` accessor is `public`, so the property can be read from outside the class.
- The `set` accessor is `private`, so the property can only be set within the class.

### Using Properties in Object Initialization

In C#, you can use properties for object initialization in an initializer block.

```csharp
public class Person
{
    public string Name { get; set; }
    public int Age { get; set; }
}

class Program
{
    static void Main()
    {
        // Using object initializer to set property values
        Person person = new Person { Name = "John", Age = 30 };
        Console.WriteLine($"Name: {person.Name}, Age: {person.Age}");
    }
}
```

### Explanation:
- The object initializer syntax allows setting property values directly when creating the object.

### Property Validation

You can perform validation inside the `set` accessor to ensure that the value being assigned meets certain criteria.

```csharp
public class Person
{
    private int age;

    public int Age
    {
        get { return age; }
        set
        {
            if (value < 0)
                throw new ArgumentException("Age cannot be negative");
            age = value;
        }
    }
}
```

### Explanation:
- The `set` accessor checks if the value being assigned to `age` is valid (non-negative in this case).
- If an invalid value is provided, an exception is thrown.

### Property vs Field

While properties and fields may seem similar, they serve different purposes in C#. 

- **Fields**: Directly hold data. Typically private, and accessible only within the class.
- **Properties**: Provide controlled access to fields and can include logic for getting or setting values. They allow for validation, computation, or modification before assigning or retrieving values.

### Summary of Key Points:

- **Basic Property Syntax**: `public type PropertyName { get; set; }`
- **Auto-Implemented Properties**: Simplified properties that are automatically backed by private fields.
- **Read-Only and Write-Only Properties**: You can control the accessibility of properties using `get` and `set` accessors.
- **Computed Properties**: Properties that return a value computed from other data in the class.
- **Access Modifiers**: You can apply different access levels to `get` and `set` accessors.
- **Object Initializer Syntax**: Allows setting property values at the time of object creation.
- **Property Validation**: You can validate data before setting property values.

Properties in C# provide a structured, controlled way to access and modify data, and they can enforce logic such as validation, calculation, or encapsulation of the underlying implementation.
