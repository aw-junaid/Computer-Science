### C# - Anonymous Methods

**Anonymous methods** in C# are a way to define a method without giving it a name. These methods can be used inline, where you would typically pass a delegate. Anonymous methods provide a concise and flexible way to write code, especially when working with delegates, events, and LINQ queries.

Anonymous methods allow you to write small, reusable functions directly in the place where they are needed, which improves readability and reduces the need for boilerplate code.

#### Key Characteristics:
1. **No name**: An anonymous method does not have a method name.
2. **Delegate type**: It is associated with a specific delegate type when passed.
3. **Inline usage**: It is written inline as part of an expression or event handler.

### Syntax of Anonymous Methods

An anonymous method is defined using the `delegate` keyword followed by a block of code. It can either take parameters or not, depending on the type of delegate it's associated with.

```csharp
delegate void MyDelegate(string message);

MyDelegate myDelegate = delegate (string message)
{
    Console.WriteLine("Message: " + message);
};
myDelegate("Hello, Anonymous Method!");
```

Here, the `delegate` keyword is used to define an anonymous method that matches the signature of the `MyDelegate` delegate.

### Example of Anonymous Methods

#### Example 1: Simple Anonymous Method

```csharp
using System;

class Program
{
    delegate void DisplayMessage(string message);

    static void Main()
    {
        // Anonymous method that matches the delegate signature
        DisplayMessage display = delegate (string message)
        {
            Console.WriteLine("Message: " + message);
        };

        // Calling the anonymous method
        display("Hello, Anonymous Method!");  // Output: Message: Hello, Anonymous Method!
    }
}
```

- Here, the anonymous method is assigned to the `display` delegate.
- It takes a `string` parameter and writes the message to the console.

#### Example 2: Anonymous Method with Multiple Parameters

```csharp
using System;

class Program
{
    delegate int AddNumbers(int num1, int num2);

    static void Main()
    {
        // Anonymous method to add two numbers
        AddNumbers add = delegate (int num1, int num2)
        {
            return num1 + num2;
        };

        // Calling the anonymous method
        Console.WriteLine("Sum: " + add(10, 20));  // Output: Sum: 30
    }
}
```

- The anonymous method takes two `int` parameters and returns their sum.

#### Example 3: Anonymous Method as an Event Handler

```csharp
using System;

class Program
{
    // Declare an event
    public event EventHandler<EventArgs> MyEvent;

    static void Main()
    {
        Program program = new Program();

        // Subscribe to the event with an anonymous method
        program.MyEvent += delegate (object sender, EventArgs e)
        {
            Console.WriteLine("Event triggered!");
        };

        // Trigger the event
        program.MyEvent?.Invoke(program, EventArgs.Empty);  // Output: Event triggered!
    }
}
```

- In this example, an anonymous method is used as an event handler. It gets triggered when the event `MyEvent` is invoked.

### Advantages of Anonymous Methods

1. **Conciseness**: They allow you to write smaller, inline methods without needing a full method definition elsewhere in your code.
2. **Readability**: It is easier to write event handlers or delegate-based code without needing to separately define a method.
3. **Less Boilerplate**: You don’t have to declare a separate method in a class when the functionality is small and used only in one place.

### Limitations of Anonymous Methods

1. **No method name**: Since anonymous methods don't have a name, they can't be reused directly elsewhere.
2. **Cannot be used as method overrides**: You cannot override methods using anonymous methods.
3. **Scope issues**: Variables used inside an anonymous method must be in scope, which could potentially lead to unintended variable captures.

### Anonymous Methods vs. Lambda Expressions

In C#, **lambda expressions** were introduced as a more concise and flexible alternative to anonymous methods. While both can be used to define inline code, lambda expressions provide a more powerful and simpler syntax, especially for LINQ queries and delegates.

#### Lambda Expression Example

```csharp
using System;

class Program
{
    delegate int AddNumbers(int num1, int num2);

    static void Main()
    {
        // Lambda expression to add two numbers
        AddNumbers add = (num1, num2) => num1 + num2;

        // Calling the lambda expression
        Console.WriteLine("Sum: " + add(10, 20));  // Output: Sum: 30
    }
}
```

- The lambda expression `(num1, num2) => num1 + num2` provides a more concise way to write the same functionality as an anonymous method.

### Summary:

- **Anonymous methods** provide a way to define inline methods without names and are often used with delegates, events, and callbacks.
- They are useful for small, one-off functionality, making the code more concise and easier to maintain.
- **Lambda expressions** are an advanced feature that provides an even more concise syntax for anonymous methods, and they are often preferred in modern C# code.
