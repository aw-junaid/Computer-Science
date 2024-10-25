Layer 2 security features such as DHCP snooping, dynamic ARP inspection, and port security are essential for protecting the integrity and availability of a network. These features help prevent common Layer 2 attacks and unauthorized access. Below are general steps for configuring these security features on a Cisco switch. Keep in mind that the specific commands may vary based on the switch model and the operating system it runs (e.g., Cisco IOS).

### 1. DHCP Snooping:

#### a. Enable DHCP Snooping Globally:

```bash
Switch(config)# ip dhcp snooping
```

#### b. Enable DHCP Snooping on Specific VLANs:

```bash
Switch(config)# ip dhcp snooping vlan <vlan_number>
```

### 2. Dynamic ARP Inspection (DAI):

#### a. Enable Dynamic ARP Inspection Globally:

```bash
Switch(config)# arp inspection
```

#### b. Enable Dynamic ARP Inspection on Specific VLANs:

```bash
Switch(config)# arp inspection vlan <vlan_number>
```

### 3. Port Security:

#### a. Enable Port Security on an Interface:

```bash
Switch(config)# interface <interface_type><interface_number>
Switch(config-if)# switchport mode access
Switch(config-if)# switchport port-security
```

#### b. Set the Maximum Number of Allowed MAC Addresses:

```bash
Switch(config-if)# switchport port-security maximum <max_addresses>
```

#### c. Specify the Violation Action:

```bash
Switch(config-if)# switchport port-security violation {protect|restrict|shutdown}
```

- `protect`: Drops packets from unknown MAC addresses.
- `restrict`: Drops packets from unknown MAC addresses and generates a log message.
- `shutdown`: Shuts down the port if an unauthorized MAC address is detected.

#### d. Configure Aging for MAC Addresses:

```bash
Switch(config-if)# switchport port-security aging time <time_seconds>
Switch(config-if)# switchport port-security aging type inactivity
```

### Verification:

#### 1. Display DHCP Snooping Information:

```bash
Switch# show ip dhcp snooping
Switch# show ip dhcp snooping binding
```

#### 2. Display Dynamic ARP Inspection Information:

```bash
Switch# show arp inspection
Switch# show arp inspection vlan <vlan_number>
```

#### 3. Display Port Security Information:

```bash
Switch# show port-security
Switch# show port-security address
```

### Notes:

- DHCP snooping helps mitigate rogue DHCP server attacks by ensuring that only authorized DHCP servers can assign IP addresses.
- Dynamic ARP Inspection prevents ARP spoofing attacks by validating ARP packets and dropping those with invalid information.
- Port security restricts access to a switch port based on MAC address, limiting the number of MAC addresses allowed on a port and defining actions for security violations.

These commands are examples, and the specific syntax may vary based on the switch model and IOS version. Always refer to the documentation specific to your switch for accurate and up-to-date information. Additionally, it's important to carefully plan and test the implementation of these security features to avoid disrupting network operations.
