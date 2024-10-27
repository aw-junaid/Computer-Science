A **Switch Static and Dynamic Routing Cheat Sheet** covering key commands, configurations, and explanations for both static and dynamic routing on Layer 3 switches. 

---

# **Switch Static and Dynamic Routing Cheat Sheet**

### **Static Routing**

Static routing involves manually defining routes to specific networks in a Layer 3 switch, which can be useful for small, predictable network topologies. 

#### **1. Enable IP Routing on the Switch**
   - **Command**:
   ```bash
   configure terminal
   ip routing
   ```
   - **Explanation**: Enables Layer 3 routing capabilities on the switch, allowing it to route traffic between different VLANs or subnets.

#### **2. Configuring a Static Route**
   - **Command**:
   ```bash
   ip route [destination-network] [subnet-mask] [next-hop-IP or exit-interface]
   ```
   - **Example**:
   ```bash
   ip route 192.168.10.0 255.255.255.0 192.168.1.1
   ```
   - **Explanation**: Adds a static route for traffic destined to `192.168.10.0/24` through the next-hop IP `192.168.1.1`. Static routes are simple to configure but do not automatically adjust for network changes.

#### **3. Default Route**
   - **Command**:
   ```bash
   ip route 0.0.0.0 0.0.0.0 [next-hop-IP]
   ```
   - **Example**:
   ```bash
   ip route 0.0.0.0 0.0.0.0 192.168.1.1
   ```
   - **Explanation**: Creates a default route (also known as a “gateway of last resort”) that directs all traffic not matching specific routes to `192.168.1.1`.

#### **4. Verify Static Routes**
   - **Command**:
   ```bash
   show ip route
   ```
   - **Explanation**: Displays the routing table, showing all configured routes, including static and directly connected routes.

---

### **Dynamic Routing**

Dynamic routing automatically discovers network topology changes and adjusts routes accordingly. Layer 3 switches often support RIP, EIGRP, or OSPF for dynamic routing.

#### **Routing Information Protocol (RIP)**

##### **1. Enable RIP**
   - **Command**:
   ```bash
   configure terminal
   router rip
   ```
   - **Explanation**: Starts RIP on the switch. RIP is a distance-vector protocol suitable for small networks (RIP Version 2 is preferred due to subnet support).

##### **2. Specify RIP Version**
   - **Command**:
   ```bash
   version 2
   ```
   - **Explanation**: Configures RIP to use Version 2, which supports classless routing and is more flexible for modern networks.

##### **3. Advertise Networks in RIP**
   - **Command**:
   ```bash
   network [network-address]
   ```
   - **Example**:
   ```bash
   network 192.168.1.0
   ```
   - **Explanation**: Advertises the specified network in RIP, allowing it to be shared with other RIP-enabled devices.

##### **4. Verify RIP Configuration**
   - **Command**:
   ```bash
   show ip rip database
   ```
   - **Explanation**: Displays the RIP routing database, showing networks learned via RIP.

---

#### **Open Shortest Path First (OSPF)**

##### **1. Enable OSPF**
   - **Command**:
   ```bash
   configure terminal
   router ospf [process-id]
   ```
   - **Example**:
   ```bash
   router ospf 1
   ```
   - **Explanation**: Starts OSPF on the switch. `process-id` is locally significant, allowing multiple OSPF processes on the device if needed.

##### **2. Configure OSPF Router ID**
   - **Command**:
   ```bash
   router-id [router-id]
   ```
   - **Example**:
   ```bash
   router-id 1.1.1.1
   ```
   - **Explanation**: Sets a unique router ID for OSPF operations, useful in identifying routers in OSPF databases.

##### **3. Advertise Networks in OSPF**
   - **Command**:
   ```bash
   network [network-address] [wildcard-mask] area [area-id]
   ```
   - **Example**:
   ```bash
   network 192.168.1.0 0.0.0.255 area 0
   ```
   - **Explanation**: Advertises the specified network in OSPF Area 0. The wildcard mask determines which IP range is covered.

##### **4. Configure OSPF Cost on an Interface**
   - **Command**:
   ```bash
   interface [interface-id]
   ip ospf cost [cost-value]
   ```
   - **Explanation**: Adjusts OSPF cost to influence path selection. Lower costs are preferred, affecting the chosen route within the OSPF topology.

##### **5. Verify OSPF Configuration**
   - **Command**:
   ```bash
   show ip ospf neighbor
   ```
   - **Explanation**: Shows information about OSPF neighbors and their relationship states, confirming OSPF adjacency.

---

#### **Enhanced Interior Gateway Routing Protocol (EIGRP)**

##### **1. Enable EIGRP**
   - **Command**:
   ```bash
   configure terminal
   router eigrp [ASN]
   ```
   - **Example**:
   ```bash
   router eigrp 100
   ```
   - **Explanation**: Starts EIGRP with an Autonomous System Number (ASN) on the switch.

##### **2. Specify EIGRP Networks**
   - **Command**:
   ```bash
   network [network-address] [wildcard-mask]
   ```
   - **Example**:
   ```bash
   network 192.168.1.0 0.0.0.255
   ```
   - **Explanation**: Advertises the specified network for EIGRP, allowing it to be learned by other EIGRP devices.

##### **3. Set EIGRP Bandwidth on an Interface**
   - **Command**:
   ```bash
   interface [interface-id]
   bandwidth [kilobits-per-second]
   ```
   - **Explanation**: Configures interface bandwidth, which EIGRP uses for metric calculations.

##### **4. Verify EIGRP Configuration**
   - **Command**:
   ```bash
   show ip eigrp neighbors
   ```
   - **Explanation**: Displays EIGRP neighbors and shows whether the switch has formed adjacencies.

---

### **Route Redistribution (Static to Dynamic and Vice Versa)**

Route redistribution allows static and dynamic routes to be shared across different routing protocols, enabling a more cohesive network topology.

#### **1. Redistribute Static Routes into a Dynamic Protocol**
   - **Command**:
   ```bash
   router [protocol]
   redistribute static
   ```
   - **Example for OSPF**:
   ```bash
   router ospf 1
   redistribute static subnets
   ```
   - **Explanation**: Redistributes static routes into OSPF, making them visible in the OSPF routing table and advertised to OSPF neighbors.

#### **2. Redistribute Routes between Dynamic Protocols**
   - **Command**:
   ```bash
   router [protocol]
   redistribute [other-protocol]
   ```
   - **Example for Redistributing OSPF into EIGRP**:
   ```bash
   router eigrp 100
   redistribute ospf 1
   ```
   - **Explanation**: Shares routes from one dynamic protocol (e.g., OSPF) with another (e.g., EIGRP), allowing seamless route sharing across different protocol types.

---

### **Verification and Troubleshooting**

#### **1. Display Routing Table**
   - **Command**:
   ```bash
   show ip route
   ```
   - **Explanation**: Lists all active routes in the routing table, including static, connected, and dynamically learned routes.

#### **2. View Routing Protocol-Specific Information**
   - **RIP**: 
     ```bash
     show ip rip database
     ```
   - **OSPF**: 
     ```bash
     show ip ospf neighbor
     show ip ospf interface
     ```
   - **EIGRP**: 
     ```bash
     show ip eigrp neighbors
     show ip eigrp topology
     ```
   - **Explanation**: Each command displays protocol-specific information for monitoring the health and status of dynamic routing protocols.

#### **3. Trace Path of a Packet**
   - **Command**:
   ```bash
   traceroute [destination-ip]
   ```
   - **Explanation**: Displays the path a packet takes to reach its destination, useful for troubleshooting route paths and connectivity issues.

---

### **Example Configurations**

#### **Static Routing Example**
```bash
configure terminal
ip routing
ip route 192.168.10.0 255.255.255.0 192.168.1.1
ip route 0.0.0.0 0.0.0.0 192.168.1.1
```

#### **Dynamic Routing Example (OSPF)**
```bash
configure terminal
router ospf 1
network 192.168.1.0 0.0.0.255 area 0
```

#### **Dynamic Routing Example (EIGRP)**
```bash
configure terminal
router eigrp 100
network

 192.168.1.0 0.0.0.255
```

---

This cheat sheet provides a comprehensive guide for setting up static and dynamic routing on Layer 3 switches.
