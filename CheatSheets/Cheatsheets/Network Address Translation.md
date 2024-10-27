An **Extended Network Address Translation (NAT) Cheat Sheet** that covers the key types of NAT, configuration commands, and detailed explanations in table format.

---

# **Network Address Translation (NAT) Cheat Sheet**

## **1. NAT Overview Table**

| **NAT Type**              | **Description**                                                                                           | **Use Case**                                     |
|---------------------------|-----------------------------------------------------------------------------------------------------------|--------------------------------------------------|
| **Static NAT**            | Maps a single private IP address to a single public IP address.                                          | When one-to-one mapping is needed (e.g., servers)|
| **Dynamic NAT**           | Maps a pool of private IPs to a pool of public IPs on a first-come, first-served basis.                   | Limited public IP pool for multiple devices.     |
| **PAT (Port Address Translation)** | Maps multiple private IPs to a single public IP by using different port numbers (also called NAT Overload). | Home/office networks with limited public IPs.    |
| **NAT64**                 | Translates IPv6 addresses to IPv4, allowing IPv6-only devices to communicate with IPv4 networks.         | Transitioning to IPv6 networks.                  |

---

## **2. NAT Configuration Commands Table (Cisco IOS)**

| **Command**                      | **Explanation**                                                                                     |
|----------------------------------|-----------------------------------------------------------------------------------------------------|
| `ip nat inside`                  | Marks an interface as inside (private) for NAT translation.                                         |
| `ip nat outside`                 | Marks an interface as outside (public) for NAT translation.                                         |
| `ip nat pool [name] [start-ip] [end-ip] netmask [mask]` | Creates a pool of public IP addresses for Dynamic NAT.                |
| `ip nat inside source static [inside-local-ip] [inside-global-ip]` | Configures Static NAT mapping.                       |
| `ip nat inside source list [access-list] pool [pool-name]` | Applies Dynamic NAT using an ACL and a NAT pool.                  |
| `ip nat inside source list [access-list] interface [outside-interface] overload` | Configures PAT using a single IP.    |
| `clear ip nat translation *`     | Clears all NAT translations in the NAT table.                                                      |
| `show ip nat translations`       | Displays the NAT translation table to show active mappings.                                        |
| `show ip nat statistics`         | Shows NAT statistics, including number of active translations and NAT configuration status.         |

---

## **3. Static NAT Configuration**

| **Command** | **Explanation** |
|-------------|-----------------|
| `ip nat inside source static [inside-local-ip] [inside-global-ip]` | Maps a specific internal IP address to a specific public IP address. Useful for one-to-one NAT, often for servers. |

### **Example Configuration**
```bash
interface GigabitEthernet0/1
 ip address 192.168.1.1 255.255.255.0
 ip nat inside

interface GigabitEthernet0/2
 ip address 203.0.113.5 255.255.255.0
 ip nat outside

ip nat inside source static 192.168.1.10 203.0.113.10
```

---

## **4. Dynamic NAT Configuration**

| **Command**                                                         | **Explanation**                                                                                          |
|---------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------|
| `ip nat pool [name] [start-ip] [end-ip] netmask [mask]`             | Defines a pool of public IP addresses available for dynamic NAT.                                         |
| `access-list [number] permit [private-subnet]`                      | Creates an ACL to define the range of IPs that can use NAT.                                              |
| `ip nat inside source list [access-list] pool [pool-name]`          | Configures NAT to translate IPs that match the ACL using the specified NAT pool.                         |

### **Example Configuration**
```bash
access-list 1 permit 192.168.1.0 0.0.0.255

ip nat pool PUBLIC_POOL 203.0.113.20 203.0.113.30 netmask 255.255.255.0
ip nat inside source list 1 pool PUBLIC_POOL

interface GigabitEthernet0/1
 ip address 192.168.1.1 255.255.255.0
 ip nat inside

interface GigabitEthernet0/2
 ip address 203.0.113.5 255.255.255.0
 ip nat outside
```

---

## **5. Port Address Translation (PAT) Configuration**

| **Command**                                                         | **Explanation**                                                                                            |
|---------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------|
| `access-list [number] permit [private-subnet]`                      | Defines which internal IPs can be translated.                                                              |
| `ip nat inside source list [access-list] interface [outside-interface] overload` | Configures PAT (NAT Overload) using a single public IP.     |

### **Example Configuration**
```bash
access-list 1 permit 192.168.1.0 0.0.0.255

interface GigabitEthernet0/1
 ip address 192.168.1.1 255.255.255.0
 ip nat inside

interface GigabitEthernet0/2
 ip address 203.0.113.5 255.255.255.0
 ip nat outside

ip nat inside source list 1 interface GigabitEthernet0/2 overload
```

---

## **6. NAT64 Configuration (IPv6 to IPv4 Translation)**

| **Command**                            | **Explanation**                                                                                           |
|----------------------------------------|-----------------------------------------------------------------------------------------------------------|
| `ipv6 nat64 enable`                    | Enables NAT64 functionality on the router.                                                                |
| `ipv6 nat64 prefix stateful [prefix]`  | Defines the NAT64 prefix to use for IPv4-to-IPv6 translation.                                             |
| `ipv6 nat64 v4-mapped [IPv4-address] [IPv6-address]` | Maps a specific IPv4 address to an IPv6 address for stateful NAT64.  |

### **Example Configuration**
```bash
interface GigabitEthernet0/1
 ipv6 address 2001:db8:1::1/64
 ipv6 nat64 enable

interface GigabitEthernet0/2
 ip address 203.0.113.5 255.255.255.0
 ipv6 nat64 v4-mapped 203.0.113.10 2001:db8:1::10
```

---

## **7. NAT Verification Commands**

| **Command**                      | **Explanation**                                                        |
|----------------------------------|------------------------------------------------------------------------|
| `show ip nat translations`       | Shows active NAT translations for verification of NAT mapping.         |
| `show ip nat statistics`         | Displays statistics including NAT hit counts and number of active translations. |
| `clear ip nat translation *`     | Clears all active NAT translations.                                    |
| `debug ip nat`                   | Provides real-time debugging information for NAT operations.           |

---

## **Types of NAT Comparison Table**

| **Feature**               | **Static NAT**                        | **Dynamic NAT**                      | **PAT (NAT Overload)**              | **NAT64**                                |
|---------------------------|---------------------------------------|--------------------------------------|-------------------------------------|------------------------------------------|
| **Purpose**               | One-to-one mapping                   | Many-to-many mapping                | Many-to-one mapping                 | IPv6 to IPv4 translation                |
| **Address Pool**          | Single public IP                     | Pool of public IPs                  | Single public IP (using ports)      | Prefix-based for IPv4-to-IPv6 mapping   |
| **Suitable For**          | Hosting services, servers            | Limited public IP resources         | Home or office networks             | Enabling IPv6-only devices to reach IPv4 |
| **Configuration Complexity** | Low                              | Moderate                            | Low                                 | Moderate                                |
| **Limitations**           | Requires multiple IPs                | Limited by available public IPs     | Limited to port numbers             | Limited to dual-stack (IPv4/IPv6) environments |
| **Scalability**           | Limited                              | Moderate                            | High                                | High                                    |

---

This comprehensive NAT cheat sheet provides configurations and explanations for common NAT types and commands, tailored for network environments of varying scales and complexities.
