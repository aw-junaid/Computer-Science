### **Calculating IPv4 Subnets and Hosts**

When dealing with IPv4 addressing, it’s essential to know how to calculate the number of available subnets and hosts for a given IP address and subnet mask. This can be done using basic binary math and subnetting principles.

### **1. Understanding the Subnet Mask**

An IPv4 address is a 32-bit address, which is divided into four octets (each 8 bits long). The subnet mask defines how many bits are used for the network portion and how many bits are available for hosts. The more bits used for the network portion, the fewer bits are available for host addresses.

**Example:**
IPv4 address: `192.168.10.0`
Subnet mask: `255.255.255.0` or `/24`

The subnet mask `255.255.255.0` is written in binary as:

```
11111111.11111111.11111111.00000000
```

The first 24 bits are set to `1`, representing the network portion, and the last 8 bits are set to `0`, representing the host portion.

### **2. Calculating Subnets**

To calculate the number of subnets, you need to know how many bits have been borrowed from the host portion of the address. This is typically done by changing the default subnet mask of the class of the network (Class A, B, or C) to create additional subnets.

#### **Formula for Subnets:**

The formula to calculate the number of subnets is:

\[
\text{Number of Subnets} = 2^n
\]

Where **n** is the number of bits borrowed from the host portion.

#### **Example:**

Given the IP address `192.168.10.0` and subnet mask `255.255.255.192` (which is a `/26` subnet):

- The default subnet mask for a Class C address (`192.168.10.0`) is `/24`.
- The new subnet mask is `/26`, so we have borrowed **2 bits** from the host portion.
  
Now, we can calculate the number of subnets:

\[
\text{Number of Subnets} = 2^2 = 4
\]

So, with a `/26` subnet mask, we can create **4 subnets**.

### **3. Calculating Hosts per Subnet**

To calculate the number of hosts per subnet, we use the number of bits available for the host portion of the address.

#### **Formula for Hosts:**

The formula to calculate the number of hosts is:

\[
\text{Number of Hosts} = 2^h - 2
\]

Where **h** is the number of bits left for the host portion. The subtraction of 2 accounts for the **network address** (all 0s) and the **broadcast address** (all 1s) which cannot be assigned to hosts.

#### **Example:**

Let’s continue with the `/26` subnet mask:

- The subnet mask is `/26`, which means the first 26 bits are used for the network portion, leaving **6 bits** for the host portion.
  
Now, we can calculate the number of hosts per subnet:

\[
\text{Number of Hosts} = 2^6 - 2 = 64 - 2 = 62
\]

So, each `/26` subnet can have **62 hosts**.

### **4. Step-by-Step Calculation Example**

Let’s walk through a more detailed example with the network `192.168.10.0/24` and subnet mask `255.255.255.224` (or `/27`).

#### **Step 1: Identify the number of borrowed bits**

- The default subnet mask for a Class C network is `/24` (which is `255.255.255.0`).
- The new subnet mask is `/27` (which is `255.255.255.224`).
  
We borrowed **3 bits** from the host portion (`27 - 24 = 3`).

#### **Step 2: Calculate the number of subnets**

Using the formula for subnets:

\[
\text{Number of Subnets} = 2^3 = 8
\]

So, we can create **8 subnets** with a `/27` subnet mask.

#### **Step 3: Calculate the number of hosts per subnet**

Using the formula for hosts:

\[
\text{Number of Hosts} = 2^5 - 2 = 32 - 2 = 30
\]

So, each `/27` subnet can have **30 hosts**.

#### **Step 4: Subnetting the Network**

Now that we know we have **8 subnets** and **30 hosts** per subnet, let’s find the subnets:

The first subnet will start at `192.168.10.0` and the next subnet will start 32 addresses later (since the subnet size is 32 addresses). The subnets are as follows:

1. **Subnet 1**: `192.168.10.0/27` (Network: `192.168.10.0`, Broadcast: `192.168.10.31`, Hosts: `192.168.10.1` to `192.168.10.30`)
2. **Subnet 2**: `192.168.10.32/27` (Network: `192.168.10.32`, Broadcast: `192.168.10.63`, Hosts: `192.168.10.33` to `192.168.10.62`)
3. **Subnet 3**: `192.168.10.64/27` (Network: `192.168.10.64`, Broadcast: `192.168.10.95`, Hosts: `192.168.10.65` to `192.168.10.94`)
4. **Subnet 4**: `192.168.10.96/27` (Network: `192.168.10.96`, Broadcast: `192.168.10.127`, Hosts: `192.168.10.97` to `192.168.10.126`)
5. **Subnet 5**: `192.168.10.128/27` (Network: `192.168.10.128`, Broadcast: `192.168.10.159`, Hosts: `192.168.10.129` to `192.168.10.158`)
6. **Subnet 6**: `192.168.10.160/27` (Network: `192.168.10.160`, Broadcast: `192.168.10.191`, Hosts: `192.168.10.161` to `192.168.10.190`)
7. **Subnet 7**: `192.168.10.192/27` (Network: `192.168.10.192`, Broadcast: `192.168.10.223`, Hosts: `192.168.10.193` to `192.168.10.222`)
8. **Subnet 8**: `192.168.10.224/27` (Network: `192.168.10.224`, Broadcast: `192.168.10.255`, Hosts: `192.168.10.225` to `192.168.10.254`)

### **Summary**

- **Subnets**: The number of subnets can be calculated by borrowing bits from the host portion of the address. The formula is `2^n`, where **n** is the number of borrowed bits.
- **Hosts per Subnet**: The number of hosts in each subnet is calculated by the formula `2^h - 2`, where **h** is the number of bits available for hosts.
- In general, you must balance the number of subnets needed with the number of hosts required for each subnet to maximize the use of available IP addresses.
