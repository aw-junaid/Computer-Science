### UDP (User Datagram Protocol) is an unreliable, unordered, connectionless protocol for sending and receiving data. It is a simpler and more efficient protocol than TCP, but it does not provide the same level of reliability or ordering guarantees.

```
UDP
├────────────── UDP Header
│    ├── 16-bit Source Port
│    ├── 16-bit Destination Port
│    ├── 8-bit Length
│    ├── 8-bit Checksum
│    └── Variable Length Data
├────────────── Characteristics
│    ├── Unreliable
│    ├── Unordered
│    ├── Connectionless
│    ├── Fast
│    ├── Efficient
├────────────── Applications
│    ├── DNS
│    ├── VoIP
│    ├── Online gaming
│    ├── Video streaming
│    └── File sharing
```

UDP is often used for applications that require low latency or high throughput, such as DNS, VoIP, online gaming, video streaming, and file sharing. It is also used for applications that do not require reliable delivery, such as logging and monitoring.

Here are some of the key differences between UDP and TCP:

| Feature | UDP | TCP |
|---|---|---|
| Reliability | Unreliable | Reliable |
| Ordering | Unordered | Ordered |
| Connection | Connectionless | Connection-oriented |
| Overhead | Low | High |
| Latency | Low | High |
| Throughput | High | Low |

UDP is a versatile protocol that can be used for a wide variety of applications. It is a good choice for applications that require low latency or high throughput, but it is not a good choice for applications that require reliable delivery.
