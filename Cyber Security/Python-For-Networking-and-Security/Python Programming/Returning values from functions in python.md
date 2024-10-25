In Python, functions can return values using the `return` statement. The value(s) returned by a function can then be assigned to variables or used in expressions. Here's how you return values from functions:

**Returning a Single Value:**

```python
def add(a, b):
    result = a + b
    return result

sum_result = add(5, 3)
print(sum_result)  # Output: 8
```

In this example, the `add()` function returns the sum of two numbers. When you call the function and assign its result to the `sum_result` variable, you can use that value in your program.

**Returning Multiple Values:**

Python functions can also return multiple values using tuples. You can unpack these values into separate variables after calling the function.

```python
def divide_and_remainder(a, b):
    quotient = a // b
    remainder = a % b
    return quotient, remainder

quot, rem = divide_and_remainder(10, 3)
print("Quotient:", quot)  # Output: 3
print("Remainder:", rem)  # Output: 1
```

In this example, the `divide_and_remainder()` function returns both the quotient and remainder of division. The returned values are unpacked into separate variables (`quot` and `rem`) after the function call.

**Returning None:**

If you don't explicitly use a `return` statement in a function, it will return `None` by default.

```python
def greet(name):
    print(f"Hello, {name}!")

result = greet("Alice")
print(result)  # Output: None
```

Here, the `greet()` function prints a greeting but does not return any value. When you print the result of the function call, you'll see `None`.

Remember that a function can have only one `return` statement. Once the function encounters a `return` statement, it immediately exits, and any subsequent code in the function is not executed.
