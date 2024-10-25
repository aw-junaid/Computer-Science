### **Using Tor with `torpy` Library: Explanation**

This Python script demonstrates how to use the `torpy` library to send HTTP requests through the Tor network. The `torpy` library provides a simple interface for working with Tor in Python.

### **Setting Up Tor Connection:**
```python
from torpy.http.requests import TorRequests

# Establish a TorRequests session
with TorRequests() as tor_requests:
```

This code initializes a TorRequests session, creating a connection to the Tor network.

### **Building and Renewing Circuits:**
```python
    print("building circuit...")
    with tor_requests.get_session() as session:
        print(session.get("http://httpbin.org/ip").json())
    print("renewing circuit...")
    with tor_requests.get_session() as session:
        print(session.get("http://httpbin.org/ip").json())
```

Here, the script builds a Tor circuit, makes a request to [http://httpbin.org/ip](http://httpbin.org/ip), prints the obtained IP address, and then renews the circuit to obtain a new IP address. This demonstrates the ability to manage circuits for enhanced anonymity.

### **Accessing .onion Website:**
```python
    response = session.get('http://3g2upl4pq6kufc4m.onion')
    for key, value in response.headers.items():
        print(key, value)
```

This part of the code sends a request to the DuckDuckGo onion service (`.onion` domain) and prints the headers of the response. Accessing a .onion website showcases the ability to interact with Tor hidden services.

### **Explanation Summary:**
- The script uses the `torpy` library to establish a connection to the Tor network and manage Tor circuits.
- It demonstrates the process of building a circuit, making requests, and renewing the circuit to obtain a new IP address.
- Accessing a .onion website is showcased, highlighting the ability to interact with Tor hidden services.

Ensure that you have Tor running on your local machine for this script to work correctly. The `torpy` library simplifies Tor integration in Python, making it easier to work with Tor circuits and hidden services.
