A comprehensive Wireshark cheat sheet that covers essential commands, features, and usage for network packet analysis. Wireshark is a powerful open-source network protocol analyzer used to capture and interactively browse the traffic running on a computer network.

---

# **Wireshark Cheat Sheet**

## **1. Installation**

### On Windows
- Download the installer from the [official Wireshark website](https://www.wireshark.org/download.html).

### On macOS
```bash
brew install wireshark
```

### On Linux (Ubuntu/Debian)
```bash
sudo apt update
sudo apt install wireshark
```

### On Linux (Fedora)
```bash
sudo dnf install wireshark
```

### Post-Installation
- **Grant Permissions**: Ensure that your user has permissions to capture packets (usually requires adding your user to the `wireshark` group).
  ```bash
  sudo usermod -aG wireshark $(whoami)
  ```

---

## **2. Starting Wireshark**

### 2.1 Launch Wireshark
- **GUI**: Open the Wireshark application from your applications menu or start menu.
- **Command Line**: Use the following command to start Wireshark with root privileges.
  ```bash
  sudo wireshark
  ```

### 2.2 Capture Options
- Go to **Capture** > **Options** or use the shortcut **Ctrl + K** to select the interface for capturing packets.

---

## **3. Basic Capturing Commands**

### 3.1 Start Capturing Packets
- Click on the interface you want to monitor (e.g., `eth0`, `wlan0`) from the main screen.

### 3.2 Stop Capturing Packets
- Click the red square button on the toolbar or use **Ctrl + E**.

### 3.3 Capture Specific Packets
- Start capturing with specific filters (more on filters below).

### 3.4 Save Capture
```bash
File > Save As...
```
- Save your capture to a file in `.pcap`, `.pcapng`, or other supported formats.

---

## **4. Display Filters**

Display filters allow you to specify criteria for which packets to display. Here are some common display filters:

| **Filter**                        | **Explanation**                                   |
|-----------------------------------|--------------------------------------------------|
| `ip`                              | Show all IP packets.                            |
| `tcp`                             | Show all TCP packets.                           |
| `udp`                             | Show all UDP packets.                           |
| `http`                            | Show all HTTP packets.                          |
| `icmp`                            | Show all ICMP packets.                          |
| `tcp.port == 80`                 | Show TCP packets on port 80.                    |
| `ip.addr == 192.168.1.1`         | Show packets from/to IP 192.168.1.1.           |
| `eth.src == 00:11:22:33:44:55`   | Show packets from the specified MAC address.    |
| `!(arp || icmp)`                 | Show all packets except ARP and ICMP.           |
| `frame.len > 1500`               | Show packets larger than 1500 bytes.            |
| `dns`                             | Show all DNS packets.                           |

### 4.1 Applying Display Filters
- Type the filter expression in the filter toolbar and press **Enter**.

---

## **5. Capture Filters**

Capture filters are used to specify which packets should be captured. Here are some common capture filters:

| **Filter**                        | **Explanation**                                   |
|-----------------------------------|--------------------------------------------------|
| `host 192.168.1.1`               | Capture traffic to and from the specified host. |
| `port 80`                         | Capture traffic on port 80.                      |
| `tcp`                             | Capture TCP packets.                             |
| `udp`                             | Capture UDP packets.                             |
| `src net 192.168.1.0/24`         | Capture packets from the specified subnet.       |
| `dst host 192.168.1.1`           | Capture packets destined for the specified host. |
| `tcp port 80 and src host 192.168.1.1` | Capture packets from a specific source on port 80.|

### 5.1 Setting Capture Filters
- Click **Capture Options**, enter the filter in the **Capture Filter** field, and start capturing.

---

## **6. Analyzing Packets**

### 6.1 Packet Details
- **Click on a Packet**: Expands details in the middle pane, showing protocol layers.
- **Right-click a Packet**: Offers options such as "Follow" TCP/UDP stream to analyze the conversation.

### 6.2 Follow TCP/UDP Stream
- **TCP Stream**: Right-click on a TCP packet, select **Follow** > **TCP Stream** to view the entire conversation.
- **UDP Stream**: Similar process for UDP packets.

### 6.3 Statistics
- Go to **Statistics** in the menu bar to access various statistics, including:
  - **Protocol Hierarchy**: Overview of protocols in the capture.
  - **Conversations**: Lists all conversations between hosts.
  - **Endpoints**: Lists all devices that communicated.

---

## **7. Exporting Data**

### 7.1 Exporting Packet Data
- Go to **File** > **Export Specified Packets** to save selected packets.

### 7.2 Export to CSV or JSON
- Go to **File** > **Export Packet Dissections** > **As CSV** or **As JSON** for further analysis.

---

## **8. Common Shortcuts**

| **Action**                            | **Shortcut**       |
|---------------------------------------|---------------------|
| Start Capture                         | Ctrl + E            |
| Stop Capture                          | Ctrl + E            |
| Open Capture File                     | Ctrl + O            |
| Save Capture File                     | Ctrl + S            |
| Find Packet                           | Ctrl + F            |
| Go to Next Packet                     | Ctrl + N            |
| Go to Previous Packet                 | Ctrl + P            |
| Show/Hide Packet Details              | Ctrl + D            |
| Toggle Display Filter                 | Ctrl + R            |

---

## **9. Useful Commands in Terminal**

### 9.1 Capture Packets with TShark
TShark is the command-line version of Wireshark.

- **Capture to File**
  ```bash
  tshark -i eth0 -w capture.pcap
  ```
  **Explanation**: Captures packets on the `eth0` interface and saves them to `capture.pcap`.

- **Read from File**
  ```bash
  tshark -r capture.pcap
  ```
  **Explanation**: Reads and displays packets from the specified file.

- **Filter during Capture**
  ```bash
  tshark -i eth0 -f "tcp port 80" -w capture.pcap
  ```
  **Explanation**: Captures only TCP packets on port 80.

---

## **10. Conclusion**

Wireshark is a powerful tool for analyzing network traffic and troubleshooting issues. This cheat sheet provides a quick reference for essential commands, filters, and features in Wireshark. For more advanced usage and features, refer to the official [Wireshark documentation](https://www.wireshark.org/docs/).
