### FTP File Download Script Using `ftplib`

This Python script uses the `ftplib` module to download a file from an FTP server.

### 1. Importing Required Modules:

```python
from ftplib import FTP
```

The script imports the `FTP` class from the `ftplib` module for FTP client operations.

### 2. FTP Configuration:

```python
ftp_client = FTP('ftp.be.debian.org')
ftp_client.login()
ftp_client.cwd('/pub/linux/kernel/v5.x/')
```

The script initializes an FTP client, connects to the specified FTP server (`ftp.be.debian.org`), and logs in anonymously. It then changes to the specified directory (`/pub/linux/kernel/v5.x/`) on the server.

### 3. Writing Data to a Local File:

```python
file_descriptor = open('ChangeLog-5.0', 'wt')
```

The script opens a local file (`ChangeLog-5.0`) for writing.

### 4. Retrieving Lines from the FTP Server:

```python
def write_data(data):
    file_descriptor.write(data + "\n")

ftp_client.retrlines('RETR ChangeLog-5.0', write_data)
```

The script defines a function `write_data` to write each line received from the FTP server to the local file. It then uses `retrlines` to retrieve lines from the specified file (`ChangeLog-5.0`) on the FTP server and writes them to the local file.

### 5. Closing the Local File and Quitting the FTP Session:

```python
file_descriptor.close()
ftp_client.quit()
```

After retrieving lines, the local file is closed, and the FTP client session is terminated.

### Note:

- This script assumes anonymous FTP access. If you need to provide credentials, modify the `login` method accordingly.
- Ensure you have the necessary permissions to access the specified FTP server and download files.
- Modify the FTP server URL, directory path, and file name based on your requirements.

The script follows the same logic as the previous script but uses the `retrlines` method for line-oriented retrieval.
