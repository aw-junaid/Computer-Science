### C# - Nullables

In C#, **nullable types** allow you to represent a value type (like `int`, `double`, `bool`, etc.) as **null**, which is normally not allowed. By default, value types cannot be `null` because they must always contain a value (e.g., an `int` must contain a number). However, with nullable types, you can assign `null` to a value type, making it possible to represent the absence of a value.

### Nullable Types
Nullable types are defined by appending a question mark (`?`) to the type, which allows the type to hold its usual values or `null`.

#### Syntax:
```csharp
Type? variableName;
```

- **Type** is any value type, such as `int`, `double`, `bool`, etc.
- **Type?** allows the variable to hold either a valid value of the type or `null`.

### Example of Nullable Types

```csharp
int? nullableInt = null;   // Nullable integer, can hold an int or null
double? nullableDouble = 3.14;  // Nullable double, can hold a double or null

Console.WriteLine(nullableInt);  // Output: (null)
Console.WriteLine(nullableDouble);  // Output: 3.14
```

In the example above, `nullableInt` can hold either an `int` value or `null`, and `nullableDouble` can hold a `double` value or `null`.

### How Nullable Types Work

Nullable types work by utilizing a special struct called `Nullable<T>`. The `Nullable<T>` struct has two main properties:
- `HasValue`: A property that indicates whether the nullable type has a value or is `null`.
- `Value`: The property that returns the value of the nullable type, but throws an exception if the value is `null`.

#### Example:
```csharp
int? nullableInt = 5;

if (nullableInt.HasValue)
{
    Console.WriteLine("Value: " + nullableInt.Value);  // Output: Value: 5
}
else
{
    Console.WriteLine("The value is null.");
}

nullableInt = null;

if (nullableInt.HasValue)
{
    Console.WriteLine("Value: " + nullableInt.Value);
}
else
{
    Console.WriteLine("The value is null.");  // Output: The value is null.
}
```

- `HasValue`: Checks whether the nullable type has a value (i.e., it is not `null`).
- `Value`: Retrieves the actual value of the nullable type. It should only be accessed if `HasValue` is `true`, otherwise, it will throw an exception if the value is `null`.

### Default Value of Nullable Types
When a nullable type is declared but not initialized, it has a default value of `null`.

```csharp
int? uninitializedNullableInt;  // Default is null
Console.WriteLine(uninitializedNullableInt);  // Output: (null)
```

### Null-Coalescing Operator (`??`)

The **null-coalescing operator (`??`)** is used to provide a default value when a nullable type is `null`. It allows you to handle `null` values gracefully by returning a specified default value if the nullable variable is `null`.

#### Syntax:
```csharp
nullableVariable ?? defaultValue;
```

- **`nullableVariable`**: A nullable type.
- **`defaultValue`**: The value that will be used if `nullableVariable` is `null`.

#### Example:
```csharp
int? nullableInt = null;
int result = nullableInt ?? 0;  // If nullableInt is null, use 0

Console.WriteLine(result);  // Output: 0
```

In this example, since `nullableInt` is `null`, the expression `nullableInt ?? 0` returns `0`.

### Nullable Value Types with Conditional Access (`?.`)

The **null-conditional operator (`?.`)** can be used to safely access members or methods of an object that could be `null`. When used with nullable types, it helps prevent exceptions caused by dereferencing `null`.

#### Example:
```csharp
int? nullableInt = null;

int? result = nullableInt?.Value;  // Safe access, result will be null

Console.WriteLine(result);  // Output: (null)
```

In this example, the expression `nullableInt?.Value` will only access the `Value` property of `nullableInt` if it is not `null`. If `nullableInt` is `null`, the entire expression evaluates to `null`.

### Nullable Types with Collections

You can use nullable types in collections like arrays, lists, or dictionaries, which allows the collection to hold `null` for value types.

#### Example:
```csharp
List<int?> numbers = new List<int?> { 1, 2, null, 4, 5 };

foreach (var number in numbers)
{
    if (number.HasValue)
    {
        Console.WriteLine("Number: " + number.Value);
    }
    else
    {
        Console.WriteLine("Number is null");
    }
}
```

Output:
```
Number: 1
Number: 2
Number is null
Number: 4
Number: 5
```

### Nullable Reference Types (C# 8.0 and Later)
Starting from C# 8.0, **nullable reference types** were introduced, allowing reference types (like `string`, `object`, etc.) to be nullable and enabling better control over `null` reference exceptions.

#### Syntax:
To enable nullable reference types, you need to enable it in the project or file with:
```csharp
#nullable enable
```

Once enabled, reference types can be declared as nullable using the `?` symbol:

```csharp
#nullable enable

string? name = null;  // Nullable reference type
string nonNullableName = "John";  // Non-nullable reference type
```

#### Nullability Annotations
When nullable reference types are enabled, the compiler helps you catch potential null dereference errors by enforcing nullability rules:
- **Non-nullable reference types** (like `string`) must not be assigned `null`.
- **Nullable reference types** (like `string?`) can be assigned `null`.

### Example of Nullable Reference Types:
```csharp
#nullable enable

public class Person
{
    public string? FirstName { get; set; }  // Nullable reference type
    public string LastName { get; set; }  // Non-nullable reference type
}

public void DisplayPersonInfo(Person? person)
{
    if (person?.FirstName != null)
    {
        Console.WriteLine(person.FirstName);
    }
    else
    {
        Console.WriteLine("First name is not provided.");
    }
}
```

In this example, `FirstName` is a nullable reference type, meaning it can hold `null`. The `?.` operator is used to safely check if `FirstName` is `null` before accessing it.

### Summary of Nullable Types in C#:

1. **Nullable Value Types**: Appending `?` to a value type (`int?`, `double?`, `bool?`) allows it to hold `null` as well as its normal values.
2. **Null-Coalescing Operator (`??`)**: Provides a default value if a nullable type is `null`.
3. **Null-Conditional Operator (`?.`)**: Safely accesses members or methods of a nullable type, returning `null` if the object is `null`.
4. **Nullable Reference Types**: Introduced in C# 8.0, allowing reference types (e.g., `string`, `object`) to be nullable, with compiler checks to help prevent null reference exceptions.
5. **HasValue and Value**: Nullable types have `HasValue` to check for `null` and `Value` to access the underlying value (if it’s not `null`).

Nullable types provide a more flexible way to handle the absence of values, improving safety and control in your code, especially when dealing with data that can be missing or optional.
