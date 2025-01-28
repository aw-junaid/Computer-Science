CRUD operations (Create, Read, Update, Delete) are the fundamental operations for interacting with a MongoDB database. Below is a guide to performing these operations using MongoDB's query language.

---

### **1. Create (Insert) Documents**
To add new documents to a collection, use the `insertOne()` or `insertMany()` methods.

#### Insert a Single Document
```javascript
db.collectionName.insertOne({
  name: "John Doe",
  age: 30,
  email: "john.doe@example.com"
});
```

#### Insert Multiple Documents
```javascript
db.collectionName.insertMany([
  { name: "Alice", age: 25, email: "alice@example.com" },
  { name: "Bob", age: 28, email: "bob@example.com" }
]);
```

---

### **2. Read (Query) Documents**
To retrieve documents from a collection, use the `find()` method.

#### Find All Documents
```javascript
db.collectionName.find();
```

#### Find Documents with a Filter
```javascript
db.collectionName.find({ age: { $gt: 25 } }); // Find documents where age is greater than 25
```

#### Find a Single Document
```javascript
db.collectionName.findOne({ name: "John Doe" });
```

#### Projection (Select Specific Fields)
```javascript
db.collectionName.find({}, { name: 1, email: 1 }); // Only return the `name` and `email` fields
```

---

### **3. Update Documents**
To modify existing documents, use the `updateOne()` or `updateMany()` methods.

#### Update a Single Document
```javascript
db.collectionName.updateOne(
  { name: "John Doe" }, // Filter
  { $set: { age: 31 } } // Update operation
);
```

#### Update Multiple Documents
```javascript
db.collectionName.updateMany(
  { age: { $lt: 30 } }, // Filter
  { $set: { status: "young" } } // Update operation
);
```

#### Increment a Field
```javascript
db.collectionName.updateOne(
  { name: "John Doe" },
  { $inc: { age: 1 } } // Increment age by 1
);
```

---

### **4. Delete Documents**
To remove documents from a collection, use the `deleteOne()` or `deleteMany()` methods.

#### Delete a Single Document
```javascript
db.collectionName.deleteOne({ name: "John Doe" });
```

#### Delete Multiple Documents
```javascript
db.collectionName.deleteMany({ age: { $lt: 30 } });
```

---

### **5. Additional Operations**
#### Count Documents
```javascript
db.collectionName.countDocuments({ age: { $gt: 25 } });
```

#### Sort Documents
```javascript
db.collectionName.find().sort({ age: 1 }); // 1 for ascending, -1 for descending
```

#### Limit Results
```javascript
db.collectionName.find().limit(5); // Return only 5 documents
```

#### Skip Documents
```javascript
db.collectionName.find().skip(10); // Skip the first 10 documents
```

---

### **Example Workflow**
```javascript
// Insert documents
db.users.insertMany([
  { name: "Alice", age: 25, email: "alice@example.com" },
  { name: "Bob", age: 28, email: "bob@example.com" },
  { name: "Charlie", age: 30, email: "charlie@example.com" }
]);

// Query documents
db.users.find({ age: { $gt: 25 } });

// Update a document
db.users.updateOne({ name: "Alice" }, { $set: { age: 26 } });

// Delete a document
db.users.deleteOne({ name: "Charlie" });
```

---

### **Best Practices**
1. **Indexing**: Create indexes on frequently queried fields to improve performance.
2. **Atomicity**: Use atomic operators like `$set`, `$inc`, etc., to ensure data consistency.
3. **Validation**: Use schema validation to enforce data structure and integrity.
4. **Bulk Operations**: Use `bulkWrite()` for efficient batch operations.

---
