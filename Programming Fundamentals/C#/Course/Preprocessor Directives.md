### C# - Preprocessor Directives

Preprocessor directives in C# are commands that are processed by the compiler before the actual compilation of the code. These directives can be used to include or exclude parts of the code conditionally, define symbols, or control debugging and conditional compilation. Preprocessor directives are not executed by the program but influence how the code is compiled.

### Key Characteristics of Preprocessor Directives:
- **Begin with `#`**: All preprocessor directives begin with a `#` symbol.
- **No semicolon**: Preprocessor directives do not require semicolons.
- **Not part of the runtime code**: Preprocessor directives affect the compilation process, not the execution of the program.

### Common Preprocessor Directives in C#

1. **`#define`**: Defines a symbol that can be used for conditional compilation.
2. **`#undef`**: Undefines a symbol.
3. **`#if`, `#else`, `#elif`, `#endif`**: Conditional compilation based on symbols or expressions.
4. **`#region`, `#endregion`**: Code folding for grouping sections of code.
5. **`#warning`**: Generates a compile-time warning message.
6. **`#error`**: Generates a compile-time error message.
7. **`#line`**: Specifies the line number and file name for the code.
8. **`#pragma`**: Controls specific compiler behavior or issues warnings.
9. **`#nullable`**: Enables or disables nullable reference type annotations.

### Example: `#define` and Conditional Compilation

The `#define` directive is used to define a symbol, and conditional compilation can be used to include or exclude parts of code based on whether the symbol is defined.

```csharp
#define DEBUG   // Define the DEBUG symbol

using System;

class Program
{
    static void Main()
    {
        #if DEBUG
            Console.WriteLine("Debug mode is enabled.");
        #else
            Console.WriteLine("Debug mode is disabled.");
        #endif
    }
}
```

### Explanation:
- **`#define DEBUG`**: The `DEBUG` symbol is defined before the program runs.
- **`#if DEBUG`**: This directive checks if the `DEBUG` symbol is defined. If true, it includes the code that follows it.
- **`#else`**: This code is executed if the `DEBUG` symbol is not defined.
- **`#endif`**: Ends the conditional block.

### Example: `#undef` and Re-defining Symbols

The `#undef` directive is used to undefine a symbol that was previously defined.

```csharp
#define FEATURE_A
#undef FEATURE_A   // Undefine FEATURE_A

using System;

class Program
{
    static void Main()
    {
        #if FEATURE_A
            Console.WriteLine("Feature A is enabled.");
        #else
            Console.WriteLine("Feature A is disabled.");
        #endif
    }
}
```

### Explanation:
- **`#undef FEATURE_A`**: This undefines the `FEATURE_A` symbol, meaning that the code inside `#if FEATURE_A` will not be included.
- **`#else`**: Since `FEATURE_A` is not defined, the code inside the `#else` block will execute.

### Example: `#region` and `#endregion`

The `#region` and `#endregion` directives allow you to group sections of code into collapsible regions in the editor for easier navigation.

```csharp
using System;

class Program
{
    #region Initialization
    static void Initialize()
    {
        Console.WriteLine("Initializing...");
    }
    #endregion

    #region Main Execution
    static void Main()
    {
        Console.WriteLine("Starting Program...");
        Initialize();
    }
    #endregion
}
```

### Explanation:
- **`#region`**: Defines a region of code that can be collapsed in the editor.
- **`#endregion`**: Marks the end of the region.
- These directives don’t affect the code’s execution but make it easier to manage large files.

### Example: `#warning` and `#error`

You can use `#warning` to generate a compile-time warning or `#error` to stop the compilation with a custom error message.

```csharp
using System;

class Program
{
    #warning This is a warning message

    static void Main()
    {
        Console.WriteLine("Hello, World!");
    }
}
```

### Explanation:
- **`#warning`**: This generates a compile-time warning message. The message will be displayed in the build output.
  
```csharp
using System;

class Program
{
    #error This is a custom error message

    static void Main()
    {
        Console.WriteLine("Hello, World!");
    }
}
```

### Explanation:
- **`#error`**: This generates a compile-time error and stops the compilation process.

### Example: `#line` and File Information

The `#line` directive is used to modify the line numbers and file name in the compiler output, useful for pre-processing or code generation scenarios.

```csharp
using System;

class Program
{
    #line 100 "GeneratedCode.cs"
    static void Main()
    {
        Console.WriteLine("This code is treated as if it's in the GeneratedCode.cs file.");
    }
}
```

### Explanation:
- **`#line`**: This changes the line number and file name for the code that follows it. In the above example, the `Main` method will appear as if it's written in a file named `GeneratedCode.cs` starting at line 100.

### Example: `#nullable` (C# 8.0+)

The `#nullable` directive is used to enable or disable nullable reference type annotations.

```csharp
#nullable enable

using System;

class Program
{
    static void Main()
    {
        string? nullableString = null;
        Console.WriteLine(nullableString?.Length);
    }
}
```

### Explanation:
- **`#nullable enable`**: This enables nullable reference types, which means that a reference type like `string` can be null and requires explicit nullable annotations (`string?`).
- **`string?`**: Indicates that the string can be null. The code uses the null-conditional operator (`?.`) to avoid potential `NullReferenceException`.

### Summary of Common Preprocessor Directives

- **`#define`**: Defines a symbol that can be used for conditional compilation.
- **`#undef`**: Undefines a previously defined symbol.
- **`#if`, `#else`, `#elif`, `#endif`**: Conditional compilation based on defined symbols or expressions.
- **`#region`, `#endregion`**: Marks a block of code as a collapsible region in the editor.
- **`#warning`**: Generates a compile-time warning message.
- **`#error`**: Generates a compile-time error message and halts compilation.
- **`#line`**: Specifies the line number and file name for the code.
- **`#nullable`**: Controls the behavior of nullable reference types.

Preprocessor directives allow for flexibility and control during the compilation process, helping to manage debugging, conditional features, and code generation.
