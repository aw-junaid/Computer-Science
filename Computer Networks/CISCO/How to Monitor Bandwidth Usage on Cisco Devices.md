Monitoring bandwidth usage on Cisco devices involves using various commands and tools. Here are some common methods to do so:

### 1. Using the `show` Commands:

#### a. Show Interface:

```shell
show interface <interface-type> <interface-number>
```

Replace `<interface-type> <interface-number>` with the specific interface you want to monitor. Look for the "input rate" and "output rate" fields to see the current traffic rates.

#### b. Show Interface Summary:

```shell
show interface summary
```

This command provides a summary view of all interfaces and their current status, including input and output rates.

#### c. Show Traffic:

```shell
show traffic
```

This command displays traffic statistics for each interface, including input and output packets.

### 2. Using NetFlow:

NetFlow allows you to collect and analyze traffic data on a Cisco router. To set up NetFlow, you'll need to configure flow exporting and collect data with a NetFlow collector or analyzer.

### 3. Using SNMP (Simple Network Management Protocol):

You can enable SNMP on your Cisco device and use an SNMP management tool to monitor bandwidth usage. Configure the SNMP community strings and access permissions for security.

### 4. Using Embedded Packet Capture (EPC):

EPC allows you to capture traffic directly on the router. You can then analyze the captured packets to understand the traffic patterns.

### 5. Using Cisco Prime Infrastructure:

Cisco Prime Infrastructure is a network management tool that provides comprehensive monitoring capabilities, including bandwidth usage. It offers a user-friendly graphical interface for monitoring and managing Cisco devices.

### 6. Using Cisco NetFlow Traffic Analyzer (NTA):

NTA is a part of the SolarWinds suite of network management tools. It provides detailed visibility into network traffic patterns using NetFlow data.

### Important Notes:

- When using monitoring tools like SNMP, ensure that the community strings are secure to prevent unauthorized access.

- Depending on the specific model and IOS version of your Cisco device, some commands and tools may vary. Always consult the documentation for your specific router or switch.

- Regularly monitoring bandwidth usage helps in identifying potential issues and optimizing network performance.
