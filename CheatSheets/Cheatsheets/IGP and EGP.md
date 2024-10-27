An **IGP (Interior Gateway Protocol) and EGP (Exterior Gateway Protocol) Cheat Sheet** that covers key commands, features, and explanations of each protocol in a table format for easy reference. 

---

# **IGP and EGP Protocols Cheat Sheet**

## **1. Interior Gateway Protocols (IGP)**

| **Protocol** | **Type**          | **Key Commands**                             | **Explanation**                                                                                                                                         | **Use Case**                                            |
|--------------|-------------------|----------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------|
| **RIP**      | Distance Vector   | `router rip` <br> `version 2` <br> `network [network]` <br> `show ip rip database` | Starts RIP, configures Version 2 (supports subnetting), and advertises network. Displays learned routes.                                                | Small networks with low complexity.                     |
| **EIGRP**    | Hybrid            | `router eigrp [ASN]` <br> `network [network]` <br> `bandwidth [kbits]` <br> `show ip eigrp neighbors` | Enables EIGRP with ASN, advertises network, sets interface bandwidth, and shows EIGRP neighbors.                                                        | Cisco environments with medium to large networks.       |
| **OSPF**     | Link-State        | `router ospf [ID]` <br> `network [network] area [area-id]` <br> `show ip ospf neighbor` | Starts OSPF, configures advertised networks, and shows neighbors in adjacency.                                                                          | Large, scalable networks requiring fast convergence.    |
| **IS-IS**    | Link-State        | `router isis` <br> `net [Network Entity Title]` <br> `show clns neighbors`           | Starts IS-IS, sets network entity title (NET), and shows adjacency.                                                                                     | Backbone networks and ISP environments.                 |

---

## **2. Exterior Gateway Protocols (EGP)**

| **Protocol** | **Type** | **Key Commands**                            | **Explanation**                                                                                                 | **Use Case**                                            |
|--------------|----------|---------------------------------------------|-----------------------------------------------------------------------------------------------------------------|---------------------------------------------------------|
| **BGP**      | Path Vector | `router bgp [ASN]` <br> `neighbor [IP] remote-as [ASN]` <br> `network [network] mask [subnet-mask]` <br> `show ip bgp summary` | Configures BGP with ASN, defines neighbor AS, advertises networks, and shows BGP summary.                         | Internet routing, ISP peering, large enterprise networks.|

---

## **IGP vs. EGP Comparison Table**

| **Feature**                    | **IGP**                                             | **EGP**                                     |
|--------------------------------|-----------------------------------------------------|---------------------------------------------|
| **Primary Use**                | Within an autonomous system (AS)                    | Between autonomous systems                  |
| **Examples**                   | RIP, EIGRP, OSPF, IS-IS                             | BGP                                         |
| **Scalability**                | Limited to AS, typically supports smaller networks  | Highly scalable, suitable for large-scale networks |
| **Route Calculation**          | Uses distance-vector or link-state algorithms       | Uses path vector algorithm (for BGP)        |
| **Convergence Time**           | Fast convergence (OSPF/IS-IS) but varies by protocol| Slower convergence                          |
| **Complexity**                 | Lower, simpler to configure                         | Higher, more complex policy controls        |
| **Flexibility in Routing**     | Limited policy-based routing                        | Advanced policy-based routing               |
| **Common Use Case**            | Internal enterprise networks                        | Internet and WAN (Wide Area Network) routing|

---

## **Detailed IGP and EGP Commands**

### **RIP (Routing Information Protocol)**
- **Basic Configuration**:
  ```bash
  router rip
  version 2
  network 10.0.0.0
  ```
- **Verification**:
  ```bash
  show ip rip database
  ```
  - **Explanation**: Configures RIP with Version 2 and advertises `10.0.0.0`. Shows the RIP routing table.

### **EIGRP (Enhanced Interior Gateway Routing Protocol)**
- **Basic Configuration**:
  ```bash
  router eigrp 100
  network 192.168.1.0 0.0.0.255
  ```
- **Adjust Interface Bandwidth**:
  ```bash
  interface GigabitEthernet0/0
  bandwidth 1000
  ```
- **Verification**:
  ```bash
  show ip eigrp neighbors
  ```
  - **Explanation**: Starts EIGRP with ASN `100`, advertises network `192.168.1.0/24`, and adjusts bandwidth on the interface. Displays EIGRP neighbors.

### **OSPF (Open Shortest Path First)**
- **Basic Configuration**:
  ```bash
  router ospf 1
  network 10.1.1.0 0.0.0.255 area 0
  ```
- **Verification**:
  ```bash
  show ip ospf neighbor
  ```
  - **Explanation**: Configures OSPF process ID `1`, advertises `10.1.1.0/24` in Area 0, and verifies neighbors in OSPF.

### **BGP (Border Gateway Protocol)**
- **Basic Configuration**:
  ```bash
  router bgp 65001
  neighbor 192.168.2.1 remote-as 65002
  network 203.0.113.0 mask 255.255.255.0
  ```
- **Verification**:
  ```bash
  show ip bgp summary
  ```
  - **Explanation**: Configures BGP with ASN `65001`, establishes peering with ASN `65002`, advertises network `203.0.113.0/24`, and displays BGP session status.

---

Each protocol here has specific use cases, with IGPs mainly for internal routing and EGP (primarily BGP) for external routing.
