### Common Ports in Networking  

Ports are virtual endpoints used in networking to identify specific processes or services on a device. They are part of the **Transport Layer** in the **OSI model** and are essential for managing communication between devices. Ports work with protocols like **TCP** and **UDP** to ensure that data is sent and received by the correct application.

---

#### **What are Ports?**
- A **port** is a 16-bit number that ranges from **0 to 65535**.
- Ports are associated with IP addresses to form a **socket** (e.g., `192.168.1.1:80`).
- Ports allow multiple applications to use the same IP address without conflict.

---

#### **Types of Ports**
1. **Well-Known Ports (0–1023)**:  
   Reserved for standard services and protocols.
2. **Registered Ports (1024–49151)**:  
   Assigned to specific services by software developers.
3. **Dynamic/Private Ports (49152–65535)**:  
   Used for temporary or ephemeral connections.

---

#### **List of Common Ports**  

| **Port Number** | **Protocol**     | **Service/Usage**                             |
|------------------|------------------|-----------------------------------------------|
| **20, 21**       | TCP              | FTP (File Transfer Protocol) - Data and Control |
| **22**           | TCP              | SSH (Secure Shell)                            |
| **23**           | TCP              | Telnet (Unsecured Remote Login)               |
| **25**           | TCP              | SMTP (Simple Mail Transfer Protocol)          |
| **53**           | UDP/TCP          | DNS (Domain Name System)                      |
| **67, 68**       | UDP              | DHCP (Dynamic Host Configuration Protocol)    |
| **69**           | UDP              | TFTP (Trivial File Transfer Protocol)         |
| **80**           | TCP              | HTTP (Hypertext Transfer Protocol)            |
| **110**          | TCP              | POP3 (Post Office Protocol v3)                |
| **143**          | TCP              | IMAP (Internet Message Access Protocol)       |
| **161, 162**     | UDP              | SNMP (Simple Network Management Protocol)     |
| **443**          | TCP              | HTTPS (HTTP Secure)                           |
| **465**          | TCP              | SMTPS (SMTP Secure)                           |
| **993**          | TCP              | IMAPS (IMAP Secure)                           |
| **995**          | TCP              | POP3S (POP3 Secure)                           |
| **3389**         | TCP              | RDP (Remote Desktop Protocol)                 |
| **5432**         | TCP              | PostgreSQL                                    |
| **3306**         | TCP              | MySQL                                         |
| **6379**         | TCP              | Redis                                         |
| **27017**        | TCP              | MongoDB                                       |

---

#### **Purpose of Common Ports**
1. **HTTP and HTTPS (80, 443)**:
   - HTTP: Used for standard web traffic.
   - HTTPS: Secure version of HTTP using encryption.  

2. **DNS (53)**:  
   Resolves domain names to IP addresses.  

3. **SMTP, POP3, and IMAP (25, 110, 143)**:  
   Facilitate sending and receiving emails.  

4. **SSH and Telnet (22, 23)**:  
   Provide remote login, with SSH being secure and Telnet not encrypted.  

5. **FTP and TFTP (20, 21, 69)**:  
   Enable file transfers between devices.  

---

#### **Dynamic Ports and Ephemeral Ports**
- Used for temporary communication, such as by client devices during web browsing or API requests.  
- Operating systems typically assign these ports dynamically in the range **49152–65535**.  

---

#### **Security Concerns**
- Unused or open ports can be exploited by attackers.
- Best practices include:
  - Closing unused ports.
  - Using a firewall to filter traffic.
  - Employing network monitoring tools to detect unusual activity.

---
This list highlights essential ports and their functions.
