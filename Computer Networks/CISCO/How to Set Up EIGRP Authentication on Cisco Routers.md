Setting up EIGRP (Enhanced Interior Gateway Routing Protocol) authentication on Cisco routers helps secure routing information exchanged between EIGRP neighbors. Here's a step-by-step guide:

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

### Step 4: Enable EIGRP on the Interface

```shell
router eigrp <AS-number>
network <network-address> <wildcard-mask>
```

Replace `<AS-number>` with your EIGRP Autonomous System number, `<network-address>` with the network address you want to advertise, and `<wildcard-mask>` with the corresponding wildcard mask.

Example:

```shell
router eigrp 100
network 192.168.1.0 0.0.0.255
```

### Step 5: Enable EIGRP Authentication

```shell
interface <interface-type> <interface-number>
ip authentication mode eigrp <AS-number> md5
ip authentication key-chain eigrp <AS-number> <key-chain-name>
```

Replace `<AS-number>` with your EIGRP Autonomous System number, `<interface-type> <interface-number>` with the specific interface, and `<key-chain-name>` with the name of the key chain.

Example:

```shell
interface GigabitEthernet0/0
ip authentication mode eigrp 100 md5
ip authentication key-chain eigrp 100 MY_KEY_CHAIN
```

### Step 6: Create a Key Chain

```shell
key chain <key-chain-name>
key <key-number>
key-string <key-string>
```

Replace `<key-chain-name>` with the name you used in the previous step, `<key-number>` with the number of the key, and `<key-string>` with the actual authentication key.

Example:

```shell
key chain MY_KEY_CHAIN
key 1
key-string MySecretKey
```

### Step 7: Save Configuration

```shell
write memory
```

or

```shell
copy running-config startup-config
```

### Important Notes:

- Ensure that the same key chain name and key number are used on all routers in the EIGRP network.

- Both routers must use the same authentication mode and key-string for EIGRP adjacency to form.

- Always consult the documentation for your specific router model and IOS version if you encounter any issues. The exact commands and syntax might vary depending on the specific Cisco router model and IOS version you are using.
