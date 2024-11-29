### Perl - Socket Programming

Socket programming allows Perl scripts to communicate over networks by creating sockets that can send and receive data. Perl’s built-in `Socket` module provides a straightforward interface for TCP/IP socket programming, allowing you to build both client and server applications.

---

### 1. **Using the `Socket` Module**

The `Socket` module is part of Perl’s core library, so you can use it without additional installations. This module provides constants and functions for socket operations.

```perl
use Socket;
```

---

### 2. **Creating a Simple TCP Client**

A TCP client connects to a server, sends a message, and reads the server’s response.

#### Example: TCP Client

```perl
use strict;
use warnings;
use Socket;

my $host = '127.0.0.1';       # Server address (localhost in this case)
my $port = 7890;              # Port to connect to

# Convert hostname to IP address
my $ip = inet_aton($host) or die "Cannot resolve hostname: $!\n";
my $address = sockaddr_in($port, $ip);

# Create a socket
socket(my $socket, PF_INET, SOCK_STREAM, getprotobyname('tcp')) or die "Socket creation failed: $!\n";

# Connect to the server
connect($socket, $address) or die "Cannot connect to server: $!\n";

# Send a message to the server
my $message = "Hello from the client!";
print $socket "$message\n";

# Receive response from the server
my $response = <$socket>;
print "Received from server: $response\n";

# Close the socket
close($socket);
```

---

### 3. **Creating a Simple TCP Server**

A TCP server waits for client connections, receives messages, and responds.

#### Example: TCP Server

```perl
use strict;
use warnings;
use Socket;

my $port = 7890;             # Port to listen on
my $proto = getprotobyname('tcp'); 

# Create a socket
socket(my $server_socket, PF_INET, SOCK_STREAM, $proto) or die "Socket creation failed: $!\n";

# Allow reusing the address
setsockopt($server_socket, SOL_SOCKET, SO_REUSEADDR, 1) or die "Cannot set socket option: $!\n";

# Bind the socket to a local address and port
bind($server_socket, sockaddr_in($port, INADDR_ANY)) or die "Cannot bind socket: $!\n";

# Start listening for incoming connections
listen($server_socket, SOMAXCONN) or die "Cannot listen on socket: $!\n";
print "Server is listening on port $port...\n";

# Accept client connections and handle each one in a loop
while (my $client_addr = accept(my $client_socket, $server_socket)) {
    my ($client_port, $client_ip) = sockaddr_in($client_addr);
    my $client_ip_str = inet_ntoa($client_ip);
    print "Connected to client at $client_ip_str:$client_port\n";

    # Receive message from client
    my $client_message = <$client_socket>;
    print "Received from client: $client_message";

    # Send response back to client
    my $response = "Hello from the server!";
    print $client_socket "$response\n";

    # Close the client socket
    close($client_socket);
    print "Connection closed with client.\n";
}

# Close the server socket
close($server_socket);
```

---

### 4. **UDP Client and Server**

UDP is a connectionless protocol that sends messages without establishing a connection. This makes it faster but less reliable than TCP.

#### Example: UDP Client

```perl
use strict;
use warnings;
use Socket;

my $host = '127.0.0.1';  # Server address
my $port = 7891;         # Port to connect to

# Create a socket
socket(my $socket, PF_INET, SOCK_DGRAM, getprotobyname('udp')) or die "Socket creation failed: $!\n";

# Server address
my $server_address = sockaddr_in($port, inet_aton($host));

# Send message to server
my $message = "Hello from UDP client!";
send($socket, $message, 0, $server_address) or die "Send failed: $!\n";

# Receive response
my $response;
recv($socket, $response, 1024, 0);
print "Received from server: $response\n";

# Close the socket
close($socket);
```

#### Example: UDP Server

```perl
use strict;
use warnings;
use Socket;

my $port = 7891;  # Port to listen on

# Create a socket
socket(my $socket, PF_INET, SOCK_DGRAM, getprotobyname('udp')) or die "Socket creation failed: $!\n";

# Bind the socket to a local address and port
bind($socket, sockaddr_in($port, INADDR_ANY)) or die "Cannot bind socket: $!\n";
print "UDP server is listening on port $port...\n";

# Receive messages from clients in a loop
while (1) {
    my $client_address;
    my $data;
    recv($socket, $data, 1024, 0, $client_address);
    my ($client_port, $client_ip) = sockaddr_in($client_address);
    my $client_ip_str = inet_ntoa($client_ip);
    print "Received from client $client_ip_str:$client_port - $data\n";

    # Send response back to client
    my $response = "Hello from UDP server!";
    send($socket, $response, 0, $client_address);
}

# Close the socket
close($socket);
```

---

### Summary of Key Socket Programming Concepts in Perl

| **Function**               | **Description**                                                            |
|----------------------------|----------------------------------------------------------------------------|
| `socket`                   | Creates a socket.                                                          |
| `bind`                     | Binds the socket to a local address and port.                              |
| `listen`                   | Allows the server to listen for incoming connections (TCP only).           |
| `accept`                   | Accepts an incoming client connection (TCP only).                          |
| `connect`                  | Connects the client to a server (TCP only).                                |
| `send`                     | Sends data to the socket.                                                  |
| `recv`                     | Receives data from the socket.                                             |
| `close`                    | Closes the socket.                                                         |

Perl’s socket programming capabilities allow you to create both TCP and UDP clients and servers. This flexibility makes it possible to handle network-based applications for a wide range of use cases.
