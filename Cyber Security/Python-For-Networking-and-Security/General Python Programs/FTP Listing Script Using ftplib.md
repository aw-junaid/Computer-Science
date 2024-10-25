### FTP Listing Script Using `ftplib`

This Python script utilizes the `ftplib` module to connect to an FTP server, log in, and list files and directories.

### 1. Importing Required Modules:

```python
from ftplib import FTP
```

The script imports the `FTP` class from the `ftplib` module for FTP client operations.

### 2. Connecting to the FTP Server and Listing Directories:

```python
ftp_client = FTP('ftp.be.debian.org')
print("Server: ", ftp_client.getwelcome())
print(ftp_client.login())
print("Files and directories in the root directory:")
ftp_client.dir()
```

The script connects to the specified FTP server (`ftp.be.debian.org`), prints the server's welcome message, logs in anonymously, and lists the files and directories in the root directory.

### 3. Changing Directory and Listing Files:

```python
ftp_client.cwd('/pub/linux/kernel')
files = ftp_client.nlst()
files.sort()
print("%d files in /pub/linux/kernel directory:" % len(files))
for file in files:
    print(file)
```

The script changes the current working directory to `/pub/linux/kernel`, retrieves a list of files in that directory, sorts the list, and prints the number of files along with their names.

### 4. Closing the Connection:

```python
ftp_client.quit()
```

The script gracefully closes the FTP connection.

### Note:

- This script assumes anonymous FTP access. If you need to provide credentials, modify the `login` method accordingly.
- Ensure you have the necessary permissions to access the specified FTP server and list files and directories.
- Modify the FTP server URL and directory path based on your requirements.
