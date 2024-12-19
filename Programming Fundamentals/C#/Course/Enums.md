### C# - Enums

An **enum** (short for **enumeration**) is a distinct value type in C# that defines a set of named constants. Enums are useful for representing a collection of related values, making the code more readable and maintainable. Enums can be used to represent flags, categories, or any other scenario where you need to work with a limited set of values.

### Key Features of Enums:
1. **Strongly Typed**: Enums are strongly typed constants, meaning they are associated with a specific underlying type, often `int` by default.
2. **Named Constants**: They provide a way to define a set of named constants, making the code more readable and self-explanatory.
3. **Underlying Type**: The underlying type of an enum is by default `int`, but you can change it to other integral types like `byte`, `short`, `long`, etc.
4. **Improved Code Clarity**: Enums allow you to use meaningful names instead of numbers, making the code easier to understand and maintain.

### Declaring an Enum
Enums are declared using the `enum` keyword, followed by the name of the enum and the values it contains. By default, the first value in an enum has the value `0`, and each subsequent value is incremented by `1`.

#### Example:
```csharp
enum Day
{
    Sunday,    // Default value 0
    Monday,    // Default value 1
    Tuesday,   // Default value 2
    Wednesday, // Default value 3
    Thursday,  // Default value 4
    Friday,    // Default value 5
    Saturday   // Default value 6
}
```

### Assigning Values to Enum Members
You can explicitly assign values to the members of an enum. If you don't assign a value, the values will be assigned incrementally from 0.

#### Example with Assigned Values:
```csharp
enum Day
{
    Sunday = 1,
    Monday = 2,
    Tuesday = 3,
    Wednesday = 4,
    Thursday = 5,
    Friday = 6,
    Saturday = 7
}
```

### Using Enums

#### Example: Using Enums in Code:
```csharp
using System;

class Program
{
    enum Day
    {
        Sunday = 1,
        Monday = 2,
        Tuesday = 3,
        Wednesday = 4,
        Thursday = 5,
        Friday = 6,
        Saturday = 7
    }

    static void Main()
    {
        Day today = Day.Monday;
        Console.WriteLine($"Today is: {today}");  // Output: Today is: Monday

        // You can also use the numeric value of an enum
        int dayNumber = (int)today;
        Console.WriteLine($"Numeric value of {today}: {dayNumber}");  // Output: Numeric value of Monday: 2
    }
}
```

### Enum Underlying Types
By default, the underlying type of an enum is `int`, but you can specify a different integral type, such as `byte`, `short`, `long`, etc.

#### Example: Enum with `byte` as the underlying type:
```csharp
enum Status : byte
{
    Pending = 1,
    Completed = 2,
    Failed = 3
}
```

In this example, the `Status` enum uses `byte` as its underlying type instead of the default `int`.

### Enum and Type Safety
Enums are strongly typed, so they help prevent invalid values from being assigned. For instance, you cannot assign a `string` or an integer that is not a valid enum member to an enum variable.

#### Example: Invalid Enum Assignment (will result in a compile-time error):
```csharp
Day today = 5;  // Error: Cannot implicitly convert type 'int' to 'Day'
```

### Converting Enums to and from Integers
You can convert an enum to its underlying integer value using casting, and you can also convert an integer back to its enum value using `Enum.ToObject()` or `Enum.GetValues()`.

#### Example: Converting an Enum to an Integer:
```csharp
Day today = Day.Wednesday;
int dayValue = (int)today;  // Cast to integer
Console.WriteLine(dayValue);  // Output: 4
```

#### Example: Converting an Integer to an Enum:
```csharp
int dayNumber = 3;
Day day = (Day)dayNumber;
Console.WriteLine(day);  // Output: Wednesday
```

Alternatively, you can use the `Enum.GetValues()` method to get all the values of an enum:

#### Example: Iterating over Enum Values:
```csharp
foreach (Day day in Enum.GetValues(typeof(Day)))
{
    Console.WriteLine($"{day} = {(int)day}");
}
```
This will output all the values and their corresponding integer values:
```
Sunday = 1
Monday = 2
Tuesday = 3
Wednesday = 4
Thursday = 5
Friday = 6
Saturday = 7
```

### Enum Flags
You can use enums with the `[Flags]` attribute to represent a combination of values, typically in cases where you want to use a bit field (such as for permission settings). The `[Flags]` attribute indicates that the enum members are meant to be combined with bitwise operations.

#### Example: Enum with Flags
```csharp
[Flags]
enum Permissions
{
    None = 0,
    Read = 1,
    Write = 2,
    Execute = 4,
    Delete = 8
}

class Program
{
    static void Main()
    {
        Permissions userPermissions = Permissions.Read | Permissions.Write;
        
        Console.WriteLine(userPermissions);  // Output: Read, Write

        // Check for a specific permission using bitwise AND
        bool canRead = (userPermissions & Permissions.Read) == Permissions.Read;
        Console.WriteLine($"Can Read: {canRead}");  // Output: Can Read: True

        bool canDelete = (userPermissions & Permissions.Delete) == Permissions.Delete;
        Console.WriteLine($"Can Delete: {canDelete}");  // Output: Can Delete: False
    }
}
```

### Enum Methods

1. **`Enum.GetValues(Type enumType)`**: Returns an array of all the values of the enum.
   
   ```csharp
   Day[] days = (Day[])Enum.GetValues(typeof(Day));
   foreach (var day in days)
   {
       Console.WriteLine(day);
   }
   ```

2. **`Enum.GetName(Type enumType, object value)`**: Returns the name of the constant that has the specified value.
   
   ```csharp
   string dayName = Enum.GetName(typeof(Day), 3);
   Console.WriteLine(dayName);  // Output: Tuesday
   ```

3. **`Enum.IsDefined(Type enumType, object value)`**: Checks if a value is defined in the enum.
   
   ```csharp
   bool isValid = Enum.IsDefined(typeof(Day), 5);
   Console.WriteLine(isValid);  // Output: True (as Thursday is 5)
   ```

### Enum with String Representation
If you want your enum values to have string-like names, you can use attributes like `enumDescription` or similar approaches, but C# enums by default store their values as integers. To output a more descriptive string, you would typically use `Enum.GetName()` or string formatting.

### Summary of Enums in C#
- **Definition**: An enum is a set of named constants.
- **Default Underlying Type**: The default underlying type of an enum is `int`, but you can specify a different integral type.
- **Strongly Typed**: Enums provide type safety by restricting values to a predefined set of options.
- **Flags**: You can use enums as flags (bit fields) by applying the `[Flags]` attribute.
- **Conversion**: You can convert enums to integers and vice versa using casting or helper methods.
- **Methods**: Useful methods like `Enum.GetValues()`, `Enum.GetName()`, and `Enum.IsDefined()` help with working with enums.

Enums help create more readable and maintainable code by representing fixed sets of related values and preventing the use of arbitrary numbers or strings.
