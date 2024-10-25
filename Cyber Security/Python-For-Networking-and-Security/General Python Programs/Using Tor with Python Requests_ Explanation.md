### **Using Tor with Python Requests: Explanation**

This Python script demonstrates how to use the Requests library to make HTTP requests through the Tor network. It sets up a Tor session and sends requests through Tor, allowing you to access websites with increased anonymity.

### **Function: `get_tor_session()`**
```python
def get_tor_session():
    session = requests.session()
    # Tor uses the 9050 port as the default socks port
    session.proxies = {'http':  'socks5://127.0.0.1:9050',
                       'https': 'socks5://127.0.0.1:9050'}
    return session
```

This function creates a new Requests session and configures it to use the Tor network. It sets the session's proxies to use the Tor SOCKS5 proxy at `127.0.0.1:9050`.

### **Print Normal Public IP:**
```python
print("Normal Public IP:", requests.get("http://httpbin.org/ip").text)
```

This line makes a regular HTTP request to [http://httpbin.org/ip](http://httpbin.org/ip) to get the public IP address without using Tor. It serves as a baseline for comparison.

### **Print IP for Tor Connection:**
```python
# Make a request through the Tor connection
# IP visible through Tor
session = get_tor_session()
print("IP for Tor connection:", session.get("http://httpbin.org/ip").text)
# Above should print an IP different than your public IP
```

Here, a request is made through the Tor connection, and the resulting IP address is printed. This IP should be different from the public IP obtained in the previous step, demonstrating that the request is being routed through the Tor network.

### **Accessing .onion Website:**
```python
response = session.get('https://www.facebookcorewwwi.onion/')
```

This line sends a GET request to the Facebook onion service, which is accessible only through the Tor network. It demonstrates how to access .onion websites using the Tor-configured session.

### **Print Headers:**
```python
#get headers dictionary response
for key, value in response.headers.items():
    print(key, value)
```

This loop prints the headers of the response from the .onion website. Headers may contain information about the server, content type, and other details.

This script illustrates how to use Tor with Python's Requests library to enhance anonymity while making HTTP requests. Make sure you have Tor running on your local machine (`127.0.0.1:9050`) for this script to work properly.
