Port Mirroring, also known as Switched Port Analyzer (SPAN), is a feature on Cisco switches that allows you to monitor traffic on one or more ports by forwarding a copy of the traffic to a designated monitoring port. Here's a step-by-step guide to implementing Port Mirroring on Cisco switches:

### Step 1: Access the Switch CLI

Connect to the Cisco switch using a console cable or through SSH/Telnet.

### Step 2: Enter Privileged Exec Mode

```shell
enable
```

Provide the enable password if prompted.

### Step 3: Enter Global Configuration Mode

```shell
configure terminal
```

### Step 4: Create a VLAN for SPAN Traffic (Optional)

While not strictly necessary, it's recommended to segregate SPAN traffic to a dedicated VLAN. This step may be skipped if you choose to use an existing VLAN.

```shell
vlan <vlan-number>
```

Replace `<vlan-number>` with a unique VLAN ID.

### Step 5: Define the Monitoring Session

```shell
monitor session <session-number> source interface <source-interface> both
```

- Replace `<session-number>` with a unique session number.
- Replace `<source-interface>` with the interface(s) you want to monitor. Use a comma to separate multiple interfaces (e.g., `GigabitEthernet0/1, GigabitEthernet0/2`).

### Step 6: Set the Destination (Monitor) Interface

```shell
monitor session <session-number> destination interface <monitor-interface>
```

- Replace `<session-number>` with the session number you assigned in the previous step.
- Replace `<monitor-interface>` with the interface where you want to receive the mirrored traffic.

### Step 7: (Optional) Specify VLAN for SPAN Traffic

If you created a dedicated VLAN for SPAN traffic in Step 4, assign it to the monitor session:

```shell
monitor session <session-number> filter vlan <vlan-number>
```

- Replace `<session-number>` with the session number.
- Replace `<vlan-number>` with the VLAN ID you created in Step 4.

### Step 8: Exit Configuration Mode

```shell
exit
```

### Step 9: Save Configuration

```shell
write memory
```

### Step 10: Verify the Configuration

You can use the following command to check the status and settings of the SPAN session:

```shell
show monitor session <session-number>
```

### Important Notes:

- Port Mirroring can have a performance impact on the switch, especially if monitoring a high amount of traffic. Use it judiciously.

- Verify that the monitoring port is properly connected to the monitoring device (e.g., a packet sniffer or monitoring tool).

- Ensure that the destination interface has sufficient bandwidth to handle the mirrored traffic.

- Be cautious when applying SPAN on production networks, as it may impact network performance.

- Consult the documentation for your specific switch model and IOS version if you encounter any issues. The exact commands and syntax might vary depending on the specific Cisco switch model and IOS version you are using.
