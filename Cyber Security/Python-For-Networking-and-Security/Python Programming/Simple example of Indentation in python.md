Indentation in Python is used to define the structure and grouping of code blocks. It's crucial for defining the scope of loops, conditional statements, functions, and other code structures. Here's a simple example to illustrate indentation in Python:

```python
# Example of indentation in Python

def greet(name):
    if name == "Alice":
        print("Hello, Alice!")
    else:
        print("Hello, stranger!")

    print("Goodbye!")  # This line is at the same indentation level as the if-else block

# Main program
user_name = input("Enter your name: ")
greet(user_name)
```

In the above example:

1. The `greet()` function is defined, taking a `name` parameter.
2. Inside the function, there's an `if-else` block. The lines within the `if` and `else` blocks are indented, indicating that they belong to the respective branches of the condition.
3. The `print("Goodbye!")` statement is at the same indentation level as the `if-else` block, indicating that it's part of the function, but outside the `if-else` block.
4. In the main program, the user is asked to enter their name, and the `greet()` function is called with the entered name.

Indentation in this example is used to define the boundaries of the function and the conditional block. It tells Python which statements are part of which code blocks. Incorrect indentation can lead to syntax errors or logic issues in your code.

Remember that Python relies on consistent indentation to determine the structure of your program, so it's essential to maintain proper and consistent indentation throughout your code.
