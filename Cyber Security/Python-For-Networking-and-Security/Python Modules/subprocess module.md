The `subprocess` module in Python provides a way to spawn new processes, connect to their input/output/error pipes, and obtain their return codes. It replaces several older modules and functions, such as `os.system`, `os.spawn*`, and `os.popen*`. The `subprocess` module allows for more powerful process management and communication with the spawned processes.

Here are some common use cases and functionalities of the `subprocess` module:

1. **Running External Commands:**
   - `subprocess.run(command, [args, ...], *, input=None, ...):` Run the command with arguments. This is a high-level function that simplifies subprocess management.

   ```python
   import subprocess

   result = subprocess.run(["ls", "-l"], stdout=subprocess.PIPE)
   print(result.stdout.decode())
   ```

2. **Capturing Output:**
   - `subprocess.check_output(command, *, input=None, ...):` Run command with arguments and return its output as a byte string.

   ```python
   import subprocess

   result = subprocess.check_output(["echo", "Hello, World!"])
   print(result.decode())
   ```

3. **Running Shell Commands:**
   - `subprocess.run(command, *, shell=False, ...):` If `shell` is True, the command will be executed through the shell.

   ```python
   import subprocess

   result = subprocess.run("echo Hello, World!", shell=True, stdout=subprocess.PIPE)
   print(result.stdout.decode())
   ```

4. **Handling Input and Output Streams:**
   - `subprocess.PIPE`: Special value that can be used as the stdin, stdout, or stderr argument to indicate that a pipe to the standard stream should be opened.

   ```python
   import subprocess

   process = subprocess.Popen(["cat"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True)
   output, _ = process.communicate(input="Hello, Subprocess!")
   print(output)
   ```

5. **Checking Return Codes:**
   - `subprocess.CalledProcessError`: Raised when a process returns a non-zero exit code.

   ```python
   import subprocess

   try:
       subprocess.run(["ls", "nonexistent_directory"], check=True)
   except subprocess.CalledProcessError as e:
       print(f"Command failed with return code {e.returncode}")
   ```

6. **Timeouts:**
   - `timeout`: Specify a timeout for the command.

   ```python
   import subprocess

   try:
       subprocess.run(["sleep", "10"], timeout=5)
   except subprocess.TimeoutExpired as e:
       print(f"Command timed out after {e.timeout} seconds")
   ```

These examples cover some of the basic functionalities of the `subprocess` module. It's a powerful module for managing external processes and interacting with them from within Python scripts.
