### **MongoDB - Delete Document**

In MongoDB, you can delete documents from a collection using the `deleteOne()` and `deleteMany()` methods. These methods allow you to remove one or more documents that match specific criteria.

### **Step 1: Connect to MongoDB**

Open your terminal and start the Mongo shell by typing:

```bash
mongosh
```

This will connect you to the default database (`test`). You can switch to your desired database using the `use` command:

```javascript
use myDatabase
```

### **Step 2: Basic Delete Syntax**

In MongoDB, the basic syntax for a delete operation is:

```javascript
db.collection.deleteOne(<filter>)
```

or

```javascript
db.collection.deleteMany(<filter>)
```

Where:
- **`filter`**: Specifies the criteria to match the document(s) that should be deleted.

---

### **Step 3: Delete a Single Document (`deleteOne`)**

The `deleteOne()` method deletes the first document that matches the specified filter.

#### **Syntax:**

```javascript
db.collection.deleteOne({ <filter> })
```

#### **Example: Delete a Single Document**

Suppose we want to delete the document of the user named `"John"`:

```javascript
db.users.deleteOne({ name: "John" })
```

This will delete the first document in the `users` collection where `name` is `"John"`.

#### **Response:**

MongoDB will return an object indicating how many documents were deleted:

```json
{
  "acknowledged": true,
  "deletedCount": 1
}
```

If no documents match the filter, `deletedCount` will be `0`.

---

### **Step 4: Delete Multiple Documents (`deleteMany`)**

The `deleteMany()` method deletes all documents that match the specified filter.

#### **Syntax:**

```javascript
db.collection.deleteMany({ <filter> })
```

#### **Example: Delete Multiple Documents**

Suppose we want to delete all users who are older than 30:

```javascript
db.users.deleteMany({ age: { $gt: 30 } })
```

This will delete all documents in the `users` collection where `age` is greater than 30.

#### **Response:**

The response will show how many documents were deleted:

```json
{
  "acknowledged": true,
  "deletedCount": 5
}
```

---

### **Step 5: Delete All Documents in a Collection**

If you want to delete all documents in a collection, you can use `deleteMany()` with an empty filter `{}`.

#### **Example: Delete All Documents**

```javascript
db.users.deleteMany({})
```

This will remove all documents from the `users` collection.

#### **Response:**

```json
{
  "acknowledged": true,
  "deletedCount": 100
}
```

---

### **Step 6: Delete Documents Based on Specific Criteria**

You can delete documents that match more complex criteria, just like in the `find()` or `update()` operations. For example, if you want to delete users who are both named `"John"` and older than 30:

```javascript
db.users.deleteMany({ name: "John", age: { $gt: 30 } })
```

This will delete all documents in the `users` collection where the `name` is `"John"` and `age` is greater than 30.

---

### **Step 7: Delete Documents with the `$in` Operator**

You can use the `$in` operator to match documents where a field value is in an array of values. For example, to delete users whose names are either `"John"` or `"Alice"`:

```javascript
db.users.deleteMany({ name: { $in: ["John", "Alice"] } })
```

This will delete all documents where the `name` field is either `"John"` or `"Alice"`.

---

### **Step 8: Verify the Deletion**

You can verify that the documents were deleted by running a `find()` query:

```javascript
db.users.find({ name: "John" }).pretty()
```

If the document was successfully deleted, the query will return no results.

---

### **Step 9: Use `drop()` to Delete an Entire Collection**

If you want to delete the entire collection (including all its documents and indexes), you can use the `drop()` method.

#### **Syntax:**

```javascript
db.collection.drop()
```

#### **Example: Drop the `users` Collection**

```javascript
db.users.drop()
```

This will completely remove the `users` collection from the database.

#### **Response:**

```json
{
  "ok": 1
}
```

---

### **Step 10: Delete Documents with `limit()` and `sort()`**

You can combine `limit()` and `sort()` with `deleteMany()` or `deleteOne()` to delete a limited number of documents that match specific criteria.

#### **Example: Delete the Oldest 5 Users**

```javascript
db.users.deleteMany(
  { age: { $gt: 20 } },
  { limit: 5, sort: { age: -1 } }
)
```

This deletes the 5 oldest users (age greater than 20) from the collection.

---

### **Conclusion**

MongoDB provides simple and efficient methods for deleting documents from a collection. The `deleteOne()` and `deleteMany()` methods allow you to delete one or many documents that match specific criteria, while the `drop()` method removes an entire collection. You can also use various operators to create complex delete queries, and the response object will indicate how many documents were deleted. Be cautious when using delete operations, as they are irreversible.
