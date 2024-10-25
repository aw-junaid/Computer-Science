### Purpose of the Code
The provided Python script is a simple TCP server that listens for incoming connections and handles client requests. It utilizes the `socket` module for socket operations and `threading` for concurrent handling of client connections.

### Import Statements
```python
#!/usr/bin/python

import socket
import threading
```
1. **Shebang Line:** Specifies the interpreter to be used for running the script.
2. **Import Statements:**
   - `socket`: Provides low-level networking functionality.
   - `threading`: Allows for concurrent execution using threads.

### Server Configuration
```python
SERVER_IP   = "127.0.0.1"
SERVER_PORT = 9998
```
- **Server IP and Port:** Defines the IP address and port on which the server will listen for incoming connections.

### Socket Creation and Binding
```python
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((SERVER_IP, SERVER_PORT))
```
1. **Socket Creation:** Creates a socket for IPv4 (AF_INET) and TCP (SOCK_STREAM) communication.
2. **Binding:** Binds the socket to the specified IP address and port.

### Listening for Connections
```python
server.listen(5)
```
- **Listening:** The server is configured to listen for up to 5 incoming connections in the listen queue.

### Connection Acceptance
```python
print("[*] Server Listening on %s:%d" % (SERVER_IP, SERVER_PORT))

client, addr = server.accept()
client.send("I am the server accepting connections...".encode())
print("[*] Accepted connection from: %s:%d" % (addr[0], addr[1]))
```
1. **Print Information:** Prints that the server is listening on a specific IP and port.
2. **Accept Connection:** Accepts an incoming connection and retrieves the client socket and address.
3. **Sending Initial Message:** Sends an initial message to the connected client.

### Client Handling Function
```python
def handle_client(client_socket):
    request = client_socket.recv(1024)
    print("[*] Received request : %s from client %s" , request, client_socket.getpeername())
    client_socket.send(bytes("ACK","utf-8"))
```
- **Function Definition:** Defines a function `handle_client` to process client requests.
- **Request Reception:** Receives a request from the client using `recv()`.
- **Prints Request Information:** Prints the received request and the client's address.
- **Sends ACK:** Sends an acknowledgment back to the client.

### Infinite Loop for Client Handling
```python
while True:
    handle_client(client)
```
- **Infinite Loop:** Repeatedly calls the `handle_client` function for the connected client.

### Closing Sockets
```python
client_socket.close()
server.close()
```
- **Socket Closure:** Closes both the client socket and the server socket after handling the client request.

### Summary
This script sets up a TCP server that listens for incoming connections, accepts a single connection, sends an initial message, and then enters into an infinite loop to handle client requests. The `handle_client` function is responsible for processing each client's request. Note that this script handles only one client connection due to the lack of multi-threading or asynchronous handling.
