Working with files and folders (directories) is a common task in programming. Python provides built-in modules and functions that allow you to perform various input and output operations on files and directories. Here's a brief overview of file and folder I/O in Python:

**Working with Files:**

1. **Opening and Closing Files:** You can use the `open()` function to open a file. It takes two arguments: the filename and the mode (e.g., "r" for reading, "w" for writing, "a" for appending). After you're done, it's important to close the file using the `close()` method or by using the `with` statement to ensure proper cleanup.

   ```python
   # Reading from a file
   with open("file.txt", "r") as file:
       content = file.read()

   # Writing to a file
   with open("output.txt", "w") as file:
       file.write("Hello, World!")
   ```

2. **Reading and Writing:** You can read from a file using methods like `read()`, `readline()`, or `readlines()`. To write to a file, you can use the `write()` method.

   ```python
   with open("file.txt", "r") as file:
       content = file.read()
       print(content)

   with open("output.txt", "w") as file:
       file.write("Hello, World!")
   ```

3. **Appending to Files:** You can open a file in append mode using "a". This allows you to add content to the end of an existing file.

   ```python
   with open("file.txt", "a") as file:
       file.write("This line is appended.")
   ```

**Working with Folders (Directories):**

1. **Creating Directories:** You can create a new directory using the `os` module's `mkdir()` function.

   ```python
   import os
   os.mkdir("my_folder")
   ```

2. **Listing Files and Subdirectories:** The `os` module provides functions like `listdir()` and `scandir()` to list files and directories in a folder.

   ```python
   import os
   contents = os.listdir("my_folder")
   for item in contents:
       print(item)
   ```

3. **Checking if a Path Exists:** You can use `os.path.exists()` to check if a file or folder exists.

   ```python
   import os
   if os.path.exists("my_folder"):
       print("The folder exists.")
   ```

4. **Removing Files and Directories:** The `os` module's `remove()` function can be used to delete files, and the `rmdir()` function can be used to delete empty directories.

   ```python
   import os
   os.remove("file.txt")
   os.rmdir("my_folder")
   ```

These are just some of the basic operations you can perform with files and folders in Python. For more complex tasks, such as working with file paths, copying and moving files, or handling exceptions, you may need to use additional functions and libraries like `shutil`.
