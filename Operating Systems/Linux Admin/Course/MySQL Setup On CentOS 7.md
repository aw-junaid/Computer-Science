### Setting Up MySQL on CentOS 7

MySQL is an open-source relational database management system (RDBMS) widely used in various applications. In this guide, you’ll learn how to install, configure, and secure MySQL on CentOS 7.

---

### 1. **Install MySQL on CentOS 7**

#### 1.1. **Install MySQL Server**

CentOS 7 uses the **MySQL 5.7** or **MariaDB** (a fork of MySQL) by default. However, if you need to install MySQL specifically (and not MariaDB), you can enable the MySQL repository and install it.

To install MySQL, you can use the official MySQL repository.

```bash
# Download the MySQL Community Repository
sudo wget https://dev.mysql.com/get/mysql80-community-release-el7-3.noarch.rpm

# Install the repository
sudo rpm -ivh mysql80-community-release-el7-3.noarch.rpm

# Install MySQL Server
sudo yum install mysql-community-server -y
```

This will install MySQL 8.0. You can check the version of MySQL that is installed:

```bash
mysql --version
```

#### 1.2. **Start MySQL Service**

Once MySQL is installed, start the MySQL service using `systemctl`:

```bash
sudo systemctl start mysqld
```

#### 1.3. **Enable MySQL to Start on Boot**

To ensure MySQL starts automatically when the system reboots:

```bash
sudo systemctl enable mysqld
```

#### 1.4. **Verify MySQL is Running**

Check if MySQL is running by using the following command:

```bash
sudo systemctl status mysqld
```

The output should show that MySQL is active and running.

---

### 2. **Secure MySQL Installation**

MySQL provides a built-in security script that helps to secure the MySQL installation by setting a root password and removing insecure default settings.

#### 2.1. **Run the Security Script**

To run the MySQL secure installation script:

```bash
sudo mysql_secure_installation
```

You will be prompted to configure several settings:

1. **Set a root password** (if it hasn’t been set already).
2. **Remove the test database** (recommended for production environments).
3. **Disallow remote root login** (recommended for security purposes).
4. **Remove anonymous users** (recommended for security purposes).
5. **Reload privilege tables** to ensure all changes take effect.

---

### 3. **Login to MySQL**

Once MySQL is installed and secured, you can log in as the root user:

```bash
sudo mysql -u root -p
```

Enter the password you set during the `mysql_secure_installation` process.

You should now be in the MySQL shell, where you can run SQL commands.

---

### 4. **Create a New MySQL User and Database (Optional)**

It’s a good practice not to use the root user for regular database operations. Below are the steps to create a new user and database.

#### 4.1. **Create a New Database**

Once logged into the MySQL shell, you can create a new database:

```sql
CREATE DATABASE mydatabase;
```

#### 4.2. **Create a New User**

Create a new user with the following command:

```sql
CREATE USER 'myuser'@'localhost' IDENTIFIED BY 'mypassword';
```

#### 4.3. **Grant Privileges to the User**

Now, grant the necessary privileges to the user for accessing the database:

```sql
GRANT ALL PRIVILEGES ON mydatabase.* TO 'myuser'@'localhost';
```

#### 4.4. **Flush Privileges**

To apply the changes, flush the privileges:

```sql
FLUSH PRIVILEGES;
```

#### 4.5. **Exit MySQL**

Exit the MySQL shell:

```sql
EXIT;
```

---

### 5. **Configuring MySQL**

MySQL configuration files are located in `/etc/my.cnf` or `/etc/my.cnf.d/`. You may need to adjust these files for performance tuning, security settings, and other configurations based on your use case.

#### 5.1. **Edit MySQL Configuration File**

To edit the MySQL configuration, use your favorite text editor:

```bash
sudo vi /etc/my.cnf
```

You can modify the `bind-address` to control which IP addresses MySQL can listen on, change the `max_connections` limit, and configure other parameters.

#### 5.2. **Restart MySQL After Configuration Changes**

After modifying the configuration file, restart MySQL for the changes to take effect:

```bash
sudo systemctl restart mysqld
```

---

### 6. **Access MySQL Remotely (Optional)**

By default, MySQL is bound to `localhost`, which means you can only connect to MySQL from the same machine. If you want to allow remote access, you need to change the `bind-address` in the MySQL configuration file:

1. Open the MySQL configuration file:

```bash
sudo vi /etc/my.cnf
```

2. Find the line with `bind-address` and change it to `0.0.0.0` or the specific IP address you want MySQL to listen on:

```ini
bind-address = 0.0.0.0
```

3. Restart MySQL for the changes to take effect:

```bash
sudo systemctl restart mysqld
```

4. **Allow MySQL in the Firewall**

If you're using `firewalld`, allow MySQL traffic on port `3306`:

```bash
sudo firewall-cmd --permanent --add-service=mysql
sudo firewall-cmd --reload
```

5. **Grant Remote Access to MySQL User**

To allow remote users to access MySQL, you need to grant privileges to the user for specific hosts:

```sql
GRANT ALL PRIVILEGES ON mydatabase.* TO 'myuser'@'%' IDENTIFIED BY 'mypassword';
```

The `%` symbol allows connections from any host. Replace it with a specific IP address for more security.

---

### 7. **Backup and Restore MySQL Databases**

#### 7.1. **Backup MySQL Database**

To backup a MySQL database, use the `mysqldump` command:

```bash
mysqldump -u myuser -p mydatabase > mydatabase_backup.sql
```

This will create a backup of `mydatabase` and store it in a `.sql` file.

#### 7.2. **Restore MySQL Database**

To restore the backup, use the following command:

```bash
mysql -u myuser -p mydatabase < mydatabase_backup.sql
```

---

### 8. **Monitor MySQL**

MySQL provides several tools for monitoring performance:

- **Show Processlist**: Shows the current threads being executed by MySQL.

```sql
SHOW PROCESSLIST;
```

- **MySQL Status**: Provides server statistics.

```sql
SHOW STATUS;
```

- **Check MySQL Error Log**: MySQL error logs are located in `/var/log/mysqld.log` by default. You can check the log for any errors:

```bash
sudo tail -f /var/log/mysqld.log
```

---

### Conclusion

You have successfully installed MySQL on CentOS 7. You can now create databases, users, and manage permissions. Additionally, you’ve learned how to secure MySQL, enable remote access, and configure basic settings. MySQL is now ready for use in your applications.
