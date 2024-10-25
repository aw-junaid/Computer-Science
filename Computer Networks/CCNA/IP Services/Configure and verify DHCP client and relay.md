Configuring and verifying DHCP (Dynamic Host Configuration Protocol) client and relay involves setting up devices to obtain IP addresses dynamically from a DHCP server or forwarding DHCP requests from clients to a DHCP server. Below are general steps for configuring and verifying DHCP client and relay on a Cisco router. The specific commands may vary based on the router model and the operating system it runs.

### DHCP Client Configuration:

#### 1. **Enter Interface Configuration Mode:**

```bash
Router(config)# interface <interface_type><interface_number>
```

- `<interface_type>`: Type of the interface (e.g., Ethernet, GigabitEthernet).
- `<interface_number>`: Interface number.

#### 2. **Enable DHCP Client on the Interface:**

```bash
Router(config-if)# ip address dhcp
```

This command configures the interface to obtain an IP address dynamically from a DHCP server.

#### 3. **Verify DHCP Client Configuration:**

```bash
Router# show ip interface brief
```

This command displays the status of all interfaces, including the one configured for DHCP. Check if the interface has obtained an IP address.

### DHCP Relay Configuration:

#### 1. **Enter Global Configuration Mode:**

```bash
Router(config)# interface <interface_type><interface_number>
```

- `<interface_type>`: Type of the interface facing the DHCP clients.
- `<interface_number>`: Interface number.

#### 2. **Configure DHCP Relay:**

```bash
Router(config-if)# ip helper-address <dhcp_server_ip_address>
```

- `<dhcp_server_ip_address>`: IP address of the DHCP server.

This command configures the router to forward DHCP requests received on the specified interface to the specified DHCP server.

#### 3. **Verify DHCP Relay Configuration:**

```bash
Router# show ip helper-address
```

This command displays the configured DHCP relay helper addresses on each interface.

### Notes:

- Ensure that DHCP is properly configured and operational on the DHCP server.
- Verify that the DHCP client interface is connected to a network where a DHCP server is available.
- For DHCP relay, ensure that the router has routing enabled, and the DHCP server is reachable from the relay agent (router).
- The DHCP relay agent forwards DHCP discover messages from clients to the DHCP server, and the DHCP server responds with offer, request, and acknowledgment messages.
- Use the appropriate `debug` commands for troubleshooting DHCP issues.

Always refer to the documentation specific to your router platform for accurate and up-to-date information. The provided examples assume a Cisco router using IOS-based commands.
