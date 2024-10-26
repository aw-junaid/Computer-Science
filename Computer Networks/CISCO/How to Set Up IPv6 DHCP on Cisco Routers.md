Setting up IPv6 DHCP (Dynamic Host Configuration Protocol) on Cisco routers allows you to automatically assign IPv6 addresses and other network configuration parameters to clients. Here's a step-by-step guide:

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

### Step 4: Configure IPv6 DHCP Pool

```shell
ipv6 dhcp pool <pool-name>
```

Replace `<pool-name>` with a name for your DHCP pool.

Example:

```shell
ipv6 dhcp pool MY_POOL
```

### Step 5: Define Address Range

```shell
address prefix <ipv6-prefix> <prefix-length>
```

Replace `<ipv6-prefix>` with the starting IPv6 address and `<prefix-length>` with the prefix length.

Example:

```shell
address prefix 2001:DB8:0:1::/64
```

### Step 6: Set DNS Server (Optional)

```shell
dns-server <ipv6-dns-server>
```

Replace `<ipv6-dns-server>` with the IPv6 address of your DNS server.

Example:

```shell
dns-server 2001:DB8::1
```

### Step 7: Set Domain Name (Optional)

```shell
domain-name <domain-name>
```

Replace `<domain-name>` with the desired domain name.

Example:

```shell
domain-name example.com
```

### Step 8: Assign Other Parameters (Optional)

You can configure additional parameters such as default router, NTP server, and more if needed.

### Step 9: Exit DHCP Pool Configuration

```shell
exit
```

### Step 10: Enable DHCP on an Interface

```shell
interface <interface-type> <interface-number>
ipv6 nd other-config-flag
ipv6 dhcp server <pool-name>
```

Replace `<interface-type> <interface-number>` with the specific interface and `<pool-name>` with the name of the DHCP pool you created.

Example:

```shell
interface GigabitEthernet0/0
ipv6 nd other-config-flag
ipv6 dhcp server MY_POOL
```

### Step 11: Save Configuration

```shell
write memory
```

or

```shell
copy running-config startup-config
```

### Important Notes:

- Ensure that your router supports IPv6 and that it's running a compatible IOS version.

- Make sure to assign a unique IPv6 prefix to each DHCP pool.

- Verify that your network devices are configured to request IPv6 addresses using DHCP.

- Always consult the documentation for your specific router model and IOS version if you encounter any issues. The exact commands and syntax might vary depending on the specific Cisco router model and IOS version you are using.
