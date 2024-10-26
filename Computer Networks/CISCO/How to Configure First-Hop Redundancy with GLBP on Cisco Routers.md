Configuring Gateway Load Balancing Protocol (GLBP) on Cisco routers allows for first-hop redundancy, providing automatic failover in case of a router or interface failure. Here's a step-by-step guide on how to set up GLBP:

### Step 1: Access the Router's CLI

Connect to your Cisco router using a console cable or through SSH/Telnet.

### Step 2: Enter Privileged Exec Mode

```shell
enable
```

Provide the enable password if prompted.

### Step 3: Enter Global Configuration Mode

```shell
configure terminal
```

### Step 4: Create GLBP Group

```shell
interface <interface-type> <interface-number>
glbp <group-number> ip <virtual-ip>
```

Replace `<interface-type> <interface-number>` with the interface you want to enable GLBP on (e.g., `FastEthernet0/0`). `<group-number>` is the GLBP group number (1 to 1024), and `<virtual-ip>` is the virtual IP address that will serve as the default gateway.

Example:

```shell
interface FastEthernet0/0
glbp 1 ip 192.168.1.1
```

### Step 5: Configure GLBP Priority (Optional)

If you want to set a specific router as the primary, you can adjust the priority. The router with the highest priority becomes the AVG (Active Virtual Gateway).

```shell
glbp <group-number> priority <priority>
```

Example:

```shell
glbp 1 priority 150
```

### Step 6: Set GLBP Preemption (Optional)

By default, preemption is enabled, meaning that the original AVG will regain control when it recovers from a failure. If you want to disable this:

```shell
glbp <group-number> preempt
```

### Step 7: Save Configuration

```shell
write memory
```

or

```shell
copy running-config startup-config
```

### Step 8: Verify GLBP Configuration

Use the command `show glbp` to verify the GLBP configuration and status.

### Important Notes:

- GLBP is most effective in environments with multiple routers on the same LAN.

- The virtual IP address should be in the same subnet as the physical interfaces participating in GLBP.

- Make sure all routers in the GLBP group have consistent configurations and authentication settings.

The exact commands and syntax might vary depending on the specific Cisco router model and IOS version you are using. Always consult the documentation for your specific router if you encounter any issues.
