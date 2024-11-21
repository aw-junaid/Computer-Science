### **MongoDB - Update Document**

In MongoDB, you can update existing documents in a collection using the `updateOne()`, `updateMany()`, and `replaceOne()` methods. These methods allow you to modify one or more documents that match specified criteria.

### **Step 1: Connect to MongoDB**

Open your terminal and start the Mongo shell by typing:

```bash
mongosh
```

This will connect you to the default database (`test`). You can switch to your desired database using the `use` command:

```javascript
use myDatabase
```

### **Step 2: Basic Update Syntax**

In MongoDB, the basic syntax for an update operation is:

```javascript
db.collection.updateOne(<filter>, <update>, <options>)
```

Where:
- **`filter`**: Specifies the criteria to match the document(s) that should be updated.
- **`update`**: Defines the update operation(s) to apply.
- **`options`**: Additional options like `upsert` (if true, it will insert a document if no match is found).

---

### **Step 3: Update a Single Document (`updateOne`)**

The `updateOne()` method updates the first document that matches the given filter.

#### **Syntax:**

```javascript
db.collection.updateOne(
  { <filter> },         // The filter criteria to match the document
  { <update> }          // The update operation
)
```

#### **Example: Update a Single Document**

Let's say we want to update the email address of a user with the name `"John"`:

```javascript
db.users.updateOne(
  { name: "John" },                       // Filter criteria
  { $set: { email: "john.doe@example.com" } }  // Update operation
)
```

This updates the first document where `name` is `"John"` and sets the `email` field to `"john.doe@example.com"`.

#### **Response:**

MongoDB will return a response indicating how many documents were matched and modified:

```json
{
  "acknowledged": true,
  "matchedCount": 1,
  "modifiedCount": 1
}
```

---

### **Step 4: Update Multiple Documents (`updateMany`)**

The `updateMany()` method updates all documents that match the specified filter.

#### **Syntax:**

```javascript
db.collection.updateMany(
  { <filter> },         // The filter criteria to match documents
  { <update> }          // The update operation
)
```

#### **Example: Update Multiple Documents**

Suppose we want to update the `status` field of all users who are under 30 years old to `"active"`:

```javascript
db.users.updateMany(
  { age: { $lt: 30 } },                          // Filter criteria
  { $set: { status: "active" } }                  // Update operation
)
```

This updates all users whose `age` is less than 30 and sets their `status` to `"active"`.

#### **Response:**

The response will indicate how many documents were matched and modified:

```json
{
  "acknowledged": true,
  "matchedCount": 5,
  "modifiedCount": 5
}
```

---

### **Step 5: Replace a Document (`replaceOne`)**

The `replaceOne()` method replaces an entire document, matching the first document found by the specified filter.

#### **Syntax:**

```javascript
db.collection.replaceOne(
  { <filter> },               // The filter criteria to match the document
  { <replacementDocument> }    // The replacement document
)
```

#### **Example: Replace a Document**

Let's say we want to replace a user document where `name` is `"John"`:

```javascript
db.users.replaceOne(
  { name: "John" },                            // Filter criteria
  { name: "John Doe", age: 30, email: "john@example.com" }  // Replacement document
)
```

This will completely replace the existing document where `name` is `"John"` with a new document. Any existing fields in the document that are not in the replacement document will be removed.

#### **Response:**

The response will show how many documents were matched and replaced:

```json
{
  "acknowledged": true,
  "matchedCount": 1,
  "modifiedCount": 1
}
```

---

### **Step 6: Update Document with Operators**

MongoDB provides several operators to modify the values of specific fields within a document.

#### **1. `$set` Operator**

The `$set` operator is used to set the value of a field. If the field does not exist, it will be created.

```javascript
db.users.updateOne(
  { name: "Alice" },
  { $set: { age: 32, email: "alice.new@example.com" } }
)
```

This updates the `age` and `email` fields of the document where `name` is `"Alice"`. If the fields don’t exist, they are created.

#### **2. `$unset` Operator**

The `$unset` operator is used to remove a field from a document.

```javascript
db.users.updateOne(
  { name: "John" },
  { $unset: { email: "" } }
)
```

This removes the `email` field from the document where `name` is `"John"`.

#### **3. `$inc` Operator**

The `$inc` operator is used to increment or decrement a numeric field.

```javascript
db.users.updateOne(
  { name: "Bob" },
  { $inc: { age: 1 } }
)
```

This increments the `age` field by 1 for the document where `name` is `"Bob"`.

#### **4. `$push` Operator**

The `$push` operator is used to add an element to an array.

```javascript
db.users.updateOne(
  { name: "Charlie" },
  { $push: { hobbies: "reading" } }
)
```

This adds `"reading"` to the `hobbies` array of the document where `name` is `"Charlie"`.

#### **5. `$pull` Operator**

The `$pull` operator is used to remove an element from an array.

```javascript
db.users.updateOne(
  { name: "Charlie" },
  { $pull: { hobbies: "reading" } }
)
```

This removes `"reading"` from the `hobbies` array of the document where `name` is `"Charlie"`.

#### **6. `$addToSet` Operator**

The `$addToSet` operator ensures that an item is added to an array only if it doesn’t already exist in the array (like a set in programming).

```javascript
db.users.updateOne(
  { name: "Charlie" },
  { $addToSet: { hobbies: "swimming" } }
)
```

This adds `"swimming"` to the `hobbies` array of the document where `name` is `"Charlie"` if it doesn’t already exist.

#### **7. `$rename` Operator**

The `$rename` operator is used to rename a field in a document.

```javascript
db.users.updateOne(
  { name: "John" },
  { $rename: { "email": "contact_email" } }
)
```

This renames the `email` field to `contact_email` in the document where `name` is `"John"`.

---

### **Step 7: Upsert (Insert if Document Does Not Exist)**

If you want to update a document and insert it if no matching document is found, you can use the `upsert` option. When set to `true`, MongoDB will insert a new document if no matching document is found.

#### **Example: Upsert**

```javascript
db.users.updateOne(
  { name: "Alice" },                         // Filter
  { $set: { age: 35, email: "alice@example.com" } }, // Update operation
  { upsert: true }                           // Upsert option
)
```

If no document with `name: "Alice"` is found, this operation will insert a new document with `name: "Alice"`, `age: 35`, and `email: "alice@example.com"`.

---

### **Step 8: Verify the Update**

After updating a document, you can use the `find()` method to check the updated data:

```javascript
db.users.find({ name: "John" }).pretty()
```

---

### **Conclusion**

MongoDB provides several powerful methods and operators for updating documents. The `updateOne()`, `updateMany()`, and `replaceOne()` methods give you flexibility in modifying documents based on specific criteria. You can update fields, remove fields, increment values, and even modify arrays. Additionally, operators like `$set`, `$unset`, `$push`, `$inc`, and others make it easy to perform common update tasks.
