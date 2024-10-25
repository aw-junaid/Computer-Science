The `CREATE SCHEMA` command in PostgreSQL is used to create a new schema within a database. A schema is a way to organize database objects, such as tables, views, and functions, into separate namespaces. Here's a guide on how to use the `CREATE SCHEMA` command:

## 1. **Basic Usage**

To create a new schema, use the following syntax:

```sql
CREATE SCHEMA schema_name;
```

For example, to create a schema named `sales`:

```sql
CREATE SCHEMA sales;
```

## 2. **Creating a Schema with an Owner**

You can specify the owner of the schema using the `AUTHORIZATION` clause:

```sql
CREATE SCHEMA schema_name AUTHORIZATION owner_name;
```

For example:

```sql
CREATE SCHEMA sales AUTHORIZATION sales_manager;
```

## 3. **Creating a Schema with Access Privileges**

You can also specify access privileges for the schema:

```sql
CREATE SCHEMA schema_name
    [ AUTHORIZATION owner_name ]
    [ schema_element [, ...] ]
    [ schema_privilege [, ...] ];
```

For example:

```sql
CREATE SCHEMA sales AUTHORIZATION sales_manager
    CREATE TABLE t1 (c1 INT);
```

## 4. **Creating a Schema with Default Privileges**

You can set default privileges for objects created within the schema:

```sql
CREATE SCHEMA schema_name
    [ AUTHORIZATION owner_name ]
    [ schema_element [, ...] ]
    [ schema_privilege [, ...] ]
    [ DEFAULT PRIVILEGES default_privileges ];
```

For example:

```sql
CREATE SCHEMA sales AUTHORIZATION sales_manager
    CREATE TABLE t1 (c1 INT)
    DEFAULT PRIVILEGES GRANT ALL ON TABLES TO PUBLIC;
```

## 5. **Viewing Schemas**

You can query the `pg_namespace` system catalog to view the existing schemas:

```sql
SELECT nspname FROM pg_namespace;
```

## 6. **Setting Search Path**

The search path determines the order in which schemas are searched for objects. You can set the search path for a session:

```sql
SET search_path TO schema_name, ...;
```

For example:

```sql
SET search_path TO sales, public;
```

## 7. **Dropping a Schema**

To drop a schema, you can use the `DROP SCHEMA` command:

```sql
DROP SCHEMA schema_name;
```

## 8. **Dropping a Schema with Cascade**

If you want to drop a schema along with all objects contained within it, you can use:

```sql
DROP SCHEMA schema_name CASCADE;
```

By following these steps, you can effectively use the `CREATE SCHEMA` command in PostgreSQL to create new namespaces for organizing database objects. Schemas are a powerful way to manage the structure of a database, especially in multi-tenant environments or when dealing with multiple applications within a single database. Remember to plan your schema organization carefully to optimize your database structure.
