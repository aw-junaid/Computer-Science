Setting up a GRE (Generic Routing Encapsulation) tunnel on Cisco routers allows you to establish a point-to-point tunnel for encapsulating various network layer protocols. Here's a step-by-step guide on how to set up GRE tunnels:

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

### Step 4: Create a Tunnel Interface

Define a tunnel interface and specify an arbitrary number (in this example, we'll use `0`):

```
interface tunnel <number>
```

Example:

```
interface tunnel 0
```

### Step 5: Configure Tunnel Source and Destination

Specify the source and destination addresses for the tunnel.

```
tunnel source <source-interface>
tunnel destination <destination-ip>
```

Example:

```
tunnel source FastEthernet0/0
tunnel destination 203.0.113.2
```

### Step 6: Assign IP Addresses to the Tunnel Interfaces

Assign IP addresses to both ends of the tunnel. These should be in the same subnet.

```
ip address <local-ip> <subnet-mask>
```

Example:

```
ip address 10.0.0.1 255.255.255.0
```

### Step 7: Configure GRE Protocol

```
tunnel mode gre ip
```

### Step 8: Enable the Tunnel Interface

```
no shutdown
```

### Step 9: Save Configuration

```
write memory
```

or

```
copy running-config startup-config
```

### Step 10: Verify GRE Tunnel Configuration

Use the command `show interface tunnel <number>` to verify the configuration of the tunnel.

### Step 11: Test GRE Tunnel

Verify that traffic can pass through the GRE tunnel. You can use ping or other testing tools to ensure connectivity.

### Important Note:

Keep in mind that GRE alone doesn't provide encryption or security features. If security is a concern, you may want to consider using IPsec in conjunction with GRE.

Remember to replace placeholders like `<number>`, `<source-interface>`, `<destination-ip>`, `<local-ip>`, `<subnet-mask>`, etc., with your actual values. The exact commands and syntax might vary depending on the specific Cisco router model and IOS version you are using. Always consult the documentation for your specific router if you encounter any issues.
