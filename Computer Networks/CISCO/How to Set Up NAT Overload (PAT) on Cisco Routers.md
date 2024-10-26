Setting up Network Address Translation (NAT) Overload, also known as Port Address Translation (PAT), on a Cisco router allows multiple internal devices to share a single public IP address to access the internet. Here's how you can configure PAT on a Cisco router:

1. **Access the Router's CLI**:

   Connect to your Cisco router using a console cable or through SSH/Telnet.

2. **Enter Privileged Exec Mode**:

   ```
   enable
   ```

   Provide the enable password if prompted.

3. **Enter Global Configuration Mode**:

   ```
   configure terminal
   ```

4. **Identify the Internal Network**:

   Determine the IP address range of your internal network. For example, if your internal network uses the subnet 192.168.1.0/24, you need to know this information.

5. **Configure NAT Overload (PAT)**:

   Use the following command to configure PAT:

   ```
   ip nat inside source list <access-list-number> interface <interface> overload
   ```

   - `<access-list-number>`: The access list number or name that specifies the internal network.
   - `<interface>`: The interface connected to the internet (usually your WAN interface).

   Example:

   ```
   ip nat inside source list 1 interface FastEthernet0/0 overload
   ```

6. **Create an Access Control List (ACL)**:

   You need to create an access list to define which internal IP addresses are allowed to use PAT.

   ```
   access-list <access-list-number> permit ip <internal-network> <wildcard-mask>
   ```

   Example:

   ```
   access-list 1 permit ip 192.168.1.0 0.0.0.255 any
   ```

   This example allows all IP addresses within the 192.168.1.0/24 subnet to use PAT.

7. **Apply NAT to the Interface**:

   Go to the interface that connects to your internal network (e.g., FastEthernet0/1) and enable NAT.

   ```
   interface <interface>
   ip nat inside
   ```

   Example:

   ```
   interface FastEthernet0/1
   ip nat inside
   ```

8. **Apply NAT to the Interface Connected to the Internet**:

   Go to the interface that connects to your internet service provider (ISP) and enable NAT.

   ```
   interface <interface>
   ip nat outside
   ```

   Example:

   ```
   interface FastEthernet0/0
   ip nat outside
   ```

9. **Save Configuration**:

   ```
   write memory
   ```

   or

   ```
   copy running-config startup-config
   ```

   This step saves your configuration so that it persists after a router reboot.

10. **Exit Configuration Mode and Verify**:

    ```
    exit
    ```

    Your router is now configured for NAT Overload (PAT). Multiple internal devices will share the same public IP address when accessing the internet, with each connection tracked using unique port numbers.

Remember to replace placeholders like `<access-list-number>`, `<interface>`, `<internal-network>`, etc., with your actual values. The exact commands and syntax might vary depending on the specific Cisco router model and IOS version you are using. Always consult the documentation for your specific router if you encounter any issues.
