Creating a document in **CouchDB** involves using an HTTP **POST** or **PUT** request to insert JSON data into a database. Each document in CouchDB is a JSON object stored with a unique identifier (`_id`) and revision (`_rev`).

---

## **1. Creating a Document Using HTTP POST**

When you use a `POST` request, CouchDB automatically generates a unique document ID (`_id`) for you.

### **Syntax**  
```bash
curl -X POST http://127.0.0.1:5984/{database_name} \
-H "Content-Type: application/json" \
-d '{ "key": "value", "key2": "value2" }'
```

- Replace `{database_name}` with the name of your database.
- Add your JSON data in the `-d` option.

---

### **Example**  
Create a document in a database named `my_database`:
```bash
curl -X POST http://127.0.0.1:5984/my_database \
-H "Content-Type: application/json" \
-d '{ "name": "Alice", "age": 25, "city": "New York" }'
```

---

### **Response**  
If the document is created successfully:
```json
{
  "ok": true,
  "id": "6e1748cd1b1d53f4e8b6a2d9d5a00172",
  "rev": "1-967a00dff5e02add41819138abb3284d"
}
```

- **`id`**: Unique identifier for the document.  
- **`rev`**: Document revision number (used for updates).  

---

## **2. Creating a Document Using HTTP PUT**

Using a `PUT` request allows you to specify the document's unique identifier (`_id`).

### **Syntax**  
```bash
curl -X PUT http://127.0.0.1:5984/{database_name}/{document_id} \
-H "Content-Type: application/json" \
-d '{ "key": "value", "key2": "value2" }'
```

- Replace `{database_name}` with your database name.
- Replace `{document_id}` with your desired document ID.

---

### **Example**  
Create a document with a specific ID (`doc123`) in `my_database`:
```bash
curl -X PUT http://127.0.0.1:5984/my_database/doc123 \
-H "Content-Type: application/json" \
-d '{ "name": "Bob", "age": 30, "city": "San Francisco" }'
```

---

### **Response**  
If the document is created successfully:
```json
{
  "ok": true,
  "id": "doc123",
  "rev": "1-967a00dff5e02add41819138abb3284d"
}
```

---

## **3. Viewing the Created Document**

Once a document is created, you can retrieve it using a `GET` request.

### **Syntax**  
```bash
curl -X GET http://127.0.0.1:5984/{database_name}/{document_id}
```

---

### **Example**  
Retrieve the document with ID `doc123`:
```bash
curl -X GET http://127.0.0.1:5984/my_database/doc123
```

---

### **Response**  
```json
{
  "_id": "doc123",
  "_rev": "1-967a00dff5e02add41819138abb3284d",
  "name": "Bob",
  "age": 30,
  "city": "San Francisco"
}
```

---

## **4. Key Points to Remember**

- **`_id`**: Each document must have a unique ID. If omitted in `POST`, CouchDB generates one automatically.
- **`_rev`**: Revision numbers are used to track updates and prevent conflicts during updates.
- Use `POST` when you don’t care about the document ID.  
- Use `PUT` when you want to specify the document ID.  

---

## **Summary**

You can create a document in CouchDB in two ways:

1. **POST** (CouchDB generates the document ID):
   ```bash
   curl -X POST http://127.0.0.1:5984/my_database \
   -H "Content-Type: application/json" \
   -d '{ "name": "Alice", "age": 25 }'
   ```

2. **PUT** (You specify the document ID):
   ```bash
   curl -X PUT http://127.0.0.1:5984/my_database/doc123 \
   -H "Content-Type: application/json" \
   -d '{ "name": "Bob", "age": 30 }'
   ```

Use `GET` to verify that the document was successfully created.
