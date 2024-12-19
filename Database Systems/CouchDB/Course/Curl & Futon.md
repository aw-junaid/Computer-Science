CouchDB provides two primary interfaces for interacting with the database:  

1. **cURL** (Command-Line HTTP Requests)  
2. **Futon/Fauxton** (Web-Based Interfaces)  

Here’s a breakdown of both:

---

## **1. Using cURL with CouchDB**

CouchDB exposes a RESTful HTTP API. This allows you to interact with the database using tools like **cURL**.

---

### **Basic Operations with cURL**

#### **1. Check CouchDB Status**  
To verify if CouchDB is running:  
```bash
curl -X GET http://127.0.0.1:5984/
```
**Response**:  
```json
{
  "couchdb": "Welcome",
  "version": "3.3.1",
  "vendor": {
    "name": "The Apache Software Foundation"
  }
}
```

---

#### **2. Create a Database**  
To create a new database:  
```bash
curl -X PUT http://127.0.0.1:5984/my_database
```
**Response**:  
```json
{"ok":true}
```

---

#### **3. List All Databases**  
To get a list of all databases:  
```bash
curl -X GET http://127.0.0.1:5984/_all_dbs
```
**Response**:  
```json
["_users", "_replicator", "my_database"]
```

---

#### **4. Add a Document**  
To insert a document into a database:  
```bash
curl -X POST http://127.0.0.1:5984/my_database \
-H "Content-Type: application/json" \
-d '{"name": "Alice", "age": 25, "city": "New York"}'
```
**Response**:  
```json
{"ok":true,"id":"document_id","rev":"1-xyz"}
```

---

#### **5. Retrieve a Document**  
To fetch a document by its ID:  
```bash
curl -X GET http://127.0.0.1:5984/my_database/document_id
```
**Response**:  
```json
{"_id":"document_id", "_rev":"1-xyz", "name":"Alice", "age":25, "city":"New York"}
```

---

#### **6. Update a Document**  
To update a document, provide the document's `_id` and `_rev`:  
```bash
curl -X PUT http://127.0.0.1:5984/my_database/document_id \
-H "Content-Type: application/json" \
-d '{"_id": "document_id", "_rev": "1-xyz", "name": "Alice", "age": 26, "city": "San Francisco"}'
```
**Response**:  
```json
{"ok":true,"id":"document_id","rev":"2-abc"}
```

---

#### **7. Delete a Document**  
To delete a document, include its ID and revision:  
```bash
curl -X DELETE http://127.0.0.1:5984/my_database/document_id?rev=2-abc
```
**Response**:  
```json
{"ok":true,"id":"document_id","rev":"3-def"}
```

---

#### **8. Delete a Database**  
To delete a database:  
```bash
curl -X DELETE http://127.0.0.1:5984/my_database
```
**Response**:  
```json
{"ok":true}
```

---

### **Summary of Common cURL Commands**

| Operation               | Command Example                                                                 |
|-------------------------|-------------------------------------------------------------------------------|
| Check CouchDB Status    | `curl -X GET http://127.0.0.1:5984/`                                          |
| Create a Database       | `curl -X PUT http://127.0.0.1:5984/my_database`                              |
| List All Databases      | `curl -X GET http://127.0.0.1:5984/_all_dbs`                                 |
| Add a Document          | `curl -X POST http://127.0.0.1:5984/my_database -d '{"key": "value"}'`        |
| Get a Document          | `curl -X GET http://127.0.0.1:5984/my_database/document_id`                  |
| Update a Document       | `curl -X PUT http://127.0.0.1:5984/my_database/document_id -d '{"key":"val"}` |
| Delete a Document       | `curl -X DELETE http://127.0.0.1:5984/my_database/document_id?rev=rev_id`    |

---

## **2. Futon & Fauxton**

Futon and Fauxton are web-based graphical interfaces for CouchDB.  

### **Futon** (Legacy Interface)  
- Futon was the original administrative interface for CouchDB.  
- It allowed basic database management operations such as:  
   - Creating databases  
   - Managing documents  
   - Running queries  
- Futon has been **deprecated** and replaced by **Fauxton** in recent CouchDB versions.

---

### **Fauxton** (Modern Interface)  
Fauxton is the **default web interface** for managing CouchDB.  

#### **Access Fauxton**:  
1. Open your browser.  
2. Go to `http://127.0.0.1:5984/_utils`.  

#### **Features of Fauxton**:  
- **Database Management**: Create, delete, and list databases.  
- **Document Management**: Add, retrieve, update, and delete JSON documents.  
- **Replication**: Set up and monitor database replication.  
- **Query Execution**: Write **MapReduce views** and run queries.  
- **Cluster Management**: Manage nodes in a clustered environment.  

#### **Using Fauxton**:  
1. Navigate to the homepage (`_utils`).  
2. Select the database you want to manage.  
3. Use the graphical interface to interact with documents or run queries.  

---

### **Summary**  
- **cURL** is ideal for **command-line** database management and scripting.  
- **Fauxton** is a user-friendly, modern web interface for managing CouchDB visually.  
- Futon has been replaced by Fauxton but may still be found in older CouchDB versions.  

Both tools are powerful and provide complete control over CouchDB for developers and administrators.
