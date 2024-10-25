Formatted string literals, often referred to as f-strings, are a convenient way to create formatted strings in Python. They allow you to embed expressions directly within string literals, making string formatting more readable and concise. F-strings were introduced in Python 3.6 and provide a powerful and intuitive way to format strings.

Here's how you use f-strings:

```python
name = "Alice"
age = 30

formatted_string = f"My name is {name} and I am {age} years old."
print(formatted_string)
```

In the example above, the variables `name` and `age` are embedded within the string using curly braces `{}`. The values of these variables are automatically inserted into the string.

**Expressions in F-strings:**

You can include any valid Python expressions inside the curly braces of an f-string. This allows you to perform calculations, call functions, and format variables directly within the string.

```python
x = 10
y = 20

formatted_string = f"The sum of {x} and {y} is {x + y}."
print(formatted_string)
```

**Formatting Options in F-strings:**

F-strings support a wide range of formatting options similar to those available with the `%` operator and the `str.format()` method.

```python
value = 123.456

formatted_string = f"Formatted value: {value:.2f}"
print(formatted_string)
```

In this example, the `:.2f` format specifier is used to display `value` with two decimal places.

**Alignment and Padding in F-strings:**

You can also control alignment and padding within f-strings.

```python
name = "Alice"
formatted_string = f"|{name:>10}|"
print(formatted_string)
```

The `:>10` format specifier aligns `name` to the right within a field of width 10.

**Using Braces in F-strings:**

If you need to include curly braces as literal characters in an f-string, you can double them.

```python
amount = 1000
formatted_string = f"{{Amount: {amount}}}"
print(formatted_string)
```

F-strings provide a concise and expressive way to create formatted strings, making your code more readable and reducing the need for additional string concatenation and formatting operations.
