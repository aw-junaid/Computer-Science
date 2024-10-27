A **Switch Interface Properties Cheat Sheet** that covers essential switch interface properties, common commands, and their explanations for configuring and managing switch ports.

---

# **Switch Interface Properties Cheat Sheet**

## **1. Basic Interface Configuration**

### **1. Accessing Interface Configuration Mode**
   - **Command**:
   ```bash
   configure terminal
   interface [interface-id]
   ```
   - **Explanation**: Enters global configuration mode, then selects an interface (e.g., `GigabitEthernet0/1`) to configure. The `interface-id` specifies the switch port you want to configure.

### **2. Assigning a Description to an Interface**
   - **Command**:
   ```bash
   description [Description Text]
   ```
   - **Explanation**: Adds a description to the interface, making it easier to identify the interface's purpose, such as "Connected to HR PC."

### **3. Enabling or Disabling an Interface**
   - **Command to Enable**:
   ```bash
   no shutdown
   ```
   - **Command to Disable**:
   ```bash
   shutdown
   ```
   - **Explanation**: The `shutdown` command disables the interface, while `no shutdown` enables it.

---

## **2. Interface Speed and Duplex Settings**

### **1. Configuring Speed**
   - **Command**:
   ```bash
   speed [10 | 100 | 1000 | auto]
   ```
   - **Explanation**: Sets the speed of the interface to either 10 Mbps, 100 Mbps, 1000 Mbps, or `auto` for auto-negotiation based on the connected device's capability.

### **2. Configuring Duplex Mode**
   - **Command**:
   ```bash
   duplex [auto | full | half]
   ```
   - **Explanation**: Sets the duplex mode of the interface:
     - `auto`: Auto-negotiates the best duplex mode.
     - `full`: Both sending and receiving can occur simultaneously.
     - `half`: Only one direction of communication is allowed at a time.

---

## **3. Switch Port Modes (Access and Trunk)**

### **1. Configuring a Port as an Access Port**
   - **Command**:
   ```bash
   switchport mode access
   switchport access vlan [vlan-id]
   ```
   - **Explanation**: Sets the port to access mode and assigns it to a specific VLAN. Access ports are typically used to connect end devices like computers or printers.

### **2. Configuring a Port as a Trunk Port**
   - **Command**:
   ```bash
   switchport mode trunk
   switchport trunk allowed vlan [vlan-id, vlan-id]
   ```
   - **Explanation**: Configures the port as a trunk, allowing it to carry traffic from multiple VLANs. Use `allowed vlan` to specify which VLANs are allowed on the trunk.

### **3. Setting the Native VLAN on a Trunk Port**
   - **Command**:
   ```bash
   switchport trunk native vlan [vlan-id]
   ```
   - **Explanation**: Specifies the native VLAN for untagged traffic on a trunk port. By default, VLAN 1 is often used as the native VLAN.

---

## **4. Security Features**

### **1. Enabling Port Security**
   - **Command**:
   ```bash
   switchport port-security
   ```
   - **Explanation**: Enables port security, which restricts the number of devices allowed on the port.

### **2. Setting Maximum MAC Addresses Allowed**
   - **Command**:
   ```bash
   switchport port-security maximum [number]
   ```
   - **Explanation**: Limits the number of MAC addresses that can be learned on the port, providing an additional layer of security.

### **3. Configuring a Port Security Violation Action**
   - **Command**:
   ```bash
   switchport port-security violation [protect | restrict | shutdown]
   ```
   - **Explanation**:
     - `protect`: Discards traffic from unknown MAC addresses but does not log violations.
     - `restrict`: Discards traffic and logs a security violation.
     - `shutdown`: Puts the port in an error-disabled state if a violation occurs (default action).

---

## **5. Advanced Interface Settings**

### **1. Setting Interface Bandwidth (for reference)**
   - **Command**:
   ```bash
   bandwidth [kilobits per second]
   ```
   - **Explanation**: Adjusts the perceived bandwidth of the interface for routing protocols, but does not actually change the physical bandwidth.

### **2. Enabling Spanning Tree Protocol (STP) PortFast**
   - **Command**:
   ```bash
   spanning-tree portfast
   ```
   - **Explanation**: Enables STP PortFast, allowing the port to skip the STP listening and learning states, useful for end devices to quickly connect.

### **3. Enabling BPDU Guard on an Interface**
   - **Command**:
   ```bash
   spanning-tree bpduguard enable
   ```
   - **Explanation**: Enables BPDU Guard, which shuts down the port if a BPDU is received, protecting against accidental loops from misconfigured devices on access ports.

### **4. Configuring EtherChannel (Link Aggregation)**
   - **Command**:
   ```bash
   interface range [interface-id, interface-id]
   channel-group [number] mode [on | active | passive]
   ```
   - **Explanation**: Aggregates multiple physical links into a single logical link for redundancy and increased bandwidth. `mode` options:
     - `on`: Forces EtherChannel without protocol negotiation.
     - `active`: Uses LACP (Link Aggregation Control Protocol) to form the EtherChannel.
     - `passive`: Waits for LACP initiation.

---

## **6. Monitoring and Verification Commands**

### **1. Display Interface Status**
   - **Command**:
   ```bash
   show interfaces status
   ```
   - **Explanation**: Shows interface status, VLAN assignment, speed, and duplex information.

### **2. Display Detailed Interface Configuration**
   - **Command**:
   ```bash
   show running-config interface [interface-id]
   ```
   - **Explanation**: Displays the current configuration for a specified interface.

### **3. View Port Security Status**
   - **Command**:
   ```bash
   show port-security interface [interface-id]
   ```
   - **Explanation**: Displays port security status and configuration details for a specific interface.

### **4. Check Trunk Port Status**
   - **Command**:
   ```bash
   show interfaces trunk
   ```
   - **Explanation**: Shows all active trunk ports and the VLANs allowed on each.

### **5. Display EtherChannel Summary**
   - **Command**:
   ```bash
   show etherchannel summary
   ```
   - **Explanation**: Displays the status of EtherChannel groups on the switch.

---

## **7. Example Configuration Scenarios**

### **1. Configure a Secure Access Port for an Office PC**
   ```bash
   configure terminal
   interface GigabitEthernet0/1
   description Office_PC
   switchport mode access
   switchport access vlan 10
   switchport port-security
   switchport port-security maximum 1
   switchport port-security violation shutdown
   spanning-tree portfast
   ```
   - **Explanation**: Configures an access port in VLAN 10 for a PC, limits to one MAC address, and shuts down on violation.

### **2. Configure a Trunk Port for Switch Interconnection**
   ```bash
   configure terminal
   interface GigabitEthernet0/24
   description Uplink_to_Switch2
   switchport mode trunk
   switchport trunk allowed vlan 10,20,30
   switchport trunk native vlan 99
   ```
   - **Explanation**: Sets up a trunk port allowing VLANs 10, 20, and 30, with VLAN 99 as the native VLAN.

---

## **Summary**

This cheat sheet provides a structured approach to configuring and managing switch interfaces, covering everything from basic settings to security, trunking, and monitoring. Implement these commands to create secure, well-managed switch interfaces in any network environment.
