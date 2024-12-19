### C# - Delegates

A **delegate** in C# is a type that represents references to methods with a particular parameter list and return type. Essentially, delegates are used to define method signatures that can then be called dynamically, making them powerful tools for implementing callbacks, event handling, and designing flexible systems.

In simple terms, a delegate is a type-safe function pointer. It allows methods to be passed as parameters and invoked at runtime, offering great flexibility.

### Basics of Delegates

To declare a delegate in C#, you use the `delegate` keyword, followed by the return type, the delegate name, and the parameters it will accept.

#### Delegate Declaration

```csharp
public delegate returnType DelegateName(parameterType1 parameter1, parameterType2 parameter2, ...);
```

- `returnType`: The return type of the methods that the delegate can point to.
- `DelegateName`: The name of the delegate type.
- `parameterType1`, `parameterType2`, ...: The parameter types that the delegate will accept.

#### Example: Basic Delegate

```csharp
using System;

public delegate void PrintMessageDelegate(string message);

class Program
{
    static void Main()
    {
        // Creating a delegate instance and assigning a method
        PrintMessageDelegate printDelegate = PrintMessage;

        // Calling the delegate (which calls PrintMessage)
        printDelegate("Hello, Delegates!");
    }

    // Method that matches the delegate signature
    static void PrintMessage(string message)
    {
        Console.WriteLine(message);
    }
}
```

### Explanation:
- The `PrintMessageDelegate` is a delegate type that can point to methods that accept a `string` parameter and return `void`.
- The delegate `printDelegate` is created and assigned to the `PrintMessage` method.
- When `printDelegate("Hello, Delegates!")` is called, it invokes the `PrintMessage` method.

### Delegate Types

C# has built-in delegates, such as:

1. **Action**: Represents a method that returns `void` and can have parameters.
2. **Func**: Represents a method that returns a value and can have parameters.
3. **Predicate**: Represents a method that takes one parameter and returns a `bool`.

#### Example with `Action`:

```csharp
using System;

class Program
{
    static void Main()
    {
        // Action delegate that points to a method with no return type and one parameter
        Action<string> greetAction = Greet;
        greetAction("Hello from Action Delegate!");
    }

    static void Greet(string message)
    {
        Console.WriteLine(message);
    }
}
```

- The `Action<string>` delegate represents methods that take one `string` parameter and return `void`.

#### Example with `Func`:

```csharp
using System;

class Program
{
    static void Main()
    {
        // Func delegate that returns a string and takes an integer parameter
        Func<int, string> numberToString = NumberToString;
        string result = numberToString(123);
        Console.WriteLine(result);
    }

    static string NumberToString(int number)
    {
        return "The number is " + number;
    }
}
```

- The `Func<int, string>` delegate represents methods that take an `int` parameter and return a `string`.

#### Example with `Predicate`:

```csharp
using System;

class Program
{
    static void Main()
    {
        // Predicate delegate that returns a boolean based on an integer parameter
        Predicate<int> isEven = IsEven;
        Console.WriteLine(isEven(4));  // Output: True
        Console.WriteLine(isEven(5));  // Output: False
    }

    static bool IsEven(int number)
    {
        return number % 2 == 0;
    }
}
```

- The `Predicate<int>` delegate represents methods that take an `int` parameter and return a `bool`.

### Multicast Delegates

In C#, delegates can point to more than one method. This is known as **multicasting**. When a delegate is invoked, all methods in the invocation list are called, in the order they were added.

To create a multicast delegate, you can use the `+=` operator to add methods to the delegate's invocation list.

#### Example: Multicast Delegate

```csharp
using System;

public delegate void DisplayMessage(string message);

class Program
{
    static void Main()
    {
        // Creating delegate instances
        DisplayMessage displayDelegate = PrintMessage1;
        displayDelegate += PrintMessage2;

        // Calling the multicast delegate
        displayDelegate("Hello, Multicast Delegates!");
    }

    static void PrintMessage1(string message)
    {
        Console.WriteLine("Message 1: " + message);
    }

    static void PrintMessage2(string message)
    {
        Console.WriteLine("Message 2: " + message);
    }
}
```

### Explanation:
- The `displayDelegate` is a multicast delegate that first points to `PrintMessage1` and then to `PrintMessage2`.
- When `displayDelegate("Hello, Multicast Delegates!")` is invoked, both `PrintMessage1` and `PrintMessage2` are called in sequence.

### Removing Methods from Delegate Invocation List

You can also remove methods from the delegate's invocation list using the `-=` operator.

```csharp
displayDelegate -= PrintMessage1;  // Removes PrintMessage1 from invocation list
```

### Delegate Compatibility

For a delegate to be compatible with a method, the method must match the delegate’s signature. The return type and parameters (including the number and type) must be identical.

### Anonymous Methods and Lambda Expressions

C# allows you to define inline delegate methods using **anonymous methods** or **lambda expressions**.

#### Example with Anonymous Method:

```csharp
using System;

class Program
{
    static void Main()
    {
        // Using an anonymous method to define the delegate body
        Action<string> greetAction = delegate (string message)
        {
            Console.WriteLine("Anonymous Method: " + message);
        };

        greetAction("Hello from Anonymous Method!");
    }
}
```

#### Example with Lambda Expression:

```csharp
using System;

class Program
{
    static void Main()
    {
        // Using a lambda expression to define the delegate body
        Action<string> greetAction = message => Console.WriteLine("Lambda Expression: " + message);

        greetAction("Hello from Lambda Expression!");
    }
}
```

### Explanation:
- **Anonymous Method**: Defines the method inline using the `delegate` keyword.
- **Lambda Expression**: A more concise syntax for defining inline methods. The `=>` operator separates the parameter list from the method body.

### Delegates in Event Handling

Delegates are the foundation of **events** in C#. Events use delegates to specify what methods should be called when an event is raised.

#### Example: Event Handling with Delegates

```csharp
using System;

public delegate void NotifyEventHandler(string message);

public class Publisher
{
    public event NotifyEventHandler Notify;

    public void RaiseEvent(string message)
    {
        Notify?.Invoke(message);
    }
}

public class Subscriber
{
    public void OnNotify(string message)
    {
        Console.WriteLine("Received event: " + message);
    }
}

class Program
{
    static void Main()
    {
        Publisher publisher = new Publisher();
        Subscriber subscriber = new Subscriber();

        // Subscribe to the event
        publisher.Notify += subscriber.OnNotify;

        // Raise the event
        publisher.RaiseEvent("Event triggered!");
    }
}
```

### Explanation:
- `NotifyEventHandler` is a delegate type used to handle events.
- The `Publisher` class declares an event `Notify`, which is triggered when the `RaiseEvent` method is called.
- The `Subscriber` class defines the `OnNotify` method that handles the event.
- The `Notify += subscriber.OnNotify;` statement subscribes the `OnNotify` method to the `Notify` event.
- When the `RaiseEvent` method is called, the `OnNotify` method is executed.

### Summary of Key Points:

1. **Delegate Declaration**: A delegate defines the signature for methods it can reference.
   - Example: `public delegate void PrintMessageDelegate(string message);`

2. **Multicast Delegates**: A delegate can reference multiple methods, and all methods in the invocation list are called when the delegate is invoked.

3. **Anonymous Methods**: You can define methods inline without naming them, using the `delegate` keyword.

4. **Lambda Expressions**: A more concise way to define methods inline, often used with delegates.

5. **Event Handling**: Delegates are used to define events and to specify what methods should be called when an event is raised.

6. **Action, Func, and Predicate**: These built-in delegates provide commonly used method signatures and simplify delegate creation.

Delegates in C# provide powerful functionality for working with callbacks, events, and flexible method invocation. They promote type safety, better abstraction, and more readable code.
