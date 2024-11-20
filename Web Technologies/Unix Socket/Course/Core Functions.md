### **Unix Socket - Core Functions**

Unix domain sockets provide a mechanism for **inter-process communication (IPC)** within the same machine. The core functions used for working with Unix domain sockets are similar to those used with network sockets, such as TCP/IP, but they focus on local communication using file paths or abstract addresses instead of IP addresses and ports.

Below is an overview of the key Unix socket core functions:

### **1. `socket()`**
- **Description**: The `socket()` function creates a new socket. For Unix domain sockets, the socket type is typically `SOCK_STREAM` (for reliable, connection-based communication) or `SOCK_DGRAM` (for connectionless communication).
- **Prototype**:
  ```c
  int socket(int domain, int type, int protocol);
  ```
- **Parameters**:
  - `domain`: For Unix domain sockets, this is typically `AF_UNIX` or `AF_LOCAL`.
  - `type`: The type of socket, usually `SOCK_STREAM` (for TCP-like communication) or `SOCK_DGRAM` (for UDP-like communication).
  - `protocol`: Should usually be set to `0`, as Unix domain sockets do not use a specific protocol.

- **Return value**: On success, it returns a socket descriptor (a non-negative integer). On failure, it returns `-1`.

  ```c
  int sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (sockfd == -1) {
      perror("socket creation failed");
      exit(1);
  }
  ```

### **2. `bind()`**
- **Description**: The `bind()` function associates a socket with a specific address. For Unix domain sockets, the address is usually a file path in the filesystem or an abstract address.
- **Prototype**:
  ```c
  int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
  ```
- **Parameters**:
  - `sockfd`: The socket descriptor created using `socket()`.
  - `addr`: A pointer to a `struct sockaddr_un` that contains the address to bind the socket to.
  - `addrlen`: The size of the `struct sockaddr_un` structure.

- **Return value**: On success, returns `0`. On failure, returns `-1`.

  ```c
  struct sockaddr_un addr;
  memset(&addr, 0, sizeof(struct sockaddr_un));
  addr.sun_family = AF_UNIX;
  strcpy(addr.sun_path, "/tmp/my_unix_socket");
  int res = bind(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un));
  if (res == -1) {
      perror("bind failed");
      exit(1);
  }
  ```

### **3. `listen()`**
- **Description**: The `listen()` function prepares a server socket to accept incoming connections. It only applies to **SOCK_STREAM** sockets (i.e., connection-oriented communication).
- **Prototype**:
  ```c
  int listen(int sockfd, int backlog);
  ```
- **Parameters**:
  - `sockfd`: The socket descriptor returned by `socket()`.
  - `backlog`: The maximum length of the pending connections queue. If the queue is full, new incoming connections may be rejected.

- **Return value**: On success, returns `0`. On failure, returns `-1`.

  ```c
  int backlog = 5;
  if (listen(sockfd, backlog) == -1) {
      perror("listen failed");
      exit(1);
  }
  ```

### **4. `accept()`**
- **Description**: The `accept()` function is used by a server to accept an incoming connection request from a client. It creates a new socket for the connection.
- **Prototype**:
  ```c
  int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
  ```
- **Parameters**:
  - `sockfd`: The listening socket descriptor (created using `socket()` and `bind()`).
  - `addr`: A pointer to a `struct sockaddr_un` where the client’s address will be stored.
  - `addrlen`: The size of the address structure.

- **Return value**: On success, returns a new socket descriptor for the accepted connection. On failure, returns `-1`.

  ```c
  int client_sockfd = accept(sockfd, NULL, NULL);
  if (client_sockfd == -1) {
      perror("accept failed");
      exit(1);
  }
  ```

### **5. `connect()`**
- **Description**: The `connect()` function is used by a client to establish a connection to a server via the Unix domain socket.
- **Prototype**:
  ```c
  int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
  ```
- **Parameters**:
  - `sockfd`: The socket descriptor created using `socket()`.
  - `addr`: A pointer to a `struct sockaddr_un` containing the address of the server to connect to.
  - `addrlen`: The size of the address structure.

- **Return value**: On success, returns `0`. On failure, returns `-1`.

  ```c
  struct sockaddr_un addr;
  memset(&addr, 0, sizeof(struct sockaddr_un));
  addr.sun_family = AF_UNIX;
  strcpy(addr.sun_path, "/tmp/my_unix_socket");
  
  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1) {
      perror("connect failed");
      exit(1);
  }
  ```

### **6. `send()` and `recv()`**
- **Description**: These functions are used to send and receive data over Unix domain sockets.
- **Prototypes**:
  ```c
  ssize_t send(int sockfd, const void *buf, size_t len, int flags);
  ssize_t recv(int sockfd, void *buf, size_t len, int flags);
  ```
- **Parameters**:
  - `sockfd`: The socket descriptor.
  - `buf`: A pointer to the buffer containing data to be sent or received.
  - `len`: The length of the data to be sent or received.
  - `flags`: Optional flags for the operation (usually `0`).

- **Return value**: On success, returns the number of bytes sent/received. On failure, returns `-1`.

  ```c
  const char *msg = "Hello, Unix Socket!";
  if (send(sockfd, msg, strlen(msg), 0) == -1) {
      perror("send failed");
      exit(1);
  }

  char buffer[256];
  ssize_t bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_received == -1) {
      perror("recv failed");
      exit(1);
  }
  ```

### **7. `close()`**
- **Description**: The `close()` function is used to close a socket when it is no longer needed.
- **Prototype**:
  ```c
  int close(int sockfd);
  ```
- **Parameters**:
  - `sockfd`: The socket descriptor to be closed.

- **Return value**: On success, returns `0`. On failure, returns `-1`.

  ```c
  if (close(sockfd) == -1) {
      perror("close failed");
      exit(1);
  }
  ```

### **8. `unlink()`**
- **Description**: The `unlink()` function is used to delete a Unix domain socket file. This is necessary after closing the socket to remove the socket file from the filesystem.
- **Prototype**:
  ```c
  int unlink(const char *pathname);
  ```
- **Parameters**:
  - `pathname`: The path to the Unix domain socket file.

- **Return value**: On success, returns `0`. On failure, returns `-1`.

  ```c
  if (unlink("/tmp/my_unix_socket") == -1) {
      perror("unlink failed");
      exit(1);
  }
  ```

### **Summary of Core Functions**
- **`socket()`**: Creates a new socket.
- **`bind()`**: Binds the socket to an address (file path for Unix domain sockets).
- **`listen()`**: Prepares the socket to accept incoming connections.
- **`accept()`**: Accepts incoming connection requests (for server).
- **`connect()`**: Connects to a server (for client).
- **`send()` / `recv()`**: Send and receive data over the socket.
- **`close()`**: Closes the socket when done.
- **`unlink()`**: Deletes the socket file (optional cleanup after closing the socket).

These functions provide the core functionality required to set up and communicate using **Unix domain sockets** for local inter-process communication (IPC) on the same machine.
