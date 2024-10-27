An IPv4 cheat sheet that includes commands and explanations for configuring, troubleshooting, and managing IPv4 addresses across different operating systems. This guide will cover essential commands for both Unix/Linux and Windows environments.

---

# **IPv4 Cheat Sheet**

## **1. Understanding IPv4**

### 1.1 What is IPv4?

- **IPv4 (Internet Protocol Version 4)** is the fourth version of the Internet Protocol, widely used to identify devices on a network through an addressing system.
- An IPv4 address consists of 32 bits, usually represented in decimal as four octets (e.g., `192.168.1.1`).

### 1.2 IPv4 Address Structure

- **Classes**: IPv4 addresses are divided into classes (A, B, C, D, E) based on their leading bits.
- **Subnetting**: Divides a larger network into smaller, manageable sub-networks.
- **CIDR (Classless Inter-Domain Routing)**: Allows for more flexible allocation of IP addresses using a suffix (e.g., `/24`).

---

## **2. Basic Commands for IPv4 Management**

### 2.1 Unix/Linux Commands

- **Show Network Configuration**

  **Command:**
  ```bash
  ip addr show
  ```

  **Explanation**: Displays all network interfaces along with their IPv4 addresses.

- **Assign an IPv4 Address**

  **Command:**
  ```bash
  sudo ip addr add 192.168.1.10/24 dev eth0
  ```

  **Explanation**: Assigns the specified IPv4 address to the network interface `eth0`.

- **Remove an IPv4 Address**

  **Command:**
  ```bash
  sudo ip addr del 192.168.1.10/24 dev eth0
  ```

  **Explanation**: Removes the specified IPv4 address from the network interface `eth0`.

- **Show Routing Table**

  **Command:**
  ```bash
  ip route show
  ```

  **Explanation**: Displays the current routing table.

- **Ping an IPv4 Address**

  **Command:**
  ```bash
  ping 192.168.1.1
  ```

  **Explanation**: Sends ICMP echo requests to the specified IPv4 address to test connectivity.

### 2.2 Windows Commands

- **Show Network Configuration**

  **Command:**
  ```cmd
  ipconfig
  ```

  **Explanation**: Displays IP configuration details for all network interfaces.

- **Assign an IPv4 Address**

  **Command:**
  ```cmd
  netsh interface ip set address "Local Area Connection" static 192.168.1.10 255.255.255.0
  ```

  **Explanation**: Assigns a static IPv4 address to the specified network interface (replace "Local Area Connection" with the actual interface name).

- **Remove an IPv4 Address**

  **Command:**
  ```cmd
  netsh interface ip set address "Local Area Connection" dhcp
  ```

  **Explanation**: Configures the specified interface to obtain an IP address from a DHCP server.

- **Show Routing Table**

  **Command:**
  ```cmd
  route print
  ```

  **Explanation**: Displays the current routing table.

- **Ping an IPv4 Address**

  **Command:**
  ```cmd
  ping 192.168.1.1
  ```

  **Explanation**: Sends ICMP echo requests to the specified IPv4 address to test connectivity.

---

## **3. Subnetting Commands**

### 3.1 Subnetting Basics

- **Subnet Mask**: Defines the network portion of an IP address. Common masks include:
  - `/24` (255.255.255.0)
  - `/16` (255.255.0.0)
  - `/8` (255.0.0.0)

### 3.2 Calculate Subnets

- **Using `ipcalc` (Linux)**

  **Command:**
  ```bash
  ipcalc 192.168.1.0/24
  ```

  **Explanation**: Displays subnet information, including the network address, broadcast address, and valid host range.

- **Using Subnetting Calculators Online**

  **Command**: Use websites like [Subnet Calculator](https://www.subnet-calculator.com) to visually calculate subnets.

---

## **4. Troubleshooting IPv4**

### 4.1 Unix/Linux Commands

- **Check Connectivity**

  **Command:**
  ```bash
  traceroute 192.168.1.1
  ```

  **Explanation**: Displays the route packets take to reach the specified IPv4 address.

- **Display Active Connections**

  **Command:**
  ```bash
  netstat -tn
  ```

  **Explanation**: Displays active TCP connections with their IPv4 addresses.

- **Check Firewall Status**

  **Command:**
  ```bash
  sudo ufw status
  ```

  **Explanation**: Displays the status of the UFW firewall, including allowed and denied rules.

### 4.2 Windows Commands

- **Check Connectivity**

  **Command:**
  ```cmd
  tracert 192.168.1.1
  ```

  **Explanation**: Displays the route packets take to reach the specified IPv4 address.

- **Display Active Connections**

  **Command:**
  ```cmd
  netstat -an
  ```

  **Explanation**: Displays all active connections and their states.

- **Check Firewall Status**

  **Command:**
  ```cmd
  netsh advfirewall show allprofiles
  ```

  **Explanation**: Displays the status of the Windows Firewall for all profiles.

---

## **5. Miscellaneous Commands**

### 5.1 DHCP Commands

- **Release DHCP Lease (Linux)**

  **Command:**
  ```bash
  sudo dhclient -r
  ```

  **Explanation**: Releases the current DHCP lease for the interface.

- **Renew DHCP Lease (Linux)**

  **Command:**
  ```bash
  sudo dhclient
  ```

  **Explanation**: Requests a new DHCP lease for the interface.

- **Release DHCP Lease (Windows)**

  **Command:**
  ```cmd
  ipconfig /release
  ```

  **Explanation**: Releases the current DHCP lease for all interfaces.

- **Renew DHCP Lease (Windows)**

  **Command:**
  ```cmd
  ipconfig /renew
  ```

  **Explanation**: Requests a new DHCP lease for all interfaces.

---

## **6. Conclusion**

This IPv4 cheat sheet provides essential commands for managing and troubleshooting IPv4 addresses on both Unix/Linux and Windows systems. Understanding these commands will help you efficiently configure and maintain your network.
