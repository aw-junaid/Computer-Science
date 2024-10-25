The provided code defines a function `write_results` that creates a temporary file using the `NamedTemporaryFile` class from the `tempfile` module and writes the provided results to that file. Let's break down the code and understand its functionality:

```python
from tempfile import NamedTemporaryFile

def write_results(results):
    # Create a NamedTemporaryFile object, and set delete=False to keep the file after it's closed
    filename = NamedTemporaryFile(delete=False)

    # Print the name of the temporary file
    print(filename.name)

    # Write the results (as bytes) to the temporary file
    filename.write(bytes(results, "utf-8"))

    # Print a message indicating that the results are written to the temporary file
    print("Results written to", filename)

# Example usage of the write_results function
write_results("writing in a temp file")
```

Explanation of the code:

1. **Import `NamedTemporaryFile`:**
   - The code imports the `NamedTemporaryFile` class from the `tempfile` module. This class provides a convenient way to create temporary files.

2. **`write_results` Function:**
   - The `write_results` function takes a single parameter `results`, which represents the data to be written to the temporary file.

3. **Create a Named Temporary File:**
   - The function creates a `NamedTemporaryFile` object named `filename`. The `delete=False` argument is used to indicate that the file should not be automatically deleted when it is closed. This allows the file to persist after the function completes.

4. **Print Temporary File Name:**
   - The name of the temporary file is printed to the console using `filename.name`.

5. **Write Results to the Temporary File:**
   - The provided `results` string is converted to bytes using `bytes(results, "utf-8")` and then written to the temporary file using the `write` method.

6. **Print Message:**
   - A message is printed to the console indicating that the results have been written to the temporary file.

7. **Example Usage:**
   - The function is called with an example string ("writing in a temp file").

### Note:
- The `NamedTemporaryFile` object is automatically closed when it goes out of scope, and since `delete=False` was set, the file is not deleted. The file will persist until it is explicitly deleted or until the program exits.

- In practice, it's good to consider proper file closing using a `with` statement to ensure that resources are released promptly.

- If you want the temporary file to be automatically deleted when closed, you can omit the `delete=False` argument, and the file will be deleted when the `NamedTemporaryFile` object is closed.

- Always be cautious when working with temporary files, and ensure that they are handled securely to avoid security vulnerabilities.
