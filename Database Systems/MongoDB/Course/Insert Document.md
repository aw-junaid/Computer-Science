### **MongoDB - Insert Document**

In MongoDB, a **document** is a record or entry in a collection. To add or insert documents into a MongoDB collection, you use the `insertOne()` or `insertMany()` methods. These methods allow you to insert one or more documents, respectively.

---

### **Step 1: Connect to MongoDB**

Open your terminal and start the Mongo shell by typing:

```bash
mongosh
```

This will connect you to the default database (`test`). You can switch to the desired database using the `use` command.

### **Step 2: Switch to the Desired Database**

To insert a document into a specific database, switch to it using the `use` command. For example, to use the database `myDatabase`, type:

```javascript
use myDatabase
```

If the database doesn’t exist, MongoDB will create it when you insert data.

---

### **Step 3: Insert a Single Document (`insertOne`)**

To insert a single document into a collection, use the `insertOne()` method. The document is passed as a JavaScript object inside the `insertOne()` method.

#### **Syntax:**

```javascript
db.collectionName.insertOne({ field1: value1, field2: value2, ... })
```

#### **Example:**

```javascript
db.users.insertOne({
  name: "John Doe",
  age: 30,
  email: "johndoe@example.com"
})
```

This inserts a document with three fields (`name`, `age`, and `email`) into the `users` collection. If the `users` collection does not already exist, MongoDB will automatically create it.

#### **Response:**

After inserting a document, MongoDB returns an acknowledgment that includes the inserted document's `_id`:

```json
{
  "acknowledged": true,
  "insertedId": ObjectId("507f191e810c19729de860ea")
}
```

The `_id` field is automatically added by MongoDB if it is not specified. It is a unique identifier for each document in a collection.

---

### **Step 4: Insert Multiple Documents (`insertMany`)**

If you need to insert multiple documents at once, use the `insertMany()` method. This method takes an array of documents to be inserted.

#### **Syntax:**

```javascript
db.collectionName.insertMany([{ field1: value1, field2: value2, ... }, { field1: value1, field2: value2, ... }, ...])
```

#### **Example:**

```javascript
db.users.insertMany([
  { name: "Alice", age: 25, email: "alice@example.com" },
  { name: "Bob", age: 28, email: "bob@example.com" },
  { name: "Charlie", age: 35, email: "charlie@example.com" }
])
```

This inserts three documents into the `users` collection. If the collection does not exist, it will be created.

#### **Response:**

MongoDB returns an acknowledgment with the `insertedIds` array, which contains the `_id` values of the newly inserted documents:

```json
{
  "acknowledged": true,
  "insertedIds": [
    ObjectId("507f191e810c19729de860ea"),
    ObjectId("507f191e810c19729de860eb"),
    ObjectId("507f191e810c19729de860ec")
  ]
}
```

---

### **Step 5: Verify the Inserted Documents**

To verify that the documents have been inserted, use the `find()` method to retrieve documents from the collection. For example:

```javascript
db.users.find()
```

This will return all the documents in the `users` collection. If you want to view the documents in a more readable format, you can use `pretty()`:

```javascript
db.users.find().pretty()
```

---

### **Step 6: Insert Document with Specified `_id` (Optional)**

You can also manually specify the `_id` field when inserting a document. However, this is optional, as MongoDB will automatically generate a unique `_id` if you don’t provide one.

#### **Example:**

```javascript
db.users.insertOne({
  _id: 1, 
  name: "David", 
  age: 40, 
  email: "david@example.com"
})
```

In this case, the `_id` field is explicitly set to `1`. If you attempt to insert another document with the same `_id` value, MongoDB will return an error because the `_id` must be unique within a collection.

---

### **Step 7: Insert Document with Arrays and Embedded Documents**

MongoDB allows you to store arrays and embedded documents in a single document.

#### **Example: Inserting a Document with an Array**

```javascript
db.products.insertOne({
  name: "Laptop",
  price: 999.99,
  features: ["16GB RAM", "512GB SSD", "Intel i7"]
})
```

#### **Example: Inserting a Document with an Embedded Document**

```javascript
db.users.insertOne({
  name: "Emma",
  address: {
    street: "123 Main St",
    city: "Springfield",
    state: "IL"
  }
})
```

In this case, the `address` is an embedded document with its own fields (`street`, `city`, `state`).

---

### **Step 8: Handling Errors**

If you try to insert invalid data, such as duplicate `_id` values or invalid BSON types, MongoDB will return an error. Here's an example of an error caused by a duplicate `_id`:

```javascript
db.users.insertOne({ _id: 1, name: "John", age: 30 })
```

If another document with `_id: 1` already exists, MongoDB will throw an error:

```json
{
  "code": 11000,
  "errmsg": "E11000 duplicate key error collection: myDatabase.users index: _id_ dup key: { : 1 }",
  "op": { "_id": 1, "name": "John", "age": 30 }
}
```

---

### **Conclusion**

Inserting documents into MongoDB is simple using the `insertOne()` and `insertMany()` methods. MongoDB automatically adds the `_id` field if it is not specified, and it supports a variety of data types, including arrays and embedded documents. Always ensure that documents are inserted with valid data, and handle potential errors like duplicate `_id` values gracefully.
