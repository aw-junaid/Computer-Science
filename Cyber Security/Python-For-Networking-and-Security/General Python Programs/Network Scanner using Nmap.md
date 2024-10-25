### Network Scanner using Nmap

This Python script utilizes the `nmap` library to perform a network scan on a specified host. It checks the status and state of common ports (21, 22, 23, 25, 80) for the specified host.

### 1. Importing Required Modules:

```python
import nmap
```

### 2. Network Scanner Function:

```python
def network_scanner():
    # Create an instance of the nmap PortScanner
    port_scanner = nmap.PortScanner()

    # Get user input for the target host
    host_scan = input('Host scan: ')

    # Define a list of ports to scan
    port_list = "21,22,23,25,80"

    # Perform the network scan with nmap
    port_scanner.scan(hosts=host_scan, arguments='-n -p' + port_list)

    # Print the command line used for the scan
    print(port_scanner.command_line())

    # Extract and display information about the scanned hosts
    hosts_list = [(x, port_scanner[x]['status']['state']) for x in port_scanner.all_hosts()]
    for host, status in hosts_list:
        print(host, status)

    # Display information about open ports for each scanned host
    for protocol in port_scanner[host].all_protocols():
        print('Protocol : %s' % protocol)
        list_ports = port_scanner[host][protocol].keys()
        for port in list_ports:
            print('Port : %s State : %s' % (port, port_scanner[host][protocol][port]['state']))


if __name__ == '__main__':
    # Execute the network scanner function
    network_scanner()
```

### Notes:

- The script prompts the user for the target host to scan.
- It specifies a list of common ports (21, 22, 23, 25, 80) to check for each host.
- The `nmap` library is used to perform the scan and retrieve information about the scanned hosts and open ports.
- This script is for educational purposes only. Ensure you have the appropriate permissions before scanning any network or system.
