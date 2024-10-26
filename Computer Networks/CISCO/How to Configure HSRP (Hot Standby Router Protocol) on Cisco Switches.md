Configuring Hot Standby Router Protocol (HSRP) on Cisco switches allows you to provide high availability and redundancy for network services like default gateways. Here's a step-by-step guide on how to set up HSRP:

### Step 1: Access the Switch's CLI

Connect to your Cisco switch using a console cable or through SSH/Telnet.

### Step 2: Enter Privileged Exec Mode

```shell
enable
```

Provide the enable password if prompted.

### Step 3: Enter Global Configuration Mode

```shell
configure terminal
```

### Step 4: Configure the HSRP Group

Create a virtual HSRP group and specify the virtual IP address and priority. The priority determines which switch will be the active router.

```shell
interface <interface-type> <interface-number>
hsrp <group-number> ip <virtual-ip>
hsrp <group-number> priority <priority>
```

Example:

```shell
interface Vlan1
hsrp 1 ip 192.168.1.1
hsrp 1 priority 110
```

### Step 5: Specify the Standby Router

```shell
hsrp <group-number> standby <standby-ip>
```

Example:

```shell
hsrp 1 standby 192.168.1.2
```

### Step 6: Set Preemption (Optional)

By default, the router with the highest priority becomes the active router. If you want the original active router to take back control when it recovers, enable preemption:

```shell
hsrp <group-number> preempt
```

### Step 7: Save Configuration

```shell
write memory
```

or

```shell
copy running-config startup-config
```

### Step 8: Verify HSRP Configuration

Use the command `show standby` to verify the HSRP configuration and status.

### Step 9: Test HSRP Failover

Verify that the HSRP failover occurs correctly by testing connectivity to the virtual IP address.

### Important Notes:

- Remember to replace placeholders like `<interface-type> <interface-number>`, `<group-number>`, `<virtual-ip>`, `<priority>`, `<standby-ip>`, etc., with your actual values.

- HSRP works on Layer 3 interfaces (like VLAN interfaces), not physical ports. Make sure you're configuring the correct interface type and number.

- The priority value can range from 1 to 255. The higher the priority, the more likely the router is to become the active router.

- Verify that both switches have IP connectivity to each other on the same VLAN for HSRP to function properly.

The exact commands and syntax might vary depending on the specific Cisco switch model and IOS version you are using. Always consult the documentation for your specific switch if you encounter any issues.
