### **Node.js - MongoDB Update**

In MongoDB, you can update documents in a collection using the following methods:

- **`updateOne()`**: Updates a single document that matches the query filter.
- **`updateMany()`**: Updates multiple documents that match the query filter.
- **`findOneAndUpdate()`**: Finds a single document based on the filter and updates it.
- **`replaceOne()`**: Replaces a document entirely.

These methods allow you to modify the data in MongoDB, either partially or entirely, depending on the use case.

---

### **1. Install MongoDB Node.js Driver**

If you haven't installed the MongoDB Node.js driver, install it using npm:

```bash
npm install mongodb
```

---

### **2. Update a Single Document with `updateOne()`**

The `updateOne()` method updates the first document that matches the query filter. You can specify the update operation using operators like `$set`, `$inc`, `$push`, etc.

#### **Example: Update a Single Document**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function updateSingleUser() {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Update a user where the name is 'Alice', setting the age to 25
    const result = await collection.updateOne(
      { name: 'Alice' },    // Filter: Find the document with name 'Alice'
      { $set: { age: 25 } } // Update operation: Set age to 25
    );

    console.log(`${result.modifiedCount} document(s) updated.`);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

updateSingleUser();
```

- **`updateOne({ name: 'Alice' }, { $set: { age: 25 } })`**: This updates the first document where `name` is `'Alice'` and sets the `age` field to 25.
- **`result.modifiedCount`**: This will return the number of documents modified.

---

### **3. Update Multiple Documents with `updateMany()`**

The `updateMany()` method updates all documents that match the query filter.

#### **Example: Update Multiple Documents**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function updateMultipleUsers() {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Update all users with age less than 30, setting status to 'active'
    const result = await collection.updateMany(
      { age: { $lt: 30 } },    // Filter: Find users with age less than 30
      { $set: { status: 'active' } }  // Update operation: Set status to 'active'
    );

    console.log(`${result.modifiedCount} document(s) updated.`);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

updateMultipleUsers();
```

- **`updateMany({ age: { $lt: 30 } }, { $set: { status: 'active' } })`**: This updates all documents where `age` is less than 30, setting the `status` field to `'active'`.
- **`result.modifiedCount`**: This will return the number of documents modified.

---

### **4. Update a Document with `findOneAndUpdate()`**

The `findOneAndUpdate()` method finds a single document based on the filter, updates it, and returns the original or updated document.

#### **Example: Find and Update a Document**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function findAndUpdateUser() {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Find a user with name 'Bob' and update their age to 28
    const result = await collection.findOneAndUpdate(
      { name: 'Bob' },    // Filter: Find user with name 'Bob'
      { $set: { age: 28 } },  // Update operation: Set age to 28
      { returnDocument: 'after' }  // Return the updated document
    );

    console.log('Updated document:', result.value);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

findAndUpdateUser();
```

- **`findOneAndUpdate({ name: 'Bob' }, { $set: { age: 28 } })`**: This finds the first document where `name` is `'Bob'` and sets the `age` to 28.
- **`result.value`**: Returns the updated document.

---

### **5. Replace a Document with `replaceOne()`**

The `replaceOne()` method replaces an entire document with a new one.

#### **Example: Replace a Document**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function replaceUser() {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Replace the document where the name is 'Alice' with a new document
    const result = await collection.replaceOne(
      { name: 'Alice' },  // Filter: Find the user with name 'Alice'
      { name: 'Alice', age: 26, status: 'active' }  // New document to replace the old one
    );

    console.log(`${result.modifiedCount} document(s) replaced.`);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

replaceUser();
```

- **`replaceOne({ name: 'Alice' }, { name: 'Alice', age: 26, status: 'active' })`**: This replaces the entire document where `name` is `'Alice'` with a new document.

---

### **6. Update Operators**

MongoDB provides several update operators that allow you to modify documents in different ways:

- **`$set`**: Sets the value of a field.
- **`$inc`**: Increments the value of a field by a specified amount.
- **`$push`**: Adds an element to an array.
- **`$pull`**: Removes an element from an array.
- **`$addToSet`**: Adds a unique element to an array.
- **`$unset`**: Removes a field from a document.

#### **Example: Incrementing a Field (`$inc`)**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function incrementAge() {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Increment the age of user 'Alice' by 1
    const result = await collection.updateOne(
      { name: 'Alice' },  // Filter: Find user 'Alice'
      { $inc: { age: 1 } }  // Update operation: Increment age by 1
    );

    console.log(`${result.modifiedCount} document(s) updated.`);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

incrementAge();
```

---

### **7. Conclusion**

- **`updateOne()`**: Updates the first document that matches the query filter.
- **`updateMany()`**: Updates all documents that match the query filter.
- **`findOneAndUpdate()`**: Finds and updates a single document and returns the updated document.
- **`replaceOne()`**: Replaces a document entirely with a new one.
- **Update Operators**: MongoDB provides operators like `$set`, `$inc`, `$push`, `$pull`, and others to perform complex updates on documents.

These methods and operators allow you to manipulate documents efficiently in MongoDB, making it easy to modify data within your collections.
