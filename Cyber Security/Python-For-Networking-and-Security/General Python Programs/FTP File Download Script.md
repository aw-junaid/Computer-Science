### FTP File Download Script

This Python script demonstrates downloading a file from an FTP server using the `ftplib` module.

### 1. Importing Required Modules:

```python
import ftplib
```

The script imports the `ftplib` module for interacting with FTP servers.

### 2. FTP Server Configuration:

```python
FTP_SERVER_URL = 'ftp.be.debian.org'
DOWNLOAD_DIR_PATH = '/pub/linux/kernel/v5.x/'
DOWNLOAD_FILE_NAME = 'ChangeLog-5.0'
```

The script sets the FTP server URL, the directory path on the server, and the name of the file to be downloaded.

### 3. FTP File Download Function:

```python
def ftp_file_download(server, username):
    ftp_client = ftplib.FTP(server, username)
    ftp_client.cwd(DOWNLOAD_DIR_PATH)
    try:
        with open(DOWNLOAD_FILE_NAME, 'wb') as file_handler:
            ftp_cmd = 'RETR %s' % DOWNLOAD_FILE_NAME
            ftp_client.retrbinary(ftp_cmd, file_handler.write)
            ftp_client.quit()
    except Exception as exception:
        print('File could not be downloaded:', exception)
```

The script defines a function `ftp_file_download` that takes the FTP server URL and a username as parameters. It connects to the FTP server, changes to the specified directory, and attempts to download the specified file using the 'RETR' command.

### 4. Main Execution:

```python
if __name__ == '__main__':
    ftp_file_download(server=FTP_SERVER_URL, username='anonymous')
```

The script executes the `ftp_file_download` function with the configured FTP server URL and the username set to 'anonymous'. This is a common practice for anonymous FTP access.

### Note:

- Ensure that you have the necessary permissions to access the specified FTP server and download files.
- Modify the FTP server URL, directory path, and file name according to your requirements.
- This script uses anonymous FTP access, but in a real-world scenario, you may need to provide valid credentials.
- Handle exceptions appropriately to manage errors during FTP operations.
