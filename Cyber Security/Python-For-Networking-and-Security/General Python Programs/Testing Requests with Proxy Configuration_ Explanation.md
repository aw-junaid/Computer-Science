### **Testing Requests with Proxy Configuration: Explanation**

This Python script demonstrates how to use the `anonymize` library to enable and disable a proxy for HTTP requests using the `requests` library.

### **1. Import Libraries and Define Test URL:**
```python
import requests
from anonymize import enable_proxy, disable_proxy

# This URL returns your IP as plain text
url = 'http://icanhazip.com'
```

The script imports the necessary libraries (`requests`, `enable_proxy`, and `disable_proxy`) and defines a test URL (`http://icanhazip.com`) that returns the public IP address.

### **2. Enable and Test Requests with Proxy:**
```python
def test_requests():
    print('requests: %s' % requests.get(url).text)

enable_proxy()
test_requests()
```

The `test_requests` function sends an HTTP GET request to the specified URL and prints the response text. Before calling this function, the `enable_proxy` function is invoked, which configures the `requests` library to use a proxy.

### **3. Disable and Test Requests without Proxy:**
```python
disable_proxy()
test_requests()
```

After testing requests with the proxy enabled, the script calls `disable_proxy` to revert to the default network configuration. Subsequently, it calls `test_requests` again to demonstrate making requests without the proxy.

### **Explanation Summary:**
- The script utilizes the `anonymize` library to enable and disable a proxy for HTTP requests.
- The `test_requests` function uses the `requests` library to make an HTTP GET request to a URL that returns the public IP address.
- The script first enables the proxy using `enable_proxy` and tests requests, then disables the proxy using `disable_proxy` and tests requests again without the proxy.

### **Note:**
Ensure that the `anonymize` library is properly installed (`pip install anonymize`) before running this script. Additionally, the effectiveness of the proxy may vary depending on your network setup and the availability of the proxy server.
