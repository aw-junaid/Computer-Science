Using regular expressions (regex) in Python involves several steps:

1. **Import the `re` module**:

    Before you can use regex in Python, you need to import the `re` module:

    ```python
    import re
    ```

2. **Compile a Regex Pattern**:

    To use a regex pattern, you need to compile it first using `re.compile()`. This creates a regex object that you can use for pattern matching operations.

    ```python
    pattern = re.compile(r'pattern_here')
    ```

3. **Matching Patterns**:

    There are several functions in the `re` module that you can use to find patterns in strings:

    - `re.search()`: Searches for a pattern anywhere in the string.
    
    - `re.match()`: Matches a pattern at the beginning of the string.
    
    - `re.fullmatch()`: Matches a pattern against the entire string.
    
    - `re.findall()`: Finds all occurrences of a pattern in a string.
    
    - `re.finditer()`: Finds all occurrences and returns an iterator.

    ```python
    result = pattern.search('text_to_search')
    ```

4. **Using Match Objects**:

    When a match is found, you get a match object. You can extract information from it using various methods:

    - `group()`: Returns the matched text.
    
    - `start()`: Returns the starting position of the match.
    
    - `end()`: Returns the ending position of the match.
    
    - `span()`: Returns a tuple containing (start, end) positions.

    ```python
    if result:
        print(result.group())  # Prints the matched text
    ```

5. **Using Quantifiers and Anchors**:

    You can use quantifiers like `*` (0 or more), `+` (1 or more), `?` (0 or 1), and anchors `^` (start) and `$` (end) to refine your pattern.

    ```python
    pattern = re.compile(r'^\d{3}-\d{2}-\d{4}$')  # Matches a Social Security Number
    ```

6. **Groups and Alternation**:

    Groups are created using parentheses `()`. You can also use alternation `|` to match multiple patterns.

    ```python
    pattern = re.compile(r'(apple|banana|cherry)')
    ```

7. **Escaping Special Characters**:

    If you want to match special characters like `.`, `\`, `*`, etc., you need to escape them with a backslash `\`.

    ```python
    pattern = re.compile(r'\d+\.\d+')
    ```

8. **Using Modifiers**:

    You can use modifiers like `re.I` for case-insensitive matching, `re.M` for multi-line matching, and `re.S` to allow the dot `.` to match newline characters.

    ```python
    pattern = re.compile(r'pattern_here', re.I)
    ```

9. **Substituting Patterns**:

    You can use `re.sub()` to replace occurrences of a pattern in a string.

    ```python
    new_string = re.sub(r'old_pattern', 'replacement', 'original_string')
    ```

10. **Other Operations**:

    There are many other operations you can perform using regex in Python. This includes splitting strings, using lookahead and lookbehind, and more.

Remember that regex patterns can be complex and may require testing and adjustment. It's helpful to use online regex testers to experiment with your patterns before using them in your code. Additionally, refer to the Python `re` documentation for more advanced features and options.
