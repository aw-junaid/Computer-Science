### **Node.js - MySQL Insert Into**

In Node.js, you can insert data into a MySQL table using the `mysql` (or `mysql2`) package. This process involves connecting to a MySQL database and executing an `INSERT INTO` SQL query.

Here’s a step-by-step guide to inserting data into a MySQL table using Node.js.

---

### **1. Install the `mysql` Package**

To interact with MySQL from Node.js, you need to install the `mysql` package (or `mysql2` if you prefer using promises).

```bash
npm install mysql
```

Alternatively, for promise-based operations, you can use the `mysql2` package:

```bash
npm install mysql2
```

---

### **2. Connect to the MySQL Database**

Before you can insert data into a table, you need to connect to the MySQL server and specify the database you are working with.

#### **Example: Connecting to MySQL**

```javascript
// Import the mysql package
const mysql = require('mysql');

// Create a connection to MySQL
const connection = mysql.createConnection({
  host: 'localhost',       // MySQL server host
  user: 'root',            // MySQL username
  password: '',            // MySQL password (empty if none)
  database: 'my_database'  // The database where the table exists
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

### **3. Insert Data into the Table**

After establishing the connection, you can use the `INSERT INTO` SQL query to insert data into a specific table. Below is an example of inserting data into the `users` table.

#### **Example: Inserting a Single Row**

```javascript
// SQL query to insert data
const insertQuery = 'INSERT INTO users (name, email) VALUES (?, ?)';

// Data to insert
const values = ['John Doe', 'john.doe@example.com'];

// Execute the query to insert data
connection.query(insertQuery, values, (err, result) => {
  if (err) {
    console.error('Error inserting data: ' + err.stack);
    return;
  }
  console.log('Data inserted successfully:', result);
});
```

In this example:
- `users` is the table name.
- `name` and `email` are the column names.
- The `VALUES` clause contains the data to be inserted, which is provided as an array (`['John Doe', 'john.doe@example.com']`).
- The `?` placeholders are used to safely insert data and avoid SQL injection.

---

### **4. Insert Multiple Rows**

To insert multiple rows of data at once, you can pass an array of arrays to the `query()` method.

#### **Example: Inserting Multiple Rows**

```javascript
// SQL query to insert multiple rows
const insertQuery = 'INSERT INTO users (name, email) VALUES ?';

// Data to insert (an array of arrays)
const values = [
  ['Alice Smith', 'alice.smith@example.com'],
  ['Bob Johnson', 'bob.johnson@example.com'],
  ['Charlie Brown', 'charlie.brown@example.com']
];

// Execute the query to insert multiple rows
connection.query(insertQuery, [values], (err, result) => {
  if (err) {
    console.error('Error inserting data: ' + err.stack);
    return;
  }
  console.log('Multiple rows inserted successfully:', result);
});
```

In this case, the `VALUES` clause is replaced with a single array containing multiple arrays, each representing a row to be inserted.

---

### **5. Handling Errors**

It’s important to handle errors that may arise during the insertion process. The `mysql` package passes any errors to the callback function, which you can use to handle exceptions or log errors.

#### **Example: Error Handling**

```javascript
connection.query(insertQuery, values, (err, result) => {
  if (err) {
    console.error('Error inserting data:', err);
    return;
  }
  console.log('Data inserted successfully:', result);
});
```

---

### **6. Closing the Connection**

Once the data is inserted, always remember to close the connection to the MySQL server.

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

### **Full Example: Insert Data into MySQL**

Here is a complete example of inserting a single row and multiple rows into a MySQL table using Node.js:

```javascript
// Import the mysql package
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

  // SQL query to insert a single row
  const insertQuery = 'INSERT INTO users (name, email) VALUES (?, ?)';
  const values = ['John Doe', 'john.doe@example.com'];

  // Insert the single row
  connection.query(insertQuery, values, (err, result) => {
    if (err) {
      console.error('Error inserting data: ' + err.stack);
      return;
    }
    console.log('Single row inserted successfully:', result);

    // SQL query to insert multiple rows
    const insertMultipleQuery = 'INSERT INTO users (name, email) VALUES ?';
    const multipleValues = [
      ['Alice Smith', 'alice.smith@example.com'],
      ['Bob Johnson', 'bob.johnson@example.com'],
      ['Charlie Brown', 'charlie.brown@example.com']
    ];

    // Insert multiple rows
    connection.query(insertMultipleQuery, [multipleValues], (err, result) => {
      if (err) {
        console.error('Error inserting multiple rows: ' + err.stack);
        return;
      }
      console.log('Multiple rows inserted successfully:', result);

      // Close the connection after all queries
      connection.end();
    });
  });
});
```

---

### **7. Using Promises with `mysql2` (Optional)**

If you prefer using promises or `async/await`, the `mysql2` package supports this. Here’s how you can insert data using promises:

1. Install `mysql2`:

```bash
npm install mysql2
```

2. Example using `mysql2` with Promises:

```javascript
const mysql = require('mysql2');

// Create a connection to MySQL
const connection = mysql.createConnection({
  host: 'localhost',
  user: 'root',
  password: '',
  database: 'my_database'
});

// SQL query to insert a single row
const insertQuery = 'INSERT INTO users (name, email) VALUES (?, ?)';
const values = ['John Doe', 'john.doe@example.com'];

// Use Promises with mysql2 to insert data
connection.promise().query(insertQuery, values)
  .then(([rows, fields]) => {
    console.log('Single row inserted successfully:', rows);

    // SQL query to insert multiple rows
    const insertMultipleQuery = 'INSERT INTO users (name, email) VALUES ?';
    const multipleValues = [
      ['Alice Smith', 'alice.smith@example.com'],
      ['Bob Johnson', 'bob.johnson@example.com'],
      ['Charlie Brown', 'charlie.brown@example.com']
    ];

    return connection.promise().query(insertMultipleQuery, [multipleValues]);
  })
  .then(([rows, fields]) => {
    console.log('Multiple rows inserted successfully:', rows);
  })
  .catch((err) => {
    console.error('Error inserting data:', err);
  })
  .finally(() => {
    // Close the connection
    connection.end();
  });
```

---

### **Conclusion**

To insert data into a MySQL table using Node.js, you:

1. Install the `mysql` (or `mysql2`) package.
2. Connect to the MySQL database.
3. Use the `INSERT INTO` query to insert data.
4. Handle errors properly to avoid crashes.
5. Optionally, you can use Promises with `mysql2` for a cleaner async/await approach.

By following these steps, you can efficiently insert both single and multiple rows into MySQL tables.
