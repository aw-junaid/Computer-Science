PCAP (Packet Capture) files store network traffic data, and processing them is a common task in network analysis, security, and troubleshooting. Python provides various libraries for working with PCAP files, and one of them is `scapy`, which is used in the code you provided. Here's how to process PCAP files using `scapy`:

Assuming you have a PCAP file named `arper.pcap` generated from the previous ARP poisoning script, you can use the following code to read and process the contents of the PCAP file:

```python
from scapy.all import rdpcap

# Load the PCAP file
pcap_file = 'arper.pcap'
packets = rdpcap(pcap_file)

# Process each packet
for packet in packets:
    # Access packet information and fields
    if packet.haslayer(IP):
        # IP layer information
        src_ip = packet[IP].src
        dst_ip = packet[IP].dst

        # Print IP addresses
        print(f"Source IP: {src_ip}, Destination IP: {dst_ip}")

    elif packet.haslayer(TCP):
        # TCP layer information
        src_port = packet[TCP].sport
        dst_port = packet[TCP].dport

        # Print TCP ports
        print(f"Source Port: {src_port}, Destination Port: {dst_port}")

    # You can add more conditions to handle other protocol layers (e.g., UDP, ICMP, etc.)

    print("----------")
```

Explanation:

1. **Import `rdpcap` from `scapy.all`:**
   - `rdpcap` is a function in Scapy that reads a PCAP file and returns a list of packets.

2. **Load the PCAP File:**
   ```python
   pcap_file = 'arper.pcap'
   packets = rdpcap(pcap_file)
   ```
   - Replace `'arper.pcap'` with the actual path to your PCAP file.
   - `packets` now contains a list of packet objects.

3. **Process Each Packet:**
   ```python
   for packet in packets:
       # Access packet information and fields
       if packet.haslayer(IP):
           # Access IP layer information
           src_ip = packet[IP].src
           dst_ip = packet[IP].dst

           # Print IP addresses
           print(f"Source IP: {src_ip}, Destination IP: {dst_ip}")

       elif packet.haslayer(TCP):
           # Access TCP layer information
           src_port = packet[TCP].sport
           dst_port = packet[TCP].dport

           # Print TCP ports
           print(f"Source Port: {src_port}, Destination Port: {dst_port}")

       # You can add more conditions to handle other protocol layers (e.g., UDP, ICMP, etc.)

       print("----------")
   ```
   - Loop through each packet in the PCAP file.
   - Check if the packet has an IP layer (`haslayer(IP)`) and print source and destination IP addresses.
   - Check if the packet has a TCP layer (`haslayer(TCP)`) and print source and destination ports.
   - You can add more conditions to handle other protocol layers (e.g., UDP, ICMP, etc.).

This code is a basic example of processing PCAP files using `scapy`. Depending on your specific analysis goals, you may need to extract and analyze more details from the packets.
