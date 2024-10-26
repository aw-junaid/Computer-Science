Setting up Frame Relay on Cisco routers involves configuring the necessary interfaces, map statements, and addressing. Frame Relay is a packet-switched wide-area network (WAN) technology. Below are the steps to set up Frame Relay:

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

### Step 4: Configure the Physical Interfaces

You'll need to configure the physical interfaces that connect to the Frame Relay network. In this example, we'll assume you have two interfaces: Serial0/0/0 and Serial0/0/1.

```shell
interface Serial0/0/0
  encapsulation frame-relay
  ip address <interface-ip> <subnet-mask>
  frame-relay interface-dlci <dlci>
```

```shell
interface Serial0/0/1
  encapsulation frame-relay
  ip address <interface-ip> <subnet-mask>
  frame-relay interface-dlci <dlci>
```

Replace `<interface-ip>`, `<subnet-mask>`, and `<dlci>` with your actual values.

### Step 5: Configure Frame Relay Switching

If you're using a physical Frame Relay switch, configure the switch encapsulation on the same physical interfaces as above:

```shell
interface Serial0/0/0
  encapsulation frame-relay
```

```shell
interface Serial0/0/1
  encapsulation frame-relay
```

### Step 6: Map the DLCIs to IP Addresses

Next, create map statements to associate DLCIs with IP addresses. This is done in the global configuration mode:

```shell
frame-relay map ip <next-hop-ip> <dlci> broadcast
```

Replace `<next-hop-ip>` with the IP address of the remote router, and `<dlci>` with the DLCI you want to use for this connection.

### Step 7: Set the LMI Type

Frame Relay uses Local Management Interface (LMI) to manage connections. Set the LMI type to be used on the interface:

```shell
frame-relay lmi-type cisco
```

### Step 8: Enable the Interface

```shell
interface Serial0/0/0
  no shutdown
```

```shell
interface Serial0/0/1
  no shutdown
```

### Step 9: Save Configuration

```shell
write memory
```

or

```shell
copy running-config startup-config
```

### Step 10: Verify Frame Relay Configuration

Use the `show interfaces`, `show frame-relay map`, and `show frame-relay lmi` commands to verify the configuration.

### Step 11: Test Frame Relay Connection

Verify that the Frame Relay link is established by testing connectivity between the two routers.

Please ensure that you replace placeholders like `<interface-ip>`, `<subnet-mask>`, `<dlci>`, `<next-hop-ip>`, etc., with your actual values. The exact commands and syntax might vary depending on the specific Cisco router model and IOS version you are using. Always consult the documentation for your specific router if you encounter any issues.
