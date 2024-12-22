### **Node.js - MySQL WHERE Clause**

In Node.js, you can use the `WHERE` clause in SQL queries to filter data based on specific conditions. This allows you to select only the rows that meet the criteria you define. The `mysql` (or `mysql2`) package allows you to interact with MySQL databases in Node.js, making it easy to execute queries with a `WHERE` clause.

### **1. Install the `mysql` Package**

To interact with MySQL in Node.js, you need to install the `mysql` package (or `mysql2` for Promises support).

```bash
npm install mysql
```

For promise-based functionality, you can install `mysql2`:

```bash
npm install mysql2
```

---

### **2. Connect to MySQL Database**

Before executing queries, connect to the MySQL database. Here is an example of how to establish a connection.

#### **Example: Connecting to MySQL**

```javascript
const mysql = require('mysql');

// Create a connection to the MySQL database
const connection = mysql.createConnection({
  host: 'localhost',       // MySQL host
  user: 'root',            // MySQL username
  password: '',            // MySQL password (empty if none)
  database: 'my_database'  // The database to query
});

// Connect to the MySQL server
connection.connect((err) => {
  if (err) {
    console.error('Error connecting to database: ' + err.stack);
    return;
  }
  console.log('Connected as id ' + connection.threadId);
});
```

---

### **3. Using `WHERE` Clause to Filter Data**

The `WHERE` clause is used to filter records based on a condition. You can filter rows based on column values, ranges, or specific patterns.

#### **Example: SELECT with `WHERE` Clause**

Here is an example of selecting all rows from the `users` table where the `age` column is greater than 30.

```javascript
// SQL query to select users with age greater than 30
const selectQuery = 'SELECT * FROM users WHERE age > 30';

// Execute the query
connection.query(selectQuery, (err, results) => {
  if (err) {
    console.error('Error fetching data: ' + err.stack);
    return;
  }
  console.log('Data fetched successfully:', results);
});
```

In this example:
- The `WHERE age > 30` condition filters the rows based on the `age` column, retrieving users whose age is greater than 30.

---

### **4. Using `WHERE` with Multiple Conditions**

You can combine multiple conditions using `AND`, `OR`, or `NOT` for more complex queries.

#### **Example: `WHERE` with Multiple Conditions (AND)**

```javascript
// SQL query to select users older than 30 and from a specific city
const selectQuery = 'SELECT * FROM users WHERE age > 30 AND city = ?';
const city = 'New York';

// Execute the query with the condition
connection.query(selectQuery, [city], (err, results) => {
  if (err) {
    console.error('Error fetching data: ' + err.stack);
    return;
  }
  console.log('Data fetched successfully:', results);
});
```

In this example:
- `WHERE age > 30 AND city = ?` filters users who are both older than 30 and live in "New York."

#### **Example: `WHERE` with OR Condition**

```javascript
// SQL query to select users who are either older than 30 or from New York
const selectQuery = 'SELECT * FROM users WHERE age > 30 OR city = ?';
const city = 'New York';

// Execute the query with the condition
connection.query(selectQuery, [city], (err, results) => {
  if (err) {
    console.error('Error fetching data: ' + err.stack);
    return;
  }
  console.log('Data fetched successfully:', results);
});
```

In this example:
- `WHERE age > 30 OR city = ?` retrieves users who are either older than 30 or from "New York."

---

### **5. Using `WHERE` with `LIKE` for Pattern Matching**

You can use the `LIKE` keyword to search for a pattern within a column's values.

#### **Example: Using `LIKE` with `WHERE`**

```javascript
// SQL query to select users whose name starts with "John"
const selectQuery = 'SELECT * FROM users WHERE name LIKE ?';
const namePattern = 'John%';  // % is a wildcard for any number of characters

// Execute the query with the LIKE condition
connection.query(selectQuery, [namePattern], (err, results) => {
  if (err) {
    console.error('Error fetching data: ' + err.stack);
    return;
  }
  console.log('Data fetched successfully:', results);
});
```

In this example:
- `WHERE name LIKE 'John%'` retrieves users whose name starts with "John" (the `%` symbol acts as a wildcard for any characters following "John").

---

### **6. Using `WHERE` with `BETWEEN`**

The `BETWEEN` keyword allows you to filter data within a specific range (inclusive).

#### **Example: Using `BETWEEN`**

```javascript
// SQL query to select users whose age is between 20 and 40
const selectQuery = 'SELECT * FROM users WHERE age BETWEEN ? AND ?';
const ageMin = 20;
const ageMax = 40;

// Execute the query with the BETWEEN condition
connection.query(selectQuery, [ageMin, ageMax], (err, results) => {
  if (err) {
    console.error('Error fetching data: ' + err.stack);
    return;
  }
  console.log('Data fetched successfully:', results);
});
```

In this example:
- `WHERE age BETWEEN 20 AND 40` retrieves users whose age is between 20 and 40 (inclusive).

---

### **7. Using `WHERE` with `IN`**

The `IN` keyword allows you to filter rows based on multiple possible values for a column.

#### **Example: Using `IN`**

```javascript
// SQL query to select users who live in New York, London, or Paris
const selectQuery = 'SELECT * FROM users WHERE city IN (?, ?, ?)';
const cities = ['New York', 'London', 'Paris'];

// Execute the query with the IN condition
connection.query(selectQuery, cities, (err, results) => {
  if (err) {
    console.error('Error fetching data: ' + err.stack);
    return;
  }
  console.log('Data fetched successfully:', results);
});
```

In this example:
- `WHERE city IN ('New York', 'London', 'Paris')` retrieves users who live in one of the specified cities.

---

### **8. Using `WHERE` with `IS NULL`**

You can use `IS NULL` to filter records where a column has no value (is `NULL`).

#### **Example: Using `IS NULL`**

```javascript
// SQL query to select users whose phone number is null
const selectQuery = 'SELECT * FROM users WHERE phone_number IS NULL';

// Execute the query with the IS NULL condition
connection.query(selectQuery, (err, results) => {
  if (err) {
    console.error('Error fetching data: ' + err.stack);
    return;
  }
  console.log('Data fetched successfully:', results);
});
```

In this example:
- `WHERE phone_number IS NULL` retrieves users who do not have a phone number listed.

---

### **9. Closing the Connection**

Once the query is executed and data is retrieved, don’t forget to close the connection to the database.

```javascript
connection.end((err) => {
  if (err) {
    console.error('Error ending connection:', err);
  } else {
    console.log('Connection closed.');
  }
});
```

---

### **Full Example: Using `WHERE` in Node.js**

Here is a complete example that combines several `WHERE` conditions to select users from the `users` table:

```javascript
const mysql = require('mysql');

// Create a connection to MySQL
const connection = mysql.createConnection({
  host: 'localhost',
  user: 'root',
  password: '',
  database: 'my_database'
});

// Connect to the MySQL server
connection.connect((err) => {
  if (err) {
    console.error('Error connecting to database: ' + err.stack);
    return;
  }
  console.log('Connected as id ' + connection.threadId);

  // SQL query to select users older than 30 and live in New York
  const selectQuery = 'SELECT * FROM users WHERE age > 30 AND city = ?';
  const city = 'New York';

  // Execute the query
  connection.query(selectQuery, [city], (err, results) => {
    if (err) {
      console.error('Error fetching data: ' + err.stack);
      return;
    }
    console.log('Data fetched successfully:', results);

    // Close the connection
    connection.end((err) => {
      if (err) {
        console.error('Error ending connection:', err);
      } else {
        console.log('Connection closed.');
      }
    });
  });
});
```

---

### **Conclusion**

Using the `WHERE` clause in Node.js with MySQL allows you to filter your queries based on specific conditions. The `mysql` package helps you execute these queries by:
1. Connecting to the MySQL database.
2. Writing SQL queries with the `WHERE` clause to filter data.
3. Using conditions like `AND`, `OR`, `LIKE`, `BETWEEN`, and `IN` to refine the query results.
4. Closing the connection after performing the query.

This is a fundamental technique for retrieving specific data from MySQL databases in Node.js applications.
