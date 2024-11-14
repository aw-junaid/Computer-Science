### SQLite - Subqueries

A **subquery** (or **nested query**) is a SQL query that is embedded within another query. In SQLite, subqueries can be used in various parts of a query, such as in the `SELECT`, `FROM`, `WHERE`, and `HAVING` clauses. Subqueries allow you to perform more complex operations by using the result of one query as input to another query.

Subqueries can be used for tasks like filtering results, calculating aggregate values, or joining tables in more flexible ways.

### Types of Subqueries in SQLite

There are several types of subqueries in SQLite, including:

1. **Single-Value Subqueries (Scalar Subqueries)**
2. **Multi-Value Subqueries (In-List Subqueries)**
3. **Correlated Subqueries**
4. **Exists Subqueries**
5. **Subqueries in the `FROM` Clause**

---

### 1. **Single-Value Subqueries**

A **single-value subquery** returns a single value (scalar) and is typically used in places where a single value is expected, such as in the `SELECT`, `WHERE`, or `HAVING` clauses.

**Syntax**:
```sql
SELECT column1, column2
FROM table_name
WHERE column_name = (SELECT value FROM another_table WHERE condition);
```

**Example**:
Let's say we have two tables: `employees` and `departments`.

```sql
CREATE TABLE departments (
    department_id INTEGER PRIMARY KEY,
    department_name TEXT
);

CREATE TABLE employees (
    id INTEGER PRIMARY KEY,
    name TEXT,
    department_id INTEGER
);
```

To find the name of the employee working in a specific department (e.g., department with ID 1), we could use a single-value subquery:

```sql
SELECT name
FROM employees
WHERE department_id = (SELECT department_id FROM departments WHERE department_name = 'Sales');
```

**Explanation**: 
- The subquery `(SELECT department_id FROM departments WHERE department_name = 'Sales')` retrieves the department ID for the "Sales" department.
- The main query then selects the `name` from the `employees` table where the `department_id` matches the result of the subquery.

---

### 2. **Multi-Value Subqueries (IN Clause)**

A **multi-value subquery** returns multiple values and is often used with the `IN` operator to filter results based on multiple values. 

**Syntax**:
```sql
SELECT column1, column2
FROM table_name
WHERE column_name IN (SELECT column_name FROM another_table WHERE condition);
```

**Example**:
To find employees working in any of the departments listed in the `departments` table:

```sql
SELECT name
FROM employees
WHERE department_id IN (SELECT department_id FROM departments WHERE department_name IN ('Sales', 'Marketing'));
```

**Explanation**:
- The subquery `(SELECT department_id FROM departments WHERE department_name IN ('Sales', 'Marketing'))` returns multiple department IDs (for Sales and Marketing).
- The main query then retrieves all employees who belong to either of those departments.

---

### 3. **Correlated Subqueries**

A **correlated subquery** is a subquery that references columns from the outer query. The subquery is evaluated once for each row processed by the outer query. This makes correlated subqueries more flexible but potentially less efficient, as they may require the subquery to be re-executed for each row.

**Syntax**:
```sql
SELECT column1, column2
FROM table1
WHERE column_name = (SELECT column_name FROM table2 WHERE table1.column = table2.column);
```

**Example**:
To find employees whose salary is higher than the average salary in their department:

```sql
SELECT e.name, e.salary
FROM employees e
WHERE e.salary > (SELECT AVG(salary) 
                  FROM employees 
                  WHERE department_id = e.department_id);
```

**Explanation**:
- The subquery `(SELECT AVG(salary) FROM employees WHERE department_id = e.department_id)` is correlated because it references `e.department_id` from the outer query.
- For each employee, the subquery calculates the average salary for their department, and the outer query selects employees whose salary is greater than that average.

---

### 4. **Exists Subqueries**

An **`EXISTS` subquery** is used to check whether a subquery returns any rows. It is typically used with a `WHERE` clause to filter results based on the existence of related data in another table.

**Syntax**:
```sql
SELECT column1
FROM table_name
WHERE EXISTS (SELECT 1 FROM another_table WHERE condition);
```

**Example**:
To find employees who belong to departments that have at least one employee:

```sql
SELECT name
FROM employees e
WHERE EXISTS (SELECT 1 
              FROM employees 
              WHERE department_id = e.department_id);
```

**Explanation**:
- The subquery `(SELECT 1 FROM employees WHERE department_id = e.department_id)` checks if there is at least one employee in the same department as the current employee.
- The `EXISTS` condition returns `TRUE` if the subquery returns one or more rows, and the outer query will include the employee in the result.

---

### 5. **Subqueries in the `FROM` Clause**

A subquery in the `FROM` clause allows you to treat the result of a subquery as a temporary table. This is useful when you need to perform multiple operations on the same result set, like grouping or joining.

**Syntax**:
```sql
SELECT column1, column2
FROM (SELECT column1, column2 FROM table_name WHERE condition) AS alias_name;
```

**Example**:
To calculate the average salary in each department and select only those departments where the average salary is greater than a certain value:

```sql
SELECT department_id, avg_salary
FROM (SELECT department_id, AVG(salary) AS avg_salary
      FROM employees
      GROUP BY department_id) AS dept_avg
WHERE dept_avg.avg_salary > 50000;
```

**Explanation**:
- The subquery `(SELECT department_id, AVG(salary) AS avg_salary FROM employees GROUP BY department_id)` calculates the average salary for each department.
- The main query then filters these departments, selecting only those where the average salary is greater than 50,000.

---

### Subquery Performance Considerations

- **Efficiency**: Subqueries, particularly correlated subqueries, can be less efficient than joins because they may require the subquery to be executed multiple times (once for each row in the outer query). In some cases, rewriting subqueries as joins can improve performance.
  
- **Execution Plan**: Use `EXPLAIN QUERY PLAN` to analyze the performance of queries with subqueries and to determine if they can be optimized (e.g., using indexes or rewriting with joins).

---

### Summary of Subqueries in SQLite

- **Single-Value Subqueries**: Return a single value and are used in conditions that expect a single result, like `=` or `>` operators.
- **Multi-Value Subqueries**: Return multiple values and are typically used with the `IN` or `NOT IN` operators.
- **Correlated Subqueries**: Reference columns from the outer query and are evaluated for each row processed by the outer query.
- **Exists Subqueries**: Check for the existence of rows in the subquery and return `TRUE` or `FALSE` based on whether the subquery returns any rows.
- **Subqueries in the `FROM` Clause**: Allow you to treat the result of a subquery as a temporary table for further querying.

Subqueries are a powerful feature in SQLite that allows you to perform complex queries and data manipulation in a more flexible way. However, it is important to consider performance, especially when dealing with large datasets or complex correlated subqueries.
