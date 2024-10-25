Configuring network devices for remote access using SSH (Secure Shell) involves enabling SSH on the device, configuring authentication methods, and setting up user accounts. Below are general steps for configuring SSH on a Cisco router. Keep in mind that the specific commands may vary based on the router model and the operating system it runs.

### SSH Configuration:

#### 1. **Enter Global Configuration Mode:**

```bash
Router# configure terminal
```

#### 2. **Generate RSA Key Pair:**

```bash
Router(config)# crypto key generate rsa modulus <modulus_size>
```

- `<modulus_size>`: The size of the RSA key modulus (e.g., 1024, 2048).

#### 3. **Configure SSH Version:**

```bash
Router(config)# ip ssh version 2
```

This command configures the router to use SSH version 2. SSH version 2 is more secure than version 1.

#### 4. **Configure Domain Name:**

```bash
Router(config)# ip domain-name <domain_name>
```

- `<domain_name>`: The domain name used for generating the default SSH key.

#### 5. **Enable SSH on VTY Lines:**

```bash
Router(config)# line vty 0 15
Router(config-line)# transport input ssh
```

This configures the VTY lines to allow SSH as the transport input method.

#### 6. **Configure Local User Account (Optional):**

```bash
Router(config)# username <username> privilege <privilege_level> secret <password>
```

- `<username>`: The username for the local user account.
- `<privilege_level>`: The privilege level (e.g., 15 for full access).
- `<password>`: The password for the local user account.

#### 7. **Configure SSH Timeout (Optional):**

```bash
Router(config-line)# exec-timeout <minutes> <seconds>
```

- `<minutes>`: Timeout duration in minutes.
- `<seconds>`: Timeout duration in seconds.

This command sets the timeout for an SSH session.

#### 8. **Exit Configuration Mode:**

```bash
Router(config-line)# exit
Router(config)# exit
```

#### 9. **Save Configuration:**

```bash
Router# write memory
```

This command saves the configuration to the startup-config file.

### Verification:

#### 1. **Verify SSH Configuration:**

```bash
Router# show ip ssh
```

This command displays information about the SSH configuration, including the SSH version, key exchange algorithms, and the status of SSH sessions.

#### 2. **Verify SSH Sessions:**

```bash
Router# show ssh
```

This command shows information about active SSH sessions, including the source IP address, username, and encryption algorithm.

### Notes:

- Ensure that the router's hostname is configured using the `hostname` command.
- The generated RSA key pair is used for encrypting SSH communications. The modulus size determines the strength of the key.
- The `ip domain-name` command is used for generating the default SSH key and is essential for successful SSH operation.
- Configuring a local user account is optional, but it provides an additional layer of authentication.
- Verify SSH connectivity using an SSH client such as PuTTY or the native SSH client on Unix-based systems.

Always refer to the documentation specific to your router platform for accurate and up-to-date information. The provided examples assume a Cisco router using IOS-based commands.
