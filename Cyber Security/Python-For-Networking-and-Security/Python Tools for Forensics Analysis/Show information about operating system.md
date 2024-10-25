This Python script analyzes the "SOFTWARE" registry hive on a Windows system, specifically focusing on the "Microsoft\\Windows NT\\CurrentVersion" registry key. It extracts and prints information such as the product name, current version, service pack, and product ID. The script uses the `Registry` class from the `python-registry` library to access and inspect the registry data. Here's an explanation of the code:

```python
#!/usr/bin/python3

import sys
from Registry import Registry

# Open the registry hive specified in the command-line argument
reg = Registry.Registry(sys.argv[1])

# Print an informative message
print("Analyzing SOFTWARE in Windows registry...")

try:
    # Attempt to open the "Microsoft\\Windows NT\\CurrentVersion" registry key
    key = reg.open("Microsoft\\Windows NT\\CurrentVersion")

    # Print various information from the registry key
    print("\tProduct name: " + key.value("ProductName").value())
    print("\tCurrentVersion: " + key.value("CurrentVersion").value())
    print("\tServicePack: " + key.value("CSDVersion").value())
    print("\tProductID: " + key.value("ProductId").value() + "\n")

except Registry.RegistryKeyNotFoundException as exception:
    # Handle the exception if the registry key is not found
    print("Exception", exception)
```

Explanation:

1. **Command-Line Argument:**
   - The script takes a command-line argument (`sys.argv[1]`), which should be the path to the Windows registry hive file to analyze.

2. **Registry Analysis:**
   - The `Registry` class is used to open the specified registry hive file (`sys.argv[1]`).
   - The script then attempts to open the "Microsoft\\Windows NT\\CurrentVersion" registry key using `reg.open("Microsoft\\Windows NT\\CurrentVersion")`.

3. **Output Information:**
   - If the key is successfully opened, the script prints various information extracted from specific values in the registry key:
     - `ProductName`: The name of the Windows product.
     - `CurrentVersion`: The current version of the Windows operating system.
     - `CSDVersion`: The service pack version.
     - `ProductId`: The product ID.

4. **Exception Handling:**
   - If the "Microsoft\\Windows NT\\CurrentVersion" registry key is not found, it catches the `RegistryKeyNotFoundException` exception and prints an error message.

This script provides an overview of key information related to the Windows operating system version and product details stored in the registry.
