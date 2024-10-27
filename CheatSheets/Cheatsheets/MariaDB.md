An extended MariaDB cheat sheet that covers various commands, how to use them, and explanations. This cheat sheet includes basic operations, data types, and common SQL queries in MariaDB.

---

# **MariaDB Extended Cheat Sheet**

## **1. MariaDB Basics**

### 1.1 Connecting to MariaDB

**Command:**
```bash
mysql -u username -p
```
**Explanation**: Connects to the MariaDB server using the specified username. You'll be prompted for a password.

### 1.2 Show Databases

**Command:**
```sql
SHOW DATABASES;
```
**Explanation**: Lists all databases on the MariaDB server.

### 1.3 Create Database

**Command:**
```sql
CREATE DATABASE database_name;
```
**Explanation**: Creates a new database with the specified name.

### 1.4 Drop Database

**Command:**
```sql
DROP DATABASE database_name;
```
**Explanation**: Deletes the specified database and all its tables.

### 1.5 Use Database

**Command:**
```sql
USE database_name;
```
**Explanation**: Switches to the specified database for subsequent operations.

---

## **2. Working with Tables**

### 2.1 Show Tables

**Command:**
```sql
SHOW TABLES;
```
**Explanation**: Lists all tables in the current database.

### 2.2 Create Table

**Command:**
```sql
CREATE TABLE table_name (
    column1 datatype PRIMARY KEY,
    column2 datatype,
    column3 datatype
);
```
**Explanation**: Creates a new table with specified columns and data types. The `PRIMARY KEY` constraint ensures that the column has unique values.

### 2.3 Show Table Structure

**Command:**
```sql
DESCRIBE table_name;
```
**Explanation**: Displays the structure (columns and types) of the specified table.

### 2.4 Drop Table

**Command:**
```sql
DROP TABLE table_name;
```
**Explanation**: Deletes the specified table and all of its data.

---

## **3. Data Types**

### 3.1 Common MariaDB Data Types

- **INT**: A signed integer.
- **FLOAT**: A floating-point number.
- **DOUBLE**: A double-precision floating-point number.
- **VARCHAR(n)**: A variable-length string with a maximum length of `n`.
- **TEXT**: A string of text.
- **BLOB**: A binary large object, used for storing binary data.
- **DATETIME**: A date and time value.
- **ENUM**: A string object with a value chosen from a list of permitted values.

---

## **4. CRUD Operations**

### 4.1 Insert Data

**Command (Single Row):**
```sql
INSERT INTO table_name (column1, column2) VALUES (value1, value2);
```
**Explanation**: Inserts a new row into the specified table.

**Command (Multiple Rows):**
```sql
INSERT INTO table_name (column1, column2) VALUES (value1, value2), (value3, value4);
```
**Explanation**: Inserts multiple rows into the specified table.

### 4.2 Query Data

**Command:**
```sql
SELECT * FROM table_name;
```
**Explanation**: Retrieves all columns and rows from the specified table.

### 4.3 Query with Conditions

**Command:**
```sql
SELECT * FROM table_name WHERE condition;
```
**Explanation**: Retrieves rows from the specified table that meet the given condition.

### 4.4 Update Data

**Command:**
```sql
UPDATE table_name SET column1 = value1 WHERE condition;
```
**Explanation**: Updates existing rows in the specified table that match the condition.

### 4.5 Delete Data

**Command:**
```sql
DELETE FROM table_name WHERE condition;
```
**Explanation**: Deletes rows from the specified table that meet the given condition.

---

## **5. Querying Data**

### 5.1 Select Specific Columns

**Command:**
```sql
SELECT column1, column2 FROM table_name;
```
**Explanation**: Retrieves only the specified columns from the table.

### 5.2 Order Results

**Command:**
```sql
SELECT * FROM table_name ORDER BY column1 ASC;  -- ASC for ascending, DESC for descending
```
**Explanation**: Retrieves all rows and orders them based on the specified column.

### 5.3 Limit Results

**Command:**
```sql
SELECT * FROM table_name LIMIT number;
```
**Explanation**: Retrieves a specified number of rows from the result set.

---

## **6. Aggregation Functions**

### 6.1 Count Rows

**Command:**
```sql
SELECT COUNT(*) FROM table_name;
```
**Explanation**: Counts the total number of rows in the specified table.

### 6.2 Sum Values

**Command:**
```sql
SELECT SUM(column_name) FROM table_name;
```
**Explanation**: Calculates the total sum of values in the specified column.

### 6.3 Average Values

**Command:**
```sql
SELECT AVG(column_name) FROM table_name;
```
**Explanation**: Calculates the average of values in the specified column.

### 6.4 Grouping Results

**Command:**
```sql
SELECT column_name, COUNT(*) FROM table_name GROUP BY column_name;
```
**Explanation**: Groups results based on the specified column and counts the number of occurrences in each group.

---

## **7. Joins**

### 7.1 Inner Join

**Command:**
```sql
SELECT * FROM table1 INNER JOIN table2 ON table1.common_column = table2.common_column;
```
**Explanation**: Retrieves rows that have matching values in both tables.

### 7.2 Left Join

**Command:**
```sql
SELECT * FROM table1 LEFT JOIN table2 ON table1.common_column = table2.common_column;
```
**Explanation**: Retrieves all rows from the left table and the matched rows from the right table. If there’s no match, NULLs will be returned for columns from the right table.

### 7.3 Right Join

**Command:**
```sql
SELECT * FROM table1 RIGHT JOIN table2 ON table1.common_column = table2.common_column;
```
**Explanation**: Retrieves all rows from the right table and the matched rows from the left table. If there’s no match, NULLs will be returned for columns from the left table.

### 7.4 Cross Join

**Command:**
```sql
SELECT * FROM table1 CROSS JOIN table2;
```
**Explanation**: Returns the Cartesian product of the two tables, combining all rows from `table1` with all rows from `table2`.

---

## **8. Indexing**

### 8.1 Create Index

**Command:**
```sql
CREATE INDEX index_name ON table_name (column_name);
```
**Explanation**: Creates an index on the specified column to improve query performance.

### 8.2 Drop Index

**Command:**
```sql
DROP INDEX index_name ON table_name;
```
**Explanation**: Deletes the specified index from the table.

---

## **9. Transactions**

### 9.1 Begin Transaction

**Command:**
```sql
START TRANSACTION;
```
**Explanation**: Starts a new transaction.

### 9.2 Commit Transaction

**Command:**
```sql
COMMIT;
```
**Explanation**: Saves all changes made during the current transaction.

### 9.3 Rollback Transaction

**Command:**
```sql
ROLLBACK;
```
**Explanation**: Reverts the database to the last committed state, undoing all changes made during the transaction.

---

## **10. Backup and Restore**

### 10.1 Backup Database

**Command:**
```bash
mysqldump -u username -p database_name > backup_file.sql
```
**Explanation**: Creates a backup of the specified database and saves it to a SQL file.

### 10.2 Restore Database

**Command:**
```bash
mysql -u username -p database_name < backup_file.sql
```
**Explanation**: Restores the database from a previously created backup file.

---

## **11. User Management**

### 11.1 Create User

**Command:**
```sql
CREATE USER 'username'@'host' IDENTIFIED BY 'password';
```
**Explanation**: Creates a new user with the specified username, host, and password.

### 11.2 Grant Privileges

**Command:**
```sql
GRANT ALL PRIVILEGES ON database_name.* TO 'username'@'host';
```
**Explanation**: Grants all privileges on the specified database to the user.

### 11.3 Show Grants

**Command:**
```sql
SHOW GRANTS FOR 'username'@'host';
```
**Explanation**: Displays the privileges granted to the specified user.

### 11.4 Revoke Privileges

**Command:**
```sql
REVOKE ALL PRIVILEGES ON database_name.* FROM 'username'@'host';
```
**Explanation**: Revokes all privileges from the specified user on the specified database.

### 11.5 Drop User

**Command:**
```sql
DROP USER 'username'@'host';
```
**Explanation**: Deletes the specified user from the MariaDB server.

---

## **12. Common Queries**

### 12.1 Check for Existence of a Value

**Command:**
```sql
SELECT EXISTS(SELECT 1 FROM table_name WHERE condition);
```
**Explanation**: Returns `1` if the subquery returns any rows, otherwise returns `0`.

### 12.2 Sub

query

**Command:**
```sql
SELECT * FROM table_name WHERE column_name IN (SELECT column_name FROM another_table WHERE condition);
```
**Explanation**: Retrieves rows based on values returned from a subquery.

### 12.3 Conditional Logic with CASE

**Command:**
```sql
SELECT column1, 
       CASE 
           WHEN condition1 THEN result1
           WHEN condition2 THEN result2
           ELSE default_result
       END AS alias_name
FROM table_name;
```
**Explanation**: Returns values based on conditional logic.

---

This cheat sheet provides a comprehensive overview of common MariaDB commands and their explanations. It can help you navigate and utilize MariaDB effectively for various database operations.
