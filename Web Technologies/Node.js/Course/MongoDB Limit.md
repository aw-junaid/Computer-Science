### **Node.js - MongoDB Limit**

In MongoDB, the **`limit()`** method is used to specify the maximum number of documents to return from a query. This is especially useful when you want to paginate results or limit the amount of data fetched for performance reasons.

### **1. Install MongoDB Node.js Driver**

If you haven't installed the MongoDB Node.js driver, install it using npm:

```bash
npm install mongodb
```

---

### **2. Basic Usage of `limit()`**

The `limit()` method can be applied to the result of a `find()` query to limit the number of documents returned. It is commonly used in combination with other query methods like `skip()`, `sort()`, etc., for pagination.

#### **Example: Limit the Number of Documents**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function getLimitedUsers() {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Find users and limit the result to 5 documents
    const users = await collection.find().limit(5).toArray();

    console.log('Users:', users);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

getLimitedUsers();
```

- **`find().limit(5)`**: This retrieves a maximum of 5 documents from the `users` collection.
- **`toArray()`**: Converts the result to an array.

---

### **3. Using `limit()` with `skip()` for Pagination**

The `limit()` method is often used in combination with `skip()` to implement pagination. The `skip()` method is used to skip a specified number of documents, which allows you to paginate the results.

#### **Example: Implement Pagination**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function getPaginatedUsers(page, pageSize) {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Skip the previous pages and limit the results to `pageSize`
    const users = await collection.find()
      .skip((page - 1) * pageSize)  // Skip documents for the previous pages
      .limit(pageSize)              // Limit to the page size
      .toArray();

    console.log(`Page ${page} users:`, users);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

// Example: Get the second page with 5 users per page
getPaginatedUsers(2, 5);
```

- **`skip((page - 1) * pageSize)`**: This skips the appropriate number of documents for the current page.
- **`limit(pageSize)`**: This limits the number of documents returned per page.

---

### **4. Using `limit()` with `sort()`**

You can also combine `limit()` with `sort()` to return the top N documents based on a specified sorting order.

#### **Example: Get the Top 3 Most Recent Users**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function getTopUsers() {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Find the top 3 most recent users (sorted by `createdAt` descending)
    const topUsers = await collection.find()
      .sort({ createdAt: -1 })  // Sort by `createdAt` field in descending order
      .limit(3)                 // Limit to 3 documents
      .toArray();

    console.log('Top 3 most recent users:', topUsers);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

getTopUsers();
```

- **`sort({ createdAt: -1 })`**: Sorts the documents by the `createdAt` field in descending order (most recent first).
- **`limit(3)`**: Limits the result to 3 documents.

---

### **5. Conclusion**

- **`limit(n)`**: Limits the number of documents returned by a query to `n` documents.
- **Pagination**: By combining `limit()` with `skip()`, you can paginate through the results.
- **Sorting**: You can combine `limit()` with `sort()` to fetch the top N results based on a sorting order.

Using the `limit()` method is an efficient way to control the amount of data retrieved from MongoDB, especially for large datasets where you may only need a subset of the documents.
