Comprehensive cheatsheet for various Linux commands, categorized by functionality.

---

## System Information and Management

| Command                 | Description                                 |
|-------------------------|---------------------------------------------|
| `uname -a`               | Display system information.                 |
| `hostname`               | Display or set the system's host name.      |
| `whoami`                 | Display the current user.                   |
| `top`                    | Display system usage and processes.         |
| `ps`                     | Display information about processes.        |
| `kill [PID]`             | Terminate a process by its process ID.      |
| `reboot`                 | Reboot the system.                          |
| `shutdown`               | Shut down the system.                       |
| `df -h`                  | Display disk space usage.                   |
| `du -h`                  | Display disk usage of files and directories.|
| `free -m`                | Display amount of free and used memory.     |
| `uptime`                 | Display how long the system has been running.|

## File System Navigation and Manipulation

| Command                 | Description                                 |
|-------------------------|---------------------------------------------|
| `ls`                     | List files and directories.                 |
| `cd [directory]`        | Change current directory.                   |
| `pwd`                    | Print working directory.                    |
| `mkdir [directory]`      | Create a new directory.                     |
| `rmdir [directory]`      | Remove an empty directory.                  |
| `touch [file]`           | Create an empty file or update timestamps.  |
| `cp [source] [destination]` | Copy files or directories.               |
| `mv [source] [destination]` | Move or rename files/directories.       |
| `rm [file]`              | Remove files or directories.               |
| `cat [file]`             | Display or concatenate files.              |
| `less [file]`            | View file content with paging.             |
| `head [file]`            | Display the first part of a file.           |
| `tail [file]`            | Display the last part of a file.            |

## File Permissions and Ownership

| Command                 | Description                                 |
|-------------------------|---------------------------------------------|
| `chmod [permissions] [file]` | Change file permissions.                 |
| `chown [owner]:[group] [file]` | Change file owner and group.           |
| `chgrp [group] [file]`   | Change file group.                         |

## Text Manipulation

| Command                 | Description                                 |
|-------------------------|---------------------------------------------|
| `grep [pattern] [file]`  | Search for patterns in files.               |
| `sed 's/old/new/g' [file]` | Search and replace text.                 |
| `awk [pattern] [file]`   | Pattern scanning and processing language.   |
| `sort [file]`            | Sort lines of text files.                   |
| `uniq [file]`            | Report or omit repeated lines.              |
| `cut -d [delimiter] -f [fields] [file]` | Extract sections from lines.        |

## File Compression and Archiving

| Command                 | Description                                 |
|-------------------------|---------------------------------------------|
| `tar -cvf [archive.tar] [files]` | Create a new tar archive.              |
| `tar -xvf [archive.tar]` | Extract files from a tar archive.        |
| `gzip [file]`            | Compress files.                            |
| `gunzip [file]`          | Decompress files.                          |
| `zip [archive.zip] [files]` | Create a new ZIP archive.              |
| `unzip [archive.zip]`    | Extract files from a ZIP archive.          |

## User and Group Management

| Command                 | Description                                 |
|-------------------------|---------------------------------------------|
| `useradd [username]`     | Add a new user.                             |
| `passwd [username]`      | Set or change user password.                |
| `userdel [username]`     | Delete a user.                              |
| `groupadd [group]`       | Add a new group.                            |
| `groupdel [group]`       | Delete a group.                             |
| `id [username]`          | Display user and group information.         |

## Network and Connectivity

| Command                 | Description                                 |
|-------------------------|---------------------------------------------|
| `ifconfig`               | Display network interface configuration.    |
| `ping [host]`            | Test network connectivity.                  |
| `nslookup [host]`        | Query DNS for domain information.           |
| `netstat -tuln`          | Display listening ports.                    |
| `iptables`               | Configure firewall rules.                   |
| `route`                  | Display or modify the IP routing table.     |

## Package Management

| Command                 | Description                                 |
|-------------------------|---------------------------------------------|
| `apt-get install [package]` | Install software packages.             |
| `apt-get remove [package]`  | Remove software packages.               |
| `apt-get update`         | Update list of available packages.          |
| `apt-get upgrade`        | Upgrade all installed packages.             |
| `apt-cache search [keyword]` | Search for packages.                    |

---

Note: This cheatsheet provides a broad overview of essential Linux commands. Depending on your specific needs and system configuration, you may encounter additional commands or options. Always refer to man pages or online documentation for more in-depth information.
