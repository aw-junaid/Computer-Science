In PL/SQL, **constants** and **literals** are important concepts used to represent fixed values in code. They ensure immutability and clarity when defining fixed values or expressions in your program.

---

### **Constants**
A constant is a variable whose value, once set, cannot be changed during the program's execution.

#### **Declaring a Constant**
Syntax:
```sql
constant_name CONSTANT data_type := value;
```

- **`constant_name`**: The name of the constant.
- **`CONSTANT`**: Specifies that the value is unchangeable.
- **`data_type`**: Specifies the type of the constant.
- **`value`**: The initial (and only) value of the constant. This is mandatory.

#### **Example: Declaring Constants**
```sql
DECLARE
   c_pi CONSTANT NUMBER := 3.14159;  -- Constant for Pi
   c_company_name CONSTANT VARCHAR2(50) := 'Oracle Corp';
BEGIN
   DBMS_OUTPUT.PUT_LINE('Pi: ' || c_pi);
   DBMS_OUTPUT.PUT_LINE('Company: ' || c_company_name);
   -- c_pi := 3.2; -- This would raise an error because c_pi is a constant.
END;
```

#### **Why Use Constants?**
1. **Immutability**: Prevents accidental changes to critical values.
2. **Clarity**: Improves code readability by giving meaningful names to fixed values.
3. **Maintenance**: Centralizes fixed values, making updates easier.

---

### **Literals**
Literals are fixed, direct values that you use in your PL/SQL program. They can be numeric, character, string, or date values.

#### **Types of Literals**

1. **Numeric Literals**
   - Used for numbers.
   - Can be integer or floating-point.
   ```sql
   DECLARE
      v_number1 NUMBER := 42;         -- Integer literal
      v_number2 NUMBER := 3.14;      -- Floating-point literal
   BEGIN
      DBMS_OUTPUT.PUT_LINE(v_number1);
      DBMS_OUTPUT.PUT_LINE(v_number2);
   END;
   ```

2. **String Literals**
   - Enclosed in single quotes.
   - Used for character or text values.
   ```sql
   DECLARE
      v_name VARCHAR2(50) := 'John';
   BEGIN
      DBMS_OUTPUT.PUT_LINE('Hello, ' || v_name);
   END;
   ```

   - **Escaping Single Quotes**:
     Use two single quotes to include one in the string.
     ```sql
     DECLARE
        v_quote VARCHAR2(50) := 'It''s a good day!';
     BEGIN
        DBMS_OUTPUT.PUT_LINE(v_quote);
     END;
     ```

3. **Date Literals**
   - Use the `DATE` or `TO_DATE` function to specify date values.
   ```sql
   DECLARE
      v_date DATE := TO_DATE('2024-01-01', 'YYYY-MM-DD'); -- Date literal
   BEGIN
      DBMS_OUTPUT.PUT_LINE('Date: ' || TO_CHAR(v_date, 'DD-MON-YYYY'));
   END;
   ```

4. **Boolean Literals**
   - `TRUE`, `FALSE`, and `NULL` are valid Boolean literals.
   ```sql
   DECLARE
      v_flag BOOLEAN := TRUE;
   BEGIN
      IF v_flag THEN
         DBMS_OUTPUT.PUT_LINE('The flag is TRUE.');
      END IF;
   END;
   ```

---

### **Using Constants and Literals Together**

#### Example: Constants and Literals in Operations
```sql
DECLARE
   c_tax_rate CONSTANT NUMBER := 0.18;  -- Tax rate constant
   v_price NUMBER := 100;               -- Price literal
   v_tax NUMBER;
BEGIN
   v_tax := v_price * c_tax_rate;       -- Using constant and literal
   DBMS_OUTPUT.PUT_LINE('Tax: ' || v_tax);
END;
```

#### Example: Combining String Literals with Constants
```sql
DECLARE
   c_app_name CONSTANT VARCHAR2(20) := 'MyApp';
   v_message VARCHAR2(100);
BEGIN
   v_message := 'Welcome to ' || c_app_name || '!';
   DBMS_OUTPUT.PUT_LINE(v_message);
END;
```

---

### **Key Points**
1. **Constants**:
   - Must be initialized during declaration.
   - Their value cannot be changed after declaration.
2. **Literals**:
   - Are directly written fixed values in the code.
   - Can be of different types: numeric, string, date, and boolean.

---

### **Practice Examples**

#### Example 1: Calculating Area of a Circle
```sql
DECLARE
   c_pi CONSTANT NUMBER := 3.14159;  -- Constant for Pi
   v_radius NUMBER := 5;            -- Radius literal
   v_area NUMBER;
BEGIN
   v_area := c_pi * v_radius * v_radius; -- Formula: πr²
   DBMS_OUTPUT.PUT_LINE('Area of Circle: ' || v_area);
END;
```

#### Example 2: String Formatting
```sql
DECLARE
   c_company CONSTANT VARCHAR2(30) := 'Oracle';
   c_tagline CONSTANT VARCHAR2(50) := 'Your Data Partner';
BEGIN
   DBMS_OUTPUT.PUT_LINE('Company: ' || c_company || ' - ' || c_tagline);
END;
```

