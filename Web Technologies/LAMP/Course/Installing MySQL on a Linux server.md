### **Installing MySQL on a Linux Server**

Installing MySQL on a Linux server depends on the distribution you're using. The two most common Linux distributions are **Ubuntu/Debian** (which uses `apt` package manager) and **CentOS/Red Hat** (which uses `yum` or `dnf` package manager).

Below are the steps to install MySQL on both distributions.

---

### **1. Installing MySQL on Ubuntu/Debian**

#### **Step 1: Update the Package Repository**
Before installing any packages, it's a good practice to update your package repository to ensure you get the latest versions.

```bash
sudo apt update
```

#### **Step 2: Install MySQL Server**
Install the MySQL server package using the `apt` package manager.

```bash
sudo apt install mysql-server
```

This will install the latest stable version of MySQL available in the Ubuntu/Debian repositories.

#### **Step 3: Start MySQL Service**
Once installed, MySQL should start automatically. If it doesn't, you can start it manually using `systemctl`.

```bash
sudo systemctl start mysql
```

You can verify that MySQL is running by checking its status.

```bash
sudo systemctl status mysql
```

#### **Step 4: Secure MySQL Installation**
MySQL comes with a script to help secure your installation by setting a root password, removing insecure default settings, and disabling remote root login.

Run the security script:

```bash
sudo mysql_secure_installation
```

Follow the on-screen prompts:
- Set the root password.
- Remove insecure default settings (e.g., anonymous users, test databases, etc.).
- Disallow root login remotely (recommended for security).
- Reload privilege tables to apply changes.

#### **Step 5: Enable MySQL to Start on Boot**
To ensure MySQL starts automatically when the system boots, use the following command:

```bash
sudo systemctl enable mysql
```

#### **Step 6: Log into MySQL**
To log into MySQL as the root user, use the `mysql` command:

```bash
sudo mysql -u root -p
```

Enter the root password when prompted. Once logged in, you can start managing your MySQL databases.

---

### **2. Installing MySQL on CentOS/Red Hat**

#### **Step 1: Update the Package Repository**
Update the system package repository to ensure the latest versions are available.

```bash
sudo yum update    # For CentOS 7 / RHEL 7
```
or
```bash
sudo dnf update    # For CentOS 8 / RHEL 8 and newer
```

#### **Step 2: Install MySQL Server**
CentOS/RHEL 7 and earlier versions use `yum`, while CentOS/RHEL 8 and later versions use `dnf`. Install MySQL with the following command:

For CentOS 7/RHEL 7:
```bash
sudo yum install mysql-server
```

For CentOS 8/RHEL 8:
```bash
sudo dnf install mysql-server
```

#### **Step 3: Start MySQL Service**
Once the installation is complete, start the MySQL service:

```bash
sudo systemctl start mysqld
```

#### **Step 4: Check MySQL Service Status**
To verify that MySQL is running, check the service status:

```bash
sudo systemctl status mysqld
```

#### **Step 5: Secure MySQL Installation**
Like on Ubuntu/Debian, MySQL provides a script to secure your installation.

Run the security script:

```bash
sudo mysql_secure_installation
```

You will be prompted to:
- Set the root password.
- Remove insecure default settings (e.g., anonymous users, test databases, etc.).
- Disallow root login remotely (recommended for security).
- Reload privilege tables to apply changes.

#### **Step 6: Enable MySQL to Start on Boot**
To enable MySQL to start automatically after a reboot:

```bash
sudo systemctl enable mysqld
```

#### **Step 7: Retrieve the Temporary MySQL Root Password**
When MySQL is first installed on CentOS/RHEL, a temporary root password is generated. You can find this password by viewing the MySQL log:

```bash
sudo grep 'temporary password' /var/log/mysqld.log
```

Note down the temporary password and use it to log into MySQL for the first time.

#### **Step 8: Log into MySQL**
To log into MySQL as the root user, use the following command:

```bash
sudo mysql -u root -p
```

You will be prompted to enter the root password. Enter the temporary password and change it immediately upon login.

---

### **3. Verifying MySQL Installation**

Once MySQL is installed and running, you can perform basic verification.

- **Check MySQL Version**: To check the installed MySQL version, run the following command in MySQL:

  ```sql
  SELECT VERSION();
  ```

- **Check MySQL Databases**: To see the available databases:

  ```sql
  SHOW DATABASES;
  ```

- **Create a New Database**: To create a new database:

  ```sql
  CREATE DATABASE my_database;
  ```

- **Create a New User**: To create a new MySQL user:

  ```sql
  CREATE USER 'new_user'@'localhost' IDENTIFIED BY 'password';
  ```

- **Grant Privileges**: To grant the user privileges on a specific database:

  ```sql
  GRANT ALL PRIVILEGES ON my_database.* TO 'new_user'@'localhost';
  ```

---

### **Conclusion**

MySQL can be installed on both Ubuntu/Debian and CentOS/Red Hat-based Linux systems with straightforward commands using the respective package managers (`apt`, `yum`, or `dnf`). After installation, securing the installation, starting the MySQL service, and configuring it to start on boot are essential steps to ensure a secure and functional MySQL server. Afterward, you can log into MySQL and start creating databases, users, and managing your data.
