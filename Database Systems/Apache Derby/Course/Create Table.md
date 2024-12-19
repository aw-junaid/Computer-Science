In Apache Derby, the `CREATE TABLE` statement is used to define a new table within a database. This table can have multiple columns, each with a specific data type, and can include constraints such as primary keys, foreign keys, not null, and unique constraints.

### Basic Syntax for `CREATE TABLE`
```sql
CREATE TABLE table_name (
    column1 data_type [constraint],
    column2 data_type [constraint],
    ...
    [table_constraints]
);
```

- `table_name`: The name of the table you want to create.
- `column1, column2, ...`: The names of the columns in the table.
- `data_type`: The data type for each column (e.g., `INT`, `VARCHAR(255)`, `DATE`, etc.).
- `constraint`: Optional constraints for the column, such as `NOT NULL`, `PRIMARY KEY`, `UNIQUE`, etc.
- `table_constraints`: Optional constraints applied to the entire table, such as `PRIMARY KEY` or `FOREIGN KEY`.

### Example 1: Basic Table Creation
This example creates a simple table `employees` with `id`, `name`, and `hire_date` columns.

```sql
CREATE TABLE employees (
    id INT PRIMARY KEY,
    name VARCHAR(100),
    hire_date DATE
);
```
- **`id`**: Integer column, acting as the primary key.
- **`name`**: Variable-length string column with a maximum length of 100 characters.
- **`hire_date`**: Date column to store the employee's hire date.

### Example 2: Table with Constraints
In this example, we create a `departments` table, which includes a `department_id` as the primary key and a `manager_id` as a foreign key that references the `id` from the `employees` table.

```sql
CREATE TABLE departments (
    department_id INT PRIMARY KEY,
    department_name VARCHAR(100) NOT NULL,
    manager_id INT,
    FOREIGN KEY (manager_id) REFERENCES employees(id)
);
```
- **`department_id`**: Integer column acting as the primary key.
- **`department_name`**: A string column that cannot be `NULL`.
- **`manager_id`**: Integer column representing a foreign key that references the `id` in the `employees` table.

### Example 3: Table with Multiple Constraints
This example demonstrates using multiple constraints, including `NOT NULL`, `UNIQUE`, and `CHECK`.

```sql
CREATE TABLE products (
    product_id INT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    product_name VARCHAR(100) NOT NULL,
    price DECIMAL(10, 2) CHECK (price > 0),
    category VARCHAR(50) UNIQUE
);
```
- **`product_id`**: Auto-incrementing `INT` column defined as the primary key.
- **`product_name`**: A string column that cannot be `NULL`.
- **`price`**: A decimal column with a check constraint ensuring the price is positive.
- **`category`**: A string column with a unique constraint ensuring that each product category is distinct.

### Example 4: Table with Default Values
You can define default values for columns using the `DEFAULT` keyword.

```sql
CREATE TABLE orders (
    order_id INT PRIMARY KEY,
    order_date DATE DEFAULT CURRENT_DATE,
    status VARCHAR(20) DEFAULT 'Pending'
);
```
- **`order_date`**: If not specified, the current date is used.
- **`status`**: If not specified, the default value will be `'Pending'`.

### Example 5: Complex Table with Composite Key
You can define composite keys using multiple columns as the primary key.

```sql
CREATE TABLE order_items (
    order_id INT,
    product_id INT,
    quantity INT,
    PRIMARY KEY (order_id, product_id)
);
```
- **Composite Primary Key**: The combination of `order_id` and `product_id` serves as the primary key for this table.

### Example 6: Table with Auto-Incrementing Column (Identity)
In Derby, you can use the `GENERATED ALWAYS AS IDENTITY` syntax to create an auto-incrementing column, commonly used for primary keys.

```sql
CREATE TABLE customers (
    customer_id INT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    email VARCHAR(100)
);
```
- **`customer_id`**: Automatically generates unique IDs for each row inserted into the `customers` table.

### Example 7: Creating a Table with Foreign Key Constraints
This example shows how to create a table with a foreign key constraint, linking the `orders` table to the `customers` table.

```sql
CREATE TABLE orders (
    order_id INT PRIMARY KEY,
    customer_id INT,
    order_date DATE,
    FOREIGN KEY (customer_id) REFERENCES customers(customer_id)
);
```
- **`customer_id`**: This column is a foreign key that references the `customer_id` column from the `customers` table.

### Summary of Constraints:
- **`PRIMARY KEY`**: Ensures that the column (or set of columns) contains unique values and cannot be `NULL`.
- **`FOREIGN KEY`**: Ensures referential integrity by linking a column to a column in another table.
- **`UNIQUE`**: Ensures that all values in a column (or set of columns) are unique.
- **`CHECK`**: Ensures that values in a column satisfy a specific condition (e.g., `price > 0`).
- **`NOT NULL`**: Ensures that a column cannot contain `NULL` values.
- **`DEFAULT`**: Specifies a default value for a column if no value is provided during insertion.
- **`GENERATED ALWAYS AS IDENTITY`**: Used for auto-incrementing columns (commonly used for primary keys).

### Conclusion
The `CREATE TABLE` statement in Apache Derby allows you to define tables with various data types, constraints, and relationships. By carefully using constraints like `PRIMARY KEY`, `FOREIGN KEY`, and `CHECK`, you can ensure data integrity and structure your tables to meet your application's needs.
