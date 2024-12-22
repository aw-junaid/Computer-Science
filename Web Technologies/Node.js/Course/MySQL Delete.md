### **Node.js - MySQL DELETE**

The `DELETE` statement in MySQL is used to remove records from a table. You can delete one or more rows based on a specific condition. In Node.js, you can interact with MySQL databases and execute a `DELETE` query using the `mysql` (or `mysql2`) package.

### **1. Install the `mysql` Package**

If you haven't already installed the `mysql` package, you can install it using npm:

```bash
npm install mysql
```

For promises support, you can use `mysql2`:

```bash
npm install mysql2
```

---

### **2. Connect to MySQL Database**

Before running any queries, you need to establish a connection to your MySQL database.

#### **Example: Connecting to MySQL**

```javascript
const mysql = require('mysql');

// Create a connection to MySQL
const connection = mysql.createConnection({
  host: 'localhost',       // MySQL host
  user: 'root',            // MySQL username
  password: '',            // MySQL password
  database: 'my_database'  // Database to query
});

// Connect to MySQL
connection.connect((err) => {
  if (err) {
    console.error('Error connecting to database: ' + err.stack);
    return;
  }
  console.log('Connected as id ' + connection.threadId);
});
```

---

### **3. Using `DELETE` to Remove Records**

The `DELETE` query removes records from the specified table. You should always use a `WHERE` clause to specify the condition for the deletion to avoid removing all records in the table.

#### **Example: Deleting a Single Record**

Here’s an example of deleting a single record from the `users` table where the `id` is 5:

```javascript
// SQL query to delete a user with id 5
const deleteQuery = 'DELETE FROM users WHERE id = ?';
const userId = 5;

// Execute the query
connection.query(deleteQuery, [userId], (err, result) => {
  if (err) {
    console.error('Error deleting data: ' + err.stack);
    return;
  }
  console.log(`Record deleted: ${result.affectedRows} row(s)`);
});
```

In this example:
- The `DELETE FROM users WHERE id = ?` query deletes the user with `id` 5.
- `result.affectedRows` will tell you how many rows were deleted.

---

### **4. Deleting Multiple Records**

If you want to delete multiple records based on a condition, you can specify the condition accordingly. Here is an example where users older than 60 are deleted:

#### **Example: Deleting Multiple Records**

```javascript
// SQL query to delete users older than 60
const deleteQuery = 'DELETE FROM users WHERE age > ?';
const age = 60;

// Execute the query
connection.query(deleteQuery, [age], (err, result) => {
  if (err) {
    console.error('Error deleting data: ' + err.stack);
    return;
  }
  console.log(`${result.affectedRows} records deleted.`);
});
```

In this example:
- The query deletes all users whose age is greater than 60.

---

### **5. Deleting All Records (No Condition)**

If you want to delete **all** records from a table without deleting the table itself, you can omit the `WHERE` clause. However, use this with caution as it will remove all data from the table.

#### **Example: Deleting All Records**

```javascript
// SQL query to delete all users
const deleteQuery = 'DELETE FROM users';

// Execute the query
connection.query(deleteQuery, (err, result) => {
  if (err) {
    console.error('Error deleting data: ' + err.stack);
    return;
  }
  console.log(`All records deleted: ${result.affectedRows} row(s)`);
});
```

In this example:
- The query deletes all users in the `users` table.

---

### **6. Using `DELETE` with `LIMIT`**

If you want to delete only a certain number of records, you can use the `LIMIT` clause. This is useful when you want to delete only a subset of rows.

#### **Example: Deleting a Limited Number of Records**

```javascript
// SQL query to delete up to 5 users with age greater than 30
const deleteQuery = 'DELETE FROM users WHERE age > ? LIMIT ?';
const age = 30;
const limit = 5;

// Execute the query
connection.query(deleteQuery, [age, limit], (err, result) => {
  if (err) {
    console.error('Error deleting data: ' + err.stack);
    return;
  }
  console.log(`${result.affectedRows} records deleted.`);
});
```

In this example:
- The query deletes up to 5 users whose age is greater than 30.

---

### **7. Using `DELETE` with `JOIN`**

You can also use a `JOIN` operation in a `DELETE` query if you need to delete rows from one table based on conditions in another table.

#### **Example: Deleting Records with `JOIN`**

Let’s say you have two tables, `users` and `orders`, and you want to delete users who haven’t placed any orders.

```javascript
// SQL query to delete users who don't have any orders
const deleteQuery = `
  DELETE u
  FROM users u
  LEFT JOIN orders o ON u.id = o.user_id
  WHERE o.user_id IS NULL
`;

connection.query(deleteQuery, (err, result) => {
  if (err) {
    console.error('Error deleting data: ' + err.stack);
    return;
  }
  console.log(`${result.affectedRows} records deleted.`);
});
```

In this example:
- The `LEFT JOIN` is used to find users who do not have any associated orders (`WHERE o.user_id IS NULL`), and those users are deleted.

---

### **8. Closing the Connection**

After executing your `DELETE` query, you should close the connection to the database.

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

### **Full Example: Deleting Records in Node.js**

Here’s a complete example of connecting to the database, executing a `DELETE` query, and closing the connection afterward.

```javascript
const mysql = require('mysql');

// Create a connection to MySQL
const connection = mysql.createConnection({
  host: 'localhost',
  user: 'root',
  password: '',
  database: 'my_database'
});

// Connect to MySQL
connection.connect((err) => {
  if (err) {
    console.error('Error connecting to database: ' + err.stack);
    return;
  }
  console.log('Connected as id ' + connection.threadId);

  // SQL query to delete users older than 60
  const deleteQuery = 'DELETE FROM users WHERE age > ?';
  const age = 60;

  // Execute the query
  connection.query(deleteQuery, [age], (err, result) => {
    if (err) {
      console.error('Error deleting data: ' + err.stack);
      return;
    }
    console.log(`${result.affectedRows} records deleted.`);

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

In Node.js, you can use the `mysql` (or `mysql2`) package to execute `DELETE` queries to remove records from a table based on certain conditions. Key points to remember when using `DELETE`:
- Always use a `WHERE` clause to specify the rows to delete, unless you want to delete all records in the table.
- The `LIMIT` clause can be used to restrict the number of records deleted.
- Be cautious when using `DELETE` as it permanently removes data.
- Always close the connection once your operations are complete.

By understanding these techniques, you can safely and efficiently manage data deletion in MySQL using Node.js.
