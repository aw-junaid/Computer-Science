In PHP, **Heredoc** and **Nowdoc** are both ways to define string literals that allow for multi-line strings without the need to escape special characters. While they may appear similar, there are key differences in how they handle variables and escape sequences.

### **Heredoc Syntax**

Heredoc is used to define a string over multiple lines, and it can interpret variables and escape sequences (like `\n`, `\t`).

#### **Syntax**:

```php
$string = <<<EOD
This is a string
spanning multiple
lines in PHP.
EOD;
```

- The string starts with `<<<EOD` (or any identifier you choose) and ends with the same identifier (`EOD` in this case). The identifier can be any string, as long as it matches at the end.
- There is no need to escape special characters like quotes inside the string.
- It can parse variables and escape sequences.

#### **Example with Variables and Escape Sequences**:

```php
<?php
$name = "John";
$age = 30;

$str = <<<EOD
Hello, my name is $name.
I am $age years old.
This is a multi-line string.
EOD;

echo $str;
?>
```

**Output**:

```
Hello, my name is John.
I am 30 years old.
This is a multi-line string.
```

- In this example, the variables `$name` and `$age` are parsed and their values are injected into the string.
- Escape sequences like newline (`\n`) and tab (`\t`) are also parsed.

#### **Important Notes for Heredoc**:
- The identifier at the end must be the same as the starting identifier and cannot have any indentation or leading spaces. It should be on a new line after the string, without any spaces before it.

### **Nowdoc Syntax**

Nowdoc is similar to Heredoc, but it behaves more like a single-quoted string. It does not parse variables or escape sequences within the string. It is useful when you need a raw string without any variable interpolation or escape sequence parsing.

#### **Syntax**:

```php
$string = <<<'EOD'
This is a string
spanning multiple
lines in PHP.
EOD;
```

- The string starts with `<<<'EOD` and ends with the same identifier (`EOD`).
- The identifier is enclosed in single quotes (`'`) at the start.
- It does not interpret variables or escape sequences.

#### **Example with No Variable Parsing**:

```php
<?php
$name = "John";
$age = 30;

$str = <<<'EOD'
Hello, my name is $name.
I am $age years old.
This is a raw multi-line string.
EOD;

echo $str;
?>
```

**Output**:

```
Hello, my name is $name.
I am $age years old.
This is a raw multi-line string.
```

- In this case, the variables `$name` and `$age` are not parsed, and the literal text `$name` and `$age` are printed as they are.
- Escape sequences like `\n` or `\t` are not processed either.

### **Key Differences Between Heredoc and Nowdoc**

| Feature                        | **Heredoc**                                    | **Nowdoc**                                   |
|---------------------------------|------------------------------------------------|----------------------------------------------|
| **Variable Parsing**            | Yes, variables inside the string are parsed.   | No, variables are not parsed.                |
| **Escape Sequences**            | Yes, escape sequences (like `\n`, `\t`, etc.) are processed. | No, escape sequences are not processed.      |
| **Syntax**                      | Starts with `<<<EOD` and ends with `EOD`. No quotes around the identifier. | Starts with `<<<'EOD` and ends with `'EOD'`. Identifier is enclosed in single quotes. |
| **Use Case**                    | Suitable when you want to embed variables and process escape sequences. | Suitable when you need a raw, unprocessed string (e.g., for code or SQL queries). |

### **When to Use Each**

- **Heredoc** is ideal for scenarios where you need to embed variables or process escape sequences in a string over multiple lines.
- **Nowdoc** is useful when you need a raw string where nothing should be interpreted, such as for large blocks of text like code or JSON that shouldn't be altered.

### **Examples of Usage**

#### **Heredoc with Formatting**

```php
<?php
$variable = "PHP";
$text = <<<EOD
This is a Heredoc example.
I am learning $variable.
New lines and special characters like \n and \t are processed.
EOD;
echo $text;
?>
```

**Output**:

```
This is a Heredoc example.
I am learning PHP.
New lines and special characters like \n and \t are processed.
```

#### **Nowdoc with Raw String**

```php
<?php
$sql = <<<'SQL'
SELECT * FROM users WHERE name = '$name' AND age = $age;
SQL;
echo $sql;
?>
```

**Output**:

```
SELECT * FROM users WHERE name = '$name' AND age = $age;
```

In this case, the variables `$name` and `$age` are not interpreted, and the SQL query is returned as a raw string, making Nowdoc ideal for this situation.
