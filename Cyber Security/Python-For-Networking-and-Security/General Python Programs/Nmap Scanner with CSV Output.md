### Nmap Scanner with CSV Output

This Python script utilizes the `nmap` library to perform a network scan on a specified host and ports. It outputs the results in CSV format.

### 1. Importing Required Modules:

```python
import optparse
import nmap
import csv
```

### 2. Nmap Scanner Class:

```python
class NmapScannerCSV:
     
    def __init__(self):
        self.portScanner = nmap.PortScanner()
    
    def nmapScanCSV(self, host, ports):
        try:
            print("Checking ports "+ str(ports) +" ..........")
            self.portScanner.scan(host, arguments='-n -p'+ports)
            
            print("[*] Executing command: %s" % self.portScanner.command_line())
            
            print(self.portScanner.csv())

            print("Summary for host",host)

            with open('csv_file.csv', mode='w') as csv_file:
                csv_writer = csv.writer(csv_file, delimiter=',')
                csv_writer.writerow(['Host', 'Protocol', 'Port', 'State'])
           
                for x in self.portScanner.csv().split("\n")[1:-1]:
                    splited_line = x.split(";")
                    host = splited_line[0]
                    protocol = splited_line[5]
                    port = splited_line[4]
                    state = splited_line[6]
                    print("Protocol:",protocol,"Port:",port,"State:",state)
                    csv_writer.writerow([host, protocol, port, state])         
    
        except Exception as exception:
            print("Error connecting to " + host + " for port scanning" ,exception)
```

### 3. Main Function:

```python
def main():
    parser = optparse.OptionParser("usage%prog " + "--host <target host> --ports <target port>") 
    parser.add_option('--host', dest='host', type='string', help='Please, specify the target host.')
    parser.add_option('--ports', dest='ports', type='string', help='Please, specify the target port(s) separated by commas.')
    (options, args) = parser.parse_args()
    if (options.host == None) | (options.ports == None): 
        print('[-] You must specify a target host and target port(s).')
        exit(0)
    host = options.host
    ports = options.ports

    NmapScannerCSV().nmapScanCSV(host, ports)

if __name__ == "__main__": 
    main()
```

### Notes:

- The script defines a class `NmapScannerCSV` with a method `nmapScanCSV` for performing the scan and generating CSV output.
- The main function (`main`) parses command-line options, including the target host and ports.
- The `main` function then calls the `nmapScanCSV` method of the `NmapScannerCSV` class with the provided host and ports.
- The results are printed to the console, and a CSV file (`csv_file.csv`) is generated with information about the host, protocol, port, and state.
- Ensure you have the appropriate permissions before scanning any network or system.
