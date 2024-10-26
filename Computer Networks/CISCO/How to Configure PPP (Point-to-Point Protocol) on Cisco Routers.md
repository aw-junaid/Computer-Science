Configuring Point-to-Point Protocol (PPP) on Cisco routers allows you to establish a direct, secure connection between two routers. Here's a step-by-step guide on how to set up PPP:

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

### Step 4: Create a Loopback Interface (Optional)

If you don't have a physical interface available for testing, you can create a loopback interface for testing purposes:

```
interface loopback <number>
ip address <ip-address> <subnet-mask>
```

Example:

```
interface loopback 0
ip address 192.168.1.1 255.255.255.0
```

### Step 5: Create a Physical Interface (if needed)

Skip this step if you're using an existing interface. Otherwise, configure a physical interface with an IP address:

```
interface <interface-type> <interface-number>
ip address <ip-address> <subnet-mask>
```

Example:

```
interface FastEthernet0/0
ip address 192.168.0.1 255.255.255.0
```

### Step 6: Configure PPP Encapsulation

Enter the interface configuration mode for the chosen interface and configure it for PPP encapsulation:

```
interface <interface-type> <interface-number>
encapsulation ppp
```

Example:

```
interface FastEthernet0/0
encapsulation ppp
```

### Step 7: Set Authentication (Optional)

If required, configure authentication for the PPP link. You can use either PAP (Password Authentication Protocol) or CHAP (Challenge Handshake Authentication Protocol).

For PAP:

```
ppp authentication pap
```

For CHAP:

```
ppp authentication chap
```

### Step 8: Set PPP Username and Password (if using PAP)

If using PAP authentication, set the username and password for the remote router:

```
username <remote-username> password <remote-password>
```

Example:

```
username Router2 password MySecretPassword
```

### Step 9: Set PPP Authentication with CHAP (if using CHAP)

If using CHAP, configure the CHAP username and password:

```
interface <interface-type> <interface-number>
ppp chap hostname <remote-username>
ppp chap password <remote-password>
```

Example:

```
interface FastEthernet0/0
ppp chap hostname Router2
ppp chap password MySecretPassword
```

### Step 10: Enable the Interface

```
interface <interface-type> <interface-number>
no shutdown
```

Example:

```
interface FastEthernet0/0
no shutdown
```

### Step 11: Save Configuration

```
write memory
```

or

```
copy running-config startup-config
```

### Step 12: Verify PPP Configuration

Use the `show interfaces` command to verify that the PPP interface is up and running.

### Step 13: Test PPP Connection

Verify that the PPP link is established by testing connectivity between the two routers.

Remember to replace placeholders like `<interface-type> <interface-number>`, `<ip-address>`, `<subnet-mask>`, `<remote-username>`, `<remote-password>`, etc., with your actual values. The exact commands and syntax might vary depending on the specific Cisco router model and IOS version you are using. Always consult the documentation for your specific router if you encounter any issues.
