Configuring and verifying Network Time Protocol (NTP) involves setting up a device to synchronize its clock with a time server. NTP can operate in client mode, where a device synchronizes its clock with a server, and in server mode, where a device provides time information to other devices. Below are general steps for configuring and verifying NTP in client and server modes on a Cisco router. The specific commands may vary based on the router model and the operating system it runs.

### NTP Configuration as a Client:

#### 1. **Enter Global Configuration Mode:**

```bash
Router(config)# ntp server <ntp_server_ip_address>
```

- `<ntp_server_ip_address>`: The IP address of the NTP server.

Example:

```bash
Router(config)# ntp server 192.168.1.1
```

This command configures the router to use 192.168.1.1 as the NTP server.

#### 2. **Configure NTP Source Interface (Optional):**

```bash
Router(config)# ntp source <interface_type><interface_number>
```

- `<interface_type>`: Type of the source interface (e.g., Loopback, Ethernet).
- `<interface_number>`: Interface number.

Example:

```bash
Router(config)# ntp source Loopback0
```

This command specifies Loopback0 as the source interface for NTP.

#### 3. **Verify NTP Configuration:**

```bash
Router# show ntp associations
```

This command displays the NTP associations to verify that the router is synchronized with the configured NTP server.

### NTP Configuration as a Server:

#### 1. **Enter Global Configuration Mode:**

```bash
Router(config)# ntp master <stratum>
```

- `<stratum>`: The stratum level of the local NTP server.

Example:

```bash
Router(config)# ntp master 1
```

This command configures the router as an NTP master with a stratum of 1.

#### 2. **Configure NTP Source Interface (Optional):**

```bash
Router(config)# ntp source <interface_type><interface_number>
```

- `<interface_type>`: Type of the source interface (e.g., Loopback, Ethernet).
- `<interface_number>`: Interface number.

Example:

```bash
Router(config)# ntp source Loopback0
```

This command specifies Loopback0 as the source interface for NTP.

#### 3. **Verify NTP Configuration:**

```bash
Router# show ntp status
```

This command displays the status of the local NTP server, including its stratum level and synchronization status.

### Notes:

- In client mode, the router synchronizes its clock with the specified NTP server.
- In server mode, the router acts as an NTP master, providing time information to other devices.
- It's advisable to configure at least three NTP servers for redundancy.
- Stratum values range from 1 to 15, where a lower stratum indicates a more accurate time source.

Always refer to the documentation specific to your router platform for accurate and up-to-date information. The provided examples assume a Cisco router using IOS-based commands.
