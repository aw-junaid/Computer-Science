In Java JDBC, **PreparedStatement** and **CallableStatement** are interfaces used to execute SQL queries. They provide additional functionality and security compared to the basic `Statement` interface. Below is a detailed explanation of both, along with examples.

---

### **1. PreparedStatement**

`PreparedStatement` is used to execute **parameterized SQL queries**. It precompiles the SQL query, which improves performance and prevents SQL injection attacks.

#### **Advantages of PreparedStatement**
1. **Performance**: The SQL query is precompiled, so it executes faster for repeated queries.
2. **Security**: Prevents SQL injection by automatically escaping special characters.
3. **Readability**: Makes the code cleaner by separating SQL logic from data.

#### **Example: Using PreparedStatement**

```java
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class PreparedStatementExample {
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

### **2. CallableStatement**

`CallableStatement` is used to execute **stored procedures** in the database. Stored procedures are precompiled SQL code stored in the database.

#### **Advantages of CallableStatement**
1. **Reusability**: Stored procedures can be reused across multiple applications.
2. **Performance**: Stored procedures are precompiled and executed on the database server.
3. **Security**: Reduces the risk of SQL injection.

#### **Example: Using CallableStatement**

```java
import java.sql.CallableStatement;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class CallableStatementExample {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/mydatabase";
        String username = "root";
        String password = "password";

        try (Connection connection = DriverManager.getConnection(url, username, password)) {
            System.out.println("Connected to the database.");

            // SQL to call a stored procedure
            String sql = "{CALL get_user_email(?, ?)}";

            // Create a CallableStatement
            try (CallableStatement callableStatement = connection.prepareCall(sql)) {
                // Set input parameter
                callableStatement.setInt(1, 1);

                // Register output parameter
                callableStatement.registerOutParameter(2, java.sql.Types.VARCHAR);

                // Execute the stored procedure
                callableStatement.execute();

                // Get the output parameter value
                String email = callableStatement.getString(2);
                System.out.println("User Email: " + email);
            }
        } catch (SQLException e) {
            System.out.println("Connection failed.");
            e.printStackTrace();
        }
    }
}
```

---

### **Key Differences Between PreparedStatement and CallableStatement**

| Feature               | PreparedStatement                     | CallableStatement                     |
|-----------------------|---------------------------------------|---------------------------------------|
| **Purpose**           | Executes parameterized SQL queries.   | Executes stored procedures.           |
| **Performance**       | Precompiled for repeated queries.     | Precompiled and executed on the server. |
| **Use Case**          | INSERT, UPDATE, DELETE, SELECT.       | Stored procedures with input/output parameters. |
| **Security**          | Prevents SQL injection.               | Reduces SQL injection risk.           |

---

### **Best Practices**

1. **Use PreparedStatement for Parameterized Queries**:
   - Always use `PreparedStatement` for queries with user input to prevent SQL injection.

2. **Use CallableStatement for Stored Procedures**:
   - Use `CallableStatement` to execute stored procedures for better performance and reusability.

3. **Close Resources**:
   - Use try-with-resources or explicitly close `PreparedStatement` and `CallableStatement`.

4. **Handle Exceptions**:
   - Always handle `SQLException` to manage database errors.

5. **Use Connection Pooling**:
   - Use libraries like HikariCP or Apache DBCP for better performance.

---

### **Example: Combining PreparedStatement and CallableStatement**

```java
import java.sql.CallableStatement;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class CombinedExample {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/mydatabase";
        String username = "root";
        String password = "password";

        try (Connection connection = DriverManager.getConnection(url, username, password)) {
            System.out.println("Connected to the database.");

            // Example 1: Using PreparedStatement
            String sql1 = "SELECT id, name, email FROM users WHERE id = ?";
            try (PreparedStatement preparedStatement = connection.prepareStatement(sql1)) {
                preparedStatement.setInt(1, 1);

                ResultSet resultSet = preparedStatement.executeQuery();
                while (resultSet.next()) {
                    int id = resultSet.getInt("id");
                    String name = resultSet.getString("name");
                    String email = resultSet.getString("email");
                    System.out.println("ID: " + id + ", Name: " + name + ", Email: " + email);
                }
            }

            // Example 2: Using CallableStatement
            String sql2 = "{CALL get_user_email(?, ?)}";
            try (CallableStatement callableStatement = connection.prepareCall(sql2)) {
                callableStatement.setInt(1, 1);
                callableStatement.registerOutParameter(2, java.sql.Types.VARCHAR);
                callableStatement.execute();

                String email = callableStatement.getString(2);
                System.out.println("User Email: " + email);
            }
        } catch (SQLException e) {
            System.out.println("Connection failed.");
            e.printStackTrace();
        }
    }
}
```

---

By using `PreparedStatement` and `CallableStatement`, you can write secure, efficient, and maintainable database code in Java.
