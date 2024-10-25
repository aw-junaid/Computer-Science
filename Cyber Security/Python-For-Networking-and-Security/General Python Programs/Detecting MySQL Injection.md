### Detecting MySQL Injection

This Python script detects MySQL injection vulnerabilities by sending SQL injection payloads to a target URL and checking for specific responses.

### 1. Importing Required Modules:

```python
import requests
```

The script imports the `requests` module for making HTTP requests.

### 2. Target URL and Payloads:

```python
domain = "http://testphp.vulnweb.com/listproducts.php?cat="
```

The target URL is set to "http://testphp.vulnweb.com/listproducts.php?cat=" for demonstration purposes. Change this to the actual target URL.

```python
mysql_attacks = []

# Open file and read the content into a list
with open('MSSQL.txt', 'r') as filehandle:
    for line in filehandle:
        attack = line.strip()
        mysql_attacks.append(attack)
```

The script reads a list of SQL injection payloads from a file named 'MSSQL.txt' and stores them in the `mysql_attacks` list.

### 3. Checking for MySQL Injection:

```python
for attack in mysql_attacks:
    print("Testing... " + domain + attack)
    response = requests.get(domain + attack)
    if "mysql" in response.text.lower():
        print("Injectable MySQL detected")
        print("Attack string: " + attack)
```

The script iterates through each SQL injection payload in the `mysql_attacks` list, sends a GET request to the target URL with the payload appended, and checks if the response contains the string "mysql" in a case-insensitive manner. If the string is detected, it prints that an injectable MySQL vulnerability is detected.

### Summary:

- The script checks for MySQL injection vulnerabilities by sending SQL injection payloads to a target URL and checking for specific responses.
- It reads the SQL injection payloads from a file ('MSSQL.txt') and sends GET requests to the target URL with each payload appended.
- If the response contains the string "mysql" (case-insensitive), it indicates an injectable MySQL vulnerability.

### Note:

- Modify the `domain` variable to the actual target URL.
- Adjust the file name and format if the list of SQL injection payloads is stored differently.
- Be cautious when testing on live systems and ensure you have appropriate authorization to perform security testing.
