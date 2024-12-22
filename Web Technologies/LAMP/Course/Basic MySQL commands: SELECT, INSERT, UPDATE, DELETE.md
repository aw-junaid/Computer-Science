### **Basic MySQL Commands: `SELECT`, `INSERT`, `UPDATE`, `DELETE`**

These four basic SQL commands are the foundation for interacting with a MySQL database. Below is an explanation and usage of each command.

---

### **1. `SELECT` – Retrieving Data**

The `SELECT` statement is used to query and retrieve data from a MySQL database.

#### **Basic Syntax:**
```sql
SELECT column1, column2, ... FROM table_name;
```
- `column1, column2, ...`: The specific columns you want to retrieve.
- `table_name`: The name of the table from which to retrieve data.

#### **Examples:**

- **Select all columns from a table:**
  ```sql
  SELECT * FROM customers;
  ```
  This retrieves all columns and rows from the `customers` table.

- **Select specific columns:**
  ```sql
  SELECT first_name, last_name FROM customers;
  ```
  This retrieves only the `first_name` and `last_name` columns from the `customers` table.

- **Filtering with `WHERE`:**
  ```sql
  SELECT * FROM customers WHERE city = 'New York';
  ```
  This retrieves all customers who live in New York.

- **Sorting results with `ORDER BY`:**
  ```sql
  SELECT * FROM customers ORDER BY last_name ASC;
  ```
  This sorts the results by the `last_name` column in ascending order. You can also use `DESC` for descending order.

- **Limiting results with `LIMIT`:**
  ```sql
  SELECT * FROM customers LIMIT 5;
  ```
  This limits the result to only 5 rows.

---

### **2. `INSERT` – Inserting Data**

The `INSERT` statement is used to add new rows (records) into a table.

#### **Basic Syntax:**
```sql
INSERT INTO table_name (column1, column2, ...) VALUES (value1, value2, ...);
```
- `table_name`: The name of the table where the data will be inserted.
- `column1, column2, ...`: The columns in the table where data is being inserted.
- `value1, value2, ...`: The values corresponding to each column.

#### **Examples:**

- **Insert a new record into a table:**
  ```sql
  INSERT INTO customers (first_name, last_name, email) VALUES ('John', 'Doe', 'john.doe@example.com');
  ```
  This inserts a new customer record with the first name `John`, last name `Doe`, and email `john.doe@example.com` into the `customers` table.

- **Insert multiple records at once:**
  ```sql
  INSERT INTO customers (first_name, last_name, email) 
  VALUES ('Alice', 'Smith', 'alice.smith@example.com'),
         ('Bob', 'Jones', 'bob.jones@example.com');
  ```
  This inserts two records at once into the `customers` table.

---

### **3. `UPDATE` – Updating Data**

The `UPDATE` statement is used to modify existing data in a table.

#### **Basic Syntax:**
```sql
UPDATE table_name SET column1 = value1, column2 = value2, ... WHERE condition;
```
- `table_name`: The name of the table to update.
- `column1, column2, ...`: The columns that you want to update.
- `value1, value2, ...`: The new values for the columns.
- `condition`: The condition that specifies which records to update. Without this, all rows will be updated.

#### **Examples:**

- **Update a single record:**
  ```sql
  UPDATE customers SET email = 'john.newemail@example.com' WHERE customer_id = 1;
  ```
  This updates the email of the customer with `customer_id = 1` to `john.newemail@example.com`.

- **Update multiple columns:**
  ```sql
  UPDATE customers SET first_name = 'John', last_name = 'Doe' WHERE customer_id = 2;
  ```
  This updates both the `first_name` and `last_name` columns for the customer with `customer_id = 2`.

- **Update all rows (use with caution):**
  ```sql
  UPDATE customers SET email = 'default@example.com';
  ```
  This updates the email for **all** rows in the `customers` table. Always be careful when omitting the `WHERE` clause.

---

### **4. `DELETE` – Deleting Data**

The `DELETE` statement is used to remove rows from a table.

#### **Basic Syntax:**
```sql
DELETE FROM table_name WHERE condition;
```
- `table_name`: The name of the table from which to delete data.
- `condition`: The condition that specifies which rows to delete.

#### **Examples:**

- **Delete a single record:**
  ```sql
  DELETE FROM customers WHERE customer_id = 1;
  ```
  This deletes the customer with `customer_id = 1` from the `customers` table.

- **Delete multiple records:**
  ```sql
  DELETE FROM customers WHERE city = 'New York';
  ```
  This deletes all customers who live in New York.

- **Delete all records (use with caution):**
  ```sql
  DELETE FROM customers;
  ```
  This deletes **all** rows in the `customers` table. The table structure remains, but the data is removed. Always be cautious when using `DELETE` without a `WHERE` clause.

---

### **Conclusion**

These four basic SQL commands — `SELECT`, `INSERT`, `UPDATE`, and `DELETE` — are essential for managing data in a MySQL database. They allow you to retrieve, add, modify, and remove data as needed. Always use `WHERE` clauses carefully in `UPDATE` and `DELETE` statements to avoid unintended changes to your data.
