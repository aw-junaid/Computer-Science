In Apache Derby, the `ALTER TABLE` statement is used to modify the structure of an existing table. You can use this statement to add, modify, or drop columns, as well as rename the table or columns.

### Basic Syntax of `ALTER TABLE`
```sql
ALTER TABLE table_name
action;
```
Where `action` is one of the following operations, such as adding a column, modifying a column, or dropping a column.

### Operations in `ALTER TABLE` Statement

1. **Add a New Column**  
   To add a new column to an existing table:
   ```sql
   ALTER TABLE table_name
   ADD column_name column_definition;
   ```
   - **`column_name`**: The name of the new column.
   - **`column_definition`**: The data type and any constraints for the new column.

   #### Example:
   ```sql
   ALTER TABLE employees
   ADD middle_name VARCHAR(50);
   ```
   - This query adds a new column `middle_name` of type `VARCHAR(50)` to the `employees` table.

2. **Modify an Existing Column**  
   To change the definition of an existing column (such as changing the data type, or modifying the size of a column):
   ```sql
   ALTER TABLE table_name
   ALTER COLUMN column_name SET DATA TYPE new_data_type;
   ```
   - **`column_name`**: The name of the column to modify.
   - **`new_data_type`**: The new data type for the column.

   #### Example:
   ```sql
   ALTER TABLE employees
   ALTER COLUMN salary SET DATA TYPE DECIMAL(15, 2);
   ```
   - This query modifies the `salary` column to have the data type `DECIMAL(15, 2)`.

   **Note:** Changing the data type of a column can cause issues if the existing data does not match the new type. Always check compatibility before altering the column type.

3. **Drop a Column**  
   To remove a column from an existing table:
   ```sql
   ALTER TABLE table_name
   DROP COLUMN column_name;
   ```
   - **`column_name`**: The name of the column to be removed.

   #### Example:
   ```sql
   ALTER TABLE employees
   DROP COLUMN middle_name;
   ```
   - This query removes the `middle_name` column from the `employees` table.

4. **Rename a Column**  
   To rename a column in an existing table, use the `RENAME COLUMN` clause:
   ```sql
   ALTER TABLE table_name
   RENAME COLUMN old_column_name TO new_column_name;
   ```
   - **`old_column_name`**: The current name of the column.
   - **`new_column_name`**: The new name for the column.

   #### Example:
   ```sql
   ALTER TABLE employees
   RENAME COLUMN hire_date TO date_of_hire;
   ```
   - This query renames the `hire_date` column to `date_of_hire` in the `employees` table.

5. **Rename a Table**  
   To rename an existing table, use the `RENAME TO` clause:
   ```sql
   ALTER TABLE old_table_name
   RENAME TO new_table_name;
   ```
   - **`old_table_name`**: The current name of the table.
   - **`new_table_name`**: The new name for the table.

   #### Example:
   ```sql
   ALTER TABLE employees
   RENAME TO staff;
   ```
   - This query renames the `employees` table to `staff`.

6. **Add a Primary Key Constraint**  
   To add a primary key constraint to an existing table:
   ```sql
   ALTER TABLE table_name
   ADD CONSTRAINT constraint_name PRIMARY KEY (column_name);
   ```
   - **`constraint_name`**: The name of the constraint.
   - **`column_name`**: The column or columns to be part of the primary key.

   #### Example:
   ```sql
   ALTER TABLE employees
   ADD CONSTRAINT pk_employee_id PRIMARY KEY (employee_id);
   ```
   - This query adds a primary key constraint on the `employee_id` column in the `employees` table.

7. **Add a Foreign Key Constraint**  
   To add a foreign key constraint to an existing table:
   ```sql
   ALTER TABLE table_name
   ADD CONSTRAINT constraint_name FOREIGN KEY (column_name) REFERENCES other_table (column_name);
   ```
   - **`constraint_name`**: The name of the constraint.
   - **`column_name`**: The column in the current table that will reference another table.
   - **`other_table`**: The table containing the column to which the foreign key refers.
   - **`column_name`**: The column in the referenced table.

   #### Example:
   ```sql
   ALTER TABLE employees
   ADD CONSTRAINT fk_department FOREIGN KEY (department_id) REFERENCES departments(department_id);
   ```
   - This query adds a foreign key constraint to the `department_id` column in the `employees` table, referencing the `department_id` column in the `departments` table.

8. **Drop a Constraint**  
   To remove a constraint from an existing table, use the `DROP CONSTRAINT` clause:
   ```sql
   ALTER TABLE table_name
   DROP CONSTRAINT constraint_name;
   ```
   - **`constraint_name`**: The name of the constraint to be removed.

   #### Example:
   ```sql
   ALTER TABLE employees
   DROP CONSTRAINT fk_department;
   ```
   - This query removes the `fk_department` foreign key constraint from the `employees` table.

### Notes on `ALTER TABLE`:
- **Column Modifications**: In Apache Derby, certain column modifications (such as changing a column’s data type or adding a unique constraint) may require rebuilding the table, which can lead to performance overhead on large datasets.
- **Unsupported Operations**: Some advanced operations (like renaming constraints or changing default values) may not be supported directly in Apache Derby or may require alternative approaches (such as dropping and recreating constraints).
- **Index Updates**: If a column is involved in an index and is modified (e.g., its data type is changed), you might need to drop and recreate the index for optimal performance.

### Conclusion
The `ALTER TABLE` statement in Apache Derby is a versatile tool for modifying the structure of an existing table. You can add or drop columns, rename columns or tables, and add or drop constraints. However, care should be taken when altering columns, especially with respect to data type changes, as they can lead to data compatibility issues.
