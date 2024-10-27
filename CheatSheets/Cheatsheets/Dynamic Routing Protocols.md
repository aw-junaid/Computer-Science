An **Extended Dynamic Routing Protocols Cheat Sheet** covering key protocols, commands, features, and explanations using tables for easy reference. This includes common dynamic routing protocols used within networks: RIP, EIGRP, OSPF, IS-IS, and BGP.

---

# **Dynamic Routing Protocols Cheat Sheet**

## **1. Overview Table**

| **Protocol** | **Type**          | **Algorithm**           | **Metric**         | **Key Features**                                                        | **Primary Use**                         |
|--------------|-------------------|-------------------------|--------------------|-------------------------------------------------------------------------|-----------------------------------------|
| **RIP**      | Distance Vector   | Bellman-Ford            | Hop Count         | Simple configuration, limited to 15 hops                               | Small networks                          |
| **EIGRP**    | Hybrid            | DUAL (Diffusing Update Algorithm) | Bandwidth, Delay | Cisco proprietary, fast convergence, supports unequal load balancing    | Medium to large enterprise networks     |
| **OSPF**     | Link-State        | Dijkstra’s Shortest Path | Cost (Bandwidth)  | Open standard, hierarchical design, fast convergence                    | Large and scalable networks             |
| **IS-IS**    | Link-State        | Dijkstra’s Shortest Path | Cost              | Supports large networks, often used in ISP backbones                    | Backbone networks, ISPs                 |
| **BGP**      | Path Vector       | Path Vector            | Path attributes   | Exterior routing, policy-based control, scalable                        | Internet routing and ISP connections    |

---

## **2. RIP (Routing Information Protocol)**

| **Command**                    | **Explanation**                                  |
|--------------------------------|--------------------------------------------------|
| `router rip`                   | Enables RIP on the router                        |
| `version 2`                    | Configures RIP to use Version 2 for subnetting   |
| `network [network]`            | Advertises a specific network in RIP             |
| `passive-interface [int]`      | Prevents RIP updates from being sent on an interface |
| `show ip rip database`         | Displays routes learned through RIP              |

### **Configuration Example**
```bash
router rip
version 2
network 192.168.1.0
passive-interface GigabitEthernet0/1
```

---

## **3. EIGRP (Enhanced Interior Gateway Routing Protocol)**

| **Command**                    | **Explanation**                                      |
|--------------------------------|------------------------------------------------------|
| `router eigrp [ASN]`           | Enables EIGRP with an Autonomous System Number (ASN) |
| `network [network]`            | Advertises a network                                |
| `bandwidth [kbits]`            | Sets bandwidth metric on an interface               |
| `show ip eigrp neighbors`      | Displays EIGRP neighbors                            |
| `show ip eigrp topology`       | Shows the EIGRP topology table                      |

### **Configuration Example**
```bash
router eigrp 100
network 10.0.0.0
passive-interface GigabitEthernet0/1
```

---

## **4. OSPF (Open Shortest Path First)**

| **Command**                      | **Explanation**                                               |
|----------------------------------|---------------------------------------------------------------|
| `router ospf [Process-ID]`       | Starts OSPF with a specific process ID                        |
| `network [network] area [area]`  | Assigns network to an OSPF area                               |
| `passive-interface [interface]`  | Disables OSPF advertisements on an interface                  |
| `area [area-id] stub`            | Configures an area as a stub                                  |
| `show ip ospf neighbor`          | Shows OSPF neighbors and their states                         |
| `show ip ospf database`          | Displays the OSPF database                                   |

### **Configuration Example**
```bash
router ospf 1
network 10.0.0.0 0.0.0.255 area 0
passive-interface GigabitEthernet0/2
```

---

## **5. IS-IS (Intermediate System to Intermediate System)**

| **Command**                     | **Explanation**                                             |
|---------------------------------|-------------------------------------------------------------|
| `router isis`                   | Enables IS-IS on the router                                 |
| `net [NET]`                     | Sets Network Entity Title (NET)                             |
| `metric-style wide`             | Uses wide metrics for larger networks                       |
| `isis circuit-type [level]`     | Specifies IS-IS level (Level 1, Level 2)                    |
| `show clns neighbors`           | Displays IS-IS neighbors                                   |
| `show isis database`            | Shows the IS-IS database                                   |

### **Configuration Example**
```bash
router isis
net 49.0001.1921.6800.1001.00
metric-style wide
isis circuit-type level-2-only
```

---

## **6. BGP (Border Gateway Protocol)**

| **Command**                                 | **Explanation**                                                |
|---------------------------------------------|----------------------------------------------------------------|
| `router bgp [ASN]`                          | Enables BGP with an ASN                                        |
| `neighbor [IP] remote-as [ASN]`             | Configures a BGP neighbor in a specified ASN                   |
| `network [network] mask [subnet-mask]`      | Advertises a network in BGP                                    |
| `neighbor [IP] next-hop-self`               | Sets router as next-hop for a BGP peer                         |
| `show ip bgp summary`                       | Displays summary of BGP sessions                               |
| `show ip bgp neighbors`                     | Shows detailed information about BGP neighbors                 |

### **Configuration Example**
```bash
router bgp 65001
neighbor 192.168.2.1 remote-as 65002
network 203.0.113.0 mask 255.255.255.0
```

---

## **Dynamic Routing Protocols Comparison Table**

| **Feature**                | **RIP**                   | **EIGRP**                         | **OSPF**                      | **IS-IS**                     | **BGP**                              |
|----------------------------|---------------------------|-----------------------------------|-------------------------------|--------------------------------|---------------------------------------|
| **Protocol Type**          | Distance Vector           | Hybrid                            | Link-State                    | Link-State                     | Path Vector                           |
| **Metric**                 | Hop Count (Max 15)        | Bandwidth and Delay               | Cost (Bandwidth-based)        | Cost                           | Path attributes                       |
| **Convergence Speed**      | Slow                      | Fast                              | Fast                          | Fast                           | Slow (depends on network size)        |
| **Scalability**            | Small Networks            | Large Networks                    | Very Large Networks           | Very Large Networks            | Internet-scale, very large networks   |
| **Administrative Distance**| 120                       | 90 (internal)                     | 110                           | 115                            | 20 (eBGP), 200 (iBGP)                 |
| **Standard**               | Open                      | Cisco Proprietary                 | Open                          | Open                           | Open                                  |
| **Configuration Complexity** | Simple                  | Moderate                          | Complex                       | Complex                        | Complex                               |
| **Loop Prevention**        | Split Horizon, Route Poisoning | Feasible Successor          | LSA Sequencing               | LSP Sequencing                 | AS Path attribute                     |
| **Best Use Case**          | Small office networks     | Cisco-based enterprise networks   | Large and complex networks    | ISP backbone networks         | ISPs, WANs, global internet routing   |

---

This extended cheat sheet covers the essentials for configuring, understanding, and choosing among the main dynamic routing protocols used in network environments.
