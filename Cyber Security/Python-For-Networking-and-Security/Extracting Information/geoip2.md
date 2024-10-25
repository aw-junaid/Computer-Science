The provided Python script is a command-line utility that takes a hostname as an argument, resolves its IP address, and then uses the `geoip2` module to obtain geolocation information for that IP address. Here's an explanation of the code:

```python
#!/usr/bin/env python3

import socket
import geoip2.database
import argparse

# Command-line argument parser
parser = argparse.ArgumentParser(description='Get IP Geolocation info')
parser.add_argument('--hostname', action="store", dest="hostname", default='python.org')

# Parse command-line arguments
given_args = parser.parse_args()
hostname = given_args.hostname

# Resolve the IP address of the given hostname
ip_address = socket.gethostbyname(hostname)
print("IP address: {0}".format(ip_address))

# Create a GeoIP2 database reader
reader = geoip2.database.Reader('GeoLite2-City.mmdb')

# Query the GeoIP2 database with the resolved IP address
response = reader.city(ip_address)

# Display geolocation information
if response is not None:
    print('Country: ', response.country)
    print('Continent: ', response.continent)
    print('Location: ', response.location)
```

Explanation:

1. **Shebang Line:**
   - `#!/usr/bin/env python3` is a shebang line that indicates the path to the Python interpreter to use when executing the script.

2. **Imports:**
   - The script imports the necessary modules: `socket` for hostname resolution and `geoip2.database` for working with the GeoIP2 database.

3. **Argument Parsing with `argparse`:**
   - The script uses the `argparse` module to define and parse command-line arguments.
   - It accepts a single optional argument `--hostname`, which specifies the hostname to look up (default is 'python.org').

4. **Resolving Hostname to IP:**
   - The script uses `socket.gethostbyname(hostname)` to resolve the given hostname to an IP address.
   - The resolved IP address is then printed to the console.

5. **GeoIP2 Database Reader:**
   - It creates a `geoip2.database.Reader` object using the 'GeoLite2-City.mmdb' database file.
   - The database file is assumed to be in the same directory as the script. You may need to adjust the path based on your setup.

6. **Querying the GeoIP2 Database:**
   - The script queries the GeoIP2 database with the resolved IP address using `reader.city(ip_address)`.

7. **Displaying Geolocation Information:**
   - The geolocation information, such as country, continent, and location, is printed to the console.

8. **Note:**
   - Make sure to have the `geoip2` library installed (`pip install geoip2`) and download the GeoIP2 database file ('GeoLite2-City.mmdb') from the MaxMind website.

You can run this script from the command line, providing a hostname using the `--hostname` option, and it will display geolocation information based on the resolved IP address. For example:

```bash
python script_name.py --hostname example.com
```
