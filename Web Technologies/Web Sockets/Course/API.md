### WebSockets - API

The WebSocket API is a JavaScript API that allows for bi-directional, full-duplex communication between a client (usually a web browser) and a server over a single, long-lived connection. The WebSocket API provides methods for establishing a connection, sending and receiving data, and closing the connection. It operates over the WebSocket protocol (RFC 6455) and is commonly used for real-time applications, such as chat apps, online gaming, and live data feeds.

The WebSocket API is accessible in modern web browsers and can be used both on the client and server side to enable persistent communication channels.

### 1. **WebSocket Constructor**

The `WebSocket` constructor is used to create a new WebSocket object that connects to a server.

#### Syntax:

```javascript
const socket = new WebSocket(url, protocols);
```

- `url` (required): The URL to which the client should connect. It starts with `ws://` for an unsecured connection or `wss://` for a secure connection (encrypted via TLS/SSL).
- `protocols` (optional): A subprotocol or array of subprotocols that the client is willing to use. This is used to negotiate the communication protocol between the client and the server.

#### Example:

```javascript
const socket = new WebSocket('ws://example.com/socket');
```

---

### 2. **WebSocket Properties**

WebSocket objects provide several properties that allow you to interact with the connection.

#### Properties:

- **`readyState`**: This property holds the current state of the WebSocket connection. It can have one of the following values:
  - `WebSocket.CONNECTING (0)`: The connection is being established.
  - `WebSocket.OPEN (1)`: The connection is open and ready to communicate.
  - `WebSocket.CLOSING (2)`: The connection is closing.
  - `WebSocket.CLOSED (3)`: The connection is closed or could not be opened.

  ```javascript
  console.log(socket.readyState); // Outputs the current state of the WebSocket connection
  ```

- **`protocol`**: The subprotocol selected by the server if any. This is a string representing the subprotocol that was agreed upon during the handshake.

  ```javascript
  console.log(socket.protocol); // The subprotocol negotiated during the connection
  ```

- **`url`**: The URL to which the WebSocket is connected.

  ```javascript
  console.log(socket.url); // The WebSocket server URL
  ```

---

### 3. **WebSocket Methods**

The WebSocket API provides several methods to send and manage data on the connection.

#### Methods:

- **`send(data)`**: Sends data to the server through the WebSocket connection. The data can be a `string`, `Blob`, `ArrayBuffer`, or `ArrayBufferView`. If the connection is closed, calling `send()` will result in an error.

  ```javascript
  socket.send('Hello, server!');
  ```

- **`close(code, reason)`**: Closes the WebSocket connection. Optionally, you can provide a `code` (numeric status code) and a `reason` (string) to explain the reason for closing the connection.
  
  - `code`: A numeric code that indicates the status of the closure (e.g., `1000` for normal closure).
  - `reason`: A string explaining the reason for the closure.

  ```javascript
  socket.close(1000, 'Normal closure');
  ```

---

### 4. **WebSocket Events**

The WebSocket API has various events that notify you of changes in the connection’s state and allow you to react to messages.

#### Events:

- **`onopen`**: Triggered when the WebSocket connection is successfully established. This is the first event fired once the handshake is complete.
  
  ```javascript
  socket.onopen = function(event) {
      console.log('Connection established');
      socket.send('Hello server!');
  };
  ```

- **`onmessage`**: Triggered when a message is received from the server. The `event` object contains the message data, which can be accessed using `event.data`.

  ```javascript
  socket.onmessage = function(event) {
      console.log('Message from server:', event.data);
  };
  ```

- **`onerror`**: Triggered when an error occurs with the WebSocket connection. The `event` object contains error details.

  ```javascript
  socket.onerror = function(event) {
      console.log('Error occurred:', event);
  };
  ```

- **`onclose`**: Triggered when the WebSocket connection is closed, either by the server or the client. The `event` object contains details about the closure, such as the `code` and `reason`.

  ```javascript
  socket.onclose = function(event) {
      console.log('Connection closed:', event.code, event.reason);
  };
  ```

---

### 5. **Example of Full WebSocket Client API Usage**

Here is a full example of using the WebSocket API on the client side, including handling messages, sending data, and closing the connection:

```javascript
// Create a new WebSocket connection to the server
const socket = new WebSocket('ws://example.com/socket');

// Event handler when the connection is successfully established
socket.onopen = function(event) {
    console.log('Connection opened!');
    socket.send('Hello, server!');
};

// Event handler for receiving messages from the server
socket.onmessage = function(event) {
    console.log('Message from server:', event.data);
};

// Event handler when the connection is closed
socket.onclose = function(event) {
    console.log('Connection closed');
    console.log('Code:', event.code);
    console.log('Reason:', event.reason);
};

// Event handler for errors that occur with the WebSocket connection
socket.onerror = function(event) {
    console.error('WebSocket error:', event);
};

// Close the WebSocket connection after some time
setTimeout(function() {
    socket.close(1000, 'Client finished communication');
}, 5000);
```

### 6. **WebSocket Close Codes**

When closing a WebSocket connection, the connection may be closed with a numeric status code to explain the reason for the closure. The most common codes include:

- **`1000`**: Normal closure. This is the default code for a successful and clean closure of the WebSocket connection.
- **`1001`**: Going away. This indicates that the server or client is shutting down or going offline.
- **`1002`**: Protocol error. This indicates that the connection could not be processed due to protocol errors.
- **`1003`**: Unsupported data. This code indicates that the server or client cannot handle the data being sent.
- **`1006`**: Abnormal closure. This indicates an unexpected termination of the connection.
- **`1011`**: Internal server error. This is used when an error occurs at the server-side.

### 7. **WebSocket Subprotocols**

WebSocket subprotocols are used to define specific rules or message formats for WebSocket communication between the client and the server. They are negotiated during the WebSocket handshake and allow the client and server to agree on a common protocol to use for communication.

- **Negotiating Subprotocols**: You can specify one or more subprotocols when creating a WebSocket connection:

  ```javascript
  const socket = new WebSocket('ws://example.com/socket', ['protocol1', 'protocol2']);
  ```

  The server can then respond with an appropriate subprotocol that is agreed upon during the handshake.

---

### 8. **Error Handling with WebSocket API**

You should handle errors properly while using WebSocket connections to avoid unexpected crashes and to improve user experience.

- **`onerror` Event**: The `onerror` event fires when there is a failure in the WebSocket connection, such as network problems or protocol violations.
  
  ```javascript
  socket.onerror = function(event) {
      console.error('WebSocket error:', event);
  };
  ```

- **Reconnection Strategies**: In cases of errors, you may want to implement reconnection logic to re-establish the WebSocket connection.

---

### 9. **WebSocket Server API (Node.js)**

On the server side, a WebSocket server can be created using libraries such as `ws` in Node.js. Here’s an example of how to create a WebSocket server:

#### Example (Node.js with `ws`):

```javascript
const WebSocket = require('ws');

// Create a WebSocket server that listens on port 8080
const wss = new WebSocket.Server({ port: 8080 });

// Handle incoming WebSocket connections
wss.on('connection', (ws) => {
    console.log('New client connected!');
    
    // Send a message to the client
    ws.send('Hello from server');
    
    // Handle incoming messages from clients
    ws.on('message', (message) => {
        console.log('Received:', message);
        ws.send(`Server response: ${message}`);
    });
    
    // Handle connection close
    ws.on('close', () => {
        console.log('Client disconnected');
    });

    // Handle errors
    ws.on('error', (error) => {
        console.error('Error:', error);
    });
});
```

---

### Conclusion

The WebSocket API provides a simple and efficient way to establish real-time, full-duplex communication between clients and servers. The client-side WebSocket API allows developers to connect to WebSocket servers, send and receive messages, and handle various events like opening, closing, and errors. Similarly, WebSocket servers can handle multiple clients, manage connections, and broadcast messages, making it a powerful tool for

 building real-time applications.
