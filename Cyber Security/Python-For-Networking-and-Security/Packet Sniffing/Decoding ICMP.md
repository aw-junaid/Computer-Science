```python
import socket
import os
import struct

from ctypes import *

# host to listen on
host = "192.168.0.187"


class IP(Structure):
    
    _fields_ = [
        ("ihl",           c_ubyte, 4),
        ("version",       c_ubyte, 4),
        ("tos",           c_ubyte),
        ("len",           c_ushort),
        ("id",            c_ushort),
        ("offset",        c_ushort),
        ("ttl",           c_ubyte),
        ("protocol_num",  c_ubyte),
        ("sum",           c_ushort),
        ("src",           c_uint32),
        ("dst",           c_uint32)
    ]

    def __new__(cls, socket_buffer=None):
        return cls.from_buffer_copy(socket_buffer)

    def __init__(self, socket_buffer=None):
        self.socket_buffer = socket_buffer

        # map protocol constants to their names
        self.protocol_map = {1: "ICMP", 6: "TCP", 17: "UDP"}
        
        # human readable IP addresses
        self.src_address = socket.inet_ntoa(struct.pack("@I", self.src))
        self.dst_address = socket.inet_ntoa(struct.pack("@I", self.dst))
    
        # human readable protocol
        try:
            self.protocol = self.protocol_map[self.protocol_num]
        except IndexError:
            self.protocol = str(self.protocol_num)


class ICMP(Structure):
    
    _fields_ = [
        ("type",         c_ubyte),
        ("code",         c_ubyte),
        ("checksum",     c_ushort),
        ("unused",       c_ushort),
        ("next_hop_mtu", c_ushort)
        ]
    
    def __new__(cls, socket_buffer):
        return cls.from_buffer_copy(socket_buffer)

    def __init__(self, socket_buffer):
        self.socket_buffer = socket_buffer


# create a raw socket and bind it to the public interface
if os.name == "nt":
    socket_protocol = socket.IPPROTO_IP 
else:
    socket_protocol = socket.IPPROTO_ICMP
    
sniffer = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket_protocol)

sniffer.bind((host, 0))

# we want the IP headers included in the capture
sniffer.setsockopt(socket.IPPROTO_IP, socket.IP_HDRINCL, 1)

# if we're on Windows we need to send some ioctl
# to setup promiscuous mode
if os.name == "nt":
    sniffer.ioctl(socket.SIO_RCVALL, socket.RCVALL_ON)


try:
    while True:
        # read in a single packet
        raw_buffer = sniffer.recvfrom(65535)[0]
        
        # create an IP header from the first 20 bytes of the buffer
        ip_header = IP(raw_buffer[:20])
      
        print("Protocol: %s %s -> %s" % (
            ip_header.protocol,
            ip_header.src_address,
            ip_header.dst_address)
              )

        # if it's ICMP we want it
        if ip_header.protocol == "ICMP":
            # calculate where our ICMP packet starts
            offset = ip_header.ihl * 4
            buf = raw_buffer[offset:offset + sizeof(ICMP)]
            
            # create our ICMP structure
            icmp_header = ICMP(buf)
            
            print("ICMP -> Type: %d Code: %d" % (
                icmp_header.type,
                icmp_header.code)
                  )

# handle CTRL-C
except KeyboardInterrupt:
    # if we're on Windows turn off promiscuous mode
    if os.name == "nt":
        sniffer.ioctl(socket.SIO_RCVALL, socket.RCVALL_OFF)
```

This Python code is an extension of the previous packet-sniffing example, adding the ability to decode ICMP (Internet Control Message Protocol) packets in addition to IP headers. The script uses raw sockets to capture network traffic and print information about IP and ICMP packets.

Here's an explanation of the additional code for handling ICMP packets:

1. **Define the ICMP Structure:**
   - The `ICMP` class is defined similarly to the `IP` class. It represents the structure of an ICMP header, including fields such as type, code, checksum, unused, and next_hop_mtu.

2. **Initialize ICMP Header:**
   - The `__new__` method creates a new instance of the `ICMP` class by copying the buffer containing the raw data.
   - The `__init__` method initializes the `socket_buffer` attribute.

3. **Capture and Decode ICMP Packets:**
   - Inside the packet-sniffing loop, the script checks if the captured packet's protocol is ICMP:

     ```python
     if ip_header.protocol == "ICMP":
     ```

   - If the protocol is ICMP, the script calculates the offset to the ICMP header and creates an instance of the `ICMP` class to decode the ICMP header:

     ```python
     offset = ip_header.ihl * 4
     buf = raw_buffer[offset:offset + sizeof(ICMP)]
     icmp_header = ICMP(buf)
     ```

   - Finally, the script prints information about the ICMP packet, including the type and code:

     ```python
     print("ICMP -> Type: %d Code: %d" % (icmp_header.type, icmp_header.code))
     ```

4. **Handle CTRL-C:**
   - The script uses a `try-except` block to catch a `KeyboardInterrupt` (Ctrl+C) and gracefully handles it. Before exiting, it turns off promiscuous mode on Windows if it was enabled.

This code allows the script to capture and decode ICMP packets in addition to IP headers. As before, ensure you have the necessary privileges to run the script with raw sockets, and be aware of the legal and ethical considerations when capturing network traffic. Use this script responsibly and only in environments where you have the right to monitor and analyze network traffic.
