### ASP.NET - Database Access

ASP.NET provides various methods for accessing and interacting with databases, which are essential for developing dynamic, data-driven applications. The most common way to access a database in ASP.NET is through **ADO.NET**, **Entity Framework**, or **LINQ to SQL**. These technologies allow you to connect to relational databases like SQL Server, MySQL, Oracle, or other supported data sources, retrieve, manipulate, and display data.

Below are the common approaches for database access in ASP.NET:

---

### 1. **ADO.NET (ActiveX Data Objects for .NET)**

ADO.NET is a low-level, data access technology in the .NET framework that provides the means to interact with relational databases. It includes a set of classes to connect to a database, retrieve and update data, and manage connections to the database.

#### Key Components of ADO.NET:
- **Connection**: Establishes a connection to a database (e.g., `SqlConnection` for SQL Server).
- **Command**: Executes SQL queries and stored procedures (e.g., `SqlCommand`).
- **DataReader**: Used to retrieve data in a forward-only, read-only manner (e.g., `SqlDataReader`).
- **DataAdapter**: Serves as a bridge to fill a `DataSet` or `DataTable` and update the database (e.g., `SqlDataAdapter`).
- **DataSet**: In-memory representation of data that can hold multiple tables (e.g., `DataSet`, `DataTable`).

#### Example: Using ADO.NET to Retrieve Data
```csharp
using System;
using System.Data;
using System.Data.SqlClient;

public class DatabaseExample
{
    public void GetData()
    {
        string connectionString = "your_connection_string_here";
        string query = "SELECT * FROM Users";

        // Create a connection to the database
        using (SqlConnection connection = new SqlConnection(connectionString))
        {
            SqlCommand command = new SqlCommand(query, connection);

            // Open the connection
            connection.Open();

            // Execute the command and retrieve the data
            SqlDataReader reader = command.ExecuteReader();

            // Read and display the data
            while (reader.Read())
            {
                Console.WriteLine(reader["UserName"].ToString());
            }

            // Close the reader
            reader.Close();
        }
    }
}
```

#### Example: Using DataAdapter to Fill a DataSet
```csharp
using System;
using System.Data;
using System.Data.SqlClient;

public class DatabaseExample
{
    public DataSet GetDataSet()
    {
        string connectionString = "your_connection_string_here";
        string query = "SELECT * FROM Users";

        // Create a DataAdapter to fill the DataSet
        using (SqlDataAdapter adapter = new SqlDataAdapter(query, connectionString))
        {
            DataSet dataSet = new DataSet();
            adapter.Fill(dataSet, "Users");

            return dataSet;
        }
    }
}
```

---

### 2. **Entity Framework (EF)**

Entity Framework (EF) is an Object-Relational Mapping (ORM) framework for .NET that allows developers to work with databases using .NET objects. EF simplifies data access by abstracting the database interactions and allowing developers to work with strongly-typed objects instead of writing raw SQL queries.

#### Key Features of Entity Framework:
- **Code First**: You define your database schema using C# classes, and EF will automatically create and update the database.
- **Database First**: EF generates C# classes based on an existing database.
- **Model First**: You design your database using the Entity Data Model (EDM), and EF generates the database schema from the model.
- **LINQ Queries**: You can query the database using LINQ syntax.

#### Example: Using Entity Framework Code First
1. **Define the Entity Class**:
```csharp
public class User
{
    public int UserId { get; set; }
    public string UserName { get; set; }
    public string Email { get; set; }
}
```

2. **Define the Database Context**:
```csharp
using System.Data.Entity;

public class ApplicationDbContext : DbContext
{
    public DbSet<User> Users { get; set; }
}
```

3. **Querying Data Using Entity Framework**:
```csharp
using System;
using System.Linq;

public class DatabaseExample
{
    public void GetUsers()
    {
        using (var context = new ApplicationDbContext())
        {
            var users = from u in context.Users
                        select u;

            foreach (var user in users)
            {
                Console.WriteLine($"UserId: {user.UserId}, UserName: {user.UserName}, Email: {user.Email}");
            }
        }
    }
}
```

4. **Creating and Migrating the Database** (Using Code First Migrations):
```bash
Add-Migration InitialCreate
Update-Database
```

---

### 3. **LINQ to SQL**

**LINQ to SQL** is a simpler ORM approach for accessing and manipulating data in SQL Server databases. It allows developers to use LINQ (Language Integrated Query) to query the database directly and is similar to Entity Framework but less feature-rich.

#### Key Features of LINQ to SQL:
- **Object-Relational Mapping**: LINQ to SQL automatically generates classes based on the database schema.
- **LINQ Queries**: You can write SQL-like queries directly in C# using LINQ syntax.
- **Change Tracking**: It tracks changes to objects and generates the necessary SQL to update the database.

#### Example: Using LINQ to SQL
1. **Define the DataContext Class**:
```csharp
public class ApplicationDbContext : DataContext
{
    public Table<User> Users;

    public ApplicationDbContext(string connectionString) : base(connectionString) { }
}
```

2. **Querying Data Using LINQ to SQL**:
```csharp
using System;
using System.Linq;

public class DatabaseExample
{
    public void GetUsers()
    {
        string connectionString = "your_connection_string_here";
        
        using (var context = new ApplicationDbContext(connectionString))
        {
            var users = from u in context.Users
                        select u;

            foreach (var user in users)
            {
                Console.WriteLine($"UserId: {user.UserId}, UserName: {user.UserName}, Email: {user.Email}");
            }
        }
    }
}
```

---

### 4. **Database Access in ASP.NET Web Forms**

In ASP.NET Web Forms, database access can be integrated with **GridView**, **DetailsView**, and other data-bound controls. These controls support automatic CRUD (Create, Read, Update, Delete) operations with the database.

#### Example: Using GridView with SQLDataSource (Read-Only Data)
```html
<asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="true" 
    DataSourceID="SqlDataSource1" />
<asp:SqlDataSource 
    ID="SqlDataSource1" 
    runat="server" 
    ConnectionString="your_connection_string_here" 
    SelectCommand="SELECT * FROM Users" />
```

---

### 5. **Stored Procedures in ADO.NET and Entity Framework**

Stored procedures are precompiled SQL queries stored in the database. You can execute them from your ASP.NET application using ADO.NET or Entity Framework.

#### ADO.NET Example: Calling a Stored Procedure
```csharp
using System;
using System.Data;
using System.Data.SqlClient;

public class DatabaseExample
{
    public void CallStoredProcedure()
    {
        string connectionString = "your_connection_string_here";
        string storedProc = "GetUserById";

        using (SqlConnection connection = new SqlConnection(connectionString))
        {
            SqlCommand command = new SqlCommand(storedProc, connection);
            command.CommandType = CommandType.StoredProcedure;

            // Add parameters
            command.Parameters.AddWithValue("@UserId", 1);

            connection.Open();
            SqlDataReader reader = command.ExecuteReader();

            while (reader.Read())
            {
                Console.WriteLine(reader["UserName"].ToString());
            }
            reader.Close();
        }
    }
}
```

#### Entity Framework Example: Calling a Stored Procedure
```csharp
using System;
using System.Linq;

public class DatabaseExample
{
    public void GetUserById()
    {
        using (var context = new ApplicationDbContext())
        {
            var userIdParam = new SqlParameter("@UserId", 1);
            var users = context.Database.SqlQuery<User>("EXEC GetUserById @UserId", userIdParam).ToList();

            foreach (var user in users)
            {
                Console.WriteLine(user.UserName);
            }
        }
    }
}
```

---

### 6. **Conclusion**

ASP.NET provides several options for accessing databases, including ADO.NET, Entity Framework, and LINQ to SQL. Depending on the complexity and requirements of your application, you can choose the appropriate method:

- **ADO.NET**: Offers full control over database operations, ideal for complex and high-performance applications.
- **Entity Framework**: A higher-level ORM that abstracts database operations and allows for easy query generation using LINQ.
- **LINQ to SQL**: A simpler ORM for SQL Server, offering tight integration with LINQ queries.

These technologies can be used together with ASP.NET Web Forms or MVC to build data-driven applications, enabling smooth and efficient database access.
