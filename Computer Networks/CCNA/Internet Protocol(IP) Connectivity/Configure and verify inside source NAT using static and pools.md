Configuring and verifying inside source Network Address Translation (NAT) involves translating private internal IP addresses to a single or a pool of public IP addresses as traffic exits the network. This process is commonly used to conserve public IP addresses and enhance security. Below are general steps for configuring and verifying inside source NAT using static and pools on a Cisco router. Keep in mind that the specific commands may vary based on the router model and the operating system it runs.

### Inside Source NAT Configuration:

#### 1. **Configure Static NAT:**

Static NAT maps a specific private IP address to a specific public IP address. This is often used for one-to-one mapping.

```bash
Router(config)# ip nat inside source static <inside_local_ip> <outside_global_ip>
```

- `<inside_local_ip>`: Private IP address to be translated.
- `<outside_global_ip>`: Public IP address to which the private IP is mapped.

Example:

```bash
Router(config)# interface GigabitEthernet0/0
Router(config-if)# ip nat inside

Router(config)# interface GigabitEthernet0/1
Router(config-if)# ip nat outside

Router(config)# ip nat inside source static 192.168.1.10 203.0.113.10
```

#### 2. **Configure NAT Pool:**

NAT pools allow a range of private IP addresses to be mapped to a pool of public IP addresses.

```bash
Router(config)# ip nat pool <pool_name> <start_ip> <end_ip> netmask <subnet_mask>
Router(config)# access-list <access_list_number> permit <inside_local_network>
Router(config)# ip nat inside source list <access_list_number> pool <pool_name>
```

- `<pool_name>`: A name for the NAT pool.
- `<start_ip>` and `<end_ip>`: The range of public IP addresses in the pool.
- `<subnet_mask>`: The subnet mask for the public IP addresses.
- `<access_list_number>`: An access list specifying the inside local network to be translated.

Example:

```bash
Router(config)# ip nat pool NAT_POOL 203.0.113.20 203.0.113.30 netmask 255.255.255.0
Router(config)# access-list 1 permit 192.168.1.0 0.0.0.255
Router(config)# ip nat inside source list 1 pool NAT_POOL
```

### Verification Commands:

#### 1. **Verify NAT Translations:**

```bash
Router# show ip nat translations
```

This command displays the active NAT translations, including inside local and global IP addresses.

#### 2. **Verify NAT Statistics:**

```bash
Router# show ip nat statistics
```

This command shows statistics related to NAT translations, including the number of translations created.

### Notes:

- Ensure that NAT is enabled globally on the router.
- Verify that the interfaces are correctly identified as inside or outside.
- Use proper access lists to define the inside local network.
- Monitor the router for any issues related to NAT translations.

Always refer to the documentation specific to your router platform for accurate and up-to-date information. The provided examples assume a Cisco router using IOS-based commands.
