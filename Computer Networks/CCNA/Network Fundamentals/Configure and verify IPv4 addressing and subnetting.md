Configuring and verifying IPv4 addressing and subnetting involves assigning IP addresses to devices and creating subnets to efficiently manage address space. Below are general steps for configuring and verifying IPv4 addressing and subnetting:

### Configure IPv4 Addressing:

1. **Understand the Network Requirements:**
   - Determine the network size, the number of subnets needed, and the number of hosts per subnet.

2. **Select an IP Addressing Scheme:**
   - Choose an appropriate IP addressing scheme based on the network requirements.

3. **Define Subnets:**
   - Divide the IP address space into subnets based on the number of required subnets and hosts per subnet.

4. **Assign IP Addresses:**
   - Assign IP addresses to devices based on the defined subnets. Be mindful of reserved addresses (network address, broadcast address, and reserved addresses within each subnet).

5. **Configure Subnet Masks:**
   - Assign subnet masks to devices to indicate the network and host portions of the IP address.

### Verify IPv4 Addressing:

1. **Check Device Configuration:**
   - Verify that each device is configured with the correct IP address, subnet mask, and default gateway.

   ```bash
   # Example on a Windows system
   ipconfig /all
   ```

   ```bash
   # Example on a Linux system
   ifconfig
   ```

2. **Verify Subnetting:**
   - Confirm that devices in the same subnet share the same network address and subnet mask.

3. **Check Connectivity:**
   - Use ping or other network utilities to verify connectivity between devices.

   ```bash
   # Example
   ping <destination_ip>
   ```

4. **Examine Routing Tables:**
   - Verify that routing tables on routers or layer 3 switches are correctly configured to route traffic between subnets.

   ```bash
   # Example on a Cisco router
   show ip route
   ```

5. **Use Subnet Calculators:**
   - Utilize IP subnet calculators to double-check subnetting calculations and address assignments.

### Troubleshoot and Adjust:

1. **Check for IP Address Conflicts:**
   - Ensure that no two devices have the same IP address within the same subnet.

2. **Verify Subnet Boundaries:**
   - Confirm that subnet boundaries align correctly, and there is no overlap between subnets.

3. **Review Subnet Masking:**
   - Check subnet mask consistency across devices in the same subnet.

4. **Check DHCP Configurations:**
   - If DHCP is used, verify the DHCP server's configuration to ensure correct IP address assignments.

### Example Configuration (Cisco Router - Command Line Interface):

Assuming a network with two subnets (192.168.1.0/24 and 192.168.2.0/24) connected by a router:

```bash
# Configure interfaces with IP addresses
Router(config)# interface GigabitEthernet0/0
Router(config-if)# ip address 192.168.1.1 255.255.255.0

Router(config)# interface GigabitEthernet0/1
Router(config-if)# ip address 192.168.2.1 255.255.255.0

# Verify configuration
Router# show ip interface brief
Router# show ip route
```

This is a basic example, and actual configurations will depend on the specific devices and network requirements. Always refer to the documentation of the networking devices in use.
