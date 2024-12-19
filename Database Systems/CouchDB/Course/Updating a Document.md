Updating a document in **CouchDB** involves making an HTTP **PUT** request. CouchDB uses a **revision-based system** to ensure data consistency and avoid conflicts. When you update a document, you need to include its **current revision ID (`_rev`)**, which acts as a version control mechanism.

---

## **Steps to Update a Document**

1. Retrieve the document (to get the latest `_rev` value).  
2. Modify the document as needed.  
3. Send an HTTP `PUT` request with the updated content, including the `_id` and `_rev`.

---

## **1. Retrieve the Existing Document**

Before updating, fetch the document to get its current `_rev` (revision ID).

### **Syntax**  
```bash
curl -X GET http://127.0.0.1:5984/{database_name}/{document_id}
```

---

### **Example**  
Retrieve a document with ID `doc123` from `my_database`:
```bash
curl -X GET http://127.0.0.1:5984/my_database/doc123
```

**Response**:
```json
{
  "_id": "doc123",
  "_rev": "1-abc123",
  "name": "Alice",
  "age": 25,
  "city": "New York"
}
```

---

## **2. Update the Document**

To update a document, you must include its `_id`, the current `_rev`, and the updated fields in the JSON payload.

### **Syntax**  
```bash
curl -X PUT http://127.0.0.1:5984/{database_name}/{document_id} \
-H "Content-Type: application/json" \
-d '{ "_id": "document_id", "_rev": "current_revision", "key": "new_value", ... }'
```

---

### **Example**  
Update the document with ID `doc123` to change the `age` and `city`:
```bash
curl -X PUT http://127.0.0.1:5984/my_database/doc123 \
-H "Content-Type: application/json" \
-d '{
      "_id": "doc123",
      "_rev": "1-abc123",
      "name": "Alice",
      "age": 26,
      "city": "Los Angeles"
    }'
```

---

### **Response**  
If the update is successful:
```json
{
  "ok": true,
  "id": "doc123",
  "rev": "2-def456"
}
```

- **`ok`**: Indicates success.  
- **`id`**: The document's ID.  
- **`rev`**: The new revision number (incremented after the update).  

---

## **3. Verify the Update**

After updating the document, you can verify the changes by retrieving the document again.

### **Example**  
```bash
curl -X GET http://127.0.0.1:5984/my_database/doc123
```

**Response**:
```json
{
  "_id": "doc123",
  "_rev": "2-def456",
  "name": "Alice",
  "age": 26,
  "city": "Los Angeles"
}
```

---

## **4. Handling Update Conflicts**

CouchDB requires the correct `_rev` to update a document. If you use an outdated `_rev`, CouchDB will reject the update to prevent conflicts.

### **Conflict Response**:
```json
{
  "error": "conflict",
  "reason": "Document update conflict."
}
```

---

### **Resolving Conflicts**
To resolve the conflict:
1. Retrieve the latest document (and `_rev`) using a `GET` request.  
2. Retry the update with the correct `_rev`.

---

## **5. Partial Updates**

CouchDB does not support partial updates by default. To modify specific fields:
1. Fetch the current document.
2. Update only the required fields locally.
3. Send the complete updated document back with a `PUT` request.

---

## **Summary**

To update a document in CouchDB:
1. Retrieve the document to get the current `_rev`.
   ```bash
   curl -X GET http://127.0.0.1:5984/my_database/doc123
   ```
2. Send the updated document with a `PUT` request, including `_id` and `_rev`:
   ```bash
   curl -X PUT http://127.0.0.1:5984/my_database/doc123 \
   -H "Content-Type: application/json" \
   -d '{
         "_id": "doc123",
         "_rev": "1-abc123",
         "name": "Alice",
         "age": 26,
         "city": "Los Angeles"
       }'
   ```
3. Verify the update with a `GET` request.

**Key Points**:
- Always include the correct `_rev` when updating a document.  
- If a conflict occurs, retrieve the latest `_rev` and retry the update.
