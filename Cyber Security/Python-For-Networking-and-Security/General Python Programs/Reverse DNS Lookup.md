### Reverse DNS Lookup

This Python script demonstrates how to perform a reverse DNS lookup using the `dns.reversename` module.

### 1. Importing Required Modules:
```python
import dns.reversename
```
The script imports the `dns.reversename` module for reverse DNS lookup.

### 2. Performing Reverse DNS Lookup:
```python
domain = dns.reversename.from_address("45.55.99.72")
print(domain)
print(dns.reversename.to_address(domain))
```
The script uses `dns.reversename.from_address` to create a domain name from an IP address (`"45.55.99.72"` in this example). It then prints the obtained domain and performs a reverse operation using `dns.reversename.to_address` to get the original IP address back.

### 3. Output:
The output will include the reversed domain and the original IP address.

### Summary:
- The script demonstrates how to perform a reverse DNS lookup using the `dns.reversename` module.
- It converts an IP address to a domain name (`from_address`) and then converts it back to the original IP address (`to_address`).

### Note:
- Ensure that the `dnspython` library is installed before running the script (`pip install dnspython`).
