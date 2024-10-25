### SSH Command Execution Script with Paramiko

This Python script uses the `paramiko` library to execute a command on a remote SSH server. The script prompts the user for the target hostname, port, username, password, and command to be executed on the remote server.

### 1. Importing the Required Modules:

```python
#!/usr/bin/env python3

import paramiko
import getpass
```

### 2. SSH Command Execution Function:

```python
def run_ssh_command(hostname, user, passwd, command):
    try:
        # Create a transport object
        transport = paramiko.Transport((hostname, 22))

        # Start the SSH connection
        transport.start_client()

        # Authenticate with a username and password
        transport.auth_password(username=user, password=passwd)

        # Check if the authentication was successful
        if transport.is_authenticated():
            print("Connected to", hostname)

            # Open an SSH channel
            channel = transport.open_session()

            # Execute the specified command on the remote server
            channel.exec_command(command)

            # Receive the response from the command
            response = channel.recv(1024)

            # Print the command and its response
            print(f'Command: {command} (User: {user}) --> {response.decode()}')

    except paramiko.AuthenticationException as auth_exception:
        print("Authentication failed:", auth_exception)
    except paramiko.SSHException as ssh_exception:
        print("SSHException:", ssh_exception)
    except Exception as e:
        print("An error occurred:", e)
    finally:
        # Close the SSH connection
        transport.close()
```

### 3. Main Function:

```python
if __name__ == '__main__':
    # Get user input for SSH connection details
    hostname = input("Enter the target hostname: ")
    username = input("Enter username: ")
    password = getpass.getpass(prompt="Enter password: ")
    command = input("Enter command: ")

    # Run the SSH command execution function
    run_ssh_command(hostname, username, password, command)
```

### Note:

- The script prompts the user for input, including sensitive information like the password. Ensure to handle such information securely.
- This script is for educational purposes and may need adjustments for production use. Consider using key-based authentication for increased security in a production environment.
