### C# - Events

An **event** in C# is a way to provide notifications to clients of a class when something of interest occurs. Events are based on **delegates** and enable a class or object to notify other objects when something significant happens, such as when the state of an object changes or a user interacts with an application.

Events are typically used in the **observer pattern** where multiple objects subscribe to the event, and when the event is triggered, all subscribed handlers are notified.

### Basics of Events

In C#, events are built on top of **delegates** and usually follow the pattern where an event is declared using the `event` keyword, which limits the scope of the delegate to the class that defines it. This provides a level of encapsulation.

The syntax for declaring an event is:

```csharp
public event EventHandler EventName;
```

- `EventHandler` is the type of the delegate associated with the event (most commonly `EventHandler` or `EventHandler<T>`).
- `EventName` is the name of the event.

### Declaring and Raising Events

To declare and raise an event, you will typically:
1. Declare an event using a delegate.
2. Provide a method to raise the event.
3. Define methods (event handlers) to handle the event.

#### Example: Basic Event Handling

```csharp
using System;

public class Publisher
{
    // Declare an event using EventHandler delegate
    public event EventHandler Notify;

    // Method to raise the event
    public void RaiseEvent(string message)
    {
        // Trigger the event if there are any subscribers
        Notify?.Invoke(this, new EventArgs());
        Console.WriteLine(message);
    }
}

public class Subscriber
{
    // Method to handle the event
    public void OnNotify(object sender, EventArgs e)
    {
        Console.WriteLine("Event received!");
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
        publisher.RaiseEvent("Hello, Event triggered!");
    }
}
```

### Explanation:
- **Publisher** class defines an event called `Notify` using the `EventHandler` delegate type.
- The event is raised in the `RaiseEvent` method using `Notify?.Invoke()`.
- **Subscriber** class contains a method `OnNotify`, which is called when the event is triggered.
- The `Notify += subscriber.OnNotify;` line subscribes the `OnNotify` method to the `Notify` event.
- When the `RaiseEvent` method is called, all subscribers to the event will be notified.

### Event Access Modifiers

Events can have access modifiers (e.g., `public`, `private`, `protected`) to control how they can be accessed. Typically, events are declared as **private** or **protected** and are raised using a public method or property.

Example:
```csharp
public class Publisher
{
    // Private event
    private event EventHandler Notify;

    // Public method to raise the event
    public void RaiseEvent(string message)
    {
        Notify?.Invoke(this, new EventArgs());
        Console.WriteLine(message);
    }
}
```

In this example, the event itself is **private**, but it can still be triggered by calling the `RaiseEvent` method.

### Event Handler Signature

Events use **delegates** to define the signature of the event handler methods. The most common event handler signatures are:

- `EventHandler`: Represents methods that handle events that do not have any event data (parameters).
- `EventHandler<T>`: Represents methods that handle events that provide custom event data.

### EventHandler Delegate

The `EventHandler` delegate has the following signature:

```csharp
public delegate void EventHandler(object sender, EventArgs e);
```

- `sender`: The object that triggered the event.
- `e`: The event data, usually an instance of `EventArgs` (or a derived class).

#### Example using EventHandler:

```csharp
using System;

public class Publisher
{
    public event EventHandler Notify;

    public void RaiseEvent()
    {
        // Raising the event
        Notify?.Invoke(this, EventArgs.Empty);
    }
}

public class Subscriber
{
    public void HandleEvent(object sender, EventArgs e)
    {
        Console.WriteLine("Event received!");
    }
}

class Program
{
    static void Main()
    {
        Publisher publisher = new Publisher();
        Subscriber subscriber = new Subscriber();

        // Subscribe to the event
        publisher.Notify += subscriber.HandleEvent;

        // Trigger the event
        publisher.RaiseEvent();
    }
}
```

### EventArgs and Custom Event Arguments

In C#, the `EventArgs` class is used to pass event data. For events that do not carry additional data, `EventArgs.Empty` can be passed. For events with additional data, you can create a custom subclass of `EventArgs`.

#### Example with Custom Event Data:

```csharp
using System;

// Custom EventArgs to pass data with the event
public class NotifyEventArgs : EventArgs
{
    public string Message { get; set; }

    public NotifyEventArgs(string message)
    {
        Message = message;
    }
}

public class Publisher
{
    // Event with custom EventArgs
    public event EventHandler<NotifyEventArgs> Notify;

    public void RaiseEvent(string message)
    {
        Notify?.Invoke(this, new NotifyEventArgs(message));
    }
}

public class Subscriber
{
    public void HandleEvent(object sender, NotifyEventArgs e)
    {
        Console.WriteLine($"Received event: {e.Message}");
    }
}

class Program
{
    static void Main()
    {
        Publisher publisher = new Publisher();
        Subscriber subscriber = new Subscriber();

        // Subscribe to the event
        publisher.Notify += subscriber.HandleEvent;

        // Trigger the event with custom data
        publisher.RaiseEvent("Hello, this is a custom event!");
    }
}
```

### Explanation:
- A custom class `NotifyEventArgs` inherits from `EventArgs` and carries a `Message` property.
- The `Publisher` class raises the event and passes the custom event data (`NotifyEventArgs`) when the event is triggered.
- The `Subscriber` class uses `NotifyEventArgs` to handle the event and access the `Message` data.

### Unsubscribing from Events

You can unsubscribe from an event using the `-=` operator. This ensures that a method will no longer be called when the event is raised.

#### Example of Unsubscribing:

```csharp
publisher.Notify -= subscriber.HandleEvent;
```

This removes the `HandleEvent` method from the event's invocation list.

### Summary of Key Points:

1. **Event Declaration**: Use the `event` keyword to declare events in C#.

2. **Event Raising**: Events are typically raised by calling the delegate (`Notify?.Invoke()`), which triggers all subscribed methods.

3. **Event Handlers**: Event handlers are methods that are called when an event is raised. These methods should match the signature of the event's delegate.

4. **Custom Event Data**: You can pass custom event data by creating a subclass of `EventArgs`.

5. **Multicast Events**: Events in C# can have multiple handlers (subscribers). When the event is triggered, all subscribers are notified.

6. **Unsubscribing**: Use the `-=` operator to remove methods from the event’s invocation list.

7. **Access Modifiers**: Events can be defined with different access levels to control visibility, usually as `private` or `protected`.

8. **Event Handler Types**: Common event handler types include `EventHandler` and `EventHandler<T>` for events with no data or with custom data, respectively.

Events provide a powerful mechanism for loosely coupling components of a program while allowing communication between them. This is especially useful in UI applications (such as WinForms, WPF, or ASP.NET), where user actions trigger events that other components or classes handle.
