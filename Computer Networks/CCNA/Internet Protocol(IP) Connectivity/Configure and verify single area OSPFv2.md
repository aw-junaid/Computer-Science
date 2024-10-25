Configuring and verifying a single-area OSPF (Open Shortest Path First) version 2 (OSPFv2) involves setting up OSPF in a network with a single OSPF area. Below are the general steps for configuring and verifying OSPFv2 in a single area on a Cisco router. Keep in mind that specific commands may vary based on the router model and the operating system it runs.

### OSPFv2 Configuration:

#### 1. **Enter OSPF Configuration Mode:**

```bash
Router(config)# router ospf <process_id>
```

- `<process_id>`: A locally significant OSPF process ID.

#### 2. **Configure OSPF Router ID:**

```bash
Router(config-router)# router-id <router_id>
```

- `<router_id>`: A unique 32-bit identifier for the OSPF router.

#### 3. **Configure OSPF on Interfaces:**

```bash
Router(config-router)# network <network_address> <wildcard_mask> area <area_id>
```

- `<network_address>`: The IP address of the interface in OSPF.
- `<wildcard_mask>`: The wildcard mask for the network.
- `<area_id>`: The OSPF area to which the interface belongs.

Example:

```bash
Router(config-router)# network 192.168.1.0 0.0.0.255 area 0
```

This command advertises the network 192.168.1.0/24 into OSPF area 0.

#### 4. **Configure OSPF Authentication (Optional):**

```bash
Router(config-router)# area <area_id> authentication [message-digest]
```

- `<area_id>`: The OSPF area for which authentication is configured.
- `[message-digest]`: Optional keyword for MD5 authentication.

Example:

```bash
Router(config-router)# area 0 authentication
```

This command enables plain text authentication for OSPF area 0.

#### 5. **Exit OSPF Configuration Mode:**

```bash
Router(config-router)# exit
```

#### 6. **Verify OSPF Configuration:**

```bash
Router# show ip ospf
```

This command displays OSPF information, including router ID, neighbors, and OSPF process information.

### OSPFv2 Verification:

- **Show OSPF Neighbors:**

```bash
Router# show ip ospf neighbor
```

This command displays a list of OSPF neighbors along with their state and interface.

- **Show OSPF Database:**

```bash
Router# show ip ospf database
```

This command shows the OSPF link-state database, including router LSAs and network LSAs.

- **Verify OSPF Routing Table:**

```bash
Router# show ip route ospf
```

This command displays the OSPF routing table, showing OSPF-learned routes.

### Notes:

- OSPF requires a unique router ID for each router in the OSPF autonomous system. If not configured, OSPF will automatically choose the highest IP address of any of the router's active interfaces.
- The network command in OSPF is used to enable OSPF on interfaces within the specified network range.
- OSPF authentication helps ensure secure communication between OSPF routers. It is optional but recommended for security.

Always refer to the documentation specific to your router platform for accurate and up-to-date information. The provided examples assume a Cisco router using IOS-based commands.
