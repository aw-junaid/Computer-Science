In SQLite, the **UNION** clause is used to combine the results of two or more `SELECT` queries into a single result set. This is particularly useful when you want to retrieve data from multiple tables or multiple queries in a single list. Each `SELECT` statement must have the same number of columns, and the data types of each column must be compatible between all `SELECT` statements in the `UNION`.

### Syntax of the UNION Clause

```sql
SELECT column1, column2, ...
FROM table1
UNION
SELECT column1, column2, ...
FROM table2;
```

- **UNION**: Combines unique results from both queries, excluding duplicates.
- **UNION ALL**: Combines results from both queries, including duplicates.

### Rules and Requirements for UNION

1. **Column Compatibility**: Each `SELECT` statement in the `UNION` must have the same number of columns in the result set, and the corresponding columns must have compatible data types.
2. **Order of Results**: The ordering is based on the order in which the queries appear. You can add an `ORDER BY` clause at the end of the `UNION` to sort the entire result set.
3. **Duplicate Rows**: By default, `UNION` removes duplicate rows. To include duplicates, use `UNION ALL`.

### Examples of Using UNION and UNION ALL

#### Example Setup

Suppose you have two tables:

```sql
CREATE TABLE employees (
    id INTEGER PRIMARY KEY,
    name TEXT,
    department TEXT
);

CREATE TABLE contractors (
    id INTEGER PRIMARY KEY,
    name TEXT,
    department TEXT
);

-- Insert sample data
INSERT INTO employees (name, department) VALUES ('Alice', 'HR');
INSERT INTO employees (name, department) VALUES ('Bob', 'IT');

INSERT INTO contractors (name, department) VALUES ('Charlie', 'HR');
INSERT INTO contractors (name, department) VALUES ('Alice', 'Finance');
```

#### Basic UNION Example

```sql
SELECT name, department
FROM employees
UNION
SELECT name, department
FROM contractors;
```

**Explanation**: This query will return a combined list of names and departments from both `employees` and `contractors` tables, excluding duplicates.

**Result**:

| name    | department |
|---------|------------|
| Alice   | HR         |
| Bob     | IT         |
| Charlie | HR         |
| Alice   | Finance    |

**Note**: "Alice" appears twice because she is listed in two different departments.

#### UNION ALL Example

```sql
SELECT name, department
FROM employees
UNION ALL
SELECT name, department
FROM contractors;
```

**Explanation**: This query will return all rows from both tables, including duplicates.

**Result**:

| name    | department |
|---------|------------|
| Alice   | HR         |
| Bob     | IT         |
| Charlie | HR         |
| Alice   | Finance    |
| Alice   | HR         |

**Note**: The "Alice - HR" row appears twice because `UNION ALL` includes duplicates.

---

### Using ORDER BY with UNION

To order the combined result, add an `ORDER BY` clause at the end of the final query:

```sql
SELECT name, department
FROM employees
UNION
SELECT name, department
FROM contractors
ORDER BY name ASC;
```

**Explanation**: This will combine the results and sort them by `name` in ascending order.

**Result**:

| name    | department |
|---------|------------|
| Alice   | HR         |
| Alice   | Finance    |
| Bob     | IT         |
| Charlie | HR         |

### Practical Use Cases for UNION

1. **Merging Similar Datasets**: When you have similar data in separate tables, such as `employees` and `contractors`, `UNION` can create a single list.
2. **Reporting and Analytics**: Combine results from different time periods or conditions into a unified report.
3. **Handling Data from Multiple Sources**: If your database schema includes data from various sources (like backup or archive tables), `UNION` allows you to view all relevant data in one query.

### Summary of SQLite UNION Clause

- **UNION** combines results from multiple `SELECT` queries into one set, excluding duplicates.
- **UNION ALL** includes all rows, including duplicates.
- **Requirements**: Each `SELECT` must have the same number of columns with compatible data types.
- **Usage**: Helpful for merging similar datasets, creating unified reports, and combining data from different sources.

The `UNION` clause is a powerful tool for retrieving and organizing data across multiple queries in SQLite, providing flexibility and control in result sets.
