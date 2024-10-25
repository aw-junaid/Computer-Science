String formatting in Python allows you to create formatted strings by embedding variable values or expressions within a string. There are several ways to format strings in Python, including using the `%` operator, the `str.format()` method, and f-strings (formatted string literals).

**1. Using `%` Operator:**

The `%` operator can be used to format strings by specifying placeholders and providing values for substitution.

```python
name = "Alice"
age = 30

formatted_string = "My name is %s and I am %d years old." % (name, age)
print(formatted_string)
```

**2. Using `str.format()` Method:**

The `str.format()` method allows more flexible string formatting using curly braces `{}` as placeholders.

```python
name = "Bob"
age = 25

formatted_string = "My name is {} and I am {} years old.".format(name, age)
print(formatted_string)
```

**3. Using f-strings (Formatted String Literals):**

Introduced in Python 3.6, f-strings provide a concise and readable way to format strings directly inside the string literals.

```python
name = "Charlie"
age = 28

formatted_string = f"My name is {name} and I am {age} years old."
print(formatted_string)
```

F-strings are generally preferred due to their readability and simplicity.

**String Formatting Options:**

String formatting allows you to control how variables are displayed within the string. Some common formatting options include:

- `%s`: String
- `%d` or `%i`: Integer
- `%f`: Floating-point number
- `%x` or `%X`: Integer as hexadecimal
- `%.2f`: Floating-point number with 2 decimal places

You can find more formatting options and examples in the Python documentation.

**Alignment and Padding:**

You can also specify alignment and padding for variables within formatted strings:

```python
value = 42

formatted_string = f"The value is: {value:10}"  # Right-aligned with width 10
print(formatted_string)
```

String formatting is a powerful feature in Python that allows you to create more readable and expressive output. Choose the formatting method that best suits your preference and the version of Python you're using.
