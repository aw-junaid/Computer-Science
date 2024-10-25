### FTP Connection and Directory Listing Script

This Python script connects to an FTP server anonymously using the `ftplib` module and lists the contents of a specified directory.

### 1. Importing the Required Module:

```python
import ftplib
```

The script imports the `ftplib` module for performing FTP operations.

### 2. FTP Connection and Directory Listing Function:

```python
def check_anonymous_connection(host, path):
    with ftplib.FTP(host, user="anonymous") as connection:
        print("Welcome to ftp server", connection.getwelcome())
        for name, details in connection.mlsd(path):
            print(name, details['type'], details.get('size'))
```

The `check_anonymous_connection` function connects to the FTP server specified by `host` using anonymous credentials. It then lists the contents of the specified `path` using the `mlsd` method, which returns a directory listing in machine-readable format.

### 3. Main Function:

```python
if __name__ == '__main__':
    FTP_SERVER_URL = 'ftp.be.debian.org'
    DOWNLOAD_DIR_PATH = '/pub/linux/kernel/v5.x/'
    check_anonymous_connection(FTP_SERVER_URL, DOWNLOAD_DIR_PATH)
```

The script calls the `check_anonymous_connection` function with the FTP server URL ('ftp.be.debian.org') and the target directory path ('/pub/linux/kernel/v5.x/').

### Note:

- Ensure that the specified FTP server allows anonymous logins.
- Always comply with applicable laws and ethical guidelines when interacting with external systems.
