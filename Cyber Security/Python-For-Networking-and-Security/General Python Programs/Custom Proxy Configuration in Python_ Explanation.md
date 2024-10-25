### **Custom Proxy Configuration in Python: Explanation**

This Python script demonstrates how to enable and disable a SOCKS proxy for network connections by temporarily modifying the behavior of the `socket` module.

### **1. **Disable Proxy Function:**
```python
temp_socket = socket.socket
temp_create_connection = socket.create_connection

def disable_proxy():
    socket.socket = temp_socket
    socket.create_connection = temp_create_connection
```

The `disable_proxy` function saves the original `socket.socket` and `socket.create_connection` functions and then restores them. This effectively disables the use of a proxy.

### **2. **Enable Proxy Function:**
```python
def enable_proxy(host="127.0.0.1", port=9050):
    
    def create_connection(address, timeout=None, source_address=None):
        sock = socks.socksocket()
        sock.connect(address)
        return sock
    
    socks.setdefaultproxy(socks.PROXY_TYPE_SOCKS5, host, port, True)
    socket.socket = socks.socksocket
    socket.create_connection = create_connection
```

The `enable_proxy` function configures the `socket` module to use a SOCKS5 proxy. It sets the default proxy type and address using the `socks` library. Additionally, it replaces the original `socket.socket` and `socket.create_connection` functions with custom versions that utilize the SOCKS proxy.

### **Explanation Summary:**
- The script provides two functions: `enable_proxy` and `disable_proxy`.
- `enable_proxy` sets up a SOCKS5 proxy configuration for `socket` by using the `socks` library. It overrides the `socket.socket` and `socket.create_connection` functions to enable the proxy.
- `disable_proxy` restores the original `socket` functions, effectively disabling the proxy configuration.

### **Usage:**
To use this script, you can call `enable_proxy` with the desired proxy host and port. After making network connections through the proxy, you can call `disable_proxy` to revert to the default network configuration.

### **Note:**
Ensure that the `socks` library is installed (`pip install PySocks`) before using this script. Also, keep in mind that manipulating the `socket` module globally may affect the behavior of other parts of your code, so use it judiciously.
