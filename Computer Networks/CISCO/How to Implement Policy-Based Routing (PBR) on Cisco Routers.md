Policy-Based Routing (PBR) is a technique used in Cisco routers to route traffic based on defined policies, rather than relying solely on the destination IP address. Here's a step-by-step guide on how to implement PBR:

### Step 1: Access the Router's CLI

Connect to your Cisco router using a console cable or through SSH/Telnet.

### Step 2: Enter Privileged Exec Mode

```
enable
```

Provide the enable password if prompted.

### Step 3: Enter Global Configuration Mode

```
configure terminal
```

### Step 4: Create an Access Control List (ACL)

Create an access list that defines the traffic you want to apply PBR to. This could be based on various criteria like source IP address, source port, protocol, etc.

```
access-list <access-list-number> <permit|deny> <protocol> <source> <source-wildcard> <destination> <destination-wildcard>
```

Example:

```
access-list 10 permit tcp 192.168.1.0 0.0.0.255 any eq 80
```

This allows HTTP traffic from the 192.168.1.0/24 subnet.

### Step 5: Create a Route Map

```
route-map <name> <permit|deny> <sequence-number>
```

- `<name>`: A name to identify the route map.
- `<permit|deny>`: Specifies whether to permit or deny routes matching the criteria.
- `<sequence-number>`: A numerical value to determine the order of execution.

Example:

```
route-map MY_ROUTE_MAP permit 10
```

### Step 6: Enter Route Map Configuration Mode

```
route-map <name> <sequence-number>
```

Example:

```
route-map MY_ROUTE_MAP 10
```

### Step 7: Set Next Hop or Exit Interface

Define the next hop or exit interface that traffic matching the ACL should be sent to.

- To set a next hop IP address:

  ```
  set ip next-hop <next-hop-ip>
  ```

  Example:

  ```
  set ip next-hop 203.0.113.1
  ```

- To set the exit interface:

  ```
  set interface <interface>
  ```

  Example:

  ```
  set interface FastEthernet0/0
  ```

### Step 8: Apply the Route Map

Apply the route map to the interface where the traffic originates:

```
interface <interface>
```

```
ip policy route-map <name>
```

Example:

```
interface FastEthernet0/1
```

```
ip policy route-map MY_ROUTE_MAP
```

### Step 9: Save Configuration

```
write memory
```

or

```
copy running-config startup-config
```

### Step 10: Verify PBR Configuration

You can use the `show ip policy` command to view the configured route maps and their associated interfaces.

### Step 11: Test PBR

Verify that traffic matching the criteria in your ACL is being routed according to your policy.

Remember to replace placeholders like `<access-list-number>`, `<name>`, `<protocol>`, `<source>`, `<source-wildcard>`, `<destination>`, `<destination-wildcard>`, `<next-hop-ip>`, `<interface>`, etc., with your actual values. The exact commands and syntax might vary depending on the specific Cisco router model and IOS version you are using. Always consult the documentation for your specific router if you encounter any issues.
