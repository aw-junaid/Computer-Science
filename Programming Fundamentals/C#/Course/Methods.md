### C# - Methods

In C#, **methods** are blocks of code that perform a specific task. Methods define the behavior of a class and allow you to group related functionality. Methods can accept parameters, return values, and be called by other parts of the program to execute the code within them.

### Key Concepts of Methods:
1. **Method Declaration**: Defines a method by specifying its name, return type, and parameters (if any).
2. **Method Signature**: The combination of the method name and its parameter types. The return type is not part of the signature.
3. **Parameters**: Methods can accept parameters to provide input for the operations they perform.
4. **Return Type**: Methods can return a value to the caller (optional). If a method doesn't return anything, it uses `void` as the return type.
5. **Method Body**: The block of code that performs the task of the method.

### Syntax of a Method in C#:
```csharp
returnType MethodName(parameter1Type parameter1Name, parameter2Type parameter2Name)
{
    // method body
    // perform actions and return a value if necessary
}
```

- **`returnType`**: The type of value the method will return. If it doesn’t return anything, use `void`.
- **`MethodName`**: The name of the method.
- **`parameters`**: Optional list of parameters that the method takes as input.
- **`method body`**: Contains the logic of the method.

### 1. **Methods with No Return Value (`void`)**
A method that does not return any value is declared with the `void` keyword.

#### Example:
```csharp
public void Greet()
{
    Console.WriteLine("Hello, welcome to C#!");
}
```
- **Calling the method**:
```csharp
Greet();  // Output: Hello, welcome to C#!
```

### 2. **Methods that Return a Value**
A method can return a value of a specified type. The return type is specified before the method name.

#### Example:
```csharp
public int Add(int a, int b)
{
    return a + b;
}
```
- **Calling the method**:
```csharp
int sum = Add(3, 4);  // sum = 7
Console.WriteLine(sum);  // Output: 7
```
In this case, the `Add` method returns an `int` value, which is the sum of `a` and `b`.

### 3. **Methods with Parameters**
Methods can accept parameters, which allow you to pass data into the method to influence its behavior.

#### Example:
```csharp
public void DisplayMessage(string message)
{
    Console.WriteLine(message);
}
```
- **Calling the method**:
```csharp
DisplayMessage("Hello, this is a parameterized method!");  
// Output: Hello, this is a parameterized method!
```
In this case, the `DisplayMessage` method takes a `string` parameter and prints it to the console.

### 4. **Methods with Multiple Parameters**
A method can accept multiple parameters, separated by commas.

#### Example:
```csharp
public void PrintDetails(string name, int age)
{
    Console.WriteLine("Name: " + name);
    Console.WriteLine("Age: " + age);
}
```
- **Calling the method**:
```csharp
PrintDetails("Alice", 25);
// Output:
// Name: Alice
// Age: 25
```

### 5. **Method Overloading**
In C#, you can have multiple methods with the same name but with different parameters. This is called **method overloading**.

#### Example:
```csharp
public int Add(int a, int b)
{
    return a + b;
}

public double Add(double a, double b)
{
    return a + b;
}
```
- **Calling the method**:
```csharp
int intResult = Add(5, 10);     // Calls the Add(int, int) method
double doubleResult = Add(3.5, 4.5);  // Calls the Add(double, double) method
```
Method overloading allows you to define methods with the same name but with different parameter types or counts.

### 6. **Optional Parameters**
You can define parameters with default values, making them optional. If the caller does not provide a value for the parameter, the default value will be used.

#### Example:
```csharp
public void Greet(string name = "Guest")
{
    Console.WriteLine("Hello, " + name);
}
```
- **Calling the method**:
```csharp
Greet();  // Output: Hello, Guest
Greet("John");  // Output: Hello, John
```
Here, the `name` parameter has a default value of `"Guest"`, so if no value is provided when calling the method, it defaults to `"Guest"`.

### 7. **Named Arguments**
When calling a method, you can specify arguments by their parameter name, which can make the call more readable and allow you to pass arguments in a different order.

#### Example:
```csharp
public void DisplayInfo(string name, int age)
{
    Console.WriteLine("Name: " + name);
    Console.WriteLine("Age: " + age);
}
```
- **Calling the method with named arguments**:
```csharp
DisplayInfo(age: 30, name: "Alice");  // Output:
// Name: Alice
// Age: 30
```

### 8. **Ref and Out Parameters**
- **`ref`**: A `ref` parameter is used when you want to pass a parameter by reference, meaning changes to the parameter inside the method will affect the original variable.
- **`out`**: An `out` parameter is used when you want to return multiple values from a method.

#### Example using `ref`:
```csharp
public void UpdateAge(ref int age)
{
    age += 1;  // Increment age by 1
}

int age = 25;
UpdateAge(ref age);
Console.WriteLine(age);  // Output: 26
```

#### Example using `out`:
```csharp
public void GetDimensions(out int length, out int width)
{
    length = 5;
    width = 10;
}

int length, width;
GetDimensions(out length, out width);
Console.WriteLine($"Length: {length}, Width: {width}");  // Output: Length: 5, Width: 10
```

### 9. **Method Return Type (`void` and other types)**
- **`void`**: A method with `void` return type does not return anything. It performs an action but doesn't provide a result.
- **Non-void return types**: A method can return values of various types (like `int`, `string`, `double`, `bool`, etc.).

#### Example with a return type other than `void`:
```csharp
public double CalculateArea(double radius)
{
    return Math.PI * radius * radius;  // Return the area of the circle
}

double area = CalculateArea(5);
Console.WriteLine("Area: " + area);  // Output: Area: 78.53981633974483
```

### 10. **Recursive Methods**
A **recursive method** is a method that calls itself in order to solve a problem. Recursion can be useful for problems that can be broken down into smaller sub-problems (like factorial, Fibonacci numbers, etc.).

#### Example:
```csharp
public int Factorial(int n)
{
    if (n == 0)  // Base case
    {
        return 1;
    }
    else
    {
        return n * Factorial(n - 1);  // Recursive call
    }
}

Console.WriteLine(Factorial(5));  // Output: 120
```

### Summary of Methods in C#:
- **Method Declaration**: Defines a method with a specific return type and parameters.
- **Return Type**: Methods can return values or be void (if no value is returned).
- **Parameters**: Methods can accept input via parameters, making them reusable with different data.
- **Method Overloading**: Methods can have the same name but different parameter types or counts.
- **Optional Parameters**: Parameters can have default values, making them optional during method calls.
- **`ref` and `out` Parameters**: Allow passing arguments by reference or returning multiple values.
- **Named Arguments**: Allows specifying arguments by name for clarity and flexibility in method calls.
- **Recursion**: Methods can call themselves to solve problems in smaller chunks.

Methods are fundamental to organizing code, making it modular, reusable, and easy to maintain. They define the actions that objects or classes can perform and provide a way to structure and organize code logically.
