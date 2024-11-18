### WebSockets - Events & Actions

WebSockets provide a simple, event-driven API that enables developers to handle various events that occur during the lifecycle of a WebSocket connection. These events can be used to trigger specific actions when something happens, such as opening a connection, receiving a message, or encountering an error.

Below, we'll break down the key WebSocket events, their associated actions, and how to handle them both on the client and server sides.

### 1. **Client-Side WebSocket Events**

In the browser, WebSocket connections are represented by the `WebSocket` object, which exposes several important events that allow you to handle the lifecycle of the connection and its interactions.

#### Key WebSocket Events in JavaScript (Client-Side)

1. **`onopen`** – Fired when the WebSocket connection is successfully established.
   - **Action**: Once the connection is open, you can begin sending messages or perform initialization actions.
   
   ```javascript
   const socket = new WebSocket('ws://example.com/socket');
   
   socket.onopen = function(event) {
       console.log('Connection opened!');
       socket.send('Hello, server!');  // Send message after connection is open
   };
   ```

2. **`onmessage`** – Fired when a message is received from the server.
   - **Action**: You can process the incoming data, whether it's text or binary, and update the UI or perform other actions based on the data received.
   
   ```javascript
   socket.onmessage = function(event) {
       console.log('Message from server: ', event.data);
       // Process the received message
   };
   ```

3. **`onclose`** – Fired when the WebSocket connection is closed, either by the client or the server.
   - **Action**: Perform cleanup operations, such as updating the UI or attempting to reconnect.
   
   ```javascript
   socket.onclose = function(event) {
       console.log('Connection closed', event);
       // Optionally attempt to reconnect or clean up resources
   };
   ```

4. **`onerror`** – Fired when there is an error with the WebSocket connection.
   - **Action**: Log the error, show error messages to the user, or attempt to reconnect.
   
   ```javascript
   socket.onerror = function(error) {
       console.error('WebSocket Error: ', error);
       // Handle errors (e.g., display error message or try reconnecting)
   };
   ```

5. **`send()`** – This is an action (method) you can use to send data to the WebSocket server.
   - **Action**: Send a message or data (text or binary) to the connected server.
   
   ```javascript
   socket.send('Hello from the client');
   ```

6. **`close()`** – This is an action (method) to close the WebSocket connection.
   - **Action**: Explicitly close the WebSocket connection.
   
   ```javascript
   socket.close();
   ```

### Example (Client-Side):

```javascript
const socket = new WebSocket('ws://example.com/socket');

// Open connection and send a message
socket.onopen = function(event) {
    console.log('Connection opened');
    socket.send('Hello, Server!');
};

// Handle incoming messages
socket.onmessage = function(event) {
    console.log('Received message: ' + event.data);
};

// Handle connection closure
socket.onclose = function(event) {
    console.log('Connection closed');
};

// Handle errors
socket.onerror = function(error) {
    console.error('WebSocket error:', error);
};

// Sending a message later
function sendMessage(message) {
    socket.send(message);
}

// Closing the connection
function closeConnection() {
    socket.close();
}
```

### 2. **Server-Side WebSocket Events**

On the server side, handling WebSocket events depends on the platform and WebSocket library being used. Below are examples of handling WebSocket events in popular server-side environments.

#### Example 1: **Node.js with `ws` Library**

In Node.js, the `ws` library is commonly used to create WebSocket servers and handle WebSocket events like `connection`, `message`, `close`, and `error`.

##### Key Server-Side WebSocket Events:

1. **`'connection'`** – Fired when a new client connects to the server.
   - **Action**: Establish communication with the connected client by sending or receiving data.
   
   ```javascript
   const WebSocket = require('ws');
   const wss = new WebSocket.Server({ port: 8080 });
   
   wss.on('connection', function connection(ws) {
       console.log('Client connected');
       ws.send('Welcome to the server!');  // Send message to client on connection

       // Handling client messages
       ws.on('message', function incoming(message) {
           console.log('Received: %s', message);
           ws.send('Server received: ' + message);  // Respond to client
       });

       // Handling connection closure
       ws.on('close', function() {
           console.log('Client disconnected');
       });
   });
   ```

2. **`'message'`** – Fired when a message is received from a client.
   - **Action**: Process the message from the client and respond as needed.

3. **`'close'`** – Fired when the WebSocket connection is closed, either by the client or server.
   - **Action**: Handle cleanup or logging when a client disconnects.

4. **`'error'`** – Fired when there is an error in the WebSocket connection.
   - **Action**: Log the error or notify the client.

#### Example (Node.js with `ws`):

```javascript
const WebSocket = require('ws');
const wss = new WebSocket.Server({ port: 8080 });

wss.on('connection', function connection(ws) {
    console.log('A client connected');
    
    // Send a welcome message
    ws.send('Welcome to the WebSocket server!');
    
    // Handle incoming messages from the client
    ws.on('message', function incoming(message) {
        console.log('Received message: ' + message);
        ws.send('Server says: ' + message);  // Respond to client
    });
    
    // Handle disconnection event
    ws.on('close', function() {
        console.log('Client disconnected');
    });

    // Handle errors
    ws.on('error', function(error) {
        console.error('WebSocket error: ', error);
    });
});

console.log('WebSocket server is listening on ws://localhost:8080');
```

#### Key Server-Side WebSocket Events:
- **`'connection'`**: Triggered when a new client connects.
- **`'message'`**: Triggered when a message is received from the client.
- **`'close'`**: Triggered when the WebSocket connection is closed.
- **`'error'`**: Triggered when an error occurs during the WebSocket communication.

### 3. **Handling Data Types in WebSocket Messages**

WebSocket messages can either be **text** (UTF-8) or **binary**. WebSocket libraries typically allow you to send and receive both text and binary data (e.g., `Blob`, `ArrayBuffer`).

#### Sending Text Data:
```javascript
socket.send("Hello, Server!");  // Send a text message
```

#### Sending Binary Data:
```javascript
const arrayBuffer = new ArrayBuffer(8);  // Create an ArrayBuffer
socket.send(arrayBuffer);  // Send binary data
```

### 4. **Actions on Error or Reconnection**

In case of connection errors or disconnections, WebSocket provides a way to handle errors and attempt reconnections.

#### Client-Side Example (Reconnection on Error):

```javascript
let socket;

function connect() {
    socket = new WebSocket('ws://example.com/socket');
    
    socket.onopen = function() {
        console.log('Connected');
    };

    socket.onerror = function(error) {
        console.error('WebSocket error: ', error);
        // Try reconnecting after 5 seconds
        setTimeout(connect, 5000);
    };

    socket.onclose = function() {
        console.log('Connection closed');
    };
}

connect();  // Start connection
```

---

### Summary of WebSocket Events & Actions:

1. **Client-Side Events:**
   - `onopen`: Triggered when the connection is established.
   - `onmessage`: Triggered when a message is received from the server.
   - `onclose`: Triggered when the connection is closed.
   - `onerror`: Triggered when an error occurs in the WebSocket connection.
   - `send()`: Method to send messages to the server.
   - `close()`: Method to close the WebSocket connection.

2. **Server-Side Events:**
   - `'connection'`: Triggered when a client connects.
   - `'message'`: Triggered when a message is received from a client.
   - `'close'`: Triggered when the WebSocket connection is closed.
   - `'error'`: Triggered when an error occurs in the connection.

3. **Data Types**: 
   - WebSockets support both text and binary data (e.g., `ArrayBuffer`, `Blob`).
   - Binary messages are supported alongside text messages.

4. **Error Handling & Reconnection**: 
   - Both client and server can handle errors and take actions like reconnecting or logging the error.

These events and actions allow WebSockets to provide a robust, real-time, and responsive communication channel for many types of applications, including chat apps, gaming, live updates, and more.
