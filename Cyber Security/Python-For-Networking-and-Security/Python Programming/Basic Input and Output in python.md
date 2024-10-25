Input and output (I/O) operations are fundamental in any programming language for interacting with users and external data. In Python, you can perform basic input and output operations using the `input()` function for reading user input and the `print()` function for displaying output. Here's a basic introduction to input and output in Python:

**1. Output with `print()`:**
The `print()` function is used to display output on the screen. You can pass one or more arguments to `print()`, and it will concatenate them and display the result.

```python
name = "Alice"
age = 30

print("Hello, " + name + "! You are " + str(age) + " years old.")
```

Alternatively, you can use formatted string literals (f-strings) for more concise and readable output:

```python
name = "Alice"
age = 30

print(f"Hello, {name}! You are {age} years old.")
```

**2. Input with `input()`:**
The `input()` function is used to read user input from the console. It reads a line of text from the user and returns it as a string.

```python
name = input("Enter your name: ")
age = int(input("Enter your age: "))

print(f"Hello, {name}! You are {age} years old.")
```

Remember that the `input()` function returns a string, so if you want to use the input as a number, you'll need to convert it using functions like `int()` or `float()`.

**3. File I/O:**
Python also provides capabilities for reading from and writing to files. You can use functions like `open()`, `read()`, `write()`, `readline()`, and `close()` to perform file I/O operations.

```python
# Writing to a file
with open("output.txt", "w") as file:
    file.write("Hello, World!")

# Reading from a file
with open("output.txt", "r") as file:
    content = file.read()
    print(content)
```

These are some of the basic concepts of input and output in Python. More advanced I/O operations, such as working with different file formats or handling exceptions, can also be performed using Python's built-in functions and libraries.
