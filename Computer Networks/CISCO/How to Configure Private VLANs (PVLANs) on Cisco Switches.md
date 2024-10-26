Configuring Private VLANs (PVLANs) on Cisco switches allows for segmentation of broadcast domains within a VLAN, providing additional isolation and security. Here's a step-by-step guide:

### Step 1: Access the Switch's CLI

Connect to your Cisco switch using a console cable or through SSH/Telnet.

### Step 2: Enter Privileged Exec Mode

```shell
enable
```

Provide the enable password if prompted.

### Step 3: Enter Global Configuration Mode

```shell
configure terminal
```

### Step 4: Create a Primary VLAN

```shell
vlan <vlan-id>
```

Replace `<vlan-id>` with the desired VLAN ID. This will be the primary VLAN.

Example:

```shell
vlan 100
```

### Step 5: Configure the Primary VLAN as Private

```shell
vlan <vlan-id>
private-vlan primary
```

Example:

```shell
vlan 100
private-vlan primary
```

### Step 6: Create Secondary VLANs

```shell
vlan <vlan-id>
private-vlan isolated
```

Create as many secondary VLANs as needed. These will be isolated VLANs.

Example:

```shell
vlan 101
private-vlan isolated
```

### Step 7: Associate Secondary VLANs with Primary VLAN

```shell
vlan <primary-vlan-id>
private-vlan association <isolated-vlan-id1> <isolated-vlan-id2> ...
```

Example:

```shell
vlan 100
private-vlan association 101
```

### Step 8: Configure Interface as Promiscuous (for connections to upstream router or server)

```shell
interface <interface-type> <interface-number>
switchport mode private-vlan promiscuous
switchport private-vlan mapping <primary-vlan-id> <secondary-vlan-list>
```

Replace `<interface-type> <interface-number>` with the specific interface, `<primary-vlan-id>` with the primary VLAN ID, and `<secondary-vlan-list>` with a space-separated list of isolated VLANs.

Example:

```shell
interface GigabitEthernet0/1
switchport mode private-vlan promiscuous
switchport private-vlan mapping 100 101
```

### Step 9: Configure Interface as Host (for regular devices)

```shell
interface <interface-type> <interface-number>
switchport mode private-vlan host
switchport private-vlan host-association <primary-vlan-id> <secondary-vlan-id>
```

Replace `<interface-type> <interface-number>` with the specific interface, `<primary-vlan-id>` with the primary VLAN ID, and `<secondary-vlan-id>` with the associated isolated VLAN.

Example:

```shell
interface GigabitEthernet0/2
switchport mode private-vlan host
switchport private-vlan host-association 100 101
```

### Step 10: Save Configuration

```shell
write memory
```

or

```shell
copy running-config startup-config
```

### Important Notes:

- Make sure the switch model and IOS version support Private VLANs.

- PVLANs require specific licensing on some switches.

- Private VLANs can be complex to configure and troubleshoot, so thoroughly test and plan before deploying them in production.

- The exact commands and syntax might vary depending on the specific Cisco switch model and IOS version you are using. Always consult the documentation for your specific switch if you encounter any issues.
