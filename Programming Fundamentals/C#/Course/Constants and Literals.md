In C#, **constants** and **literals** are both used to represent fixed values that do not change during the execution of a program. However, there are key differences between them in terms of how they are declared and used.

### 1. **Constants**
A **constant** in C# is a variable whose value cannot be modified after it is initialized. Constants are typically used to define values that are known at compile time and will not change throughout the execution of the program. Constants are declared using the `const` keyword.

#### Key Points:
- Constants must be initialized when declared.
- The value of a constant cannot be changed during runtime.
- Constants are implicitly `static` and can be accessed directly from the class without creating an instance.

#### Syntax:
```csharp
const <datatype> <name> = <value>;
```

#### Example:
```csharp
public class MathConstants
{
    public const double Pi = 3.14159;  // A constant representing Pi
    public const int MaxValue = 1000;  // A constant representing the maximum value

    public static void Main()
    {
        Console.WriteLine("Value of Pi: " + Pi);  // Output: 3.14159
        Console.WriteLine("Max Value: " + MaxValue);  // Output: 1000
    }
}
```

#### Characteristics of Constants:
- **Compile-time evaluation**: The value of a constant is determined at compile time, meaning it cannot depend on any runtime values.
- **Used in expressions**: Constants can be used in expressions or assignments where a literal value would otherwise be used.
  
```csharp
int area = 10 * MathConstants.Pi;  // Using a constant in an expression
```

- **Can be accessed via the class name**: Since constants are static by default, they can be accessed directly using the class name, e.g., `MathConstants.Pi`.

### 2. **Literals**
A **literal** is a value written directly in the code that represents a constant value. It can be of any literal type, such as integer literals, floating-point literals, string literals, or boolean literals. Literals are the actual values assigned to variables or constants.

#### Common Literal Types:
- **Integer literals**: Represent whole numbers.
  ```csharp
  int x = 42; // 42 is an integer literal
  ```

- **Floating-point literals**: Represent decimal numbers.
  ```csharp
  double y = 3.14;  // 3.14 is a floating-point literal
  ```

- **Boolean literals**: Represent `true` or `false`.
  ```csharp
  bool isActive = true;  // true is a boolean literal
  ```

- **String literals**: Represent sequences of characters enclosed in double quotes.
  ```csharp
  string name = "Alice";  // "Alice" is a string literal
  ```

- **Character literals**: Represent individual characters enclosed in single quotes.
  ```csharp
  char grade = 'A';  // 'A' is a character literal
  ```

- **Null literal**: Represents a null value for reference types.
  ```csharp
  object obj = null;  // null is a literal of type object
  ```

#### Example of Different Literals:
```csharp
public class LiteralsExample
{
    public static void Main()
    {
        int integerLiteral = 100;        // Integer literal
        double floatingPointLiteral = 3.14; // Floating-point literal
        bool boolLiteral = true;         // Boolean literal
        string stringLiteral = "Hello";  // String literal
        char charLiteral = 'A';          // Character literal
        object nullLiteral = null;       // Null literal

        Console.WriteLine(integerLiteral);        // Output: 100
        Console.WriteLine(floatingPointLiteral);  // Output: 3.14
        Console.WriteLine(boolLiteral);           // Output: True
        Console.WriteLine(stringLiteral);        // Output: Hello
        Console.WriteLine(charLiteral);          // Output: A
        Console.WriteLine(nullLiteral);          // Output: (null)
    }
}
```

### 3. **Difference Between Constants and Literals**
- **Constants** are **variables** whose values are set at compile time and cannot be modified. They are declared using the `const` keyword.
- **Literals** are **actual fixed values** written directly in the code. They represent fixed values of specific types and are not declared with a keyword.

#### Key Differences:
| Aspect                | Constants                                        | Literals                                      |
|-----------------------|--------------------------------------------------|-----------------------------------------------|
| **Definition**         | A named variable that holds a fixed value        | A fixed value directly used in the code       |
| **Declaration**        | Declared using the `const` keyword               | Written directly in the code (e.g., `42`, `"Hello"`) |
| **Changeability**      | Cannot be changed after initialization          | Fixed value but not declared as a variable    |
| **Scope**              | Constants are implicitly `static` and can be accessed by class name | Literals are used directly in the code wherever needed |
| **Evaluation Time**    | Evaluated at compile time                        | Evaluated at runtime                          |
| **Memory Storage**     | Stored in memory as a static value               | Stored directly as a fixed value at runtime  |

### 4. **Constant Expressions**
In C#, you can use constants in expressions, and the result will be evaluated at compile time. This is particularly useful when you need to define values that depend on other constants.

#### Example:
```csharp
public class ConstantExpression
{
    public const double Pi = 3.14159;
    public const double Radius = 5.0;
    public const double Area = Pi * Radius * Radius;  // Expression evaluated at compile time

    public static void Main()
    {
        Console.WriteLine("Area of circle: " + Area);  // Output: Area of circle: 78.53975
    }
}
```

In this example, `Area` is a constant that uses other constants (`Pi` and `Radius`) in its calculation. The result is evaluated during compilation.

### 5. **Enumerations and Constants**
In C#, you can also use constants in **enums**. An **enum** is a special "class" that represents a group of constants (usually integers).

#### Example of Enum with Constants:
```csharp
public enum Days
{
    Sunday = 1,
    Monday = 2,
    Tuesday = 3,
    Wednesday = 4,
    Thursday = 5,
    Friday = 6,
    Saturday = 7
}

public class EnumExample
{
    public static void Main()
    {
        Days today = Days.Monday;
        Console.WriteLine(today);  // Output: Monday
    }
}
```

In this example, the `Days` enum has constants associated with days of the week, with each day represented by an integer value.

### 6. **Readonly Variables vs Constants**
In addition to constants, C# also has the `readonly` keyword, which is used to define fields that can only be assigned a value once, either at the time of declaration or in the constructor of the class.

- **Constants** are compile-time values and are `static` by default.
- **Readonly variables** are runtime values and can be assigned only once, but the value can depend on runtime conditions.

#### Example of Readonly:
```csharp
public class ReadonlyExample
{
    public readonly double Gravity; // Readonly field

    public ReadonlyExample(double gravity)
    {
        Gravity = gravity;  // Can be assigned at runtime in constructor
    }

    public static void Main()
    {
        ReadonlyExample obj = new ReadonlyExample(9.81);  // Gravity is set at runtime
        Console.WriteLine(obj.Gravity);  // Output: 9.81
    }
}
```

In this case, `Gravity` is a `readonly` field, and its value is set during the construction of an object.

### Summary:
- **Constants** are values that cannot be changed once set and are determined at compile time.
- **Literals** are fixed values that are written directly in code, such as `42`, `"Hello"`, or `true`.
- Both constants and literals help represent fixed data, but constants have names and can be reused, while literals are often used directly in expressions.
