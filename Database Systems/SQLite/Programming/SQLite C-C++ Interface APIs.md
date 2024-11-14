### SQLite C/C++ Interface APIs

SQLite provides a set of C APIs to interact with databases, allowing developers to integrate SQLite databases into C or C++ applications. The C API is straightforward and is commonly used in applications where performance and low-level control over database interactions are required.

Here is a quick overview of how to use the SQLite C API to perform basic database operations like connecting to a database, creating tables, and performing CRUD operations (Insert, Select, Update, Delete).

---

### 1. **Connecting to a Database**

To connect to an SQLite database in C or C++, you need to include the SQLite header file and use the `sqlite3_open()` function. This function opens the database file if it exists, or creates a new one if it doesn't.

```c
#include <sqlite3.h>
#include <stdio.h>

int main() {
    sqlite3 *db;
    int rc;

    // Open (or create) the SQLite database file
    rc = sqlite3_open("test.db", &db);
    if (rc) {
        printf("Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        printf("Opened database successfully\n");
    }

    sqlite3_close(db);  // Close the database connection
    return 0;
}
```

- `sqlite3_open()` opens the database. If the database does not exist, SQLite will create a new one.
- `sqlite3_close()` closes the database connection.

---

### 2. **Creating a Table**

Once you are connected to the database, you can create tables using SQL commands. The `sqlite3_exec()` function is used to execute SQL queries.

```c
#include <sqlite3.h>
#include <stdio.h>

int main() {
    sqlite3 *db;
    char *errMsg = 0;
    int rc;

    rc = sqlite3_open("test.db", &db);
    if (rc) {
        printf("Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        printf("Opened database successfully\n");
    }

    // SQL query to create a table
    const char *sql = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT, age INTEGER);";

    // Execute the SQL query
    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Table created successfully\n");
    }

    sqlite3_close(db);  // Close the database connection
    return 0;
}
```

- `sqlite3_exec()` executes the SQL statement. If there's an error, the error message is stored in `errMsg`.

---

### 3. **INSERT Operation**

To insert data into a table, you can use the `sqlite3_exec()` function again, or use prepared statements (`sqlite3_prepare_v2()`).

#### **Example: Using `sqlite3_exec()` for Insert**

```c
#include <sqlite3.h>
#include <stdio.h>

int main() {
    sqlite3 *db;
    char *errMsg = 0;
    int rc;

    rc = sqlite3_open("test.db", &db);
    if (rc) {
        printf("Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    } else {
        printf("Opened database successfully\n");
    }

    // SQL query to insert data into the users table
    const char *sql = "INSERT INTO users (name, age) VALUES ('John Doe', 30);";

    // Execute the SQL query
    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Records inserted successfully\n");
    }

    sqlite3_close(db);  // Close the database connection
    return 0;
}
```

#### **Example: Using Prepared Statements for Insert**

```c
#include <sqlite3.h>
#include <stdio.h>

int main() {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int rc;

    rc = sqlite3_open("test.db", &db);
    if (rc) {
        printf("Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    }

    // SQL query to prepare for insertion
    const char *sql = "INSERT INTO users (name, age) VALUES (?, ?);";

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        printf("Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return 0;
    }

    // Bind values to the placeholders
    sqlite3_bind_text(stmt, 1, "Jane Doe", -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, 25);

    // Execute the prepared statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        printf("Execution failed: %s\n", sqlite3_errmsg(db));
    } else {
        printf("Record inserted successfully\n");
    }

    sqlite3_finalize(stmt);  // Finalize the prepared statement
    sqlite3_close(db);  // Close the database connection
    return 0;
}
```

---

### 4. **SELECT Operation**

To retrieve data from the database, the `sqlite3_prepare_v2()` function is used to prepare the SELECT query, and `sqlite3_step()` is used to execute it. The results are fetched one row at a time using `sqlite3_column_*()` functions.

```c
#include <sqlite3.h>
#include <stdio.h>

int main() {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int rc;

    rc = sqlite3_open("test.db", &db);
    if (rc) {
        printf("Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    }

    // SQL query to select all users
    const char *sql = "SELECT id, name, age FROM users;";

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        printf("Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return 0;
    }

    // Execute the statement and print the results
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char *name = (const char *)sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);

        printf("ID: %d, Name: %s, Age: %d\n", id, name, age);
    }

    sqlite3_finalize(stmt);  // Finalize the statement
    sqlite3_close(db);  // Close the database connection
    return 0;
}
```

---

### 5. **UPDATE Operation**

The update operation modifies existing records in the database. Like the insert operation, you can use prepared statements for this.

```c
#include <sqlite3.h>
#include <stdio.h>

int main() {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int rc;

    rc = sqlite3_open("test.db", &db);
    if (rc) {
        printf("Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    }

    // SQL query to update a user's age
    const char *sql = "UPDATE users SET age = ? WHERE name = ?;";

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        printf("Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return 0;
    }

    // Bind the new age and the name
    sqlite3_bind_int(stmt, 1, 35);
    sqlite3_bind_text(stmt, 2, "John Doe", -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        printf("Execution failed: %s\n", sqlite3_errmsg(db));
    } else {
        printf("Record updated successfully\n");
    }

    sqlite3_finalize(stmt);  // Finalize the statement
    sqlite3_close(db);  // Close the database connection
    return 0;
}
```

---

### 6. **DELETE Operation**

The delete operation removes records from the database based on a condition.

```c
#include <sqlite3.h>
#include <stdio.h>

int main() {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int rc;

    rc = sqlite3_open("test.db", &db);
    if (rc) {
        printf("Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    }

    // SQL query to delete a user
    const char *sql = "DELETE FROM users WHERE name = ?;";

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        printf("Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return 0;
    }

    // Bind the name to the placeholder
    sqlite3_bind_text(stmt, 1, "John Doe", -1, SQLITE_STATIC);

    rc = sqlite3

_step(stmt);
    if (rc != SQLITE_DONE) {
        printf("Execution failed: %s\n", sqlite3_errmsg(db));
    } else {
        printf("Record deleted successfully\n");
    }

    sqlite3_finalize(stmt);  // Finalize the statement
    sqlite3_close(db);  // Close the database connection
    return 0;
}
```

---

### Summary

- **Connect to Database**: `sqlite3_open()`
- **Create a Table**: `sqlite3_exec()`
- **Insert Data**: `sqlite3_exec()` or `sqlite3_prepare_v2()`
- **Select Data**: `sqlite3_prepare_v2()` and `sqlite3_step()`
- **Update Data**: `sqlite3_prepare_v2()` and `sqlite3_step()`
- **Delete Data**: `sqlite3_prepare_v2()` and `sqlite3_step()`

These examples illustrate how to perform common database operations using the SQLite C API. By using prepared statements, you can ensure that your operations are secure and optimized.
