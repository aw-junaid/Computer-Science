### **Node.js - MongoDB Sort**

In MongoDB, sorting the results of a query is a common operation, and it's easy to achieve using the `sort()` method. You can sort the query results in **ascending** or **descending** order based on one or more fields.

---

### **1. Install MongoDB Node.js Driver**

If you haven’t already installed the MongoDB Node.js driver, you can install it using npm:

```bash
npm install mongodb
```

---

### **2. Basic Sorting with `sort()`**

The `sort()` method allows you to sort documents based on the fields of the documents. You can specify the sorting order:

- **1** for ascending order.
- **-1** for descending order.

#### **Example: Basic Sort (Ascending Order)**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function sortUsersAscending() {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Find users and sort by age in ascending order (1)
    const cursor = collection.find().sort({ age: 1 });

    // Print sorted documents
    const users = await cursor.toArray();
    console.log(users);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

sortUsersAscending();
```

- **`sort({ age: 1 })`**: Sorts the users by the `age` field in **ascending** order.

---

### **3. Sorting in Descending Order**

To sort in descending order, use **-1** for the field.

#### **Example: Sort in Descending Order**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function sortUsersDescending() {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Find users and sort by age in descending order (-1)
    const cursor = collection.find().sort({ age: -1 });

    // Print sorted documents
    const users = await cursor.toArray();
    console.log(users);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

sortUsersDescending();
```

- **`sort({ age: -1 })`**: Sorts the users by the `age` field in **descending** order.

---

### **4. Sorting by Multiple Fields**

You can also sort by multiple fields. MongoDB sorts documents based on the order in which fields are specified in the `sort()` method. 

- **1** for ascending order.
- **-1** for descending order.

#### **Example: Sort by Multiple Fields**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function sortByMultipleFields() {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Sort by age in ascending order, then by name in descending order
    const cursor = collection.find().sort({ age: 1, name: -1 });

    // Print sorted documents
    const users = await cursor.toArray();
    console.log(users);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

sortByMultipleFields();
```

- **`sort({ age: 1, name: -1 })`**: First sorts by `age` in ascending order. For documents with the same age, it sorts by `name` in descending order.

---

### **5. Sorting with Projection**

You can use **projection** to select specific fields and combine it with sorting.

#### **Example: Sorting with Projection**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function sortWithProjection() {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Query to find users, project name and age fields, and sort by age
    const cursor = collection.find({}, { projection: { _id: 0, name: 1, age: 1 } }).sort({ age: 1 });

    // Print sorted documents with specific fields
    const users = await cursor.toArray();
    console.log(users);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

sortWithProjection();
```

- **Projection** `{ _id: 0, name: 1, age: 1 }`: Includes only `name` and `age` in the result, excluding the `_id` field.

---

### **6. Limit and Sort Together**

You can combine **limit** and **sort** to control the number of sorted results.

#### **Example: Limit with Sorting**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function sortWithLimit() {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Query to find users, limit the result to 5, and sort by age in ascending order
    const cursor = collection.find().sort({ age: 1 }).limit(5);

    // Print the result
    const users = await cursor.toArray();
    console.log(users);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

sortWithLimit();
```

- **`sort({ age: 1 }).limit(5)`**: Sorts the documents by `age` in ascending order and limits the result to the first 5 documents.

---

### **7. Conclusion**

- **`sort()`**: Use this method to order your query results by one or more fields. Specify **1** for ascending order and **-1** for descending order.
- **Multiple Fields**: You can sort by more than one field by specifying the fields in the `sort()` method.
- **Projection**: Use projection to limit the fields returned by your query while still sorting the results.
- **Limit and Skip**: Use `limit()` to restrict the number of documents returned and `skip()` for pagination.

Sorting is a powerful feature in MongoDB that helps to organize data and makes it easy to retrieve results in a specified order. You can combine it with other query operations to optimize your application.
