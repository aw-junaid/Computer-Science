### C# - Operator Overloading

**Operator Overloading** in C# allows you to define or customize the behavior of operators (such as `+`, `-`, `*`, etc.) for user-defined types (such as classes and structs). This means that you can provide specific implementations for these operators, so they behave differently depending on the types of operands involved.

### Key Points:
- **Overloading operators** allows a class or struct to define how operators like `+`, `-`, `*`, `==`, and others work when applied to objects of that class or struct.
- Not all operators can be overloaded in C#. For example, the `.` (dot) operator, `new`, and `sizeof` cannot be overloaded.
- Overloaded operators must always be defined as `public` and `static`.
- When overloading operators, it is essential to preserve their intuitive meaning to ensure readability and maintainability.

### Syntax for Operator Overloading

```csharp
public static returnType operator operatorSymbol(type operand1, type operand2)
{
    // Method body to define operator behavior
}
```

### Example of Operator Overloading

Let’s consider a class `ComplexNumber` that represents complex numbers and overloads some basic operators like `+`, `-`, and `==`.

#### Example: Overloading the `+`, `-`, and `==` Operators for a `ComplexNumber` Class

```csharp
using System;

public class ComplexNumber
{
    public double Real { get; set; }
    public double Imaginary { get; set; }

    public ComplexNumber(double real, double imaginary)
    {
        Real = real;
        Imaginary = imaginary;
    }

    // Overloading the + operator for complex numbers
    public static ComplexNumber operator +(ComplexNumber c1, ComplexNumber c2)
    {
        return new ComplexNumber(c1.Real + c2.Real, c1.Imaginary + c2.Imaginary);
    }

    // Overloading the - operator for complex numbers
    public static ComplexNumber operator -(ComplexNumber c1, ComplexNumber c2)
    {
        return new ComplexNumber(c1.Real - c2.Real, c1.Imaginary - c2.Imaginary);
    }

    // Overloading the == operator to compare complex numbers
    public static bool operator ==(ComplexNumber c1, ComplexNumber c2)
    {
        return (c1.Real == c2.Real && c1.Imaginary == c2.Imaginary);
    }

    // Overloading the != operator (not equal) for complex numbers
    public static bool operator !=(ComplexNumber c1, ComplexNumber c2)
    {
        return !(c1 == c2);
    }

    // Override the Equals method (required for operator ==)
    public override bool Equals(object obj)
    {
        if (obj is ComplexNumber other)
        {
            return this == other;
        }
        return false;
    }

    // Override the GetHashCode method (required for operator ==)
    public override int GetHashCode()
    {
        return (Real, Imaginary).GetHashCode();
    }

    // ToString for easy representation of the complex number
    public override string ToString()
    {
        return $"{Real} + {Imaginary}i";
    }
}

class Program
{
    static void Main()
    {
        ComplexNumber c1 = new ComplexNumber(3, 4);
        ComplexNumber c2 = new ComplexNumber(1, 2);

        // Using the overloaded + operator
        ComplexNumber sum = c1 + c2;
        Console.WriteLine($"Sum: {sum}"); // Output: Sum: 4 + 6i

        // Using the overloaded - operator
        ComplexNumber difference = c1 - c2;
        Console.WriteLine($"Difference: {difference}"); // Output: Difference: 2 + 2i

        // Using the overloaded == operator
        Console.WriteLine($"Are c1 and c2 equal? {c1 == c2}"); // Output: Are c1 and c2 equal? False
    }
}
```

### Breakdown of the Example:
- **The `+` operator**: This operator is overloaded to add the real and imaginary parts of two complex numbers.
- **The `-` operator**: This operator is overloaded to subtract the real and imaginary parts of two complex numbers.
- **The `==` operator**: This operator compares two complex numbers to check if both their real and imaginary parts are equal.
- **The `!=` operator**: This is the opposite of the `==` operator, and it checks if the two complex numbers are not equal.
- **Override `Equals` and `GetHashCode`**: Overriding `Equals` and `GetHashCode` is required to ensure the `==` operator works correctly, especially in collections or comparisons.
- **ToString Method**: The `ToString` method is overridden to provide a meaningful string representation of the `ComplexNumber` object.

### Commonly Overloaded Operators in C#
You can overload many common operators in C#. Below is a list of operators that can be overloaded:
- Arithmetic operators: `+`, `-`, `*`, `/`, `%`
- Comparison operators: `==`, `!=`, `<`, `>`, `<=`, `>=`
- Increment/Decrement operators: `++`, `--`
- Logical operators: `&`, `|`, `^`
- Unary operators: `+`, `-`, `!`, `~`
- Type-casting operators: `(type)`
- Array indexing operator: `[]`

### Example of Overloading Arithmetic Operators:

```csharp
using System;

public class Vector
{
    public int X { get; set; }
    public int Y { get; set; }

    public Vector(int x, int y)
    {
        X = x;
        Y = y;
    }

    // Overloading the + operator to add two vectors
    public static Vector operator +(Vector v1, Vector v2)
    {
        return new Vector(v1.X + v2.X, v1.Y + v2.Y);
    }

    // Overloading the * operator to multiply a vector by a scalar
    public static Vector operator *(Vector v, int scalar)
    {
        return new Vector(v.X * scalar, v.Y * scalar);
    }

    // ToString for easy representation
    public override string ToString()
    {
        return $"({X}, {Y})";
    }
}

class Program
{
    static void Main()
    {
        Vector v1 = new Vector(1, 2);
        Vector v2 = new Vector(3, 4);

        // Using the overloaded + operator to add vectors
        Vector result = v1 + v2;
        Console.WriteLine($"Sum of vectors: {result}"); // Output: Sum of vectors: (4, 6)

        // Using the overloaded * operator to multiply a vector by a scalar
        Vector scaled = v1 * 3;
        Console.WriteLine($"Scaled vector: {scaled}"); // Output: Scaled vector: (3, 6)
    }
}
```
- **Explanation**: 
  - The `+` operator adds the components of two `Vector` objects.
  - The `*` operator multiplies the vector by a scalar (integer).

### Important Notes:
1. **Symmetry**: When overloading operators like `==` and `!=`, ensure they are symmetric. If `a == b` is true, then `b == a` should also be true.
2. **Consistency with `Equals`**: Overloading the `==` operator should be consistent with the `Equals` method for comparison.
3. **Operator Precedence**: Overloading operators does not change their precedence. The precedence remains the same as for built-in types.
4. **Use Sparingly**: While operator overloading can make code more concise, overloading operators unnecessarily can lead to confusing code. Use it when it improves clarity and expressiveness.

### Summary of Operator Overloading in C#
- **Operator overloading** allows custom definitions of operators to behave in a specific way for user-defined types.
- Commonly overloaded operators include arithmetic, comparison, increment/decrement, and logical operators.
- Overloaded operators must be static and public.
- Operator overloading enhances the usability of user-defined types, making them more intuitive and expressive.
