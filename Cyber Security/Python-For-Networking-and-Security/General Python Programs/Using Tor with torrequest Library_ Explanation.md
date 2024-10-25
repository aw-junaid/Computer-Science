### **Using Tor with `torrequest` Library: Explanation**

This Python script demonstrates how to use the `torrequest` library, a wrapper around the `requests` library, to interact with the Tor network. It allows you to send HTTP requests through Tor, enhancing privacy and anonymity.

### **Setting Up TorRequest:**
```python
from torrequest import TorRequest

# Establish a TorRequest session
with TorRequest(proxy_port=9050, ctrl_port=9051, password=None) as tr:
```

This code snippet creates a TorRequest session. The `proxy_port` and `ctrl_port` parameters specify the Tor SOCKS5 proxy and the Tor control port, respectively.

### **Sending a Request and Printing IP:**
```python
    response = tr.get('http://ipecho.net/plain')
    print(response.text)  # not your IP address
```

Here, a GET request is made to [http://ipecho.net/plain](http://ipecho.net/plain) to obtain the current public IP address through Tor. The response is then printed, demonstrating that the request is routed through the Tor network.

### **Accessing Underlying Stem Controller and Resetting Identity:**
```python
    # TorRequest object also exposes the underlying Stem controller 
    # and Requests session objects for more flexibility.
    print(type(tr.ctrl))            # a stem.control.Controller object

    # Reset the Tor identity
    tr.reset_identity()
```

This part of the code showcases additional functionalities. It prints the type of the underlying Stem controller object (`tr.ctrl`) and resets the Tor identity. Resetting the identity means establishing a new circuit in the Tor network, effectively changing the IP address.

### **Sending Another Request After Identity Reset:**
```python
    response = tr.get('http://ipecho.net/plain')
    print(response.text)  # another IP address
```

After resetting the Tor identity, a new GET request is made to [http://ipecho.net/plain](http://ipecho.net/plain), and the response is printed. This IP address should differ from the one obtained in the previous request, showcasing the change in identity.

### **Explanation Summary:**
- The script demonstrates how to use the `torrequest` library to send requests through the Tor network.
- It showcases the ability to reset the Tor identity, providing a new IP address for enhanced anonymity.
- The `TorRequest` object exposes the underlying Stem controller, allowing for additional flexibility and control over Tor-related functionalities.

Ensure that you have Tor running on your local machine (`127.0.0.1:9050` and `127.0.0.1:9051`) for this script to work correctly.
