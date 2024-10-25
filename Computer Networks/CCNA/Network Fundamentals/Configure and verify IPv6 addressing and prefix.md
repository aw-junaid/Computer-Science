Configuring and verifying IPv6 addressing involves assigning IPv6 addresses and prefixes to devices within a network. Here are the steps for configuring and verifying IPv6 addressing and prefixes:

### Configure IPv6 Addressing:

1. **Understand the Network Requirements:**
   - Determine the IPv6 addressing requirements, including the number of subnets, hosts, and the desired addressing scheme.

2. **Select an IPv6 Addressing Scheme:**
   - Choose an appropriate IPv6 addressing scheme, considering the network topology and addressing best practices.

3. **Assign IPv6 Addresses to Interfaces:**
   - Manually assign IPv6 addresses to the interfaces of devices or use Stateless Address Autoconfiguration (SLAAC) or DHCPv6 for automatic address assignment.

   ```bash
   # Example of manual assignment on a Cisco router interface
   Router(config)# interface GigabitEthernet0/0
   Router(config-if)# ipv6 address 2001:db8::1/64
   ```

4. **Configure IPv6 Prefixes:**
   - Assign IPv6 prefixes to subnets or VLANs. Prefixes determine the network portion of the IPv6 address.

   ```bash
   # Example of prefix assignment on a Cisco router interface
   Router(config)# interface GigabitEthernet0/0
   Router(config-if)# ipv6 address 2001:db8::1/64
   ```

### Verify IPv6 Addressing:

1. **Check Device Configuration:**
   - Verify that each device is configured with the correct IPv6 address and prefix.

   ```bash
   # Example on a Cisco router
   Router# show ipv6 interface brief
   ```

2. **Verify Subnetting:**
   - Confirm that devices in the same subnet share the same IPv6 prefix.

3. **Check IPv6 Connectivity:**
   - Use ping or other network utilities to verify IPv6 connectivity between devices.

   ```bash
   # Example
   ping ipv6 <destination_ipv6>
   ```

4. **Review Routing Tables:**
   - Verify that routing tables on routers or layer 3 switches are correctly configured to route IPv6 traffic between subnets.

   ```bash
   # Example on a Cisco router
   Router# show ipv6 route
   ```

5. **Use IPv6 Calculators:**
   - Utilize IPv6 subnet calculators to double-check subnetting calculations and address assignments.

### Troubleshoot and Adjust:

1. **Check for Address Conflicts:**
   - Ensure that no two devices have the same IPv6 address within the same subnet.

2. **Verify Prefix Lengths:**
   - Confirm that subnet prefixes are assigned correctly with appropriate prefix lengths.

3. **Examine Router Advertisement Configuration:**
   - If using SLAAC, check Router Advertisement configurations to ensure devices receive the correct IPv6 prefixes.

   ```bash
   # Example on a Cisco router
   Router# show ipv6 nd prefix
   ```

4. **Review DHCPv6 Configuration:**
   - If using DHCPv6, verify the DHCPv6 server's configuration to ensure correct IPv6 address assignments.

   ```bash
   # Example on a Cisco router
   Router# show ipv6 dhcp pool
   ```

### Example Configuration (Cisco Router - Command Line Interface):

Assuming a network with one subnet (2001:db8::/64) connected by a router:

```bash
# Configure interfaces with IPv6 addresses
Router(config)# interface GigabitEthernet0/0
Router(config-if)# ipv6 address 2001:db8::1/64

# Verify configuration
Router# show ipv6 interface brief
Router# show ipv6 route
```

This is a basic example, and actual configurations will depend on the specific devices and network requirements. Always refer to the documentation of the networking devices in use.
