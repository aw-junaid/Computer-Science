The provided Python script is a command-line utility that uses the `geolite2` library to obtain geolocation information for a given hostname. It resolves the hostname to an IP address, queries the MaxMind GeoLite2 database, and then prints the geolocation information in JSON format. Here's an explanation of the code:

```python
#!/usr/bin/env python3

import socket
from geolite2 import geolite2
import argparse
import json

# Command-line argument parser
parser = argparse.ArgumentParser(description='Get IP Geolocation info')
parser.add_argument('--hostname', action="store", dest="hostname", default='python.org')

# Parse command-line arguments
given_args = parser.parse_args()
hostname = given_args.hostname
ip_address = socket.gethostbyname(hostname)

# Print the resolved IP address
print("IP address: {0}".format(ip_address))

# Create a GeoLite2 database reader
reader = geolite2.reader()

# Query the GeoLite2 database with the resolved IP address
response = reader.get(ip_address)

# Print the geolocation information in JSON format
print(json.dumps(response, indent=4))

# Extract and print specific geolocation details
print("Continent:", json.dumps(response['continent']['names']['en'], indent=4))
print("Country:", json.dumps(response['country']['names']['en'], indent=4))
print("Latitude:", json.dumps(response['location']['latitude'], indent=4))
print("Longitude:", json.dumps(response['location']['longitude'], indent=4))
print("Time zone:", json.dumps(response['location']['time_zone'], indent=4))
```

Explanation:

1. **Shebang Line:**
   - `#!/usr/bin/env python3` is a shebang line that indicates the path to the Python interpreter to use when executing the script.

2. **Imports:**
   - The script imports necessary modules: `socket` for hostname resolution, `geolite2` for working with the GeoLite2 database, `argparse` for command-line argument parsing, and `json` for JSON formatting.

3. **Argument Parsing with `argparse`:**
   - The script uses `argparse` to define and parse command-line arguments.
   - It accepts a single optional argument `--hostname`, specifying the hostname to look up (default is 'python.org').

4. **Resolving Hostname to IP:**
   - The script uses `socket.gethostbyname(hostname)` to resolve the given hostname to an IP address.
   - The resolved IP address is then printed to the console.

5. **GeoLite2 Database Reader:**
   - It creates a `geolite2.reader()` object, allowing you to query the GeoLite2 database.

6. **Querying the GeoLite2 Database:**
   - The script queries the GeoLite2 database with the resolved IP address using `reader.get(ip_address)`.

7. **Displaying Geolocation Information in JSON:**
   - The geolocation information is printed in JSON format using `json.dumps(response, indent=4)`.

8. **Extracting Specific Geolocation Details:**
   - Specific details such as continent name, country name, latitude, longitude, and time zone are extracted from the response and printed individually.

9. **Note:**
   - Make sure to have the `geolite2` library installed (`pip install maxminddb-geolite2`) and ensure you have the necessary permissions to read the GeoLite2 database file.

You can run this script from the command line, providing a hostname using the `--hostname` option, and it will display geolocation information based on the resolved IP address. For example:

```bash
python script_name.py --hostname example.com
```
