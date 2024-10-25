Verifying IP parameters on different operating systems involves checking network-related configurations such as IP address, subnet mask, default gateway, DNS settings, and more. Here's a general guide for verifying IP parameters on Windows, macOS, and Linux:

### Windows:

1. **View IP Configuration:**
   - Open the Command Prompt:
     ```bash
     ipconfig
     ```
   - This command displays detailed information about network interfaces, including IP address, subnet mask, default gateway, and DNS servers.

2. **Check Network Settings via GUI:**
   - Navigate to "Settings" -> "Network & Internet."
   - Click on the network connection (Wi-Fi or Ethernet).
   - View the network details, including IP address, subnet mask, and gateway.

### macOS:

1. **View IP Configuration:**
   - Open the Terminal:
     ```bash
     ifconfig
     ```
   - Alternatively, for more detailed information:
     ```bash
     networksetup -listallhardwareports
     networksetup -getinfo <interface_name>
     ```
   - This displays information like IPv4 address, subnet mask, router (default gateway), and DNS servers.

2. **Check Network Settings via GUI:**
   - Navigate to "System Preferences" -> "Network."
   - Select the active network connection (Wi-Fi or Ethernet).
   - Click on "Advanced" for more details, including TCP/IP settings.

### Linux:

1. **View IP Configuration:**
   - Open the Terminal:
     ```bash
     ifconfig
     ```
   - Alternatively, use the following command:
     ```bash
     ip addr show
     ```
   - This displays IP address, subnet mask, and other network-related information.

2. **Check Network Settings via GUI (GNOME):**
   - Open "Settings" -> "Network."
   - Click on the active network connection.
   - View details, including IPv4 address, subnet mask, gateway, and DNS.

3. **Check Network Settings via GUI (KDE):**
   - Open "System Settings" -> "Network."
   - Click on the active network connection.
   - View details under the "IPv4 Address" tab.

### Common Network Troubleshooting:

- **Ping Test:**
  - Perform a ping test to verify connectivity to a remote host:
    ```bash
    ping <remote_host>
    ```

- **DNS Test:**
  - Use nslookup or dig to check DNS resolution:
    ```bash
    nslookup <domain_name>
    ```
    or
    ```bash
    dig <domain_name>
    ```

- **Gateway Test:**
  - Ping the default gateway to check connectivity:
    ```bash
    ping <gateway_ip>
    ```

- **Routing Table:**
  - Examine the routing table:
    ```bash
    route -n (Linux)
    route print (Windows)
    netstat -nr (macOS)
    ```

By performing these steps, you can verify and troubleshoot IP parameters on different operating systems, ensuring that network configurations are correct and devices can communicate effectively on the network.
