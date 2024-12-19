Deleting a document in **CouchDB** is done using an HTTP **DELETE** request. To delete a document, you need its **unique ID (`_id`)** and the **current revision ID (`_rev`)**. CouchDB uses these to prevent accidental deletion or conflicts.

---

## **Steps to Delete a Document**

1. Retrieve the document to get its current `_rev` value.  
2. Send an HTTP `DELETE` request with the `_rev` parameter.

---

## **1. Retrieve the Document**

Before deleting, fetch the document to get its latest `_rev`.

### **Syntax**  
```bash
curl -X GET http://127.0.0.1:5984/{database_name}/{document_id}
```

---

### **Example**  
Retrieve a document with ID `doc123` in `my_database`:
```bash
curl -X GET http://127.0.0.1:5984/my_database/doc123
```

**Response**:
```json
{
  "_id": "doc123",
  "_rev": "2-abc123",
  "name": "Alice",
  "age": 26
}
```

---

## **2. Delete the Document**

Use the `DELETE` method with the `_rev` parameter to delete the document.

### **Syntax**  
```bash
curl -X DELETE http://127.0.0.1:5984/{database_name}/{document_id}?rev={current_revision}
```

- Replace `{database_name}` with your database name.  
- Replace `{document_id}` with the document's ID.  
- Replace `{current_revision}` with the document's `_rev`.  

---

### **Example**  
Delete the document `doc123` with `_rev` `2-abc123`:
```bash
curl -X DELETE http://127.0.0.1:5984/my_database/doc123?rev=2-abc123
```

---

### **Response**  
If the document is deleted successfully:
```json
{
  "ok": true,
  "id": "doc123",
  "rev": "3-def456"
}
```

- **`ok`**: Indicates success.  
- **`id`**: The document's ID.  
- **`rev`**: The new revision ID after the deletion.  

---

## **3. Verify Deletion**

After deleting the document, you can verify it by retrieving the document.

### **Example**  
```bash
curl -X GET http://127.0.0.1:5984/my_database/doc123
```

**Response**: If the document is deleted, CouchDB will return a `404` error:
```json
{
  "error": "not_found",
  "reason": "deleted"
}
```

---

## **4. Deleted Documents and Tombstones**

- Deleting a document does not immediately remove it from the database. Instead, CouchDB marks it as **"deleted"** and keeps a tombstone record to maintain history.
- Tombstone records are visible in replication and conflict resolution.

---

### **Example of Deleted Document**  
When retrieving all documents using `GET` on `_all_docs`, a deleted document appears with a `deleted: true` flag:
```json
{
  "id": "doc123",
  "key": "doc123",
  "value": { "rev": "3-def456", "deleted": true }
}
```

---

## **5. Bulk Deletion**

You can also delete multiple documents at once using the **bulk documents API** (`POST` to `_bulk_docs`).

---

### **Example**  
Send a request with `"_deleted": true` for the target documents:
```bash
curl -X POST http://127.0.0.1:5984/my_database/_bulk_docs \
-H "Content-Type: application/json" \
-d '{
  "docs": [
    { "_id": "doc123", "_rev": "3-def456", "_deleted": true },
    { "_id": "doc124", "_rev": "1-xyz789", "_deleted": true }
  ]
}'
```

**Response**:
```json
[
  { "id": "doc123", "rev": "4-ghi789" },
  { "id": "doc124", "rev": "2-jkl012" }
]
```

---

## **Summary**

To delete a document in CouchDB:

1. **Retrieve the document** to get its `_rev`:
   ```bash
   curl -X GET http://127.0.0.1:5984/my_database/doc123
   ```

2. **Delete the document** using a `DELETE` request:
   ```bash
   curl -X DELETE http://127.0.0.1:5984/my_database/doc123?rev=2-abc123
   ```

3. **Verify deletion**:
   ```bash
   curl -X GET http://127.0.0.1:5984/my_database/doc123
   ```

CouchDB will mark the document as deleted and maintain a tombstone record for future replication or conflict resolution.
