### C# - Regular Expressions

Regular expressions (regex) are a powerful way to search for patterns in text. In C#, regular expressions are used to match strings, validate input, and manipulate text data efficiently. The .NET framework provides the `System.Text.RegularExpressions` namespace, which contains the `Regex` class, offering functionality to work with regular expressions.

### Key Components of Regular Expressions:
- **Literal Characters**: A plain character matches itself (e.g., `a` matches the character `a`).
- **Meta-characters**: Special characters used to define patterns, such as `.` (any character), `^` (start of a string), `$` (end of a string).
- **Quantifiers**: Define how many times an element in the pattern can occur (e.g., `*`, `+`, `{n,m}`).
- **Character classes**: Represent a set of characters (e.g., `[a-z]` matches any lowercase letter).
- **Anchors**: Used to specify positions in the string (e.g., `^` for the start, `$` for the end).
- **Grouping and Capturing**: Grouping allows you to apply quantifiers to entire sub-patterns, and capturing enables you to extract matched portions of the string.
  
### Basic Syntax

```csharp
Regex regex = new Regex(pattern);
Match match = regex.Match(inputString);
```

Where:
- `pattern` is the regular expression string.
- `inputString` is the text where we want to search for the pattern.
- `Match` is an object that contains information about the result of the regex operation.

### Example: Simple Regular Expression Matching

```csharp
using System;
using System.Text.RegularExpressions;

class Program
{
    static void Main()
    {
        string input = "Hello, World!";
        string pattern = @"Hello";  // Regular expression pattern

        Regex regex = new Regex(pattern);
        Match match = regex.Match(input);

        if (match.Success)
        {
            Console.WriteLine("Pattern found!");
        }
        else
        {
            Console.WriteLine("Pattern not found.");
        }
    }
}
```

### Explanation:
- **`@"Hello"`**: The regular expression pattern matches the word "Hello".
- **`regex.Match(input)`**: Searches the input string for the pattern.
- **`match.Success`**: Returns `true` if the pattern is found; otherwise, `false`.

### Regular Expression Components

1. **Meta-characters**:
   - **`.` (dot)**: Matches any character except newline.
   - **`^`**: Matches the beginning of a string.
   - **`$`**: Matches the end of a string.
   - **`*`**: Matches 0 or more of the preceding element.
   - **`+`**: Matches 1 or more of the preceding element.
   - **`?`**: Matches 0 or 1 of the preceding element.
   - **`{n}`**: Matches exactly `n` occurrences of the preceding element.
   - **`{n, m}`**: Matches between `n` and `m` occurrences of the preceding element.

2. **Character Classes**:
   - **`[abc]`**: Matches any one of the characters `a`, `b`, or `c`.
   - **`[^abc]`**: Matches any character except `a`, `b`, or `c`.
   - **`\d`**: Matches any digit (equivalent to `[0-9]`).
   - **`\D`**: Matches any non-digit character.
   - **`\w`**: Matches any word character (alphanumeric or underscore).
   - **`\W`**: Matches any non-word character.
   - **`\s`**: Matches any whitespace character (spaces, tabs, line breaks).
   - **`\S`**: Matches any non-whitespace character.

3. **Groups and Capturing**:
   - **`()`**: Groups expressions together and captures matched content for later use.
   - **`(?:)`**: Groups expressions together without capturing.
   - **`|`**: Acts as a logical OR, matching either the expression before or after it.

4. **Anchors**:
   - **`^`**: Matches the start of the string.
   - **`$`**: Matches the end of the string.

### Example: Validate Email Address Using Regex

```csharp
using System;
using System.Text.RegularExpressions;

class Program
{
    static void Main()
    {
        string email = "example@example.com";
        string pattern = @"^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$"; // Email pattern

        Regex regex = new Regex(pattern);
        bool isValid = regex.IsMatch(email);

        if (isValid)
        {
            Console.WriteLine("Valid email address.");
        }
        else
        {
            Console.WriteLine("Invalid email address.");
        }
    }
}
```

### Explanation:
- The regular expression pattern for a simple email validation is: 
  - `^[a-zA-Z0-9._%+-]+`: Matches the username (alphanumeric characters, dots, underscores, etc.).
  - `@`: Matches the literal `@` symbol.
  - `[a-zA-Z0-9.-]+`: Matches the domain name (alphanumeric characters, dots, dashes).
  - `\.[a-zA-Z]{2,}$`: Matches the top-level domain (e.g., `.com`, `.org`).

### Example: Extracting Matches (Capturing Groups)

You can capture parts of the matched string for later use.

```csharp
using System;
using System.Text.RegularExpressions;

class Program
{
    static void Main()
    {
        string input = "My phone number is 123-456-7890.";
        string pattern = @"(\d{3})-(\d{3})-(\d{4})"; // Phone number pattern

        Regex regex = new Regex(pattern);
        Match match = regex.Match(input);

        if (match.Success)
        {
            Console.WriteLine("Area Code: " + match.Groups[1].Value);
            Console.WriteLine("Exchange: " + match.Groups[2].Value);
            Console.WriteLine("Subscriber Number: " + match.Groups[3].Value);
        }
        else
        {
            Console.WriteLine("No match found.");
        }
    }
}
```

### Explanation:
- **`(\d{3})-(\d{3})-(\d{4})`**: Captures three groups representing the area code, exchange, and subscriber number of the phone number.
- **`match.Groups[1].Value`**: Accesses the value of the first captured group (area code).

### Regex Methods in C#

1. **`Match()`**: Searches for the first match of the pattern in the input string.
2. **`Matches()`**: Finds all matches of the pattern in the input string.
3. **`IsMatch()`**: Returns `true` if the pattern matches the input string.
4. **`Replace()`**: Replaces matches of the pattern with a specified replacement string.
5. **`Split()`**: Splits the input string into an array of substrings based on the pattern.

### Example: Replace Text Using Regex

```csharp
using System;
using System.Text.RegularExpressions;

class Program
{
    static void Main()
    {
        string input = "The quick brown fox jumps over the lazy dog.";
        string pattern = @"\b\w+\b"; // Match all words
        string replacement = "word";

        string result = Regex.Replace(input, pattern, replacement);
        Console.WriteLine(result);  // Output: word word word word word word word word
    }
}
```

### Explanation:
- **`\b\w+\b`**: Matches whole words.
- **`Regex.Replace()`**: Replaces all words in the input with the string "word".

### Summary of Regular Expressions in C#

- **Pattern Matching**: Regular expressions provide a powerful way to match, search, and manipulate strings.
- **Basic Syntax**: C# uses the `Regex` class from the `System.Text.RegularExpressions` namespace.
- **Common Patterns**: Use meta-characters like `*`, `+`, `^`, `$`, `.` to define search patterns.
- **Groups**: Capture parts of the string using parentheses `()` for later use.
- **Methods**: Common methods like `Match()`, `Matches()`, `IsMatch()`, `Replace()`, and `Split()` allow for flexible text manipulation.

Regular expressions are a crucial tool for text processing, input validation, and data extraction in C#. They enable you to work with patterns efficiently, especially in situations involving complex or unpredictable text formats.
