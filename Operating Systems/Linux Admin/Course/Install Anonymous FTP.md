### Installing and Configuring Anonymous FTP on CentOS 7

In this guide, you'll set up **Anonymous FTP** on CentOS 7 using **vsftpd**, a lightweight and secure FTP server. Anonymous FTP allows users to access files on your server without needing a username or password.

---

### 1. **Install vsftpd**

#### 1.1. Install the **vsftpd** package

To install the **vsftpd** package (Very Secure FTP Daemon), run the following command:

```bash
sudo yum install vsftpd -y
```

#### 1.2. Start and Enable vsftpd Service

Once the installation is complete, start the vsftpd service and enable it to start automatically at boot:

```bash
sudo systemctl start vsftpd
sudo systemctl enable vsftpd
```

#### 1.3. Verify vsftpd Service Status

Check if the **vsftpd** service is running:

```bash
sudo systemctl status vsftpd
```

The output should show that **vsftpd** is active and running.

---

### 2. **Configure vsftpd for Anonymous FTP**

The main configuration file for vsftpd is located at `/etc/vsftpd/vsftpd.conf`. We will configure it to allow anonymous FTP access.

#### 2.1. Edit the Configuration File

Open the vsftpd configuration file for editing:

```bash
sudo vi /etc/vsftpd/vsftpd.conf
```

Modify or ensure the following settings are present and correctly configured:

- **Enable anonymous FTP access:**

```bash
anonymous_enable=YES
```

- **Allow anonymous users to upload files (optional):**

```bash
anon_upload_enable=YES
```

- **Set the permissions for uploading files (optional, use with caution):**

```bash
anon_mkdir_write_enable=YES
```

- **Disable anonymous login for non-anonymous FTP users (optional, for security):**

```bash
local_enable=NO
```

- **Configure the default FTP directory for anonymous users:**

```bash
anon_root=/var/ftp
```

- **Disallow writing to the anonymous directory (if you want the FTP to be read-only):**

```bash
anon_upload_enable=NO
anon_mkdir_write_enable=NO
```

These changes will enable anonymous FTP access, with the ability to configure whether uploads are allowed. By default, the FTP server will restrict writes to certain directories for security purposes.

#### 2.2. Set FTP Directory Permissions

Next, set up the FTP directory for anonymous users. By default, **vsftpd** stores anonymous user files in `/var/ftp`. You may need to create this directory and set appropriate permissions:

```bash
sudo mkdir -p /var/ftp
sudo chown -R ftp:ftp /var/ftp
```

If you want to allow file uploads, you can set the directory permissions to allow write access:

```bash
sudo chmod -R 777 /var/ftp
```

However, be cautious with this, as it allows full read/write access to the directory for all users, including anonymous FTP clients.

#### 2.3. Restart vsftpd Service

After making these changes, restart the vsftpd service to apply the new configuration:

```bash
sudo systemctl restart vsftpd
```

---

### 3. **Allow FTP Through the Firewall**

If you're running **firewalld** or another firewall service on CentOS, you need to allow FTP traffic through the firewall.

#### 3.1. Open FTP Ports in the Firewall

By default, FTP uses port **21** for control and a range of ports for data transfer. Run the following commands to open the necessary ports in the firewall:

```bash
sudo firewall-cmd --permanent --add-service=ftp
sudo firewall-cmd --reload
```

This opens port **21** for FTP. If you want to support passive FTP, you may need to configure the firewall for a range of ports used by passive FTP.

#### 3.2. Configure Passive FTP (Optional)

If you're behind a firewall or NAT, you may want to enable passive FTP. You can configure the passive mode ports by editing the `/etc/vsftpd/vsftpd.conf` file:

1. Open the configuration file:

```bash
sudo vi /etc/vsftpd/vsftpd.conf
```

2. Add or modify the following lines to specify a passive port range:

```bash
pasv_min_port=40000
pasv_max_port=50000
```

3. Open the passive ports in the firewall:

```bash
sudo firewall-cmd --permanent --add-port=40000-50000/tcp
sudo firewall-cmd --reload
```

This allows passive FTP connections on ports **40000-50000**.

---

### 4. **Test the FTP Server**

You can now test the FTP server to ensure that it is functioning correctly.

#### 4.1. **Test Anonymous FTP Login**

You can test the anonymous FTP login using the **ftp** command from the same machine or from a remote system:

```bash
ftp localhost
```

When prompted for a username and password, enter `anonymous` as the username and your email address (or any string) as the password.

You should be able to access the directory `/var/ftp` (or whichever directory you set in `anon_root`) and download files.

#### 4.2. **Test Using an FTP Client**

Alternatively, you can use an FTP client like **FileZilla** or **WinSCP** to connect to the FTP server. Use the following settings:

- **Host:** `ftp://your_server_ip_or_hostname`
- **Username:** `anonymous`
- **Password:** `your_email_address` (or any string)

---

### 5. **Securing FTP (Optional)**

Since FTP transmits data, including passwords, in plain text, it is highly recommended to secure FTP by enabling **FTPS** (FTP over SSL/TLS).

#### 5.1. **Install SSL Certificates**

Generate or use an existing SSL certificate to secure FTP connections. You can generate a self-signed certificate using OpenSSL:

```bash
sudo openssl req -x509 -newkey rsa:4096 -keyout /etc/ssl/private/vsftpd.key -out /etc/ssl/certs/vsftpd.crt -days 365
```

#### 5.2. **Enable SSL in vsftpd**

To enable FTPS, open the vsftpd configuration file:

```bash
sudo vi /etc/vsftpd/vsftpd.conf
```

Add or modify the following lines to enable SSL:

```bash
ssl_enable=YES
rsa_cert_file=/etc/ssl/certs/vsftpd.crt
rsa_private_key_file=/etc/ssl/private/vsftpd.key
```

#### 5.3. **Restart vsftpd Service**

After enabling SSL, restart the vsftpd service:

```bash
sudo systemctl restart vsftpd
```

---

### Conclusion

You have successfully set up **Anonymous FTP** on CentOS 7 using **vsftpd**. You can now share files via FTP without requiring users to authenticate. Additionally, you have the option to secure the FTP connection using SSL/TLS.
