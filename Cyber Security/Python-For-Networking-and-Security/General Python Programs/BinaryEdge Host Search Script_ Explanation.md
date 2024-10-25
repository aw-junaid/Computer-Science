### BinaryEdge Host Search Script: Explanation

This Python script uses the BinaryEdge API to perform a host search for a specified domain.

### 1. Importing Required Modules:
```python
from pybinaryedge import BinaryEdge
import os
```
The script imports the necessary modules: `pybinaryedge` for accessing the BinaryEdge API and `os` for handling environment variables.

### 2. Setting BinaryEdge API Key and Initializing BinaryEdge API:
```python
key = os.environ['BINARYEDGE_API_KEY']
binaryEdge = BinaryEdge(key)
```
The BinaryEdge API key is retrieved from the environment variable `'BINARYEDGE_API_KEY'`, and an instance of the `BinaryEdge` class is created using this key.

### 3. Performing BinaryEdge Host Search:
```python
search_domain = 'www.python.org'
results = binaryEdge.host_search(search_domain)
```
The script performs a host search using the specified domain (`'www.python.org'`). The search results are stored in the `results` variable.

### 4. Displaying IP Addresses of Matching Hosts:
```python
for ip in results['events']:
    print("%s" % (ip['target']['ip']))
```
The script iterates over the search results (`results['events']`) and prints the IP addresses of the matching hosts.

### Usage Example:
- Ensure the BinaryEdge API key is set correctly in the environment variable `'BINARYEDGE_API_KEY'`.
- Run the script to perform a host search for the specified domain.
- The script outputs the IP addresses of the matching hosts.

### Summary:
- This script demonstrates how to use the BinaryEdge API to perform a host search based on a specific domain.
- It leverages the `pybinaryedge` Python library to interact with the BinaryEdge API.
- The script prints the IP addresses of the hosts that match the specified domain.
