To retrieve data from a file in Python, you can use various methods depending on the format in which the data is stored. Here are examples of how to retrieve data from plain text, CSV, JSON, and pickle files:

1. **Plain Text Files (`open()` and Read):**

   You can use the `open()` function to open a file in read mode and read its contents.

   ```python
   with open("input.txt", "r") as file:
       data = file.read()
       print(data)
   ```

2. **CSV Files (`csv` Module):**

   Use the `csv` module to read data from CSV files.

   ```python
   import csv
   
   with open("input.csv", "r", newline="") as file:
       reader = csv.reader(file)
       for row in reader:
           print(row)
   ```

3. **JSON Files (`json` Module):**

   The `json` module is used for reading data from JSON files.

   ```python
   import json
   
   with open("input.json", "r") as file:
       data = json.load(file)
       print(data)
   ```

4. **Pickle Files (`pickle` Module):**

   The `pickle` module allows you to deserialize Python objects from pickle files.

   ```python
   import pickle
   
   with open("input.pkl", "rb") as file:
       data = pickle.load(file)
       print(data)
   ```

When retrieving data from a file, ensure that the file exists and is properly formatted according to the method you are using. Also, make sure to handle exceptions that may occur during file operations, such as `FileNotFoundError`, `IOError`, or `JSONDecodeError`, to provide graceful error handling in your code.
