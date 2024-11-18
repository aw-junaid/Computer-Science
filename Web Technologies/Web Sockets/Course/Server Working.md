### WebSockets - Server Working

A WebSocket server is responsible for handling incoming WebSocket connections from clients, maintaining active connections, sending and receiving messages, and gracefully closing connections. The WebSocket server operates based on the WebSocket protocol, enabling full-duplex communication (both sending and receiving messages at the same time) over a persistent connection. 

In this section, we will explore how a WebSocket server works, including the steps of establishing a connection, handling communication, and managing connections.

---

### 1. **Establishing a WebSocket Server**

To create a WebSocket server, you need to use a library that implements the WebSocket protocol, such as `ws` in Node.js or `websockets` in Python. The server listens for incoming WebSocket connection requests and then upgrades the connection from HTTP to WebSocket.

Here’s a basic overview of how the WebSocket server works:

#### **Connection Upgrade Process (Handshake)**
1. **Client Request**: The client sends an HTTP request to the server to initiate the WebSocket handshake.
2. **Server Response**: The server responds with a special HTTP response that includes a status code (101: Switching Protocols) to indicate that the protocol will be upgraded to WebSocket.
3. **Upgrade to WebSocket**: Once the handshake is complete, the connection is upgraded from HTTP to WebSocket, and both the client and server can send messages to each other.

---

### 2. **WebSocket Server Example (Node.js with `ws`)**

Here’s an example of how to create a WebSocket server using the `ws` library in Node.js. The server listens for client connections, handles incoming messages, and can send responses back to clients.

#### **Step 1: Install `ws` Library**
To begin with, you need to install the `ws` package in your Node.js project:

```bash
npm install ws
```

#### **Step 2: Create the WebSocket Server**

```javascript
const WebSocket = require('ws');

// Create a WebSocket server that listens on port 8080
const wss = new WebSocket.Server({ port: 8080 });

// Event handler for when a client connects
wss.on('connection', function connection(ws) {
    console.log('A new client has connected!');

    // Send a message to the client
    ws.send('Hello, client!');

    // Event handler for when a message is received from the client
    ws.on('message', function incoming(message) {
        console.log('Received message from client:', message);
        
        // Echo the received message back to the client
        ws.send(`You said: ${message}`);
    });

    // Event handler for when the connection is closed
    ws.on('close', function() {
        console.log('Client disconnected');
    });

    // Event handler for errors
    ws.on('error', function(error) {
        console.error('WebSocket error:', error);
    });
});

console.log('WebSocket server is running on ws://localhost:8080');
```

### Explanation:

- **WebSocket Server**: We create a WebSocket server using `new WebSocket.Server({ port: 8080 })`, which listens for incoming WebSocket connections on port 8080.
  
- **Handling Connections**:
  - The `wss.on('connection', function connection(ws) {...})` event listener listens for incoming WebSocket connections. Each client that connects creates a new `ws` object, representing the connection to that client.
  
- **Handling Messages**:
  - When the client sends a message, the `ws.on('message', function incoming(message) {...})` event is triggered. The server can process the message and respond back using `ws.send()`.

- **Closing Connections**:
  - The `ws.on('close', function() {...})` event is triggered when the client disconnects.
  
- **Handling Errors**:
  - The `ws.on('error', function(error) {...})` event is used to handle any WebSocket errors that occur during communication.

---

### 3. **How the WebSocket Server Handles Connections**

1. **Connection Request**:
   - When a client connects to the WebSocket server, the connection request starts as a standard HTTP request. The client sends a WebSocket handshake request (with headers like `Upgrade: websocket` and `Connection: Upgrade`).

2. **Handshake & Protocol Upgrade**:
   - The WebSocket server responds with a status code of `101` (Switching Protocols), signaling that the connection should be upgraded from HTTP to WebSocket. After the upgrade, the WebSocket connection is established.

3. **Message Exchange**:
   - Both the client and server can now send and receive messages over the WebSocket connection. The server can send messages to the client using the `send()` method, and the client can receive these messages via the `onmessage` event handler.
   - The communication continues until either the client or server decides to close the connection.

4. **Connection Closure**:
   - A WebSocket connection can be closed either by the client or the server. To close a connection, the `close()` method is called, and the connection is gracefully closed with a `close` event.

---

### 4. **Handling Multiple Client Connections**

A WebSocket server is designed to handle multiple client connections simultaneously. It can maintain a list of active connections and send messages to one or more clients based on specific conditions. Here’s how you can manage multiple connections in the server:

#### Example: Broadcasting a Message to All Clients

```javascript
const WebSocket = require('ws');

const wss = new WebSocket.Server({ port: 8080 });

// Array to store all client connections
let clients = [];

wss.on('connection', function connection(ws) {
    console.log('A new client has connected!');
    
    // Add the new connection to the clients array
    clients.push(ws);
    
    // Send a welcome message to the new client
    ws.send('Welcome to the WebSocket server!');
    
    // Handle incoming messages from clients
    ws.on('message', function incoming(message) {
        console.log('Received message:', message);

        // Broadcast the message to all connected clients
        clients.forEach(function(client) {
            if (client !== ws && client.readyState === WebSocket.OPEN) {
                client.send(`Broadcast: ${message}`);
            }
        });
    });

    // Handle client disconnection
    ws.on('close', function() {
        // Remove the disconnected client from the array
        clients = clients.filter(client => client !== ws);
        console.log('Client disconnected');
    });
    
    // Handle WebSocket errors
    ws.on('error', function(error) {
        console.error('WebSocket error:', error);
    });
});

console.log('WebSocket server is running on ws://localhost:8080');
```

### Explanation:

- **Multiple Connections**: The `clients` array stores all the active WebSocket connections. Each time a new client connects, their connection object (`ws`) is added to this array.
  
- **Broadcasting Messages**: When a message is received from a client, it is broadcasted to all other connected clients using the `clients.forEach()` method. The server checks if each client is still open (`client.readyState === WebSocket.OPEN`) before sending the message.

- **Client Disconnection**: When a client disconnects, the server removes their connection from the `clients` array to stop sending messages to them.

---

### 5. **Server-Side Events and Methods**

- **`connection` Event**: Triggered when a new client connects. A new WebSocket (`ws`) object is provided to interact with that specific client.
  
- **`message` Event**: Triggered when a message is received from a client. The message can be processed and responded to accordingly.

- **`close` Event**: Triggered when the client closes the WebSocket connection. This is typically handled by the server to clean up resources.
  
- **`error` Event**: Triggered when there is an error during communication. This is useful for debugging and logging errors that may occur.

- **`send()` Method**: Used to send messages to a specific client. The server can call this method on the `ws` object to send data to the connected client.

---

### 6. **WebSocket Server Best Practices**

1. **Handle Connection Cleanup**: When clients disconnect, clean up any resources (such as removing their references from the active connections array) to avoid memory leaks.
   
2. **Limit Client Connections**: If your application expects a large number of concurrent connections, consider limiting the number of clients that can connect to the server at once.

3. **Authentication & Security**: Ensure that only authorized clients can connect to your WebSocket server. Use security mechanisms such as token-based authentication during the WebSocket handshake.

4. **Graceful Shutdown**: Implement a graceful shutdown mechanism to close open connections properly before terminating the WebSocket server.

---

### Conclusion

The WebSocket server operates by establishing a connection with a client via an HTTP handshake, upgrading the protocol to WebSocket, and allowing both the client and server to send and receive messages. The server is responsible for managing multiple client connections, broadcasting messages, handling errors, and gracefully closing connections when needed. The `ws` library in Node.js is commonly used to handle WebSocket communication, but similar libraries exist for other languages as well.
