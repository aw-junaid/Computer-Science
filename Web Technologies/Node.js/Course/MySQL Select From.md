### **Node.js - MySQL SELECT FROM**

In Node.js, you can retrieve data from a MySQL database using the `SELECT FROM` SQL query. This involves establishing a connection to the MySQL server and executing the query to fetch data from a specific table.

Here’s a step-by-step guide on how to use `SELECT FROM` in Node.js with the `mysql` package.

---

### **1. Install the `mysql` Package**

First, ensure that the `mysql` package (or `mysql2` for Promises support) is installed.

```bash
npm install mysql
```

If you prefer working with Promises, you can use `mysql2`:

```bash
npm install mysql2
```

---

### **2. Connect to MySQL Database**

Before running any query, you need to establish a connection to your MySQL database.

#### **Example: Connecting to MySQL**

```javascript
const mysql = require('mysql');

// Create a connection to MySQL
const connection = mysql.createConnection({
  host: 'localhost',       // MySQL server host
  user: 'root',            // MySQL username
  password: '',            // MySQL password (empty if none)
  database: 'my_database'  // The database you want to query
});

// Connect to the MySQL server
connection.connect((err) => {
  if (err) {
    console.error('Error connecting: ' + err.stack);
    return;
  }
  console.log('Connected as id ' + connection.threadId);
});
```

---

### **3. Select Data from the Table**

Once the connection is established, you can execute a `SELECT FROM` query to fetch data from a table. Below is an example that selects all records from a `users` table.

#### **Example: SELECT All Rows from a Table**

```javascript
// SQL query to select all rows from the "users" table
const selectQuery = 'SELECT * FROM users';

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
- `SELECT * FROM users` selects all columns and rows from the `users` table.
- The `results` object contains the retrieved rows.

---

### **4. Select Specific Columns**

You can also specify which columns you want to retrieve from the table. Below is an example of selecting only the `name` and `email` columns from the `users` table.

#### **Example: SELECT Specific Columns**

```javascript
// SQL query to select specific columns (name, email) from the "users" table
const selectQuery = 'SELECT name, email FROM users';

// Execute the query
connection.query(selectQuery, (err, results) => {
  if (err) {
    console.error('Error fetching data: ' + err.stack);
    return;
  }
  console.log('Data fetched successfully:', results);
});
```

---

### **5. SELECT with WHERE Clause**

To filter the results based on specific conditions, you can use the `WHERE` clause. Below is an example of selecting users with a specific email.

#### **Example: SELECT with WHERE Clause**

```javascript
// SQL query to select users with a specific email
const selectQuery = 'SELECT * FROM users WHERE email = ?';
const email = 'john.doe@example.com';

// Execute the query with the condition
connection.query(selectQuery, [email], (err, results) => {
  if (err) {
    console.error('Error fetching data: ' + err.stack);
    return;
  }
  console.log('Data fetched successfully:', results);
});
```

In this example, the `WHERE` clause filters the data based on the `email` column. The `?` placeholder is used for safe data insertion, protecting against SQL injection.

---

### **6. SELECT with LIMIT**

To limit the number of rows returned, you can use the `LIMIT` clause. Below is an example that selects the first 5 rows from the `users` table.

#### **Example: SELECT with LIMIT**

```javascript
// SQL query to select the first 5 rows from the "users" table
const selectQuery = 'SELECT * FROM users LIMIT 5';

// Execute the query
connection.query(selectQuery, (err, results) => {
  if (err) {
    console.error('Error fetching data: ' + err.stack);
    return;
  }
  console.log('Data fetched successfully:', results);
});
```

---

### **7. SELECT with ORDER BY**

You can order the results using the `ORDER BY` clause. Below is an example of selecting all users ordered by `name` in ascending order.

#### **Example: SELECT with ORDER BY**

```javascript
// SQL query to select all users ordered by name (ascending)
const selectQuery = 'SELECT * FROM users ORDER BY name ASC';

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
- `ORDER BY name ASC` orders the rows by the `name` column in ascending order. You can use `DESC` for descending order.

---

### **8. Closing the Connection**

After retrieving the data, always ensure to close the connection to the MySQL server.

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

### **Full Example: SELECT Query in Node.js**

Here’s a complete example that retrieves all users from the `users` table:

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
    console.error('Error connecting: ' + err.stack);
    return;
  }
  console.log('Connected as id ' + connection.threadId);

  // SQL query to select all rows from the "users" table
  const selectQuery = 'SELECT * FROM users';

  // Execute the query
  connection.query(selectQuery, (err, results) => {
    if (err) {
      console.error('Error fetching data: ' + err.stack);
      return;
    }
    console.log('Data fetched successfully:', results);

    // Close the connection after the query
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

### **9. Using Promises with `mysql2` (Optional)**

If you prefer working with Promises, you can use `mysql2`, which supports Promises and async/await.

#### **Example Using `mysql2` with Promises**

```javascript
const mysql = require('mysql2');

// Create a connection to MySQL
const connection = mysql.createConnection({
  host: 'localhost',
  user: 'root',
  password: '',
  database: 'my_database'
});

// SQL query to select all rows from the "users" table
const selectQuery = 'SELECT * FROM users';

// Use Promises with mysql2 to fetch data
connection.promise().query(selectQuery)
  .then(([rows, fields]) => {
    console.log('Data fetched successfully:', rows);
  })
  .catch((err) => {
    console.error('Error fetching data:', err);
  })
  .finally(() => {
    // Close the connection
    connection.end();
  });
```

---

### **Conclusion**

To select data from a MySQL table in Node.js:

1. Install the `mysql` (or `mysql2`) package.
2. Connect to the MySQL database.
3. Use the `SELECT FROM` query to fetch the data.
4. Handle any errors that might occur during the query execution.
5. Optionally use `WHERE`, `LIMIT`, `ORDER BY`, and other clauses to filter, limit, or sort the data.
6. Close the connection once you’re done.

By following these steps, you can easily retrieve data from MySQL tables using Node.js.
