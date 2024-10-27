A comprehensive Nginx cheat sheet that includes essential commands, configurations, and explanations for using Nginx effectively.

---

# **Nginx Extended Cheat Sheet**

## **1. Installation**

### 1.1 Install Nginx on Ubuntu/Debian

**Command:**
```bash
sudo apt update
sudo apt install nginx
```
**Explanation**: Updates the package list and installs the Nginx web server.

### 1.2 Install Nginx on CentOS/RHEL

**Command:**
```bash
sudo yum install epel-release
sudo yum install nginx
```
**Explanation**: Installs the EPEL repository and then installs Nginx.

### 1.3 Install Nginx on macOS using Homebrew

**Command:**
```bash
brew install nginx
```
**Explanation**: Installs Nginx using Homebrew on macOS.

---

## **2. Starting and Stopping Nginx**

### 2.1 Start Nginx

**Command:**
```bash
sudo systemctl start nginx
```
**Explanation**: Starts the Nginx service.

### 2.2 Stop Nginx

**Command:**
```bash
sudo systemctl stop nginx
```
**Explanation**: Stops the Nginx service.

### 2.3 Restart Nginx

**Command:**
```bash
sudo systemctl restart nginx
```
**Explanation**: Restarts the Nginx service.

### 2.4 Reload Nginx Configuration

**Command:**
```bash
sudo systemctl reload nginx
```
**Explanation**: Reloads the Nginx configuration without stopping the service.

### 2.5 Check Nginx Status

**Command:**
```bash
sudo systemctl status nginx
```
**Explanation**: Displays the current status of the Nginx service.

---

## **3. Configuration Files**

### 3.1 Default Configuration File Location

- **Ubuntu/Debian**: `/etc/nginx/nginx.conf`
- **CentOS/RHEL**: `/etc/nginx/nginx.conf`
- **macOS**: `/usr/local/etc/nginx/nginx.conf`

### 3.2 Include Additional Configuration Files

**Command:**
```nginx
include /etc/nginx/conf.d/*.conf;
```
**Explanation**: Allows you to include multiple configuration files from a directory, useful for organizing configurations.

---

## **4. Basic Nginx Server Block Configuration**

### 4.1 Create a Simple Server Block

Create a new configuration file in `/etc/nginx/sites-available/` (on Ubuntu) or directly in `/etc/nginx/conf.d/`.

**Example**:
```nginx
server {
    listen 80;
    server_name example.com www.example.com;

    location / {
        root /var/www/html;
        index index.html index.htm;
    }
}
```
**Explanation**:
- `listen 80;`: Nginx listens on port 80.
- `server_name`: Defines the domain names for the server block.
- `location /`: Sets the configuration for the root location.
- `root`: Specifies the document root for the server.

### 4.2 Enable the Server Block (Ubuntu)

**Command:**
```bash
sudo ln -s /etc/nginx/sites-available/example.com /etc/nginx/sites-enabled/
```
**Explanation**: Creates a symbolic link to enable the server block.

---

## **5. Managing SSL with Nginx**

### 5.1 Generate a Self-Signed SSL Certificate

**Command:**
```bash
sudo openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt
```
**Explanation**: Creates a self-signed SSL certificate valid for 365 days.

### 5.2 Configure Nginx to Use SSL

**Example**:
```nginx
server {
    listen 443 ssl;
    server_name example.com www.example.com;

    ssl_certificate /etc/ssl/certs/nginx-selfsigned.crt;
    ssl_certificate_key /etc/ssl/private/nginx-selfsigned.key;

    location / {
        root /var/www/html;
        index index.html index.htm;
    }
}
```
**Explanation**:
- `listen 443 ssl;`: Nginx listens on port 443 for SSL traffic.
- `ssl_certificate`: Specifies the path to the SSL certificate.
- `ssl_certificate_key`: Specifies the path to the SSL certificate's private key.

### 5.3 Redirect HTTP to HTTPS

**Example**:
```nginx
server {
    listen 80;
    server_name example.com www.example.com;
    return 301 https://$host$request_uri;
}
```
**Explanation**: Redirects all HTTP requests to HTTPS.

---

## **6. Load Balancing with Nginx**

### 6.1 Configure Load Balancing

**Example**:
```nginx
http {
    upstream myapp {
        server app1.example.com;
        server app2.example.com;
    }

    server {
        listen 80;
        server_name example.com;

        location / {
            proxy_pass http://myapp;
        }
    }
}
```
**Explanation**:
- `upstream myapp`: Defines a group of backend servers.
- `proxy_pass`: Directs traffic to the upstream group.

---

## **7. Caching with Nginx**

### 7.1 Configure Caching

**Example**:
```nginx
http {
    proxy_cache_path /var/cache/nginx levels=1:2 keys_zone=my_cache:10m max_size=1g inactive=60m use_temp_path=off;

    server {
        location / {
            proxy_pass http://backend;
            proxy_cache my_cache;
            proxy_cache_valid 200 1h;
        }
    }
}
```
**Explanation**:
- `proxy_cache_path`: Specifies the cache directory and parameters.
- `proxy_cache`: Enables caching for the location.
- `proxy_cache_valid`: Sets cache duration for responses.

---

## **8. Viewing Logs**

### 8.1 Access Error Logs

**Command:**
```bash
sudo tail -f /var/log/nginx/error.log
```
**Explanation**: Continuously displays the last lines of the Nginx error log.

### 8.2 Access Access Logs

**Command:**
```bash
sudo tail -f /var/log/nginx/access.log
```
**Explanation**: Continuously displays the last lines of the Nginx access log.

---

## **9. Testing Nginx Configuration**

### 9.1 Test Configuration for Syntax Errors

**Command:**
```bash
sudo nginx -t
```
**Explanation**: Tests the Nginx configuration file for syntax errors and displays the result.

---

## **10. Common Nginx Directives**

| Directive            | Description                                                    |
|----------------------|---------------------------------------------------------------|
| `listen`             | Specifies the port and protocol (HTTP or HTTPS).             |
| `server_name`        | Defines the domain names that the server block responds to.  |
| `location`           | Sets configuration for specific request paths.               |
| `root`               | Specifies the root directory for requests.                    |
| `index`              | Defines the index file(s) to serve when a directory is requested. |
| `try_files`         | Attempts to serve files, falling back to a specified URI if not found. |
| `proxy_pass`         | Forwards requests to a proxied server.                       |

---

This cheat sheet provides a comprehensive overview of how to use Nginx, covering common commands, configurations, and tips.
