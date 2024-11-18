### WebSockets - Closing a Connection

Closing a WebSocket connection properly is essential for freeing up resources and ensuring a clean disconnection. Both the client and the server can initiate the closure of the WebSocket connection. The WebSocket protocol provides a clean way to handle the closing process, with specific events and status codes that indicate how and why the connection was closed.

---

### 1. **Client-Side: Closing a Connection**

In JavaScript, the WebSocket connection is closed using the `close()` method on the `WebSocket` object. This method allows you to specify a close code and a reason for closing the connection. If not provided, the connection will close with the default code.

#### Example: Client-Side Closing a Connection

```javascript
// Establish a WebSocket connection
const socket = new WebSocket('ws://example.com/socket');

// Event handler for when the connection is opened
socket.onopen = function(event) {
    console.log('Connection established!');

    // Closing the connection after sending a message
    socket.send('Hello, server!');
    socket.close(1000, 'Normal closure'); // 1000 indicates a normal closure
};

// Event handler for connection closure
socket.onclose = function(event) {
    console.log('Connection closed:', event.code, event.reason);
};

// Event handler for receiving messages from the server
socket.onmessage = function(event) {
    console.log('Message from server:', event.data);
};

// Event handler for errors
socket.onerror = function(error) {
    console.error('WebSocket error:', error);
};
```

### Explanation:

- **`socket.close(code, reason)`**:
  - `code`: A numeric code indicating the reason for closing the connection. Common codes are:
    - `1000`: Normal closure, the connection was successfully closed.
    - `1001`: Going away, the client or server is shutting down.
    - `1002`: Protocol error, there was a protocol violation.
    - `1003`: Unsupported data, the client sent unsupported data.
    - `1006`: Abnormal closure, the connection was closed unexpectedly (e.g., network error).
    - `1011`: Server error, the server encountered an error while processing the request.
  - `reason`: An optional string that describes why the connection is being closed. It can be helpful for debugging or providing context.
  
- **`onclose` Event**:
  The `onclose` event is triggered when the connection is closed. The event object contains `code` and `reason` properties, which help to identify how and why the connection was closed.
  
---

### 2. **Server-Side: Closing a Connection**

On the server-side, WebSocket connections are typically handled using libraries like `ws` (in Node.js). The server can close the connection using the `close()` method on the WebSocket object (`ws`). Just like the client, the server can specify a close code and an optional reason.

#### Example: Server-Side Closing a Connection (Node.js with `ws`)

```javascript
const WebSocket = require('ws');

// Create a new WebSocket server
const wss = new WebSocket.Server({ port: 8080 });

// Handle new client connections
wss.on('connection', function connection(ws) {
    console.log('A new client connected');
    
    // Send a message to the client
    ws.send('Welcome to the WebSocket server!');
    
    // Close the connection after 5 seconds
    setTimeout(() => {
        ws.send('Closing the connection after 5 seconds');
        ws.close(1000, 'Normal closure');
    }, 5000);
    
    // Handle incoming messages from the client
    ws.on('message', function incoming(message) {
        console.log('Received message from client:', message);
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

- **`ws.close(code, reason)`**:
  - Just like the client, the server can call the `close()` method on the `ws` object to close the connection. This can be done programmatically after performing some actions (e.g., sending a message) or in response to some condition.

- **Handling the `close` Event**:
  - The `on('close')` event is triggered when the connection is closed, either by the client or the server. It can be used to clean up resources or log information about the disconnection.

---

### 3. **Close Event Handling and Codes**

The `onclose` event in both client and server gives you access to the status code and reason for the closure. This information is crucial for understanding why the connection was closed and can be helpful for debugging.

#### Example of Handling Close Event in JavaScript (Client-Side):

```javascript
socket.onclose = function(event) {
    console.log('Connection closed');
    console.log('Close code:', event.code);
    console.log('Close reason:', event.reason);

    // Handle different close codes
    if (event.code === 1000) {
        console.log('Connection closed normally');
    } else if (event.code === 1006) {
        console.log('Connection closed abnormally');
    } else {
        console.log('Unexpected closure with code:', event.code);
    }
};
```

#### Example of Handling Close Event on Server-Side (Node.js with `ws`):

```javascript
ws.on('close', function(code, reason) {
    console.log('Connection closed');
    console.log('Close code:', code);
    console.log('Close reason:', reason);

    // Handle different close codes
    if (code === 1000) {
        console.log('Connection closed normally');
    } else if (code === 1006) {
        console.log('Connection closed abnormally');
    } else {
        console.log('Unexpected closure with code:', code);
    }
});
```

---

### 4. **Graceful Closing of a WebSocket Connection**

A graceful WebSocket connection closure involves both parties agreeing to close the connection. This usually happens when the server or client sends a **close frame** to initiate the closure. The other party then acknowledges the close frame and the connection is terminated.

1. **Initiating the Closure**:
   - Either the client or the server can initiate the closure by calling `close()` and optionally providing a code and reason.
   
2. **Acknowledging the Closure**:
   - Once the closure is initiated, the other party should acknowledge it by receiving the `close` event and optionally sending a close frame back if needed.

---

### 5. **Abnormal Closure**

An **abnormal closure** occurs when the connection is closed unexpectedly, typically due to network failures, server crashes, or a client being disconnected unexpectedly. In this case, you might receive the `onclose` event with a `1006` status code, which indicates that the WebSocket connection was closed without sending a close frame.

Example of detecting abnormal closure in the client:

```javascript
socket.onclose = function(event) {
    if (event.code === 1006) {
        console.error('Connection was closed unexpectedly!');
    } else {
        console.log('Connection closed normally.');
    }
};
```

---

### 6. **Reconnection Logic After Closing**

In some real-time applications, you may want to automatically attempt to reconnect after the WebSocket connection is closed. This can be done by implementing a reconnection strategy in the `onclose` event handler.

Example of automatic reconnection:

```javascript
socket.onclose = function(event) {
    console.log('Connection closed. Attempting to reconnect...');
    
    // Retry the connection after a delay (e.g., 3 seconds)
    setTimeout(function() {
        socket = new WebSocket('ws://example.com/socket');
        console.log('Reconnected to the WebSocket server');
    }, 3000);
};
```

---

### Conclusion

Closing a WebSocket connection involves using the `close()` method, which can be called by either the client or server. This method allows you to specify a close code and an optional reason for closing the connection. The connection is gracefully closed by sending a "close" frame, and both parties should handle the `onclose` event to properly manage the disconnection.

- **Graceful Closure**: Initiate a connection close with `close()`, and the other party should acknowledge it.
- **Abnormal Closure**: If the connection is closed unexpectedly (e.g., network failure), the code `1006` will be used to indicate that the connection was closed unexpectedly.
- **Reconnection**: You can implement automatic reconnection logic in the event of closure to maintain continuous communication.
