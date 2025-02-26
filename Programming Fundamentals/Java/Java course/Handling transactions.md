Handling transactions in Java JDBC is crucial for ensuring data integrity and consistency when performing multiple database operations. A **transaction** is a set of SQL operations that are executed as a single unit of work. If any operation in the transaction fails, the entire transaction is rolled back, and the database remains unchanged.

---

### **Key Concepts in Transaction Management**

1. **ACID Properties**:
   - **Atomicity**: All operations in a transaction are treated as a single unit.
   - **Consistency**: The database remains in a valid state before and after the transaction.
   - **Isolation**: Transactions are isolated from each other until they are completed.
   - **Durability**: Once a transaction is committed, it is permanently saved.

2. **Transaction States**:
   - **Begin**: Start a new transaction.
   - **Commit**: Save all changes made during the transaction.
   - **Rollback**: Undo all changes made during the transaction.

3. **Auto-Commit Mode**:
   - By default, JDBC operates in auto-commit mode, where each SQL statement is treated as a separate transaction.
   - To manage transactions manually, you must disable auto-commit mode.

---

### **Steps to Handle Transactions**

1. **Disable Auto-Commit Mode**:
   - Use `connection.setAutoCommit(false)` to disable auto-commit.

2. **Execute SQL Operations**:
   - Perform the required SQL operations (e.g., `INSERT`, `UPDATE`, `DELETE`).

3. **Commit the Transaction**:
   - Use `connection.commit()` to save the changes.

4. **Rollback on Failure**:
   - Use `connection.rollback()` to undo changes if an error occurs.

5. **Restore Auto-Commit Mode**:
   - Re-enable auto-commit mode using `connection.setAutoCommit(true)`.

---

### **Example: Transaction Management**

Below is an example of handling transactions in JDBC.

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
            // Step 1: Establish a connection
            connection = DriverManager.getConnection(url, username, password);
            System.out.println("Connected to the database.");

            // Step 2: Disable auto-commit mode
            connection.setAutoCommit(false);
            System.out.println("Auto-commit mode disabled.");

            // Step 3: Execute SQL operations
            String sql1 = "UPDATE accounts SET balance = balance - 100 WHERE id = 1";
            String sql2 = "UPDATE accounts SET balance = balance + 100 WHERE id = 2";

            try (PreparedStatement preparedStatement1 = connection.prepareStatement(sql1);
                 PreparedStatement preparedStatement2 = connection.prepareStatement(sql2)) {

                // Execute the first query
                preparedStatement1.executeUpdate();

                // Execute the second query
                preparedStatement2.executeUpdate();

                // Step 4: Commit the transaction
                connection.commit();
                System.out.println("Transaction committed.");
            }
        } catch (SQLException e) {
            System.out.println("Transaction failed. Rolling back.");

            // Step 5: Rollback the transaction on failure
            if (connection != null) {
                try {
                    connection.rollback();
                } catch (SQLException ex) {
                    ex.printStackTrace();
                }
            }
            e.printStackTrace();
        } finally {
            // Step 6: Restore auto-commit mode and close the connection
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

### **Savepoints**

Savepoints allow you to roll back part of a transaction instead of the entire transaction. You can create a savepoint using `connection.setSavepoint()` and roll back to it using `connection.rollback(savepoint)`.

#### **Example: Using Savepoints**

```java
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Savepoint;

public class SavepointExample {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/mydatabase";
        String username = "root";
        String password = "password";

        Connection connection = null;
        Savepoint savepoint = null;
        try {
            // Step 1: Establish a connection
            connection = DriverManager.getConnection(url, username, password);
            System.out.println("Connected to the database.");

            // Step 2: Disable auto-commit mode
            connection.setAutoCommit(false);
            System.out.println("Auto-commit mode disabled.");

            // Step 3: Execute SQL operations
            String sql1 = "UPDATE accounts SET balance = balance - 100 WHERE id = 1";
            String sql2 = "UPDATE accounts SET balance = balance + 100 WHERE id = 2";

            try (PreparedStatement preparedStatement1 = connection.prepareStatement(sql1);
                 PreparedStatement preparedStatement2 = connection.prepareStatement(sql2)) {

                // Execute the first query
                preparedStatement1.executeUpdate();

                // Create a savepoint
                savepoint = connection.setSavepoint("SAVEPOINT_1");

                // Execute the second query
                preparedStatement2.executeUpdate();

                // Step 4: Commit the transaction
                connection.commit();
                System.out.println("Transaction committed.");
            }
        } catch (SQLException e) {
            System.out.println("Transaction failed. Rolling back to savepoint.");

            // Step 5: Rollback to the savepoint on failure
            if (connection != null && savepoint != null) {
                try {
                    connection.rollback(savepoint);
                    System.out.println("Rolled back to savepoint.");
                } catch (SQLException ex) {
                    ex.printStackTrace();
                }
            }
            e.printStackTrace();
        } finally {
            // Step 6: Restore auto-commit mode and close the connection
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

1. **Disable Auto-Commit Mode**:
   - Always disable auto-commit mode when managing transactions manually.

2. **Use Try-With-Resources**:
   - Use try-with-resources to automatically close resources like `Connection`, `PreparedStatement`, and `ResultSet`.

3. **Handle Exceptions**:
   - Always handle `SQLException` and roll back the transaction on failure.

4. **Use Savepoints**:
   - Use savepoints to roll back part of a transaction instead of the entire transaction.

5. **Test Transactions**:
   - Test your transactions thoroughly to ensure data integrity.

---

By following these steps and best practices, you can effectively manage transactions in Java JDBC and ensure the consistency and reliability of your database operations.
