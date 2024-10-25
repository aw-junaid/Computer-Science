### **Rotating Tor Identity Using Stem Library: Explanation**

This Python script demonstrates how to use the `stem` library to connect to the Tor control port, authenticate, and periodically request a new Tor identity to rotate the Tor exit node.

### **1. Importing the Required Modules:**
```python
import time
from stem import Signal
from stem.control import Controller
import requests
```

The script imports the necessary modules, including `time` for time-related functions, `Signal` enumeration, `Controller` class from `stem` for Tor control, and the `requests` library for making HTTP requests through Tor.

### **2. Defining Functions:**
```python
def get_tor_session():
    session = requests.session()
    session.proxies = {'http':  'socks5h://127.0.0.1:9050', 'https': 'socks5h://127.0.0.1:9050'}
    return session
```
A function `get_tor_session` is defined to create a Tor session using the `requests` library with appropriate proxy settings.

### **3. Main Script:**
```python
def main():
    while True:
        time.sleep(5)  # Wait for 5 seconds
        print("Rotating IP")

        with Controller.from_port(port=9051) as controller:
            controller.authenticate()
            controller.signal(Signal.NEWNYM)  # Gets a new identity

        session = get_tor_session()
        print(session.get("http://httpbin.org/ip").text)
```
The `main` function is defined to run continuously. It sleeps for 5 seconds, then connects to the Tor control port, authenticates, and sends a `NEWNYM` signal to request a new Tor identity. It prints the IP visible through Tor after the identity rotation.

### **4. Running the Script:**
```python
if __name__ == '__main__':
    main()
```
The script is executed when run as a standalone program.

### **Explanation Summary:**
- The script uses the `stem` library to connect to the Tor control port and authenticate.
- It defines a function to create a Tor session using the `requests` library with appropriate proxy settings.
- The main loop periodically rotates the Tor identity (exit node) and prints the new IP visible through Tor.

### **Note:**
Make sure to have the `stem` and `requests` libraries installed (`pip install stem requests`) before running this script. Additionally, ensure that Tor is running and the control port is accessible for successful execution.
