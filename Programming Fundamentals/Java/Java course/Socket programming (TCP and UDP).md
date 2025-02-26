Socket programming in Java allows you to create networked applications that communicate over the internet or local networks. Sockets are endpoints for communication between two machines, and they can use either **TCP (Transmission Control Protocol)** or **UDP (User Datagram Protocol)** for communication.

---

### **TCP vs UDP**

| Feature               | TCP                                      | UDP                                      |
|-----------------------|------------------------------------------|------------------------------------------|
| **Connection**        | Connection-oriented (requires a connection). | Connectionless (no connection required). |
| **Reliability**       | Reliable (ensures data delivery).        | Unreliable (no guarantee of delivery).   |
| **Order**             | Ensures data arrives in order.           | No guarantee of order.                   |
| **Speed**             | Slower due to overhead.                  | Faster due to minimal overhead.          |
| **Use Cases**         | Web browsing, email, file transfer.      | Video streaming, online gaming, DNS.     |

---

### **TCP Socket Programming**

TCP is a connection-oriented protocol, meaning a connection is established between the client and server before data is transmitted.

#### **TCP Server**
The server listens for incoming connections and processes client requests.

```java
import java.io.*;
import java.net.*;

public class TCPServer {
    public static void main(String[] args) throws IOException {
        // Create a server socket on port 5000
        ServerSocket serverSocket = new ServerSocket(5000);
        System.out.println("Server started. Waiting for client...");

        // Accept a client connection
        Socket socket = serverSocket.accept();
        System.out.println("Client connected.");

        // Create input and output streams
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

        // Read data from the client
        String message = in.readLine();
        System.out.println("Client says: " + message);

        // Send a response to the client
        out.println("Hello from Server!");

        // Close resources
        socket.close();
        serverSocket.close();
    }
}
```

#### **TCP Client**
The client connects to the server and sends/receives data.

```java
import java.io.*;
import java.net.*;

public class TCPClient {
    public static void main(String[] args) throws IOException {
        // Create a socket and connect to the server on port 5000
        Socket socket = new Socket("localhost", 5000);

        // Create input and output streams
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

        // Send a message to the server
        out.println("Hello from Client!");

        // Read the server's response
        String response = in.readLine();
        System.out.println("Server says: " + response);

        // Close resources
        socket.close();
    }
}
```

---

### **UDP Socket Programming**

UDP is a connectionless protocol, meaning data is sent in packets without establishing a connection.

#### **UDP Server**
The server listens for incoming datagrams and processes them.

```java
import java.net.*;

public class UDPServer {
    public static void main(String[] args) throws Exception {
        // Create a datagram socket on port 5000
        DatagramSocket socket = new DatagramSocket(5000);
        System.out.println("Server started. Waiting for data...");

        // Create a buffer to store incoming data
        byte[] buffer = new byte[1024];
        DatagramPacket packet = new DatagramPacket(buffer, buffer.length);

        // Receive data from the client
        socket.receive(packet);
        String message = new String(packet.getData(), 0, packet.getLength());
        System.out.println("Client says: " + message);

        // Send a response to the client
        String response = "Hello from Server!";
        byte[] responseData = response.getBytes();
        DatagramPacket responsePacket = new DatagramPacket(
            responseData, responseData.length, packet.getAddress(), packet.getPort());
        socket.send(responsePacket);

        // Close the socket
        socket.close();
    }
}
```

#### **UDP Client**
The client sends datagrams to the server and receives responses.

```java
import java.net.*;

public class UDPClient {
    public static void main(String[] args) throws Exception {
        // Create a datagram socket
        DatagramSocket socket = new DatagramSocket();

        // Create a message to send
        String message = "Hello from Client!";
        byte[] sendData = message.getBytes();

        // Send the message to the server
        InetAddress serverAddress = InetAddress.getByName("localhost");
        DatagramPacket sendPacket = new DatagramPacket(
            sendData, sendData.length, serverAddress, 5000);
        socket.send(sendPacket);

        // Create a buffer to store the server's response
        byte[] receiveData = new byte[1024];
        DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);

        // Receive the server's response
        socket.receive(receivePacket);
        String response = new String(receivePacket.getData(), 0, receivePacket.getLength());
        System.out.println("Server says: " + response);

        // Close the socket
        socket.close();
    }
}
```

---

### **Key Classes for Socket Programming**

1. **`Socket`**:
   - Used for TCP communication.
   - Represents a connection between a client and server.

2. **`ServerSocket`**:
   - Used by TCP servers to listen for incoming connections.

3. **`DatagramSocket`**:
   - Used for UDP communication.
   - Represents a connectionless socket for sending and receiving datagrams.

4. **`DatagramPacket`**:
   - Represents a datagram in UDP communication.
   - Contains the data, length, and destination address.

5. **`InetAddress`**:
   - Represents an IP address (e.g., `localhost`, `192.168.1.1`).

---

### **Steps for TCP Communication**

1. **Server**:
   - Create a `ServerSocket` and bind it to a port.
   - Wait for a client connection using `accept()`.
   - Use input/output streams to communicate with the client.

2. **Client**:
   - Create a `Socket` and connect to the server.
   - Use input/output streams to communicate with the server.

---

### **Steps for UDP Communication**

1. **Server**:
   - Create a `DatagramSocket` and bind it to a port.
   - Receive datagrams using `receive()`.
   - Send datagrams using `send()`.

2. **Client**:
   - Create a `DatagramSocket`.
   - Send datagrams using `send()`.
   - Receive datagrams using `receive()`.

---

### **Best Practices**

1. **Error Handling**:
   - Always handle exceptions like `IOException` and `SocketException`.

2. **Resource Management**:
   - Close sockets and streams using `close()` to free resources.

3. **Threading**:
   - Use multi-threading to handle multiple clients simultaneously in TCP servers.

4. **Buffering**:
   - Use buffers to handle large amounts of data efficiently.

5. **Security**:
   - Use secure protocols like TLS/SSL for sensitive data.

---

### **Example: Multi-Threaded TCP Server**

To handle multiple clients, you can create a new thread for each client connection.

```java
import java.io.*;
import java.net.*;

public class MultiThreadedTCPServer {
    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(5000);
        System.out.println("Server started. Waiting for clients...");

        while (true) {
            Socket socket = serverSocket.accept();
            System.out.println("New client connected.");

            // Create a new thread for each client
            new ClientHandler(socket).start();
        }
    }
}

class ClientHandler extends Thread {
    private Socket socket;

    public ClientHandler(Socket socket) {
        this.socket = socket;
    }

    public void run() {
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

            String message;
            while ((message = in.readLine()) != null) {
                System.out.println("Client says: " + message);
                out.println("Echo: " + message);
            }

            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

---

By mastering TCP and UDP socket programming in Java, you can build robust networked applications for various use cases.
