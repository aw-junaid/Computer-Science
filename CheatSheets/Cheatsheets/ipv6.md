A comprehensive IPv6 cheat sheet that includes commands and explanations for configuring, troubleshooting, and managing IPv6 addresses across different operating systems. This guide covers essential commands for both Unix/Linux and Windows environments.

---

# **IPv6 Cheat Sheet**

## **1. Understanding IPv6**

### 1.1 What is IPv6?

- **IPv6 (Internet Protocol Version 6)** is the most recent version of the Internet Protocol designed to replace IPv4 due to the exhaustion of IPv4 addresses.
- An IPv6 address consists of 128 bits, typically represented as eight groups of four hexadecimal digits (e.g., `2001:0db8:85a3:0000:0000:8a2e:0370:7334`).

### 1.2 IPv6 Address Structure

- **Global Unicast Address**: Routable address similar to a public IPv4 address.
- **Link-Local Address**: Used for communication within a single network segment (starts with `fe80::`).
- **Multicast Address**: Used to send packets to multiple interfaces.

---

## **2. Basic Commands for IPv6 Management**

### 2.1 Unix/Linux Commands

- **Show Network Configuration**

  **Command:**
  ```bash
  ip -6 addr show
  ```

  **Explanation**: Displays all network interfaces along with their assigned IPv6 addresses.

- **Assign an IPv6 Address**

  **Command:**
  ```bash
  sudo ip -6 addr add 2001:db8::1/64 dev eth0
  ```

  **Explanation**: Assigns the specified IPv6 address to the network interface `eth0`.

- **Remove an IPv6 Address**

  **Command:**
  ```bash
  sudo ip -6 addr del 2001:db8::1/64 dev eth0
  ```

  **Explanation**: Removes the specified IPv6 address from the network interface `eth0`.

- **Show Routing Table**

  **Command:**
  ```bash
  ip -6 route show
  ```

  **Explanation**: Displays the current routing table for IPv6.

- **Ping an IPv6 Address**

  **Command:**
  ```bash
  ping6 2001:db8::1
  ```

  **Explanation**: Sends ICMPv6 echo requests to the specified IPv6 address to test connectivity.

### 2.2 Windows Commands

- **Show Network Configuration**

  **Command:**
  ```cmd
  ipconfig
  ```

  **Explanation**: Displays IP configuration details for all network interfaces, including IPv6 addresses.

- **Assign an IPv6 Address**

  **Command:**
  ```cmd
  netsh interface ipv6 set address "Local Area Connection" 2001:db8::1
  ```

  **Explanation**: Assigns the specified IPv6 address to the specified network interface (replace "Local Area Connection" with the actual interface name).

- **Remove an IPv6 Address**

  **Command:**
  ```cmd
  netsh interface ipv6 set address "Local Area Connection" dhcp
  ```

  **Explanation**: Configures the specified interface to obtain an IPv6 address from a DHCP server.

- **Show Routing Table**

  **Command:**
  ```cmd
  netstat -r
  ```

  **Explanation**: Displays the current routing table, including IPv6 routes.

- **Ping an IPv6 Address**

  **Command:**
  ```cmd
  ping 2001:db8::1
  ```

  **Explanation**: Sends ICMPv6 echo requests to the specified IPv6 address to test connectivity.

---

## **3. Subnetting Commands**

### 3.1 Subnetting Basics

- **IPv6 Subnetting**: IPv6 allows for hierarchical addressing and can be easily divided into subnets. The prefix length is usually expressed in bits (e.g., `/64`).

### 3.2 Calculate Subnets

- **Using `sipcalc` (Linux)**

  **Command:**
  ```bash
  sipcalc 2001:db8::/64
  ```

  **Explanation**: Displays subnet information, including the network address and valid host range.

- **Using Online IPv6 Subnet Calculators**

  **Command**: Use websites like [IPv6 Subnet Calculator](https://www.subnet-calculator.com/ipv6-subnet-calculator.php) for visual calculations.

---

## **4. Troubleshooting IPv6**

### 4.1 Unix/Linux Commands

- **Check Connectivity**

  **Command:**
  ```bash
  traceroute6 2001:db8::1
  ```

  **Explanation**: Displays the route packets take to reach the specified IPv6 address.

- **Display Active Connections**

  **Command:**
  ```bash
  ss -tuln
  ```

  **Explanation**: Displays active TCP and UDP connections, including their IPv6 addresses.

- **Check Firewall Status**

  **Command:**
  ```bash
  sudo ip6tables -L
  ```

  **Explanation**: Displays the status of the IPv6 firewall rules configured using `ip6tables`.

### 4.2 Windows Commands

- **Check Connectivity**

  **Command:**
  ```cmd
  tracert 2001:db8::1
  ```

  **Explanation**: Displays the route packets take to reach the specified IPv6 address.

- **Display Active Connections**

  **Command:**
  ```cmd
  netstat -an
  ```

  **Explanation**: Displays all active connections, including IPv6 connections.

- **Check Firewall Status**

  **Command:**
  ```cmd
  netsh advfirewall firewall show rule name=all
  ```

  **Explanation**: Displays the status of the Windows Firewall for all rules, including IPv6 rules.

---

## **5. Miscellaneous Commands**

### 5.1 DHCP Commands

- **Release DHCP Lease (Linux)**

  **Command:**
  ```bash
  sudo dhclient -r -6
  ```

  **Explanation**: Releases the current DHCP lease for the interface, specifically for IPv6.

- **Renew DHCP Lease (Linux)**

  **Command:**
  ```bash
  sudo dhclient -6
  ```

  **Explanation**: Requests a new DHCP lease for the interface for IPv6.

- **Release DHCP Lease (Windows)**

  **Command:**
  ```cmd
  netsh interface ipv6 set interface "Local Area Connection" dhcp
  ```

  **Explanation**: Configures the specified interface to obtain an IPv6 address from a DHCP server.

- **Renew DHCP Lease (Windows)**

  **Command:**
  ```cmd
  netsh interface ipv6 renew "Local Area Connection"
  ```

  **Explanation**: Requests a new DHCP lease for the specified interface for IPv6.

---

## **6. Conclusion**

This IPv6 cheat sheet provides essential commands for managing and troubleshooting IPv6 addresses on both Unix/Linux and Windows systems. Understanding these commands will help you efficiently configure and maintain your network using IPv6.
