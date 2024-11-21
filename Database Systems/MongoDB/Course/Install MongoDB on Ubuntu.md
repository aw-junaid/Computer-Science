To install MongoDB on Ubuntu, follow these steps:

### **Step 1: Update System Packages**
First, ensure your system’s package list is up-to-date by running the following command:

```bash
sudo apt update
```

### **Step 2: Install MongoDB**
MongoDB is available in Ubuntu's official package repository, but to get the latest stable version, you’ll need to install it from the MongoDB repository.

#### **Add MongoDB Repository**
1. **Import the MongoDB public GPG key:**

   ```bash
   wget -qO - https://www.mongodb.org/static/pgp/server-6.0.asc | sudo gpg --dearmor -o /usr/share/keyrings/mongodb-archive-keyring.gpg
   ```

2. **Add the MongoDB repository:**

   ```bash
   echo "deb [signed-by=/usr/share/keyrings/mongodb-archive-keyring.gpg] https://repo.mongodb.org/apt/ubuntu focal/mongodb-org/6.0 multiverse" | sudo tee /etc/apt/sources.list.d/mongodb-org-6.0.list
   ```

   **Note:** Replace `focal` with your Ubuntu version (e.g., `bionic`, `xenial`, etc.) if you're using a different version of Ubuntu.

#### **Update package database again**

```bash
sudo apt update
```

#### **Install MongoDB**

Now, install MongoDB by running:

```bash
sudo apt install -y mongodb-org
```

This will install the latest stable version of MongoDB and its related components.

### **Step 3: Start and Enable MongoDB Service**
Once the installation is complete, start the MongoDB service:

```bash
sudo systemctl start mongod
```

To ensure MongoDB starts automatically on system boot, enable the service:

```bash
sudo systemctl enable mongod
```

### **Step 4: Verify MongoDB Installation**
You can verify that MongoDB is running by checking the status of the MongoDB service:

```bash
sudo systemctl status mongod
```

It should show something like this if MongoDB is running:

```
Active: active (running) since Mon 2024-11-11 00:00:00 UTC; 1min ago
```

Additionally, you can verify MongoDB’s version by entering the Mongo shell:

```bash
mongosh
```

This should open the MongoDB shell, and you can run a simple command like:

```bash
db.version()
```

This will return the installed MongoDB version.

### **Step 5: Open MongoDB Port (Optional)**
By default, MongoDB runs on port `27017`. If you need to access it remotely, ensure that your firewall allows traffic on this port.

If you're using **UFW** (Uncomplicated Firewall), run the following command to allow traffic on port 27017:

```bash
sudo ufw allow 27017
```

### **Step 6: Secure MongoDB (Optional)**
By default, MongoDB does not require authentication. For production environments, it's recommended to enable authentication for added security.

1. **Edit MongoDB configuration file**:

   ```bash
   sudo nano /etc/mongod.conf
   ```

2. In the `security` section, uncomment and set `authorization` to `enabled`:

   ```yaml
   security:
     authorization: "enabled"
   ```

3. **Restart MongoDB**:

   ```bash
   sudo systemctl restart mongod
   ```

Now, MongoDB will require authentication before allowing access to the database.

---

### **Step 7: Create an Admin User (Optional)**
To create an admin user after enabling authentication, follow these steps:

1. **Access the Mongo shell** (without authentication initially):

   ```bash
   mongosh
   ```

2. **Switch to the `admin` database**:

   ```bash
   use admin
   ```

3. **Create an admin user**:

   ```javascript
   db.createUser({
     user: "admin",
     pwd: "your_password",
     roles: [{ role: "root", db: "admin" }]
   })
   ```

4. **Exit Mongo shell**:

   ```bash
   exit
   ```

Now, when you connect to MongoDB, you must authenticate using the admin credentials you just created.

---

### **Conclusion**
You have successfully installed and started MongoDB on Ubuntu. You can now use MongoDB for storing and managing data. If you enabled authentication, make sure to authenticate before accessing the database.
