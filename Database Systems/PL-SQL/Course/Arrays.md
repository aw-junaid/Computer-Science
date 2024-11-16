In PL/SQL, **arrays** (or **collections**) are used to store multiple values in a single variable. Collections in PL/SQL are similar to arrays in other programming languages but are more flexible and powerful. They allow you to group related data together for easier manipulation and access.

There are three main types of collections in PL/SQL:

1. **Associative Arrays** (formerly known as PL/SQL tables)
2. **Nested Tables**
3. **VARRAYs** (Variable-Size Arrays)

Each collection type has its use cases and advantages. Let's explore them in detail.

---

### **1. Associative Arrays (PL/SQL Tables)**

An **associative array** is a collection of key-value pairs, where the keys are either integers or strings, and the values can be any PL/SQL datatype. Associative arrays do not have a predefined size and can grow or shrink dynamically.

#### **Syntax to Declare an Associative Array:**
```sql
DECLARE
   TYPE assoc_array_type IS TABLE OF data_type INDEX BY key_type;
   v_array assoc_array_type;
BEGIN
   -- Operations
END;
```

#### **Example:**
```sql
DECLARE
   TYPE assoc_array_type IS TABLE OF VARCHAR2(50) INDEX BY PLS_INTEGER;
   v_names assoc_array_type;
BEGIN
   -- Assigning values to the array
   v_names(1) := 'Alice';
   v_names(2) := 'Bob';
   v_names(3) := 'Charlie';

   -- Retrieving values from the array
   DBMS_OUTPUT.PUT_LINE('Name at index 1: ' || v_names(1));
   DBMS_OUTPUT.PUT_LINE('Name at index 2: ' || v_names(2));
   DBMS_OUTPUT.PUT_LINE('Name at index 3: ' || v_names(3));
END;
```

#### **Key Points:**
- **Index Type**: The index can be of any scalar type (e.g., `NUMBER`, `VARCHAR2`).
- **Accessing Elements**: Elements are accessed using the index, and the index can be either an integer or string.
- **Dynamic Size**: You don't need to specify the size of the array upfront, and it grows dynamically.

---

### **2. Nested Tables**

A **nested table** is an unordered collection of elements of the same type. It is similar to an array, but unlike associative arrays, nested tables can be stored in the database as a column type.

#### **Syntax to Declare a Nested Table:**
```sql
DECLARE
   TYPE nested_table_type IS TABLE OF data_type;
   v_table nested_table_type;
BEGIN
   -- Operations
END;
```

#### **Example:**
```sql
DECLARE
   TYPE nested_table_type IS TABLE OF VARCHAR2(50);
   v_names nested_table_type;
BEGIN
   -- Extending the collection (using the EXTEND method)
   v_names.EXTEND(3); -- Adds space for 3 elements
   
   -- Assigning values to the nested table
   v_names(1) := 'Alice';
   v_names(2) := 'Bob';
   v_names(3) := 'Charlie';

   -- Retrieving values from the nested table
   DBMS_OUTPUT.PUT_LINE('Name at index 1: ' || v_names(1));
   DBMS_OUTPUT.PUT_LINE('Name at index 2: ' || v_names(2));
   DBMS_OUTPUT.PUT_LINE('Name at index 3: ' || v_names(3));
END;
```

#### **Key Points:**
- **Unordered**: Nested tables do not maintain any specific order of elements.
- **Extend**: You can use the `EXTEND` method to allocate space for a specified number of elements.
- **Size**: The size of a nested table can be dynamically increased.
- **Storage**: Nested tables can be stored in database columns, unlike associative arrays.

---

### **3. VARRAYs (Variable-Size Arrays)**

A **VARRAY** is a collection of elements of the same type, where the size is fixed when the array is created. VARRAYs are useful when you need a fixed-size collection.

#### **Syntax to Declare a VARRAY:**
```sql
DECLARE
   TYPE varray_type IS VARRAY(size) OF data_type;
   v_array varray_type;
BEGIN
   -- Operations
END;
```

#### **Example:**
```sql
DECLARE
   TYPE varray_type IS VARRAY(5) OF VARCHAR2(50);
   v_names varray_type;
BEGIN
   -- Initializing the VARRAY
   v_names := varray_type('Alice', 'Bob', 'Charlie', 'David', 'Eve');

   -- Accessing values from the VARRAY
   DBMS_OUTPUT.PUT_LINE('Name at index 1: ' || v_names(1));
   DBMS_OUTPUT.PUT_LINE('Name at index 2: ' || v_names(2));
   DBMS_OUTPUT.PUT_LINE('Name at index 3: ' || v_names(3));
   DBMS_OUTPUT.PUT_LINE('Name at index 4: ' || v_names(4));
   DBMS_OUTPUT.PUT_LINE('Name at index 5: ' || v_names(5));
END;
```

#### **Key Points:**
- **Fixed Size**: The size of a VARRAY is fixed when it is defined and cannot be changed during runtime.
- **Element Access**: Elements are accessed by index, starting from 1.
- **Storage**: VARRAYs can be stored in a database column, unlike nested tables (though nested tables can be stored too).

---

### **Collection Methods in PL/SQL**

All types of collections (associative arrays, nested tables, and VARRAYs) have common methods for manipulation:

| Method      | Description                                            | Example                          |
|-------------|--------------------------------------------------------|----------------------------------|
| **EXTEND**  | Adds elements to the collection.                       | `v_table.EXTEND(2);`            |
| **TRIM**    | Removes elements from the collection.                  | `v_table.TRIM(1);`              |
| **DELETE**  | Deletes all elements or specific elements.             | `v_table.DELETE;`               |
| **COUNT**   | Returns the number of elements in the collection.      | `v_table.COUNT;`                |
| **FIRST**   | Returns the first index of the collection.             | `v_table.FIRST;`                |
| **LAST**    | Returns the last index of the collection.              | `v_table.LAST;`                 |
| **PRIOR**   | Returns the index before a specified index.            | `v_table.PRIOR(3);`             |
| **NEXT**    | Returns the index after a specified index.             | `v_table.NEXT(2);`              |

#### **Example using `EXTEND`, `TRIM`, and `COUNT`:**
```sql
DECLARE
   TYPE nested_table_type IS TABLE OF VARCHAR2(50);
   v_names nested_table_type;
BEGIN
   -- Extend collection
   v_names.EXTEND(3); -- Adds space for 3 elements

   -- Assign values to the collection
   v_names(1) := 'Alice';
   v_names(2) := 'Bob';
   v_names(3) := 'Charlie';

   -- Count the elements in the collection
   DBMS_OUTPUT.PUT_LINE('Count: ' || v_names.COUNT);

   -- Trim the collection (remove one element)
   v_names.TRIM(1);
   
   -- Count the elements after trim
   DBMS_OUTPUT.PUT_LINE('Count after trim: ' || v_names.COUNT);
END;
```

---

### **Using Collections with Cursors**

You can use collections to fetch and manipulate multiple rows from a query.

#### **Example:**
```sql
DECLARE
   TYPE emp_table_type IS TABLE OF employees%ROWTYPE;
   v_emps emp_table_type;
BEGIN
   -- Collect data into a collection
   SELECT * BULK COLLECT INTO v_emps
   FROM employees
   WHERE department_id = 10;

   -- Iterate through the collection
   FOR i IN 1 .. v_emps.COUNT LOOP
      DBMS_OUTPUT.PUT_LINE('Employee Name: ' || v_emps(i).first_name || ' ' || v_emps(i).last_name);
   END LOOP;
END;
```

---

### **Best Practices**

1. **Choose the Right Collection Type**:
   - Use **Associative Arrays** when you need key-value pairs and do not need to store them in a database.
   - Use **Nested Tables** when you need to store data in a database or work with a dynamic collection.
   - Use **VARRAYs** for fixed-size, ordered collections.

2. **Efficient Use of `BULK COLLECT` and `FORALL`**:
   - Use `BULK COLLECT` for bulk fetching rows and `FORALL` for bulk inserts, updates, or deletes.

3. **Keep Size Limits in Mind**:
   - Be mindful of the size of collections, especially VARRAYs, as they have fixed sizes.

---

### **Practice Problems**

1. Write a PL/SQL block that:
   - Uses an associative array to store employee names and their salaries.
   - Outputs each employee's name and salary.

2. Create a nested table to store a list of phone numbers, and write a program to display all phone numbers.

3. Write a program that:
   - Uses a VARRAY to store the top 5 student grades.
   - Prints the grades in reverse order.

