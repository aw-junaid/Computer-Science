You can reverse a string in Python using several methods. Here are a few different ways to achieve this:

1. **Using Slicing:**

   You can use slicing to reverse the order of characters in a string.

   ```python
   original_string = "hello"
   reversed_string = original_string[::-1]
   print(reversed_string)  # Output: "olleh"
   ```

2. **Using the `reversed()` Function:**

   The `reversed()` function can be used to reverse any iterable, including strings.

   ```python
   original_string = "hello"
   reversed_string = "".join(reversed(original_string))
   print(reversed_string)  # Output: "olleh"
   ```

3. **Using a Loop:**

   You can use a loop to iterate through the characters of the string in reverse order.

   ```python
   original_string = "hello"
   reversed_string = ""
   for char in original_string:
       reversed_string = char + reversed_string
   print(reversed_string)  # Output: "olleh"
   ```

4. **Using `str.join()` and `list()`:**

   You can convert the string to a list of characters, reverse the list, and then join the characters back into a string.

   ```python
   original_string = "hello"
   reversed_string = "".join(list(reversed(original_string)))
   print(reversed_string)  # Output: "olleh"
   ```

All of these methods will reverse the order of characters in a string. Choose the method that you find most readable and suitable for your specific use case.
