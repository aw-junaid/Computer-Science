### Purpose of the Code
The provided Python script is designed to perform a simple multi-threaded port scan on a given host. It uses the `socket` and `optparse` modules to create a basic command-line tool for scanning open ports on a target machine.

### Import Statements
```python
#!/usr/bin/python

import optparse
from socket import *
from threading import *
```
1. **Shebang Line:** Specifies the interpreter to be used for running the script.
2. **Import Statements:**
   - `optparse`: Used for parsing command-line options and arguments.
   - `socket`: Provides low-level networking functionality.
   - `Thread` from `threading`: Enables the use of threads for concurrent execution.

### Socket Scan Function
```python
def socketScan(host, port):
    try:
        socket_connect = socket(AF_INET, SOCK_STREAM)
        socket_connect.settimeout(5)
        result = socket_connect.connect((host, port))
        print('[+] %d/tcp open' % port)
    except Exception as exception:
        print('[-] %d/tcp closed' % port)
        print('[-] Reason:%s' % str(exception))
    finally:
        socket_connect.close()
```
1. **Function Definition:** `socketScan` function is defined to check whether a given port is open on the specified host.
2. **Socket Creation:** Creates a socket using `socket(AF_INET, SOCK_STREAM)`.
3. **Connection Attempt:** Attempts to connect to the specified host and port.
4. **Prints Result:** Prints whether the port is open or closed and, in case of closure, prints the reason.

### Port Scanning Function
```python
def portScanning(host, ports):
    try:
        ip = gethostbyname(host)
        print('[+] Scan Results for: ' + ip)
    except:
        print("[-] Cannot resolve '%s': Unknown host" % host)
        return

    for port in ports:
        t = Thread(target=socketScan, args=(ip, int(port)))
        t.start()
```
1. **Function Definition:** `portScanning` function is defined to initiate the port scanning process.
2. **Host Resolution:** Resolves the host to its IP address using `gethostbyname`.
3. **Prints Scan Information:** Prints the scan results, including the target IP address.
4. **Threaded Port Scanning:** Iterates through the specified ports and creates a new thread for each port using `Thread`. Each thread runs the `socketScan` function.

### Main Function
```python
def main():
    parser = optparse.OptionParser('socket_portScan ' + '-H <Host> -P <Port>')
    parser.add_option('-H', dest='host', type='string', help='specify host')
    parser.add_option('-P', dest='port', type='string', help='specify port[s] separated by comma')

    (options, args) = parser.parse_args()

    host = options.host
    ports = str(options.port).split(',')

    if (host == None) | (ports[0] == None):
        print(parser.usage)
        exit(0)

    portScanning(host, ports)


if __name__ == '__main__':
    main()
```
1. **Main Function Definition:** `main` function is defined to handle command-line options and initiate the port scanning process.
2. **Option Parsing:** Uses `optparse.OptionParser` to parse command-line options for host and port.
3. **Command-line Argument Extraction:** Extracts the host and port values from the command line.
4. **Input Validation:** Checks if both host and at least one port are provided; if not, prints usage information and exits.
5. **Port Scanning Initiation:** Calls the `portScanning` function with the provided host and port values.

### Execution Trigger
```python
if __name__ == '__main__':
    main()
```
Ensures that the `main` function is called when the script is executed directly.

### Summary
This script is a basic command-line tool for multi-threaded port scanning. It takes a target host and a list of ports as input, resolves the host, and then concurrently checks the status of each port using threads. The results are printed on the console.
