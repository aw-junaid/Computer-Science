### **Unix Socket - Server Examples**

A Unix socket server provides a means of communication to handle incoming connections from clients on the same machine using Unix domain sockets. The server typically involves creating a socket, binding it to an address (usually a file path), listening for incoming connections, accepting those connections, and then processing requests.

Below are examples of how to implement a Unix socket server for both stream-based (TCP-like) and datagram-based (UDP-like) communication using Unix domain sockets.

---

### **1. Stream-based Server (SOCK_STREAM)**

A stream-based Unix socket server uses the `SOCK_STREAM` type, which provides a reliable, connection-oriented communication channel similar to TCP. The server will listen for incoming connections and process client requests.

#### **Stream-based Server Example**

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

// Function to handle the server logic
void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    // Receive data from the client
    bytes_received = recv(client_sock, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        perror("recv failed");
        close(client_sock);
        return;
    }

    buffer[bytes_received] = '\0';  // Null-terminate the string

    printf("Server received: %s\n", buffer);

    // Send a response back to the client
    const char *response = "Hello from server!";
    if (send(client_sock, response, strlen(response), 0) == -1) {
        perror("send failed");
        close(client_sock);
        return;
    }

    close(client_sock);
}

int main() {
    int sockfd, client_sock;
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

    // Bind the socket to the file path
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1) {
        perror("bind failed");
        close(sockfd);
        exit(1);
    }

    // Start listening for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("listen failed");
        close(sockfd);
        exit(1);
    }

    printf("Server listening on %s\n", SOCKET_PATH);

    while (1) {
        // Accept incoming connections
        client_sock = accept(sockfd, NULL, NULL);
        if (client_sock == -1) {
            perror("accept failed");
            continue;
        }

        printf("Client connected\n");

        // Handle the client request
        handle_client(client_sock);
    }

    close(sockfd);
    unlink(SOCKET_PATH);  // Cleanup the socket file
    return 0;
}
```

#### **Explanation**:
1. **Socket Creation**: The server creates a Unix domain socket using `socket(AF_UNIX, SOCK_STREAM, 0)`.
2. **Binding**: The server binds the socket to a file path (`/tmp/my_unix_socket`) using `bind()`.
3. **Listening**: The server listens for incoming connections using `listen()`.
4. **Accepting Connections**: The server accepts incoming client connections with `accept()`.
5. **Handling Client**: The server receives a message from the client using `recv()` and sends a response back using `send()`.
6. **Cleanup**: After the server finishes handling the client, it closes the connection and deletes the socket file using `unlink()`.

---

### **2. Datagram-based Server (SOCK_DGRAM)**

A datagram-based Unix socket server uses `SOCK_DGRAM`, which is connectionless and provides message-oriented communication similar to UDP. Each message sent by the client is treated as a separate packet.

#### **Datagram-based Server Example**

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
    struct sockaddr_un addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
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

    // Bind the socket to the file path
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1) {
        perror("bind failed");
        close(sockfd);
        exit(1);
    }

    printf("Server listening on %s\n", SOCKET_PATH);

    while (1) {
        // Receive data from the client
        ssize_t bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_addr, &client_len);
        if (bytes_received == -1) {
            perror("recvfrom failed");
            continue;
        }

        buffer[bytes_received] = '\0';  // Null-terminate the string
        printf("Server received: %s\n", buffer);

        // Send a response back to the client
        const char *response = "Hello from server!";
        if (sendto(sockfd, response, strlen(response), 0, (struct sockaddr *)&client_addr, client_len) == -1) {
            perror("sendto failed");
            continue;
        }
    }

    close(sockfd);
    unlink(SOCKET_PATH);  // Cleanup the socket file
    return 0;
}
```

#### **Explanation**:
1. **Socket Creation**: The server creates a Unix domain socket using `socket(AF_UNIX, SOCK_DGRAM, 0)`.
2. **Binding**: The server binds the socket to a file path (`/tmp/my_unix_socket`) using `bind()`.
3. **Receiving Data**: The server receives messages from clients using `recvfrom()`, which is used for datagram sockets.
4. **Sending Data**: The server sends responses back to clients using `sendto()`.
5. **Cleanup**: After finishing, the server closes the socket and deletes the socket file using `unlink()`.

---

### **3. Multi-client Stream Server**

A multi-client server can handle multiple clients simultaneously. This example demonstrates how a server can handle multiple clients by using `fork()` to create a new process for each client, allowing the server to process multiple clients concurrently.

#### **Multi-client Stream Server Example**

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

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    bytes_received = recv(client_sock, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        perror("recv failed");
        close(client_sock);
        return;
    }

    buffer[bytes_received] = '\0';  // Null-terminate the string
    printf("Server received: %s\n", buffer);

    const char *response = "Hello from server!";
    if (send(client_sock, response, strlen(response), 0) == -1) {
        perror("send failed");
        close(client_sock);
        return;
    }

    close(client_sock);
}

int main() {
    int sockfd, client_sock;
    struct sockaddr_un addr;
    pid_t pid;

    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket creation failed");
        exit(1);
    }

    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path) - 1);

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1) {
        perror("bind failed");
        close(sockfd);
        exit(1);
    }

    if (listen(sockfd, 5) == -1) {
        perror("listen failed");
        close(sockfd);
        exit(1);
    }

    printf("Server listening on %s\n", SOCKET_PATH);

    while (1) {
        client_sock = accept(sockfd, NULL, NULL);
        if (client_sock == -1) {
            perror("accept failed");
            continue;
        }

        pid = fork();
        if (pid == 0) {
            // Child process handles the client
            close(sockfd);  // Child doesn't need the server socket
            handle_client(client_sock);
            exit(0);
        } else if (pid > 0) {
            // Parent process closes the client socket and waits for next connection
            close(client_sock);
        } else

 {
            perror("fork failed");
            exit(1);
        }
    }

    close(sockfd);
    unlink(SOCKET_PATH);
    return 0;
}
```

#### **Explanation**:
1. **Forking**: When a client connects, the server forks a new process to handle the client. The parent process waits for further connections.
2. **Child Process**: The child process handles the client interaction, while the parent process waits for the next client.
3. **Socket Cleanup**: The server performs cleanup by closing the server socket and unlinking the Unix socket file.

---

These examples demonstrate how to implement both simple and multi-client servers using Unix domain sockets. The stream-based server is connection-oriented and handles each client in turn, while the datagram-based server is connectionless. The multi-client server uses `fork()` to allow the server to handle multiple clients concurrently.
