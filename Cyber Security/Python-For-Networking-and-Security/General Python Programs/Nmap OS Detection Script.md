### Nmap OS Detection Script

This Python script uses the `nmap` library to perform OS detection on a specified host. It also lists open ports along with their descriptions.

### 1. Importing Required Modules:

```python
import nmap
import sys
```

### 2. Command-Line Usage Information:

```python
command = "OS_detection.py <hostname/IP address>"

if len(sys.argv) == 1:
    print(command)
    sys.exit()
```

### 3. Scanning and Displaying Open Ports:

```python
host = sys.argv[1]
portScanner = nmap.PortScanner()
open_ports_dict =  portScanner.scan(host, arguments="-O -v")

if open_ports_dict is not None:
    open_ports_dict = open_ports_dict.get("scan").get(host).get("tcp")

    print("Open ports  Description")
    port_list = open_ports_dict.keys()
    for port in port_list:
        print(port, "---\t-->",open_ports_dict.get(port)['name'])
```

### 4. Displaying OS Details:

```python
    print("\n--------------OS details---------------------\n")
    print("Details about the scanned host are: \t", portScanner[host]['osmatch'][0]['osclass'][0]['cpe'])
    print("Operating system family is: \t\t", portScanner[host]['osmatch'][0]['osclass'][0]['osfamily'])
    print("Type of OS is: \t\t\t\t", portScanner[host]['osmatch'][0]['osclass'][0]['type']) 
    print("Generation of Operating System :\t", portScanner[host]['osmatch'][0]['osclass'][0]['osgen'])
    print("Operating System Vendor is:\t\t", portScanner[host]['osmatch'][0]['osclass'][0]['vendor'])
    print("Accuracy of detection is:\t\t", portScanner[host]['osmatch'][0]['osclass'][0]['accuracy'])
```

### Notes:

- The script first checks if the user has provided a hostname or IP address as a command-line argument. If not, it prints the command usage information and exits.
- It then uses the `nmap` library to perform a scan with OS detection (`-O`) and verbose (`-v`) options.
- The script prints the open ports along with their descriptions.
- Finally, it displays details about the detected operating system, including CPE (Common Platform Enumeration), OS family, type, generation, vendor, and accuracy of detection.

Ensure you have the necessary permissions before scanning any network or system.
