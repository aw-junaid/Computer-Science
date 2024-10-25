### **Rotating Tor IP Addresses with Socks Proxy: Explanation**

This Python script demonstrates how to use the `socks` library in conjunction with the `stem` library to connect to the Tor control port, authenticate, and rotate Tor IP addresses.

### **1. Importing the Required Modules:**
```python
import time
import socks
import socket
import requests
from stem import Signal
from stem.control import Controller
```

The script imports necessary modules, including `time` for time-related functions, `socks` for SOCKS proxy support, `socket` for socket manipulation, `requests` for making HTTP requests, and `Signal`, `Controller` from `stem` for Tor control.

### **2. Configuring Socks Proxy:**
```python
numberIPAddresses = 5
```
The variable `numberIPAddresses` is set to determine how many times the script will rotate Tor IP addresses.

### **3. Connecting to Tor Control Port and Rotating IP Addresses:**
```python
with Controller.from_port(port=9051) as controller:
    controller.authenticate()
    socks.setdefaultproxy(socks.PROXY_TYPE_SOCKS5, "127.0.0.1", 9050)
    socket.socket = socks.socksocket

    for i in range(0, numberIPAddresses):
        newIPAddress = requests.get("http://icanhazip.com").text
        print("New IP Address: %s" % newIPAddress)
        controller.signal(Signal.NEWNYM)

        if not controller.is_newnym_available():
            print("Waiting time for Tor to change IP: %d seconds" % controller.get_newnym_wait())
            time.sleep(controller.get_newnym_wait())
```
The script connects to the Tor control port, authenticates, sets the SOCKS proxy, and then iteratively rotates Tor IP addresses. It prints the new IP address obtained from "http://icanhazip.com" after each rotation.

### **4. Closing the Controller Connection:**
```python
    controller.close()
```
The connection to the Tor control port is closed after rotating the desired number of IP addresses.

### **Explanation Summary:**
- The script combines the `socks` and `stem` libraries to connect to the Tor control port, authenticate, and rotate Tor IP addresses.
- It uses the `requests` library to fetch the new IP address after each rotation.
- The script prints the new IP address and waits for Tor to change the IP if necessary.

### **Note:**
Make sure to have the `socks` and `stem` libraries installed (`pip install PySocks stem requests`) before running this script. Additionally, ensure that Tor is running and the control port is accessible for successful execution.
