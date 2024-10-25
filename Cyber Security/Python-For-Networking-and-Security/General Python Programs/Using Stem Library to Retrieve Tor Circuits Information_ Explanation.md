### **Using Stem Library to Retrieve Tor Circuits Information: Explanation**

This Python script demonstrates how to use the `stem` library to connect to the Tor control port, authenticate, and retrieve information about Tor circuits.

### **1. Importing the Required Module:**
```python
from stem import CircStatus
from stem.control import Controller
```

The script imports the `CircStatus` enumeration and the `Controller` class from the `stem` library.

### **2. Connecting to Tor Control Port and Authenticating:**
```python
with Controller.from_port(port=9051) as controller:
    controller.authenticate()
```

An instance of the `Controller` class is created using a context manager to ensure proper connection handling. The script connects to the Tor control port on `localhost:9051` and authenticates with the control port.

### **3. Retrieving and Printing Tor Circuits Information:**
```python
for circ in sorted(controller.get_circuits()):
    if circ.status != CircStatus.BUILT:
        continue

    print("Circuit %s (%s)" % (circ.id, circ.purpose))

    for i, entry in enumerate(circ.path):
        div = '+' if (i == len(circ.path) - 1) else '|'
        fingerprint, nickname = entry

        desc = controller.get_network_status(fingerprint, None)
        address = desc.address if desc else 'unknown'

        print(" %s- %s (%s, %s)" % (div, fingerprint, nickname, address))
```

The `get_circuits` method is used to retrieve information about Tor circuits. A loop iterates over the circuits, and for each circuit, information such as ID, purpose, and the path of relays is printed.

### **Explanation Summary:**
- The script uses the `stem` library to connect to the Tor control port and authenticate.
- The `get_circuits` method is utilized to fetch information about Tor circuits.
- Information such as circuit ID, purpose, and the path of relays in the circuit is printed for each built circuit.

### **Note:**
Make sure to have the `stem` library installed (`pip install stem`) before running this script. Additionally, ensure that Tor is running and the control port is accessible for successful execution.
