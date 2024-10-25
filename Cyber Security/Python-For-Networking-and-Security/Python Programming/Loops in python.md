Loops in Python are used to execute a block of code repeatedly. They allow you to automate repetitive tasks and process collections of data. Python provides two main types of loops: `for` loops and `while` loops.

**1. `for` Loop:**
A `for` loop iterates over a sequence (such as a list, tuple, string, or range) and executes a block of code for each element in the sequence.

```python
fruits = ["apple", "banana", "cherry"]
for fruit in fruits:
    print(fruit)
```

**2. `while` Loop:**
A `while` loop repeatedly executes a block of code as long as a specified condition is `True`.

```python
count = 0
while count < 5:
    print(count)
    count += 1
```

Loops can also be controlled using the `break` and `continue` statements:

- The `break` statement is used to exit the loop prematurely.
- The `continue` statement is used to skip the rest of the current iteration and move to the next one.

```python
for num in range(10):
    if num == 5:
        break
    print(num)

for num in range(10):
    if num == 5:
        continue
    print(num)
```

Loops are commonly used when working with collections, performing repetitive calculations, reading data from files, and many other scenarios where you need to repeat a set of instructions multiple times. It's important to ensure that loops have a proper termination condition to prevent infinite loops.

Python also provides a variety of built-in functions and modules (such as `range()`, `enumerate()`, and `zip()`) that can enhance the functionality and efficiency of loops in various situations.
