# Basic DBMS Concepts:

---

### **1. Database Basics**
- **Database**: A collection of organized data for easy access, management, and updating.
- **DBMS (Database Management System)**: Software that enables users to interact with databases to perform operations like data storage, retrieval, and manipulation.

---

### **2. Characteristics of DBMS**
- **Data Abstraction**: Levels of abstraction (Physical, Logical, View).
- **Data Independence**: Ability to change schema without affecting the application.
  - **Logical Independence**: Changes to logical schema do not affect external schema.
  - **Physical Independence**: Changes to physical storage do not affect logical schema.
- **Data Consistency**: Ensures data integrity across the system.
- **Concurrency Control**: Supports multiple users accessing the database simultaneously.

---

### **3. Database Models**
- **Relational Model**: Data is stored in tables (relations) with rows and columns.
  - Example: SQL databases like MySQL, PostgreSQL.
- **Hierarchical Model**: Data is organized in a tree-like structure.
  - Example: IBM IMS.
- **Network Model**: Data is organized as a graph with nodes and relationships.
  - Example: IDMS.
- **Object-Oriented Model**: Combines database capabilities with object-oriented programming.

---

### **4. Relational Database Concepts**
- **Relation**: A table in the database.
- **Tuple**: A single row in a table.
- **Attribute**: A column in a table.
- **Schema**: Structure of the database.
- **Keys**:
  - **Primary Key**: Unique identifier for a record.
  - **Foreign Key**: Links tables to ensure referential integrity.
  - **Candidate Key**: A set of fields that uniquely identify a record.
  - **Composite Key**: A key consisting of two or more attributes.

---

### **5. SQL Basics**
- **DDL (Data Definition Language)**: Defines the structure of the database.
  - Examples: `CREATE`, `ALTER`, `DROP`.
- **DML (Data Manipulation Language)**: Manipulates data within the database.
  - Examples: `INSERT`, `UPDATE`, `DELETE`.
- **DQL (Data Query Language)**: Retrieves data from the database.
  - Example: `SELECT`.
- **DCL (Data Control Language)**: Manages user permissions.
  - Examples: `GRANT`, `REVOKE`.
- **TCL (Transaction Control Language)**: Manages database transactions.
  - Examples: `COMMIT`, `ROLLBACK`, `SAVEPOINT`.

---

### **6. Normalization**
- Process of organizing data to reduce redundancy and dependency.
- **Normal Forms**:
  - **1NF**: Eliminate duplicate columns.
  - **2NF**: Remove partial dependency.
  - **3NF**: Remove transitive dependency.
  - **BCNF**: Higher level of 3NF ensuring no non-trivial dependencies.

---

### **7. Transactions and ACID Properties**
- **Transaction**: A sequence of operations treated as a single logical unit.
- **ACID Properties**:
  - **Atomicity**: All operations in a transaction are completed, or none are.
  - **Consistency**: The database remains in a valid state before and after a transaction.
  - **Isolation**: Transactions do not interfere with each other.
  - **Durability**: Changes made by a transaction are permanent.

---

### **8. Concurrency Control**
- Manages simultaneous transactions to avoid conflicts.
- Common Problems:
  - Dirty Reads, Lost Updates, Uncommitted Data, Inconsistent Analysis.
- Solutions:
  - Locking (Shared/Exclusive), Timestamp Ordering, Two-Phase Locking (2PL).

---

### **9. Database Security**
- **Authentication**: Verifying user identity.
- **Authorization**: Granting or restricting access to database resources.
- **Encryption**: Protecting data during storage or transmission.

---

### **10. Example DBMS Tools**
- **Relational DBMS**: MySQL, PostgreSQL, Oracle Database, Microsoft SQL Server.
- **NoSQL**: MongoDB, Cassandra, CouchDB.
- **Cloud Databases**: Amazon RDS, Google Cloud SQL, Azure Cosmos DB.

---
