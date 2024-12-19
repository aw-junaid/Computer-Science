Deleting a database in **CouchDB** is performed using the HTTP `DELETE` method. CouchDB treats a database as a resource that can be accessed and removed via its RESTful API.

You can delete a database using:

1. **cURL (Command-Line Interface)**  
2. **Fauxton (Web Interface)**  

---

## **1. Deleting a Database Using cURL**

To delete a database, you send a `DELETE` request to the database's endpoint.

---

### **Syntax**  
```bash
curl -X DELETE http://127.0.0.1:5984/{database_name}
```

- Replace `{database_name}` with the name of the database you want to delete.  

---

### **Example**  
To delete a database named `my_database`:
```bash
curl -X DELETE http://127.0.0.1:5984/my_database
```

---

### **Response**  
- **Success**: If the database is deleted successfully:
```json
{"ok":true}
```

- **Error**: If the database does not exist:
```json
{"error":"not_found","reason":"Database does not exist."}
```

- **Error**: If there are permission issues (in case of user authentication):
```json
{"error":"unauthorized","reason":"You are not authorized to access this resource."}
```

---

### **Verify Deletion**  
After deleting the database, you can confirm that it no longer exists by listing all databases:

```bash
curl -X GET http://127.0.0.1:5984/_all_dbs
```

**Response** (database no longer listed):
```json
["_replicator", "_users"]
```

---

## **2. Deleting a Database Using Fauxton**

Fauxton is the web-based user interface for CouchDB. To delete a database:

1. Open Fauxton in your browser:  
   Go to `http://127.0.0.1:5984/_utils`.

2. Navigate to the **Databases** tab.  
   - This lists all existing databases.

3. Locate the database you want to delete (e.g., `my_database`).

4. Click on the **trash bin icon** next to the database name.

5. Confirm the deletion when prompted.

Once deleted, the database will disappear from the list.

---

## **3. Key Notes**

- **Deleting a database** removes all its documents and metadata permanently. This operation **cannot be undone**, so use it cautiously.  
- If the database does not exist, CouchDB will return a `404 Not Found` error.  
- You cannot delete system databases like `_users` or `_replicator` unless you have sufficient permissions.

---

## **Summary**

You can delete a database in CouchDB using:  

1. **cURL**:
   ```bash
   curl -X DELETE http://127.0.0.1:5984/my_database
   ```

2. **Fauxton**: Use the web interface to delete the database visually.

After deletion, verify its removal by listing all databases with `_all_dbs`. Be careful, as this operation is irreversible.
