### **MongoDB - Projection**

In MongoDB, **projection** refers to the process of specifying which fields should be included or excluded when retrieving documents. Projection allows you to control the amount of data returned by a query, optimizing performance, and focusing on the relevant fields.

### **Step 1: Connect to MongoDB**

First, connect to your MongoDB instance by opening the Mongo shell:

```bash
mongosh
```

Then switch to your desired database:

```javascript
use myDatabase
```

### **Step 2: Basic Query with Projection**

By default, MongoDB returns all fields of a document in the query result. However, you can limit the fields returned using projection.

#### **Syntax:**

```javascript
db.collection.find({ <filter> }, { <projection> })
```

- **`filter`**: Criteria to find the documents you want.
- **`projection`**: Specifies the fields to include or exclude.

---

### **Step 3: Including Fields with Projection**

To include specific fields in the result, set those fields to `1` in the projection. For example, if you want to include only the `name` and `email` fields from the documents:

#### **Example: Include Specific Fields**

```javascript
db.users.find({}, { name: 1, email: 1 })
```

This will return only the `name` and `email` fields for all documents in the `users` collection. By default, the `_id` field is included unless explicitly excluded.

#### **Result:**

```json
{ "_id": ObjectId("..."), "name": "Alice", "email": "alice@example.com" }
{ "_id": ObjectId("..."), "name": "Bob", "email": "bob@example.com" }
```

---

### **Step 4: Excluding Fields with Projection**

To exclude specific fields from the result, set those fields to `0` in the projection. For example, to exclude the `password` field and include all other fields:

#### **Example: Exclude Specific Fields**

```javascript
db.users.find({}, { password: 0 })
```

This will return all fields except the `password` field.

#### **Result:**

```json
{ "_id": ObjectId("..."), "name": "Alice", "email": "alice@example.com" }
{ "_id": ObjectId("..."), "name": "Bob", "email": "bob@example.com" }
```

---

### **Step 5: Include and Exclude Fields Simultaneously**

You can include some fields and exclude others, but you cannot mix `1` and `0` in the same projection (except for the `_id` field).

#### **Example: Include and Exclude Fields**

```javascript
db.users.find({}, { name: 1, email: 1, password: 0 })
```

This will return only the `name` and `email` fields and exclude the `password` field, while still including the `_id` field by default.

#### **Result:**

```json
{ "_id": ObjectId("..."), "name": "Alice", "email": "alice@example.com" }
{ "_id": ObjectId("..."), "name": "Bob", "email": "bob@example.com" }
```

---

### **Step 6: Excluding `_id` Field**

By default, MongoDB includes the `_id` field in all query results. If you do not want the `_id` field in the result, you need to explicitly exclude it by setting it to `0`.

#### **Example: Exclude `_id` Field**

```javascript
db.users.find({}, { _id: 0, name: 1, email: 1 })
```

This will return only the `name` and `email` fields, and it will exclude the `_id` field.

#### **Result:**

```json
{ "name": "Alice", "email": "alice@example.com" }
{ "name": "Bob", "email": "bob@example.com" }
```

---

### **Step 7: Nested Fields with Projection**

You can also use projection to retrieve nested fields from documents. MongoDB supports dot notation for specifying nested fields.

#### **Example: Retrieve Nested Fields**

If your document structure has nested fields, such as:

```json
{
  "_id": ObjectId("..."),
  "name": "Alice",
  "address": {
    "street": "123 Main St",
    "city": "New York"
  }
}
```

You can retrieve only the `street` field from the `address` object like this:

```javascript
db.users.find({}, { "address.street": 1 })
```

#### **Result:**

```json
{ "_id": ObjectId("..."), "address": { "street": "123 Main St" } }
```

---

### **Step 8: Using Projection with Query**

You can combine filtering and projection in a single query. For example, to find users older than 30 and include only their `name` and `email` fields:

#### **Example: Query with Projection**

```javascript
db.users.find({ age: { $gt: 30 } }, { name: 1, email: 1 })
```

This will return only the `name` and `email` fields for users who are older than 30.

#### **Result:**

```json
{ "_id": ObjectId("..."), "name": "Alice", "email": "alice@example.com" }
{ "_id": ObjectId("..."), "name": "John", "email": "john@example.com" }
```

---

### **Step 9: Using Projection with Arrays**

MongoDB allows projection to select specific elements from an array. You can use the `$slice` operator to limit the number of elements in an array returned by the query.

#### **Example: Limit Array Elements in Projection**

If the `users` collection has a field `hobbies` which is an array:

```json
{
  "_id": ObjectId("..."),
  "name": "Alice",
  "hobbies": ["reading", "sports", "traveling"]
}
```

You can use `$slice` to return only the first 2 elements of the `hobbies` array:

```javascript
db.users.find({}, { name: 1, hobbies: { $slice: 2 } })
```

#### **Result:**

```json
{ "_id": ObjectId("..."), "name": "Alice", "hobbies": ["reading", "sports"] }
```

---

### **Step 10: Projection with Aggregation**

In aggregation queries, projection can be done using the `$project` stage. The `$project` stage allows you to specify which fields to include or exclude, and also to apply transformations or create new fields.

#### **Example: Aggregation with `$project`**

```javascript
db.users.aggregate([
  { $project: { name: 1, age: 1, _id: 0 } }
])
```

This will return documents with only the `name` and `age` fields and exclude the `_id` field.

---

### **Conclusion**

Projection in MongoDB is a powerful feature that allows you to control which fields are returned in a query result. By including or excluding specific fields, you can optimize performance and reduce the amount of unnecessary data transmitted from the server to the client. MongoDB provides flexible projection options, including dot notation for nested fields, exclusion of the `_id` field, and support for arrays and aggregations.
