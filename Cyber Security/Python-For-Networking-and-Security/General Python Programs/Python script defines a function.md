### Purpose of the Code
The provided Python script defines a function, `count_words_file(url)`, which attempts to open and read the content of a file from a given URL. It then counts the number of words in the content using the `split()` method. The code also includes error handling to catch `URLError` exceptions and print information about the error.

### Import Statements
```python
import urllib.request
import urllib.error
```
- **Import Statements:** Import the necessary modules from `urllib.request` and `urllib.error` for handling HTTP requests and errors.

### Function for Counting Words in a File
```python
def count_words_file(url):
    try:
        file_response = urllib.request.urlopen(url)
    except urllib.error.URLError as error:
        print('Exception', error)
        print('Reason:', error.reason)
    else:
        content = file_response.read()
        return len(content.split())
```
- **Function Definition (`count_words_file`):**
  - Takes a URL as a parameter.
  - Tries to open the URL using `urllib.request.urlopen`.
  - Catches and handles `URLError` exceptions, printing the exception and its reason.
  - If the URL is successfully opened, reads the content and returns the count of words in the content using `len(content.split())`.

### Example Usage
```python
print(count_words_file('https://www.gutenberg.org/cache/epub/2000/pg2000.txt'))
```
- **Example Usage 1:**
  - Calls the `count_words_file` function with a URL pointing to a text file on Project Gutenberg.
  - Prints the count of words in the content of the file.

```python
count_words_file('https://not-exists.txt')
```
- **Example Usage 2:**
  - Calls the `count_words_file` function with a URL that does not exist (`'https://not-exists.txt'`).
  - Triggers a `URLError`, and the exception details are printed.

### Summary
The script defines a function to count words in the content of a file retrieved from a given URL. It demonstrates error handling for `URLError` exceptions when attempting to open a URL. The examples showcase the function's usage with both a valid URL and a non-existent URL, highlighting the error-handling mechanism.
