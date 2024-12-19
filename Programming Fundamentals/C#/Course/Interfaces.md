### C# - Interfaces

An **interface** in C# defines a contract that classes or structs can implement. It is a way to specify that a class must implement certain methods and properties but without providing the implementation of those methods. An interface only defines the method signatures (or property signatures), and the implementing class is responsible for providing the actual implementation.

Interfaces are a powerful feature in object-oriented programming that helps to decouple systems, enhance flexibility, and enable polymorphism.

### Key Characteristics of Interfaces:
- **No implementation**: Interfaces cannot contain any implementation (except for default interface methods, introduced in C# 8.0). They only contain method and property declarations.
- **Only method and property declarations**: Interfaces can declare methods, properties, events, and indexers, but they cannot define fields or constructors.
- **Multiple interfaces**: A class can implement multiple interfaces, which allows for multiple inheritance of behavior.
- **Abstract methods**: All methods in an interface are by default `abstract`, meaning they do not have any body.
- **Cannot instantiate**: You cannot create instances of an interface directly. You must create an instance of a class that implements the interface.

### Syntax for Defining an Interface

```csharp
public interface IMyInterface
{
    // Method declarations
    void Method1();
    int Method2(int a);

    // Property declaration
    string Property { get; set; }
}
```

### Example: Implementing an Interface in C#

Let’s create a simple interface `IDriveable` and implement it in two different classes, `Car` and `Bicycle`.

```csharp
using System;

// Define an interface IDriveable
public interface IDriveable
{
    // Method declaration
    void StartEngine();

    // Property declaration
    int Speed { get; set; }

    // Method for stopping the vehicle
    void Stop();
}

// Class Car implementing IDriveable
public class Car : IDriveable
{
    public int Speed { get; set; }

    public void StartEngine()
    {
        Console.WriteLine("The car engine starts.");
    }

    public void Stop()
    {
        Console.WriteLine("The car stops.");
    }
}

// Class Bicycle implementing IDriveable
public class Bicycle : IDriveable
{
    public int Speed { get; set; }

    public void StartEngine()
    {
        Console.WriteLine("Bicycles don't have an engine, but you start pedaling.");
    }

    public void Stop()
    {
        Console.WriteLine("The bicycle stops.");
    }
}

class Program
{
    static void Main()
    {
        IDriveable myCar = new Car();
        myCar.StartEngine();
        myCar.Speed = 60;
        Console.WriteLine("Car Speed: " + myCar.Speed + " km/h");
        myCar.Stop();

        IDriveable myBicycle = new Bicycle();
        myBicycle.StartEngine();
        myBicycle.Speed = 15;
        Console.WriteLine("Bicycle Speed: " + myBicycle.Speed + " km/h");
        myBicycle.Stop();
    }
}
```

### Breakdown:
1. **IDriveable Interface**:
   - The `IDriveable` interface declares the method `StartEngine()`, the property `Speed`, and the method `Stop()`.
2. **Car and Bicycle Classes**:
   - Both `Car` and `Bicycle` implement the `IDriveable` interface, providing their own implementations for the methods and the `Speed` property.
3. **Polymorphism**:
   - In the `Main` method, both a `Car` and a `Bicycle` object are treated as `IDriveable` objects. This demonstrates polymorphism where the same interface is used to represent different types of vehicles.
4. **Multiple Implementations**:
   - The `Car` class implements the `StartEngine()` method differently than the `Bicycle` class, even though they share the same interface.

### Interface Properties

In C#, interfaces can also declare properties, events, and indexers. However, interfaces cannot provide any implementation for them. They only define the signature.

#### Example with Interface Property:

```csharp
using System;

public interface IShape
{
    double Area { get; }
    double Perimeter { get; }
}

public class Rectangle : IShape
{
    public double Length { get; set; }
    public double Width { get; set; }

    public double Area => Length * Width;
    public double Perimeter => 2 * (Length + Width);
}

public class Circle : IShape
{
    public double Radius { get; set; }

    public double Area => Math.PI * Radius * Radius;
    public double Perimeter => 2 * Math.PI * Radius;
}

class Program
{
    static void Main()
    {
        IShape rectangle = new Rectangle { Length = 5, Width = 3 };
        IShape circle = new Circle { Radius = 4 };

        Console.WriteLine($"Rectangle Area: {rectangle.Area}, Perimeter: {rectangle.Perimeter}");
        Console.WriteLine($"Circle Area: {circle.Area}, Perimeter: {circle.Perimeter}");
    }
}
```

### Key Points:
- **Properties**: Both `Rectangle` and `Circle` implement the `Area` and `Perimeter` properties as required by the `IShape` interface, but the implementation is different for each class.
- **Read-only properties**: In the interface, we can define read-only properties, i.e., properties that only have a `get` accessor but no `set`.

### Multiple Interface Implementation

In C#, a class can implement more than one interface. This allows for greater flexibility, as a class can inherit behavior from multiple sources.

#### Example: Multiple Interface Implementation

```csharp
using System;

public interface IPlayable
{
    void Play();
}

public interface IRecordable
{
    void Record();
}

public class MediaDevice : IPlayable, IRecordable
{
    public void Play()
    {
        Console.WriteLine("Playing media.");
    }

    public void Record()
    {
        Console.WriteLine("Recording media.");
    }
}

class Program
{
    static void Main()
    {
        MediaDevice device = new MediaDevice();
        device.Play();    // Output: Playing media.
        device.Record();  // Output: Recording media.
    }
}
```

### Key Points:
- **Multiple Interfaces**: The `MediaDevice` class implements both `IPlayable` and `IRecordable`. This allows it to play and record, as defined in the interfaces.

### Interface Inheritance

Interfaces can inherit from other interfaces. This allows you to build more complex contracts while maintaining reusability.

#### Example: Interface Inheritance

```csharp
using System;

public interface IPlayable
{
    void Play();
}

public interface IRecordable : IPlayable
{
    void Record();
}

public class MediaDevice : IRecordable
{
    public void Play()
    {
        Console.WriteLine("Playing media.");
    }

    public void Record()
    {
        Console.WriteLine("Recording media.");
    }
}

class Program
{
    static void Main()
    {
        MediaDevice device = new MediaDevice();
        device.Play();    // Output: Playing media.
        device.Record();  // Output: Recording media.
    }
}
```

### Key Points:
- **Inheritance in Interfaces**: The `IRecordable` interface inherits from the `IPlayable` interface, so any class that implements `IRecordable` must also implement `Play()`.

### Summary of Interfaces in C#

- **Interfaces define a contract**: They specify which methods and properties a class should implement without providing the implementation itself.
- **Multiple interfaces**: A class can implement multiple interfaces, allowing for flexible and reusable designs.
- **Inheritance between interfaces**: Interfaces can inherit from other interfaces, creating hierarchies of contracts.
- **Polymorphism**: Interfaces are commonly used to implement polymorphism, as objects can be treated as their interface type, allowing for flexibility and dynamic behavior.
- **Separation of concerns**: Interfaces help in decoupling code and promote a clear separation of concerns, making the system easier to maintain and extend.
