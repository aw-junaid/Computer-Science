### Scala - Regular Expressions

Regular expressions (regex) are patterns used to match character combinations in strings. Scala supports regular expressions through the `scala.util.matching.Regex` class, which provides functionality for both simple and complex pattern matching.

### Creating Regular Expressions in Scala

In Scala, regular expressions can be defined using either a string literal or the `"""..."""` raw string syntax.

#### 1. Using String Literals

You can define a regular expression by passing a string to the `Regex` class constructor.

```scala
import scala.util.matching.Regex

val regex = new Regex("[a-z]+")  // Matches one or more lowercase letters
```

#### 2. Using Raw String Literals

The `"""..."""` syntax allows you to define regular expressions more conveniently without needing to escape special characters like backslashes.

```scala
val regex = new Regex("""[a-z]+""")  // Matches one or more lowercase letters
```

### Basic Regular Expression Syntax

Here are some common regex components used in Scala:

- **`.`**: Matches any character except a newline.
- **`^`**: Matches the beginning of a string.
- **`$`**: Matches the end of a string.
- **`*`**: Matches zero or more of the preceding element.
- **`+`**: Matches one or more of the preceding element.
- **`?`**: Matches zero or one of the preceding element.
- **`[]`**: Matches any one character inside the square brackets.
- **`|`**: Logical OR between two patterns.
- **`()`**: Groups patterns together.
- **`\d`**: Matches any digit (equivalent to `[0-9]`).
- **`\w`**: Matches any word character (letters, digits, and underscores).
- **`\s`**: Matches any whitespace character (spaces, tabs, etc.).

### Examples of Using Regular Expressions in Scala

#### 1. Matching Strings Using `findFirstIn`

The `findFirstIn` method returns the first match found in a string.

```scala
import scala.util.matching.Regex

val regex = new Regex("[a-z]+")  // Match lowercase letters
val input = "Hello, Scala"

val result = regex.findFirstIn(input)

result match {
  case Some(matched) => println(s"Found: $matched")
  case None => println("No match found")
}
```

This will output:

```
Found: ello
```

#### 2. Matching All Occurrences Using `findAllIn`

To find all matches of a regular expression in a string, use `findAllIn`:

```scala
val regex = new Regex("\\d+")  // Match one or more digits
val input = "The number is 123 and 456"

val matches = regex.findAllIn(input).toList
println(matches)  // Output: List(123, 456)
```

#### 3. Using `replaceAllIn` to Replace Matches

You can use regular expressions to replace text in a string with `replaceAllIn`.

```scala
val regex = new Regex("\\d+")  // Match digits
val input = "My age is 25 and my brother's age is 30"

val result = regex.replaceAllIn(input, "#")  // Replace digits with '#'
println(result)  // Output: "My age is # and my brother's age is #"
```

#### 4. Matching Groups Using `findFirstMatchIn`

To extract matched groups (like capturing parts of a match), you can use `findFirstMatchIn`. This method returns a `Match` object, which contains groups that were captured by the parentheses in the regular expression.

```scala
val regex = new Regex("(\\d+)-(\\d+)")  // Capture two sets of digits separated by a hyphen
val input = "The range is 10-20"

regex.findFirstMatchIn(input) match {
  case Some(matched) => 
    println(s"Found: ${matched.group(1)} to ${matched.group(2)}")
  case None => println("No match found")
}
```

This will output:

```
Found: 10 to 20
```

#### 5. Using `split` with Regular Expressions

You can split a string based on a regular expression using the `split` method.

```scala
val regex = new Regex("\\s+")  // Split by one or more whitespace characters
val input = "This is a test string"

val result = regex.split(input)
println(result.mkString(", "))  // Output: "This, is, a, test, string"
```

#### 6. Testing for a Match Using `matches`

If you want to check if a string entirely matches a regular expression, use the `matches` method. This checks if the entire string matches the regular expression.

```scala
val regex = new Regex("^[a-zA-Z]+$")  // Match only letters
val input = "Hello"

if (regex.matches(input)) {
  println("Valid string")
} else {
  println("Invalid string")
}
```

This will output:

```
Valid string
```

If the string had digits or special characters, it would print `"Invalid string"`.

#### 7. Using Regex to Match Specific Patterns

You can use regular expressions for more specific matching, such as email validation:

```scala
val regex = new Regex("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}")
val email = "test@example.com"

if (regex.matches(email)) {
  println("Valid email address")
} else {
  println("Invalid email address")
}
```

This will output:

```
Valid email address
```

### Using Regular Expressions with `Pattern` and `Matcher`

Scala's regular expressions are actually built on Java's `Pattern` and `Matcher` classes. You can directly use these classes when needed, especially for more advanced features like named groups or advanced matching options.

```scala
import java.util.regex.{Pattern, Matcher}

val pattern = Pattern.compile("\\d+")
val matcher = pattern.matcher("There are 123 apples")

if (matcher.find()) {
  println(s"Found a match: ${matcher.group()}")
}
```

This will output:

```
Found a match: 123
```

### Summary

- Scala provides powerful support for regular expressions through the `scala.util.matching.Regex` class.
- Regular expressions can be used for a variety of string matching tasks, such as finding matches, extracting groups, replacing text, and validating patterns.
- The `Regex` class has methods like `findFirstIn`, `findAllIn`, `replaceAllIn`, `matches`, and `split` to handle different matching tasks.
- Regular expressions are widely used in parsing, validation, text processing, and string manipulation tasks.

By leveraging regular expressions in Scala, you can efficiently solve complex string matching and transformation problems.
