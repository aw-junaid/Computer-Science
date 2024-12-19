Setting up **Apache Derby** involves downloading the necessary software, configuring it, and running it in either **embedded** or **client-server** mode. Here's a step-by-step guide for both modes.

### 1. **Prerequisites**
Before setting up Apache Derby, ensure you have the following:

- **Java Development Kit (JDK)**: Apache Derby is a Java-based database, so you need the Java JDK installed on your machine.
    - Download and install JDK from the [official Oracle website](https://www.oracle.com/java/technologies/javase-downloads.html) or from [OpenJDK](https://openjdk.java.net/).
    - Set the `JAVA_HOME` environment variable to the installation directory of JDK.

- **Apache Derby Distribution**: Download the Apache Derby binary distribution from the official website.
    - Visit [Apache Derby Download Page](https://db.apache.org/derby/derby_downloads.html) and download the binary zip or tar file for your operating system.

### 2. **Setup for Embedded Mode**
In **embedded mode**, the Derby database runs inside your Java application, without a separate server process.

#### Steps to Set Up:
1. **Download and Extract Derby**:
   - Download the latest version of Apache Derby.
   - Extract the ZIP or TAR file to a directory of your choice.

2. **Set Up the Environment Variables**:
   - Set the `DERBY_HOME` environment variable to the directory where Derby was extracted. This helps in easily running Derby commands from the terminal.
   - For Windows (set in Command Prompt or in `System Properties`):
     ```bash
     set DERBY_HOME=C:\path\to\derby
     set PATH=%PATH%;%DERBY_HOME%\bin
     ```
   - For Unix/Linux (add to `.bashrc` or `.bash_profile`):
     ```bash
     export DERBY_HOME=/path/to/derby
     export PATH=$PATH:$DERBY_HOME/bin
     ```

3. **Create a Database**:
   - Apache Derby can create databases directly through JDBC from a Java program.
   - Alternatively, you can use the **ij** command-line tool (included with Derby) to create and interact with databases.

   - **Using ij Tool**:
     - Open a terminal and navigate to the `bin` directory of your Derby installation.
     - Run the `ij` tool by typing:
       ```bash
       ij
       ```
     - You can then create a new database using SQL:
       ```sql
       connect 'jdbc:derby:/path/to/database;create=true';
       ```

4. **Develop Java Application with Embedded Derby**:
   - You can now embed Derby within your Java application by including Derby's libraries (JAR files) in your project.
   - Use `EmbeddedDataSource` to connect to the database programmatically from Java.

#### Example Code Snippet (Embedded Mode):
```java
import org.apache.derby.jdbc.EmbeddedDataSource;

public class DerbyExample {
    public static void main(String[] args) {
        EmbeddedDataSource dataSource = new EmbeddedDataSource();
        dataSource.setDatabaseName("myDB");
        dataSource.setCreateDatabase("create");

        try (Connection conn = dataSource.getConnection()) {
            System.out.println("Database connected successfully.");
            // Perform database operations here
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
```

### 3. **Setup for Client-Server Mode**
In **client-server mode**, Derby runs as a separate server, and client applications connect to it over a network.

#### Steps to Set Up:
1. **Download and Extract Derby**:
   - Follow the same steps as for embedded mode to download and extract Apache Derby.

2. **Set Up the Environment Variables**:
   - Ensure the `DERBY_HOME` environment variable is set correctly, as mentioned in the embedded setup steps.

3. **Start the Derby Network Server**:
   - In client-server mode, you need to start the Derby network server, which listens for client connections.
   - Open a terminal or command prompt and run:
     ```bash
     cd $DERBY_HOME/bin
     startNetworkServer
     ```
     This command starts the Derby server on the default port (1527).
   - To stop the server, use:
     ```bash
     stopNetworkServer
     ```

4. **Accessing the Server from a Client**:
   - Applications (clients) can connect to the Derby server using JDBC.
   - In Java, configure the connection URL to point to the Derby server using `ClientDataSource`.

#### Example Code Snippet (Client Mode):
```java
import org.apache.derby.client.ClientDataSource;
import java.sql.Connection;
import java.sql.SQLException;

public class DerbyClientExample {
    public static void main(String[] args) {
        ClientDataSource dataSource = new ClientDataSource();
        dataSource.setServerName("localhost");
        dataSource.setPortNumber(1527); // Default port
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

5. **Creating the Database**:
   - The client application can create a new database by specifying the connection URL and using SQL queries or JDBC commands.
   - Example URL: `jdbc:derby://localhost:1527/myDB;create=true`

### 4. **Testing the Setup**
Once you have set up Apache Derby in either embedded or client-server mode, you can run simple tests to ensure the database is functioning correctly.

- **Embedded Mode**: Create a database using a Java program, and insert some data to verify that the database is being used.
- **Client-Server Mode**: Start the Derby network server and connect from a client application to ensure communication is successful.

### 5. **Useful Tools**
- **ij (Interactive JDBC Shell)**: A command-line tool for interacting with Derby databases. It allows you to run SQL queries, create databases, and more. It is located in the `bin` directory of Derby.
  - Start `ij` by running `ij` in the terminal.
  - Use the command `connect 'jdbc:derby://localhost:1527/myDB'` to connect to a server-based Derby database.

### Conclusion:
By following these steps, you can successfully set up Apache Derby in either **embedded** or **client-server** mode. Apache Derby provides a flexible, lightweight database solution for Java applications, and setting it up is relatively straightforward for both single-user applications and multi-user systems.
