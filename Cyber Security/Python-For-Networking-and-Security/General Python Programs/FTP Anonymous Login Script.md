### FTP Anonymous Login Script

This Python script attempts anonymous login to an FTP server using the `ftplib` module.

### 1. Importing the Required Module:

```python
import ftplib
```

The script imports the `ftplib` module to perform FTP operations.

### 2. FTP Anonymous Login Function:

```python
def anonymousLogin(hostname):
    try:
        ftp = ftplib.FTP(hostname)
        response = ftp.login('anonymous', 'anonymous')
        print(response)
        if "230 Anonymous access granted" in response:
            print('\n[*] ' + str(hostname) + ' FTP Anonymous Login Succeeded.')
            print(ftp.getwelcome())
            ftp.dir()
    except Exception as e:
        print(str(e))
        print('\n[-] ' + str(hostname) + ' FTP Anonymous Login Failed.')
```

The `anonymousLogin` function attempts to log in to the FTP server with the username "anonymous" and password "anonymous." If the login is successful, it prints a success message along with the server welcome message and directory listing.

### 3. Main Function:

```python
hostname = 'ftp.be.debian.org'
anonymousLogin(hostname)
```

The script then calls the `anonymousLogin` function with the target FTP server's hostname, in this case, 'ftp.be.debian.org'.

### Note:

- This script assumes that the target FTP server allows anonymous logins.
- Ensure that you have permission to perform anonymous logins on the specified FTP server.
- Always comply with the applicable laws and ethical guidelines when performing security testing.
