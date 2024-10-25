Docstrings are used to document Python code, providing explanations and details about functions, modules, classes, and methods. Properly documented code helps improve readability, maintainability, and collaboration among developers. Here's how you can write documentation using docstrings in Python:

1. **Function and Method Docstrings:**
   To document a function or method, place a docstring immediately below the function or method definition. A docstring is a string enclosed in triple quotes (`'''` or `"""`) and provides information about the purpose, parameters, return value, and usage of the function.

   ```python
   def add(a, b):
       """
       Adds two numbers and returns the result.

       Parameters:
       a (int): The first number.
       b (int): The second number.

       Returns:
       int: The sum of a and b.
       """
       return a + b
   ```

2. **Module Docstrings:**
   To document a module, place a docstring at the beginning of the module file. The module docstring typically provides an overview of the module's purpose, contents, and usage.

   ```python
   """
   Math Operations Module

   This module provides functions for performing basic math operations.
   """

   def add(a, b):
       """
       Adds two numbers and returns the result.
       ...
       """
       return a + b
   ```

3. **Class Docstrings:**
   To document a class, place a docstring immediately below the class definition. The class docstring should describe the class's purpose, attributes, methods, and usage.

   ```python
   class Rectangle:
       """
       Represents a rectangle with width and height attributes.
       ...

       Attributes:
       width (float): The width of the rectangle.
       height (float): The height of the rectangle.
       """
       def __init__(self, width, height):
           self.width = width
           self.height = height

       def area(self):
           """Calculates and returns the area of the rectangle."""
           return self.width * self.height
   ```

4. **Accessing Docstrings:**
   You can access docstrings using the `help()` function or by accessing the `__doc__` attribute of functions, classes, and modules:

   ```python
   print(help(add))  # Displays the docstring of the add function
   print(add.__doc__)  # Accesses the docstring of the add function
   ```

Remember to follow consistent and clear conventions when writing docstrings. You can use tools like Sphinx to generate documentation from docstrings and create user-friendly documentation for your projects. Well-documented code is an essential aspect of writing high-quality and maintainable Python programs.
