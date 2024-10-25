### Banner Grabbing Script Explanation

This Python script is designed for banner grabbing from a specified target IP and port. It sends an HTTP GET request and extracts information from the response headers.

### 1. Importing Required Modules:
```python
import socket
import argparse
import re
```
The script imports the necessary modules: `socket` for socket operations, `argparse` for parsing command-line arguments, and `re` for regular expressions.

### 2. Parsing Command-Line Arguments:
```python
parser = argparse.ArgumentParser(description='Get banner server')

# Main arguments
parser.add_argument("--target", dest="target", help="target IP", required=True)
parser.add_argument("--port", dest="port", help="port", type=int, required=True)
parsed_args = parser.parse_args()
```
The script uses `argparse` to define and parse command-line arguments. It expects the `--target` (target IP) and `--port` (target port) arguments.

### 3. Creating a Socket Connection:
```python
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect((parsed_args.target, parsed_args.port))
sock.settimeout(2)
```
A TCP socket is created, connected to the specified target IP and port, and a timeout of 2 seconds is set.

### 4. Sending an HTTP GET Request:
```python
query = "GET / HTTP/1.1\nHost: "+parsed_args.target+"\n\n"
http_get = bytes(query, 'utf-8')
```
An HTTP GET request is constructed and converted to bytes.

### 5. Reading Vulnerable Banners:
```python
data = ''
with open('vulnbanners.txt', 'r') as file:
    vulnbanners = file.readlines()
```
The script reads a file (`vulnbanners.txt`) containing vulnerable banners.

### 6. Sending HTTP GET Request and Processing Response:
```python
try:
    sock.sendall(http_get)
    data = sock.recvfrom(1024)
    data = data[0]
    print(data)

    headers = data.splitlines()

    for header in headers:
        try:
            if re.search('Server:', str(header)):
                print("*****"+header.decode("utf-8")+"*****")
            else:
                print(header.decode("utf-8"))
        except Exception as exception:
            pass
    
    for vulnbanner in vulnbanners:
        if vulnbanner.strip() in str(data.strip().decode("utf-8")):
            print('Found server vulnerable! ', vulnbanner)
            print('Target: '+str(parsed_args.target))
            print('Port: '+str(parsed_args.port))

except socket.error:
    print("Socket error", socket.errno)
finally:
    sock.close()
```

The script sends the HTTP GET request, processes the response headers, and checks for matches with known vulnerable banners. If a match is found, it prints a message indicating a vulnerable server.

### Usage:
- Run the script from the command line, providing the `--target` and `--port` arguments.
- Example: `python banner_grabber.py --target 192.168.1.1 --port 80`

### Summary:
- The script performs banner grabbing by sending an HTTP GET request and extracting information from the response headers.
- It checks for known vulnerable banners in the response and prints a message if a match is found.
- The script is useful for identifying server information and potential vulnerabilities during penetration testing.
