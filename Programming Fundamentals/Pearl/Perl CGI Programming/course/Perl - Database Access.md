### Perl - Database Access

Perl provides efficient ways to connect to and interact with databases through the **DBI (Database Interface)** module, which is a database-independent interface for Perl. The DBI module, combined with a specific DBD (Database Driver) module, allows Perl to interact with various databases like MySQL, PostgreSQL, SQLite, Oracle, and others.

---

### 1. **Installing DBI and DBD Modules**

To access databases, you need to install `DBI` and a corresponding `DBD` module (e.g., `DBD::mysql` for MySQL, `DBD::Pg` for PostgreSQL).

```shell
cpan DBI            # Install DBI module
cpan DBD::mysql      # Install MySQL driver, change to DBD::Pg or DBD::SQLite if needed
```

---

### 2. **Connecting to a Database**

The `DBI->connect` method is used to establish a database connection. It returns a database handle (or connection object) that is used for executing queries.

#### Example: Connect to a MySQL Database

```perl
use strict;
use warnings;
use DBI;

my $dsn = "DBI:mysql:database=your_database;host=localhost";
my $username = "your_username";
my $password = "your_password";

# Connect to the database
my $dbh = DBI->connect($dsn, $username, $password, { RaiseError => 1, AutoCommit => 1 })
    or die "Could not connect to database: $DBI::errstr";

print "Connected to the database successfully!\n";

# Disconnect
$dbh->disconnect();
```

Here:
- `DBI:mysql:database=your_database;host=localhost` is the **DSN** (Data Source Name), which specifies the database type, name, and host.
- `RaiseError => 1` automatically throws an error on query failure.
- `AutoCommit => 1` ensures that each statement is automatically committed.

---

### 3. **Executing Queries**

The `DBI` module allows execution of SQL queries using `prepare` and `execute`. These queries can be:
- **SELECT** queries (for fetching data)
- **INSERT, UPDATE, DELETE** queries (for modifying data)

#### Example: SELECT Query

```perl
# Prepare and execute a query
my $sth = $dbh->prepare("SELECT id, name FROM employees") or die "Prepare failed: $DBI::errstr";
$sth->execute() or die "Execute failed: $DBI::errstr";

# Fetch and print results
while (my @row = $sth->fetchrow_array) {
    print "ID: $row[0], Name: $row[1]\n";
}

# Finish the statement handle
$sth->finish();
```

Here:
- `$sth->prepare` prepares the SQL statement.
- `$sth->execute` executes it.
- `$sth->fetchrow_array` retrieves each row as an array.

---

### 4. **Using Placeholders for Security**

Placeholders (`?`) in SQL queries help prevent SQL injection attacks by binding variables safely.

#### Example: SELECT Query with Placeholders

```perl
my $sth = $dbh->prepare("SELECT id, name FROM employees WHERE id = ?") or die "Prepare failed: $DBI::errstr";
$sth->execute(1) or die "Execute failed: $DBI::errstr";

while (my @row = $sth->fetchrow_array) {
    print "ID: $row[0], Name: $row[1]\n";
}
$sth->finish();
```

---

### 5. **Inserting Data**

Use `execute` to pass values directly to the placeholders, which bind them securely.

#### Example: INSERT Query

```perl
my $sth = $dbh->prepare("INSERT INTO employees (name, age) VALUES (?, ?)") or die "Prepare failed: $DBI::errstr";
$sth->execute("Alice", 30) or die "Execute failed: $DBI::errstr";
print "Record inserted successfully.\n";
$sth->finish();
```

---

### 6. **Updating and Deleting Data**

Updating and deleting records follow a similar syntax to the `INSERT` example.

#### Example: UPDATE Query

```perl
my $sth = $dbh->prepare("UPDATE employees SET age = ? WHERE name = ?") or die "Prepare failed: $DBI::errstr";
$sth->execute(31, "Alice") or die "Execute failed: $DBI::errstr";
print "Record updated successfully.\n";
$sth->finish();
```

#### Example: DELETE Query

```perl
my $sth = $dbh->prepare("DELETE FROM employees WHERE name = ?") or die "Prepare failed: $DBI::errstr";
$sth->execute("Alice") or die "Execute failed: $DBI::errstr";
print "Record deleted successfully.\n";
$sth->finish();
```

---

### 7. **Fetching Data**

There are multiple methods for retrieving data:

- `fetchrow_array`: Retrieves one row as an array.
- `fetchrow_arrayref`: Retrieves one row as an array reference.
- `fetchrow_hashref`: Retrieves one row as a hash reference, with column names as keys.

#### Example: Fetching Data as Hash References

```perl
my $sth = $dbh->prepare("SELECT id, name FROM employees") or die "Prepare failed: $DBI::errstr";
$sth->execute() or die "Execute failed: $DBI::errstr";

while (my $row = $sth->fetchrow_hashref) {
    print "ID: $row->{id}, Name: $row->{name}\n";
}

$sth->finish();
```

---

### 8. **Transactions**

Transactions in DBI can be managed manually using `AutoCommit => 0` to begin a transaction, followed by `commit` or `rollback` to finalize or undo the transaction.

#### Example: Transaction Management

```perl
# Disable AutoCommit to begin a transaction
$dbh->{AutoCommit} = 0;

eval {
    $dbh->do("INSERT INTO employees (name, age) VALUES ('Bob', 28)");
    $dbh->do("UPDATE employees SET age = 29 WHERE name = 'Bob'");
    
    # Commit transaction
    $dbh->commit();
    print "Transaction committed successfully.\n";
};

if ($@) {
    print "Transaction aborted due to error: $@\n";
    $dbh->rollback();
}
```

Here:
- `AutoCommit => 0` disables automatic commit.
- `$dbh->commit()` commits the transaction.
- `$dbh->rollback()` rolls back if any part of the transaction fails.

---

### 9. **Disconnecting from the Database**

Always disconnect from the database after completing your operations to free up resources.

```perl
$dbh->disconnect();
```

---

### Summary of DBI Key Methods

| **DBI Method**               | **Description**                                                          |
|------------------------------|--------------------------------------------------------------------------|
| `DBI->connect`               | Connects to the database and returns a database handle (DBH).           |
| `$dbh->prepare`              | Prepares an SQL statement.                                               |
| `$sth->execute`              | Executes a prepared statement.                                           |
| `$sth->fetchrow_array`       | Fetches one row as an array.                                             |
| `$sth->fetchrow_hashref`     | Fetches one row as a hash reference.                                     |
| `$dbh->commit`               | Commits the current transaction.                                         |
| `$dbh->rollback`             | Rolls back the current transaction.                                      |
| `$dbh->disconnect`           | Disconnects from the database.                                           |

---

### Conclusion

Using Perl's DBI module, you can connect to, query, and manage databases effectively. By leveraging placeholders and transaction management, DBI ensures secure and efficient database access, making Perl a powerful choice for database-driven applications.
