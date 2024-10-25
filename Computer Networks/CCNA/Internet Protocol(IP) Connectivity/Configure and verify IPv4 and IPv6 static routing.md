Configuring and verifying IPv4 and IPv6 static routing involves manually specifying routes to reach specific networks. Below are the general steps for configuring and verifying static routes for both IPv4 and IPv6 on a Cisco router. Keep in mind that the specific commands may vary slightly based on the router model and the operating system it runs.

### IPv4 Static Routing Configuration:

#### 1. **Configure a Static IPv4 Route:**

```bash
Router(config)# ip route <destination_network> <subnet_mask> <next_hop_ip_address_or_outgoing_interface>
```

- `<destination_network>`: The destination network or host IP address.
- `<subnet_mask>`: The subnet mask indicating the network or host portion.
- `<next_hop_ip_address_or_outgoing_interface>`: The next-hop IP address or the outgoing interface.

Example:

```bash
Router(config)# ip route 192.168.2.0 255.255.255.0 10.0.0.1
```

#### 2. **Verify IPv4 Static Routes:**

```bash
Router# show ip route
```

This command displays the configured static routes in the routing table.

### IPv6 Static Routing Configuration:

#### 1. **Configure a Static IPv6 Route:**

```bash
Router(config)# ipv6 route <destination_network>/<prefix_length> <next_hop_ipv6_address_or_outgoing_interface>
```

- `<destination_network>/<prefix_length>`: The destination network or host IPv6 address with prefix length.
- `<next_hop_ipv6_address_or_outgoing_interface>`: The next-hop IPv6 address or the outgoing interface.

Example:

```bash
Router(config)# ipv6 route 2001:db8:1::/64 2001:db8:0:1::1
```

#### 2. **Verify IPv6 Static Routes:**

```bash
Router# show ipv6 route
```

This command displays the configured static routes in the IPv6 routing table.

### Common Verification Commands:

- **Show Specific Route:**
  ```bash
  Router# show ip route <destination_network>
  ```

  ```bash
  Router# show ipv6 route <destination_network>/<prefix_length>
  ```

- **Ping Test:**
  Verify reachability by pinging a destination using the configured static route.

### Notes:

- Ensure that the next-hop IP address or outgoing interface is reachable.
- Verify the correctness of the configured routes using the appropriate `show` commands.
- Consider the use of the `ping` command to verify end-to-end reachability.

Remember that these commands are general examples, and the syntax may vary based on the specific router platform and software version. Always refer to the documentation specific to your router for accurate and up-to-date information.
