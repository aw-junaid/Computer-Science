### **Node.js - MongoDB Get Started**

MongoDB is a NoSQL database, which stores data in a flexible, JSON-like format called BSON (Binary JSON). It is widely used for building scalable and high-performance web applications.

To interact with MongoDB in Node.js, you use the **MongoDB Node.js driver** or **Mongoose**, which is an ODM (Object Data Modeling) library that provides a higher abstraction layer over MongoDB.

This guide will show you how to get started with MongoDB in Node.js using the **MongoDB Node.js Driver**.

---

### **1. Install MongoDB**

If you don’t have MongoDB installed locally, follow the installation guide for your operating system:

- **Windows**: [MongoDB Windows Installation](https://docs.mongodb.com/manual/tutorial/install-mongodb-on-windows/)
- **macOS**: [MongoDB macOS Installation](https://docs.mongodb.com/manual/tutorial/install-mongodb-on-os-x/)
- **Linux**: [MongoDB Linux Installation](https://docs.mongodb.com/manual/installation/)

Alternatively, you can use **MongoDB Atlas**, a cloud-based MongoDB service, for easy database management.

---

### **2. Install MongoDB Driver for Node.js**

To interact with MongoDB from a Node.js application, you’ll need the `mongodb` package.

You can install it using npm:

```bash
npm install mongodb
```

Alternatively, you can install `mongoose` for higher-level operations:

```bash
npm install mongoose
```

In this tutorial, we'll use the MongoDB native driver (`mongodb` package).

---

### **3. Connect to MongoDB Database**

After installing the MongoDB Node.js driver, the next step is to connect to your MongoDB server.

#### **Example: Connecting to MongoDB Using the MongoDB Native Driver**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB URI (use localhost or a MongoDB Atlas connection string)
const url = 'mongodb://localhost:27017';  // Change this for MongoDB Atlas
const dbName = 'mydatabase';  // Name of your database

// Create a new MongoClient
const client = new MongoClient(url);

// Connect to MongoDB
client.connect()
  .then(() => {
    console.log('Connected to MongoDB');
    const db = client.db(dbName); // Get the database
  })
  .catch(err => {
    console.error('Error connecting to MongoDB:', err);
  });
```

In this example:
- We are connecting to a local MongoDB server running on `localhost` and port `27017`.
- The `dbName` is the name of the database you want to use.

If you’re using MongoDB Atlas, you’ll replace `url` with the connection string provided by Atlas.

---

### **4. CRUD Operations in MongoDB**

MongoDB allows you to perform CRUD (Create, Read, Update, Delete) operations. Here's how you can perform these operations using the MongoDB native driver in Node.js.

#### **A. Create (Insert Documents)**

To insert data, you can use the `insertOne()` or `insertMany()` methods.

```javascript
// Insert a single document
const collection = db.collection('users'); // Get the collection

// Single document insertion
collection.insertOne({
  name: 'John Doe',
  age: 30,
  email: 'john.doe@example.com'
})
  .then(result => {
    console.log('Inserted document:', result.insertedId);
  })
  .catch(err => {
    console.error('Error inserting document:', err);
  });
```

To insert multiple documents at once:

```javascript
// Insert multiple documents
const users = [
  { name: 'Alice', age: 25, email: 'alice@example.com' },
  { name: 'Bob', age: 28, email: 'bob@example.com' }
];

collection.insertMany(users)
  .then(result => {
    console.log(`${result.insertedCount} documents inserted.`);
  })
  .catch(err => {
    console.error('Error inserting documents:', err);
  });
```

---

#### **B. Read (Find Documents)**

You can use `find()` to retrieve documents from a collection. To retrieve a single document, use `findOne()`.

```javascript
// Find all documents in a collection
collection.find({}).toArray()
  .then(results => {
    console.log('Documents:', results);
  })
  .catch(err => {
    console.error('Error finding documents:', err);
  });

// Find a single document with a specific condition
collection.findOne({ name: 'John Doe' })
  .then(result => {
    console.log('Found document:', result);
  })
  .catch(err => {
    console.error('Error finding document:', err);
  });
```

To filter results, pass a query object:

```javascript
// Find users with age greater than 25
collection.find({ age: { $gt: 25 } }).toArray()
  .then(results => {
    console.log('Users older than 25:', results);
  })
  .catch(err => {
    console.error('Error finding users:', err);
  });
```

---

#### **C. Update Documents**

You can update documents using `updateOne()`, `updateMany()`, or `replaceOne()`.

```javascript
// Update a single document
collection.updateOne(
  { name: 'John Doe' }, // Filter condition
  { $set: { age: 31 } }  // Update operation
)
  .then(result => {
    console.log('Updated document:', result.modifiedCount);
  })
  .catch(err => {
    console.error('Error updating document:', err);
  });
```

To update multiple documents:

```javascript
// Update multiple documents
collection.updateMany(
  { age: { $lt: 30 } },
  { $set: { status: 'young' } }
)
  .then(result => {
    console.log('Updated documents:', result.modifiedCount);
  })
  .catch(err => {
    console.error('Error updating documents:', err);
  });
```

---

#### **D. Delete Documents**

You can delete documents using `deleteOne()` or `deleteMany()`.

```javascript
// Delete a single document
collection.deleteOne({ name: 'John Doe' })
  .then(result => {
    console.log('Deleted document:', result.deletedCount);
  })
  .catch(err => {
    console.error('Error deleting document:', err);
  });

// Delete multiple documents
collection.deleteMany({ age: { $gt: 30 } })
  .then(result => {
    console.log('Deleted documents:', result.deletedCount);
  })
  .catch(err => {
    console.error('Error deleting documents:', err);
  });
```

---

### **5. Closing the MongoDB Connection**

It’s important to close the connection once you’re done with the operations:

```javascript
client.close()
  .then(() => {
    console.log('Connection closed');
  })
  .catch(err => {
    console.error('Error closing connection:', err);
  });
```

---

### **6. Full Example: Connecting and Performing CRUD Operations**

```javascript
const { MongoClient } = require('mongodb');

const url = 'mongodb://localhost:27017'; // MongoDB URI
const dbName = 'mydatabase'; // Database name

const client = new MongoClient(url);

async function run() {
  try {
    await client.connect();
    console.log('Connected to MongoDB');

    const db = client.db(dbName);
    const collection = db.collection('users');

    // Insert a single document
    const result = await collection.insertOne({
      name: 'John Doe',
      age: 30,
      email: 'john.doe@example.com'
    });
    console.log('Inserted document:', result.insertedId);

    // Find all documents
    const users = await collection.find({}).toArray();
    console.log('Users:', users);

    // Update a document
    const updateResult = await collection.updateOne(
      { name: 'John Doe' },
      { $set: { age: 31 } }
    );
    console.log('Updated document count:', updateResult.modifiedCount);

    // Delete a document
    const deleteResult = await collection.deleteOne({ name: 'John Doe' });
    console.log('Deleted document count:', deleteResult.deletedCount);

  } catch (err) {
    console.error('Error:', err);
  } finally {
    await client.close();
    console.log('Connection closed');
  }
}

run();
```

---

### **Conclusion**

In this tutorial, we’ve covered the basics of interacting with MongoDB in Node.js. Here are the key points:

1. Install the MongoDB Node.js driver (`mongodb`).
2. Establish a connection to MongoDB using `MongoClient`.
3. Perform CRUD operations: insert, read, update, and delete documents.
4. Close the connection when done.

By following these steps, you can effectively use MongoDB as your database solution in Node.js applications.
