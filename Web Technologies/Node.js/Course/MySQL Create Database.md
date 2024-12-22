### **Node.js - MySQL Create Database**

In Node.js, to create a MySQL database, you can use the `mysql` or `mysql2` package. The process is fairly simple, and involves connecting to the MySQL server, and executing a query to create a new database.

Here’s a step-by-step guide to create a database in MySQL using Node.js:

---

### **1. Install the `mysql` Package**

If you haven’t installed the `mysql` package yet, you can install it via npm. This package allows you to interact with the MySQL server.

```bash
npm install mysql
```

Alternatively, you can use `mysql2`, which supports promises and prepared statements:

```bash
npm install mysql2
```

For this guide, we will use the `mysql` package, but you can follow a similar approach with `mysql2`.

---

### **2. Connect to MySQL Server**

To create a database, first, you need to establish a connection with the MySQL server. 

Here's an example:

```javascript
// Import the mysql package
const mysql = require('mysql');

// Create a connection to MySQL server (not specifying a database yet)
const connection = mysql.createConnection({
  host: 'localhost',    // MySQL server host
  user: 'root',         // MySQL username
  password: '',         // MySQL password (empty if no password is set)
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

### **3. Create a Database**

Once you're connected to the MySQL server, you can execute a query to create a new database. Here’s an example of creating a database named `my_database`:

```javascript
const createDatabaseQuery = 'CREATE DATABASE my_database';

// Execute the query to create the database
connection.query(createDatabaseQuery, (err, result) => {
  if (err) {
    console.error('Error creating database: ' + err.stack);
    return;
  }
  console.log('Database created successfully:', result);
});
```

This query will create a new database named `my_database` on the MySQL server.

---

### **4. Close the Connection**

After executing the query, always remember to close the connection to the MySQL server.

```javascript
// Close the connection
connection.end((err) => {
  if (err) {
    console.error('Error ending connection:', err);
  } else {
    console.log('Connection closed.');
  }
});
```

---

### **Full Example: Create Database in MySQL**

Here is the complete example of creating a MySQL database in Node.js:

```javascript
// Import the mysql package
const mysql = require('mysql');

// Create a connection to MySQL server (without specifying a database)
const connection = mysql.createConnection({
  host: 'localhost',    // MySQL server host
  user: 'root',         // MySQL username
  password: '',         // MySQL password (empty if no password is set)
});

// Connect to the MySQL server
connection.connect((err) => {
  if (err) {
    console.error('Error connecting: ' + err.stack);
    return;
  }
  console.log('Connected as id ' + connection.threadId);

  // Create a database named "my_database"
  const createDatabaseQuery = 'CREATE DATABASE my_database';

  // Execute the query to create the database
  connection.query(createDatabaseQuery, (err, result) => {
    if (err) {
      console.error('Error creating database: ' + err.stack);
      return;
    }
    console.log('Database created successfully:', result);

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

### **5. Using Promises (Optional)**

If you prefer using **Promises**, you can switch to using the `mysql2` package. Here's an example of creating a database using `mysql2`:

1. Install `mysql2`:

```bash
npm install mysql2
```

2. Code to create a database using promises:

```javascript
const mysql = require('mysql2');

// Create a connection to MySQL server (without specifying a database)
const connection = mysql.createConnection({
  host: 'localhost',
  user: 'root',
  password: ''
});

// Create a Promise-based connection
connection.promise().query('CREATE DATABASE my_database')
  .then(([rows, fields]) => {
    console.log('Database created successfully:', rows);
  })
  .catch((err) => {
    console.error('Error creating database:', err);
  })
  .finally(() => {
    // Close the connection
    connection.end();
  });
```

---

### **Conclusion**

To create a MySQL database using Node.js, you first need to connect to the MySQL server using the `mysql` (or `mysql2`) package. After establishing a connection, you can execute a `CREATE DATABASE` query to create a new database.

Always handle errors gracefully and ensure you close the connection to the MySQL server once your operations are complete. If you prefer Promises, you can use the `mysql2` package to work with async/await or `.then()` and `.catch()` methods.
