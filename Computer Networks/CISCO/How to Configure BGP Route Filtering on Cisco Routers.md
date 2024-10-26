Configuring BGP (Border Gateway Protocol) route filtering on Cisco routers allows you to control which routes are advertised to or received from BGP peers. Here's a step-by-step guide:

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

### Step 4: Configure BGP Process

```shell
router bgp <AS-number>
```

Replace `<AS-number>` with your BGP Autonomous System number.

Example:

```shell
router bgp 65001
```

### Step 5: Configure Route Filtering

#### To Filter Routes Advertised to a Neighbor:

```shell
neighbor <neighbor-IP> filter-list <access-list> out
```

Replace `<neighbor-IP>` with the IP address of the BGP neighbor, and `<access-list>` with the name or number of the access list.

Example:

```shell
neighbor 192.168.1.2 filter-list 1 out
```

#### To Filter Routes Received from a Neighbor:

```shell
neighbor <neighbor-IP> filter-list <access-list> in
```

Replace `<neighbor-IP>` with the IP address of the BGP neighbor, and `<access-list>` with the name or number of the access list.

Example:

```shell
neighbor 192.168.1.2 filter-list 2 in
```

### Step 6: Create Access Lists

```shell
ip access-list <standard|extended> <access-list-number>
```

Replace `<standard|extended>` with the type of access list (standard or extended), and `<access-list-number>` with the access list number.

Example:

```shell
ip access-list standard 1
```

### Step 7: Define the Access List Rules

```shell
<permit|deny> <source> <wildcard> [<destination> <wildcard>]
```

Replace `<permit|deny>` with the action (permit or deny), `<source>` with the source IP address or network, `<wildcard>` with the corresponding wildcard mask, and optionally specify the `<destination>` and `<wildcard>`.

Example:

```shell
permit 192.168.1.0 0.0.0.255
```

### Step 8: Save Configuration

```shell
write memory
```

or

```shell
copy running-config startup-config
```

### Important Notes:

- Route filtering should be used carefully to avoid unintentional traffic disruptions.

- Be cautious when filtering routes, as it can lead to suboptimal routing or blackholing of traffic.

- Ensure that the access lists match the intended routes you want to filter.

- Always consult the documentation for your specific router model and IOS version if you encounter any issues. The exact commands and syntax might vary depending on the specific Cisco router model and IOS version you are using.
