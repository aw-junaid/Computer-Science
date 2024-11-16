In PL/SQL, **strings** are sequences of characters that can be manipulated using string functions, operators, and various PL/SQL constructs. Strings are stored in variables of character datatypes like `VARCHAR2`, `CHAR`, `CLOB`, etc.

---

### **PL/SQL String Datatypes**

| Datatype     | Description                                                                 | Example          |
|--------------|-----------------------------------------------------------------------------|------------------|
| **VARCHAR2** | Variable-length string with a maximum size (up to 32767 bytes in PL/SQL).   | `VARCHAR2(50)`   |
| **CHAR**     | Fixed-length string; padded with spaces if value is shorter.               | `CHAR(10)`       |
| **CLOB**     | Used for large strings (up to 4 GB).                                        | `CLOB`           |
| **NCHAR**    | Fixed-length string for storing Unicode characters.                        | `NCHAR(10)`      |
| **NVARCHAR2**| Variable-length string for storing Unicode characters.                     | `NVARCHAR2(50)`  |

---

### **Declaring String Variables**

#### **Example**
```sql
DECLARE
   v_first_name VARCHAR2(50) := 'John';
   v_last_name CHAR(10) := 'Doe';
   v_message CLOB;
BEGIN
   v_message := 'This is a long string stored in a CLOB variable.';
   DBMS_OUTPUT.PUT_LINE('Full Name: ' || v_first_name || ' ' || v_last_name);
END;
```

---

### **String Operators**

| Operator | Description             | Example                       | Result          |
|----------|-------------------------|-------------------------------|-----------------|
| `||`     | Concatenation operator  | `'Hello' || ' ' || 'World'`   | `Hello World`   |

#### **Example**
```sql
DECLARE
   v_greeting VARCHAR2(50);
BEGIN
   v_greeting := 'Hello' || ' ' || 'PL/SQL!';
   DBMS_OUTPUT.PUT_LINE(v_greeting); -- Outputs: Hello PL/SQL!
END;
```

---

### **String Functions**

PL/SQL provides a wide range of built-in functions to manipulate strings.

#### **1. Character Manipulation**

| Function        | Description                                       | Example                                  | Result            |
|------------------|---------------------------------------------------|------------------------------------------|-------------------|
| **UPPER**       | Converts string to uppercase.                     | `UPPER('hello')`                         | `HELLO`           |
| **LOWER**       | Converts string to lowercase.                     | `LOWER('HELLO')`                         | `hello`           |
| **INITCAP**     | Capitalizes the first letter of each word.         | `INITCAP('hello world')`                 | `Hello World`     |
| **LENGTH**      | Returns the length of the string.                 | `LENGTH('PL/SQL')`                       | `6`               |

#### **Example**
```sql
DECLARE
   v_text VARCHAR2(50) := 'hello world';
BEGIN
   DBMS_OUTPUT.PUT_LINE('Uppercase: ' || UPPER(v_text));
   DBMS_OUTPUT.PUT_LINE('Lowercase: ' || LOWER(v_text));
   DBMS_OUTPUT.PUT_LINE('Title Case: ' || INITCAP(v_text));
   DBMS_OUTPUT.PUT_LINE('Length: ' || LENGTH(v_text));
END;
```

---

#### **2. Substring Functions**

| Function      | Description                                           | Example                        | Result   |
|---------------|-------------------------------------------------------|--------------------------------|----------|
| **SUBSTR**    | Extracts a substring from the string.                | `SUBSTR('Hello', 2, 3)`        | `ell`    |
| **INSTR**     | Returns the position of a substring.                 | `INSTR('Hello', 'l')`          | `3`      |
| **LPAD**      | Left-pads the string with a specified character.      | `LPAD('123', 5, '0')`          | `00123`  |
| **RPAD**      | Right-pads the string with a specified character.     | `RPAD('123', 5, '0')`          | `12300`  |

#### **Example**
```sql
DECLARE
   v_text VARCHAR2(50) := 'PL/SQL Programming';
BEGIN
   DBMS_OUTPUT.PUT_LINE('Substring: ' || SUBSTR(v_text, 4, 3)); -- Outputs: SQL
   DBMS_OUTPUT.PUT_LINE('Position of "SQL": ' || INSTR(v_text, 'SQL')); -- Outputs: 4
   DBMS_OUTPUT.PUT_LINE('Left Padded: ' || LPAD('99', 5, '*')); -- Outputs: ***99
   DBMS_OUTPUT.PUT_LINE('Right Padded: ' || RPAD('99', 5, '*')); -- Outputs: 99***
END;
```

---

#### **3. Trimming Functions**

| Function      | Description                                    | Example                      | Result         |
|---------------|------------------------------------------------|------------------------------|----------------|
| **TRIM**      | Removes leading and trailing spaces or characters. | `TRIM(' x ')`                | `x`            |
| **LTRIM**     | Removes leading spaces or characters.          | `LTRIM('   x')`              | `x`            |
| **RTRIM**     | Removes trailing spaces or characters.         | `RTRIM('x   ')`              | `x`            |

#### **Example**
```sql
DECLARE
   v_text VARCHAR2(50) := '   PL/SQL   ';
BEGIN
   DBMS_OUTPUT.PUT_LINE('Trimmed: ' || TRIM(v_text)); -- Outputs: PL/SQL
   DBMS_OUTPUT.PUT_LINE('Left Trimmed: ' || LTRIM(v_text)); -- Outputs: PL/SQL   
   DBMS_OUTPUT.PUT_LINE('Right Trimmed: ' || RTRIM(v_text)); -- Outputs:    PL/SQL
END;
```

---

#### **4. String Comparison**

| Function           | Description                                          | Example                    | Result |
|--------------------|------------------------------------------------------|----------------------------|--------|
| **CHR**            | Returns the character for an ASCII code.            | `CHR(65)`                  | `A`    |
| **ASCII**          | Returns the ASCII code of a character.              | `ASCII('A')`               | `65`   |
| **REPLACE**        | Replaces occurrences of a substring.                | `REPLACE('HELLO', 'L', 'X')` | `HEXXO` |

#### **Example**
```sql
DECLARE
   v_text VARCHAR2(50) := 'HELLO';
BEGIN
   DBMS_OUTPUT.PUT_LINE('Replace L with X: ' || REPLACE(v_text, 'L', 'X')); -- Outputs: HEXXO
   DBMS_OUTPUT.PUT_LINE('ASCII of H: ' || ASCII('H')); -- Outputs: 72
   DBMS_OUTPUT.PUT_LINE('Character for 65: ' || CHR(65)); -- Outputs: A
END;
```

---

### **Dynamic SQL with Strings**

PL/SQL allows combining strings to build dynamic SQL statements.

#### **Example**
```sql
DECLARE
   v_table_name VARCHAR2(50) := 'employees';
   v_sql VARCHAR2(200);
BEGIN
   v_sql := 'SELECT COUNT(*) FROM ' || v_table_name;
   DBMS_OUTPUT.PUT_LINE('Generated SQL: ' || v_sql);
END;
```

---

### **Best Practices**

1. **Use VARCHAR2 for Flexibility**:
   - Prefer `VARCHAR2` for variable-length strings instead of `CHAR`.
2. **Limit String Length**:
   - Always specify the maximum length for string variables to avoid memory issues.
3. **Avoid Unnecessary Concatenation**:
   - Minimize concatenation inside loops for better performance.
4. **Use String Functions Judiciously**:
   - Optimize string manipulations to avoid unnecessary computations.

---

### **Practice Problems**

1. Write a PL/SQL block to:
   - Reverse a string using `SUBSTR` in a loop.
   - Count the number of vowels in a given string.

2. Create a PL/SQL block that takes a user’s full name (as a single string) and outputs:
   - First name
   - Last name
   - Length of the full name

3. Write a dynamic SQL query that generates a `SELECT` statement to fetch the top 5 rows from a given table.

