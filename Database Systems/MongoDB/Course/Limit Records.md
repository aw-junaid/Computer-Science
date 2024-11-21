### **MongoDB - Limit Records**

In MongoDB, you can limit the number of documents returned by a query using the `limit()` method. This is useful when you want to restrict the result set to a specific number of documents, especially when working with large datasets or implementing pagination.

### **Step 1: Connect to MongoDB**

First, connect to your MongoDB instance using the Mongo shell:

```bash
mongosh
```

Switch to your desired database:

```javascript
use myDatabase
```

### **Step 2: Basic Syntax for `limit()`**

The basic syntax for limiting the number of documents returned by a query is:

```javascript
db.collection.find({ <filter> }).limit(<number>)
```

- **`filter`**: Optional criteria to match documents.
- **`number`**: The maximum number of documents to return.

---

### **Step 3: Example - Limit the Number of Documents**

If you want to limit the number of documents returned, say to 5, from the `users` collection, you can do the following:

```javascript
db.users.find().limit(5)
```

This will return the first 5 documents from the `users` collection, based on the default sort order (which is by `_id`).

#### **Result:**

```json
{ "_id": ObjectId("..."), "name": "Alice", "email": "alice@example.com" }
{ "_id": ObjectId("..."), "name": "Bob", "email": "bob@example.com" }
{ "_id": ObjectId("..."), "name": "Charlie", "email": "charlie@example.com" }
{ "_id": ObjectId("..."), "name": "David", "email": "david@example.com" }
{ "_id": ObjectId("..."), "name": "Eve", "email": "eve@example.com" }
```

---

### **Step 4: Using `limit()` with Query Filters**

You can also use `limit()` with a query filter to limit the documents returned that match specific criteria. For example, if you want to limit the results to users who are older than 30 and return only 3 documents:

```javascript
db.users.find({ age: { $gt: 30 } }).limit(3)
```

This will return up to 3 users whose age is greater than 30.

#### **Result:**

```json
{ "_id": ObjectId("..."), "name": "Alice", "age": 35, "email": "alice@example.com" }
{ "_id": ObjectId("..."), "name": "John", "age": 32, "email": "john@example.com" }
{ "_id": ObjectId("..."), "name": "Sarah", "age": 40, "email": "sarah@example.com" }
```

---

### **Step 5: Using `limit()` with Projection**

You can combine `limit()` with projection to return only specific fields. For example, if you want to return only the `name` and `email` fields for the first 3 users who are older than 30:

```javascript
db.users.find({ age: { $gt: 30 } }, { name: 1, email: 1 }).limit(3)
```

This will return the first 3 users who meet the age condition, with only the `name` and `email` fields.

#### **Result:**

```json
{ "_id": ObjectId("..."), "name": "Alice", "email": "alice@example.com" }
{ "_id": ObjectId("..."), "name": "John", "email": "john@example.com" }
{ "_id": ObjectId("..."), "name": "Sarah", "email": "sarah@example.com" }
```

---

### **Step 6: Using `limit()` with `skip()` for Pagination**

If you're implementing pagination, you can combine `limit()` with `skip()`. The `skip()` method allows you to skip a certain number of documents in the result set, which is useful for retrieving different pages of results.

#### **Example: Pagination**

To get the second page of 3 results (i.e., skip the first 3 documents and return the next 3), you can use:

```javascript
db.users.find().skip(3).limit(3)
```

This skips the first 3 documents and returns the next 3 documents.

#### **Result:**

```json
{ "_id": ObjectId("..."), "name": "David", "email": "david@example.com" }
{ "_id": ObjectId("..."), "name": "Eve", "email": "eve@example.com" }
{ "_id": ObjectId("..."), "name": "Frank", "email": "frank@example.com" }
```

---

### **Step 7: Sorting and Limiting**

You can also use the `limit()` method in combination with `sort()` to control the order in which documents are returned. For example, to get the first 3 users who are older than 30, sorted by their age in descending order:

```javascript
db.users.find({ age: { $gt: 30 } }).sort({ age: -1 }).limit(3)
```

This will return the top 3 users older than 30, ordered by their age from highest to lowest.

#### **Result:**

```json
{ "_id": ObjectId("..."), "name": "Sarah", "age": 40, "email": "sarah@example.com" }
{ "_id": ObjectId("..."), "name": "John", "age": 32, "email": "john@example.com" }
{ "_id": ObjectId("..."), "name": "Alice", "age": 35, "email": "alice@example.com" }
```

---

### **Step 8: Using `limit()` with Aggregation**

In MongoDB's aggregation framework, the `$limit` stage is used to restrict the number of documents processed by the pipeline.

#### **Example: Aggregation with `$limit`**

To get the first 3 users from an aggregation pipeline:

```javascript
db.users.aggregate([
  { $limit: 3 }
])
```

This will return the first 3 documents from the `users` collection, based on the default sorting order.

---

### **Conclusion**

The `limit()` method in MongoDB is a powerful tool for restricting the number of documents returned in a query. Whether you are retrieving all documents, filtering by certain criteria, or implementing pagination, `limit()` allows you to control the result set size efficiently. You can combine it with other operations like `skip()`, `sort()`, and aggregation to tailor the results to your specific needs.
