Configuring IPv6 tunneling on Cisco routers allows IPv6 packets to be encapsulated and sent over an IPv4 network. One common method for IPv6 tunneling is through 6to4 tunnels. Here's a step-by-step guide:

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

### Step 4: Configure an IPv6 Tunnel Interface

```shell
interface Tunnel <tunnel-number>
```

Replace `<tunnel-number>` with a number to identify the tunnel interface.

Example:

```shell
interface Tunnel0
```

### Step 5: Enable IPv6 Unicast Routing

```shell
ipv6 unicast-routing
```

### Step 6: Specify Tunnel Source and Destination

```shell
tunnel source <source-interface>
tunnel mode ipv6ip
tunnel destination <destination-IPv4-address>
```

Replace `<source-interface>` with the interface facing the IPv4 network, and `<destination-IPv4-address>` with the IPv4 address of the remote endpoint.

Example:

```shell
tunnel source GigabitEthernet0/0
tunnel mode ipv6ip
tunnel destination 203.0.113.1
```

### Step 7: Configure IPv6 Addresses on Tunnel Interface

```shell
ipv6 address <local-IPv6-address/prefix-length>
ipv6 address <remote-IPv6-address/prefix-length> eui-64
```

Replace `<local-IPv6-address>` with the local IPv6 address and `<remote-IPv6-address>` with the remote IPv6 address.

Example:

```shell
ipv6 address 2001:DB8:0:1::1/64
ipv6 address 2001:DB8:0:1::2/64 eui-64
```

### Step 8: Enable the Tunnel Interface

```shell
no shutdown
```

### Step 9: Verify Tunnel Configuration

```shell
show interface tunnel <tunnel-number>
show ipv6 route
```

These commands will display information about the configured tunnel interface and IPv6 routing table.

### Step 10: Save Configuration

```shell
write memory
```

or

```shell
copy running-config startup-config
```

### Important Notes:

- Ensure that your router supports IPv6 and that it's running a compatible IOS version.

- Make sure the tunnel source and destination addresses are reachable.

- Verify that IPv6 routing is correctly configured on both ends of the tunnel.

- Always consult the documentation for your specific router model and IOS version if you encounter any issues. The exact commands and syntax might vary depending on the specific Cisco router model and IOS version you are using.
