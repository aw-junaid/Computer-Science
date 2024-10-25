To check for allowed characters in a string using regular expressions in Python, you can define a pattern that specifies the characters you want to allow, and then use the `re` module to perform the matching.

Here's an example of how to check if a string contains only certain allowed characters:

```python
import re

def is_valid_string(input_string, allowed_characters):
    pattern = f'^[{re.escape(allowed_characters)}]+$'
    return re.match(pattern, input_string) is not None

input_string = "Hello123"
allowed_characters = "A-Za-z0-9"  # Allowed characters: letters (uppercase and lowercase) and digits

if is_valid_string(input_string, allowed_characters):
    print("String is valid.")
else:
    print("String contains disallowed characters.")
```

In this example:

- `allowed_characters` specifies the characters that are allowed in the input string. Here, "A-Za-z0-9" represents letters (both uppercase and lowercase) and digits.
- The `re.escape()` function is used to escape any special characters in the allowed characters string to ensure that they are treated as literal characters in the regex pattern.
- The `^` anchor asserts the start of the string, and `+` indicates one or more occurrences of the allowed characters.
- `re.match()` is used to match the input string against the pattern. If the match is successful, the string is considered valid.

You can modify the `allowed_characters` string to include the specific characters you want to allow. You can also adjust the regex pattern to fit your specific requirements, such as allowing additional characters or enforcing specific character counts.
