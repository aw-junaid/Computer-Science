This Python script analyzes the "SOFTWARE" registry hive on a Windows system, specifically focusing on the "Microsoft\\Windows\\CurrentVersion\\Run" registry key. It uses the `Registry` class from the `python-registry` library to access and inspect the registry data. Here's an explanation of the code:

```python
#!/usr/bin/python3

import sys
from Registry import Registry

# Open the registry hive specified in the command-line argument
reg = Registry.Registry(sys.argv[1])

# Print an informative message
print("Analyzing SOFTWARE in Windows registry...")

try:
    # Attempt to open the "Microsoft\\Windows\\CurrentVersion\\Run" registry key
    key = reg.open("Microsoft\\Windows\\CurrentVersion\\Run")

    # Print the last modification timestamp of the registry key
    print("Last modified: %s [UTC]" % key.timestamp())

    # Iterate over the values in the registry key
    for value in key.values():
        print("Name: " + value.name() + ", Value path: " + value.value())

except Registry.RegistryKeyNotFoundException as exception:
    # Handle the exception if the registry key is not found
    print("Exception", exception)
```

Explanation:

1. **Command-Line Argument:**
   - The script takes a command-line argument (`sys.argv[1]`), which should be the path to the Windows registry hive file to analyze.

2. **Registry Analysis:**
   - The `Registry` class is used to open the specified registry hive file (`sys.argv[1]`).
   - The script then attempts to open the "Microsoft\\Windows\\CurrentVersion\\Run" registry key using `reg.open("Microsoft\\Windows\\CurrentVersion\\Run")`.

3. **Output Information:**
   - If the key is successfully opened, the script prints the last modification timestamp of the registry key (`key.timestamp()` in UTC).
   - It then iterates over the values in the registry key using a loop (`for value in key.values()`).
   - For each value, it prints the name and value path.

4. **Exception Handling:**
   - If the "Microsoft\\Windows\\CurrentVersion\\Run" registry key is not found, it catches the `RegistryKeyNotFoundException` exception and prints an error message.

The script provides a basic overview of the contents of the "Microsoft\\Windows\\CurrentVersion\\Run" registry key, which typically contains entries for programs that run at system startup. The timestamp indicates when the registry key was last modified.
