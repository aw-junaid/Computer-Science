A comprehensive cheat sheet for computer networking commands, covering both Windows and Unix-like systems (Linux, macOS). This guide includes commands for network configuration, troubleshooting, and monitoring.

---

# **Computer Networks Extended Cheat Sheet**

## **1. Network Configuration Commands**

### 1.1 Unix/Linux Commands

- **Show Network Interfaces**

  **Command:**
  ```bash
  ip addr
  ```

  **Explanation**: Displays information about all network interfaces and their assigned IP addresses.

- **View Routing Table**

  **Command:**
  ```bash
  ip route
  ```

  **Explanation**: Displays the routing table of the system, showing how packets are directed.

- **Show Network Configuration**

  **Command:**
  ```bash
  ifconfig
  ```

  **Explanation**: Displays the configuration of all network interfaces (use `ip addr` in newer systems).

- **Configure an IP Address**

  **Command:**
  ```bash
  sudo ip addr add 192.168.1.100/24 dev eth0
  ```

  **Explanation**: Assigns the specified IP address to the network interface `eth0`.

- **Bring Interface Up/Down**

  **Commands:**
  ```bash
  sudo ip link set eth0 up
  sudo ip link set eth0 down
  ```

  **Explanation**: Activates (`up`) or deactivates (`down`) the specified network interface.

### 1.2 Windows Commands

- **Show Network Interfaces**

  **Command:**
  ```cmd
  ipconfig
  ```

  **Explanation**: Displays IP address configuration for all network interfaces.

- **View Routing Table**

  **Command:**
  ```cmd
  route print
  ```

  **Explanation**: Displays the routing table of the system.

- **Configure an IP Address**

  **Command:**
  ```cmd
  netsh interface ip set address "Local Area Connection" static 192.168.1.100 255.255.255.0
  ```

  **Explanation**: Assigns a static IP address to the specified network interface (replace "Local Area Connection" with the actual interface name).

- **Release/Renew DHCP Lease**

  **Commands:**
  ```cmd
  ipconfig /release
  ipconfig /renew
  ```

  **Explanation**: Releases the current DHCP lease and requests a new one.

---

## **2. Network Troubleshooting Commands**

### 2.1 Unix/Linux Commands

- **Ping a Host**

  **Command:**
  ```bash
  ping google.com
  ```

  **Explanation**: Sends ICMP echo requests to the specified host to check connectivity.

- **Traceroute**

  **Command:**
  ```bash
  traceroute google.com
  ```

  **Explanation**: Displays the route packets take to reach the specified host, showing each hop along the way.

- **Check Open Ports**

  **Command:**
  ```bash
  netstat -tuln
  ```

  **Explanation**: Lists all open listening ports and associated IP addresses.

- **Check Connection Status**

  **Command:**
  ```bash
  curl -I http://google.com
  ```

  **Explanation**: Sends a HEAD request to the specified URL to check connectivity and retrieve HTTP headers.

### 2.2 Windows Commands

- **Ping a Host**

  **Command:**
  ```cmd
  ping google.com
  ```

  **Explanation**: Sends ICMP echo requests to the specified host to check connectivity.

- **Traceroute**

  **Command:**
  ```cmd
  tracert google.com
  ```

  **Explanation**: Displays the route packets take to reach the specified host, showing each hop along the way.

- **Check Open Ports**

  **Command:**
  ```cmd
  netstat -an
  ```

  **Explanation**: Lists all active connections and listening ports.

- **Check Connection Status**

  **Command:**
  ```cmd
  curl -I http://google.com
  ```

  **Explanation**: Sends a HEAD request to the specified URL to check connectivity and retrieve HTTP headers.

---

## **3. DNS Commands**

### 3.1 Unix/Linux Commands

- **Query DNS Records**

  **Command:**
  ```bash
  dig google.com
  ```

  **Explanation**: Performs a DNS lookup and displays information about the domain.

- **Show DNS Cache**

  **Command:**
  ```bash
  sudo systemd-resolve --status
  ```

  **Explanation**: Displays the status of the DNS resolver, including cached entries.

### 3.2 Windows Commands

- **Query DNS Records**

  **Command:**
  ```cmd
  nslookup google.com
  ```

  **Explanation**: Performs a DNS lookup and displays information about the domain.

- **Show DNS Cache**

  **Command:**
  ```cmd
  ipconfig /displaydns
  ```

  **Explanation**: Displays the contents of the DNS resolver cache.

---

## **4. Network Security Commands**

### 4.1 Unix/Linux Commands

- **Check Firewall Status**

  **Command:**
  ```bash
  sudo ufw status
  ```

  **Explanation**: Displays the status of the UFW firewall, including rules and active status.

- **Add Firewall Rule**

  **Command:**
  ```bash
  sudo ufw allow 80/tcp
  ```

  **Explanation**: Adds a rule to allow incoming traffic on TCP port 80 (HTTP).

### 4.2 Windows Commands

- **Check Firewall Status**

  **Command:**
  ```cmd
  netsh advfirewall show allprofiles
  ```

  **Explanation**: Displays the status of the Windows Firewall for all profiles.

- **Add Firewall Rule**

  **Command:**
  ```cmd
  netsh advfirewall firewall add rule name="Allow HTTP" dir=in action=allow protocol=TCP localport=80
  ```

  **Explanation**: Adds a rule to allow incoming traffic on TCP port 80 (HTTP).

---

## **5. Miscellaneous Commands**

### 5.1 Unix/Linux Commands

- **Display Current Connections**

  **Command:**
  ```bash
  ss -tuln
  ```

  **Explanation**: Displays current TCP and UDP connections.

- **Network Interface Statistics**

  **Command:**
  ```bash
  ifstat
  ```

  **Explanation**: Displays network interface statistics such as bytes received and sent.

### 5.2 Windows Commands

- **Display Current Connections**

  **Command:**
  ```cmd
  netstat -a
  ```

  **Explanation**: Displays all active connections and listening ports.

- **Network Interface Statistics**

  **Command:**
  ```cmd
  netsh interface ipv4 show interfaces
  ```

  **Explanation**: Displays statistics for all IPv4 interfaces.

---

## **6. Conclusion**

This computer networks cheat sheet provides essential commands for network configuration, troubleshooting, DNS management, and security for both Unix/Linux and Windows systems. Familiarity with these commands can enhance your ability to manage and troubleshoot network issues effectively.
