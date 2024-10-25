### FTP Binary File Download Script Using `ftplib`

This Python script uses the `ftplib` module to download a binary file from an FTP server.

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

The script initializes an FTP client, connects to the specified FTP server (`ftp.be.debian.org`), logs in anonymously, and changes to the specified directory (`/pub/linux/kernel/v5.x/`) on the server.

### 3. Downloading the Binary File:

```python
ftp_client.voidcmd("TYPE I")
datasock, est_size = ftp_client.ntransfercmd("RETR ChangeLog-5.0")
trans_bytes = 0

with open('ChangeLog-5.0', 'wb') as file_descriptor:
    while True:
        buffer = datasock.recv(2048)
        if not len(buffer):
            break
        file_descriptor.write(buffer)
        trans_bytes += len(buffer)
        print("Bytes received", trans_bytes, "Total", (est_size, 100.0 * float(trans_bytes) / float(est_size)), str('%'))

datasock.close()
ftp_client.quit()
```

The script sets the transfer type to binary using `voidcmd("TYPE I")`. It then establishes a data connection for the transfer with `ntransfercmd("RETR ChangeLog-5.0")` and starts receiving data in binary mode. The received data is written to the local file (`ChangeLog-5.0`). The progress of the download is printed, including the number of bytes received and the completion percentage.

### Note:

- This script assumes anonymous FTP access. If you need to provide credentials, modify the `login` method accordingly.
- Ensure you have the necessary permissions to access the specified FTP server and download files.
- Modify the FTP server URL, directory path, and file name based on your requirements.
