An extended C# cheat sheet that covers essential commands, syntax, and concepts. This cheat sheet includes variables, data types, control structures, methods, classes, interfaces, collections, LINQ, and more.

---

## **1. Basic Syntax**

### 1.1 Hello World Program

```csharp
using System;

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Hello, World!");
    }
}
```

**Explanation**: This program uses `Console.WriteLine()` to print "Hello, World!" to the console. The `Main` method is the entry point of a C# application.

---

## **2. Variables and Data Types**

### 2.1 Declaring Variables

```csharp
int number = 10;                   // Integer
double price = 19.99;             // Double
char letter = 'A';                // Character
string name = "Alice";            // String
bool isActive = true;             // Boolean
```

**Explanation**: C# supports several data types, including integers, doubles, characters, strings, and booleans.

### 2.2 Implicitly Typed Variables

```csharp
var age = 25;                     // Implicitly typed variable
```

**Explanation**: The `var` keyword allows the compiler to infer the type of the variable based on the assigned value.

---

## **3. Control Structures**

### 3.1 If-Else Statement

```csharp
if (number > 0)
{
    Console.WriteLine("Positive");
}
else if (number < 0)
{
    Console.WriteLine("Negative");
}
else
{
    Console.WriteLine("Zero");
}
```

**Explanation**: The `if-else` statement is used for conditional branching.

### 3.2 Switch Statement

```csharp
switch (number)
{
    case 1:
        Console.WriteLine("One");
        break;
    case 2:
        Console.WriteLine("Two");
        break;
    default:
        Console.WriteLine("Other");
        break;
}
```

**Explanation**: The `switch` statement evaluates an expression and matches it against multiple cases.

### 3.3 For Loop

```csharp
for (int i = 0; i < 5; i++)
{
    Console.WriteLine(i);
}
```

**Explanation**: The `for` loop iterates a specific number of times.

### 3.4 Foreach Loop

```csharp
string[] fruits = { "Apple", "Banana", "Cherry" };
foreach (string fruit in fruits)
{
    Console.WriteLine(fruit);
}
```

**Explanation**: The `foreach` loop iterates over a collection, such as an array or a list.

---

## **4. Methods**

### 4.1 Defining and Calling Methods

```csharp
void Greet(string name)
{
    Console.WriteLine($"Hello, {name}!");
}

// Calling the method
Greet("Alice");
```

**Explanation**: Methods are defined with a return type and can take parameters.

### 4.2 Returning Values

```csharp
int Add(int a, int b)
{
    return a + b;
}

// Using the method
int sum = Add(5, 3);
```

**Explanation**: Methods can return values using the `return` statement.

### 4.3 Overloading Methods

```csharp
int Add(int a, int b) => a + b;
double Add(double a, double b) => a + b;

// Calling overloaded methods
int intSum = Add(5, 3);
double doubleSum = Add(5.5, 3.3);
```

**Explanation**: Method overloading allows you to define multiple methods with the same name but different parameter types.

---

## **5. Classes and Objects**

### 5.1 Defining a Class

```csharp
class Person
{
    public string Name { get; set; }
    public int Age { get; set; }

    public void Introduce()
    {
        Console.WriteLine($"My name is {Name} and I am {Age} years old.");
    }
}
```

**Explanation**: Classes can contain fields, properties, and methods.

### 5.2 Creating an Object

```csharp
Person person = new Person();
person.Name = "Alice";
person.Age = 25;
person.Introduce(); // Outputs: My name is Alice and I am 25 years old.
```

**Explanation**: Create an instance of a class using the `new` keyword.

### 5.3 Constructors

```csharp
class Person
{
    public string Name { get; }
    public int Age { get; }

    public Person(string name, int age)
    {
        Name = name;
        Age = age;
    }
}

// Creating an object using the constructor
Person person = new Person("Alice", 25);
```

**Explanation**: Constructors are special methods used to initialize objects.

### 5.4 Inheritance

```csharp
class Student : Person
{
    public string Major { get; set; }

    public Student(string name, int age, string major) : base(name, age)
    {
        Major = major;
    }
}

// Creating an object of the derived class
Student student = new Student("Alice", 25, "Computer Science");
```

**Explanation**: Inheritance allows a class to inherit properties and methods from another class.

---

## **6. Interfaces**

### 6.1 Defining an Interface

```csharp
interface IAnimal
{
    void Speak();
}

class Dog : IAnimal
{
    public void Speak()
    {
        Console.WriteLine("Woof!");
    }
}
```

**Explanation**: Interfaces define contracts that classes must implement.

### 6.2 Implementing an Interface

```csharp
IAnimal dog = new Dog();
dog.Speak(); // Outputs: Woof!
```

**Explanation**: Classes implement interfaces to provide specific functionality.

---

## **7. Collections**

### 7.1 Arrays

```csharp
int[] numbers = { 1, 2, 3, 4, 5 };
```

**Explanation**: Arrays are fixed-size collections of elements of the same type.

### 7.2 Lists

```csharp
using System.Collections.Generic;

List<string> fruits = new List<string>();
fruits.Add("Apple");
fruits.Add("Banana");
```

**Explanation**: `List<T>` is a dynamic collection that can grow in size.

### 7.3 Dictionaries

```csharp
Dictionary<string, int> ages = new Dictionary<string, int>();
ages["Alice"] = 25;
ages["Bob"] = 30;
```

**Explanation**: `Dictionary<TKey, TValue>` stores key-value pairs.

---

## **8. LINQ (Language Integrated Query)**

### 8.1 Basic LINQ Query

```csharp
using System.Linq;

int[] numbers = { 1, 2, 3, 4, 5 };
var evenNumbers = from n in numbers
                  where n % 2 == 0
                  select n;

foreach (var num in evenNumbers)
{
    Console.WriteLine(num); // Outputs: 2, 4
}
```

**Explanation**: LINQ allows you to query collections using a SQL-like syntax.

### 8.2 Method Syntax

```csharp
var evenNumbers = numbers.Where(n => n % 2 == 0);
```

**Explanation**: LINQ can also be used with method syntax for more concise queries.

---

## **9. Exception Handling**

### 9.1 Try-Catch Block

```csharp
try
{
    int result = 10 / 0; // This will throw an exception
}
catch (DivideByZeroException ex)
{
    Console.WriteLine("Cannot divide by zero.");
}
finally
{
    Console.WriteLine("Execution completed.");
}
```

**Explanation**: Use `try-catch` to handle exceptions and prevent crashes.

---

## **10. File I/O**

### 10.1 Reading and Writing Files

```csharp
using System.IO;

// Writing to a file
File.WriteAllText("example.txt", "Hello, World!");

// Reading from a file
string content = File.ReadAllText("example.txt");
Console.WriteLine(content); // Outputs: Hello, World!
```

**Explanation**: Use `File` class methods to read from and write to files.

---

## **11. Asynchronous Programming**

### 11.1 Async and Await

```csharp
using System.Net.Http;
using System.Threading.Tasks;

async Task<string> FetchDataAsync(string url)
{
    using (HttpClient client = new HttpClient())
    {
        return await client.GetStringAsync(url);
    }
}
```

**Explanation**: Use `async` and `await` keywords to perform asynchronous operations without blocking the main thread.

---

## **12. Attributes**

### 12.1 Defining and Using Attributes

```csharp
[Obsolete("This method is obsolete.")]
void OldMethod()
{
    // Some code
}
```

**Explanation**: Attributes provide metadata about the program elements, like marking a method as obsolete.

---

## **Conclusion**

This cheat sheet provides a comprehensive overview of essential commands and concepts in C#. Regular practice with these concepts will help you become proficient in C# programming.
