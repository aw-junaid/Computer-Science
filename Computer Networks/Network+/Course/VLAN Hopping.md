### **VLAN Hopping**

**VLAN Hopping** is a type of network attack where an attacker gains unauthorized access to traffic from other Virtual Local Area Networks (VLANs) by exploiting vulnerabilities in the network configuration. VLANs are used to segment networks into isolated broadcast domains, which can enhance security and reduce congestion. However, improper configuration or vulnerabilities can allow attackers to bypass VLAN segmentation and access sensitive data.

VLAN Hopping typically occurs in two main forms:

1. **Double Tagging Attack**  
2. **Switch Spoofing Attack**

### **Types of VLAN Hopping**

#### 1. **Double Tagging Attack**
   - This attack leverages a vulnerability in the way VLAN tags are processed by switches. VLAN tags are used to identify the VLAN to which a packet belongs. In a double tagging attack, the attacker crafts a malicious Ethernet frame with two VLAN tags.
   - When the frame enters a switch, it typically uses the outer VLAN tag to route the frame, but when the frame reaches the second switch, the inner tag is used to identify the target VLAN. This allows the attacker to "hop" to a VLAN that they should not have access to.

   **How it works**:
   1. The attacker sends a specially crafted frame with two VLAN tags:
      - The outer tag is assigned to the VLAN the attacker is in.
      - The inner tag corresponds to the VLAN the attacker wants to gain access to.
   2. The first switch removes the outer VLAN tag and forwards the packet based on the inner tag.
   3. If the second switch is not properly configured (i.e., it trusts the inner tag), it forwards the packet to the intended target VLAN, bypassing VLAN security.

   **Mitigation**:
   - Use **access ports** for devices that do not require VLAN tagging and **trunk ports** only where necessary.
   - Disable **802.1Q trunking** on unused ports and ensure that switch ports are properly configured to handle the VLAN tagging.

#### 2. **Switch Spoofing Attack**
   - Switch spoofing occurs when an attacker tricks a switch into thinking that the attacking device is a legitimate switch, enabling the attacker to form a trunk link. Once the trunk is established, the attacker can send traffic to any VLAN, effectively bypassing VLAN restrictions.
   
   **How it works**:
   1. The attacker configures their device to impersonate a switch by sending out a **DTP (Dynamic Trunking Protocol)** message.
   2. The switch, believing the attacker to be a legitimate trunking switch, allows the attacker to create a trunk link.
   3. This trunk link allows the attacker to transmit traffic to any VLAN on the network, even if they are not authorized to access those VLANs.

   **Mitigation**:
   - Disable **DTP (Dynamic Trunking Protocol)** on all switch ports that are not explicitly needed for trunking. This can be done by configuring the ports as static access ports.
   - Manually configure trunk links between switches, avoiding dynamic trunking negotiation.
   - Use **VLAN Access Control Lists (ACLs)** to limit the traffic flow between VLANs.

### **General Mitigation Techniques**

1. **Disable Unused Ports**:
   - Physically disable unused ports to ensure attackers cannot connect to the network and launch a VLAN hopping attack.
   
2. **Secure Trunking**:
   - Use **manual configuration** for trunking (disable DTP) to ensure that only authorized devices can establish trunk links.
   - Enforce **802.1Q** tagging for all trunk ports and restrict VLANs on trunk links to only those that need to pass through.

3. **Use Access Control Lists (ACLs)**:
   - Implement **VLAN ACLs** to control and limit the traffic flow between VLANs, preventing unauthorized access.

4. **Private VLANs**:
   - Configure **Private VLANs (PVLANs)** to restrict the communication between devices within the same VLAN or across VLANs, adding an extra layer of security.

5. **Port Security**:
   - Enable **port security** on switches to limit the number of MAC addresses allowed on each port, preventing unauthorized devices from connecting to the network.

6. **Regular Audits and Monitoring**:
   - Regularly audit switch configurations, especially VLAN configurations, and monitor network traffic to detect any suspicious activity or misconfigurations.

7. **VLAN Configuration Best Practices**:
   - Configure VLANs carefully, ensuring that VLAN IDs are properly segmented and that sensitive data is placed in isolated VLANs.
   - Avoid using VLAN 1, as it is the default VLAN for many switch configurations, making it a common target for attackers.

---

### **Impact of VLAN Hopping**

1. **Unauthorized Access**:
   - If successful, VLAN hopping allows attackers to access sensitive data or resources in VLANs they are not authorized to reach.

2. **Data Exfiltration**:
   - Attackers may exfiltrate sensitive data from isolated VLANs, bypassing network segmentation and causing potential data breaches.

3. **Network Disruption**:
   - By sending unauthorized traffic to different VLANs, attackers can disrupt the network, causing congestion, service outages, or performance degradation.

4. **Compromise of Sensitive Systems**:
   - Attackers could use VLAN hopping to gain access to systems, such as servers, databases, or management interfaces, that are typically isolated in specific VLANs for security.

---

### **Conclusion**

VLAN hopping is a serious attack that can undermine the security benefits of VLAN segmentation. It exploits vulnerabilities in VLAN tagging and switch configuration to gain unauthorized access to sensitive network resources. To protect against VLAN hopping, network administrators should ensure proper configuration, implement security measures like ACLs, disable unused ports, and monitor network activity for any signs of misconfiguration or attack. Properly securing VLANs and trunk links is essential to maintaining the integrity and security of network segmentation.
