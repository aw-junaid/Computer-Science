### DNS Resolution Script Explanation

This Python script performs DNS resolution for a list of domain names and prints their corresponding IP addresses.

### 1. Importing Required Module:
```python
import dns.resolver
```
The script imports the `dns.resolver` module for DNS resolution.

### 2. Defining a List of Domain Names:
```python
hosts = ["oreilly.com", "yahoo.com", "google.com", "microsoft.com", "cnn.com"]
```
A list of domain names is defined.

### 3. Performing DNS Resolution:
```python
for host in hosts:
    print(host)
    ip = dns.resolver.query(host, "A")
    for i in ip:
        print(i)
```
A loop iterates over each domain name in the list. For each domain, it prints the domain name and then queries the DNS resolver for its A (IPv4 address) records. The resulting IP addresses are then printed.

### Usage:
- Ensure the `dnspython` library is installed (`pip install dnspython`).
- Run the script.

### Summary:
- The script uses the `dns.resolver` module to perform DNS resolution for a list of domain names.
- It queries the A records to obtain the corresponding IPv4 addresses.
- The script can be helpful for obtaining the IP addresses of various domains.

### Note:
- Make sure to install the `dnspython` library before running the script (`pip install dnspython`).
