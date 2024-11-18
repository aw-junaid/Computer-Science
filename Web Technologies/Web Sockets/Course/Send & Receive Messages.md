### WebSockets - Send & Receive Messages

WebSockets allow for full-duplex communication, meaning both the client and server can send and receive messages at the same time over the same open connection. This is one of the primary advantages of WebSockets, as it enables real-time, bidirectional communication.

In this section, we'll cover how to send and receive messages using WebSockets on both the **client-side** and **server-side**.

---

### 1. **Client-Side: Sending and Receiving Messages**

Once the WebSocket connection is open, the client can send messages using the `send()` method and receive messages using the `onmessage` event handler.

#### Sending Messages from the Client:
The `send()` method is used to send data to the server. This can be any valid JavaScript data type, such as strings, objects (usually serialized as JSON), or binary data.

#### Example of Sending Messages from the Client (JavaScript):

```javascript
// Establish a WebSocket connection
const socket = new WebSocket('ws://example.com/socket');

// Event handler for when the connection is opened
socket.onopen = function(event) {
    console.log('Connection established!');
    
    // Send a message to the server after connection is opened
    socket.send('Hello, server!');  // Sending a simple string message
    socket.send(JSON.stringify({ message: 'Hello from client', timestamp: Date.now() }));  // Sending a JSON object
};

// Event handler for receiving messages from the server
socket.onmessage = function(event) {
    console.log('Message from server: ', event.data);
    
    // Example of parsing JSON message received from server
    try {
        const serverMessage = JSON.parse(event.data);
        console.log('Parsed message from server:', serverMessage);
    } catch (e) {
        console.error('Invalid JSON from server:', e);
    }
};

// Event handler for errors
socket.onerror = function(error) {
    console.error('WebSocket error:', error);
};

// Event handler for connection closure
socket.onclose = function(event) {
    console.log('Connection closed:', event);
};
```

### Explanation:
- **Sending a String Message**: 
  ```javascript
  socket.send('Hello, server!');
  ```
  This sends a simple text message to the server.

- **Sending a JSON Object**:
  ```javascript
  socket.send(JSON.stringify({ message: 'Hello from client', timestamp: Date.now() }));
  ```
  The `JSON.stringify()` method is used to serialize an object into a string format before sending it.

- **Receiving Messages**:
  The `onmessage` event is triggered whenever a message is received from the server. The `event.data` property contains the message data, which could be a string or a binary message, depending on the server response.
  
  In the example above, we attempt to parse the received message as JSON.

---

### 2. **Server-Side: Sending and Receiving Messages**

On the server side, the WebSocket server listens for incoming WebSocket connections and can send or receive messages to and from the client. The WebSocket server can use libraries such as `ws` in Node.js, which provides a simple interface for handling WebSocket communication.

#### Example: Sending and Receiving Messages on the Server (Node.js with `ws`):

```javascript
const WebSocket = require('ws');

// Create a new WebSocket server
const wss = new WebSocket.Server({ port: 8080 });

// Handle client connections
wss.on('connection', function connection(ws) {
    console.log('A new client connected');
    
    // Send a message to the client when they connect
    ws.send('Welcome to the WebSocket server!');
    
    // Handle incoming messages from the client
    ws.on('message', function incoming(message) {
        console.log('Received message:', message);
        
        // Example: Echo the message back to the client
        ws.send(`Server received: ${message}`);
        
        // Sending a JSON message to the client
        try {
            const clientMessage = JSON.parse(message);
            ws.send(JSON.stringify({ response: 'Message received', data: clientMessage }));
        } catch (e) {
            console.error('Invalid JSON message:', e);
            ws.send('Error: Invalid JSON message');
        }
    });

    // Handle WebSocket close event
    ws.on('close', function() {
        console.log('Client disconnected');
    });
    
    // Handle WebSocket error event
    ws.on('error', function(error) {
        console.error('WebSocket error:', error);
    });
});

console.log('WebSocket server is running on ws://localhost:8080');
```

### Explanation:
- **Sending Messages to the Client**:
  - When a client connects, the server sends a welcome message:
    ```javascript
    ws.send('Welcome to the WebSocket server!');
    ```

- **Receiving Messages from the Client**:
  - The `message` event is triggered when the server receives a message from a client:
    ```javascript
    ws.on('message', function incoming(message) {
        console.log('Received message:', message);
    });
    ```
    In this example, the server sends the received message back to the client using `ws.send()`. The server also checks if the message is valid JSON, and responds accordingly.

- **Error Handling**:
  - If the received message is not valid JSON, the server logs an error and sends an error message back to the client.
  
- **Handling Connection Closure**:
  - The server listens for the `close` event, which is triggered when the client disconnects.

---

### 3. **Binary Data (Optional)**

WebSockets support sending and receiving binary data, such as images, files, or other binary formats. This can be done using `Blob`, `ArrayBuffer`, or `Buffer` (in Node.js).

#### Example: Sending and Receiving Binary Data (Client-Side):

```javascript
// Send an ArrayBuffer (binary data)
const buffer = new ArrayBuffer(8); // Create a simple 8-byte buffer
const uint8View = new Uint8Array(buffer);
uint8View[0] = 42;  // Example of filling the buffer with some data
socket.send(buffer);  // Send binary data

// Receive binary data from the server
socket.onmessage = function(event) {
    if (event.data instanceof ArrayBuffer) {
        console.log('Received binary data:', event.data);
    } else {
        console.log('Received message:', event.data);
    }
};
```

#### Example: Sending and Receiving Binary Data (Server-Side with Node.js):

```javascript
wss.on('connection', function connection(ws) {
    // Send a binary message (ArrayBuffer) to the client
    const buffer = Buffer.from([0x01, 0x02, 0x03, 0x04]); // Example binary data
    ws.send(buffer);

    // Handle binary message from the client
    ws.on('message', function incoming(message) {
        if (message instanceof Buffer) {
            console.log('Received binary data:', message);
        } else {
            console.log('Received text message:', message);
        }
    });
});
```

### Explanation:
- **Client-Side**: The `ArrayBuffer` is used to represent binary data, and the data is sent using the `send()` method.
- **Server-Side**: The server can send and receive binary data using `Buffer` (in Node.js) or `ArrayBuffer`/`Blob` (in browsers).

---

### 4. **Handling Errors with Messages**

If there is an issue with the message format, both the client and server should handle errors gracefully. This includes invalid JSON format, unsupported message types, or other exceptions during message processing.

#### Example of Error Handling in Message Processing:

**Client-Side:**
```javascript
socket.onmessage = function(event) {
    try {
        const data = JSON.parse(event.data);
        console.log('Received parsed data:', data);
    } catch (e) {
        console.error('Failed to parse message:', e);
    }
};
```

**Server-Side:**
```javascript
ws.on('message', function(message) {
    try {
        const parsedMessage = JSON.parse(message);
        console.log('Received parsed message:', parsedMessage);
    } catch (e) {
        console.error('Invalid JSON format:', e);
        ws.send('Error: Invalid JSON format');
    }
});
```

---

### 5. **Message Formats**

While WebSocket allows any type of message to be sent, **text** and **binary** data are the most common formats used. Text messages are typically in JSON format, while binary messages are used for files, images, or other binary data.

- **Text**: Usually sent as plain strings or JSON-encoded strings.
- **Binary**: Sent as `ArrayBuffer`, `Blob`, or `Buffer` (Node.js).

---

### Conclusion

WebSockets provide a flexible and powerful way to send and receive messages in real-time. The key points for sending and receiving messages are:
- **Client-Side**: Use `send()` to send messages and `onmessage` to receive them.
- **Server-Side**: Use `send()` to send messages and `message` event to receive them.
- **Binary Data**: WebSockets support sending binary data using `ArrayBuffer` or `Blob`.
- **Error Handling**: Properly handle errors in message formats (e.g., invalid JSON).
