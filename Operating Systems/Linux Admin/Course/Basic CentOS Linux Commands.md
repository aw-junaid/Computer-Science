Basic CentOS Linux commands that every Linux administrator should know for system management, networking, package management, file operations, and other administrative tasks.

### 1. **System Information Commands**
- **`hostname`**: Displays or sets the system's hostname.
  - Example: `hostname` (Displays the current hostname)
  - Example: `hostnamectl set-hostname newhostname` (Sets a new hostname)

- **`uptime`**: Displays the system uptime, load average, and current time.
  - Example: `uptime`

- **`top`**: Displays a real-time list of system processes and resource usage.
  - Example: `top`

- **`free`**: Displays memory usage statistics.
  - Example: `free -h` (shows memory in human-readable format)

- **`df`**: Shows disk space usage of mounted filesystems.
  - Example: `df -h` (shows disk space in human-readable format)

- **`du`**: Displays the disk usage of files and directories.
  - Example: `du -sh /path/to/directory` (shows total size of a directory)

- **`lscpu`**: Displays detailed CPU architecture information.
  - Example: `lscpu`

### 2. **Process Management**
- **`ps`**: Displays a list of currently running processes.
  - Example: `ps aux` (shows all processes with detailed information)

- **`kill`**: Sends a signal to a process (usually to terminate it).
  - Example: `kill <PID>` (terminates a process with a specific process ID)
  
- **`pkill`**: Sends a signal to processes by name.
  - Example: `pkill <process_name>` (terminates processes by name)

- **`htop`**: An interactive process viewer (an enhanced version of `top`).
  - Example: `htop` (requires installation)

### 3. **Package Management (YUM/DNF)**
- **`yum`** (CentOS 7) and **`dnf`** (CentOS 8 and later) are the package managers for CentOS.
  - **`dnf install`**: Install packages.
    - Example: `dnf install httpd` (Installs the Apache web server)
  - **`dnf remove`**: Removes installed packages.
    - Example: `dnf remove httpd` (Removes the Apache web server)
  - **`dnf update`**: Updates installed packages.
    - Example: `dnf update` (Updates all packages)
  - **`dnf upgrade`**: Upgrades the system to the latest version.
    - Example: `dnf upgrade` (Upgrades installed packages to the latest versions)
  - **`dnf list installed`**: Lists all installed packages.
    - Example: `dnf list installed`
  - **`dnf search`**: Searches for available packages.
    - Example: `dnf search vim`

### 4. **File and Directory Management**
- **`ls`**: Lists files and directories.
  - Example: `ls -l` (lists files with detailed information)
  - Example: `ls -a` (lists all files including hidden files)

- **`cd`**: Changes the current directory.
  - Example: `cd /path/to/directory`

- **`pwd`**: Prints the current working directory.
  - Example: `pwd`

- **`mkdir`**: Creates a new directory.
  - Example: `mkdir new_directory`

- **`rmdir`**: Removes an empty directory.
  - Example: `rmdir directory_name`

- **`rm`**: Removes files or directories.
  - Example: `rm filename` (removes a file)
  - Example: `rm -r directory_name` (removes a directory and its contents)

- **`cp`**: Copies files or directories.
  - Example: `cp file1 file2` (copies file1 to file2)

- **`mv`**: Moves or renames files and directories.
  - Example: `mv file1 new_location` (moves file1 to a new location)
  - Example: `mv old_name new_name` (renames a file)

- **`chmod`**: Changes file permissions.
  - Example: `chmod 755 file` (sets the file permissions to rwxr-xr-x)
  
- **`chown`**: Changes the owner and group of a file or directory.
  - Example: `chown user:group filename` (changes ownership to `user` and group to `group`)

### 5. **User Management**
- **`useradd`**: Adds a new user.
  - Example: `useradd username`

- **`passwd`**: Changes a user's password.
  - Example: `passwd username`

- **`usermod`**: Modifies a user's account details.
  - Example: `usermod -aG groupname username` (adds the user to a group)

- **`userdel`**: Deletes a user account.
  - Example: `userdel username` (removes the user)

- **`groupadd`**: Adds a new group.
  - Example: `groupadd groupname`

- **`groupdel`**: Deletes a group.
  - Example: `groupdel groupname`

- **`id`**: Displays user and group information for a user.
  - Example: `id username`

### 6. **Networking**
- **`ip`**: A versatile networking tool used to display and configure networking interfaces.
  - Example: `ip addr show` (shows the current network interfaces and IP addresses)
  - Example: `ip link set eth0 up` (activates the eth0 interface)

- **`ping`**: Tests network connectivity.
  - Example: `ping google.com`

- **`netstat`**: Displays network connections, routing tables, and network statistics.
  - Example: `netstat -tuln` (shows active listening ports)

- **`ss`**: Displays socket statistics (a modern replacement for `netstat`).
  - Example: `ss -tuln` (shows active listening ports)

- **`firewall-cmd`**: Manages the firewalld service (CentOS 7+).
  - Example: `firewall-cmd --state` (shows the firewall status)
  - Example: `firewall-cmd --add-port=80/tcp` (opens port 80)

- **`nmcli`**: Command-line tool for managing network connections using NetworkManager.
  - Example: `nmcli device show` (shows information about network devices)

### 7. **System and Service Management**
- **`systemctl`**: Manages system services (with systemd).
  - Example: `systemctl start <service>` (starts a service)
  - Example: `systemctl stop <service>` (stops a service)
  - Example: `systemctl restart <service>` (restarts a service)
  - Example: `systemctl enable <service>` (enables a service to start at boot)
  - Example: `systemctl status <service>` (shows the status of a service)

- **`service`**: A legacy command to start and stop services (still available in CentOS 7).
  - Example: `service httpd start` (starts the Apache service)

### 8. **Log Management**
- **`journalctl`**: Displays logs from the systemd journal.
  - Example: `journalctl` (shows all logs)
  - Example: `journalctl -u <service_name>` (shows logs for a specific service)

- **`tail`**: Displays the last part of a file.
  - Example: `tail -f /var/log/messages` (continuously displays new logs as they are added)

### 9. **Disk and Filesystem Management**
- **`fdisk`**: Used for partitioning hard drives.
  - Example: `fdisk -l` (lists disk partitions)

- **`mount`**: Mounts a filesystem.
  - Example: `mount /dev/sdb1 /mnt`

- **`umount`**: Unmounts a filesystem.
  - Example: `umount /mnt`

- **`lsblk`**: Lists information about block devices.
  - Example: `lsblk`

- **`blkid`**: Displays information about block devices (like UUIDs).
  - Example: `blkid`

### 10. **File Search and Find**
- **`find`**: Searches for files and directories.
  - Example: `find /path/to/dir -name "filename"`
  - Example: `find / -type f -name "*.log"` (finds all `.log` files)

- **`locate`**: Finds files by name using a prebuilt database.
  - Example: `locate filename`

These are just some of the basic Linux commands used by CentOS administrators. There are many more advanced commands and options that you can use as you become more familiar with Linux systems.
