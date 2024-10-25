### DNS Record Resolver

This Python script resolves various DNS records for a given domain using the `dns.resolver` module.

### 1. Importing Required Modules:
```python
import dns.resolver
```
The script imports the `dns.resolver` module for querying DNS records.

### 2. Defining the Main Function:
```python
def main(domain):
    records = ['A', 'AAAA', 'NS', 'SOA', 'MX', 'TXT']
    for record in records:
        try:
            responses = dns.resolver.query(domain, record)
            print("\nRecord response ", record)
            print("-----------------------------------")
            for response in responses:
                print(response)
        except Exception as exception:
            print("Cannot resolve query for record", record)
            print("Error for obtaining record information:", exception)
```
The `main` function takes a domain name as input, and for each specified record type (`'A', 'AAAA', 'NS', 'SOA', 'MX', 'TXT'`), it queries the DNS resolver, prints the record type, and displays the responses.

### 3. Running the Script:
```python
if __name__ == '__main__':
    try:
        main('awjunaid.com')
    except KeyboardInterrupt:
        exit()
```
The script checks if it's being run as the main module, and if so, it calls the `main` function with a sample domain (`'awjunaid.com'`). It also handles a `KeyboardInterrupt` exception to gracefully exit the script.

### Usage:
- Run the script to obtain information about various DNS records for the specified domain (`'awjunaid.com'` in this example).

### Summary:
- The script uses the `dns.resolver` module to query DNS records for a given domain.
- It provides a comprehensive overview of different record types, including 'A', 'AAAA', 'NS', 'SOA', 'MX', and 'TXT'.

### Note:
- Make sure to install the `dnspython` library before running the script (`pip install dnspython`).
