### **Using Stem Library to Retrieve Tor Network Status: Explanation**

This Python script demonstrates how to use the `stem` library to connect to the Tor control port, authenticate, and retrieve information about Tor network router entries.

### **1. Importing the Required Module:**
```python
from stem.control import Controller
```

The script imports the `Controller` class from the `stem.control` module.

### **2. Connecting to Tor Control Port and Authenticating:**
```python
controller = Controller.from_port(port=9051)
controller.authenticate()
```

An instance of the `Controller` class is created, connecting to the Tor control port on `localhost:9051`. The `authenticate` method is called to authenticate with the Tor control port.

### **3. Retrieving and Printing Tor Network Status:**
```python
entries = controller.get_network_statuses()
for routerEntry in entries:
    print('Nickname:', routerEntry.nickname)
    print('Fingerprint:', routerEntry.fingerprint)
```

The `get_network_statuses` method is used to retrieve a list of network statuses, representing Tor routers. A loop iterates over the router entries, and information such as nickname and fingerprint is printed for each router.

### **Explanation Summary:**
- The script uses the `stem` library to connect to the Tor control port and authenticate.
- The `get_network_statuses` method is utilized to fetch information about Tor network router entries.
- Information such as nickname and fingerprint is printed for each router in the retrieved network statuses.

### **Note:**
Make sure to have the `stem` library installed (`pip install stem`) before running this script. Additionally, ensure that Tor is running and the control port is accessible for successful execution.
