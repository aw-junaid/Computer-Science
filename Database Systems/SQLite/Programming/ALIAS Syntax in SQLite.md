In SQLite, an **alias** is a temporary name assigned to a table or a column in a query. Aliases make the query results more readable and can simplify the syntax, especially when dealing with complex expressions or long table names. Aliases only exist for the duration of the query in which they are defined.

### Types of Aliases in SQLite

1. **Column Alias**: Renames a column in the query result.
2. **Table Alias**: Renames a table in the query for easier reference, particularly useful when joining tables.

---

### 1. Column Alias

A **column alias** is used to give a temporary name to a column in the output of a `SELECT` statement.

**Syntax**:
```sql
SELECT column_name AS alias_name
FROM table_name;
```

- `AS` is optional in SQLite, so you can also write `column_name alias_name`.
- Aliases are typically used to make column names more descriptive or concise in the output.

**Example**:
```sql
SELECT name AS employee_name, department_id AS dept_id
FROM employees;
```

**Explanation**: This renames `name` to `employee_name` and `department_id` to `dept_id` in the result set.

---

### 2. Table Alias

A **table alias** provides a temporary name for a table, which can simplify referencing tables in complex queries, particularly when joining tables or self-referencing a table.

**Syntax**:
```sql
SELECT column_name
FROM table_name AS alias_name;
```

- As with column aliases, `AS` is optional for table aliases in SQLite.
- Table aliases are beneficial when you need to join a table to itself or when the table names are long and complex.

**Example**:
```sql
SELECT e.name, d.department_name
FROM employees AS e
JOIN departments AS d
ON e.department_id = d.id;
```

**Explanation**: Here, `employees` is aliased as `e` and `departments` as `d`. This makes the query shorter and easier to read.

---

### Practical Examples of Using Aliases

#### Example 1: Using Column Alias in a Calculation

```sql
SELECT name, salary * 1.1 AS increased_salary
FROM employees;
```

**Explanation**: The result will display the `name` and the calculated column `increased_salary`, which represents a 10% increase on `salary`.

---

#### Example 2: Using Table Alias in a Self-Join

Table aliases are essential for performing self-joins, where a table joins with itself.

```sql
SELECT e1.name AS employee, e2.name AS manager
FROM employees AS e1
JOIN employees AS e2
ON e1.manager_id = e2.id;
```

**Explanation**: Here, `employees` is joined with itself. `e1` represents the employees, and `e2` represents the managers. The result set shows each employee along with their respective manager.

---

#### Example 3: Using Column and Table Aliases Together

```sql
SELECT e.name AS employee_name, d.department_name AS dept_name
FROM employees AS e
LEFT JOIN departments AS d
ON e.department_id = d.id;
```

**Explanation**: This query retrieves each employee’s name (`employee_name`) and their department name (`dept_name`). Aliasing both the table names and column names makes the query more readable.

---

### Summary of SQLite ALIAS Usage

- **Column Aliases**: Used to rename columns in the result for readability; defined as `column_name AS alias_name`.
- **Table Aliases**: Used to rename tables within a query, especially useful in joins; defined as `table_name AS alias_name`.
- **AS Keyword**: Optional in SQLite but often used for clarity.
  
Aliases improve readability, simplify references in complex queries, and are temporary for the duration of the query.
