**JDBC (Java Database Connectivity)** is a Java API that allows Java applications to interact with relational databases. It provides a standard interface for connecting to databases, executing SQL queries, and processing the results. JDBC is part of the Java Standard Edition (SE) and is widely used for database-driven applications.

---

### **Key Components of JDBC**

1. **JDBC Driver**:
   - A JDBC driver is a software component that enables Java applications to interact with a specific database.
   - Types of JDBC drivers:
     - **Type 1**: JDBC-ODBC Bridge (deprecated).
     - **Type 2**: Native-API driver.
     - **Type 3**: Network Protocol driver.
     - **Type 4**: Thin driver (pure Java, most commonly used).

2. **Connection**:
   - Represents a connection to the database.
   - Created using the `DriverManager` or a `DataSource`.

3. **Statement**:
   - Used to execute SQL queries.
   - Types:
     - `Statement`: For static SQL queries.
     - `PreparedStatement`: For parameterized SQL queries.
     - `CallableStatement`: For stored procedures.

4. **ResultSet**:
   - Represents the result of a query.
   - Allows you to iterate through the rows and access column values.

5. **SQLException**:
   - A checked exception that handles database-related errors.

---

### **Steps to Use JDBC**

1. **Load the JDBC Driver**:
   - Register the JDBC driver with the `DriverManager`.

2. **Establish a Connection**:
   - Use the `DriverManager.getConnection()` method to connect to the database.

3. **Create a Statement**:
   - Create a `Statement`, `PreparedStatement`, or `CallableStatement` object.

4. **Execute a Query**:
   - Use the `executeQuery()` method for SELECT queries or `executeUpdate()` for INSERT, UPDATE, DELETE queries.

5. **Process the ResultSet**:
   - Iterate through the `ResultSet` to retrieve data.

6. **Close Resources**:
   - Close the `ResultSet`, `Statement`, and `Connection` to free resources.

---

### **Example: JDBC Program**

Below is an example of a simple JDBC program that connects to a MySQL database, executes a query, and retrieves data.

#### **1. Add MySQL JDBC Driver (Maven Dependency)**
```xml
<dependency>
    <groupId>mysql</groupId>
    <artifactId>mysql-connector-java</artifactId>
    <version>8.0.33</version>
</dependency>
```

#### **2. JDBC Code**
```java
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class JDBCExample {
    public static void main(String[] args) {
        // Database credentials
        String url = "jdbc:mysql://localhost:3306/mydatabase";
        String username = "root";
        String password = "password";

        // Step 1: Load the JDBC driver (optional for modern JDBC drivers)
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            System.out.println("MySQL JDBC Driver not found.");
            e.printStackTrace();
            return;
        }

        // Step 2: Establish a connection
        try (Connection connection = DriverManager.getConnection(url, username, password)) {
            System.out.println("Connected to the database.");

            // Step 3: Create a statement
            Statement statement = connection.createStatement();

            // Step 4: Execute a query
            String sql = "SELECT id, name, email FROM users";
            ResultSet resultSet = statement.executeQuery(sql);

            // Step 5: Process the ResultSet
            while (resultSet.next()) {
                int id = resultSet.getInt("id");
                String name = resultSet.getString("name");
                String email = resultSet.getString("email");

                System.out.println("ID: " + id + ", Name: " + name + ", Email: " + email);
            }

            // Step 6: Close resources (automatically handled by try-with-resources)
        } catch (SQLException e) {
            System.out.println("Connection failed.");
            e.printStackTrace();
        }
    }
}
```

---

### **Using PreparedStatement**

`PreparedStatement` is used for parameterized queries and provides better performance and security (prevents SQL injection).

#### **Example: Insert Data Using PreparedStatement**
```java
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class JDBCPreparedStatementExample {
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

### **Using CallableStatement**

`CallableStatement` is used to call stored procedures in the database.

#### **Example: Call a Stored Procedure**
```java
import java.sql.CallableStatement;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class JDBCCallableStatementExample {
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

### **Best Practices**

1. **Use Try-With-Resources**:
   - Automatically closes resources like `Connection`, `Statement`, and `ResultSet`.

2. **Use PreparedStatement**:
   - Prevents SQL injection and improves performance.

3. **Handle Exceptions**:
   - Always handle `SQLException` to manage database errors.

4. **Connection Pooling**:
   - Use connection pooling libraries like **HikariCP** or **Apache DBCP** for better performance.

5. **Close Resources**:
   - Always close resources to avoid memory leaks.

6. **Use Constants for Credentials**:
   - Store database credentials in configuration files or environment variables.

---

### **Connection Pooling Example (HikariCP)**

**Add Dependency (Maven)**:
```xml
<dependency>
    <groupId>com.zaxxer</groupId>
    <artifactId>HikariCP</artifactId>
    <version>5.0.1</version>
</dependency>
```

**Example**:
```java
import com.zaxxer.hikari.HikariConfig;
import com.zaxxer.hikari.HikariDataSource;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class HikariCPExample {
    public static void main(String[] args) {
        // Configure HikariCP
        HikariConfig config = new HikariConfig();
        config.setJdbcUrl("jdbc:mysql://localhost:3306/mydatabase");
        config.setUsername("root");
        config.setPassword("password");

        // Create a connection pool
        try (HikariDataSource dataSource = new HikariDataSource(config);
             Connection connection = dataSource.getConnection()) {

            // Execute a query
            String sql = "SELECT id, name, email FROM users";
            try (PreparedStatement preparedStatement = connection.prepareStatement(sql);
                 ResultSet resultSet = preparedStatement.executeQuery()) {

                while (resultSet.next()) {
                    int id = resultSet.getInt("id");
                    String name = resultSet.getString("name");
                    String email = resultSet.getString("email");
                    System.out.println("ID: " + id + ", Name: " + name + ", Email: " + email);
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
```

---

By mastering JDBC, you can build Java applications that interact with relational databases efficiently and securely.
