### **Switch Interface Properties**

Switch interface properties refer to the configurable characteristics and behaviors of the ports on a network switch. These properties determine how a switch port operates, interacts with connected devices, and handles data traffic. Proper configuration of switch interfaces is crucial for achieving optimal network performance, security, and reliability.

---

### **Common Switch Interface Properties**

#### 1. **Speed and Duplex Settings**
   - **Speed**: Determines the transmission rate of the port (e.g., 10 Mbps, 100 Mbps, 1 Gbps, or 10 Gbps).
   - **Duplex**:
     - **Full-Duplex**: Allows simultaneous sending and receiving of data.
     - **Half-Duplex**: Data transmission occurs in one direction at a time.
   - **Configuration**:
     - **Auto-Negotiation**: Default mode where the switch and connected device automatically agree on speed and duplex settings.
     - **Manual Configuration**: Useful for preventing mismatches that can cause performance issues.

   **Commands (Cisco Example)**:
   ```bash
   interface GigabitEthernet0/1
   speed 1000
   duplex full
   ```

#### 2. **Port Modes**
   - **Access Mode**:
     - Configures the port for a single VLAN.
     - Commonly used for end-user devices.
   - **Trunk Mode**:
     - Allows the port to carry traffic for multiple VLANs using VLAN tagging (e.g., IEEE 802.1Q).
     - Commonly used for switch-to-switch or switch-to-router connections.

   **Commands**:
   ```bash
   interface GigabitEthernet0/1
   switchport mode access
   switchport access vlan 10

   interface GigabitEthernet0/2
   switchport mode trunk
   switchport trunk allowed vlan 10,20,30
   ```

#### 3. **Port Security**
   - Limits the number of MAC addresses allowed on a port to prevent unauthorized devices from accessing the network.
   - Can specify actions for violations:
     - **Protect**: Drops packets from unauthorized MAC addresses.
     - **Restrict**: Logs violations and drops packets.
     - **Shutdown**: Disables the port on a violation.

   **Commands**:
   ```bash
   interface GigabitEthernet0/1
   switchport port-security
   switchport port-security maximum 2
   switchport port-security violation shutdown
   switchport port-security mac-address sticky
   ```

#### 4. **VLAN Assignment**
   - Assigns a specific VLAN to the port.
   - Only applicable in access mode.

   **Command**:
   ```bash
   interface GigabitEthernet0/1
   switchport access vlan 20
   ```

#### 5. **Spanning Tree Protocol (STP) Settings**
   - Configures STP-related properties to prevent loops and optimize topology.
   - **PortFast**: Used for end-user devices to skip STP states and immediately enter the forwarding state.
   - **BPDU Guard**: Protects the network by shutting down a port if a BPDU is received.

   **Commands**:
   ```bash
   interface GigabitEthernet0/1
   spanning-tree portfast
   spanning-tree bpduguard enable
   ```

#### 6. **EtherChannel (Link Aggregation)**
   - Combines multiple physical links into a single logical link for increased bandwidth and redundancy.
   - Uses protocols like LACP (Link Aggregation Control Protocol) or PAgP (Cisco proprietary).

   **Commands**:
   ```bash
   interface range GigabitEthernet0/1 - 2
   channel-group 1 mode active
   ```

#### 7. **Power over Ethernet (PoE)**
   - Provides electrical power to connected devices (e.g., IP phones, wireless access points) over Ethernet cables.
   - Configurable on PoE-capable switches.

   **Command**:
   ```bash
   interface GigabitEthernet0/1
   power inline auto
   ```

#### 8. **MTU (Maximum Transmission Unit)**
   - Configures the maximum frame size a port can handle. Default is usually 1500 bytes for Ethernet.
   - Increasing MTU allows jumbo frames for high-performance applications.

   **Command**:
   ```bash
   interface GigabitEthernet0/1
   mtu 9000
   ```

#### 9. **Administrative States**
   - **Enabled**: The port is active and can transmit/receive traffic.
   - **Disabled**: The port is administratively shut down and does not forward traffic.

   **Command**:
   ```bash
   interface GigabitEthernet0/1
   shutdown
   no shutdown
   ```

#### 10. **Storm Control**
   - Prevents broadcast, multicast, or unknown unicast traffic from overwhelming the port.
   - Configurable thresholds limit the traffic rate.

   **Command**:
   ```bash
   interface GigabitEthernet0/1
   storm-control broadcast level 1.00
   ```

---

### **Best Practices for Configuring Switch Interfaces**

1. **Enable Port Security**: Prevent unauthorized devices from connecting to sensitive ports.  
2. **Use Descriptive Interface Descriptions**: Document the purpose of each port for easier management.  
   ```bash
   interface GigabitEthernet0/1
   description Connected to Finance-PC1
   ```
3. **Disable Unused Ports**: Shut down inactive ports to improve security.  
4. **Implement STP Features**: Use PortFast and BPDU Guard where appropriate to prevent misconfigurations.  
5. **Use Auto-Negotiation with Care**: Avoid mismatched speed/duplex settings by explicitly configuring them when needed.  

---
