### MariaDB - Create Tables

In MariaDB, a **table** is a collection of rows, and each row contains a set of **columns**. The `CREATE TABLE` statement is used to create a new table in a database. When creating a table, you define its structure, including the column names, data types, and constraints.

### Basic Syntax

```sql
CREATE TABLE table_name (
    column1_name column1_data_type constraints,
    column2_name column2_data_type constraints,
    ...,
    table_constraints
);
```

### 1. **Steps to Create a Table**

1. **Select the Database**: Ensure you have selected the correct database where the table will be created. If you haven't done so already, you can select the database using:
   ```sql
   USE database_name;
   ```

2. **Create the Table**: Define the table structure using the `CREATE TABLE` statement.

---

### 2. **Example of a Simple Table**

Let’s create a simple table `users` to store information about users.

```sql
CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    date_of_birth DATE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
```

#### Explanation:
- **`id INT AUTO_INCREMENT PRIMARY KEY`**: Creates a column `id` that stores integers. The `AUTO_INCREMENT` ensures that each new row gets a unique ID automatically. The `PRIMARY KEY` constraint ensures that `id` is unique for each row.
- **`first_name VARCHAR(50) NOT NULL`**: Creates a column `first_name` of type `VARCHAR` with a maximum length of 50 characters. The `NOT NULL` constraint ensures that the column cannot have a `NULL` value.
- **`last_name VARCHAR(50) NOT NULL`**: Similar to `first_name`, it creates the `last_name` column with a length of 50 characters and disallows `NULL` values.
- **`email VARCHAR(100) UNIQUE NOT NULL`**: The `email` column is of type `VARCHAR`, with a maximum length of 100 characters. The `UNIQUE` constraint ensures no duplicate emails, and `NOT NULL` ensures every user must have an email address.
- **`date_of_birth DATE`**: This column stores the user's date of birth in `YYYY-MM-DD` format.
- **`created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP`**: The `created_at` column stores the timestamp of when the record was created. The `DEFAULT CURRENT_TIMESTAMP` ensures the column is automatically set to the current date and time when the row is created.

---

### 3. **Table Constraints**

Constraints are rules enforced on data columns to ensure data integrity. There are several types of constraints that can be used in a table definition.

#### 3.1. **PRIMARY KEY**
A primary key is a column or a combination of columns that uniquely identifies each row in a table.

```sql
id INT AUTO_INCREMENT PRIMARY KEY
```

#### 3.2. **UNIQUE**
The `UNIQUE` constraint ensures all values in a column are different.

```sql
email VARCHAR(100) UNIQUE
```

#### 3.3. **NOT NULL**
The `NOT NULL` constraint ensures that a column cannot have a `NULL` value.

```sql
first_name VARCHAR(50) NOT NULL
```

#### 3.4. **DEFAULT**
The `DEFAULT` constraint provides a default value for a column when no value is specified during an insert operation.

```sql
created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
```

#### 3.5. **FOREIGN KEY**
A foreign key is used to link two tables together. It ensures that the value in the foreign key column matches a value in the primary key column of another table.

Example:

```sql
CREATE TABLE orders (
    order_id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT,
    order_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES users(id)
);
```

This creates a foreign key relationship between the `orders` table's `user_id` column and the `users` table's `id` column.

#### 3.6. **CHECK**
The `CHECK` constraint ensures that values in a column meet a specific condition.

```sql
age INT CHECK (age >= 18)
```

This ensures that the `age` column only contains values greater than or equal to 18.

---

### 4. **Example: Creating Multiple Tables with Foreign Key**

Here’s a more complex example where we create two tables: `users` and `orders`, with a foreign key relationship between them.

```sql
CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE orders (
    order_id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT,
    order_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    amount DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (user_id) REFERENCES users(id)
);
```

- The `orders` table includes a foreign key `user_id` that references the `id` column in the `users` table.
- The `orders` table also includes a `DECIMAL` type for the `amount` column to store monetary values.

---

### 5. **Managing Tables**

After creating a table, you may need to perform operations like viewing, modifying, or deleting tables.

#### 5.1. **View Tables**
To list all tables in the current database:

```sql
SHOW TABLES;
```

#### 5.2. **Describe Table Structure**
To view the structure (columns, data types, and constraints) of a table:

```sql
DESCRIBE users;
```

#### 5.3. **Alter Table**
To modify the structure of an existing table, such as adding or removing columns:

```sql
ALTER TABLE users ADD COLUMN phone_number VARCHAR(20);
```

#### 5.4. **Drop Table**
To delete a table and all its data:

```sql
DROP TABLE users;
```

---

### 6. **Conclusion**

The `CREATE TABLE` statement is essential for defining the structure of your database. By using appropriate data types and constraints, you can ensure the integrity and efficiency of your data. 

**Key Points**:
- Use `PRIMARY KEY`, `NOT NULL`, `UNIQUE`, and `DEFAULT` constraints to define the behavior of columns.
- Foreign keys help maintain relationships between tables.
- After creating tables, you can manage them with `ALTER TABLE` and `DROP TABLE` commands.

By understanding the various constraints and how to structure your tables effectively, you can build well-organized, maintainable databases in MariaDB.
