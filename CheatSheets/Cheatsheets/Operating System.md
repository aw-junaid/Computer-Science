An extended cheat sheet for common operating system commands, focusing on both Windows and Unix-like systems (Linux, macOS). This guide covers essential commands for file management, system monitoring, network configuration, and more.

---

# **Operating System Extended Cheat Sheet**

## **1. File Management Commands**

### 1.1 Unix/Linux Commands

- **List Files in a Directory**

  **Command:**
  ```bash
  ls -l
  ```

  **Explanation**: Lists files in the current directory in long format, showing file permissions, number of links, owner, group, size, and modification date.

- **Change Directory**

  **Command:**
  ```bash
  cd /path/to/directory
  ```

  **Explanation**: Changes the current directory to the specified path.

- **Create a Directory**

  **Command:**
  ```bash
  mkdir new_directory
  ```

  **Explanation**: Creates a new directory named `new_directory`.

- **Remove a Directory**

  **Command:**
  ```bash
  rmdir directory_name
  ```

  **Explanation**: Removes an empty directory.

- **Copy a File**

  **Command:**
  ```bash
  cp source_file destination_file
  ```

  **Explanation**: Copies a file from `source_file` to `destination_file`.

- **Move/Rename a File**

  **Command:**
  ```bash
  mv old_file new_file
  ```

  **Explanation**: Moves or renames a file from `old_file` to `new_file`.

- **Remove a File**

  **Command:**
  ```bash
  rm file_name
  ```

  **Explanation**: Deletes the specified file.

### 1.2 Windows Commands

- **List Files in a Directory**

  **Command:**
  ```cmd
  dir
  ```

  **Explanation**: Lists the files and directories in the current directory.

- **Change Directory**

  **Command:**
  ```cmd
  cd \path\to\directory
  ```

  **Explanation**: Changes the current directory to the specified path.

- **Create a Directory**

  **Command:**
  ```cmd
  mkdir new_directory
  ```

  **Explanation**: Creates a new directory named `new_directory`.

- **Remove a Directory**

  **Command:**
  ```cmd
  rmdir directory_name
  ```

  **Explanation**: Removes an empty directory.

- **Copy a File**

  **Command:**
  ```cmd
  copy source_file destination_file
  ```

  **Explanation**: Copies a file from `source_file` to `destination_file`.

- **Move/Rename a File**

  **Command:**
  ```cmd
  move old_file new_file
  ```

  **Explanation**: Moves or renames a file from `old_file` to `new_file`.

- **Remove a File**

  **Command:**
  ```cmd
  del file_name
  ```

  **Explanation**: Deletes the specified file.

---

## **2. System Monitoring Commands**

### 2.1 Unix/Linux Commands

- **Show Current Processes**

  **Command:**
  ```bash
  ps aux
  ```

  **Explanation**: Displays detailed information about all running processes.

- **Monitor System Performance**

  **Command:**
  ```bash
  top
  ```

  **Explanation**: Provides a dynamic view of system processes, CPU usage, memory usage, and more.

- **Check Disk Usage**

  **Command:**
  ```bash
  df -h
  ```

  **Explanation**: Shows disk space usage for all mounted filesystems in a human-readable format.

- **Check Memory Usage**

  **Command:**
  ```bash
  free -h
  ```

  **Explanation**: Displays the total, used, and available memory in a human-readable format.

### 2.2 Windows Commands

- **Show Current Processes**

  **Command:**
  ```cmd
  tasklist
  ```

  **Explanation**: Lists all currently running processes.

- **Monitor System Performance**

  **Command:**
  ```cmd
  taskmgr
  ```

  **Explanation**: Opens the Task Manager, where you can view and manage running processes.

- **Check Disk Usage**

  **Command:**
  ```cmd
  wmic logicaldisk get size,freespace,caption
  ```

  **Explanation**: Displays the total and free space on all logical drives.

- **Check Memory Usage**

  **Command:**
  ```cmd
  systeminfo | findstr /C:"Total Physical Memory" /C:"Available Physical Memory"
  ```

  **Explanation**: Displays total and available physical memory.

---

## **3. Network Configuration Commands**

### 3.1 Unix/Linux Commands

- **Show IP Address**

  **Command:**
  ```bash
  ip addr
  ```

  **Explanation**: Displays the IP addresses assigned to all network interfaces.

- **Ping a Host**

  **Command:**
  ```bash
  ping google.com
  ```

  **Explanation**: Sends ICMP echo requests to the specified host to check connectivity.

- **Show Routing Table**

  **Command:**
  ```bash
  route -n
  ```

  **Explanation**: Displays the current routing table.

- **Check Network Connections**

  **Command:**
  ```bash
  netstat -tuln
  ```

  **Explanation**: Lists all listening ports and their associated addresses.

### 3.2 Windows Commands

- **Show IP Address**

  **Command:**
  ```cmd
  ipconfig
  ```

  **Explanation**: Displays the IP configuration for all network interfaces.

- **Ping a Host**

  **Command:**
  ```cmd
  ping google.com
  ```

  **Explanation**: Sends ICMP echo requests to the specified host to check connectivity.

- **Show Routing Table**

  **Command:**
  ```cmd
  route print
  ```

  **Explanation**: Displays the current routing table.

- **Check Network Connections**

  **Command:**
  ```cmd
  netstat -an
  ```

  **Explanation**: Lists all network connections and listening ports.

---

## **4. User and Group Management**

### 4.1 Unix/Linux Commands

- **Add a New User**

  **Command:**
  ```bash
  sudo adduser username
  ```

  **Explanation**: Creates a new user account with the specified username.

- **Delete a User**

  **Command:**
  ```bash
  sudo deluser username
  ```

  **Explanation**: Deletes the specified user account.

- **Add a User to a Group**

  **Command:**
  ```bash
  sudo usermod -aG groupname username
  ```

  **Explanation**: Adds the specified user to the specified group.

- **Show Current User**

  **Command:**
  ```bash
  whoami
  ```

  **Explanation**: Displays the username of the current user.

### 4.2 Windows Commands

- **Add a New User**

  **Command:**
  ```cmd
  net user username password /add
  ```

  **Explanation**: Creates a new user account with the specified username and password.

- **Delete a User**

  **Command:**
  ```cmd
  net user username /delete
  ```

  **Explanation**: Deletes the specified user account.

- **Add a User to a Group**

  **Command:**
  ```cmd
  net localgroup groupname username /add
  ```

  **Explanation**: Adds the specified user to the specified local group.

- **Show Current User**

  **Command:**
  ```cmd
  echo %USERNAME%
  ```

  **Explanation**: Displays the username of the current user.

---

## **5. System Shutdown and Restart**

### 5.1 Unix/Linux Commands

- **Shutdown the System**

  **Command:**
  ```bash
  sudo shutdown now
  ```

  **Explanation**: Immediately shuts down the system.

- **Restart the System**

  **Command:**
  ```bash
  sudo reboot
  ```

  **Explanation**: Restarts the system.

### 5.2 Windows Commands

- **Shutdown the System**

  **Command:**
  ```cmd
  shutdown /s /t 0
  ```

  **Explanation**: Immediately shuts down the system.

- **Restart the System**

  **Command:**
  ```cmd
  shutdown /r /t 0
  ```

  **Explanation**: Immediately restarts the system.

---

## **6. Package Management**

### 6.1 Unix/Linux Commands

#### For Debian/Ubuntu:

- **Update Package List**

  **Command:**
  ```bash
  sudo apt update
  ```

  **Explanation**: Updates the list of available packages and their versions.

- **Install a Package**

  **Command:**
  ```bash
  sudo apt install package_name
  ```

  **Explanation**: Installs the specified package.

- **Remove a Package**

  **Command:**
  ```bash
  sudo apt remove package_name
  ```

  **Explanation**: Removes the specified package.

#### For CentOS/RHEL:

- **Update Package List**

  **Command:**
  ```bash
  sudo yum check-update
  ```

  **Explanation**: Checks for available package updates.

- **Install a Package**

  **Command:**
  ```bash
  sudo yum install package_name
  ```

  **Explanation**: Inst

alls the specified package.

- **Remove a Package**

  **Command:**
  ```bash
  sudo yum remove package_name
  ```

  **Explanation**: Removes the specified package.

### 6.2 Windows Commands

- **Install a Package (via Chocolatey)**

  **Command:**
  ```cmd
  choco install package_name
  ```

  **Explanation**: Installs the specified package using Chocolatey, a package manager for Windows.

- **Update a Package (via Chocolatey)**

  **Command:**
  ```cmd
  choco upgrade package_name
  ```

  **Explanation**: Upgrades the specified package using Chocolatey.

- **Remove a Package (via Chocolatey)**

  **Command:**
  ```cmd
  choco uninstall package_name
  ```

  **Explanation**: Uninstalls the specified package using Chocolatey.

---

## **7. Conclusion**

This operating system cheat sheet covers essential commands for file management, system monitoring, network configuration, user management, and more for both Unix/Linux and Windows environments. Familiarity with these commands will enhance your productivity and streamline your workflows in different operating systems.
