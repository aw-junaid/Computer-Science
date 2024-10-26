Configuring IPv6 routing on Cisco routers involves enabling IPv6 routing, configuring interfaces with IPv6 addresses, and potentially implementing IPv6 routing protocols. Here's a step-by-step guide:

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

### Step 5: Configure an IPv6 Address on an Interface

```shell
interface <interface-type> <interface-number>
ipv6 address <ipv6-address/prefix-length>
```

Replace `<interface-type> <interface-number>` with the specific interface, and `<ipv6-address/prefix-length>` with the IPv6 address and prefix length.

Example:

```shell
interface GigabitEthernet0/0
ipv6 address 2001:DB8::1/64
```

### Step 6: Enable the Interface

```shell
interface <interface-type> <interface-number>
no shutdown
```

Example:

```shell
interface GigabitEthernet0/0
no shutdown
```

### Step 7: Optionally, Configure a Routing Protocol

If you want to use a routing protocol like OSPFv3 or EIGRP for IPv6, you can do so now. The process is similar to configuring IPv4 routing protocols, but you'll use the IPv6 versions (e.g., `ipv6 router ospf`).

### Step 8: Verify IPv6 Routing Configuration

```shell
show ipv6 interface brief
show ipv6 route
```

These commands will display a summary of IPv6 interfaces and their status, as well as the current IPv6 routing table.

### Step 9: Save Configuration

```shell
write memory
```

or

```shell
copy running-config startup-config
```

### Important Notes:

- Ensure that your router supports IPv6 and that it's running a compatible IOS version.

- Make sure to assign unique IPv6 addresses to each interface.

- If you're using IPv6 with a specific ISP or network, you may need to configure additional settings provided by them.

- Always consult the documentation for your specific router model and IOS version if you encounter any issues. The exact commands and syntax might vary depending on the specific Cisco router model and IOS version you are using.
