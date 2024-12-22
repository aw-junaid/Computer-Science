### **Node.js - MySQL UPDATE**

The `UPDATE` statement in MySQL is used to modify existing records in a table. You can update one or more columns of a table based on a specified condition. In Node.js, you can execute `UPDATE` queries using the `mysql` (or `mysql2`) package.

### **1. Install the `mysql` Package**

If you haven't already installed the `mysql` package, you can install it using npm:

```bash
npm install mysql
```

Alternatively, for Promises support, you can install `mysql2`:

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

### **3. Using `UPDATE` to Modify Records**

The `UPDATE` statement allows you to modify one or more columns in a table. The basic syntax is as follows:

```sql
UPDATE table_name
SET column1 = value1, column2 = value2, ...
WHERE condition;
```

In Node.js, you can use the `mysql` package to run `UPDATE` queries.

#### **Example: Updating a Single Record**

Here’s an example of updating a specific user’s `name` where the `id` is 5.

```javascript
// SQL query to update the name of the user with id 5
const updateQuery = 'UPDATE users SET name = ? WHERE id = ?';
const newName = 'John Doe';
const userId = 5;

// Execute the query
connection.query(updateQuery, [newName, userId], (err, result) => {
  if (err) {
    console.error('Error updating data: ' + err.stack);
    return;
  }
  console.log(`${result.affectedRows} record(s) updated.`);
});
```

In this example:
- The query `UPDATE users SET name = ? WHERE id = ?` updates the `name` column of the `users` table where the `id` is 5.
- The `result.affectedRows` will give the number of records that were updated.

---

### **4. Updating Multiple Records**

You can update multiple records at once by using a condition that matches more than one row.

#### **Example: Updating Multiple Records**

Here’s an example of updating multiple users’ `status` to `'inactive'` where the `age` is less than 30.

```javascript
// SQL query to update status of users with age less than 30
const updateQuery = 'UPDATE users SET status = ? WHERE age < ?';
const newStatus = 'inactive';
const ageLimit = 30;

// Execute the query
connection.query(updateQuery, [newStatus, ageLimit], (err, result) => {
  if (err) {
    console.error('Error updating data: ' + err.stack);
    return;
  }
  console.log(`${result.affectedRows} record(s) updated.`);
});
```

In this example:
- The query updates the `status` column for all users whose `age` is less than 30.

---

### **5. Updating Multiple Columns in a Single Query**

You can update multiple columns of a record in a single query.

#### **Example: Updating Multiple Columns**

Here’s an example of updating both `name` and `age` for a user with `id` 5.

```javascript
// SQL query to update multiple columns for user with id 5
const updateQuery = 'UPDATE users SET name = ?, age = ? WHERE id = ?';
const newName = 'Alice Johnson';
const newAge = 28;
const userId = 5;

// Execute the query
connection.query(updateQuery, [newName, newAge, userId], (err, result) => {
  if (err) {
    console.error('Error updating data: ' + err.stack);
    return;
  }
  console.log(`${result.affectedRows} record(s) updated.`);
});
```

In this example:
- The `name` and `age` columns are updated for the user with `id` 5.

---

### **6. Using `UPDATE` with `LIMIT`**

If you want to limit the number of records to be updated, you can use the `LIMIT` clause. This is helpful when you only want to update a certain number of records.

#### **Example: Using `LIMIT`**

Here’s an example of updating the `status` for only the first 3 users with `age` less than 30:

```javascript
// SQL query to update status of the first 3 users with age less than 30
const updateQuery = 'UPDATE users SET status = ? WHERE age < ? LIMIT ?';
const newStatus = 'inactive';
const ageLimit = 30;
const limit = 3;

// Execute the query
connection.query(updateQuery, [newStatus, ageLimit, limit], (err, result) => {
  if (err) {
    console.error('Error updating data: ' + err.stack);
    return;
  }
  console.log(`${result.affectedRows} record(s) updated.`);
});
```

In this example:
- The query updates the `status` of the first 3 users with `age` less than 30.

---

### **7. Using `UPDATE` with `JOIN`**

You can use a `JOIN` operation in an `UPDATE` query to update records in one table based on conditions in another table.

#### **Example: Using `UPDATE` with `JOIN`**

Suppose you have two tables, `users` and `orders`, and you want to update the `status` of users who have placed an order in the last 30 days. Here’s an example using `JOIN`:

```javascript
// SQL query to update status for users who placed an order in the last 30 days
const updateQuery = `
  UPDATE users u
  JOIN orders o ON u.id = o.user_id
  SET u.status = ?
  WHERE o.order_date > DATE_SUB(NOW(), INTERVAL 30 DAY)
`;

const newStatus = 'active';

// Execute the query
connection.query(updateQuery, [newStatus], (err, result) => {
  if (err) {
    console.error('Error updating data: ' + err.stack);
    return;
  }
  console.log(`${result.affectedRows} record(s) updated.`);
});
```

In this example:
- The query updates the `status` of users in the `users` table who have placed an order in the last 30 days.

---

### **8. Closing the Connection**

After executing the `UPDATE` query, always close the connection.

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

### **Full Example: Updating Records in Node.js**

Here’s a complete example that connects to the MySQL database, runs an `UPDATE` query, and then closes the connection.

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

  // SQL query to update user status
  const updateQuery = 'UPDATE users SET status = ? WHERE age < ?';
  const newStatus = 'inactive';
  const ageLimit = 30;

  // Execute the query
  connection.query(updateQuery, [newStatus, ageLimit], (err, result) => {
    if (err) {
      console.error('Error updating data: ' + err.stack);
      return;
    }
    console.log(`${result.affectedRows} record(s) updated.`);

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

The `UPDATE` statement in MySQL allows you to modify existing records in a table based on certain conditions. In Node.js, you can use the `mysql` (or `mysql2`) package to execute `UPDATE` queries efficiently. Key points:
- Use the `WHERE` clause to specify which records to update.
- You can update multiple columns at once.
- You can also use `LIMIT` to restrict the number of rows updated.
- The `JOIN` operation can be used in `UPDATE` queries to update rows in one table based on conditions in another table.

By understanding how to use `UPDATE`, you can efficiently modify records in your MySQL database using Node.js.
