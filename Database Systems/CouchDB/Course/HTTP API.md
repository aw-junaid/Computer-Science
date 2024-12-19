CouchDB provides a **RESTful HTTP API** that allows you to interact with the database using standard HTTP methods such as **GET**, **PUT**, **POST**, and **DELETE**. Each resource (databases, documents, views, etc.) in CouchDB is represented as a URL, and operations are performed via HTTP requests.

---

## **CouchDB HTTP Methods**

| HTTP Method | Description                     |
|-------------|---------------------------------|
| **GET**     | Retrieve a resource             |
| **PUT**     | Create or update a resource     |
| **POST**    | Create or modify a resource     |
| **DELETE**  | Delete a resource               |

---

## **CouchDB API Endpoints**

Here are the key API endpoints and operations for working with CouchDB:

---

### **1. Server Information**

- **Endpoint**: `/`  
- **Method**: `GET`  
- **Purpose**: Retrieve server information.  
- **Example**:
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

### **2. Databases**

#### **List All Databases**
- **Endpoint**: `/_all_dbs`  
- **Method**: `GET`  
- **Example**:
   ```bash
   curl -X GET http://127.0.0.1:5984/_all_dbs
   ```
   **Response**:
   ```json
   ["_replicator", "_users", "my_database"]
   ```

#### **Create a Database**
- **Endpoint**: `/{db}`  
- **Method**: `PUT`  
- **Example**:
   ```bash
   curl -X PUT http://127.0.0.1:5984/my_database
   ```
   **Response**:
   ```json
   {"ok":true}
   ```

#### **Delete a Database**
- **Endpoint**: `/{db}`  
- **Method**: `DELETE`  
- **Example**:
   ```bash
   curl -X DELETE http://127.0.0.1:5984/my_database
   ```
   **Response**:
   ```json
   {"ok":true}
   ```

#### **Get Database Information**
- **Endpoint**: `/{db}`  
- **Method**: `GET`  
- **Example**:
   ```bash
   curl -X GET http://127.0.0.1:5984/my_database
   ```
   **Response**:
   ```json
   {
     "db_name": "my_database",
     "doc_count": 3,
     "doc_del_count": 0,
     "update_seq": 4
   }
   ```

---

### **3. Documents**

#### **Create a New Document**
- **Endpoint**: `/{db}`  
- **Method**: `POST`  
- **Example**:
   ```bash
   curl -X POST http://127.0.0.1:5984/my_database \
   -H "Content-Type: application/json" \
   -d '{"name": "John", "age": 30}'
   ```
   **Response**:
   ```json
   {"ok":true,"id":"123456789","rev":"1-abc"}
   ```

#### **Retrieve a Document**
- **Endpoint**: `/{db}/{doc_id}`  
- **Method**: `GET`  
- **Example**:
   ```bash
   curl -X GET http://127.0.0.1:5984/my_database/123456789
   ```
   **Response**:
   ```json
   {
     "_id": "123456789",
     "_rev": "1-abc",
     "name": "John",
     "age": 30
   }
   ```

#### **Update a Document**
- **Endpoint**: `/{db}/{doc_id}`  
- **Method**: `PUT`  
- **Example**:
   ```bash
   curl -X PUT http://127.0.0.1:5984/my_database/123456789 \
   -H "Content-Type: application/json" \
   -d '{"_id": "123456789", "_rev": "1-abc", "name": "John", "age": 35}'
   ```
   **Response**:
   ```json
   {"ok":true,"id":"123456789","rev":"2-def"}
   ```

#### **Delete a Document**
- **Endpoint**: `/{db}/{doc_id}?rev={rev}`  
- **Method**: `DELETE`  
- **Example**:
   ```bash
   curl -X DELETE http://127.0.0.1:5984/my_database/123456789?rev=2-def
   ```
   **Response**:
   ```json
   {"ok":true,"id":"123456789","rev":"3-ghi"}
   ```

---

### **4. Bulk Operations**

#### **Bulk Insert or Update Documents**
- **Endpoint**: `/{db}/_bulk_docs`  
- **Method**: `POST`  
- **Example**:
   ```bash
   curl -X POST http://127.0.0.1:5984/my_database/_bulk_docs \
   -H "Content-Type: application/json" \
   -d '{
         "docs": [
           {"name": "Alice", "age": 25},
           {"name": "Bob", "age": 28}
         ]
       }'
   ```
   **Response**:
   ```json
   [
     {"ok":true,"id":"123","rev":"1-abc"},
     {"ok":true,"id":"124","rev":"1-def"}
   ]
   ```

---

### **5. Views and Queries**

#### **Create a Design Document with a View**
- **Endpoint**: `/{db}/_design/{design_doc}`  
- **Method**: `PUT`  
- **Example**:
   ```bash
   curl -X PUT http://127.0.0.1:5984/my_database/_design/example \
   -H "Content-Type: application/json" \
   -d '{
         "views": {
           "by_age": {
             "map": "function(doc) { if (doc.age) emit(doc.age, doc.name); }"
           }
         }
       }'
   ```

#### **Query a View**
- **Endpoint**: `/{db}/_design/{design_doc}/_view/{view_name}`  
- **Method**: `GET`  
- **Example**:
   ```bash
   curl -X GET http://127.0.0.1:5984/my_database/_design/example/_view/by_age
   ```
   **Response**:
   ```json
   {
     "rows": [
       {"id": "123", "key": 25, "value": "Alice"},
       {"id": "124", "key": 28, "value": "Bob"}
     ]
   }
   ```

---

## **6. Replication**

#### **Replicate Databases**
- **Endpoint**: `/_replicate`  
- **Method**: `POST`  
- **Example**:
   ```bash
   curl -X POST http://127.0.0.1:5984/_replicate \
   -H "Content-Type: application/json" \
   -d '{
         "source": "my_database",
         "target": "backup_database"
       }'
   ```
   **Response**:
   ```json
   {"ok":true,"history":[]}
   ```

---

### **Key Points**

- CouchDB's **HTTP API** allows interaction using standard HTTP methods.
- Use `GET`, `POST`, `PUT`, and `DELETE` for CRUD operations.
- CouchDB uses JSON for both requests and responses.
- Fauxton, the web interface, works as a frontend to this HTTP API.

By leveraging the CouchDB HTTP API, developers can easily integrate it into applications, automate database management, and perform advanced operations like replication and querying.
