To install **CouchDB**, you can set it up on various platforms like Linux, macOS, and Windows. Below are the steps for installation across different operating systems.

---

### **1. Installing CouchDB on Linux**

#### **For Ubuntu/Debian:**

1. **Update the system and install prerequisites**:
   ```bash
   sudo apt update
   sudo apt install -y curl gnupg
   ```

2. **Add the CouchDB GPG key and repository**:
   ```bash
   curl https://couchdb.apache.org/repo/keys.asc | gpg --dearmor | sudo tee /usr/share/keyrings/couchdb-archive-keyring.gpg >/dev/null
   echo "deb [signed-by=/usr/share/keyrings/couchdb-archive-keyring.gpg] https://apache.jfrog.io/artifactory/couchdb-deb/ $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/couchdb.list >/dev/null
   ```

3. **Install CouchDB**:
   ```bash
   sudo apt update
   sudo apt install -y couchdb
   ```

4. **Configure CouchDB**:
   - During installation, you will be prompted to configure CouchDB:
     - **Standalone** (Single Node)
     - **Clustered** (Multi-Node)
   - Choose your preferred option and provide required details (IP address, admin credentials).

5. **Verify Installation**:
   - Access CouchDB at: `http://127.0.0.1:5984/_utils`  
   - This opens the **Fauxton** web-based interface.

---

#### **For Red Hat/CentOS:**

1. **Add the CouchDB repository**:
   ```bash
   sudo tee /etc/yum.repos.d/bintray-apache-couchdb-rpm.repo <<EOF
   [bintray--apache-couchdb-rpm]
   name=bintray--apache-couchdb-rpm
   baseurl=https://apache.jfrog.io/artifactory/couchdb-rpm/el\$releasever/\$basearch/
   gpgcheck=1
   repo_gpgcheck=1
   gpgkey=https://couchdb.apache.org/repo/keys.asc
   enabled=1
   EOF
   ```

2. **Install CouchDB**:
   ```bash
   sudo yum install -y couchdb
   ```

3. **Start and Enable CouchDB**:
   ```bash
   sudo systemctl start couchdb
   sudo systemctl enable couchdb
   ```

4. **Verify Installation**:
   Access `http://127.0.0.1:5984/_utils`.

---

### **2. Installing CouchDB on macOS**

#### **Using Homebrew**:

1. **Install Homebrew** (if not already installed):
   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```

2. **Install CouchDB**:
   ```bash
   brew install couchdb
   ```

3. **Start CouchDB**:
   ```bash
   brew services start couchdb
   ```

4. **Verify Installation**:
   Open your browser and visit `http://127.0.0.1:5984/_utils`.

---

### **3. Installing CouchDB on Windows**

1. **Download the CouchDB Installer**:
   - Go to the official website: [https://couchdb.apache.org/](https://couchdb.apache.org/).
   - Download the Windows installer.

2. **Run the Installer**:
   - Follow the installation wizard.
   - Choose the installation directory and configure the CouchDB setup:
     - **Single Node** or **Clustered Mode**.

3. **Start CouchDB**:
   - Once installed, CouchDB will run as a service.
   - Open your browser and access CouchDB at `http://127.0.0.1:5984/_utils`.

4. **Verify Installation**:
   You should see the **Fauxton** web interface.

---

### **4. Verifying CouchDB Installation**

To ensure CouchDB is running correctly:

- **Check CouchDB Status**:  
   Open a browser and go to:  
   ```http://127.0.0.1:5984```
   You should see a response like:
   ```json
   {
     "couchdb": "Welcome",
     "version": "3.3.1",
     "vendor": {
       "name": "The Apache Software Foundation"
     }
   }
   ```

- **Access Fauxton UI**:  
   Open the CouchDB web-based interface at:  
   ```http://127.0.0.1:5984/_utils```

---

### **5. Installing CouchDB in Docker**

If you prefer using Docker:

1. **Pull the CouchDB Docker Image**:
   ```bash
   docker pull apache/couchdb:latest
   ```

2. **Run CouchDB**:
   ```bash
   docker run -d --name couchdb -p 5984:5984 -e COUCHDB_USER=admin -e COUCHDB_PASSWORD=password apache/couchdb
   ```

3. **Verify Installation**:  
   Access `http://127.0.0.1:5984/_utils`.

---

### **Summary**

After installation, CouchDB can be accessed via its **RESTful API** or the **Fauxton web interface**. Make sure to configure user credentials, especially for production environments, to secure the database.
