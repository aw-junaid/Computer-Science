### Asynchronous Nmap Scanner with Command-Line Arguments

This Python script uses the `nmap` library to perform asynchronous scanning on specified ports of a target host. It accepts command-line arguments for the target host (`--host`) and target ports (`--ports`). The default ports are set to 80 and 8080.

### 1. Importing Required Modules:

```python
import nmap
import argparse
```

### 2. Callback Function to Print Scan Results:

```python
def callbackResult(host, scan_result):
    port_state = scan_result['scan'][host]['tcp']
    print("Command line:"+ scan_result['nmap']['command_line'])
    for key, value in port_state.items():
        print('Port {0} --> {1}'.format(key, value))
```

### 3. Asynchronous Nmap Scanner Class:

```python
class NmapScannerAsync:
    def __init__(self):
        self.portScannerAsync = nmap.PortScannerAsync()

    def scanning(self):
        while self.portScannerAsync.still_scanning():
            print("Scanning >>>")
            self.portScannerAsync.wait(5)

    def nmapScanAsync(self, hostname, port):
        try:
            print("Checking port "+ port +" ..........")
            self.portScannerAsync.scan(hostname, arguments="-A -sV -p"+port ,callback=callbackResult)
            self.scanning()
        except Exception as exception:
            print("Error connecting to " + hostname + " for port scanning",str(exception))
```

### 4. Main Block with Command-Line Argument Parsing:

```python
if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Asynchronous Nmap scanner')
    parser.add_argument("--host", dest="host", help="target IP / domain", required=True)
    parser.add_argument("-ports", dest="ports", help="Specify the target port(s) separated by comma[80,8080 by default]", default="80,8080")
    parsed_args = parser.parse_args()
    port_list = parsed_args.ports.split(',')
    host = parsed_args.host
    for port in port_list:
        NmapScannerAsync().nmapScanAsync(host, port)
```

### Usage:

- Run the script with the `--host` argument to specify the target host.
- Optionally, use the `-ports` argument to specify the target ports separated by commas (default is "80,8080").

```bash
python script.py --host example.com -ports 80,443
```

Ensure you have the necessary permissions before scanning any network or system.
