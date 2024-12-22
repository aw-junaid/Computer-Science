### **Network Configuration and System Monitoring Tools in Linux**

In Linux, network configuration and system monitoring are essential tasks for ensuring that the system is performing optimally and that network connectivity is properly configured. Below is an overview of commonly used tools for these tasks.

---

### **1. Network Configuration Tools**

#### **a. `ifconfig` (Interface Configuration)**

The `ifconfig` command is used to configure network interfaces on Unix-like systems. It is used to view or change the configuration of network interfaces.

- **View network interfaces**:
   ```bash
   ifconfig
   ```

- **View a specific network interface**:
   ```bash
   ifconfig eth0
   ```

- **Assign an IP address to an interface**:
   ```bash
   sudo ifconfig eth0 192.168.1.100 netmask 255.255.255.0
   ```

- **Bring an interface up or down**:
   ```bash
   sudo ifconfig eth0 up
   sudo ifconfig eth0 down
   ```

Note: `ifconfig` is deprecated on many Linux distributions and has been replaced with `ip`.

---

#### **b. `ip` (IP Route and Interface)**

The `ip` command is a more modern and powerful tool for network configuration. It is used for managing network interfaces, IP addresses, routing, and tunnels.

- **Show all network interfaces**:
   ```bash
   ip a
   ```

- **Assign an IP address to an interface**:
   ```bash
   sudo ip addr add 192.168.1.100/24 dev eth0
   ```

- **Bring an interface up or down**:
   ```bash
   sudo ip link set eth0 up
   sudo ip link set eth0 down
   ```

- **View the routing table**:
   ```bash
   ip route show
   ```

- **Delete an IP address**:
   ```bash
   sudo ip addr del 192.168.1.100/24 dev eth0
   ```

---

#### **c. `nmcli` (NetworkManager Command Line Interface)**

`nmcli` is a command-line tool for managing network connections, typically used on systems running **NetworkManager** (a service that manages network connections).

- **Show all network connections**:
   ```bash
   nmcli connection show
   ```

- **Connect to a Wi-Fi network**:
   ```bash
   nmcli device wifi connect SSID password "your_password"
   ```

- **View device status**:
   ```bash
   nmcli device status
   ```

- **Set static IP address**:
   ```bash
   nmcli con mod "connection_name" ipv4.addresses 192.168.1.100/24 ipv4.gateway 192.168.1.1 ipv4.dns 8.8.8.8
   nmcli con up "connection_name"
   ```

---

#### **d. `netplan` (For Ubuntu 18.04 and newer)**

`netplan` is the default tool for configuring networking on Ubuntu-based systems starting from version 18.04. It uses YAML configuration files that are later applied to the system using the `netplan` command.

- **View the current network configuration**:
   ```bash
   cat /etc/netplan/*.yaml
   ```

- **Configure network settings (edit YAML file)**:
   You can manually edit the `/etc/netplan/01-netcfg.yaml` or similar file and then apply the configuration with the following command:
   ```bash
   sudo netplan apply
   ```

---

### **2. System Monitoring Tools**

System monitoring tools allow you to check various system parameters like CPU, memory, disk usage, and network activity. Here are some common tools for this purpose:

#### **a. `top` (Task Manager)**

The `top` command is a real-time task manager that shows the processes running on the system, along with CPU and memory usage.

- **Basic usage**:
   ```bash
   top
   ```

- **Sort by CPU usage**:
   - Press `P` while in `top`.
   
- **Sort by memory usage**:
   - Press `M` while in `top`.

- **Display summary information**:
   - Press `1` to view CPU usage per core.

#### **b. `htop` (Interactive Process Viewer)**

`htop` is a more advanced version of `top`. It provides a better user interface with color, and allows interactive manipulation.

- **Install `htop` (if not installed)**:
   ```bash
   sudo apt install htop   # Ubuntu/Debian
   sudo yum install htop   # CentOS/RedHat
   ```

- **Launch `htop`**:
   ```bash
   htop
   ```

`htop` provides a tree-like process display and can be used to sort processes and send signals to them.

---

#### **c. `vmstat` (Virtual Memory Statistics)**

The `vmstat` command is used to report virtual memory statistics, such as memory usage, processes, paging, block IO, and CPU activity.

- **Display memory and system statistics**:
   ```bash
   vmstat
   ```

- **Monitor system activity with intervals**:
   ```bash
   vmstat 2
   ```

#### **d. `free` (Memory Usage)**

The `free` command displays information about the system's memory usage, including total, used, free, and available memory.

- **View memory usage**:
   ```bash
   free -h
   ```

- **Display detailed memory info**:
   ```bash
   free -m
   ```

---

#### **e. `df` (Disk Usage)**

The `df` command shows the disk space usage of the file systems. It reports how much space is used and how much is available.

- **Display disk space usage**:
   ```bash
   df -h
   ```

- **Show disk space for a specific directory**:
   ```bash
   df -h /home
   ```

---

#### **f. `du` (Disk Usage for Directories)**

The `du` command shows the disk usage of directories and their subdirectories.

- **Show disk usage for all subdirectories**:
   ```bash
   du -h /path/to/directory
   ```

- **Show total disk usage for the current directory**:
   ```bash
   du -sh .
   ```

---

#### **g. `iostat` (Input/Output Statistics)**

The `iostat` command is used to monitor the system’s input/output device performance, including CPU statistics and I/O statistics for devices.

- **Display CPU and I/O stats**:
   ```bash
   iostat
   ```

- **Monitor device performance over intervals**:
   ```bash
   iostat -x 2
   ```

---

#### **h. `sar` (System Activity Report)**

The `sar` command is used to collect, report, and save system activity information. It is part of the **sysstat** package, which provides various system performance monitoring tools.

- **Display CPU usage**:
   ```bash
   sar -u 5 5
   ```

- **Display memory usage**:
   ```bash
   sar -r 5 5
   ```

- **Install `sysstat` (if not installed)**:
   ```bash
   sudo apt install sysstat   # Ubuntu/Debian
   sudo yum install sysstat   # CentOS/RedHat
   ```

---

#### **i. `netstat` (Network Statistics)**

The `netstat` command is used to display network connections, routing tables, and interface statistics.

- **Show network connections**:
   ```bash
   netstat -tuln
   ```

- **Display active network connections**:
   ```bash
   netstat -an
   ```

- **View network statistics**:
   ```bash
   netstat -s
   ```

---

#### **j. `ss` (Socket Stat)**

The `ss` command is used to display detailed information about network connections, similar to `netstat`, but with more options and faster performance.

- **Show TCP connections**:
   ```bash
   ss -t
   ```

- **Show all sockets (TCP, UDP, etc.)**:
   ```bash
   ss -a
   ```

---

### **3. System Logs**

System logs provide important information about the health and status of your system. Common logs can be found in the `/var/log/` directory.

- **View system logs**:
   ```bash
   less /var/log/syslog   # On Ubuntu/Debian
   less /var/log/messages # On CentOS/RedHat
   ```

- **View specific log files** (for example, authentication logs):
   ```bash
   less /var/log/auth.log
   ```

---

### **Conclusion**

By using these tools, you can effectively configure your network and monitor system performance in Linux. Tools like `ip`, `nmcli`, and `netplan` help you manage networking, while tools like `top`, `htop`, `vmstat`, `df`, and `iostat` provide crucial insights into your system's resource usage. Combining these tools helps you troubleshoot, optimize, and maintain a healthy system.
