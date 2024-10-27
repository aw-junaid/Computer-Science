A comprehensive Nmap cheat sheet that covers essential commands, usage, and explanations for different scanning techniques and options. Nmap (Network Mapper) is a powerful open-source tool used for network discovery and security auditing.

---

# **Nmap Cheat Sheet**

## **1. Installation**

### On Ubuntu/Debian:
```bash
sudo apt update
sudo apt install nmap
```

### On CentOS/Fedora:
```bash
sudo yum install nmap
```

### On macOS:
```bash
brew install nmap
```

### On Windows:
- Download the installer from the [official Nmap website](https://nmap.org/download.html).

---

## **2. Basic Scanning Commands**

### 2.1 Scan a Single Host
```bash
nmap <target-ip>
```
**Explanation**: Scans the specified IP address or hostname for open ports.

### 2.2 Scan a Range of IPs
```bash
nmap <starting-ip>-<ending-ip>
```
**Example**: `nmap 192.168.1.1-20`
**Explanation**: Scans all IPs from `192.168.1.1` to `192.168.1.20`.

### 2.3 Scan a Subnet
```bash
nmap <subnet>
```
**Example**: `nmap 192.168.1.0/24`
**Explanation**: Scans all IPs in the subnet `192.168.1.0` with a subnet mask of `/24`.

### 2.4 Scan with Service Detection
```bash
nmap -sV <target-ip>
```
**Explanation**: Identifies the version of services running on open ports.

### 2.5 Scan with OS Detection
```bash
nmap -O <target-ip>
```
**Explanation**: Attempts to determine the operating system of the target host.

---

## **3. Port Scanning Techniques**

### 3.1 TCP SYN Scan (Default Scan)
```bash
nmap -sS <target-ip>
```
**Explanation**: Performs a stealthy SYN scan. This is the default and most popular scan type.

### 3.2 TCP Connect Scan
```bash
nmap -sT <target-ip>
```
**Explanation**: Performs a full TCP connection scan. Useful when SYN scan is not possible due to firewalls.

### 3.3 UDP Scan
```bash
nmap -sU <target-ip>
```
**Explanation**: Scans for open UDP ports.

### 3.4 Xmas Tree Scan
```bash
nmap -sX <target-ip>
```
**Explanation**: Sends packets with the FIN, PSH, and URG flags set. Useful for stealthy scans.

### 3.5 FIN Scan
```bash
nmap -sF <target-ip>
```
**Explanation**: Sends TCP FIN packets to determine which ports are open.

### 3.6 Null Scan
```bash
nmap -sN <target-ip>
```
**Explanation**: Sends TCP packets with no flags set. Used for stealth scanning.

---

## **4. Output Options**

### 4.1 Output to File
```bash
nmap -oN output.txt <target-ip>
```
**Explanation**: Saves the scan results to a normal text file.

### 4.2 Output in XML Format
```bash
nmap -oX output.xml <target-ip>
```
**Explanation**: Saves the scan results in XML format.

### 4.3 Output in Grepable Format
```bash
nmap -oG output.gnmap <target-ip>
```
**Explanation**: Saves the scan results in a grepable format.

### 4.4 Verbose Output
```bash
nmap -v <target-ip>
```
**Explanation**: Provides more detailed output during the scan.

---

## **5. Advanced Scanning Techniques**

### 5.1 Scan Specific Ports
```bash
nmap -p <port1,port2> <target-ip>
```
**Example**: `nmap -p 22,80,443 192.168.1.1`
**Explanation**: Scans only the specified ports.

### 5.2 Scan All Ports
```bash
nmap -p- <target-ip>
```
**Explanation**: Scans all 65535 TCP ports.

### 5.3 Use a Custom Timing Template
```bash
nmap -T<0-5> <target-ip>
```
**Explanation**: Adjusts the speed of the scan. `0` is the slowest, `5` is the fastest.

### 5.4 Scan with Specific Network Interface
```bash
nmap -e <interface> <target-ip>
```
**Example**: `nmap -e eth0 192.168.1.1`
**Explanation**: Specifies which network interface to use for the scan.

### 5.5 Perform a Script Scan
```bash
nmap -sC <target-ip>
```
**Explanation**: Runs a set of default scripts against the target.

### 5.6 Run a Specific Nmap Script
```bash
nmap --script <script-name> <target-ip>
```
**Example**: `nmap --script http-enum 192.168.1.1`
**Explanation**: Runs a specific Nmap script against the target.

---

## **6. Firewall and Security Evasion Techniques**

### 6.1 Use Fragmentation
```bash
nmap -f <target-ip>
```
**Explanation**: Sends fragmented packets to evade detection by firewalls.

### 6.2 Use Decoy
```bash
nmap -D RND:10 <target-ip>
```
**Explanation**: Uses decoy scanning to mask the source of the scan.

### 6.3 Randomize Scan Order
```bash
nmap -r <target-ip>
```
**Explanation**: Scans ports in random order to evade detection.

---

## **7. Commonly Used Nmap Scripts**

### 7.1 Check for Vulnerabilities
```bash
nmap --script vuln <target-ip>
```
**Explanation**: Runs vulnerability detection scripts against the target.

### 7.2 DNS Enumeration
```bash
nmap --script dns-enum <target-ip>
```
**Explanation**: Enumerates DNS records for the target.

### 7.3 HTTP Enumeration
```bash
nmap --script http-enum <target-ip>
```
**Explanation**: Enumerates web applications and services running on the target.

---

## **8. Conclusion**

Nmap is an invaluable tool for network administrators and security professionals. This cheat sheet provides a concise overview of common Nmap commands and options for effective scanning and assessment of networks. 

For more advanced features and options, refer to the official [Nmap documentation](https://nmap.org/book/man.html) or run `man nmap` in your terminal.
