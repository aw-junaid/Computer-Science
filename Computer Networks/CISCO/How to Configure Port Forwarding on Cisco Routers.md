Configuring port forwarding on a Cisco router involves a series of steps. Port forwarding allows you to direct traffic from a specific port to a device or server inside your network. Here's a basic guide on how to do it:

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

4. **Identify the Internal Device**:

   You need to know the IP address of the device to which you want to forward the ports.

5. **Configure the Port Forwarding**:

   The command format for port forwarding on a Cisco router is:

   ```
   ip nat inside source static <internal-ip> <protocol> <internal-port> interface <interface> <external-port>
   ```

   - `<internal-ip>`: IP address of the internal device.
   - `<protocol>`: The protocol you want to forward (e.g., tcp or udp).
   - `<internal-port>`: The port on the internal device.
   - `<interface>`: The interface through which the external traffic will come (e.g., FastEthernet0/0).
   - `<external-port>`: The port on the external interface.

   Example:

   ```
   ip nat inside source static 192.168.1.100 tcp 80 interface FastEthernet0/0 8080
   ```

   This example forwards incoming TCP traffic on port 8080 of the external interface to port 80 on the device with the IP address 192.168.1.100.

6. **Set Up Access Control List (ACL)**:

   You need to create an access list to permit the traffic you want to forward. 

   ```
   access-list <number> permit <protocol> <source> <source-wildcard>
   ```

   Example:

   ```
   access-list 101 permit tcp any any eq 8080
   ```

7. **Apply NAT to the Interface**:

   ```
   interface <interface>
   ip nat inside
   ```

   Example:

   ```
   interface FastEthernet0/0
   ip nat inside
   ```

8. **Apply ACL to the Interface**:

   ```
   interface <interface>
   ip access-group <number> in
   ```

   Example:

   ```
   interface FastEthernet0/0
   ip access-group 101 in
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

    You can now test the port forwarding by attempting to connect to the external IP address and port.

Please replace placeholders like `<internal-ip>`, `<protocol>`, etc., with your actual values. Keep in mind that exact commands and syntax might vary depending on the specific Cisco router model and IOS version you are using. Always consult the documentation for your specific router if you encounter any issues.
