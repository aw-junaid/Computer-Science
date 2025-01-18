### **Classful Subnetting and IPv4 Subnet Masks**

**Classful subnetting** is a method used in IPv4 addressing to divide the IP address space into distinct network classes (Class A, B, C, D, and E). This concept was prominent before the introduction of **CIDR (Classless Inter-Domain Routing)** but is still useful to understand basic network design. In classful subnetting, the subnet mask is implicitly determined based on the class of the address.

A **subnet mask** in IPv4 is a 32-bit number that separates the network portion of an IP address from the host portion. The subnet mask indicates which part of the address is for network identification and which part is for host identification. 

#### **IPv4 Address Classes**

- **Class A** (1.0.0.0 to 127.255.255.255):
  - Default subnet mask: **255.0.0.0** (or **/8**)
  - The first octet (8 bits) is used for the network portion, and the remaining three octets (24 bits) are used for the host portion.
  - Supports up to **16 million** hosts on a single network.

- **Class B** (128.0.0.0 to 191.255.255.255):
  - Default subnet mask: **255.255.0.0** (or **/16**)
  - The first two octets (16 bits) are used for the network portion, and the remaining two octets (16 bits) are used for the host portion.
  - Supports up to **65,000** hosts per network.

- **Class C** (192.0.0.0 to 223.255.255.255):
  - Default subnet mask: **255.255.255.0** (or **/24**)
  - The first three octets (24 bits) are used for the network portion, and the remaining one octet (8 bits) is used for the host portion.
  - Supports up to **254** hosts per network.

- **Class D** (224.0.0.0 to 239.255.255.255): Reserved for **multicast** groups. These addresses are not used for regular hosts.
  
- **Class E** (240.0.0.0 to 255.255.255.255): Reserved for **experimental purposes** and not used for general addressing.

---

### **Subnet Mask in Classful Addressing**

The subnet mask is used to identify which part of an IPv4 address corresponds to the network and which part corresponds to the host. It does this by marking the network portion of the address with **1s** and the host portion with **0s**.

- **Class A**: The default subnet mask is **255.0.0.0** or **/8**. This means the first 8 bits represent the network portion, and the remaining 24 bits are for hosts.
  
- **Class B**: The default subnet mask is **255.255.0.0** or **/16**. The first 16 bits represent the network portion, and the remaining 16 bits are for hosts.
  
- **Class C**: The default subnet mask is **255.255.255.0** or **/24**. The first 24 bits represent the network portion, and the remaining 8 bits are for hosts.

---

### **Subnetting Process**

Subnetting is the process of dividing a large network into smaller, more manageable subnets. When subnetting, bits are borrowed from the host portion of the address and used to create additional network bits. This results in a new subnet mask, which is typically expressed in **CIDR notation** (e.g., **/24**).

#### **Steps for Subnetting:**

1. **Determine the required number of subnets**: Based on the number of subnets needed for the network.
2. **Borrow bits from the host portion**: The more bits borrowed, the more subnets can be created.
3. **Create the new subnet mask**: Combine the network bits from the classful address and the borrowed bits to create a new subnet mask.
4. **Calculate the number of hosts per subnet**: Subtract the network bits and the borrowed bits from 32 to determine how many bits are available for hosts.
5. **Assign subnets**: Create the subnets based on the new subnet mask.

---

### **Example of Subnetting:**

Let’s take a **Class C** IP address: **192.168.1.0/24**

We want to subnet this network into 4 subnets.

- The default subnet mask for **Class C** is **255.255.255.0** (**/24**).
- To create 4 subnets, we need to borrow 2 bits from the host portion (8 bits in Class C) because \( 2^2 = 4 \).
- New subnet mask: **/26** (which is **255.255.255.192**).

#### **Calculating the Number of Hosts per Subnet:**

With a **/26** subnet mask, 6 bits are available for hosts (since 32 - 26 = 6). The formula for calculating the number of hosts is:
\[
2^6 - 2 = 62 \text{ hosts per subnet (subtracting 2 for the network and broadcast addresses)}.
\]

#### **New Subnets:**

- **192.168.1.0/26**: Network address **192.168.1.0**, broadcast address **192.168.1.63**, host range **192.168.1.1 to 192.168.1.62**.
- **192.168.1.64/26**: Network address **192.168.1.64**, broadcast address **192.168.1.127**, host range **192.168.1.65 to 192.168.1.126**.
- **192.168.1.128/26**: Network address **192.168.1.128**, broadcast address **192.168.1.191**, host range **192.168.1.129 to 192.168.1.190**.
- **192.168.1.192/26**: Network address **192.168.1.192**, broadcast address **192.168.1.255**, host range **192.168.1.193 to 192.168.1.254**.

---

### **CIDR (Classless Inter-Domain Routing) Notation**

CIDR notation provides a more flexible and efficient way of subnetting than the classful method. Instead of being restricted by fixed class-based subnet masks, CIDR allows for more granular control over the network portion of the address.

- CIDR notation is written as **IP address/Prefix length**, where the **prefix length** indicates how many bits are used for the network portion of the address. 
- For example, **192.168.1.0/26** means the first 26 bits are used for the network, leaving 6 bits for hosts.

CIDR allows for more efficient use of IP address space, especially in large networks.

---

### **Subnet Mask Table**

| **Class**   | **Default Subnet Mask** | **CIDR Notation** | **Number of Hosts**       |
|-------------|-------------------------|-------------------|---------------------------|
| Class A     | 255.0.0.0               | /8                | 16,777,214                |
| Class B     | 255.255.0.0             | /16               | 65,534                    |
| Class C     | 255.255.255.0           | /24               | 254                       |
| Class D     | Reserved                | N/A               | N/A                       |
| Class E     | Reserved                | N/A               | N/A                       |

---

### **Summary**

- **Classful subnetting** divides the IPv4 address space into five classes (A, B, C, D, and E), each with a default subnet mask.
- Subnet masks determine which part of an IP address is the network portion and which part is the host portion.
- **Subnetting** involves borrowing bits from the host portion to create additional subnets, resulting in a new subnet mask.
- **CIDR** notation allows for more flexible subnetting by specifying the exact number of bits used for the network portion.
- The **subnet mask** and **CIDR notation** are essential for dividing networks into smaller, more manageable subnets.

Understanding classful subnetting and subnet masks is crucial for designing and managing IP networks efficiently.
