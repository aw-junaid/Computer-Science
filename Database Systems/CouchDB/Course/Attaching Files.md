In **CouchDB**, you can attach files (such as images, text files, PDFs, or any binary content) to documents. Attachments are stored as part of the document and can be accessed or managed using CouchDB's HTTP API.

---

## **1. Uploading an Attachment**

To attach a file to a document, you need to:
1. Have the document's `_id` and `_rev` (revision ID).  
2. Use the HTTP **PUT** method to upload the file as an attachment.

---

### **Syntax**  
```bash
curl -X PUT http://127.0.0.1:5984/{database_name}/{document_id}/{attachment_name}?rev={current_revision} \
--data-binary @{file_path} \
-H "Content-Type: {mime_type}"
```

- **`{database_name}`**: The name of your CouchDB database.  
- **`{document_id}`**: The ID of the document to attach the file to.  
- **`{attachment_name}`**: The desired name of the attachment (e.g., `file.txt`).  
- **`{current_revision}`**: The document's current `_rev`.  
- **`{file_path}`**: Path to the file on your system.  
- **`{mime_type}`**: The file's MIME type (e.g., `image/png`, `text/plain`, `application/pdf`).

---

### **Example**

#### **Step 1: Create a Document**
If the document does not exist, create it first:
```bash
curl -X PUT http://127.0.0.1:5984/my_database/doc123 \
-H "Content-Type: application/json" \
-d '{ "name": "Alice" }'
```

**Response**:
```json
{
  "ok": true,
  "id": "doc123",
  "rev": "1-abc123"
}
```

---

#### **Step 2: Attach a File**
Attach a file named `hello.txt`:
```bash
curl -X PUT http://127.0.0.1:5984/my_database/doc123/hello.txt?rev=1-abc123 \
--data-binary @/path/to/hello.txt \
-H "Content-Type: text/plain"
```

- Replace `/path/to/hello.txt` with the file's location.  
- Replace `1-abc123` with the document's revision ID.

---

#### **Response**
If the attachment is successfully uploaded:
```json
{
  "ok": true,
  "id": "doc123",
  "rev": "2-def456"
}
```

---

## **2. Viewing Attachments**

You can access the attachment directly using its URL.

### **Syntax**  
```bash
curl -X GET http://127.0.0.1:5984/{database_name}/{document_id}/{attachment_name}
```

---

### **Example**  
To download or view the `hello.txt` file:
```bash
curl -X GET http://127.0.0.1:5984/my_database/doc123/hello.txt
```

**Output**: The file content will be displayed or downloaded.

---

## **3. Listing Attachments**

Attachments are stored as part of the document. You can view them by retrieving the document.

### **Syntax**  
```bash
curl -X GET http://127.0.0.1:5984/{database_name}/{document_id}
```

---

### **Example**
Retrieve the document `doc123`:
```bash
curl -X GET http://127.0.0.1:5984/my_database/doc123
```

**Response**:
```json
{
  "_id": "doc123",
  "_rev": "2-def456",
  "name": "Alice",
  "_attachments": {
    "hello.txt": {
      "content_type": "text/plain",
      "length": 15
    }
  }
}
```

- **`_attachments`**: Contains metadata for the file (e.g., file size, MIME type).

---

## **4. Deleting an Attachment**

To delete an attachment, use the HTTP **DELETE** method.

### **Syntax**  
```bash
curl -X DELETE http://127.0.0.1:5984/{database_name}/{document_id}/{attachment_name}?rev={current_revision}
```

---

### **Example**  
Delete `hello.txt` from `doc123`:
```bash
curl -X DELETE http://127.0.0.1:5984/my_database/doc123/hello.txt?rev=2-def456
```

**Response**:
```json
{
  "ok": true,
  "id": "doc123",
  "rev": "3-ghi789"
}
```

---

## **5. Inline Attachments**

You can also include small attachments directly within a document in **Base64-encoded** format when creating or updating a document.

---

### **Example**  
Add an inline attachment:
```bash
curl -X PUT http://127.0.0.1:5984/my_database/doc_inline \
-H "Content-Type: application/json" \
-d '{
  "_attachments": {
    "hello.txt": {
      "content_type": "text/plain",
      "data": "aGVsbG8gd29ybGQ="
    }
  }
}'
```

- **`data`**: Base64-encoded content of the file (`hello world` encoded here).

---

## **Summary**

1. **Attach a file** using:
   ```bash
   curl -X PUT http://127.0.0.1:5984/my_database/doc123/hello.txt?rev=1-abc123 \
   --data-binary @/path/to/hello.txt \
   -H "Content-Type: text/plain"
   ```

2. **View the attachment**:
   ```bash
   curl -X GET http://127.0.0.1:5984/my_database/doc123/hello.txt
   ```

3. **Delete the attachment**:
   ```bash
   curl -X DELETE http://127.0.0.1:5984/my_database/doc123/hello.txt?rev=2-def456
   ```

4. **List attachments** by retrieving the document:
   ```bash
   curl -X GET http://127.0.0.1:5984/my_database/doc123
   ```

Attachments are an efficient way to store and manage files directly within CouchDB documents.
