Setting up IPv6 BGP (Border Gateway Protocol) on Cisco routers involves enabling BGP for IPv6 and configuring BGP parameters. Here's a step-by-step guide:

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

### Step 5: Configure BGP for IPv6

```shell
router bgp <AS-number>
```

Replace `<AS-number>` with the desired BGP Autonomous System number.

Example:

```shell
router bgp 65001
```

### Step 6: Specify IPv6 Address Family

```shell
address-family ipv6
```

This command enters IPv6 address family configuration mode.

### Step 7: Enable BGP for IPv6 Unicast

```shell
neighbor <neighbor-IPv6-address> remote-as <neighbor-AS-number>
```

Replace `<neighbor-IPv6-address>` with the IPv6 address of the BGP neighbor, and `<neighbor-AS-number>` with the AS number of the neighbor.

Example:

```shell
neighbor 2001:DB8::1 remote-as 65002
```

### Step 8: Configure IPv6 BGP Peering

```shell
neighbor <neighbor-IPv6-address> activate
```

This command activates the BGP neighbor for IPv6.

Example:

```shell
neighbor 2001:DB8::1 activate
```

### Step 9: Exit Address Family Configuration Mode

```shell
exit-address-family
```

### Step 10: Verify BGP Configuration

```shell
show bgp ipv6 unicast summary
show bgp ipv6 unicast neighbors
```

These commands will display a summary of BGP for IPv6 and information about the BGP neighbors.

### Step 11: Save Configuration

```shell
write memory
```

or

```shell
copy running-config startup-config
```

### Important Notes:

- Ensure that your router supports BGP for IPv6 and that it's running a compatible IOS version.

- BGP AS numbers should be consistent across routers in the same BGP network.

- Verify that BGP for IPv6 is enabled on all interfaces that participate in BGP routing.

- Always consult the documentation for your specific router model and IOS version if you encounter any issues. The exact commands and syntax might vary depending on the specific Cisco router model and IOS version you are using.
