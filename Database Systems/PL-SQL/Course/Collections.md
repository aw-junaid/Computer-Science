In PL/SQL, **collections** are data structures that allow you to store multiple values in a single variable. Collections are useful when you need to handle multiple rows or a list of values in a program, and they can be used to improve the performance and readability of your PL/SQL code.

PL/SQL collections can be classified into three main types:

1. **Associative Arrays (formerly known as PL/SQL Tables)**: A collection of key-value pairs, where each key is unique and can be of any scalar type.
2. **Nested Tables**: A collection of ordered elements, similar to arrays, but they are more flexible and can be sparse (i.e., elements are not required to be continuous).
3. **Varrays (Variable-Size Arrays)**: A collection of ordered elements, but with a fixed upper bound for the number of elements.

### **Types of Collections in PL/SQL**

---

### **1. Associative Arrays (PL/SQL Tables)**

Associative arrays are like hash tables or dictionaries. They are collections of key-value pairs, where the keys are unique and can be of any scalar data type (e.g., `NUMBER`, `VARCHAR2`, etc.). These are often used for dynamically storing data in memory.

#### **Key Characteristics of Associative Arrays**:
- Keys can be any scalar type (e.g., `NUMBER`, `VARCHAR2`).
- They are not stored in the database; they exist only in memory during program execution.
- Unlike traditional arrays, the indices can be non-contiguous (e.g., 1, 3, 5) and are not automatically assigned by PL/SQL.

#### **Example: Associative Array**

```sql
DECLARE
   TYPE employee_salary_table IS TABLE OF NUMBER INDEX BY VARCHAR2(20);
   employee_salaries employee_salary_table;
BEGIN
   -- Assigning values using employee IDs (keys)
   employee_salaries('E001') := 50000;
   employee_salaries('E002') := 60000;
   employee_salaries('E003') := 55000;
   
   -- Accessing values
   DBMS_OUTPUT.PUT_LINE('Salary of E001: ' || employee_salaries('E001'));
   DBMS_OUTPUT.PUT_LINE('Salary of E002: ' || employee_salaries('E002'));
END;
```

Explanation:
- **`employee_salary_table`** is an associative array that holds employee salaries, where the employee ID (a `VARCHAR2`) is the key and the salary (a `NUMBER`) is the value.
- The array elements are accessed by key (e.g., `'E001'`), not by index.

---

### **2. Nested Tables**

A **nested table** is similar to an array, but it can hold a variable number of elements and is more flexible than an associative array. Nested tables are stored in the database, which allows you to persist the data in the database if necessary.

#### **Key Characteristics of Nested Tables**:
- Elements are ordered.
- Can store an arbitrary number of elements.
- Can be sparse, meaning the table doesn’t require contiguous elements.
- Can be stored in the database as a column type.
  
#### **Example: Nested Table**

```sql
DECLARE
   TYPE salary_table IS TABLE OF NUMBER;
   salaries salary_table := salary_table(50000, 60000, 55000);
BEGIN
   -- Accessing elements of the nested table by index
   DBMS_OUTPUT.PUT_LINE('Salary at index 1: ' || salaries(1));
   DBMS_OUTPUT.PUT_LINE('Salary at index 2: ' || salaries(2));
   DBMS_OUTPUT.PUT_LINE('Salary at index 3: ' || salaries(3));
   
   -- Adding a new salary to the nested table
   salaries.EXTEND;  -- Adds a new element
   salaries(4) := 65000;
   
   DBMS_OUTPUT.PUT_LINE('New salary at index 4: ' || salaries(4));
END;
```

Explanation:
- **`salary_table`** is a nested table that holds the salaries of employees.
- **`EXTEND`** method is used to add a new element to the nested table.
- Unlike associative arrays, nested tables can be resized dynamically and can hold a variable number of elements.

---

### **3. Varrays (Variable-Size Arrays)**

A **VARRAY** (variable-size array) is an ordered collection of elements with a fixed size limit. It is a more restricted form of collection than a nested table but offers better performance when the number of elements is known ahead of time. The size limit for a VARRAY is specified when it is defined.

#### **Key Characteristics of Varrays**:
- Varrays have a fixed upper bound for the number of elements.
- All elements must be contiguous, meaning the indices must be sequential.
- They are suitable for situations where the number of elements is known and fixed.

#### **Example: Varray**

```sql
DECLARE
   TYPE salary_varray IS VARRAY(5) OF NUMBER;  -- Fixed size of 5
   salaries salary_varray := salary_varray(50000, 60000, 55000);
BEGIN
   -- Accessing elements of the VARRAY by index
   DBMS_OUTPUT.PUT_LINE('Salary at index 1: ' || salaries(1));
   DBMS_OUTPUT.PUT_LINE('Salary at index 2: ' || salaries(2));
   DBMS_OUTPUT.PUT_LINE('Salary at index 3: ' || salaries(3));
   
   -- Adding a new salary (only works if it doesn't exceed the size limit)
   salaries.EXTEND;  -- Adds a new element
   salaries(4) := 65000;
   
   DBMS_OUTPUT.PUT_LINE('New salary at index 4: ' || salaries(4));
END;
```

Explanation:
- **`salary_varray`** is a VARRAY with a maximum size of 5 elements.
- You can extend the VARRAY using `EXTEND`, but you can't exceed the size limit (5 in this case).
- Varrays are typically used in cases where the number of elements is small and fixed.

---

### **Operations on Collections**

PL/SQL collections support a number of built-in methods for managing and manipulating the data:

1. **`EXTEND(n)`**: Adds `n` elements to the collection. If `n` is omitted, it adds one element.
   - Example: `salary_table.EXTEND;`
   
2. **`TRIM(n)`**: Removes `n` elements from the collection.
   - Example: `salary_table.TRIM(1);`
   
3. **`DELETE(i)`**: Deletes the element at index `i` from the collection. If `i` is omitted, all elements are deleted.
   - Example: `salary_table.DELETE(2);`
   
4. **`COUNT`**: Returns the number of elements in the collection.
   - Example: `DBMS_OUTPUT.PUT_LINE(salary_table.COUNT);`
   
5. **`FIRST` and `LAST`**: Return the first and last index of a collection, respectively.
   - Example: `DBMS_OUTPUT.PUT_LINE(salary_table.FIRST);`

6. **`NEXT(i)`**: Returns the next index after `i` in the collection.
   - Example: `DBMS_OUTPUT.PUT_LINE(salary_table.NEXT(1));`

---

### **Collection Types in Database Tables**

You can also use collections in database tables as columns. For example, you can define a **nested table** or **VARRAY** as a column type and store multiple values in a single row.

```sql
CREATE TYPE salary_varray_type IS VARRAY(10) OF NUMBER;
CREATE TABLE employees (
    employee_id NUMBER,
    employee_salaries salary_varray_type
);
```

In this example, `employee_salaries` is a column that stores a `VARRAY` of numbers in the `employees` table.

---

### **Collection Iteration**

To iterate over the elements of a collection, you can use a **FOR loop**. For example, if you want to print all the salaries stored in a nested table:

```sql
DECLARE
   TYPE salary_table IS TABLE OF NUMBER;
   salaries salary_table := salary_table(50000, 60000, 55000);
BEGIN
   FOR i IN 1 .. salaries.COUNT LOOP
      DBMS_OUTPUT.PUT_LINE('Salary at index ' || i || ': ' || salaries(i));
   END LOOP;
END;
```

---

### **Summary**

- **Associative Arrays**: Store key-value pairs, where keys can be of any scalar data type. They are used when you need to map unique keys to values.
- **Nested Tables**: Store an ordered set of elements, and can be stored in the database.
- **Varrays**: Store an ordered set of elements with a fixed size limit. They are ideal for cases where the number of elements is known and fixed.
- **Operations on Collections**: Use methods like `EXTEND`, `TRIM`, `DELETE`, and `COUNT` to manage collections.
- **Iteration**: Use a `FOR` loop to iterate through the elements of a collection.

