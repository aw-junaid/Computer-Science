Local Scope and Global Scope in Python refer to the accessibility and visibility of variables within different parts of your code. Understanding the distinction between these scopes is crucial for writing clear and maintainable programs.

**Local Scope:**
- A variable has local scope if it is defined within a function. It is only accessible within that function and its nested functions.
- Variables with local scope are temporary and exist only as long as the function is executing.
- Local variables do not interfere with variables of the same name in other functions or in the global scope.

Example:

```python
def my_function():
    local_variable = 10  # Local variable
    print(local_variable)

my_function()
# print(local_variable)  # This would raise an error because local_variable is not defined here
```

**Global Scope:**
- A variable has global scope if it is defined at the top level of a module or explicitly declared as global within a function.
- Variables with global scope are accessible from anywhere in the module or within functions that declare them as global.
- Global variables are typically used for constants or values that need to be shared across multiple functions.

Example:

```python
global_variable = 20  # Global variable

def my_function():
    global global_variable  # Declare global within the function
    print(global_variable)

my_function()
print(global_variable)  # Accessible outside the function as well
```

It's important to note that when a variable is accessed within a scope, Python follows the LEGB (Local, Enclosing, Global, Built-in) rule to determine the order in which scopes are searched for the variable's value. If a variable is not found in the local scope, Python will search in the enclosing (e.g., class or function), global, and built-in scopes.

Example:

```python
x = "global"

def outer_function():
    x = "enclosing"

    def inner_function():
        print(x)  # Searches the LEGB rule for the value of x

    inner_function()

outer_function()
```

Understanding local and global scope helps you manage variables effectively and avoid unintended conflicts or name collisions in your code.
