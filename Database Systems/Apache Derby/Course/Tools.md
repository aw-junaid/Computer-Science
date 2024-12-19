Apache Derby provides several tools to help with database management, development, and testing. These tools are designed to make it easier for developers to interact with and manage Derby databases, whether in embedded or client-server mode. Here are the main tools provided by Apache Derby:

### 1. **ij (Interactive JDBC Tool)**

The `ij` tool is a command-line utility that provides an interactive SQL shell to execute SQL queries, manage databases, and perform administrative tasks. It works in both **embedded mode** and **client-server mode**.

#### Key Features:
- **Execute SQL Commands**: You can execute any valid SQL command, such as creating tables, inserting data, or querying a database.
- **Database Connection**: Allows connection to both embedded and networked Derby databases using JDBC URLs.
- **Database Management**: Create, connect to, and drop databases, all from the command-line interface.

#### Common Usage:
- To start `ij`, navigate to the `bin` directory of your Derby installation and run the following command:
  ```bash
  ij
  ```

- To connect to a database:
  ```sql
  connect 'jdbc:derby:/path/to/database;create=true';
  ```

- Example of creating a table:
  ```sql
  create table employees (id int, name varchar(100));
  ```

- To disconnect:
  ```sql
  connect 'jdbc:derby:;shutdown=true';
  ```

#### Example:
```bash
$ ij
ij version 10.15
ij> connect 'jdbc:derby://localhost:1527/myDB;create=true';
ij> create table employee (id int, name varchar(100));
ij> insert into employee values (1, 'John Doe');
ij> select * from employee;
```

### 2. **Network Server (startNetworkServer and stopNetworkServer)**

The **Network Server** allows Derby to operate in **client-server mode**. The network server listens for incoming connections from client applications, which can then interact with the Derby database over a network.

#### Key Features:
- **Runs as a Separate Process**: The server runs independently of the client application.
- **Supports Multiple Clients**: Multiple clients can connect to the server simultaneously.
- **Network Communication**: Uses JDBC to communicate with clients over TCP/IP, allowing remote access to the database.

#### How to Use:
1. **Start the Network Server**:
   - Navigate to the `bin` directory of your Derby installation and run the command:
     ```bash
     startNetworkServer
     ```

2. **Stop the Network Server**:
   - To stop the server, you can use:
     ```bash
     stopNetworkServer
     ```

### 3. **Derby Tools for Eclipse**

**Apache Derby** provides integration with the **Eclipse IDE** through the Derby Plug-in for Eclipse. This allows developers to manage and interact with Derby databases directly within the IDE.

#### Key Features:
- **Graphical Interface**: Provides a GUI for creating, managing, and browsing Derby databases.
- **SQL Query Execution**: Run SQL queries against Derby databases within Eclipse.
- **Database Management**: Create and drop tables, view data, and run SQL scripts.

#### Installation:
- Download and install the **Derby plugin** from the Eclipse marketplace or use the **Eclim** project.
- Once installed, you can connect to a Derby database and use the database tools through the Eclipse interface.

### 4. **dblook**

`dblook` is a tool for generating the schema of a Derby database in SQL format. This tool can be useful for exporting the schema for documentation or moving it between different systems.

#### Key Features:
- **Generate Database Schema**: It creates an SQL script that represents the schema of an existing Derby database.
- **Portability**: You can use the generated SQL script to recreate the schema on another system.

#### Usage:
- To generate a schema script for a database, use the following command:
  ```bash
  dblook -d 'jdbc:derby:/path/to/database' -o schema.sql
  ```
  This command connects to the specified database and generates the schema in the `schema.sql` file.

### 5. **sysinfo**

The `sysinfo` tool provides detailed information about the environment, configuration, and properties of the running Derby instance. It is useful for debugging and verifying the setup.

#### Key Features:
- **System Information**: Displays Java version, Derby version, database environment, and system properties.
- **Diagnostic Tool**: Helps troubleshoot Derby configuration issues.

#### Usage:
- To use the `sysinfo` tool, navigate to the `bin` directory of your Derby installation and run the following command:
  ```bash
  sysinfo
  ```

### 6. **JDBC Client (Derby Client Driver)**

Derby includes a **JDBC driver** that can be used for both embedded and client-server modes. The client driver allows external applications to connect to the Derby database, whether it's running in embedded mode or as a network server.

#### Key Features:
- **JDBC Connectivity**: The JDBC client driver enables Java applications to connect to Derby using JDBC API.
- **Supports Client-Server Mode**: Enables remote access to the database when Derby is running as a network server.

#### Example of Using the JDBC Client Driver (Java):
```java
import org.apache.derby.client.ClientDataSource;
import java.sql.*;

public class DerbyClientExample {
    public static void main(String[] args) {
        ClientDataSource dataSource = new ClientDataSource();
        dataSource.setServerName("localhost");
        dataSource.setPortNumber(1527);  // Default port
        dataSource.setDatabaseName("myDB");

        try (Connection conn = dataSource.getConnection()) {
            System.out.println("Connected to Derby Server.");
            // Perform database operations here
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
```

### 7. **dblook and dbtool**

- **dblook**: As mentioned earlier, it is a tool used to extract the schema of an existing Derby database and output it as an SQL script.
- **dbtool**: Used for exporting the database in various formats.

#### Example:
```bash
dblook -d 'jdbc:derby:/path/to/database' -o schema.sql
```

### 8. **Derby Tools for Command-Line Management (Apache Derby)**

Apache Derby also provides additional command-line utilities for managing and interacting with databases. These include:
- **System Management**: Helps you manage the Derby system, including backup and recovery.
- **Database Utilities**: Tools like `dump` and `restore` for exporting and importing databases.

---

### Summary of Key Derby Tools:
| Tool                | Purpose                                          |
|---------------------|--------------------------------------------------|
| **ij**              | Interactive SQL tool for running queries and managing databases. |
| **Network Server**  | Starts a Derby server for client-server mode (supports remote access). |
| **Derby Tools for Eclipse** | Eclipse plugin for managing Derby databases directly within the IDE. |
| **dblook**          | Generates SQL schema for an existing database. |
| **sysinfo**         | Displays system information about the running Derby instance. |
| **JDBC Client Driver** | Connects Java applications to Derby in client-server mode. |

These tools can help you manage and interact with your Derby databases more effectively, depending on whether you're working in an embedded or client-server environment.
