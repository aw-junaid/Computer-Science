Certainly! Enabling Telnet access to a Cisco router involves configuring the router to accept Telnet connections and setting up authentication for security. Here's a step-by-step guide:

### Step 1: Access the Cisco Router

1. **Connect to the Router:**
   - Use a terminal emulation program like PuTTY or the built-in terminal on your computer to connect to the Cisco router's command-line interface (CLI) via a console cable or SSH.

### Step 2: Access Global Configuration Mode

2. **Enter Privileged Exec Mode:**
   ```bash
   Router> enable
   ```

3. **Access Global Configuration Mode:**
   ```bash
   Router# configure terminal
   ```

### Step 3: Configure Telnet

4. **Enable Telnet:**
   ```bash
   Router(config)# line vty 0 4
   Router(config-line)# transport input telnet
   ```

   This configuration allows Telnet access to the router on virtual terminals (vty) 0 through 4.

5. **Set Password for Telnet:**
   ```bash
   Router(config-line)# password YourTelnetPassword
   Router(config-line)# login
   ```

   Replace `YourTelnetPassword` with the desired password. This sets the password for Telnet access and enables login.

### Step 4: Specify Allowed IP Addresses (Optional but Recommended)

6. **Limit Access to Specific IP Addresses (Optional):**
   ```bash
   Router(config-line)# access-class 1 in
   ```

   Optionally, you can use an access list (`access-class`) to restrict Telnet access to specific IP addresses.

   ```bash
   Router(config)# access-list 1 permit 192.168.1.0 0.0.0.255
   ```

   This example allows Telnet access only from the 192.168.1.0/24 network. Modify the IP address and subnet mask according to your network.

### Step 5: Exit Configuration Mode and Save Configuration

7. **Exit Configuration Mode:**
   ```bash
   Router(config-line)# exit
   Router(config)# exit
   ```

### Step 6: Save Configuration

8. **Save Configuration:**
   ```bash
   Router# write memory
   ```

   This command saves the configuration changes to the router's startup configuration, ensuring they persist after a reboot.

### Step 7: Test Telnet Access

9. **Test Telnet Connection:**
   - Open a command prompt on your host computer.
   ```bash
   telnet RouterIPAddress
   ```

   Replace `RouterIPAddress` with the actual IP address of your Cisco router.

   - Enter the Telnet password when prompted.

### Notes:

- **Security Considerations:**
  - Telnet sends data, including passwords, in clear text. For more secure remote access, consider using SSH (Secure Shell) instead of Telnet.

- **Password Encryption:**
  - In a production environment, it's recommended to use encryption for passwords. The example above uses plain text passwords for simplicity. For encrypted passwords, consider using the `service password-encryption` command.

- **Backup Configuration:**
  - Before making changes, always take a backup of your router's configuration.

This guide provides a basic setup for Telnet access. In a production environment, security considerations are crucial, and additional measures should be taken to secure remote access.
