In Apache Derby, a **schema** is a container for database objects like tables, views, procedures, and indexes. It provides a way to logically group related objects together and helps in organizing and managing the database structure. A schema is essentially a namespace for database objects, which ensures that object names within a schema do not conflict with those in other schemas.

### Key Concepts of Schemas in Apache Derby

1. **Namespace**: A schema acts as a namespace, so you can have multiple tables or other objects with the same name in different schemas.
2. **Default Schema**: Each user in Derby is associated with a default schema, which is used if no schema is explicitly mentioned when creating or referring to database objects.
3. **Schemas and Users**: In Derby, schemas are often linked with users. By default, the schema has the same name as the user. However, you can create and manage multiple schemas for better organization.

### Common Operations on Schemas

#### 1. **Creating a Schema**

You can create a schema using the `CREATE SCHEMA` statement. This defines a new schema within the database.

```sql
CREATE SCHEMA schema_name;
```

- **`schema_name`**: The name of the schema you want to create.

##### Example:
```sql
CREATE SCHEMA sales;
```
- This creates a schema named `sales` within the database.

#### 2. **Setting a Schema**

Once a schema is created, you can set the current schema to work with. This can be done using the `SET SCHEMA` statement.

```sql
SET SCHEMA schema_name;
```

- **`schema_name`**: The name of the schema you want to set as the current one for the session.

##### Example:
```sql
SET SCHEMA sales;
```
- This sets the `sales` schema as the current schema for the session. After this, any objects you create will be placed in the `sales` schema unless you specify a different schema.

#### 3. **Listing Schemas**

To view the schemas in a Derby database, you can query the system table `SYS.SYSTABLES`. You can use the following SQL to retrieve all schemas:

```sql
SELECT schemaid, schemaname
FROM SYS.SYSSCHEMAS;
```

- This query returns all the schemas in the current database.

#### 4. **Dropping a Schema**

To remove a schema from the database, you can use the `DROP SCHEMA` statement. However, the schema must be empty before you can drop it (i.e., it should not contain any tables, views, or other objects).

```sql
DROP SCHEMA schema_name;
```

##### Example:
```sql
DROP SCHEMA sales;
```
- This drops the `sales` schema from the database. If the schema contains objects, you must first drop them before dropping the schema.

#### 5. **Creating Objects within a Schema**

Once a schema is created, you can create various database objects within it, such as tables, views, and indexes. When specifying the name of the object, you can include the schema name as a prefix to distinguish it from objects in other schemas.

##### Example 1: Creating a Table in a Schema
```sql
CREATE TABLE sales.customers (
    customer_id INT PRIMARY KEY,
    customer_name VARCHAR(255),
    contact_name VARCHAR(255)
);
```
- This query creates a `customers` table within the `sales` schema.

##### Example 2: Creating a View in a Schema
```sql
CREATE VIEW sales.customer_summary AS
SELECT customer_id, customer_name
FROM sales.customers;
```
- This creates a view named `customer_summary` within the `sales` schema, which selects data from the `customers` table in the same schema.

#### 6. **Accessing Objects in Other Schemas**

You can access objects in other schemas by prefixing the object name with the schema name. For example:

```sql
SELECT * FROM hr.employees;
```
- This query retrieves data from the `employees` table in the `hr` schema.

If you do not specify a schema when creating an object, it will be created in the default schema associated with your user account.

### Default Schema and Schema Switching

- When you connect to the database, Derby automatically uses the schema that matches the username for your connection as the default schema.
- If you don't specify a schema when creating or referencing an object, Derby uses the default schema for the user.

#### Example of Default Schema:
```sql
-- If the user is 'admin', the default schema is 'admin'
CREATE TABLE employees (
    employee_id INT PRIMARY KEY,
    employee_name VARCHAR(255)
);
```
- This will create the `employees` table in the `admin` schema because the user is `admin` (assuming no `SET SCHEMA` was used).

To change the schema for the session, you can use the `SET SCHEMA` statement.

### Schemas and User Permissions

In Apache Derby, access to schemas and their objects is controlled by user permissions. You can manage permissions for users to access or modify objects in a schema. For example, a user can have permissions to only certain schemas, providing a way to isolate access to sensitive data.

You can grant or revoke permissions on schemas, tables, and other objects using the `GRANT` and `REVOKE` statements:

```sql
GRANT SELECT ON schema_name.* TO user_name;
REVOKE SELECT ON schema_name.* FROM user_name;
```

- The `GRANT` statement gives a user permission to access the objects within a schema.
- The `REVOKE` statement removes the user’s access to the schema.

### Example Use Case for Schemas

Consider a company that uses a Derby database to store data for different departments (e.g., **HR**, **Sales**, and **Finance**). Each department could have its own schema:

- **HR schema** could contain tables like `employees`, `departments`, and `salaries`.
- **Sales schema** could contain tables like `customers`, `orders`, and `products`.
- **Finance schema** could contain tables like `budgets`, `expenses`, and `revenues`.

This structure helps to logically separate the data and ensures that each department only has access to its own data, which can also be controlled using user permissions.

### Conclusion

Schemas in Apache Derby provide a way to organize and manage database objects in a structured and isolated manner. They allow you to create and manage groups of related objects, improving the organization and maintainability of your database. You can create, modify, and drop schemas, as well as control user access to objects within schemas. Additionally, using schemas allows you to avoid naming conflicts and provides a level of security by isolating data between different departments or users.
