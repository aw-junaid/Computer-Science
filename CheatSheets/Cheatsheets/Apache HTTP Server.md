An extended cheat sheet for the Apache HTTP Server, covering essential commands, configurations, and explanations to help you effectively manage and deploy web applications using Apache.

---

# **Apache HTTP Server Extended Cheat Sheet**

## **1. Prerequisites**

### 1.1 Install Apache HTTP Server

#### On Debian/Ubuntu:

```bash
sudo apt update
sudo apt install apache2
```

#### On CentOS/RHEL:

```bash
sudo yum install httpd
```

**Explanation**: These commands install the Apache HTTP Server on your system. The package manager handles all dependencies and configurations.

### 1.2 Start and Enable Apache

#### Start Apache

```bash
sudo systemctl start apache2     # For Ubuntu/Debian
sudo systemctl start httpd       # For CentOS/RHEL
```

**Explanation**: Starts the Apache HTTP Server service.

#### Enable Apache to Start on Boot

```bash
sudo systemctl enable apache2     # For Ubuntu/Debian
sudo systemctl enable httpd       # For CentOS/RHEL
```

**Explanation**: Configures the Apache service to start automatically at boot time.

---

## **2. Basic Commands**

### 2.1 Check Apache Status

```bash
sudo systemctl status apache2     # For Ubuntu/Debian
sudo systemctl status httpd       # For CentOS/RHEL
```

**Explanation**: Displays the current status of the Apache service, indicating whether it is running or inactive.

### 2.2 Restart Apache

```bash
sudo systemctl restart apache2     # For Ubuntu/Debian
sudo systemctl restart httpd       # For CentOS/RHEL
```

**Explanation**: Restarts the Apache HTTP Server service, applying any configuration changes.

### 2.3 Stop Apache

```bash
sudo systemctl stop apache2     # For Ubuntu/Debian
sudo systemctl stop httpd       # For CentOS/RHEL
```

**Explanation**: Stops the Apache HTTP Server service.

### 2.4 Reload Apache Configuration

```bash
sudo systemctl reload apache2     # For Ubuntu/Debian
sudo systemctl reload httpd       # For CentOS/RHEL
```

**Explanation**: Reloads the Apache configuration files without terminating existing connections.

---

## **3. Configuration Files**

### 3.1 Main Configuration File

**File**:  
`/etc/apache2/apache2.conf` (Ubuntu/Debian)  
`/etc/httpd/conf/httpd.conf` (CentOS/RHEL)

**Explanation**: This is the main configuration file for the Apache HTTP Server where global settings are defined.

### 3.2 Virtual Hosts Configuration

#### Default Configuration File:

**File**:  
`/etc/apache2/sites-available/000-default.conf` (Ubuntu/Debian)  
`/etc/httpd/conf.d/vhost.conf` (CentOS/RHEL)

**Explanation**: This file defines virtual hosts, allowing multiple websites to be hosted on the same server.

---

## **4. Managing Virtual Hosts**

### 4.1 Create a Virtual Host

**Example Configuration**:
```apache
<VirtualHost *:80>
    ServerName example.com
    DocumentRoot /var/www/example.com/public_html
    ErrorLog ${APACHE_LOG_DIR}/error.log
    CustomLog ${APACHE_LOG_DIR}/access.log combined
</VirtualHost>
```

**Explanation**: This configuration sets up a virtual host for `example.com`, serving files from the specified document root. 

### 4.2 Enable a Virtual Host

For Ubuntu/Debian systems, you need to enable the virtual host after creating it:

```bash
sudo a2ensite example.com.conf
```

**Explanation**: This command enables the specified virtual host configuration.

### 4.3 Disable a Virtual Host

```bash
sudo a2dissite example.com.conf
```

**Explanation**: Disables the specified virtual host configuration.

### 4.4 Restart Apache After Changes

After enabling or disabling a virtual host, restart Apache:

```bash
sudo systemctl restart apache2     # For Ubuntu/Debian
sudo systemctl restart httpd       # For CentOS/RHEL
```

---

## **5. Directory Permissions and Access Control**

### 5.1 Set Directory Permissions

In your virtual host configuration:

```apache
<Directory /var/www/example.com/public_html>
    AllowOverride All
    Require all granted
</Directory>
```

**Explanation**: This configuration allows `.htaccess` files to override settings and grants access to the specified directory.

### 5.2 Deny Access to a Directory

```apache
<Directory /var/www/private>
    Require all denied
</Directory>
```

**Explanation**: This configuration denies access to the `/private` directory.

---

## **6. Common Apache Modules**

### 6.1 Enable a Module

For Ubuntu/Debian systems:

```bash
sudo a2enmod rewrite
```

**Explanation**: This command enables the `rewrite` module, which allows for URL rewriting.

### 6.2 Disable a Module

```bash
sudo a2dismod rewrite
```

**Explanation**: This command disables the specified module.

### 6.3 List Enabled Modules

```bash
apache2ctl -M     # For Ubuntu/Debian
httpd -M          # For CentOS/RHEL
```

**Explanation**: Lists all currently enabled modules in the Apache HTTP Server.

---

## **7. SSL Configuration**

### 7.1 Install OpenSSL (if not already installed)

```bash
sudo apt install openssl     # For Ubuntu/Debian
sudo yum install openssl     # For CentOS/RHEL
```

### 7.2 Create a Self-Signed SSL Certificate

```bash
sudo openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
  -keyout /etc/ssl/private/apache-selfsigned.key \
  -out /etc/ssl/certs/apache-selfsigned.crt
```

**Explanation**: This command generates a self-signed SSL certificate valid for one year.

### 7.3 Enable SSL Module

```bash
sudo a2enmod ssl
```

**Explanation**: Enables the SSL module for Apache.

### 7.4 Configure SSL in Virtual Host

**Example Configuration**:
```apache
<VirtualHost *:443>
    ServerName example.com
    DocumentRoot /var/www/example.com/public_html

    SSLEngine on
    SSLCertificateFile /etc/ssl/certs/apache-selfsigned.crt
    SSLCertificateKeyFile /etc/ssl/private/apache-selfsigned.key
</VirtualHost>
```

**Explanation**: This configuration sets up an SSL-enabled virtual host.

### 7.5 Redirect HTTP to HTTPS

To redirect traffic from HTTP to HTTPS, add the following in your virtual host for port 80:

```apache
<VirtualHost *:80>
    ServerName example.com
    Redirect permanent / https://example.com/
</VirtualHost>
```

**Explanation**: This configuration permanently redirects HTTP requests to HTTPS.

---

## **8. Performance Optimization**

### 8.1 Enable KeepAlive

In the main configuration file (`apache2.conf` or `httpd.conf`):

```apache
KeepAlive On
MaxKeepAliveRequests 100
KeepAliveTimeout 5
```

**Explanation**: Enables persistent connections, allowing multiple requests to be sent over a single connection.

### 8.2 Configure Caching

**Example Configuration**:
```apache
<IfModule mod_cache.c>
    CacheQuickHandler off
    CacheIgnoreCacheControl On
    CacheIgnoreNoLastMod On
    CacheDefaultExpire 3600
</IfModule>
```

**Explanation**: Configures caching to improve performance.

---

## **9. Common Apache Commands**

| Command                                          | Description                                           |
|--------------------------------------------------|-------------------------------------------------------|
| `sudo systemctl start apache2`                  | Starts the Apache server.                            |
| `sudo systemctl stop apache2`                   | Stops the Apache server.                             |
| `sudo systemctl restart apache2`                | Restarts the Apache server.                          |
| `sudo systemctl reload apache2`                 | Reloads Apache configuration.                        |
| `sudo a2ensite <site>`                           | Enables a virtual host.                              |
| `sudo a2dissite <site>`                          | Disables a virtual host.                             |
| `apache2ctl -M`                                  | Lists enabled modules.                               |

---

## **10. Conclusion**

This Apache HTTP Server cheat sheet covers essential commands, configuration files, and management practices to help you effectively deploy and manage web applications on Apache. Familiarity with these commands and configurations will streamline your development and operational tasks in an Apache environment.
