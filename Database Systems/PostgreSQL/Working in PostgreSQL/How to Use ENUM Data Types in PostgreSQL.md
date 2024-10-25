Using ENUM data types in PostgreSQL allows you to define a list of predefined values that a column can take. This provides a way to enforce a specific set of allowed values for a column. Here's a guide on how to use ENUM data types:

## 1. **Create an ENUM Type**

You can create an ENUM type using the `CREATE TYPE` command:

```sql
CREATE TYPE status_enum AS ENUM ('active', 'inactive', 'deleted');
```

This creates a type called `status_enum` with three allowed values: `'active'`, `'inactive'`, and `'deleted'`.

## 2. **Create a Table with ENUM Column**

Next, create a table with a column of type `status_enum`:

```sql
CREATE TABLE my_table (
    id serial PRIMARY KEY,
    status status_enum
);
```

Now, the `status` column can only take one of the three allowed values.

## 3. **Inserting Data**

You can insert data into the table, making sure to use one of the allowed ENUM values:

```sql
INSERT INTO my_table (status) VALUES ('active');
```

## 4. **Querying Data**

You can query data from the table as usual:

```sql
SELECT * FROM my_table WHERE status = 'active';
```

## 5. **Updating Data**

You can update the ENUM column with one of the allowed values:

```sql
UPDATE my_table SET status = 'inactive' WHERE id = 1;
```

## 6. **Adding New Values to ENUM**

You can add new values to an existing ENUM type using the `ALTER TYPE` command:

```sql
ALTER TYPE status_enum ADD VALUE 'pending';
```

This adds a new value `'pending'` to the `status_enum`.

## 7. **Removing Values from ENUM**

You can remove values from an ENUM type, but this should be done carefully to avoid breaking existing data. If the value being removed is currently in use, it may cause errors.

```sql
-- First, redefine the type without the value to be removed
CREATE TYPE new_status_enum AS ENUM ('active', 'inactive', 'deleted');

-- Then, alter the column to use the new type
ALTER TABLE my_table ALTER COLUMN status TYPE new_status_enum USING status::text::new_status_enum;
```

## 8. **Dropping an ENUM Type**

To drop an ENUM type, you must first make sure it's not being used in any table. Once you've removed any dependencies, you can drop the type:

```sql
DROP TYPE status_enum;
```

## 9. **Using Default Values**

You can set a default value for an ENUM column:

```sql
ALTER TABLE my_table ALTER COLUMN status SET DEFAULT 'active';
```

## 10. **Using ENUM with Constraints**

You can use an ENUM as part of a check constraint:

```sql
ALTER TABLE my_table ADD CONSTRAINT valid_status CHECK (status IN ('active', 'inactive', 'deleted'));
```

By following these steps, you can effectively use ENUM data types in PostgreSQL to enforce a specific set of allowed values for a column. Remember to validate and handle ENUM values properly to ensure data integrity and security.
