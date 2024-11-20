### **Unix Socket - Client Examples**

A Unix socket client connects to a server through a Unix domain socket to send and receive data. Below are examples demonstrating how to implement Unix socket clients using both **stream-based (SOCK_STREAM)** and **datagram-based (SOCK_DGRAM)** communication.

---

### **1. Stream-based Client (SOCK_STREAM)**

A stream-based client communicates with a server in a connection-oriented manner, similar to TCP. The client will create a socket, connect to the server, send data, and receive a response.

#### **Stream-based Client Example**

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>

#define SOCKET_PATH "/tmp/my_unix_socket"
#define BUFFER_SIZE 256

int main() {
    int sockfd;
    struct sockaddr_un addr;
    char buffer[BUFFER_SIZE];

    // Create a Unix domain socket (stream-based)
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket creation failed");
        exit(1);
    }

    // Initialize sockaddr_un structure
    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path) - 1);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1) {
        perror("connect failed");
        close(sockfd);
        exit(1);
    }

    printf("Connected to server at %s\n", SOCKET_PATH);

    // Send a message to the server
    const char *message = "Hello from client!";
    if (send(sockfd, message, strlen(message), 0) == -1) {
        perror("send failed");
        close(sockfd);
        exit(1);
    }

    // Receive a response from the server
    ssize_t bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        perror("recv failed");
        close(sockfd);
        exit(1);
    }

    buffer[bytes_received] = '\0';  // Null-terminate the string
    printf("Received from server: %s\n", buffer);

    // Close the socket
    close(sockfd);
    return 0;
}
```

#### **Explanation**:
1. **Socket Creation**: The client creates a Unix domain socket using `socket(AF_UNIX, SOCK_STREAM, 0)`.
2. **Connect to Server**: The client connects to the server at the specified socket path (`/tmp/my_unix_socket`) using `connect()`.
3. **Send Data**: The client sends a message to the server using `send()`.
4. **Receive Data**: The client receives a response from the server using `recv()`.
5. **Close Socket**: After communication, the client closes the socket using `close()`.

---

### **2. Datagram-based Client (SOCK_DGRAM)**

A datagram-based client communicates with a server in a connectionless manner, similar to UDP. The client sends individual packets to the server without establishing a connection. Each message is sent independently.

#### **Datagram-based Client Example**

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>

#define SOCKET_PATH "/tmp/my_unix_socket"
#define BUFFER_SIZE 256

int main() {
    int sockfd;
    struct sockaddr_un addr;
    char buffer[BUFFER_SIZE];

    // Create a Unix domain socket (datagram-based)
    sockfd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket creation failed");
        exit(1);
    }

    // Initialize sockaddr_un structure
    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path) - 1);

    // Send a message to the server
    const char *message = "Hello from client!";
    if (sendto(sockfd, message, strlen(message), 0, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1) {
        perror("sendto failed");
        close(sockfd);
        exit(1);
    }

    // Receive a response from the server
    ssize_t bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);
    if (bytes_received == -1) {
        perror("recvfrom failed");
        close(sockfd);
        exit(1);
    }

    buffer[bytes_received] = '\0';  // Null-terminate the string
    printf("Received from server: %s\n", buffer);

    // Close the socket
    close(sockfd);
    return 0;
}
```

#### **Explanation**:
1. **Socket Creation**: The client creates a Unix domain socket using `socket(AF_UNIX, SOCK_DGRAM, 0)`.
2. **Send Data**: The client sends a message to the server using `sendto()`. The message is sent to the specified socket address.
3. **Receive Data**: The client receives a response from the server using `recvfrom()`.
4. **Close Socket**: After communication, the client closes the socket using `close()`.

---

### **3. Multi-client Stream Client**

In a scenario where a server is handling multiple clients simultaneously (for example, using `fork()` or `select()`), the client can repeatedly connect and send requests to the server. This example demonstrates how a client can simulate multiple connections.

#### **Multi-client Stream Client Example**

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>

#define SOCKET_PATH "/tmp/my_unix_socket"
#define BUFFER_SIZE 256

void communicate_with_server(int sockfd) {
    char buffer[BUFFER_SIZE];

    // Send a message to the server
    const char *message = "Hello from client!";
    if (send(sockfd, message, strlen(message), 0) == -1) {
        perror("send failed");
        close(sockfd);
        exit(1);
    }

    // Receive a response from the server
    ssize_t bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        perror("recv failed");
        close(sockfd);
        exit(1);
    }

    buffer[bytes_received] = '\0';  // Null-terminate the string
    printf("Received from server: %s\n", buffer);
}

int main() {
    int sockfd;
    struct sockaddr_un addr;

    // Create a Unix domain socket (stream-based)
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket creation failed");
        exit(1);
    }

    // Initialize sockaddr_un structure
    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path) - 1);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1) {
        perror("connect failed");
        close(sockfd);
        exit(1);
    }

    printf("Connected to server at %s\n", SOCKET_PATH);

    // Communicate with the server
    communicate_with_server(sockfd);

    // Close the socket
    close(sockfd);
    return 0;
}
```

#### **Explanation**:
- **Simulate Multiple Clients**: In this example, you can run the client multiple times or use a loop to simulate multiple clients. The server (as shown in the previous examples) would need to be able to handle each connection separately, either using `fork()`, `pthread`, or an event-driven mechanism like `select()`.
  
---

### **4. Client with Error Handling**

For robustness, it’s important to handle potential errors during socket communication, including checking if the server is available or if network resources are valid. Here is an example of how to add better error handling to a client.

#### **Client with Enhanced Error Handling Example**

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>

#define SOCKET_PATH "/tmp/my_unix_socket"
#define BUFFER_SIZE 256

int main() {
    int sockfd;
    struct sockaddr_un addr;
    char buffer[BUFFER_SIZE];

    // Create a Unix domain socket (stream-based)
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize sockaddr_un structure
    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path) - 1);

    // Attempt to connect to the server
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1) {
        perror("connect failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server at %s\n", SOCKET_PATH);

    // Send a message to the server
    const char *message = "Hello from client!";
    if (send(sockfd, message, strlen(message), 0)

 == -1) {
        perror("send failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive a response from the server
    ssize_t bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        perror("recv failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    buffer[bytes_received] = '\0';  // Null-terminate the string
    printf("Received from server: %s\n", buffer);

    // Close the socket
    close(sockfd);
    return 0;
}
```

---

These examples show how a client can communicate with a server using Unix domain sockets, including stream-based (SOCK_STREAM) and datagram-based (SOCK_DGRAM) communication, handling both single and multiple client scenarios. Each client example demonstrates the basics of socket creation, data transmission, and error handling.
