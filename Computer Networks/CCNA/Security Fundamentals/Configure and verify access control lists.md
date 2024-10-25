Access Control Lists (ACLs) are used to control and filter traffic based on specified criteria. ACLs can be implemented on routers, switches, and firewalls to permit or deny traffic. Below are general steps for configuring and verifying standard and extended ACLs on a Cisco router. Keep in mind that the specific commands may vary based on the router model and the operating system it runs (e.g., Cisco IOS).

### Standard ACL Configuration:

#### 1. Enter Global Configuration Mode:

```bash
Router> enable
Router# configure terminal
```

#### 2. Create a Standard ACL:

```bash
Router(config)# access-list <ACL_number> {permit|deny} <source_address> [wildcard_mask]
```

- `<ACL_number>`: A numeric value (1-99 for standard ACLs).
- `permit` or `deny`: Specifies whether to allow or deny traffic.
- `<source_address>`: Source IP address or source network.
- `[wildcard_mask]`: Wildcard mask to match source addresses (optional for standard ACLs).

#### 3. Apply the ACL to an Interface:

```bash
Router(config)# interface <interface_type><interface_number>
Router(config-if)# ip access-group <ACL_number> {in|out}
```

- `<interface_type>`: Type of the interface (e.g., Ethernet, GigabitEthernet).
- `<interface_number>`: Interface number.
- `{in|out}`: Specifies whether the ACL is applied to incoming or outgoing traffic.

### Extended ACL Configuration:

#### 1. Enter Global Configuration Mode:

```bash
Router> enable
Router# configure terminal
```

#### 2. Create an Extended ACL:

```bash
Router(config)# access-list <ACL_number> {permit|deny} <protocol> <source_address> [source_wildcard_mask] [operator] [port] <destination_address> [destination_wildcard_mask] [operator] [port]
```

- `<ACL_number>`: A numeric value (100-199 for extended ACLs).
- `permit` or `deny`: Specifies whether to allow or deny traffic.
- `<protocol>`: IP protocol (e.g., tcp, udp, icmp).
- `<source_address>`: Source IP address or source network.
- `[source_wildcard_mask]`: Wildcard mask for source addresses (optional).
- `[operator] [port]`: Optional operator and port number for source port.
- `<destination_address>`: Destination IP address or destination network.
- `[destination_wildcard_mask]`: Wildcard mask for destination addresses (optional).
- `[operator] [port]`: Optional operator and port number for destination port.

#### 3. Apply the ACL to an Interface:

```bash
Router(config)# interface <interface_type><interface_number>
Router(config-if)# ip access-group <ACL_number> {in|out}
```

- `<interface_type>`: Type of the interface (e.g., Ethernet, GigabitEthernet).
- `<interface_number>`: Interface number.
- `{in|out}`: Specifies whether the ACL is applied to incoming or outgoing traffic.

### Verification:

#### 1. View ACLs:

```bash
Router# show access-lists
```

This command displays a list of configured ACLs, including their contents and applied interfaces.

#### 2. Check Interface Status:

```bash
Router# show interfaces <interface_type><interface_number>
```

Verify that the ACL is applied to the correct interface and in the correct direction (inbound or outbound).

### Notes:

- Standard ACLs filter traffic based on source IP addresses only.
- Extended ACLs provide more granular control by filtering based on source and destination IP addresses, protocols, and port numbers.
- ACLs are processed in the order they are configured. Be mindful of the order when creating ACL entries.
- Always thoroughly test ACLs in a lab environment before deploying them in a production network.

These commands are examples, and the specific syntax may vary based on the router model and IOS version. Always refer to the documentation specific to your router for accurate and up-to-date information.
