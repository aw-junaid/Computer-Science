A **Spanning Tree Protocol (STP) Cheat Sheet** that covers the essential commands, configurations, and explanations for understanding and implementing STP in a network. 

---

# **Spanning Tree Protocol (STP) Cheat Sheet**

## **1. What is Spanning Tree Protocol?**
- **Spanning Tree Protocol (STP)** is a network protocol that ensures a loop-free topology in Ethernet networks with redundant links.
- **Purpose**: Prevents broadcast storms, MAC table instability, and multiple-frame transmission in networks with redundant paths.
- **Protocol Standard**: Defined in IEEE 802.1D.

## **2. Key Components in STP**

- **Root Bridge**: The central reference point in the STP topology. Chosen based on the bridge ID (lowest bridge priority and MAC address).
- **Bridge ID**: Unique identifier used to elect the root bridge, consisting of a priority value and the MAC address.
- **BPDU (Bridge Protocol Data Units)**: Frames exchanged by switches to share STP information.
- **Port Roles**:
  - **Root Port**: The port with the best path to the root bridge.
  - **Designated Port**: A port that forwards traffic for a segment.
  - **Blocked Port**: A port that is not allowed to forward traffic to prevent loops.

## **3. STP Port States**

1. **Blocking**: Does not forward frames and listens to BPDUs.
2. **Listening**: Listens to BPDUs to decide network topology.
3. **Learning**: Learns MAC addresses but does not forward frames.
4. **Forwarding**: Forwards frames and learns MAC addresses.
5. **Disabled**: The port is administratively shut down.

---

## **4. Types of STP**

- **STP (802.1D)**: Traditional spanning tree with slower convergence.
- **RSTP (802.1w)**: Rapid Spanning Tree Protocol with faster convergence.
- **MSTP (802.1s)**: Multiple Spanning Tree Protocol for multiple VLANs.

---

## **5. Basic STP Configuration Commands**

### **1. Enable STP on a Switch**
   - **Command**: By default, most switches have STP enabled. However, you can enable it explicitly.
   ```bash
   spanning-tree vlan [vlan-id]
   ```
   - **Explanation**: Enables STP on a specified VLAN.

### **2. Set Bridge Priority**
   - **Command**:
   ```bash
   spanning-tree vlan [vlan-id] priority [value]
   ```
   - **Explanation**: Sets the switch's priority in a specific VLAN, influencing root bridge selection. Lower priority values have a higher chance of being elected as the root bridge.

### **3. View STP Status**
   - **Command**:
   ```bash
   show spanning-tree
   ```
   - **Explanation**: Displays STP information, including root bridge details, port roles, and costs.

### **4. Configure Root Bridge**
   - **Command**:
   ```bash
   spanning-tree vlan [vlan-id] root primary
   ```
   - **Explanation**: Forces the switch to become the root bridge for a specified VLAN by adjusting its priority.

### **5. Set Port Cost**
   - **Command**:
   ```bash
   spanning-tree vlan [vlan-id] cost [value]
   ```
   - **Explanation**: Sets the STP path cost for a port. Lower costs make the port more likely to become a root port.

### **6. Set Port Priority**
   - **Command**:
   ```bash
   spanning-tree vlan [vlan-id] port-priority [value]
   ```
   - **Explanation**: Sets the port priority for STP calculations within a VLAN. Lower values increase the chance of a port becoming a designated port.

### **7. Enable Rapid Spanning Tree Protocol (RSTP)**
   - **Command**:
   ```bash
   spanning-tree mode rapid-pvst
   ```
   - **Explanation**: Enables Rapid PVST+ (Cisco's implementation of RSTP for each VLAN).

### **8. Enable BPDU Guard on Access Ports**
   - **Command**:
   ```bash
   spanning-tree bpduguard enable
   ```
   - **Explanation**: Protects the network by shutting down the port if it receives a BPDU, often used on access ports to prevent loops from end devices.

### **9. Enable PortFast on Access Ports**
   - **Command**:
   ```bash
   spanning-tree portfast
   ```
   - **Explanation**: Enables PortFast, which allows the port to skip STP’s listening and learning states and go directly to forwarding, often used on ports connected to end devices.

---

## **6. Advanced STP Configuration Commands**

### **1. Enable Root Guard on a Port**
   - **Command**:
   ```bash
   spanning-tree guard root
   ```
   - **Explanation**: Prevents external switches from becoming the root bridge on a port by placing it in a root-inconsistent state if a superior BPDU is received.

### **2. Configure UplinkFast**
   - **Command**:
   ```bash
   spanning-tree uplinkfast
   ```
   - **Explanation**: Speeds up the convergence process for uplink ports in case of a failure, primarily for access switches.

### **3. Configure BackboneFast**
   - **Command**:
   ```bash
   spanning-tree backbonefast
   ```
   - **Explanation**: Reduces convergence time when an indirect link fails by immediately transitioning ports after receiving inferior BPDUs.

### **4. Disable STP on Specific VLANs**
   - **Command**:
   ```bash
   no spanning-tree vlan [vlan-id]
   ```
   - **Explanation**: Disables STP for a specific VLAN. This can be risky as it may lead to loops in VLAN segments.

---

## **7. Monitoring and Troubleshooting Commands**

### **1. Show Spanning Tree for All VLANs**
   - **Command**:
   ```bash
   show spanning-tree summary
   ```
   - **Explanation**: Displays a summary of STP status across all VLANs on the switch.

### **2. Show PortFast Status**
   - **Command**:
   ```bash
   show spanning-tree interface [interface-id] portfast
   ```
   - **Explanation**: Displays whether PortFast is enabled on a specific interface.

### **3. Show STP Root Information**
   - **Command**:
   ```bash
   show spanning-tree root
   ```
   - **Explanation**: Displays information about the current root bridge for each VLAN.

### **4. Show BPDU Guard Status**
   - **Command**:
   ```bash
   show spanning-tree inconsistentports
   ```
   - **Explanation**: Lists ports that are in an inconsistent state due to BPDU Guard.

---

## **8. STP Best Practices**

1. **Use Lower Priorities for Core Switches**: Ensure core or distribution layer switches have the lowest priorities so they are elected as the root bridge.
2. **Enable BPDU Guard on Access Ports**: Protect the network by enabling BPDU Guard on end-user access ports.
3. **Enable PortFast on Edge Ports**: Speed up connectivity on edge ports using PortFast, especially on ports connected to workstations.
4. **Use Root Guard on Uplinks**: Prevent other switches from taking over the root bridge role by enabling Root Guard on designated uplinks.

---

## **Conclusion**

Understanding and configuring STP can prevent network loops, improve network performance, and maintain a stable network topology. This cheat sheet provides essential commands and practices to manage and troubleshoot STP effectively in any network environment.
