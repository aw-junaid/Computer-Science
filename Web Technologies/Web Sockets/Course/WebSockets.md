WebSockets are a protocol for full-duplex communication channels over a single, long-lived TCP connection, commonly used in web applications. Unlike HTTP, which is a request-response protocol, WebSockets allow for persistent connections where both the server and client can send and receive messages independently, making it ideal for real-time communication.

### Key Features of WebSockets:
- **Bi-directional communication**: Both the client and server can send data at any time, without needing to wait for a request.
- **Low latency**: WebSockets eliminate the need for repetitive HTTP requests and responses, reducing the overhead and latency.
- **Persistent connection**: Once established, the connection stays open until closed explicitly by either party.
- **Efficient**: Since the connection remains open, there is no need for repeated handshakes or headers like in HTTP.

### Use Cases:
- **Real-time applications**: WebSockets are used in chat applications, live notifications, stock ticker updates, online multiplayer games, and collaborative tools.
- **Streaming data**: For applications that require the continuous flow of data, such as financial services (real-time stock prices), or social media updates.

### How WebSocket Works:
1. **Handshake**: A WebSocket connection begins with an HTTP request. The client sends an HTTP request with an `Upgrade` header, indicating that it wants to establish a WebSocket connection.
2. **Protocol Switching**: The server responds with an HTTP 101 status code (Switching Protocols) if it supports WebSockets, and the connection is upgraded from HTTP to WebSocket.
3. **Data Exchange**: After the handshake, both client and server can send and receive data in the form of "frames" until the connection is closed.
4. **Closing the Connection**: Either party can initiate a graceful closure of the connection by sending a special "close" frame.

### WebSocket API (in JavaScript):
```javascript
// Create a new WebSocket connection
const socket = new WebSocket('ws://example.com/socket');

// Event handler when the connection is opened
socket.onopen = function(event) {
    console.log('Connection established');
    socket.send('Hello, server!');
};

// Event handler when a message is received
socket.onmessage = function(event) {
    console.log('Message from server: ' + event.data);
};

// Event handler when the connection is closed
socket.onclose = function(event) {
    console.log('Connection closed');
};

// Event handler for errors
socket.onerror = function(error) {
    console.error('WebSocket error: ' + error);
};
```

### Security Considerations:
- **WSS (WebSocket Secure)**: Similar to HTTPS, WebSockets can be secured using WSS, where the communication is encrypted over TLS/SSL.
- **Cross-origin requests**: Since WebSockets are not constrained by the same-origin policy, special care should be taken to avoid cross-origin attacks.

WebSockets are an essential tool for applications requiring real-time interactions and low-latency updates.
