### C# - Classes

A **class** in C# is a reference type that serves as a blueprint for creating objects. Classes define the properties, methods, and behaviors of objects and provide a way to encapsulate data and functionality. In object-oriented programming, classes allow you to model real-world entities and their interactions.

### Key Concepts of Classes in C#
1. **Object-Oriented**: C# classes are fundamental to object-oriented programming, allowing you to define objects and work with them.
2. **Reference Type**: A class is a reference type, which means that when you assign a class instance to another variable, both variables refer to the same object in memory.
3. **Encapsulation**: Classes support encapsulation, meaning they allow you to group data (fields) and methods that operate on the data into a single unit.
4. **Inheritance**: Classes can inherit from other classes, which means they can reuse and extend functionality from base classes.
5. **Polymorphism**: Classes support polymorphism, enabling objects to be treated as instances of their base type, allowing methods to be overridden for specific behaviors.
6. **Abstraction**: Classes help in abstracting complex details and exposing only necessary functionality.

### Declaring a Class
A class is defined using the `class` keyword, followed by the class name. A class can have fields (variables), methods (functions), properties, and constructors.

#### Basic Syntax:
```csharp
class ClassName
{
    // Fields (Variables)
    public int field1;
    private string field2;

    // Constructor
    public ClassName(int f1, string f2)
    {
        field1 = f1;
        field2 = f2;
    }

    // Methods (Functions)
    public void DisplayInfo()
    {
        Console.WriteLine($"Field1: {field1}, Field2: {field2}");
    }

    // Properties
    public string Field2
    {
        get { return field2; }
        set { field2 = value; }
    }
}
```

### Example of a Class in Use:
```csharp
using System;

class Person
{
    // Fields
    public string Name;
    public int Age;

    // Constructor to initialize fields
    public Person(string name, int age)
    {
        Name = name;
        Age = age;
    }

    // Method to display person's details
    public void Display()
    {
        Console.WriteLine($"Name: {Name}, Age: {Age}");
    }
}

class Program
{
    static void Main()
    {
        // Create an instance (object) of the Person class
        Person person1 = new Person("Alice", 30);
        person1.Display();  // Output: Name: Alice, Age: 30

        // Create another instance
        Person person2 = new Person("Bob", 25);
        person2.Display();  // Output: Name: Bob, Age: 25
    }
}
```

### Key Components of a Class

1. **Fields**: Fields are variables defined inside a class to store data.
   - Fields can be of any data type (primitive types, arrays, or other objects).
   - Fields can have access modifiers (e.g., `public`, `private`, `protected`) to define visibility.

2. **Constructors**: Constructors are special methods used to initialize objects of a class.
   - A constructor has the same name as the class.
   - If no constructor is defined, a default parameterless constructor is provided automatically.
   - You can define parameterized constructors to initialize objects with specific values.

   Example of Constructor:
   ```csharp
   public class Person
   {
       public string Name;
       public int Age;

       // Constructor with parameters
       public Person(string name, int age)
       {
           Name = name;
           Age = age;
       }
   }
   ```

3. **Methods**: Methods define the behavior or functionality of a class.
   - Methods can accept parameters and return values.
   - You can define methods to perform operations on class fields or perform actions related to the class.

   Example of a Method:
   ```csharp
   public void Display()
   {
       Console.WriteLine($"Name: {Name}, Age: {Age}");
   }
   ```

4. **Properties**: Properties are special methods that provide a way to get and set the values of private fields.
   - Properties use `get` and `set` accessors to control access to a field.
   - Properties can be read-only, write-only, or both.

   Example of a Property:
   ```csharp
   public string Name { get; set; }
   ```

5. **Access Modifiers**: These modifiers determine the accessibility of a class, field, method, or property.
   - `public`: Accessible from anywhere.
   - `private`: Accessible only within the class.
   - `protected`: Accessible within the class and by derived classes.
   - `internal`: Accessible within the same assembly.
   - `protected internal`: Accessible within the same assembly or by derived classes.

6. **Static Members**: Static members belong to the class itself rather than to instances of the class.
   - A static field or method is shared among all instances of the class.

   Example of a Static Method:
   ```csharp
   class MyClass
   {
       public static int Count;

       public static void DisplayCount()
       {
           Console.WriteLine($"Count: {Count}");
       }
   }
   ```

7. **Destructors**: A destructor is called when an object is destroyed, typically used to clean up resources (e.g., closing file handles).
   - Destructors are automatically called by the garbage collector.

   Example of a Destructor:
   ```csharp
   ~Person()
   {
       Console.WriteLine("Destructor called for Person");
   }
   ```

### Inheritance in C# Classes

Inheritance allows one class to inherit fields, methods, and properties from another class. The class that is inherited from is called the **base class**, and the class that inherits is called the **derived class**.

#### Example of Inheritance:
```csharp
using System;

// Base Class
class Animal
{
    public string Name;

    public void Eat()
    {
        Console.WriteLine($"{Name} is eating.");
    }
}

// Derived Class
class Dog : Animal
{
    public void Bark()
    {
        Console.WriteLine($"{Name} is barking.");
    }
}

class Program
{
    static void Main()
    {
        Dog dog = new Dog();
        dog.Name = "Buddy";
        dog.Eat();   // Output: Buddy is eating.
        dog.Bark();  // Output: Buddy is barking.
    }
}
```

### Polymorphism

Polymorphism allows derived classes to provide a specific implementation of methods that are already defined in the base class. The base class defines the method, and the derived class overrides it to provide specific behavior.

#### Example of Polymorphism:
```csharp
using System;

// Base Class
class Animal
{
    public virtual void Sound()
    {
        Console.WriteLine("Animal makes a sound");
    }
}

// Derived Class
class Dog : Animal
{
    public override void Sound()
    {
        Console.WriteLine("Dog barks");
    }
}

class Program
{
    static void Main()
    {
        Animal animal = new Animal();
        animal.Sound();  // Output: Animal makes a sound

        Animal dog = new Dog();
        dog.Sound();  // Output: Dog barks
    }
}
```

In the above example, the method `Sound()` is overridden in the `Dog` class to provide a different implementation than the one in the `Animal` class.

### Abstraction

Abstraction is the concept of hiding the implementation details and exposing only the necessary parts of an object or class. This is achieved using abstract classes or interfaces in C#.

- **Abstract Classes**: You can declare a class as `abstract` to prevent it from being instantiated directly.
- **Abstract Methods**: Abstract methods are declared without implementation and must be implemented by derived classes.

#### Example of an Abstract Class:
```csharp
abstract class Animal
{
    public string Name;
    public abstract void MakeSound();
}

class Dog : Animal
{
    public override void MakeSound()
    {
        Console.WriteLine("Woof");
    }
}

class Program
{
    static void Main()
    {
        Dog dog = new Dog();
        dog.Name = "Buddy";
        dog.MakeSound();  // Output: Woof
    }
}
```

### Summary of Classes in C#
1. **Class Definition**: A class is a blueprint for creating objects that encapsulates data and behavior.
2. **Fields and Methods**: A class can contain fields (variables), methods (functions), and properties (getters/setters).
3. **Constructors**: Constructors are special methods for initializing new objects.
4. **Inheritance**: A class can inherit from another class to reuse code and extend functionality.
5. **Polymorphism**: A class can override methods in derived classes to provide specialized behavior.
6. **Encapsulation**: Classes encapsulate data and provide controlled access through methods and properties.
7. **Abstraction**: Abstract classes or methods provide a way to define methods that must be implemented by derived classes.

Classes are a cornerstone of object-oriented programming and provide a way to model real-world objects, abstracting complexity and promoting code reuse.
