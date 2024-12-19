### C# - Polymorphism

**Polymorphism** is one of the core concepts of object-oriented programming (OOP) that allows objects of different classes to be treated as objects of a common base class. In C#, polymorphism enables methods to perform different tasks based on the object calling them, even if they share the same method signature. It allows for flexibility and the ability to write more generalized and reusable code.

Polymorphism comes in two primary forms in C#:
1. **Compile-time Polymorphism** (also called **Static Polymorphism**)
2. **Run-time Polymorphism** (also called **Dynamic Polymorphism**)

### 1. **Compile-time Polymorphism (Static Polymorphism)**
   - This type of polymorphism is resolved at compile time.
   - It is achieved through **method overloading** and **operator overloading**.
   - In **method overloading**, multiple methods with the same name but different parameters (either by number, type, or both) can be defined in the same class.

#### Example of Method Overloading (Compile-time Polymorphism):
```csharp
using System;

class Calculator
{
    // Method to add two integers
    public int Add(int a, int b)
    {
        return a + b;
    }

    // Overloaded method to add three integers
    public int Add(int a, int b, int c)
    {
        return a + b + c;
    }

    // Overloaded method to add two doubles
    public double Add(double a, double b)
    {
        return a + b;
    }
}

class Program
{
    static void Main()
    {
        Calculator calc = new Calculator();

        Console.WriteLine(calc.Add(2, 3));        // Output: 5
        Console.WriteLine(calc.Add(2, 3, 4));     // Output: 9
        Console.WriteLine(calc.Add(2.5, 3.5));    // Output: 6
    }
}
```
- **Method Overloading**: The method `Add` is overloaded with different parameters (two integers, three integers, and two doubles). The appropriate method is chosen at compile-time based on the arguments passed.

### 2. **Run-time Polymorphism (Dynamic Polymorphism)**
   - This type of polymorphism is resolved at runtime.
   - It is achieved through **method overriding** using **inheritance** and **interfaces**.
   - The most common use case for run-time polymorphism is when a method in the derived class overrides a method in the base class. The type of the object, rather than the reference, determines which version of the method is called.

#### Key Concepts of Run-time Polymorphism:
- **Virtual Method**: A method in the base class that is marked with the `virtual` keyword to indicate that it can be overridden by derived classes.
- **Override Method**: A method in the derived class that provides a specific implementation of a virtual method from the base class.

#### Example of Run-time Polymorphism (Method Overriding):
```csharp
using System;

class Animal
{
    public string Name;

    public Animal(string name)
    {
        Name = name;
    }

    // Virtual method to be overridden
    public virtual void MakeSound()
    {
        Console.WriteLine("Animal makes a sound");
    }
}

class Dog : Animal
{
    public Dog(string name) : base(name) { }

    // Override the MakeSound method
    public override void MakeSound()
    {
        Console.WriteLine("Dog barks");
    }
}

class Cat : Animal
{
    public Cat(string name) : base(name) { }

    // Override the MakeSound method
    public override void MakeSound()
    {
        Console.WriteLine("Cat meows");
    }
}

class Program
{
    static void Main()
    {
        Animal myAnimal = new Animal("Generic Animal");
        Animal myDog = new Dog("Buddy");
        Animal myCat = new Cat("Whiskers");

        myAnimal.MakeSound();  // Output: Animal makes a sound
        myDog.MakeSound();     // Output: Dog barks
        myCat.MakeSound();     // Output: Cat meows
    }
}
```
- **Explanation**:
  - The `MakeSound` method is defined as `virtual` in the `Animal` class and overridden in the `Dog` and `Cat` classes.
  - The actual method called is determined by the object type at runtime, not the reference type.
  - Even though all three objects (`myAnimal`, `myDog`, `myCat`) are of type `Animal`, the correct `MakeSound` method is called based on the actual object type (`Animal`, `Dog`, or `Cat`).

### Polymorphism with Interfaces

Polymorphism can also be achieved through interfaces. In this case, multiple classes can implement the same interface, and the behavior of the methods defined in the interface can be implemented differently in each class.

#### Example of Polymorphism with Interfaces:
```csharp
using System;

interface IAnimal
{
    void MakeSound();
}

class Dog : IAnimal
{
    public void MakeSound()
    {
        Console.WriteLine("Dog barks");
    }
}

class Cat : IAnimal
{
    public void MakeSound()
    {
        Console.WriteLine("Cat meows");
    }
}

class Program
{
    static void Main()
    {
        IAnimal animal1 = new Dog();
        IAnimal animal2 = new Cat();

        animal1.MakeSound();  // Output: Dog barks
        animal2.MakeSound();  // Output: Cat meows
    }
}
```
- **Explanation**:
  - The `IAnimal` interface defines the `MakeSound` method.
  - Both `Dog` and `Cat` implement this interface and provide their own implementation of `MakeSound`.
  - The method that gets called is based on the actual type of the object (`Dog` or `Cat`), not the reference type (`IAnimal`).

### Advantages of Polymorphism
1. **Code Reusability**: Polymorphism allows you to write more flexible and reusable code. You can use a common interface or base class to refer to objects of different types.
2. **Maintainability**: You can modify the implementation of methods in derived classes without affecting the code that uses the base class or interface.
3. **Extensibility**: Polymorphism makes it easy to extend the system by adding new classes that implement common methods or interfaces.

### Summary of Polymorphism in C#

1. **Compile-time Polymorphism (Static Polymorphism)**:
   - Achieved through **method overloading** and **operator overloading**.
   - Resolved at compile time based on method signatures.

2. **Run-time Polymorphism (Dynamic Polymorphism)**:
   - Achieved through **method overriding**.
   - Involves base and derived classes, where the base class defines virtual methods and derived classes override them.
   - The method invoked is determined at runtime based on the object's actual type.

3. **Interface Polymorphism**:
   - Multiple classes can implement the same interface, providing different implementations for the interface methods.

4. **Benefits**: 
   - Code reusability, maintainability, and extensibility.
   - Allows classes to work interchangeably when they share a common interface or base class, promoting flexibility.

Polymorphism enhances the flexibility and scalability of object-oriented systems by enabling objects to be treated in a general way, allowing for easier maintenance and extension of the codebase.
