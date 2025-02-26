Executing SQL queries in Java using JDBC involves connecting to a database, creating statements, and executing queries. Below are examples of how to execute common SQL operations like `SELECT`, `INSERT`, `UPDATE`, and `DELETE`.

---

### **1. Executing a `SELECT` Query**

A `SELECT` query retrieves data from the database. Use the `executeQuery()` method to execute the query and process the results using a `ResultSet`.

#### **Example: SELECT Query**
```java
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class SelectExample {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/mydatabase";
        String username = "root";
        String password = "password";

        try (Connection connection = DriverManager.getConnection(url, username, password)) {
            System.out.println("Connected to the database.");

            // Create a statement
            Statement statement = connection.createStatement();

            // Execute a SELECT query
            String sql = "SELECT id, name, email FROM users";
            ResultSet resultSet = statement.executeQuery(sql);

            // Process the ResultSet
            while (resultSet.next()) {
                int id = resultSet.getInt("id");
                String name = resultSet.getString("name");
                String email = resultSet.getString("email");

                System.out.println("ID: " + id + ", Name: " + name + ", Email: " + email);
            }
        } catch (SQLException e) {
            System.out.println("Connection failed.");
            e.printStackTrace();
        }
    }
}
```

---

### **2. Executing an `INSERT` Query**

An `INSERT` query adds new rows to a table. Use the `executeUpdate()` method to execute the query, which returns the number of rows affected.

#### **Example: INSERT Query**
```java
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class InsertExample {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/mydatabase";
        String username = "root";
        String password = "password";

        try (Connection connection = DriverManager.getConnection(url, username, password)) {
            System.out.println("Connected to the database.");

            // SQL query with placeholders
            String sql = "INSERT INTO users (name, email) VALUES (?, ?)";

            // Create a PreparedStatement
            try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
                // Set parameters
                preparedStatement.setString(1, "John Doe");
                preparedStatement.setString(2, "john.doe@example.com");

                // Execute the query
                int rowsInserted = preparedStatement.executeUpdate();
                System.out.println(rowsInserted + " row(s) inserted.");
            }
        } catch (SQLException e) {
            System.out.println("Connection failed.");
            e.printStackTrace();
        }
    }
}
```

---

### **3. Executing an `UPDATE` Query**

An `UPDATE` query modifies existing rows in a table. Use the `executeUpdate()` method to execute the query.

#### **Example: UPDATE Query**
```java
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class UpdateExample {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/mydatabase";
        String username = "root";
        String password = "password";

        try (Connection connection = DriverManager.getConnection(url, username, password)) {
            System.out.println("Connected to the database.");

            // SQL query with placeholders
            String sql = "UPDATE users SET email = ? WHERE id = ?";

            // Create a PreparedStatement
            try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
                // Set parameters
                preparedStatement.setString(1, "john.new@example.com");
                preparedStatement.setInt(2, 1);

                // Execute the query
                int rowsUpdated = preparedStatement.executeUpdate();
                System.out.println(rowsUpdated + " row(s) updated.");
            }
        } catch (SQLException e) {
            System.out.println("Connection failed.");
            e.printStackTrace();
        }
    }
}
```

---

### **4. Executing a `DELETE` Query**

A `DELETE` query removes rows from a table. Use the `executeUpdate()` method to execute the query.

#### **Example: DELETE Query**
```java
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class DeleteExample {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/mydatabase";
        String username = "root";
        String password = "password";

        try (Connection connection = DriverManager.getConnection(url, username, password)) {
            System.out.println("Connected to the database.");

            // SQL query with placeholders
            String sql = "DELETE FROM users WHERE id = ?";

            // Create a PreparedStatement
            try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
                // Set parameters
                preparedStatement.setInt(1, 1);

                // Execute the query
                int rowsDeleted = preparedStatement.executeUpdate();
                System.out.println(rowsDeleted + " row(s) deleted.");
            }
        } catch (SQLException e) {
            System.out.println("Connection failed.");
            e.printStackTrace();
        }
    }
}
```

---

### **Using Transactions**

Transactions ensure that a set of SQL operations are executed atomically (all or nothing). Use the `Connection` object to manage transactions.

#### **Example: Transaction Management**
```java
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class TransactionExample {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/mydatabase";
        String username = "root";
        String password = "password";

        Connection connection = null;
        try {
            connection = DriverManager.getConnection(url, username, password);
            System.out.println("Connected to the database.");

            // Disable auto-commit to start a transaction
            connection.setAutoCommit(false);

            // SQL queries
            String sql1 = "UPDATE accounts SET balance = balance - 100 WHERE id = 1";
            String sql2 = "UPDATE accounts SET balance = balance + 100 WHERE id = 2";

            // Execute the first query
            try (PreparedStatement preparedStatement1 = connection.prepareStatement(sql1)) {
                preparedStatement1.executeUpdate();
            }

            // Execute the second query
            try (PreparedStatement preparedStatement2 = connection.prepareStatement(sql2)) {
                preparedStatement2.executeUpdate();
            }

            // Commit the transaction
            connection.commit();
            System.out.println("Transaction committed.");
        } catch (SQLException e) {
            System.out.println("Transaction failed. Rolling back.");
            if (connection != null) {
                try {
                    connection.rollback(); // Rollback the transaction on failure
                } catch (SQLException ex) {
                    ex.printStackTrace();
                }
            }
            e.printStackTrace();
        } finally {
            // Restore auto-commit and close the connection
            if (connection != null) {
                try {
                    connection.setAutoCommit(true);
                    connection.close();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
```

---

### **Best Practices**

1. **Use PreparedStatement**:
   - Prevents SQL injection and improves performance.

2. **Handle Exceptions**:
   - Always handle `SQLException` to manage database errors.

3. **Close Resources**:
   - Use try-with-resources or explicitly close `Connection`, `Statement`, and `ResultSet`.

4. **Use Transactions**:
   - Group related operations into transactions for consistency.

5. **Connection Pooling**:
   - Use libraries like HikariCP or Apache DBCP for better performance.

---

By following these examples and best practices, you can execute SQL queries in Java efficiently and securely.
