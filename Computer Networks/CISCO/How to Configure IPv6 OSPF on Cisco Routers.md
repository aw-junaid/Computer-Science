Configuring IPv6 OSPF (Open Shortest Path First) on Cisco routers involves enabling OSPF for IPv6 and configuring OSPF parameters. Here's a step-by-step guide:

### Step 1: Access the Router's CLI

Connect to your Cisco router using a console cable or through SSH/Telnet.

### Step 2: Enter Privileged Exec Mode

```shell
enable
```

Provide the enable password if prompted.

### Step 3: Enter Global Configuration Mode

```shell
configure terminal
```

### Step 4: Enable IPv6 Unicast Routing

```shell
ipv6 unicast-routing
```

This command enables IPv6 routing on the router.

### Step 5: Configure OSPF for IPv6

```shell
router ospfv3 <process-id>
```

Replace `<process-id>` with a unique OSPF process ID.

Example:

```shell
router ospfv3 1
```

### Step 6: Specify OSPF Router ID (Optional)

```shell
router-id <router-id>
```

Replace `<router-id>` with the OSPF router ID. If not configured, OSPF will automatically select one.

Example:

```shell
router-id 1.1.1.1
```

### Step 7: Enable OSPF on Interfaces

```shell
interface <interface-type> <interface-number>
ipv6 ospf <process-id> area <area-id>
```

Replace `<interface-type> <interface-number>` with the specific interface, `<process-id>` with the OSPF process ID, and `<area-id>` with the OSPF area ID.

Example:

```shell
interface GigabitEthernet0/0
ipv6 ospf 1 area 0
```

### Step 8: Specify OSPF Router Priority (Optional)

```shell
ipv6 ospf priority <priority>
```

Replace `<priority>` with the OSPF router priority. This is relevant for routers with multiple interfaces in the same OSPF area. Higher priorities are preferred.

Example:

```shell
ipv6 ospf priority 100
```

### Step 9: Exit OSPF Configuration

```shell
exit
```

### Step 10: Verify OSPF Configuration

```shell
show ipv6 ospf
show ipv6 ospf interface
```

These commands will display the OSPF configuration and interface status.

### Step 11: Save Configuration

```shell
write memory
```

or

```shell
copy running-config startup-config
```

### Important Notes:

- Ensure that your router supports OSPFv3 for IPv6 and that it's running a compatible IOS version.

- OSPF areas and process IDs should be consistent across routers in the same OSPF network.

- Verify that OSPFv3 is enabled on all interfaces that participate in OSPF routing.

- Always consult the documentation for your specific router model and IOS version if you encounter any issues. The exact commands and syntax might vary depending on the specific Cisco router model and IOS version you are using.
