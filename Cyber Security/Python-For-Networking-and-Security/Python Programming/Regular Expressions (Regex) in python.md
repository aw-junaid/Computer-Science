Regular expressions, often referred to as regex or regexp, are powerful tools for pattern matching and text manipulation. Python provides a built-in module called `re` that allows you to work with regular expressions. Regular expressions can be used for tasks like searching, extracting, validating, and replacing text patterns in strings.

Here's a basic overview of using regular expressions in Python:

1. **Import the `re` Module:**

   Before using regular expressions, you need to import the `re` module:

   ```python
   import re
   ```

2. **Matching Patterns:**

   The `re.match()` function is used to match patterns at the beginning of a string:

   ```python
   pattern = r"hello"
   text = "hello, world!"
   match = re.match(pattern, text)
   if match:
       print("Pattern matched:", match.group())
   ```

3. **Searching Patterns:**

   The `re.search()` function is used to search for patterns anywhere in a string:

   ```python
   pattern = r"world"
   text = "hello, world!"
   search = re.search(pattern, text)
   if search:
       print("Pattern found:", search.group())
   ```

4. **Pattern Groups and Capturing:**

   You can use parentheses to create groups and capture portions of matched text:

   ```python
   pattern = r"(hello), (world)"
   text = "hello, world!"
   match = re.match(pattern, text)
   if match:
       print("Full match:", match.group(0))
       print("First group:", match.group(1))
       print("Second group:", match.group(2))
   ```

5. **Find All Matches:**

   The `re.findall()` function returns a list of all occurrences of a pattern in a string:

   ```python
   pattern = r"\d+"  # Matches one or more digits
   text = "42 apples, 123 bananas, 7 oranges"
   matches = re.findall(pattern, text)
   print("Matches:", matches)
   ```

6. **Replacing Patterns:**

   The `re.sub()` function is used to replace patterns with a specified replacement:

   ```python
   pattern = r"\d+"  # Matches one or more digits
   text = "42 apples, 123 bananas, 7 oranges"
   replacement = "X"
   new_text = re.sub(pattern, replacement, text)
   print("New text:", new_text)
   ```

These are just a few basic examples of using regular expressions in Python. Regular expressions can become quite complex and powerful, enabling you to perform sophisticated text manipulations. It's important to understand the syntax and behavior of regular expressions to use them effectively. You can refer to the official Python documentation for the `re` module and other online resources for more advanced usage and patterns.
