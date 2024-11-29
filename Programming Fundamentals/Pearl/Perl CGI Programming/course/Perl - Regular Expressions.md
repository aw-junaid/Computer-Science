### Perl - Regular Expressions

Perl has powerful built-in support for regular expressions, enabling complex pattern matching, text manipulation, and data extraction tasks. This flexibility is one of Perl’s core strengths, making it a popular choice for text processing.

---

### 1. **Basic Regular Expression Syntax**

Regular expressions (regex) are typically used with operators such as `=~` (matches) and `!~` (does not match). 

#### Example

```perl
my $text = "Hello, World!";
if ($text =~ /World/) {
    print "Pattern found!\n";
}
```

This regex `/World/` matches the string if it contains "World".

---

### 2. **Regex Modifiers**

Modifiers alter how the regex engine interprets the pattern.

- **`i`**: Case-insensitive matching.

  ```perl
  /hello/i  # Matches "hello", "Hello", etc.
  ```

- **`g`**: Global matching (finds all matches).

  ```perl
  while ($text =~ /word/g) { ... }
  ```

- **`m`**: Multiline mode, treating the string as multiple lines.

- **`s`**: Allows `.` to match newline characters.

- **`x`**: Allows for whitespace and comments within the regex, improving readability.

  ```perl
  my $phone = qr/
      \d{3}  # Area code
      \d{3}  # Exchange
      \d{4}  # Subscriber number
  /x;
  ```

---

### 3. **Anchors**

Anchors are used to specify positions in the string.

- **`^`**: Start of the string.
  
  ```perl
  /^hello/  # Matches "hello" at the start
  ```

- **`$`**: End of the string.

  ```perl
  /world$/  # Matches "world" at the end
  ```

---

### 4. **Character Classes**

Character classes match specific types or ranges of characters.

- **`[abc]`**: Matches `a`, `b`, or `c`.
- **`[a-z]`**: Matches any lowercase letter.
- **`\d`**: Matches any digit (equivalent to `[0-9]`).
- **`\w`**: Matches any "word" character (alphanumeric plus `_`).
- **`\s`**: Matches whitespace (space, tab, newline).

#### Negated Classes

- **`\D`**: Matches any non-digit.
- **`\W`**: Matches any non-word character.
- **`\S`**: Matches any non-whitespace character.

---

### 5. **Quantifiers**

Quantifiers specify the number of times a character or group should appear.

- **`*`**: 0 or more times.

  ```perl
  /a*/  # Matches "", "a", "aa", etc.
  ```

- **`+`**: 1 or more times.

  ```perl
  /a+/  # Matches "a", "aa", etc.
  ```

- **`?`**: 0 or 1 time (optional).

  ```perl
  /a?/  # Matches "", "a"
  ```

- **`{n}`**: Exactly `n` times.
  
  ```perl
  /\d{3}/  # Matches exactly 3 digits
  ```

- **`{n,}`**: `n` or more times.

- **`{n,m}`**: Between `n` and `m` times.

---

### 6. **Grouping and Capturing**

- **Parentheses `()`**: Group patterns and capture matched text in special variables, such as `$1`, `$2`, etc.

  ```perl
  my $text = "John Doe";
  if ($text =~ /(\w+)\s+(\w+)/) {
      print "First name: $1, Last name: $2\n";  # Captures "John" and "Doe"
  }
  ```

- **Non-Capturing Group `(?:...)`**: Groups without capturing, useful for grouping without creating variables.

---

### 7. **Alternation**

The pipe `|` allows for alternation (logical OR) in matching.

```perl
/my|your|their/  # Matches "my", "your", or "their"
```

---

### 8. **Substitution with `s///`**

The `s///` operator substitutes matched text with a replacement string.

#### Example

```perl
my $text = "apples are red";
$text =~ s/red/green/;
print $text;  # Output: apples are green
```

**Global substitution** (`s///g`) replaces all occurrences.

```perl
$text =~ s/a/e/g;  # Replaces all "a" with "e"
```

**Case-insensitive substitution** (`s///i`).

---

### 9. **Transliteration with `tr///`**

The `tr///` operator replaces characters one-for-one.

#### Example

```perl
my $dna = "GATTACA";
$dna =~ tr/ACGT/TGCA/;
print $dna;  # Output: CTAATGT
```

---

### 10. **Regex Variables**

Perl stores the results of matches in special variables:

- **`$&`**: The matched string.
- **`$``**: Text before the match.
- **`$'`**: Text after the match.
- **`$1`, `$2`, ...**: Captured groups.

```perl
if ("Hello, World!" =~ /(Hello), (World)/) {
    print "$1 $2\n";  # Outputs: Hello World
}
```

---

### 11. **Using `qr//` for Regex Reuse**

The `qr//` operator creates regex objects that can be reused, improving readability and maintainability.

#### Example

```perl
my $word_pattern = qr/\b\w+\b/;
while ($text =~ /$word_pattern/g) {
    print "Found word: $&\n";
}
```

---

### 12. **Regex Examples**

- **Email Validation**

  ```perl
  my $email = 'example@example.com';
  if ($email =~ /^[\w\.\-]+@[\w\-]+\.[a-z]{2,}$/i) {
      print "Valid email\n";
  }
  ```

- **Phone Number Formatting**

  ```perl
  my $phone = '(123) 456-7890';
  if ($phone =~ /\(\d{3}\)\s\d{3}-\d{4}/) {
      print "Valid phone number\n";
  }
  ```

---

### Summary of Perl Regular Expressions

| **Feature**            | **Syntax**                         | **Description**                                          |
|------------------------|------------------------------------|----------------------------------------------------------|
| **Basic Match**        | `/pattern/`                       | Matches `pattern`                                        |
| **Modifiers**          | `/pattern/i`, `/pattern/g`, etc.  | `i` for case-insensitive, `g` for global                 |
| **Anchors**            | `^`, `$`                          | Start and end of string                                  |
| **Character Classes**  | `[abc]`, `\d`, `\w`, etc.         | Match specific character sets                            |
| **Quantifiers**        | `*`, `+`, `{n}`, etc.             | Control the number of matches                            |
| **Grouping**           | `(pattern)`, `(?:pattern)`        | Capture groups and non-capturing groups                  |
| **Alternation**        | `pattern1|pattern2`               | Match either pattern1 or pattern2                        |
| **Substitution**       | `s/pattern/replacement/`          | Replace matched text                                     |
| **Transliteration**    | `tr/abc/xyz/`                     | Translate characters one-for-one                         |
| **Variables**          | `$&`, `$1`, `$2`, etc.            | Matched text and captured groups                         |
| **Regex Objects**      | `qr/pattern/`                     | Create reusable regex patterns                           |

Perl’s regex capabilities make it extremely effective for parsing and text manipulation. Understanding these regex features allows you to craft concise and powerful text-processing solutions.
