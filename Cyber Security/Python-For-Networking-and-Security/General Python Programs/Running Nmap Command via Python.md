### Running Nmap Command via Python

Your Python script executes an Nmap command using the `os.system` function. Here's an explanation:

```python
import os

nmap_command = "nmap -sT 127.0.0.1"

os.system(nmap_command)
```

### Explanation:

1. **Importing the `os` Module:**
   ```python
   import os
   ```
   This line imports the `os` module, which provides a way to interact with the operating system, including running shell commands.

2. **Defining the Nmap Command:**
   ```python
   nmap_command = "nmap -sT 127.0.0.1"
   ```
   Here, you define an Nmap command as a string. This command (`-sT`) performs a TCP connect scan on the localhost (`127.0.0.1`).

3. **Executing the Nmap Command:**
   ```python
   os.system(nmap_command)
   ```
   The `os.system` function is used to run the Nmap command in the system shell. It passes the command string to the operating system for execution.

### Note:
- Ensure that Nmap is installed on your system, and its executable is in the system's PATH.
- Be cautious when running Nmap scans, especially on networks or systems that you do not own or do not have permission to scan.
- This script is a basic example and might not capture the output or handle errors. Depending on your use case, you may want to capture the output or use more advanced Python libraries for interacting with Nmap.
