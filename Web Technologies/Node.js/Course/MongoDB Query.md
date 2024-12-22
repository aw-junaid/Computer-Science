### **Node.js - MongoDB Query**

In MongoDB, querying data is a fundamental operation. You can perform queries using various operators to filter documents, project specific fields, sort data, and much more. Queries in MongoDB use a **filter** to specify the documents you want to retrieve, and a **projection** to specify which fields to include or exclude from the result.

Let’s explore how to perform different types of queries using MongoDB in Node.js.

---

### **1. Install MongoDB Node.js Driver**

If you haven’t installed the MongoDB Node.js driver yet, you can install it using npm:

```bash
npm install mongodb
```

---

### **2. Basic Querying with `find()`**

The `find()` method is used for querying data. You can use various query filters to find specific documents in a collection.

#### **Example: Simple Query with `find()`**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function queryExample() {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Query to find users older than 30
    const query = { age: { $gt: 30 } };

    // Execute the query
    const users = await collection.find(query).toArray();  // Converts cursor to an array

    console.log(users);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

queryExample();
```

- **Query Filter**: `{ age: { $gt: 30 } }` retrieves all users whose `age` is greater than 30.
- **`find(query)`**: Executes the query with the given filter.

---

### **3. Query Operators**

MongoDB provides several operators to help you filter data more efficiently. Here are some common query operators:

- **Comparison Operators**:
  - `$eq`: Equal to
  - `$ne`: Not equal to
  - `$gt`: Greater than
  - `$lt`: Less than
  - `$gte`: Greater than or equal to
  - `$lte`: Less than or equal to
  - `$in`: Value is in the specified array
  - `$nin`: Value is not in the specified array

#### **Example: Query with Comparison Operators**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function queryWithOperators() {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Query with multiple operators
    const query = {
      age: { $gte: 25, $lt: 40 },    // Age between 25 and 40
      name: { $in: ['Alice', 'Bob'] } // Name is either Alice or Bob
    };

    // Execute the query
    const users = await collection.find(query).toArray();

    console.log(users);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

queryWithOperators();
```

- **`$gte: 25`**: Finds users whose age is greater than or equal to 25.
- **`$lt: 40`**: Finds users whose age is less than 40.
- **`$in: ['Alice', 'Bob']`**: Finds users whose name is either Alice or Bob.

---

### **4. Logical Operators**

MongoDB also provides logical operators to combine multiple conditions.

- **`$and`**: Combine multiple conditions with an AND operation.
- **`$or`**: Combine multiple conditions with an OR operation.
- **`$not`**: Negate a condition.
- **`$nor`**: Combine multiple conditions with a NOR operation.

#### **Example: Query with Logical Operators**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function queryWithLogicalOperators() {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Query with logical operators
    const query = {
      $or: [
        { age: { $lt: 30 } },  // Age less than 30
        { name: 'Alice' }       // Name is Alice
      ]
    };

    // Execute the query
    const users = await collection.find(query).toArray();

    console.log(users);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

queryWithLogicalOperators();
```

- **`$or`**: Finds users who are either under 30 years old or have the name Alice.

---

### **5. Projection (Selecting Specific Fields)**

In MongoDB, you can use **projection** to specify which fields should be included or excluded in the result set. By default, MongoDB includes all fields, but you can exclude certain fields (such as `_id`) or include only specific ones.

#### **Example: Query with Projection**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function queryWithProjection() {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Query with projection to exclude the _id field and include only name and age
    const query = {};  // No filter
    const projection = { _id: 0, name: 1, age: 1 };

    // Execute the query
    const users = await collection.find(query).project(projection).toArray();

    console.log(users);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

queryWithProjection();
```

- **`{ _id: 0, name: 1, age: 1 }`**: This projection tells MongoDB to exclude the `_id` field and include only `name` and `age`.

---

### **6. Sorting Results**

You can sort query results by one or more fields using the `sort()` method. Sorting can be done in ascending (`1`) or descending (`-1`) order.

#### **Example: Query with Sorting**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function queryWithSorting() {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Query and sort by age in descending order
    const query = {};
    const sort = { age: -1 };  // -1 for descending order

    // Execute the query
    const users = await collection.find(query).sort(sort).toArray();

    console.log(users);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

queryWithSorting();
```

- **`sort({ age: -1 })`**: Sorts the users by the `age` field in descending order.

---

### **7. Limit and Skip**

You can limit the number of documents returned using the `limit()` method, and you can skip a certain number of documents using the `skip()` method. This is useful for pagination.

#### **Example: Query with Limit and Skip**

```javascript
const { MongoClient } = require('mongodb');

// MongoDB connection URL
const url = 'mongodb://localhost:27017';  // Update this if you're using MongoDB Atlas
const dbName = 'mydatabase';              // Name of your database

const client = new MongoClient(url);

async function queryWithLimitAndSkip() {
  try {
    // Connect to MongoDB server
    await client.connect();
    console.log('Connected to MongoDB');

    // Access the database
    const db = client.db(dbName);

    // Access the collection
    const collection = db.collection('users');  // Name of your collection

    // Query to find users and limit to 3 results, skipping the first 2
    const query = {};
    const users = await collection.find(query).skip(2).limit(3).toArray();

    console.log(users);
  } catch (err) {
    console.error('Error:', err);
  } finally {
    // Close the MongoDB connection
    await client.close();
    console.log('Connection closed');
  }
}

queryWithLimitAndSkip();
```

- **`skip(2)`**: Skips the first 2 documents.
- **`limit(3)`**: Limits the result to 3 documents.

---

### **8. Conclusion**

- **Query filters**: MongoDB provides a variety of query operators like `$gt`, `$lt`, `$in`, `$and`, and `$or` to filter documents.
- **Projection**: You can specify which fields to include or exclude using projection.
- **Sorting**: You can sort the query results using `sort()`.
- **Limit and Skip**: Use `limit()` to restrict the number of results and `skip()` to implement pagination.

With these techniques, you can perform powerful and efficient queries to retrieve data from MongoDB in your Node.js applications.
