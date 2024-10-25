Defining and calling functions is a fundamental concept in Python programming. Functions allow you to encapsulate a block of code that can be reused and organized. Here's how you define and call simple functions in Python:

**Defining a Function:**

You define a function using the `def` keyword, followed by the function name, parameters (if any), and a colon. The function body is indented under the `def` statement.

```python
def greet(name):
    print(f"Hello, {name}!")
```

**Calling a Function:**

You call a function by using its name followed by parentheses. If the function takes parameters, you provide the values within the parentheses.

```python
greet("Alice")  # Output: Hello, Alice!
```

Here's a complete example that defines and calls a simple function:

```python
def square(x):
    return x ** 2

number = 5
result = square(number)
print(f"The square of {number} is {result}")
```

In this example, the function `square()` takes a parameter `x` and returns the square of `x`. The function is called with the value `5`, and the result is printed.

Functions can have multiple parameters, and they can return values using the `return` statement. You can define functions at the module level or within other functions. Functions allow you to organize and modularize your code, making it more readable and maintainable.
