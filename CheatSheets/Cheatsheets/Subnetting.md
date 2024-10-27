A comprehensive subnetting cheat sheet that covers essential concepts, calculations, and examples for understanding and implementing subnetting in networking.

---

# **Subnetting Cheat Sheet**

## **1. Introduction to Subnetting**

**Subnetting** is the practice of dividing a larger IP network into smaller, manageable subnetworks (subnets). It improves network efficiency, enhances security, and simplifies management.

### **Key Concepts**
- **IP Address**: A unique identifier for a device on a network, typically represented as four octets (e.g., 192.168.1.1).
- **Subnet Mask**: A 32-bit number that divides the IP address into the network and host portions.
- **CIDR Notation**: A shorthand for the subnet mask (e.g., /24), indicating how many bits are used for the network.

---

## **2. Understanding IP Address Classes**

| **Class** | **IP Range**        | **Default Subnet Mask** | **CIDR Notation** |
|-----------|---------------------|-------------------------|--------------------|
| Class A   | 1.0.0.0 to 126.0.0.0| 255.0.0.0               | /8                 |
| Class B   | 128.0.0.0 to 191.255.0.0| 255.255.0.0         | /16                |
| Class C   | 192.0.0.0 to 223.255.255.0| 255.255.255.0     | /24                |
| Class D   | 224.0.0.0 to 239.255.255.255| N/A                | N/A                |
| Class E   | 240.0.0.0 to 255.255.255.255| N/A                | N/A                |

### **Special Addresses**
- **Loopback Address**: 127.0.0.1 (used for local testing)
- **Private IP Ranges**:
  - Class A: 10.0.0.0 to 10.255.255.255
  - Class B: 172.16.0.0 to 172.31.255.255
  - Class C: 192.168.0.0 to 192.168.255.255

---

## **3. Subnetting Calculations**

### **Subnet Mask Calculation**
1. Determine the number of subnets required.
2. Calculate the number of bits needed to represent the subnets using the formula:  
   \[
   \text{Number of subnets} = 2^n \quad \text{(where n is the number of bits)}
   \]
3. Calculate the new subnet mask by adding the number of bits used for subnets to the default mask.

### **Host Calculation**
1. Determine the number of hosts required in each subnet.
2. Calculate the number of bits needed for hosts using the formula:  
   \[
   \text{Number of hosts} = 2^h - 2 \quad \text{(where h is the number of bits for hosts)}
   \]
   - Subtract 2 for network and broadcast addresses.

### **Example:**
- Given a Class C network (192.168.1.0) and a requirement for 4 subnets:
  - Default Subnet Mask: 255.255.255.0 (/24)
  - Bits for Subnets: \(n = 2\) (since \(2^2 = 4\))
  - New Subnet Mask: 255.255.255.192 (/26)
  - Hosts per Subnet: \(h = 6\) (since \(2^6 - 2 = 62\))

---

## **4. CIDR Notation and Subnetting Table**

### **Subnetting Table for /24 to /30**

| **CIDR Notation** | **Subnet Mask**       | **Subnets** | **Hosts per Subnet** |
|-------------------|-----------------------|-------------|-----------------------|
| /24               | 255.255.255.0         | 1           | 254                   |
| /25               | 255.255.255.128       | 2           | 126                   |
| /26               | 255.255.255.192       | 4           | 62                    |
| /27               | 255.255.255.224       | 8           | 30                    |
| /28               | 255.255.255.240       | 16          | 14                    |
| /29               | 255.255.255.248       | 32          | 6                     |
| /30               | 255.255.255.252       | 64          | 2                     |

---

## **5. Subnetting Example**

### Example: Subnetting 192.168.1.0/24 into 4 Subnets

1. **Original Network**: 192.168.1.0/24
2. **New Subnet Mask**: /26 (255.255.255.192)
3. **Calculate Subnets**:
   - **Subnet 1**: 192.168.1.0/26 (Range: 192.168.1.1 - 192.168.1.62, Broadcast: 192.168.1.63)
   - **Subnet 2**: 192.168.1.64/26 (Range: 192.168.1.65 - 192.168.1.126, Broadcast: 192.168.1.127)
   - **Subnet 3**: 192.168.1.128/26 (Range: 192.168.1.129 - 192.168.1.190, Broadcast: 192.168.1.191)
   - **Subnet 4**: 192.168.1.192/26 (Range: 192.168.1.193 - 192.168.1.254, Broadcast: 192.168.1.255)

---

## **6. Tools for Subnetting**

- **Subnet Calculators**: Various online tools help in calculating subnets and CIDR notations.
- **Command-Line Tools**:
  - **Linux/Unix**: Use `ipcalc` for calculations.
    ```bash
    ipcalc 192.168.1.0/24
    ```

---

## **7. Summary of Subnetting Steps**

1. Determine the number of required subnets.
2. Identify the number of bits needed for subnetting.
3. Calculate the new subnet mask and CIDR notation.
4. Calculate the number of hosts per subnet.
5. List out the subnets with their ranges and broadcast addresses.

---

## **8. Conclusion**

Subnetting is a crucial skill in networking, allowing for efficient use of IP address space and improved network management. This cheat sheet provides an overview of subnetting concepts, calculations, and examples. For deeper understanding and practice, consider using subnetting exercises and tools.
