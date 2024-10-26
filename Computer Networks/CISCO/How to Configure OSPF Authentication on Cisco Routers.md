Configuring OSPF (Open Shortest Path First) authentication on Cisco routers helps secure the OSPF routing updates exchanged between neighbors. Here's a step-by-step guide:

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

### Step 4: Enable OSPF and Configure OSPF Area

```shell
router ospf <process-id>
network <network-address> <wildcard-mask> area <area-id>
```

Replace `<process-id>` with a unique OSPF process ID, `<network-address>` with the network address you want to advertise, `<wildcard-mask>` with the corresponding wildcard mask, and `<area-id>` with the OSPF area ID.

Example:

```shell
router ospf 1
network 192.168.1.0 0.0.0.255 area 0
```

### Step 5: Enable OSPF Authentication

```shell
interface <interface-type> <interface-number>
ip ospf authentication message-digest
ip ospf message-digest-key <key-id> md5 <key>
```

Replace `<interface-type> <interface-number>` with the specific interface, `<key-id>` with the ID of the authentication key, and `<key>` with the actual authentication key.

Example:

```shell
interface GigabitEthernet0/0
ip ospf authentication message-digest
ip ospf message-digest-key 1 md5 MySecretKey
```

### Step 6: Assign OSPF Authentication to OSPF Process

```shell
router ospf <process-id>
area <area-id> authentication message-digest
```

Replace `<process-id>` with your OSPF process ID and `<area-id>` with the OSPF area ID.

Example:

```shell
router ospf 1
area 0 authentication message-digest
```

### Step 7: Save Configuration

```shell
write memory
```

or

```shell
copy running-config startup-config
```

### Important Notes:

- Ensure that OSPF authentication settings are consistent on all routers within the OSPF area.

- OSPF router IDs, network types, and subnet masks must match for OSPF neighbors to form.

- Always consult the documentation for your specific router model and IOS version if you encounter any issues. The exact commands and syntax might vary depending on the specific Cisco router model and IOS version you are using.
