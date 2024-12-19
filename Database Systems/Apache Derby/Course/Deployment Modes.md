Apache Derby can be deployed in different modes, each serving different use cases depending on how the database is intended to interact with the application. The two primary deployment modes for Apache Derby are:

### 1. **Embedded Mode**
In **embedded mode**, Apache Derby runs as an embedded database within a Java application. This means that Derby is started and stopped from within the application itself, and there is no separate database server running.

#### Key Characteristics of Embedded Mode:
- **Database Embedded in the Application**: Derby is included as part of the Java application. It operates directly within the application’s JVM (Java Virtual Machine), and there’s no need for a standalone database server.
- **No Server Process**: Since there is no need for a separate database server, the application itself manages the connection to the Derby database.
- **Lightweight**: Ideal for resource-constrained environments where minimal overhead is desired.
- **Persistence**: Data is stored in the filesystem and persists across application restarts.
- **Automatic Startup/Shutdown**: The database starts and stops with the Java application.
  
#### Example Use Cases for Embedded Mode:
- Small desktop applications that require a local database.
- Applications running on embedded systems or mobile devices.
- Single-user applications or small-scale development environments.

#### How It Works:
- The application links to Derby’s libraries (typically a JAR file) and manages the connection to the database directly through JDBC (Java Database Connectivity).
- The Derby database files are stored in the local filesystem and accessed by the embedded JVM process.
  
#### Example Code Snippet (Java):
```java
import org.apache.derby.jdbc.EmbeddedDataSource;

public class DerbyExample {
    public static void main(String[] args) {
        EmbeddedDataSource dataSource = new EmbeddedDataSource();
        dataSource.setDatabaseName("myDatabase");
        dataSource.setCreateDatabase("create");

        try (Connection conn = dataSource.getConnection()) {
            // Perform database operations here
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
```

### 2. **Client-Server Mode**
In **client-server mode**, Apache Derby runs as a standalone database server, and applications communicate with it over a network using JDBC. This mode is typically used when multiple clients need to connect to a central database.

#### Key Characteristics of Client-Server Mode:
- **Separate Database Server**: In this mode, Derby operates as a server and is run separately from the application. The application communicates with Derby over a network connection using a client JDBC connection.
- **Centralized Database Access**: Multiple clients can access the same Derby database, allowing for multi-user scenarios.
- **Database Management**: Since Derby runs as a separate server, it requires the database server to be started and managed independently.
- **Network Connectivity**: Communication between the client and the server occurs over a TCP/IP connection.

#### Example Use Cases for Client-Server Mode:
- Small to medium-sized applications that need a centralized database shared by multiple users or client machines.
- Development and testing environments where different components of an application run on different machines or systems.
- Applications that may evolve to require a centralized database server in the future.

#### How It Works:
- The Derby server is started as a separate process and listens for incoming client connections.
- Applications (clients) use JDBC to connect to the Derby server over a network using a specific connection string.
- The database server can be configured to listen on specific ports and accept client connections.

#### Example Code Snippet (Java - Client):
```java
import org.apache.derby.client.ClientDataSource;

public class DerbyClientExample {
    public static void main(String[] args) {
        ClientDataSource dataSource = new ClientDataSource();
        dataSource.setServerName("localhost");
        dataSource.setPortNumber(1527); // Default port
        dataSource.setDatabaseName("myDatabase");

        try (Connection conn = dataSource.getConnection()) {
            // Perform database operations here
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
```

### Summary of Deployment Modes:
| Feature              | **Embedded Mode**                      | **Client-Server Mode**                |
|----------------------|----------------------------------------|---------------------------------------|
| **Server Requirement**| No separate server process             | Separate Derby server required        |
| **Concurrency**       | Single-user or embedded systems        | Multi-user access from multiple clients|
| **Connection Method** | Direct JDBC connection                 | Remote JDBC connection over network   |
| **Use Case**          | Small applications, resource-constrained environments | Larger applications, multi-user systems |
| **Configuration**     | Minimal configuration                  | Requires server and client setup      |

### When to Use Each Mode:
- **Embedded Mode**: Best for standalone applications, simple testing, or when deploying within small environments like desktop or embedded systems.
- **Client-Server Mode**: Useful for centralized database access in larger applications or multi-user systems, where the database server is separate from the client application.

By selecting the appropriate deployment mode, you can tailor Apache Derby to meet the needs of your specific application environment.
