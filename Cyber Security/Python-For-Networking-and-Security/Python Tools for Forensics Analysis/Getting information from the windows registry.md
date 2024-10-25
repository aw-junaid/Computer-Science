To retrieve information from the Windows Registry using Python, you can use the `winreg` module, which provides an interface to the Windows Registry API. Here's a simple example demonstrating how to read registry keys:

```python
import winreg

def read_registry_key(hive, subkey, key_name):
    try:
        # Open the registry key
        with winreg.OpenKey(hive, subkey) as registry_key:
            # Read the value of the specified key
            value, _ = winreg.QueryValueEx(registry_key, key_name)
            return value
    except FileNotFoundError:
        return None

# Example: Reading a registry key
hive = winreg.HKEY_LOCAL_MACHINE
subkey = r"SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall"
key_name = "DisplayName"

result = read_registry_key(hive, subkey, key_name)

if result is not None:
    print(f"The value of {key_name} is: {result}")
else:
    print(f"The specified registry key does not exist.")
```

This example reads the value of the "DisplayName" key under the "Uninstall" subkey in the HKEY_LOCAL_MACHINE hive. You can customize the `hive`, `subkey`, and `key_name` variables to suit your needs.

Here are some important notes:

- `hive`: Specifies the registry hive. Common values include `winreg.HKEY_LOCAL_MACHINE` and `winreg.HKEY_CURRENT_USER`.
- `subkey`: Specifies the path to the registry key.
- `key_name`: Specifies the name of the registry key value to read.

Remember to run your Python script with administrative privileges if you are accessing certain registry hives that require elevated permissions.

Additionally, be cautious when working with the Windows Registry, as modifying or deleting keys can impact system stability. Always double-check your code and understand the potential consequences before making changes to the registry.

If you need to perform more complex operations, such as enumerating keys or recursively traversing the registry, you can explore additional functions provided by the `winreg` module.
