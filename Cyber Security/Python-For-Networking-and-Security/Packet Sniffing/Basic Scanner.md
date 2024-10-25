```python
import socket
import os
import struct
import threading
from ipaddress import ip_address, ip_network
from ctypes import *

# host to listen on
host = "192.168.0.187"

# subnet to target
tgt_subnet = "192.168.0.0/24"

# magic we'll check ICMP responses for
tgt_message = "PYTHONRULES!"


def udp_sender(sub_net, magic_message):
    sender = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    for ip in ip_network(sub_net).hosts():
        sender.sendto(magic_message.encode('utf-8'), (str(ip), 65212))


class IP(Structure):
    _fields_ = [
        ("ihl", c_ubyte, 4),
        ("version", c_ubyte, 4),
        ("tos", c_ubyte),
        ("len", c_ushort),
        ("id", c_ushort),
        ("offset", c_ushort),
        ("ttl", c_ubyte),
        ("protocol_num", c_ubyte),
        ("sum", c_ushort),
        ("src", c_uint32),
        ("dst", c_uint32)
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
        ("type", c_ubyte),
        ("code", c_ubyte),
        ("checksum", c_ushort),
        ("unused", c_ushort),
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

# start sending packets
t = threading.Thread(target=udp_sender, args=(tgt_subnet, tgt_message))
t.start()

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

            # now check for the TYPE 3 and CODE 3 which indicates
            # a host is up but no port available to talk to           
            if icmp_header.code == 3 and icmp_header.type == 3:

                # check to make sure we are receiving the response 
                # that lands in our subnet
                if ip_address(ip_header.src_address) in ip_network(tgt_subnet):

                    # test for our magic message
                    if raw_buffer[len(raw_buffer)
                       - len(tgt_message):] == tgt_message:
                        print("Host Up: %s" % ip_header.src_address)

# handle CTRL-C
except KeyboardInterrupt:
    # if we're on Windows turn off promiscuous mode
    if os.name == "nt":
        sniffer.ioctl(socket.SIO_RCVALL, socket.RCVALL_OFF)
```
Certainly! Let's break down the code:

1. **Raw Socket Initialization:**
    ```python
    if os.name == "nt":
        socket_protocol = socket.IPPROTO_IP
    else:
        socket_protocol = socket.IPPROTO_ICMP

    sniffer = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket_protocol)
    sniffer.bind((host, 0))
    sniffer.setsockopt(socket.IPPROTO_IP, socket.IP_HDRINCL, 1)

    if os.name == "nt":
        sniffer.ioctl(socket.SIO_RCVALL, socket.RCVALL_ON)
    ```
    - Checks the operating system type. If it's Windows (`os.name == "nt"`), uses `socket.IPPROTO_IP` as the protocol; otherwise, uses `socket.IPPROTO_ICMP`.
    - Creates a raw socket (`socket.AF_INET` for IPv4) and binds it to the specified host on any available port (`(host, 0)`).
    - Sets a socket option to include IP headers in the captured data.
    - If on Windows, enables promiscuous mode using `sniffer.ioctl`.

2. **Thread for UDP Sender:**
    ```python
    t = threading.Thread(target=udp_sender, args=(tgt_subnet, tgt_message))
    t.start()
    ```
    - Creates a new thread that will execute the `udp_sender` function with the specified arguments (`tgt_subnet` and `tgt_message`).
    - Starts the thread to concurrently send UDP packets while the main thread captures and processes incoming packets.

3. **Packet Sniffing Loop:**
    ```python
    while True:
        raw_buffer = sniffer.recvfrom(65535)[0]
        ip_header = IP(raw_buffer[:20])
    ```
    - Enters an infinite loop for capturing packets using `sniffer.recvfrom(65535)`.
    - Reads the raw packet data and extracts the first 20 bytes to create an `IP` structure (`ip_header`).

4. **Handling ICMP Packets:**
    ```python
        if ip_header.protocol == "ICMP":
            offset = ip_header.ihl * 4
            buf = raw_buffer[offset:offset + sizeof(ICMP)]
            icmp_header = ICMP(buf)
    ```
    - Checks if the captured packet is an ICMP packet based on the protocol field in the IP header.
    - Calculates the offset to locate the ICMP header within the raw packet data.
    - Creates an `ICMP` structure (`icmp_header`) from the extracted ICMP header data.

5. **Checking for Host Availability:**
    ```python
            if icmp_header.code == 3 and icmp_header.type == 3:
                if ip_address(ip_header.src_address) in ip_network(tgt_subnet):
                    if raw_buffer[len(raw_buffer) - len(tgt_message):] == tgt_message:
                        print("Host Up: %s" % ip_header.src_address)
    ```
    - Checks if the ICMP packet indicates a host is up (ICMP type 3 and code 3).
    - Verifies that the source IP is within the specified target subnet.
    - Compares the end of the raw packet data with the predefined `tgt_message` to confirm the host's availability.
    - If all conditions are met, prints a message indicating that the host is up.

6. **KeyboardInterrupt Handling:**
    ```python
except KeyboardInterrupt:
    if os.name == "nt":
        sniffer.ioctl(socket.SIO_RCVALL, socket.RCVALL_OFF)
    ```
    - Handles a `KeyboardInterrupt` exception (Ctrl+C).
    - If on Windows, disables promiscuous mode using `sniffer.ioctl(socket.SIO_RCVALL, socket.RCVALL_OFF)`.
