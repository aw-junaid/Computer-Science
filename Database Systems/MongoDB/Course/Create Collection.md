### **MongoDB - Create Collection**

In MongoDB, you don't need to explicitly create collections in advance like you do with tables in relational databases. Collections are created automatically when you insert the first document into them. However, you can also create a collection explicitly using the `createCollection()` method if you want to define specific options or configure settings (e.g., validation, indexing).

Here's a guide to creating collections in MongoDB:

---

### **Step 1: Connect to MongoDB**

Open your terminal and start the Mongo shell by typing:

```bash
mongosh
```

This will connect you to the default `test` database. You can switch to the desired database where you want to create a collection.

### **Step 2: Switch to the Database**

To use a specific database, use the `use` command. For example, to switch to a database called `myNewDatabase`, type:

```javascript
use myNewDatabase
```

If `myNewDatabase` does not already exist, MongoDB will create it when you insert data.

### **Step 3: Create a Collection**

You can create a collection using the `db.createCollection()` method. For example, to create a collection called `users`, you would run:

```javascript
db.createCollection("users")
```

This will create a new, empty collection named `users` within the current database. If the collection already exists, MongoDB will not create it again.

#### **Optional Parameters:**

The `createCollection()` method accepts several optional parameters to define collection behavior, such as setting validation rules, creating capped collections, etc.

For example, to create a capped collection (a fixed-size collection), you can use the following command:

```javascript
db.createCollection("logs", { capped: true, size: 100000 })
```

This command creates a `logs` collection that is capped, meaning it has a fixed size (100,000 bytes in this case), and older entries will be automatically overwritten when the collection reaches its size limit.

### **Step 4: Verify the Collection**

To verify that the collection has been created, list all collections in the current database using the `show collections` command:

```javascript
show collections
```

This will display all the collections in the current database, and you should see `users` (or whichever collection you created) in the list.

---

### **Inserting Data into the Collection**

Once a collection is created (either explicitly or implicitly), you can start inserting data into it. For example:

```javascript
db.users.insertOne({ name: "John Doe", age: 30, email: "johndoe@example.com" })
```

If you created a collection explicitly, you would still need to insert a document into it for MongoDB to "activate" the collection and start storing data.

---

### **Step 5: Drop a Collection (Optional)**

If you no longer need a collection, you can drop it using the `drop()` method. Be careful, as this will permanently delete the collection and all of its documents.

```javascript
db.users.drop()
```

This will delete the `users` collection from the database.

---

### **Advanced Options for Collection Creation**

#### **1. Capped Collection**
A **capped collection** is a special type of collection in MongoDB that automatically overwrites the oldest documents when it reaches its maximum size.

To create a capped collection:

```javascript
db.createCollection("logData", { capped: true, size: 1000000, max: 5000 })
```

Here:
- `capped: true`: Defines the collection as capped.
- `size: 1000000`: Defines the maximum size of the collection in bytes.
- `max: 5000`: Defines the maximum number of documents allowed in the collection.

#### **2. Collection with Validation**
You can also define validation rules to ensure that only documents with the required structure are inserted.

For example, creating a `users` collection with a validation rule that ensures all documents contain the `name` and `email` fields:

```javascript
db.createCollection("users", {
  validator: { $jsonSchema: {
      bsonType: "object",
      required: ["name", "email"],
      properties: {
        name: { bsonType: "string" },
        email: { bsonType: "string" }
      }
    }
  }
})
```

This collection will now only accept documents that contain the `name` and `email` fields, both as strings.

---

### **Conclusion**

In MongoDB, collections are created automatically when you insert data into them. However, if you want to create a collection explicitly with specific options (e.g., capped collections or validation rules), you can use the `db.createCollection()` method. Once the collection is created, you can start inserting documents into it.
