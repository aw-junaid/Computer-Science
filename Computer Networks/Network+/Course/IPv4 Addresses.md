### **IPv4 Addresses**

**IPv4 (Internet Protocol version 4)** is the fourth version of the Internet Protocol, and it is the most widely used protocol for addressing and routing traffic on the internet and within local networks. IPv4 uses a 32-bit address space, which allows for a theoretical maximum of **4,294,967,296** unique addresses.

An IPv4 address is typically written in **dotted decimal notation**, which consists of four decimal numbers separated by dots, each representing an 8-bit byte (also called an **octet**). Each decimal number is in the range of 0 to 255, and the full address has a total of 32 bits.

#### **Structure of an IPv4 Address**

An IPv4 address is composed of **4 octets**, and each octet represents 8 bits, or 1 byte, of the address. The 32 bits are divided into two main parts:
1. **Network Portion**: Identifies the network to which the host belongs.
2. **Host Portion**: Identifies a specific device (host) within that network.

The format is as follows:
```
A.B.C.D
```
Where:
- **A** is the first octet (8 bits).
- **B** is the second octet (8 bits).
- **C** is the third octet (8 bits).
- **D** is the fourth octet (8 bits).

Each of these octets is represented in **decimal** form, and each octet is **between 0 and 255**.

#### **Example:**
An example of an IPv4 address:
```
192.168.1.1
```
This represents:
- **192** (8 bits)
- **168** (8 bits)
- **1** (8 bits)
- **1** (8 bits)

To better understand the division, let's convert this address into binary:
```
11000000.10101000.00000001.00000001
```
The binary format for the address is divided into 4 groups of 8 bits.

#### **IPv4 Address Classes**

IPv4 addresses are categorized into five classes, based on their intended use and the range of addresses they cover:

1. **Class A (1.0.0.0 to 127.255.255.255)**:
   - First octet: 1-127.
   - Provides a large number of host addresses (up to 16 million per network).
   - Used for very large networks (e.g., multinational organizations).

2. **Class B (128.0.0.0 to 191.255.255.255)**:
   - First octet: 128-191.
   - Provides a moderate number of host addresses (up to 65,000 per network).
   - Used for medium-sized networks (e.g., universities, large enterprises).

3. **Class C (192.0.0.0 to 223.255.255.255)**:
   - First octet: 192-223.
   - Provides a smaller number of host addresses (up to 254 per network).
   - Used for small networks (e.g., small businesses, local networks).

4. **Class D (224.0.0.0 to 239.255.255.255)**:
   - Used for **multicasting**. These addresses are reserved for group communications rather than individual hosts.

5. **Class E (240.0.0.0 to 255.255.255.255)**:
   - Reserved for **experimental** purposes and not used for public addressing.

---

### **Private vs. Public IPv4 Addresses**

- **Public IPv4 Addresses**: These addresses are assigned by the **Internet Assigned Numbers Authority (IANA)** and can be routed across the internet.
  
- **Private IPv4 Addresses**: These are reserved for use within private networks and are not routable on the internet. The ranges for private IPv4 addresses are:

    - **Class A**: 10.0.0.0 to 10.255.255.255
    - **Class B**: 172.16.0.0 to 172.31.255.255
    - **Class C**: 192.168.0.0 to 192.168.255.255

These addresses are commonly used in home and corporate networks. To access the internet, private addresses use **Network Address Translation (NAT)**, which translates private IP addresses into public IP addresses.

---

### **Subnetting in IPv4**

**Subnetting** is the practice of dividing a larger network into smaller, more manageable subnetworks. This is done by borrowing bits from the host portion of the address and using them for the network portion.

A subnet mask defines which portion of the IP address represents the network and which part represents the host. A common subnet mask is:
```
255.255.255.0
```
This mask allows for 256 addresses within the network (including network and broadcast addresses).

For example, the address **192.168.1.0/24** means that the first 24 bits (or 3 octets) are used for the network address, and the last 8 bits (1 octet) are used for host addresses within the network.

---

### **Special IPv4 Addresses**

1. **Broadcast Address**: Used to send data to all devices in a network. This address has all host bits set to 1. For a network with a subnet mask of **255.255.255.0** and network address **192.168.1.0**, the broadcast address would be **192.168.1.255**.

2. **Loopback Address**: Used to test internal networking on a local device. The loopback address in IPv4 is **127.0.0.1**, commonly referred to as "localhost."

3. **APIPA (Automatic Private IP Addressing)**: If a device cannot obtain an IP address from a DHCP server, it may assign itself an address in the **169.254.0.0/16** range (e.g., **169.254.1.1**). This is used for local network communication when no DHCP server is available.

---

### **IPv4 Address Exhaustion**

IPv4 is a 32-bit system, meaning there are only around 4.3 billion unique IP addresses available. With the rapid growth of internet-connected devices, **IPv4 address exhaustion** has been a significant concern. To solve this, the internet community has been transitioning to **IPv6**, which uses a 128-bit address space and provides vastly more unique addresses.

---

### **Summary of Key Points**
- **IPv4** addresses are **32-bit** numbers written in **dotted decimal** notation.
- An IPv4 address consists of **4 octets** (8 bits each).
- IPv4 addresses are classified into **Classes A, B, C, D, and E**.
- There are **private** and **public** IPv4 addresses, with private addresses used for internal networks.
- **Subnetting** is used to divide larger networks into smaller ones.
- Special IPv4 addresses include **loopback**, **broadcast**, and **APIPA** addresses.
- IPv4 is nearing exhaustion, leading to the adoption of **IPv6** for addressing.

Understanding IPv4 addresses and how they work is crucial for network configuration, management, and troubleshooting.
