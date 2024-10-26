Dynamic NAT allows a pool of public IP addresses to be shared among multiple internal devices, giving them access to the internet. Here's a step-by-step guide on how to configure Dynamic NAT on a Cisco router:

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

5. **Identify the External Interface**:

   Identify the interface that connects to the external network (e.g., the internet). Note its name (e.g., FastEthernet0/0).

6. **Configure Dynamic NAT**:

   Use the following command to configure Dynamic NAT:

   ```
   ip nat inside source list <access-list-number> pool <pool-name> overload
   ```

   - `<access-list-number>`: The access list number or name that specifies the internal network.
   - `<pool-name>`: A name for the pool of public IP addresses.

   Example:

   ```
   ip nat inside source list 1 pool NAT_POOL overload
   ```

7. **Create a Pool of Public IP Addresses**:

   Define a range of public IP addresses to be used for NAT. 

   ```
   ip nat pool <pool-name> <start-ip> <end-ip> netmask <subnet-mask>
   ```

   - `<pool-name>`: The name of the pool (must match the one used in the previous command).
   - `<start-ip>`: The first IP address in the pool.
   - `<end-ip>`: The last IP address in the pool.
   - `<subnet-mask>`: The subnet mask for the pool.

   Example:

   ```
   ip nat pool NAT_POOL 203.0.113.1 203.0.113.10 netmask 255.255.255.0
   ```

8. **Create an Access Control List (ACL)**:

   You need to create an access list to define which internal IP addresses are allowed to use Dynamic NAT.

   ```
   access-list <access-list-number> permit ip <internal-network> <wildcard-mask>
   ```

   Example:

   ```
   access-list 1 permit ip 192.168.1.0 0.0.0.255 any
   ```

   This example allows all IP addresses within the 192.168.1.0/24 subnet to use Dynamic NAT.

9. **Apply NAT to the Interface**:

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

10. **Apply NAT to the Interface Connected to the Internet**:

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

11. **Save Configuration**:

    ```
    write memory
    ```

    or

    ```
    copy running-config startup-config
    ```

    This step saves your configuration so that it persists after a router reboot.

12. **Exit Configuration Mode and Verify**:

    ```
    exit
    ```

    Your router is now configured for Dynamic NAT. Multiple internal devices will be able to share the pool of public IP addresses when accessing the internet.

Remember to replace placeholders like `<access-list-number>`, `<pool-name>`, `<internal-network>`, etc., with your actual values. The exact commands and syntax might vary depending on the specific Cisco router model and IOS version you are using. Always consult the documentation for your specific router if you encounter any issues.
