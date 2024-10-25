**Nessus API Scanner Script**

This Python script interacts with the Nessus API to retrieve information about scans. Here's an explanation of the code:

```python
#!/usr/bin/env python3

import ness6rest
import argparse

# Define the Nessus server URL
nessus_url = "https://localhost:8834"

# Parse command-line arguments for login and password
parser = argparse.ArgumentParser()
parser.add_argument('--login',  required=True)
parser.add_argument('--password', required=True)
args = parser.parse_args()

# Create a Nessus Scanner object
scan = ness6rest.Scanner(url=nessus_url, login=args.login, password=args.password, insecure=True)

# Print the list of scans
print(scan.scan_list())

# Get detailed information about each scan
scans = scan.scan_list()['scans']
for detail_scan in scans:
    print(scan.scan_details(detail_scan['name']))
```

**Explanation:**

1. **Nessus Server URL:**
   - The variable `nessus_url` holds the URL of the Nessus server. Adjust this URL based on your Nessus server configuration.

2. **Command-Line Arguments:**
   - The script uses the `argparse` module to parse command-line arguments for the Nessus login and password. Users must provide these credentials when running the script.

3. **Create Nessus Scanner:**
   - An instance of the `ness6rest.Scanner` class is created with the specified Nessus server URL, login, password, and the `insecure` parameter set to `True` to allow connections to servers with self-signed SSL certificates.

4. **List Scans:**
   - The `scan_list()` method is called to retrieve information about available scans. This information is printed to the console.

5. **Scan Details:**
   - The script iterates through the list of scans and retrieves detailed information about each scan using the `scan_details()` method. This information is also printed to the console.

**Usage:**
- Save this script in a file, e.g., `nessus_script.py`.
- Run the script from the command line, providing the Nessus login and password as arguments:

  ```bash
  python nessus_script.py --login your_username --password your_password
  ```

**Note:**
- Ensure that the Nessus server is running and accessible.
- Modify the `nessus_url` variable if your Nessus server is hosted on a different URL or port.
- Adjust the script as needed based on the specific requirements of your Nessus environment.
