An extended Cisco command-line interface (CLI) cheat sheet that covers essential commands for network configuration and troubleshooting on Cisco devices. This includes basic configuration commands, as well as more advanced commands for managing routing, switching, VLANs, security, and diagnostics.

---

## **Basic Cisco CLI Modes**

### 1. **Accessing Different Modes**

```plaintext
# Enter privileged EXEC mode (requires password)
enable

# Enter global configuration mode
configure terminal

# Enter interface configuration mode
interface <interface-id>

# Exit a configuration mode
exit

# Return to privileged EXEC mode from any mode
end
```

**Explanation**: Cisco devices have different modes for different configuration tasks. `enable` takes you to privileged EXEC mode, `configure terminal` takes you to global configuration, and `interface` lets you configure specific interfaces.

---

## **Basic Configuration Commands**

### 2. **Setting Hostname**

```plaintext
# Set device hostname
hostname <name>
```

**Explanation**: Assigns a name to the device, which is useful for identifying devices in large networks.

### 3. **Configuring Passwords**

```plaintext
# Set the enable password
enable password <password>

# Set the enable secret (more secure than enable password)
enable secret <password>

# Set console line password
line console 0
 password <password>
 login

# Set VTY line password (for remote access)
line vty 0 4
 password <password>
 login
```

**Explanation**: `enable password` and `enable secret` protect privileged EXEC mode, while `line console` and `line vty` secure console and remote access.

### 4. **Saving and Viewing Configurations**

```plaintext
# Save current configuration to NVRAM
write memory

# Alternatively, use this command to save
copy running-config startup-config

# View the current configuration
show running-config

# View the saved configuration
show startup-config
```

**Explanation**: Use `write memory` or `copy` to save the running configuration to NVRAM. `show running-config` displays the active configuration, and `show startup-config` displays the saved configuration.

---

## **Interface Configuration**

### 5. **Configuring an Interface IP Address**

```plaintext
# Enter interface mode
interface <interface-id>

# Set IP address and subnet mask
ip address <ip-address> <subnet-mask>

# Enable the interface
no shutdown
```

**Explanation**: Assigns an IP address to an interface and enables it. Interfaces are disabled by default on many Cisco devices.

### 6. **Configuring a Loopback Interface**

```plaintext
# Create a loopback interface
interface loopback <number>

# Assign IP address
ip address <ip-address> <subnet-mask>
```

**Explanation**: Loopback interfaces are virtual interfaces used for testing, management, or as router IDs in OSPF/BGP.

### 7. **Configuring Interface Descriptions**

```plaintext
# Add a description to an interface
interface <interface-id>
 description <text>
```

**Explanation**: Helps with documentation by labeling interfaces with meaningful descriptions, like "Link to HQ" or "ISP Connection."

---

## **VLAN Configuration (Switching)**

### 8. **Creating and Assigning VLANs**

```plaintext
# Create a VLAN
vlan <vlan-id>
 name <vlan-name>

# Assign a VLAN to an interface
interface <interface-id>
 switchport mode access
 switchport access vlan <vlan-id>
```

**Explanation**: VLANs logically segment a network. The `switchport access vlan` command assigns a VLAN to a specific interface.

### 9. **Setting Up Trunk Ports**

```plaintext
# Configure trunk mode on an interface
interface <interface-id>
 switchport mode trunk

# Specify allowed VLANs on trunk port
switchport trunk allowed vlan <vlan-list>
```

**Explanation**: Trunk ports carry multiple VLANs between switches. The `allowed vlan` command limits which VLANs are permitted on the trunk.

---

## **Routing Configuration**

### 10. **Configuring Static Routes**

```plaintext
# Define a static route
ip route <destination-network> <subnet-mask> <next-hop-ip>
```

**Explanation**: Sets a manual route to a destination network using a specified next-hop IP.

### 11. **Configuring a Default Route**

```plaintext
# Define a default route
ip route 0.0.0.0 0.0.0.0 <next-hop-ip>
```

**Explanation**: A default route (0.0.0.0/0) forwards traffic to the specified next hop when no other routes match.

### 12. **Configuring Dynamic Routing (RIP)**

```plaintext
# Enable RIP routing protocol
router rip
 version 2
 network <network-address>
```

**Explanation**: Configures RIP routing protocol, defining networks to be advertised. RIP v2 supports subnet masks and authentication.

### 13. **Configuring OSPF**

```plaintext
# Enable OSPF and specify process ID
router ospf <process-id>

# Assign networks to OSPF areas
network <network-address> <wildcard-mask> area <area-id>
```

**Explanation**: OSPF is a link-state routing protocol. Networks must be assigned to areas (often area 0 as the backbone).

---

## **Security and Access Control**

### 14. **Access Control Lists (ACLs)**

```plaintext
# Create a standard ACL
access-list <acl-number> permit <source-ip> <wildcard-mask>

# Apply an ACL to an interface (inbound)
interface <interface-id>
 ip access-group <acl-number> in
```

**Explanation**: ACLs filter traffic. Standard ACLs filter based on source IP only, while extended ACLs can filter by source/destination IP, port, and protocol.

### 15. **Configuring SSH Access**

```plaintext
# Enable SSH on the device
ip domain-name <domain-name>
crypto key generate rsa
ip ssh version 2

# Set VTY lines for SSH access
line vty 0 4
 transport input ssh
 login local
```

**Explanation**: Configures SSH for secure remote access to the device. Set up a domain and generate RSA keys for encryption.

---

## **Diagnostics and Troubleshooting**

### 16. **Viewing Interface Status**

```plaintext
# Check the status of all interfaces
show ip interface brief

# Display detailed interface information
show interface <interface-id>
```

**Explanation**: `show ip interface brief` shows IP addresses and status (up/down) for interfaces, while `show interface` gives detailed info.

### 17. **Checking Routing Table**

```plaintext
# Display the routing table
show ip route
```

**Explanation**: Lists all known routes, including directly connected, static, and dynamically learned routes.

### 18. **Ping and Traceroute Commands**

```plaintext
# Ping an IP address
ping <ip-address>

# Trace the route to an IP address
traceroute <ip-address>
```

**Explanation**: `ping` tests reachability of a host, while `traceroute` shows the path packets take to reach a destination.

### 19. **Checking CPU and Memory Usage**

```plaintext
# Display CPU usage
show processes cpu

# Display memory usage
show processes memory
```

**Explanation**: These commands show CPU and memory usage, helpful for troubleshooting performance issues.

---

## **Backing Up and Restoring Configurations**

### 20. **Backing Up Configuration**

```plaintext
# Copy the running configuration to a TFTP server
copy running-config tftp

# Copy configuration to flash
copy running-config flash:<filename>
```

**Explanation**: These commands save a copy of the current configuration to a remote server or the device’s flash memory.

### 21. **Restoring Configuration**

```plaintext
# Copy a configuration file from TFTP to running configuration
copy tftp running-config

# Restore from flash
copy flash:<filename> running-config
```

**Explanation**: Loads a saved configuration from a TFTP server or flash memory, useful for restoring settings after a reset.

---

## **System Maintenance Commands**

### 22. **Reloading or Rebooting the Device**

```plaintext
# Reload the device
reload
```

**Explanation**: Reboots the device. Be cautious as this will interrupt network traffic.

### 23. **Configuring Time and Clock**

```plaintext
# Set the system clock
clock set <HH:MM:SS> <MONTH> <DAY> <YEAR>

# Set time zone
clock timezone <timezone> <offset>
```

**Explanation**: Manually sets the system time and time zone, which is important for accurate logging and scheduling.

---

## **Advanced Configuration and Management**

### 24. **Port Security (Switch Ports)**

```plaintext
# Enable port security
interface <interface-id>
 switchport port-security

# Set maximum MAC addresses allowed
switchport port-security maximum <number>

# Set action if a violation occurs
switchport port-security violation {protect | restrict | shutdown}
```

**Explanation**: Secures access ports by limiting the number of MAC addresses, providing additional layer 2 security.

### 25. **SNMP (Simple Network Management Protocol)**

```plaintext
# Enable SNMP and set community string
snmp-server community <community-string> <RO|RW>
```

**Explanation**: Configures SNMP, allowing network monitoring software to gather information from the device. `RO` provides read-only access; `RW` allows read-write access.

---

## **Logging and Monitoring**

### 26. **Viewing Logs**



```plaintext
# Display system logs
show logging
```

**Explanation**: Lists log messages that can be helpful in diagnosing system issues.

### 27. **Configuring Syslog**

```plaintext
# Set logging level
logging trap <level>

# Define syslog server
logging host <ip-address>
```

**Explanation**: Configures logging level and specifies a remote syslog server for log collection and analysis.

---

By using these commands, you’ll have a solid foundation to configure, secure, troubleshoot, and manage Cisco network devices effectively. Practice these commands to gain proficiency and confidence when working with Cisco’s CLI.
