### **Static and Dynamic Routing**

Routing is the process of selecting paths in a network to send network traffic. Routers use different methods to determine the best route, with **static routing** and **dynamic routing** being the two primary approaches.

---

### **Static Routing**

Static routing is the manual configuration of routes on a router. It involves the network administrator defining the exact path that traffic should take to reach a destination network.

#### **Key Features of Static Routing**
- **Manual Configuration**: Routes are manually added and modified.
- **Fixed Routes**: The router follows the predefined path, with no automatic adjustments.
- **Simple**: Ideal for small networks with few routes or for networks where changes are infrequent.
- **Resource-Efficient**: Minimal CPU and memory usage because no dynamic routing protocol is involved.
- **Predictable**: The route remains constant unless manually changed.

#### **Advantages**
1. **Simple to configure**: Requires fewer resources, especially in small networks.
2. **More control**: Network administrators have full control over the routing decisions.
3. **Less overhead**: No periodic updates or maintenance overhead.
4. **Predictable behavior**: Routes will not change unless manually adjusted.

#### **Disadvantages**
1. **Scalability**: Becomes difficult to manage as the network grows, requiring manual updates to routes.
2. **Failure Recovery**: If a link goes down, there’s no automatic failover unless the administrator manually changes the routes.
3. **Human error**: Incorrect configurations can lead to routing loops or unreachable networks.

#### **Configuration Example (Cisco)**

```bash
Router1(config)# ip route 192.168.2.0 255.255.255.0 192.168.1.2
```

In this example:
- **192.168.2.0**: Destination network.
- **255.255.255.0**: Subnet mask.
- **192.168.1.2**: Next hop IP address.

---

### **Dynamic Routing**

Dynamic routing uses routing protocols to automatically learn about network routes and make decisions based on network conditions. Routers exchange routing information to update their routing tables.

#### **Key Features of Dynamic Routing**
- **Automatic Configuration**: Routers automatically learn and update routes.
- **Routing Protocols**: Dynamic routing relies on protocols like **RIP**, **OSPF**, and **EIGRP** to exchange information.
- **Adaptive**: Routes are adjusted in response to network changes (e.g., link failures, congestion).
- **Scalable**: Ideal for large, complex networks with frequent changes.

#### **Routing Protocols**

1. **RIP (Routing Information Protocol)**  
   - A distance-vector protocol that uses hop count as a metric.
   - Simple and used in smaller networks (limited to 15 hops).
   - **RIP v1** (classful) and **RIP v2** (classless, supports VLSM and multicast).
   - Updates every 30 seconds.

2. **OSPF (Open Shortest Path First)**  
   - A link-state protocol that uses cost (based on bandwidth) as a metric.
   - Scalable and suitable for large enterprise networks.
   - Uses **LSA (Link-State Advertisements)** to exchange routing information.
   - Converges faster than RIP.

3. **EIGRP (Enhanced Interior Gateway Routing Protocol)**  
   - A Cisco proprietary protocol, hybrid in nature (combines distance-vector and link-state features).
   - Uses **metric calculation** based on bandwidth, delay, load, and reliability.
   - More efficient than RIP and OSPF in many cases.
   - Faster convergence and supports more complex topologies.

4. **BGP (Border Gateway Protocol)**  
   - An exterior gateway protocol used for routing between different autonomous systems (ASes) on the internet.
   - Uses path vectors to make routing decisions.
   - **BGP** is the protocol that powers the internet’s routing decisions.

#### **Advantages of Dynamic Routing**
1. **Adaptability**: Automatically adjusts to network changes (failures, link fluctuations).
2. **Scalability**: Efficient for large and constantly changing networks.
3. **Redundancy and Load Balancing**: Many dynamic protocols support load balancing and backup routes.

#### **Disadvantages of Dynamic Routing**
1. **Resource Consumption**: Dynamic protocols use more CPU and memory on the routers.
2. **Complexity**: Requires more configuration and troubleshooting expertise.
3. **Convergence Time**: Depending on the protocol, it may take time to converge after a topology change.

#### **Configuration Example (Cisco)**

For **RIP**:
```bash
Router1(config)# router rip
Router1(config-router)# version 2
Router1(config-router)# network 192.168.0.0
Router1(config-router)# no auto-summary
```

For **OSPF**:
```bash
Router1(config)# router ospf 1
Router1(config-router)# network 192.168.0.0 0.0.255.255 area 0
```

---

### **Comparison Between Static and Dynamic Routing**

| Feature                   | **Static Routing**                             | **Dynamic Routing**                        |
|---------------------------|-----------------------------------------------|--------------------------------------------|
| **Configuration**          | Manual                                         | Automatic via routing protocols           |
| **Scalability**            | Difficult to manage in large networks         | Ideal for large networks                  |
| **Adaptability**           | No automatic adjustment to network changes    | Automatically adapts to network changes    |
| **Performance**            | Lower resource usage (CPU, memory)            | Higher resource usage due to protocol overhead |
| **Reliability**            | Can be less reliable if the network changes    | More reliable due to automatic route updates |
| **Examples of Protocols**  | None                                          | RIP, OSPF, EIGRP, BGP                     |
| **Failure Recovery**       | Requires manual intervention                  | Automatic failover (depends on protocol)  |
| **Convergence Time**       | N/A                                           | Varies by protocol (RIP: slow, OSPF: faster, EIGRP: fast) |

---

### **When to Use Static Routing vs. Dynamic Routing**

#### **Use Static Routing**:
- In small networks with minimal changes or a simple topology.
- For routes that rarely change, such as between two devices or in a stub network.
- To ensure control over routing paths for security or performance reasons.
  
#### **Use Dynamic Routing**:
- In larger, more complex networks that require constant adaptation to network changes.
- For networks that have redundant paths and require automatic failover.
- In situations where managing routing tables manually would be inefficient.

---
