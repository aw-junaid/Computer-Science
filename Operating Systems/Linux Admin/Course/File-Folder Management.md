File and folder management is a crucial part of Linux administration. Here are some essential commands for managing files and directories in Linux (CentOS or any other Linux distribution):

### 1. **Basic File and Folder Commands**

- **`ls`**: Lists files and directories in the current directory.
  - `ls` (lists files and directories in the current directory)
  - `ls -l` (lists files in long format with permissions, owner, size, and timestamps)
  - `ls -a` (lists all files, including hidden ones)
  - `ls -lh` (lists files in human-readable sizes, like KB, MB, GB)

- **`cd`**: Changes the current directory.
  - `cd /path/to/directory` (changes to the specified directory)
  - `cd ~` (changes to the home directory)
  - `cd ..` (moves up one level in the directory tree)

- **`pwd`**: Prints the working directory.
  - `pwd` (shows the current directory path)

### 2. **Creating Files and Directories**

- **`mkdir`**: Creates a new directory.
  - `mkdir directory_name` (creates a new directory)
  - `mkdir -p /path/to/directory` (creates parent directories if they don’t exist)

- **`touch`**: Creates an empty file or updates the timestamp of an existing file.
  - `touch filename` (creates an empty file or updates timestamp of the file)

- **`echo`**: Creates or appends content to a file.
  - `echo "Hello, World!" > file.txt` (creates file.txt with "Hello, World!" content)
  - `echo "New line" >> file.txt` (appends "New line" to file.txt)

### 3. **File and Folder Manipulation**

- **`cp`**: Copies files or directories.
  - `cp source_file destination_file` (copies a file)
  - `cp -r source_directory destination_directory` (copies a directory recursively)

- **`mv`**: Moves or renames files and directories.
  - `mv source_file destination_file` (moves or renames a file)
  - `mv oldname newname` (renames a file or folder)
  - `mv file1 /path/to/destination/` (moves file1 to the specified directory)

- **`rm`**: Removes files or directories.
  - `rm filename` (removes a file)
  - `rm -r directory_name` (removes a directory and its contents recursively)
  - `rm -f filename` (forces removal of a file, even if write-protected)

- **`rmdir`**: Removes empty directories.
  - `rmdir directory_name` (removes an empty directory)

### 4. **File Permissions and Ownership**

- **`chmod`**: Changes file or directory permissions.
  - `chmod 755 filename` (sets permissions to rwxr-xr-x)
  - `chmod u+x filename` (gives execute permission to the file owner)
  - `chmod -R 755 directory_name` (applies permissions recursively to a directory)

- **`chown`**: Changes the owner and/or group of a file or directory.
  - `chown user:group filename` (changes the owner to `user` and group to `group`)
  - `chown -R user:group directory_name` (changes ownership recursively for a directory)

- **`chgrp`**: Changes the group ownership of a file or directory.
  - `chgrp group filename` (changes the group of the file to `group`)

### 5. **File Viewing and Editing**

- **`cat`**: Displays the content of a file.
  - `cat filename` (displays the contents of a file)

- **`more`**: Views a file content one page at a time.
  - `more filename`

- **`less`**: Similar to `more`, but allows both forward and backward navigation.
  - `less filename`

- **`head`**: Displays the first few lines of a file.
  - `head filename` (displays the first 10 lines)
  - `head -n 20 filename` (displays the first 20 lines)

- **`tail`**: Displays the last few lines of a file.
  - `tail filename` (displays the last 10 lines)
  - `tail -n 20 filename` (displays the last 20 lines)
  - `tail -f filename` (continually outputs new lines added to the file)

- **`nano`** or **`vim`**: Text editors to edit files.
  - `nano filename` (opens the file in the `nano` editor)
  - `vim filename` (opens the file in the `vim` editor)

### 6. **Searching for Files**

- **`find`**: Finds files and directories based on search criteria.
  - `find /path/to/search -name "filename"` (searches for a file by name)
  - `find /path/to/search -type f` (finds all files)
  - `find /path/to/search -type d` (finds all directories)
  - `find / -name "*.log"` (finds all `.log` files in the system)

- **`locate`**: Finds files by name using a prebuilt database (faster than `find`).
  - `locate filename` (locates files by name)
  - Note: You may need to run `updatedb` (as root) to update the locate database.

- **`which`**: Locates a command or executable.
  - `which command_name` (shows the path of an executable)

### 7. **Disk and Filesystem Management**

- **`df`**: Shows the amount of disk space used and available on all mounted filesystems.
  - `df -h` (displays the disk space in human-readable format)

- **`du`**: Displays disk usage of files and directories.
  - `du -sh /path/to/directory` (shows the total size of the directory in human-readable format)
  - `du -ah /path/to/directory` (shows size of all files and directories)

- **`mount`**: Mounts a filesystem or storage device.
  - `mount /dev/sdb1 /mnt` (mounts the device `/dev/sdb1` to `/mnt`)
  
- **`umount`**: Unmounts a filesystem or storage device.
  - `umount /mnt` (unmounts the filesystem mounted at `/mnt`)

### 8. **Archiving and Compressing Files**

- **`tar`**: Used to create, extract, and manage archive files.
  - `tar -cvf archive.tar directory_name` (creates a `.tar` archive of a directory)
  - `tar -xvf archive.tar` (extracts a `.tar` archive)
  - `tar -cvzf archive.tar.gz directory_name` (creates a compressed `.tar.gz` archive)
  - `tar -xvzf archive.tar.gz` (extracts a compressed `.tar.gz` archive)

- **`gzip`**: Compresses files into `.gz` format.
  - `gzip filename` (compresses the file into `filename.gz`)
  - `gunzip filename.gz` (decompresses the `.gz` file)

- **`zip` and `unzip`**: Used for creating and extracting `.zip` archives.
  - `zip archive.zip file1 file2` (creates a `.zip` archive)
  - `unzip archive.zip` (extracts a `.zip` archive)

### 9. **Symbolic Links**

- **`ln`**: Creates links to files or directories.
  - `ln -s /path/to/original /path/to/link` (creates a symbolic link)
  - `ln /path/to/original /path/to/link` (creates a hard link)

### 10. **Viewing File Metadata**

- **`stat`**: Displays detailed information about a file or directory.
  - `stat filename` (shows detailed metadata like permissions, timestamps, size, etc.)

### 11. **File Integrity and Checksums**

- **`sha256sum`**: Computes the SHA-256 checksum of a file.
  - `sha256sum filename` (shows the SHA-256 checksum of the file)

- **`md5sum`**: Computes the MD5 checksum of a file.
  - `md5sum filename` (shows the MD5 checksum of the file)

---

These are essential commands for managing files and directories in CentOS or any Linux system. Mastering these commands will help you efficiently navigate and administer the filesystem.
