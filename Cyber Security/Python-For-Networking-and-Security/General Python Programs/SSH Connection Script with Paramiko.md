### SSH Connection Script with Paramiko

This Python script establishes an SSH connection using the `paramiko` library. The script connects to an SSH server with the specified hostname, username, and password.

### 1. Importing the Required Modules:

```python
import paramiko
import socket
```

The script imports the `paramiko` module for SSH operations and the `socket` module for handling socket-related exceptions.

### 2. SSH Connection Function:

```python
def establish_ssh_connection(host, username, password):
    try:
        # Create an SSH client instance
        ssh_client = paramiko.SSHClient()

        # Set up logging for debugging (optional)
        paramiko.common.logging.basicConfig(level=paramiko.common.DEBUG)

        # Load system host keys
        ssh_client.load_system_host_keys()

        # Automatically add server key to known_hosts file
        ssh_client.set_missing_host_key_policy(paramiko.AutoAddPolicy())

        # Connect to the SSH server
        response = ssh_client.connect(host, port=22, username=username, password=password)
        print('Connected to host on port 22:', response)

        # Get transport and security options
        transport = ssh_client.get_transport()
        security_options = transport.get_security_options()
        print('Key exchange algorithms:', security_options.kex)
        print('Ciphers:', security_options.ciphers)

    except paramiko.BadAuthenticationType as exception:
        print("BadAuthenticationException:", exception)
    except paramiko.SSHException as sshException:
        print("SSHException:", sshException)
    except socket.error as socketError:
        print("SocketError:", socketError)
    finally:
        print("Closing connection")
        # Close the SSH connection
        ssh_client.close()
        print("Connection closed")
```

The `establish_ssh_connection` function attempts to establish an SSH connection to the specified host using the provided username and password. It prints information about the connection and security options.

### 3. Main Function:

```python
if __name__ == '__main__':
    # Set parameters for SSH connection
    host = 'localhost'
    username = 'username'
    password = 'password'

    # Call the SSH connection function
    establish_ssh_connection(host, username, password)
```

The script calls the `establish_ssh_connection` function with the specified parameters for the SSH connection.

### Note:

- Ensure that the provided SSH server allows password-based authentication.
- Always follow security best practices when dealing with authentication credentials. Using keys instead of passwords is recommended for increased security.
