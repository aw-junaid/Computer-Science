Configuring NetFlow on Cisco routers allows you to collect traffic statistics and monitor network traffic patterns. Follow these steps to set up NetFlow:

### Step 1: Access Global Configuration Mode

```shell
enable
configure terminal
```

### Step 2: Enable NetFlow on the Interface(s)

Choose the interface(s) where you want to enable NetFlow:

```shell
interface <interface-type> <interface-number>
```

Replace `<interface-type>` with the type of interface (e.g., `GigabitEthernet`, `FastEthernet`) and `<interface-number>` with the specific interface number.

Enable NetFlow on the interface:

```shell
ip flow ingress
```

### Step 3: Configure the NetFlow Export Destination

Specify the IP address and port where NetFlow records will be sent (this should be the address of your NetFlow collector):

```shell
ip flow-export destination <collector-IP> <port>
```

Replace `<collector-IP>` with the IP address of your NetFlow collector and `<port>` with the UDP port number (typically 2055).

### Step 4: Enable NetFlow Version (Optional)

By default, NetFlow version 5 is used. If you prefer to use a different version (e.g., version 9), enable it:

```shell
ip flow-export version 9
```

### Step 5: Set the Flow Cache Timeout (Optional)

Specify how long flows should be stored in the cache before being exported:

```shell
ip flow-cache timeout active <seconds>
```

Replace `<seconds>` with the desired timeout value (e.g., 60 for one minute).

### Step 6: Configure Sampling (Optional)

Sampling allows you to collect statistics on only a fraction of the traffic. This can be useful for reducing resource utilization:

```shell
ip flow-sampler <sampler-name>
  mode random <rate>
```

Replace `<sampler-name>` with a name for the sampler and `<rate>` with the sampling rate (e.g., 1 in N).

### Step 7: Apply NetFlow to the Desired Traffic (Optional)

You can apply NetFlow to specific traffic using an access list. For example, to apply NetFlow to traffic going from one subnet to another:

```shell
ip access-list extended netflow-acl
  permit ip <source-subnet> <source-wildcard> <destination-subnet> <destination-wildcard>

interface <interface-type> <interface-number>
  ip flow monitor netflow-monitor input
```

Replace `<source-subnet>`, `<source-wildcard>`, `<destination-subnet>`, and `<destination-wildcard>` with the appropriate values.

### Step 8: Exit Configuration Mode and Save

```shell
exit
write memory
```

### Step 9: Verify NetFlow Configuration

You can check the status of NetFlow on the router:

```shell
show ip cache flow
show ip flow export
```

### Important Notes:

- Ensure that your NetFlow collector is configured to receive and analyze the exported data.

- Verify that your router model and IOS version support NetFlow.

- Adjust parameters (such as sampling rate and cache timeout) based on your specific requirements and network conditions.

- Consider the potential impact on router resources when enabling NetFlow, especially on lower-end or busy routers.
