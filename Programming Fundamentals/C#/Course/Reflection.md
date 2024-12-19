### C# - Reflection

**Reflection** in C# is a powerful feature that allows you to inspect and interact with the types, methods, properties, fields, and other members of a program at runtime. Reflection enables you to obtain metadata about assemblies, types, and members, and to dynamically create instances, invoke methods, or access fields and properties.

Reflection is part of the `System.Reflection` namespace, and it is commonly used in scenarios such as:

- Inspecting object types or metadata.
- Dynamically creating types or objects.
- Accessing private members (fields, properties, and methods).
- Invoking methods dynamically.
- Handling custom attributes applied to program elements.

### Key Classes in Reflection

1. **`Type`**: Represents type information about an object or class.
2. **`MethodInfo`**: Provides information about methods (e.g., method name, return type, parameters).
3. **`PropertyInfo`**: Provides information about properties (e.g., name, type).
4. **`FieldInfo`**: Provides information about fields (e.g., field name, type).
5. **`ConstructorInfo`**: Provides information about constructors.
6. **`Assembly`**: Provides information about the assembly, which is a compiled .NET code library.
7. **`MemberInfo`**: A base class for `MethodInfo`, `FieldInfo`, `PropertyInfo`, etc.

### Basic Reflection Operations

#### 1. **Getting Type Information**

You can use the `Type` class to get metadata about a type. This can be done using the `GetType()` method on an object or directly by the `typeof` operator.

```csharp
using System;

public class Example
{
    public int MyProperty { get; set; }

    public void MyMethod() 
    {
        Console.WriteLine("Method executed");
    }

    public static void Main()
    {
        Example obj = new Example();
        
        // Getting Type using GetType() method
        Type type = obj.GetType();
        Console.WriteLine("Type Name: " + type.Name);  // Prints the class name

        // Alternatively using typeof operator
        Type type2 = typeof(Example);
        Console.WriteLine("Full Name: " + type2.FullName);  // Prints the full class name (namespace + class name)
    }
}
```

### Explanation:
- **`GetType()`**: Returns the `Type` object of the instance, representing the class/type of the object.
- **`typeof()`**: Returns the `Type` object representing the specified class type.

#### 2. **Inspecting Members (Methods, Properties, Fields)**

Once you have a `Type` object, you can use it to inspect members of the class, such as methods, properties, and fields.

```csharp
using System;
using System.Reflection;

public class Example
{
    public int MyField;

    public void MyMethod()
    {
        Console.WriteLine("Method executed");
    }

    public int MyProperty { get; set; }

    public static void Main()
    {
        Example obj = new Example();
        Type type = obj.GetType();

        // Get and display methods
        Console.WriteLine("Methods:");
        MethodInfo[] methods = type.GetMethods();
        foreach (var method in methods)
        {
            Console.WriteLine(method.Name);
        }

        // Get and display properties
        Console.WriteLine("Properties:");
        PropertyInfo[] properties = type.GetProperties();
        foreach (var property in properties)
        {
            Console.WriteLine(property.Name);
        }

        // Get and display fields
        Console.WriteLine("Fields:");
        FieldInfo[] fields = type.GetFields();
        foreach (var field in fields)
        {
            Console.WriteLine(field.Name);
        }
    }
}
```

### Explanation:
- **`GetMethods()`**: Returns all methods of the type (including inherited methods).
- **`GetProperties()`**: Returns all properties of the type.
- **`GetFields()`**: Returns all fields of the type (public, private, and inherited).

#### 3. **Invoking Methods Dynamically**

You can use reflection to invoke methods dynamically at runtime.

```csharp
using System;
using System.Reflection;

public class Example
{
    public void Greet(string name)
    {
        Console.WriteLine($"Hello, {name}!");
    }

    public static void Main()
    {
        Example obj = new Example();
        Type type = obj.GetType();
        MethodInfo method = type.GetMethod("Greet");

        // Invoke method dynamically
        method.Invoke(obj, new object[] { "John" });  // Output: Hello, John!
    }
}
```

### Explanation:
- **`GetMethod()`**: Retrieves a `MethodInfo` object that represents a specific method by name.
- **`Invoke()`**: Executes the method dynamically, passing the object instance and parameters as arguments.

#### 4. **Accessing Properties and Fields Dynamically**

Reflection also allows you to get and set values of properties and fields at runtime.

##### Accessing a Property:
```csharp
using System;
using System.Reflection;

public class Example
{
    public string Name { get; set; }

    public static void Main()
    {
        Example obj = new Example();
        Type type = obj.GetType();
        PropertyInfo property = type.GetProperty("Name");

        // Set property value
        property.SetValue(obj, "John Doe");

        // Get property value
        string name = (string)property.GetValue(obj);
        Console.WriteLine(name);  // Output: John Doe
    }
}
```

##### Accessing a Field:
```csharp
using System;
using System.Reflection;

public class Example
{
    public int Age;

    public static void Main()
    {
        Example obj = new Example();
        Type type = obj.GetType();
        FieldInfo field = type.GetField("Age");

        // Set field value
        field.SetValue(obj, 30);

        // Get field value
        int age = (int)field.GetValue(obj);
        Console.WriteLine(age);  // Output: 30
    }
}
```

### Explanation:
- **`GetProperty()`**: Retrieves the `PropertyInfo` object for a specific property.
- **`SetValue()`**: Sets the value of the property.
- **`GetValue()`**: Gets the value of the property.
- **`GetField()`**: Retrieves the `FieldInfo` object for a specific field.
- **`SetValue()`** and **`GetValue()`** can also be used for fields.

#### 5. **Creating Instances Dynamically**

Reflection can be used to create instances of types at runtime using the `Activator.CreateInstance()` method or `ConstructorInfo`.

##### Using `Activator.CreateInstance()`:
```csharp
using System;

public class Example
{
    public Example(string message)
    {
        Console.WriteLine(message);
    }

    public static void Main()
    {
        Type type = typeof(Example);
        
        // Creating an instance using Activator
        object obj = Activator.CreateInstance(type, "Hello from Reflection!");
    }
}
```

##### Using `ConstructorInfo`:
```csharp
using System;
using System.Reflection;

public class Example
{
    private string message;
    
    public Example(string message)
    {
        this.message = message;
        Console.WriteLine(message);
    }

    public static void Main()
    {
        Type type = typeof(Example);
        ConstructorInfo constructor = type.GetConstructor(new[] { typeof(string) });

        // Create an instance using ConstructorInfo
        object obj = constructor.Invoke(new object[] { "Hello from ConstructorInfo!" });
    }
}
```

### Explanation:
- **`Activator.CreateInstance()`**: Dynamically creates an instance of a specified type.
- **`GetConstructor()`**: Retrieves the constructor information for the type, based on parameter types.
- **`Invoke()`**: Creates the instance by invoking the constructor with specified parameters.

#### 6. **Custom Attributes and Reflection**

You can use reflection to access custom attributes applied to classes, methods, and other members at runtime.

```csharp
using System;

[AttributeUsage(AttributeTargets.Class | AttributeTargets.Method)]
public class DeveloperInfoAttribute : Attribute
{
    public string DeveloperName { get; }

    public DeveloperInfoAttribute(string developerName)
    {
        DeveloperName = developerName;
    }
}

[DeveloperInfo("Alice")]
public class Example
{
    [DeveloperInfo("Bob")]
    public void MyMethod()
    {
        // Some code
    }

    public static void Main()
    {
        Type type = typeof(Example);
        
        // Access class attribute
        var classAttribute = (DeveloperInfoAttribute)Attribute.GetCustomAttribute(type, typeof(DeveloperInfoAttribute));
        Console.WriteLine("Class Developer: " + classAttribute.DeveloperName);

        // Access method attribute
        var method = type.GetMethod("MyMethod");
        var methodAttribute = (DeveloperInfoAttribute)Attribute.GetCustomAttribute(method, typeof(DeveloperInfoAttribute));
        Console.WriteLine("Method Developer: " + methodAttribute.DeveloperName);
    }
}
```

### Explanation:
- **`GetCustomAttribute()`**: Retrieves a custom attribute applied to the class or method.
- **`AttributeUsage`**: Specifies where the attribute can be applied (e.g., to classes, methods).

### Summary of Key Reflection Concepts:

1. **Type Inspection**: Use `Type.GetType()` or `typeof` to inspect types, get members, and analyze type metadata.
2. **Method Invocation**: Use `MethodInfo.Invoke()` to invoke methods dynamically.
3. **Accessing Fields and Properties**: Use `FieldInfo.GetValue()` and `PropertyInfo.GetValue()` to access values dynamically.
4. **Creating Instances**: Use `Activator.CreateInstance()` or `ConstructorInfo.Invoke()` to create instances at runtime.
5. **Custom Attributes**: Use reflection to access and process custom attributes dynamically.
6. **Reflection Performance**: Reflection is slower than direct code execution, so use it carefully in performance-critical applications.

Reflection provides a powerful way to work with types, methods, and properties dynamically at runtime, enabling more flexible and generic code. However, it comes with performance overhead and should be used judiciously.
