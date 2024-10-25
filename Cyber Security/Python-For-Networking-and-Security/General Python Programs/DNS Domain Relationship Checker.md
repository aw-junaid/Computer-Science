### DNS Domain Relationship Checker

This Python script checks the relationship between two domains using the `dns` module.

### 1. Importing Required Modules:
```python
import argparse
import dns.name
```
The script imports the `argparse` module for command-line argument parsing and the `dns.name` module for working with DNS domain names.

### 2. Defining the Main Function:
```python
def main(domain1, domain2):
    domain1 = dns.name.from_text(domain1)
    domain2 = dns.name.from_text(domain2)
    print("domain1 is subdomain of domain2: ", domain1.is_subdomain(domain2)) 
    print("domain1 is superdomain of domain2: ", domain1.is_superdomain(domain2))
```
The `main` function takes two domain names as input arguments, converts them to `dns.name` objects, and then checks the relationship between them using the `is_subdomain` and `is_superdomain` methods. The results are printed.

### 3. Command-Line Argument Parsing:
```python
if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Check 2 domains with dns Python')
    parser.add_argument('--domain1', action="store", dest="domain1", default='python.org')
    parser.add_argument('--domain2', action="store", dest="domain2", default='docs.python.org')
    given_args = parser.parse_args() 
    domain1 = given_args.domain1
    domain2 = given_args.domain2
    main(domain1, domain2)
```
The script checks if it's being run as the main module and, if so, parses command-line arguments using `argparse`. It sets default values for the domain names and calls the `main` function with the provided or default values.

### Usage:
- Run the script with optional `--domain1` and `--domain2` arguments to check the relationship between two domains.

### Summary:
- The script uses the `dns.name` module to check whether one domain is a subdomain or superdomain of another.
- It provides a simple way to determine the relationship between two domains using DNS-related functionality.

### Note:
- Make sure to install the `dnspython` library before running the script (`pip install dnspython`).
