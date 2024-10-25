## Cheatsheet for regular expressions (regex) in Python, organized into different sections and tables for various commands and concepts related to regex:

### Table of Contents

1. **Regular Expression Basics**

    | Command                 | Description                                      |
    |-------------------------|--------------------------------------------------|
    | `re.compile()`          | Compile a regular expression pattern              |
    | `re.search()`           | Search for a pattern in a string                  |
    | `re.match()`            | Match a pattern at the beginning of a string      |
    | `re.fullmatch()`        | Match a pattern against the entire string         |
    | `re.findall()`          | Find all occurrences of a pattern in a string     |
    | `re.finditer()`         | Find all occurrences as an iterator               |
    | `re.sub()`              | Substitute occurrences of a pattern in a string   |
    | `re.split()`            | Split a string using a pattern as delimiter       |

2. **Character Classes**

    | Character   | Description                                      |
    |-------------|--------------------------------------------------|
    | `.`         | Match any character except a newline              |
    | `\d`        | Match a digit                                   |
    | `\D`        | Match a non-digit                               |
    | `\w`        | Match a word character (alphanumeric + underscore)|
    | `\W`        | Match a non-word character                       |
    | `\s`        | Match a whitespace character                     |
    | `\S`        | Match a non-whitespace character                 |

3. **Quantifiers and Anchors**

    | Character   | Description                                      |
    |-------------|--------------------------------------------------|
    | `*`         | Match 0 or more occurrences                       |
    | `+`         | Match 1 or more occurrences                       |
    | `?`         | Match 0 or 1 occurrence                           |
    | `^`         | Match the start of a string                       |
    | `$`         | Match the end of a string                         |

4. **Groups and Alternation**

    | Character   | Description                                      |
    |-------------|--------------------------------------------------|
    | `()`        | Create a group                                  |
    | `|`         | Match either/or                                 |

5. **Character Escapes**

    | Escape      | Description                                      |
    |-------------|--------------------------------------------------|
    | `\`         | Escape special characters (e.g., `\.` matches `.`)|
    | `\n`        | Newline                                         |
    | `\t`        | Tab                                             |

6. **Modifiers**

    | Modifier    | Description                                      |
    |-------------|--------------------------------------------------|
    | `re.I`      | Ignore case                                     |
    | `re.M`      | Multiline mode (anchors work on each line)       |
    | `re.S`      | Dot matches newline                              |

7. **Special Sequences**

    | Sequence    | Description                                      |
    |-------------|--------------------------------------------------|
    | `\b`        | Match a word boundary                            |
    | `\B`        | Match a non-word boundary                        |

8. **Lookahead and Lookbehind**

    | Syntax      | Description                                      |
    |-------------|--------------------------------------------------|
    | `(?=...)`   | Positive lookahead                              |
    | `(?!...)`   | Negative lookahead                              |
    | `(?<=...)`  | Positive lookbehind                             |
    | `(?<!...)`  | Negative lookbehind                             |

9. **Escape Codes for Special Characters**

    | Escape      | Character       |
    |-------------|----------------|
    | `\t`        | Tab            |
    | `\n`        | Newline        |
    | `\r`        | Carriage Return|
    | `\d`        | Digit          |
    | `\D`        | Non-digit      |
    | `\w`        | Word character  |
    | `\W`        | Non-word character|
    | `\s`        | Whitespace     |
    | `\S`        | Non-whitespace |

Remember to import the `re` module before using these commands. This cheatsheet provides a comprehensive overview of regular expressions in Python, covering a wide range of concepts and commands. Always refer to the official Python documentation or relevant resources for detailed usage and examples.
