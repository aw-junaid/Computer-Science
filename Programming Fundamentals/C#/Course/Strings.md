### C# - Strings

In C#, a **string** is a sequence of characters used to represent text. Strings are one of the most commonly used types in programming, and C# provides many features to work with strings efficiently. 

### Key Characteristics of Strings:
1. **Immutable**: Strings in C# are immutable, meaning once a string is created, it cannot be changed. Any operation that modifies a string actually creates a new string.
2. **Reference Type**: Strings are reference types in C#. This means that when a string is assigned to another string, both variables point to the same string.
3. **Unicode**: C# strings are stored as Unicode, allowing them to represent a wide range of characters from various languages.

### Declaring Strings
You can declare a string in C# using the `string` keyword or `System.String`.

#### Example:
```csharp
string message = "Hello, World!";
System.String anotherMessage = "Goodbye, World!";
```

### String Literals

- **Regular String**: A string literal enclosed in double quotes (`""`).
  
```csharp
string greeting = "Hello, World!";
```

- **Verbatim String**: A string literal prefixed with the `@` symbol, used to represent strings with special characters, such as newlines (`\n`) or backslashes (`\`). Verbatim strings preserve formatting and escape sequences.
  
```csharp
string filePath = @"C:\Users\Name\Documents\file.txt";
string multilineText = @"This is a
multiline string.";
```

### String Operations

1. **Concatenation**: You can concatenate (combine) two or more strings using the `+` operator or `String.Concat()` method.
  
```csharp
string firstName = "John";
string lastName = "Doe";
string fullName = firstName + " " + lastName;
Console.WriteLine(fullName);  // Output: John Doe
```

Alternatively, you can use **string interpolation** for cleaner concatenation:

```csharp
string fullName = $"{firstName} {lastName}";
Console.WriteLine(fullName);  // Output: John Doe
```

2. **String Interpolation**: Allows embedding expressions inside string literals. This is more efficient and readable compared to concatenation.

```csharp
int age = 25;
string info = $"Name: {firstName} {lastName}, Age: {age}";
Console.WriteLine(info);  // Output: Name: John Doe, Age: 25
```

3. **String Formatting**: You can format strings using the `String.Format()` method, especially for complex formatting scenarios.

```csharp
string formattedString = string.Format("Hello, {0}!", firstName);
Console.WriteLine(formattedString);  // Output: Hello, John!
```

4. **String Methods**: The `System.String` class offers many methods for manipulating strings:

#### Common String Methods:

- **`Length`**: Returns the length (number of characters) of the string.
  
```csharp
string str = "Hello";
Console.WriteLine(str.Length);  // Output: 5
```

- **`ToLower()`**: Converts all characters in the string to lowercase.
  
```csharp
string lower = "HELLO".ToLower();
Console.WriteLine(lower);  // Output: hello
```

- **`ToUpper()`**: Converts all characters in the string to uppercase.
  
```csharp
string upper = "hello".ToUpper();
Console.WriteLine(upper);  // Output: HELLO
```

- **`Trim()`**: Removes whitespace from the beginning and end of the string.
  
```csharp
string padded = "  Hello  ";
string trimmed = padded.Trim();
Console.WriteLine(trimmed);  // Output: Hello
```

- **`Substring(startIndex, length)`**: Extracts a substring starting from a specific index and length.
  
```csharp
string text = "Hello, World!";
string part = text.Substring(7, 5);
Console.WriteLine(part);  // Output: World
```

- **`Replace(oldValue, newValue)`**: Replaces all occurrences of a substring with another substring.
  
```csharp
string original = "I like cats.";
string updated = original.Replace("cats", "dogs");
Console.WriteLine(updated);  // Output: I like dogs.
```

- **`Contains(value)`**: Checks if the string contains a specific substring.
  
```csharp
string sentence = "The quick brown fox";
bool hasFox = sentence.Contains("fox");
Console.WriteLine(hasFox);  // Output: True
```

- **`StartsWith(value)`**: Checks if the string starts with a specified prefix.
  
```csharp
string sentence = "The quick brown fox";
bool startsWithThe = sentence.StartsWith("The");
Console.WriteLine(startsWithThe);  // Output: True
```

- **`EndsWith(value)`**: Checks if the string ends with a specified suffix.
  
```csharp
string sentence = "The quick brown fox";
bool endsWithFox = sentence.EndsWith("fox");
Console.WriteLine(endsWithFox);  // Output: True
```

- **`IndexOf(value)`**: Returns the index of the first occurrence of a substring.
  
```csharp
string sentence = "The quick brown fox";
int index = sentence.IndexOf("brown");
Console.WriteLine(index);  // Output: 10 (index where "brown" starts)
```

- **`Split(delimiters)`**: Splits a string into an array of substrings based on delimiters.
  
```csharp
string sentence = "apple,banana,cherry";
string[] fruits = sentence.Split(',');

foreach (var fruit in fruits)
{
    Console.WriteLine(fruit);
}
// Output:
// apple
// banana
// cherry
```

- **`CompareTo()`**: Compares the current string with another string and returns an integer indicating their relative order.

```csharp
string str1 = "apple";
string str2 = "banana";
int result = str1.CompareTo(str2);
Console.WriteLine(result);  // Output: -1 (because "apple" is lexicographically less than "banana")
```

### StringBuilder (For Performance)

In C#, **strings are immutable**, meaning every time you modify a string, a new string object is created. This can lead to performance issues, especially in loops or frequent string modifications. To optimize this, you can use the **`StringBuilder`** class.

#### Example of StringBuilder:
```csharp
using System.Text;

StringBuilder sb = new StringBuilder();
sb.Append("Hello");
sb.Append(" ");
sb.Append("World!");
Console.WriteLine(sb.ToString());  // Output: Hello World!
```

`StringBuilder` is more efficient when building or modifying long strings repeatedly.

### Escaping Special Characters in Strings

Certain characters in strings have special meanings (e.g., `\n` for new line, `\t` for tab, `\\` for a backslash). To include these characters in a string, you need to escape them.

#### Example:
```csharp
string escaped = "This is a backslash: \\ and a new line:\nNext line.";
Console.WriteLine(escaped);
// Output:
// This is a backslash: \ and a new line:
// Next line.
```

To include a literal backslash, double it (`\\`).

### String Interpolation with Format Specifiers

String interpolation allows embedding expressions inside string literals, and you can use format specifiers to control how values are represented (e.g., for numbers, dates).

#### Example:
```csharp
decimal price = 19.99m;
DateTime date = DateTime.Now;
string formatted = $"Price: {price:C}, Date: {date:yyyy-MM-dd}";
Console.WriteLine(formatted);
// Output: Price: $19.99, Date: 2024-12-16
```

- **`{price:C}`**: Formats the price as currency.
- **`{date:yyyy-MM-dd}`**: Formats the date as `year-month-day`.

### Common String Use Cases in C#

1. **Handling User Input**: Strings are frequently used for gathering and processing user input.
2. **File and Path Manipulation**: Strings are essential when working with file paths and names.
3. **Displaying Data**: Strings are used extensively in user interfaces, logs, and reports.
4. **Regular Expressions**: C# supports working with regular expressions, which are typically stored and processed as strings.

### Summary of Strings in C#

- **Declaration and Initialization**: Strings can be declared using `string` or `System.String` and can be initialized using literal syntax or using the `@` symbol for verbatim strings.
- **String Operations**: C# provides numerous methods for string manipulation, including concatenation, trimming, searching, replacing, and formatting.
- **String Interpolation**: A cleaner way to include variables and expressions inside string literals.
- **StringBuilder**: An efficient way to handle string modifications in performance-sensitive applications.
- **Escape Sequences**: Special characters in strings can be represented with escape sequences (e.g., `\n` for a new line, `\\` for a backslash).
  
Strings are fundamental to text processing in C#, and the language provides a rich set of features for working with them efficiently.
