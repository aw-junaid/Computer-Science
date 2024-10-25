When working with packages in Python, you can import submodules to access modules or items that are located within subdirectories of the package. Submodules allow you to organize and structure your code in a hierarchical manner. Here's how you can import submodules:

Suppose you have a package named `mypackage` with the following directory structure:

```
mypackage/
├── __init__.py
├── module1.py
└── submodule/
    ├── __init__.py
    └── module2.py
```

1. **Importing a Submodule:**

   To import a submodule, you use dot notation to specify the path to the submodule from the package. In the example above, you can import `module2` from the `submodule` subdirectory like this:

   ```python
   from mypackage.submodule import module2

   module2.some_function()
   ```

2. **Importing Specific Items from a Submodule:**

   You can also import specific items (functions, classes, variables) from a submodule.

   ```python
   from mypackage.submodule.module2 import some_function

   some_function()
   ```

3. **Importing All Items from a Submodule:**

   You can use the `*` wildcard to import all items from a submodule.

   ```python
   from mypackage.submodule.module2 import *

   some_function()
   ```

Keep in mind that while importing submodules can provide a structured way to organize your code, it's important to maintain a clear and readable codebase. Avoid excessive use of wildcard imports (`from ... import *`) as it can make your code harder to understand and maintain. Instead, import only the specific items you need.

Additionally, if your submodules have an `__all__` list defined, it specifies which symbols are exported when using the `*` import statement. This can help control what gets imported from a submodule. For example, in `submodule/__init__.py`:

```python
__all__ = ["module2"]
```

Then, when you use `from mypackage.submodule import *`, only `module2` will be imported.
