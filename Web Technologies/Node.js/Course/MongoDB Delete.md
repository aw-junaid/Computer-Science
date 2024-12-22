### **Node.js - MongoDB Delete**

In MongoDB, you can delete documents from a collection using various methods. The most common delete methods are:

- **`deleteOne()`**: Deletes a single document that matches the query filter.
- **`deleteMany()`**: Deletes all documents that match the query filter.
- **`findOneAndDelete()`**: Finds a single document based on the query filter and deletes it.

---

### **1. Install MongoDB Node.js Driver**

If you haven't installed the MongoDB Node.js driver, you can install it using npm:

```bash
npm install mongodb
```

---

### **2. Deleting a Single Document with `deleteOne()`**

The `deleteOne()` method deletes the first document that matches the provided filter. If no document matches, it does nothing.

#### **Example: Delete a Single Document**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function deleteSingleUser() {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Delete a user where the name is 'Alice'
    const result = await collection.deleteOne({ name: 'Alice' });

    console.log(`${result.deletedCount} document(s) deleted.`);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

deleteSingleUser();
```

- **`deleteOne({ name: 'Alice' })`**: Deletes the first document where the `name` field matches `'Alice'`.
- **`result.deletedCount`**: This will return the number of documents deleted.

---

### **3. Deleting Multiple Documents with `deleteMany()`**

The `deleteMany()` method deletes all documents that match the provided filter.

#### **Example: Delete Multiple Documents**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function deleteMultipleUsers() {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Delete all users older than 30
    const result = await collection.deleteMany({ age: { $gt: 30 } });

    console.log(`${result.deletedCount} document(s) deleted.`);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

deleteMultipleUsers();
```

- **`deleteMany({ age: { $gt: 30 } })`**: Deletes all documents where the `age` field is greater than 30.
- **`result.deletedCount`**: This will return the number of documents deleted.

---

### **4. Deleting a Document with `findOneAndDelete()`**

The `findOneAndDelete()` method finds and deletes a single document that matches the filter. This method returns the document that was deleted.

#### **Example: Find and Delete a Document**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function findAndDeleteUser() {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Find and delete the user with the name 'Bob'
    const result = await collection.findOneAndDelete({ name: 'Bob' });

    console.log('Deleted document:', result.value);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

findAndDeleteUser();
```

- **`findOneAndDelete({ name: 'Bob' })`**: Finds and deletes the first document where the `name` is `'Bob'`.
- **`result.value`**: Returns the deleted document.

---

### **5. Deleting All Documents in a Collection**

If you want to delete all documents in a collection, you can use `deleteMany()` without a filter.

#### **Example: Delete All Documents in a Collection**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function deleteAllUsers() {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Delete all documents in the collection
    const result = await collection.deleteMany({});

    console.log(`${result.deletedCount} document(s) deleted.`);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

deleteAllUsers();
```

- **`deleteMany({})`**: Deletes all documents in the collection.

---

### **6. Conclusion**

- **`deleteOne()`**: Deletes the first document that matches the filter.
- **`deleteMany()`**: Deletes all documents that match the filter.
- **`findOneAndDelete()`**: Finds and deletes a single document and returns the deleted document.
- **`deleteMany({})`**: Deletes all documents in the collection (be cautious when using this).

These delete operations are useful when you need to remove documents based on specific conditions in your Node.js application, and they offer different levels of granularity depending on your needs.
