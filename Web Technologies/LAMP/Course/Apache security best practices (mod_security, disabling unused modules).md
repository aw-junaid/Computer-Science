### **Apache Security Best Practices: mod_security, Disabling Unused Modules, and More**

Apache is one of the most widely used web servers, and its security is crucial to prevent attacks, data breaches, and unauthorized access to your server. Below, we’ll discuss several key security best practices for securing your Apache server, including the use of **mod_security**, disabling unused modules, and other critical security configurations.

---

### **1. Use `mod_security` for Web Application Firewall (WAF)**

**mod_security** is an open-source web application firewall (WAF) for Apache. It helps protect web applications from a variety of attacks, such as SQL injection, cross-site scripting (XSS), and remote file inclusion (RFI). It works by inspecting HTTP requests and responses and filtering out malicious activity.

#### **1.1 Installing and Enabling `mod_security`**

On a **Debian/Ubuntu** system, you can install `mod_security` with the following commands:

```bash
sudo apt update
sudo apt install libapache2-mod-security2
```

On **CentOS/RHEL** systems, use:

```bash
sudo yum install mod_security
```

Once installed, enable and restart Apache:

```bash
sudo a2enmod security2  # Enable mod_security
sudo systemctl restart apache2
```

#### **1.2 Configuration and Rules**

After installation, `mod_security` is usually configured with a default set of rules, but you can use custom rules to enhance protection. The configuration file is typically located in `/etc/modsecurity/modsecurity.conf`.

- Enable `mod_security` by setting:

```bash
SecRuleEngine On
```

- Use recommended **OWASP Core Rule Set** (CRS) for protection against common attacks. The CRS can be downloaded and configured for comprehensive protection.

#### **1.3 Tuning mod_security**

- **Logging**: It's essential to enable logging of blocked requests to detect false positives and malicious activity:

```bash
SecAuditLog /var/log/apache2/modsec_audit.log
SecAuditLogParts ABIJDEFHZ
```

- **Performance Considerations**: While `mod_security` offers excellent protection, it can add overhead. You may need to tune it for performance by configuring specific rules to be disabled for high-traffic sites or adding exceptions for certain requests.

---

### **2. Disabling Unused Apache Modules**

Apache comes with many modules, but not all are necessary for your environment. Disabling unused modules reduces the attack surface and helps improve server performance.

#### **2.1 Identifying Enabled Modules**

You can list all enabled modules using the following command:

```bash
apache2ctl -M  # For Debian/Ubuntu systems
httpd -M  # For CentOS/RHEL systems
```

This will display a list of currently enabled modules.

#### **2.2 Disabling Unnecessary Modules**

To disable an unused module, you can either comment it out in the Apache configuration files or use `a2dismod` (on Debian/Ubuntu systems):

For example, to disable `mod_status`:

```bash
sudo a2dismod status
sudo systemctl restart apache2
```

For CentOS/RHEL, you can manually comment out the module in `/etc/httpd/conf/httpd.conf` or `/etc/httpd/conf.d/*`:

```apache
# LoadModule status_module modules/mod_status.so
```

#### **2.3 Common Unused Modules to Disable**

Consider disabling the following modules, unless they are needed for your specific use case:

- **mod_userdir**: This module allows users to host their websites in their home directories. If not needed, disable it to prevent access to sensitive directories.
  
- **mod_info**: This module provides server information through a web interface, which can expose sensitive configuration details.
  
- **mod_status**: Similar to `mod_info`, this module provides server status information and should be disabled unless necessary for monitoring purposes.
  
- **mod_autoindex**: This module generates directory listings when no index file is present. Disabling it can prevent unauthorized directory browsing.

- **mod_cgi**: If you do not require CGI scripts, disable this module to prevent potential security risks.

- **mod_php**: If you don't need PHP support, disabling `mod_php` can reduce security risks, especially if PHP isn't in use.

---

### **3. Secure Apache Configuration**

#### **3.1 Disable Directory Listing**

Ensure that directory listings are disabled to prevent users from viewing the contents of directories without an index file:

```apache
Options -Indexes
```

This directive should be included in the main Apache configuration or in the `.htaccess` file.

#### **3.2 Prevent Clickjacking**

Clickjacking is a technique where a malicious website tricks users into clicking something different from what they perceive. You can prevent it by setting the `X-Frame-Options` header:

```apache
Header always set X-Frame-Options "SAMEORIGIN"
```

This configuration tells the browser to only allow your pages to be framed by the same origin, mitigating clickjacking attacks.

#### **3.3 Prevent Cross-Site Scripting (XSS) and Content Injection**

To protect against XSS and content injection attacks, set the `X-XSS-Protection` and `Content-Security-Policy` headers:

```apache
Header set X-XSS-Protection "1; mode=block"
Header set Content-Security-Policy "default-src 'self'; script-src 'self'; object-src 'none';"
```

This configuration enables basic XSS protection and restricts which resources can be loaded on your site.

#### **3.4 Disable HTTP Methods**

Disable HTTP methods that are not needed, such as `TRACE`, `DELETE`, and `OPTIONS`. These methods can sometimes be exploited to gain unauthorized access or execute unwanted actions.

To disable unnecessary HTTP methods:

```apache
<LimitExcept GET POST>
  Deny from all
</LimitExcept>
```

This restricts all HTTP methods except `GET` and `POST`, which are the most commonly used.

#### **3.5 Configure `AllowOverride` Settings**

Using `.htaccess` files can be a security risk if not configured properly. In production environments, limit the use of `.htaccess` files and configure `AllowOverride` to minimize risk:

```apache
<Directory /var/www/html>
    AllowOverride None
</Directory>
```

This prevents Apache from reading `.htaccess` files, ensuring that only server-wide settings are used.

---

### **4. Use SSL/TLS for Encrypted Communication**

To protect data in transit, use **SSL/TLS** encryption for all communications between clients and your Apache server.

#### **4.1 Install and Configure SSL**

To enable SSL on Apache, you need to install an SSL certificate and configure Apache to use HTTPS.

On **Debian/Ubuntu** systems:

```bash
sudo apt install apache2 ssl-cert
sudo a2enmod ssl
sudo a2ensite default-ssl
```

On **CentOS/RHEL** systems:

```bash
sudo yum install mod_ssl
```

Then configure Apache to use SSL:

```apache
<VirtualHost *:443>
    ServerAdmin webmaster@example.com
    DocumentRoot /var/www/html
    SSLEngine on
    SSLCertificateFile /etc/ssl/certs/your_cert.pem
    SSLCertificateKeyFile /etc/ssl/private/your_key.pem
    SSLCertificateChainFile /etc/ssl/certs/your_chain.pem
</VirtualHost>
```

Make sure to replace the certificate and key paths with the actual files from your SSL certificate provider.

#### **4.2 Redirect HTTP to HTTPS**

To ensure that all traffic uses HTTPS, configure a redirect from HTTP to HTTPS:

```apache
<VirtualHost *:80>
    ServerAdmin webmaster@example.com
    DocumentRoot /var/www/html
    Redirect permanent / https://yourdomain.com/
</VirtualHost>
```

This will automatically redirect all HTTP traffic to the HTTPS version of your site.

---

### **5. Other Apache Security Best Practices**

- **Update Apache Regularly**: Ensure Apache is always updated with the latest security patches. Use your package manager to check for updates.
  
- **Limit Access to Sensitive Files**: Protect sensitive files, such as configuration files, by limiting access to them. For example:

```apache
<FilesMatch "\.(htaccess|htpasswd|ini|conf)$">
    Order Allow,Deny
    Deny from all
</FilesMatch>
```

This configuration denies access to `.htaccess`, `.htpasswd`, and other sensitive files.

- **Run Apache with Least Privilege**: Run Apache under a user with the least privilege possible, typically `www-data` or `apache`. Avoid running Apache as the root user.

- **Use Fail2Ban for Brute Force Protection**: Fail2Ban can help protect Apache from brute-force login attempts by blocking IPs that attempt to access protected areas too many times.

---

### **Conclusion**

Securing your Apache web server involves a combination of configuring security modules like **mod_security**, disabling unused modules, enforcing strong SSL/TLS encryption, and implementing other protective measures like HTTP headers, method restrictions, and directory browsing prevention. Regularly reviewing your Apache configurations and security practices is vital to protecting your web server from potential attacks.
