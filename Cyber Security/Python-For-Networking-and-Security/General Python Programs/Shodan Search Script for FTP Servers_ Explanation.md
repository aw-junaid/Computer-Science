### Shodan Search Script for FTP Servers: Explanation

This Python script utilizes the Shodan API to search for FTP servers that have anonymous users logged in.

### 1. Importing Required Modules:
```python
import shodan
import re
import os
```
The script imports the necessary modules: `shodan` for accessing the Shodan API, `re` for regular expressions, and `os` for handling environment variables.

### 2. Setting Shodan API Key and Initializing Shodan API:
```python
servers =[]
shodanKeyString = os.environ['SHODAN_API_KEY']
shodanApi = shodan.Shodan(shodanKeyString)
```
The Shodan API key is retrieved from the environment variable `'SHODAN_API_KEY'`, and an instance of the `Shodan` class is created using this key.

### 3. Performing Shodan Search:
```python
results = shodanApi.search("port: 21 Anonymous user logged in")
print("hosts number: " + str(len( results['matches'])))
for result in results['matches']:
    if result['ip_str'] is not None:
        servers.append(result['ip_str'])
```
The script performs a Shodan search using the query string `"port: 21 Anonymous user logged in"`. It retrieves matching results and prints the total number of hosts found. The IP addresses of the matching hosts are stored in the `servers` list.

### 4. Displaying FTP Server IP Addresses:
```python
for server in servers:
    print(server)
```
Finally, the script iterates over the `servers` list and prints each FTP server's IP address.

### Usage Example:
- Ensure the Shodan API key is set correctly in the environment variable `'SHODAN_API_KEY'`.
- Run the script to perform a Shodan search for FTP servers with anonymous users logged in.
- The script outputs the total number of matching hosts and their respective IP addresses.

### Summary:
- This script demonstrates how to use the Shodan API to search for FTP servers based on specific criteria.
- It leverages the Shodan Python library and regular expressions to formulate a search query.
- The script prints the total number of matching hosts and displays the IP addresses of the identified FTP servers.
