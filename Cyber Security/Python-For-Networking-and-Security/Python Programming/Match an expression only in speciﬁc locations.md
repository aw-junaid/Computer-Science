To match an expression only in specific locations within a string using regular expressions in Python, you can use the `re` module along with anchors and other regex constructs. Anchors are special characters that represent specific positions in a string.

Here are a few scenarios where you might want to match expressions in specific locations:

1. **Match at the Start of the String:**

   To match an expression only at the beginning of the string, use the `^` anchor:

   ```python
   import re

   pattern = r'^\d+'  # Match digits at the beginning of the string
   text = "42 apples, 123 bananas, 7 oranges"
   
   match = re.match(pattern, text)
   if match:
       print("Match:", match.group())
   else:
       print("No match")
   ```

2. **Match at the End of the String:**

   To match an expression only at the end of the string, use the `$` anchor:

   ```python
   import re

   pattern = r'\d+$'  # Match digits at the end of the string
   text = "42 apples, 123 bananas, 7 oranges"
   
   match = re.search(pattern, text)
   if match:
       print("Match:", match.group())
   else:
       print("No match")
   ```

3. **Match at Specific Positions:**

   If you want to match an expression at specific positions within the string (e.g., starting from the 10th character), you can use slicing along with `re.search()`:

   ```python
   import re

   pattern = r'\d+'  # Match digits anywhere in the string
   text = "42 apples, 123 bananas, 7 oranges"
   
   match = re.search(pattern, text[10:])  # Start matching from the 10th character
   if match:
       print("Match:", match.group())
   else:
       print("No match")
   ```

4. **Match within Specific Substrings:**

   If you want to match an expression only within specific substrings (e.g., within parentheses), you can adjust the pattern accordingly:

   ```python
   import re

   pattern = r'\(\d+\)'  # Match digits within parentheses
   text = "42 apples, (123) bananas, (7) oranges"
   
   matches = re.findall(pattern, text)
   if matches:
       for match in matches:
           print("Match:", match)
   else:
       print("No matches")
   ```

These are just a few examples of how you can match expressions in specific locations within a string using regular expressions. Adjust the patterns and anchors based on your specific use case and requirements.
