### Configuring PHP in CentOS Linux

PHP is a popular server-side scripting language commonly used for web development. In CentOS, PHP is typically configured for use with a web server such as **Apache** or **NGINX**. This guide walks you through installing, configuring, and optimizing PHP on a CentOS system.

---

### 1. **Install PHP on CentOS**

#### 1.1. **Install PHP Using YUM**
CentOS 7/8 provides a default version of PHP in the official repository, but it may not always be the latest. You can install PHP using the **yum** or **dnf** package manager depending on the version of CentOS you are using.

- **Install PHP (default version) on CentOS 7/8:**

  **For CentOS 7:**
  ```bash
  sudo yum install php php-cli php-common php-fpm php-mysqlnd php-gd php-xml php-mbstring
  ```

  **For CentOS 8:**
  ```bash
  sudo dnf install php php-cli php-common php-fpm php-mysqlnd php-gd php-xml php-mbstring
  ```

- **Install specific PHP version** (for example, PHP 7.4 or PHP 8.0) from the **Remi repository** (Recommended for newer PHP versions):

  First, install the **EPEL** and **Remi** repositories:
  ```bash
  sudo yum install epel-release
  sudo yum install yum-utils
  sudo yum install -y http://rpms.remirepo.net/enterprise/remi-release-7.rpm
  sudo yum install -y https://rpms.remirepo.net/enterprise/remi-release-8.rpm
  ```

  Enable the Remi repository:
  ```bash
  sudo yum install yum-utils
  sudo yum-config-manager --enable remi-php74
  ```

  Then, install the desired version of PHP:
  ```bash
  sudo yum install php php-cli php-common php-fpm php-mysqlnd php-gd php-xml php-mbstring
  ```

#### 1.2. **Verify PHP Installation**
After installation, verify the PHP version installed:
```bash
php -v
```

Example output:
```
PHP 7.4.3 (cli) (built: Mar  4 2021 08:29:19) ( NTS )
```

---

### 2. **Configure PHP with Apache or NGINX**

#### 2.1. **Configure PHP with Apache**

- **Install Apache Web Server**:
  If you don't have Apache installed, install it:
  ```bash
  sudo yum install httpd
  ```

- **Start and Enable Apache**:
  ```bash
  sudo systemctl start httpd
  sudo systemctl enable httpd
  ```

- **Install PHP for Apache**:
  Make sure the required PHP modules are installed for Apache:
  ```bash
  sudo yum install php php-common php-mysqlnd php-fpm
  ```

- **Restart Apache to Apply Changes**:
  ```bash
  sudo systemctl restart httpd
  ```

- **Test PHP in Apache**:
  Create a simple PHP test file to verify PHP works with Apache.

  Create the file `/var/www/html/info.php`:
  ```bash
  sudo vi /var/www/html/info.php
  ```

  Add the following content:
  ```php
  <?php
  phpinfo();
  ?>
  ```

  Visit `http://your_server_ip/info.php` in your browser. You should see a page with detailed information about your PHP installation.

#### 2.2. **Configure PHP with NGINX**

- **Install NGINX**:
  ```bash
  sudo yum install nginx
  ```

- **Install PHP-FPM (FastCGI Process Manager)**:
  PHP-FPM is used with NGINX for serving PHP.
  ```bash
  sudo yum install php-fpm
  ```

- **Configure PHP-FPM**:
  Edit the PHP-FPM configuration file to ensure it works with NGINX:
  ```bash
  sudo vi /etc/php-fpm.d/www.conf
  ```

  Find the line:
  ```
  user = apache
  ```
  Change it to:
  ```
  user = nginx
  ```

  And find the line:
  ```
  group = apache
  ```
  Change it to:
  ```
  group = nginx
  ```

- **Start PHP-FPM**:
  ```bash
  sudo systemctl start php-fpm
  sudo systemctl enable php-fpm
  ```

- **Configure NGINX to Use PHP-FPM**:
  Edit the NGINX server block to pass PHP requests to PHP-FPM.

  Open the default NGINX configuration file:
  ```bash
  sudo vi /etc/nginx/conf.d/default.conf
  ```

  Add the following location block inside the `server` block:
  ```nginx
  location ~ \.php$ {
      fastcgi_pass 127.0.0.1:9000;
      fastcgi_index index.php;
      fastcgi_param SCRIPT_FILENAME /usr/share/nginx/html$fastcgi_script_name;
      include fastcgi_params;
  }
  ```

- **Start and Enable NGINX**:
  ```bash
  sudo systemctl start nginx
  sudo systemctl enable nginx
  ```

- **Test PHP in NGINX**:
  Create the `/usr/share/nginx/html/info.php` file:
  ```bash
  sudo vi /usr/share/nginx/html/info.php
  ```

  Add the following content:
  ```php
  <?php
  phpinfo();
  ?>
  ```

  Visit `http://your_server_ip/info.php` to verify the PHP installation.

---

### 3. **PHP Configuration Settings**

The PHP configuration file is called **php.ini**. It controls various settings for how PHP behaves, such as memory limits, file upload sizes, time zone settings, etc.

#### 3.1. **Edit php.ini**

- The default location of the PHP configuration file on CentOS is `/etc/php.ini`.

  To edit the file:
  ```bash
  sudo vi /etc/php.ini
  ```

- Some common settings to modify:
  - **Increase memory limit**:
    ```ini
    memory_limit = 256M
    ```

  - **Set file upload size**:
    ```ini
    upload_max_filesize = 50M
    post_max_size = 50M
    ```

  - **Set default time zone**:
    ```ini
    date.timezone = "America/New_York"
    ```

  - **Enable or disable PHP extensions**:
    Uncomment the required extensions. For example, to enable `mbstring`:
    ```ini
    extension=mbstring
    ```

#### 3.2. **Restart Services**
After modifying `php.ini`, restart your web server (Apache or NGINX) and PHP-FPM (if applicable) to apply changes.

- For Apache:
  ```bash
  sudo systemctl restart httpd
  ```

- For NGINX (if using PHP-FPM):
  ```bash
  sudo systemctl restart php-fpm
  sudo systemctl restart nginx
  ```

---

### 4. **Additional PHP Modules**

PHP has a wide variety of extensions/modules available to enhance functionality. Here are a few commonly used modules:

- **Install MySQL/MariaDB PHP Module**:
  ```bash
  sudo yum install php-mysqlnd
  ```

- **Install GD Library (for image manipulation)**:
  ```bash
  sudo yum install php-gd
  ```

- **Install mbstring (for multi-byte character encoding)**:
  ```bash
  sudo yum install php-mbstring
  ```

- **Install XML module**:
  ```bash
  sudo yum install php-xml
  ```

- **Install curl module**:
  ```bash
  sudo yum install php-curl
  ```

After installing any new PHP module, restart the web server or PHP-FPM.

---

### 5. **Security Considerations**

- **Disable `phpinfo()` in Production**:
  Avoid using `phpinfo()` in production environments, as it exposes sensitive server information.

- **Configure PHP-FPM Security**:
  - Make sure the **user** and **group** in `/etc/php-fpm.d/www.conf` are set correctly.
  - Ensure that **`listen.owner`** and **`listen.group`** are set to `nginx` or `apache` to prevent unauthorized access.

---

### Conclusion

Configuring PHP on CentOS is straightforward, whether you're using **Apache** or **NGINX**. After installing PHP, you can configure it through the **php.ini** file and enable necessary extensions for your applications. Proper configuration ensures that PHP runs efficiently and securely on your CentOS server.
