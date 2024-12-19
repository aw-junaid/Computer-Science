Creating a database in **CouchDB** is straightforward as it exposes a **RESTful HTTP API** to perform this task. You can create a database using:

1. **cURL (Command-Line Interface)**  
2. **Fauxton (Web Interface)**  

---

## **1. Creating a Database Using cURL**

CouchDB treats databases as resources accessible via HTTP requests. You can use a `PUT` request to create a database.

---

### **Basic Syntax**  
```bash
curl -X PUT http://127.0.0.1:5984/{database_name}
```

- Replace `{database_name}` with the desired name of your database.  

---

### **Example**  
Create a database called `my_database`:
```bash
curl -X PUT http://127.0.0.1:5984/my_database
```

**Response**:  
If the database is created successfully:
```json
{"ok":true}
```

---

### **Error Handling**  
- If the database already exists, CouchDB returns an error:
```json
{"error":"file_exists","reason":"The database could not be created, the file already exists."}
```

- If the database name contains invalid characters:
```json
{"error":"illegal_database_name","reason":"Name: 'invalid_db_name'. Only lowercase characters (a-z), digits (0-9), and the characters '_', '$', '(', ')', '+', '-', and '/' are allowed."}
```

---

### **Database Naming Rules**  
CouchDB enforces the following rules for database names:  
- Must be **lowercase**.  
- Allowed characters:  
   - **a-z** (lowercase letters)  
   - **0-9** (digits)  
   - Special characters: `_`, `$`, `(`, `)`, `+`, `-`, and `/`  
- The name cannot start with an underscore (`_`) unless it is a **system database**.

---

## **2. Creating a Database Using Fauxton**

Fauxton is the **web-based user interface** for CouchDB. Here's how you can create a database using Fauxton:

1. Open Fauxton in your browser:  
   Go to `http://127.0.0.1:5984/_utils`.

2. Navigate to the **Databases** tab.  
   - This shows the list of existing databases.

3. Click on the **"Create Database"** button.  

4. Enter a name for your database (e.g., `my_database`).  

5. Click **"Create"**.

Your new database will appear in the list.

---

## **3. Verify the Database**

Once created, you can verify the existence of the database using:

### **List All Databases**  
Use the `_all_dbs` endpoint to list all databases:
```bash
curl -X GET http://127.0.0.1:5984/_all_dbs
```
**Response**:
```json
["_replicator", "_users", "my_database"]
```

### **Check Database Information**  
To get detailed information about a specific database:
```bash
curl -X GET http://127.0.0.1:5984/my_database
```
**Response**:
```json
{
  "db_name": "my_database",
  "doc_count": 0,
  "doc_del_count": 0,
  "update_seq": 0,
  "sizes": {
    "file": 0,
    "external": 0,
    "active": 0
  },
  "purge_seq": 0,
  "other": {
    "data_size": 0
  }
}
```

---

## **Summary**

You can create a database in CouchDB in two ways:
1. Using **cURL** with a `PUT` request:  
   ```bash
   curl -X PUT http://127.0.0.1:5984/my_database
   ```
2. Using **Fauxton** (web interface) by navigating to the "Create Database" option.

Once created, you can verify your database using the `_all_dbs` or database-specific API endpoints.
