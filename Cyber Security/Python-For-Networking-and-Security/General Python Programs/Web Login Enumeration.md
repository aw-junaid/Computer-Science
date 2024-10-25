### Web Login Enumeration

This Python script checks a list of login resources on a target domain using the `requests` library.

### 1. Importing Required Modules:

```python
import requests
```

The script imports the `requests` module for making HTTP requests.

### 2. Reading Login Resources from File:

```python
logins = []

# Open file and read the content into a list
with open('Logins.txt', 'r') as filehandle:
    for line in filehandle:
        login = line.strip()
        logins.append(login)
```

The script reads a list of login resources from a file named 'Logins.txt' and stores them in the `logins` list.

### 3. Target Domain:

```python
domain = "http://testphp.vulnweb.com"
```

The target domain is set to "http://testphp.vulnweb.com" for demonstration purposes. Change this to the actual target domain.

### 4. Checking Login Resources:

```python
for login in logins:
    print("Checking... " + domain + login)
    response = requests.get(domain + login)
    if response.status_code == 200:
        print("Login resource detected: " + login)
```

The script iterates through each login resource in the `logins` list, sends a GET request to the target domain with the login resource appended, and checks if the HTTP response status code is 200. If a 200 status code is received, it prints that a login resource is detected.

### Summary:

- The script checks a list of login resources on a target domain using the `requests` library.
- It reads the login resources from a file ('Logins.txt') and sends GET requests to the target domain with each login resource appended.
- If a 200 status code is received, it indicates that a login resource is detected.

### Note:

- Ensure the 'requests' library is installed before running the script (`pip install requests`).
- Modify the `domain` variable to the actual target domain.
- Adjust the file name and format if the list of login resources is stored differently.
