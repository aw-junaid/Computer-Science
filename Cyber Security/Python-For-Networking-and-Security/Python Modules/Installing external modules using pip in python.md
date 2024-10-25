To install external modules in Python, you can use a package manager called `pip`. `pip` is a tool that allows you to easily install, manage, and uninstall Python packages from the Python Package Index (PyPI) or other sources.

Here's how you can install external modules using `pip`:

1. **Open a Terminal or Command Prompt:**
   Open a terminal (Linux/Mac) or command prompt (Windows) on your computer.

2. **Check if `pip` is Installed:**
   To check if `pip` is installed, you can run the following command:
   
   ```bash
   pip --version
   ```

   If `pip` is not installed, you can install it by following the instructions on the [official pip documentation](https://pip.pypa.io/en/stable/installing/).

3. **Install a Package:**
   To install an external Python package, use the `pip install` command followed by the name of the package you want to install. For example, let's say you want to install the `requests` package, which is commonly used for making HTTP requests:

   ```bash
   pip install requests
   ```

   This command will download and install the `requests` package along with any dependencies it requires.

4. **Check Installed Packages:**
   You can check the list of installed packages and their versions using the following command:

   ```bash
   pip list
   ```

   This will display a list of installed packages along with their version numbers.

5. **Uninstall a Package:**
   If you want to uninstall a package, you can use the `pip uninstall` command followed by the package name:

   ```bash
   pip uninstall requests
   ```

   This will remove the `requests` package from your system.

It's important to note that you need to have appropriate permissions to install packages system-wide. In some cases, you might need to use `sudo` (on Linux/Mac) or run the command prompt as an administrator (on Windows) to install packages globally.

Additionally, you can create a virtual environment to isolate your project's dependencies and avoid conflicts between different projects. Virtual environments allow you to manage packages on a per-project basis. To create a virtual environment and install packages within it, you can use the `venv` module (Python 3.3+) or third-party tools like `virtualenv`.

Remember that the specific commands might vary slightly depending on your operating system and Python version.
