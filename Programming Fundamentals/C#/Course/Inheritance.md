### C# - Inheritance

**Inheritance** is a key feature of object-oriented programming (OOP) in C# that allows a class to inherit fields, methods, and properties from another class. Inheritance enables code reuse and the creation of hierarchical relationships between classes.

In C#, inheritance is implemented using the `: (colon)` symbol. A class that inherits from another class is called a **derived class**, and the class being inherited from is called the **base class**.

### Key Concepts of Inheritance
1. **Base Class**: The class that is inherited from. It provides common functionality that is shared by its derived classes.
2. **Derived Class**: The class that inherits from a base class. It can extend or override the functionality of the base class.
3. **Method Overriding**: Derived classes can provide their own implementation of methods defined in the base class.
4. **Access to Base Class Members**: The derived class can access the public and protected members of the base class but not the private members.

### Basic Syntax of Inheritance

#### Base Class
```csharp
class BaseClass
{
    public int baseField;

    public BaseClass(int value)
    {
        baseField = value;
    }

    public void Display()
    {
        Console.WriteLine($"Base class value: {baseField}");
    }
}
```

#### Derived Class
```csharp
class DerivedClass : BaseClass
{
    public int derivedField;

    // Constructor for the derived class
    public DerivedClass(int baseValue, int derivedValue) : base(baseValue)
    {
        derivedField = derivedValue;
    }

    // Overriding a method from the base class
    public new void Display()
    {
        Console.WriteLine($"Base class value: {baseField}, Derived class value: {derivedField}");
    }
}
```

### Example of Inheritance in C#

```csharp
using System;

class Animal
{
    public string Name;

    // Base class constructor
    public Animal(string name)
    {
        Name = name;
    }

    // Method in the base class
    public void Eat()
    {
        Console.WriteLine($"{Name} is eating.");
    }

    // Virtual method to be overridden in derived class
    public virtual void MakeSound()
    {
        Console.WriteLine("Animal makes a sound.");
    }
}

class Dog : Animal
{
    // Constructor of the derived class
    public Dog(string name) : base(name) { }

    // Method overriding the base class method
    public override void MakeSound()
    {
        Console.WriteLine($"{Name} barks.");
    }
}

class Program
{
    static void Main()
    {
        Animal animal = new Animal("Generic Animal");
        animal.Eat();             // Output: Generic Animal is eating.
        animal.MakeSound();       // Output: Animal makes a sound.

        Dog dog = new Dog("Buddy");
        dog.Eat();                // Output: Buddy is eating.
        dog.MakeSound();          // Output: Buddy barks.
    }
}
```

### Key Features of Inheritance in C#

1. **Constructor Inheritance**:
   - The derived class can call the constructor of the base class using the `base` keyword.
   - If the base class constructor requires parameters, the derived class must call the base constructor with appropriate arguments.

   Example:
   ```csharp
   class BaseClass
   {
       public int x;
       public BaseClass(int value) { x = value; }
   }

   class DerivedClass : BaseClass
   {
       public DerivedClass(int value) : base(value) { }
   }
   ```

2. **Overriding Methods**:
   - Methods in the base class can be marked as `virtual`, which allows derived classes to override the method with their own implementation using the `override` keyword.
   - If a method is not marked as `virtual`, it cannot be overridden, and attempting to do so will result in a compile-time error.

   Example of Overriding a Method:
   ```csharp
   class Animal
   {
       public virtual void Sound()
       {
           Console.WriteLine("Animal makes a sound");
       }
   }

   class Dog : Animal
   {
       public override void Sound()
       {
           Console.WriteLine("Dog barks");
       }
   }
   ```

3. **`new` Keyword**:
   - When a method in the derived class has the same name as one in the base class, you can use the `new` keyword to hide the base class method instead of overriding it.

   Example:
   ```csharp
   class BaseClass
   {
       public void Display()
       {
           Console.WriteLine("Base class display");
       }
   }

   class DerivedClass : BaseClass
   {
       public new void Display()
       {
           Console.WriteLine("Derived class display");
       }
   }

   class Program
   {
       static void Main()
       {
           BaseClass baseClass = new BaseClass();
           baseClass.Display();  // Output: Base class display

           DerivedClass derivedClass = new DerivedClass();
           derivedClass.Display();  // Output: Derived class display
       }
   }
   ```

4. **Base Class Access Modifiers**:
   - A derived class can access `public` and `protected` members of the base class, but it cannot access `private` members directly.
   - `protected` members are only accessible within the base and derived classes.

   Example:
   ```csharp
   class BaseClass
   {
       public int publicField;
       protected int protectedField;

       public BaseClass(int value)
       {
           publicField = value;
           protectedField = value;
       }
   }

   class DerivedClass : BaseClass
   {
       public DerivedClass(int value) : base(value) { }

       public void ShowFields()
       {
           Console.WriteLine($"Public: {publicField}, Protected: {protectedField}");
       }
   }
   ```

5. **`sealed` Keyword**:
   - A class can be marked as `sealed`, which means it cannot be inherited from.
   - A method can also be marked as `sealed` to prevent it from being overridden further in derived classes.

   Example of Sealing a Class:
   ```csharp
   sealed class SealedClass
   {
       public void Show()
       {
           Console.WriteLine("This class cannot be inherited.");
       }
   }

   // The following would result in a compile-time error:
   // class DerivedClass : SealedClass { }
   ```

6. **`virtual` and `override` Keywords**:
   - The `virtual` keyword is used to indicate that a method in the base class can be overridden in the derived class.
   - The `override` keyword is used in the derived class to provide a new implementation for a method defined as `virtual` in the base class.

   Example of Virtual Method and Override:
   ```csharp
   class Animal
   {
       public virtual void MakeSound()
       {
           Console.WriteLine("Animal sound");
       }
   }

   class Dog : Animal
   {
       public override void MakeSound()
       {
           Console.WriteLine("Woof");
       }
   }
   ```

### Inheritance and Constructor Chaining
When a derived class is instantiated, its constructor first calls the constructor of the base class (using `base()`), followed by its own constructor. This is called **constructor chaining**.

#### Example of Constructor Chaining:
```csharp
class Animal
{
    public string Name;

    public Animal(string name)
    {
        Name = name;
    }
}

class Dog : Animal
{
    public string Breed;

    public Dog(string name, string breed) : base(name)
    {
        Breed = breed;
    }
}

class Program
{
    static void Main()
    {
        Dog dog = new Dog("Buddy", "Golden Retriever");
        Console.WriteLine($"Name: {dog.Name}, Breed: {dog.Breed}");
        // Output: Name: Buddy, Breed: Golden Retriever
    }
}
```

### Summary of Inheritance in C#
1. **Base Class**: Provides common functionality that can be inherited by derived classes.
2. **Derived Class**: Inherits members from a base class and can add new members or override inherited members.
3. **Access Modifiers**: `public` and `protected` members of the base class are accessible in derived classes, but `private` members are not.
4. **Method Overriding**: Methods in the base class can be marked `virtual` and overridden in the derived class using the `override` keyword.
5. **Constructor Chaining**: A derived class constructor can call the base class constructor using `base()`.
6. **Polymorphism**: Inheritance allows for polymorphic behavior, where a base class reference can refer to derived class objects and invoke overridden methods.

Inheritance allows the creation of a more hierarchical and reusable design, where base classes provide common behavior and derived classes extend or modify this behavior.
