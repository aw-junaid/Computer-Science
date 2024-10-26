VTP (VLAN Trunking Protocol) pruning is a feature in Cisco switches that helps optimize the use of trunk links by forwarding broadcast and unknown unicast frames only to the switches that have active ports in the respective VLANs. Here's how you can set up VTP pruning:

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

### Step 4: Enable VTP

If VTP is not already enabled, you should enable it and specify the VTP mode:

```shell
vtp mode <server|client|transparent>
```

### Step 5: Enable VTP Pruning

```shell
vtp pruning
```

### Step 6: Save Configuration

```shell
write memory
```

or

```shell
copy running-config startup-config
```

### Step 7: Verify VTP Pruning Configuration

Use the command `show vtp status` to verify that VTP pruning is enabled.

### Important Notes:

- VTP pruning should be enabled on all switches in the VTP domain to work effectively.

- VTP pruning works in conjunction with VTP. Make sure you have configured the correct VTP domain and mode.

- VTP pruning is most effective in environments with multiple access switches and a distribution/aggregation layer.

The exact commands and syntax might vary depending on the specific Cisco switch model and IOS version you are using. Always consult the documentation for your specific switch if you encounter any issues.
