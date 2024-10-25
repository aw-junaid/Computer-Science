### TCP (Transmission Control Protocol)

**TCP (Transmission Control Protocol)** is one of the main protocols in the Internet protocol suite. It provides reliable, connection-oriented communication between two devices over a network. TCP ensures that data is delivered in the correct order and without errors. It achieves this by using acknowledgments and retransmissions to handle lost or corrupted data.

### TCP Header

The TCP header is part of the TCP packet used for communication. It contains several fields, each serving a specific purpose:

1. **Source Port (16 bits):** Identifies the sender's port number.
2. **Destination Port (16 bits):** Identifies the recipient's port number.
3. **Sequence Number (32 bits):** Specifies the sequence number of the first data byte in the current message.
4. **Acknowledgment Number (32 bits):** Indicates the next sequence number that the sender is expecting to receive.
5. **Data Offset (4 bits):** Specifies the size of the TCP header in 32-bit words.
6. **Reserved (3 bits):** Reserved for future use.
7. **Flags (9 bits):** Contains control flags such as URG, ACK, PSH, RST, SYN, and FIN.
8. **Window Size (16 bits):** Specifies the size of the sender's receive window, indicating how much data the sender can accept.
9. **Checksum (16 bits):** Used for error-checking the header and data.
10. **Urgent Pointer (16 bits):** Indicates the end of urgent data if the URG flag is set.
11. **Options (Variable):** Optional field used for various purposes, such as Maximum Segment Size (MSS) negotiation.

### TCP Server and Client

#### TCP Server:
A TCP server is a program that listens for incoming TCP connections from clients. It typically follows these steps:

1. **Socket Creation:** The server creates a socket to listen for incoming connections using the `socket()` function.

```python
import socket

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
```

2. **Binding:** The server binds the socket to a specific IP address and port.

```python
server_socket.bind(('127.0.0.1', 12345))
```

3. **Listening:** The server starts listening for incoming connections.

```python
server_socket.listen(5)
```

4. **Accepting Connections:** When a client attempts to connect, the server accepts the connection.

```python
client_socket, client_address = server_socket.accept()
```

5. **Data Exchange:** The server can then send and receive data with the connected client using the `send()` and `recv()` functions.

```python
data = client_socket.recv(1024)
client_socket.send(b"Hello, client!")
```

6. **Closing Connection:** Finally, when the communication is complete, the server closes the connection.

```python
client_socket.close()
server_socket.close()
```

#### TCP Client:
A TCP client is a program that initiates a connection to a TCP server. It generally follows these steps:

1. **Socket Creation:** The client creates a socket for communication.

```python
import socket

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
```

2. **Connection:** The client connects to the server using the server's IP address and port.

```python
client_socket.connect(('127.0.0.1', 12345))
```

3. **Data Exchange:** The client can then send and receive data with the server.

```python
client_socket.send(b"Hello, server!")
data = client_socket.recv(1024)
```

4. **Closing Connection:** After communication, the client closes the connection.

```python
client_socket.close()
```

In a real-world scenario, both the server and client would handle errors, use threading or asynchronous programming for concurrent connections, and implement more sophisticated communication protocols depending on the application requirements.
