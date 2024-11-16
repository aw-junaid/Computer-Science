In PL/SQL, **Object-Oriented Programming (OOP)** features allow developers to model complex data and behavior using **objects**, which are instances of **object types**. Oracle PL/SQL enables object-oriented programming through the use of **Object Types** and **Methods**. These features allow you to encapsulate data (attributes) and functionality (methods) together into a single unit, offering a more structured way of organizing code.

---

### **Key Concepts of Object-Oriented PL/SQL**

1. **Object Types**: An object type defines the structure of an object, including its attributes and methods. An object type consists of:
   - **Attributes**: Data fields (variables) that define the properties of an object.
   - **Methods**: Procedures or functions that define the behavior or operations that can be performed on the object.

2. **Instantiating Objects**: Once an object type is defined, you can create instances of that object type in PL/SQL.

3. **Inheritance (Limited)**: Oracle PL/SQL supports a form of inheritance where one object type can inherit attributes and methods from another object type, though it's not as flexible as in some other OOP languages like Java.

4. **Encapsulation**: You can encapsulate data and methods in an object, hiding the details of implementation and allowing access to object attributes only through defined methods.

5. **Polymorphism**: Oracle supports polymorphism through method overloading and overriding, which allows multiple methods with the same name but different signatures to be used based on the context.

---

### **Creating Object Types in PL/SQL**

#### **Defining an Object Type**

You define an object type using the `CREATE TYPE` statement, specifying its attributes (variables) and methods (procedures or functions).

##### **Example: Object Type Definition**

```sql
CREATE OR REPLACE TYPE Employee AS OBJECT (
   emp_id      NUMBER,
   emp_name    VARCHAR2(100),
   emp_salary  NUMBER,
   
   MEMBER FUNCTION get_salary RETURN NUMBER,
   MEMBER PROCEDURE raise_salary (percent IN NUMBER)
);
```

- **Attributes**: `emp_id`, `emp_name`, `emp_salary`.
- **Methods**:
   - `get_salary`: A function that returns the salary.
   - `raise_salary`: A procedure that raises the employee's salary by a certain percentage.

#### **Defining Methods for the Object Type**

After defining the object type, you also define the methods associated with the object type using a `CREATE OR REPLACE TYPE BODY` statement.

##### **Example: Object Type Body (Methods)**

```sql
CREATE OR REPLACE TYPE BODY Employee AS
   -- Function to return the salary
   MEMBER FUNCTION get_salary RETURN NUMBER IS
   BEGIN
      RETURN emp_salary;
   END get_salary;
   
   -- Procedure to raise salary by a certain percentage
   MEMBER PROCEDURE raise_salary (percent IN NUMBER) IS
   BEGIN
      emp_salary := emp_salary * (1 + percent / 100);
   END raise_salary;
END;
```

- The `get_salary` function returns the `emp_salary`.
- The `raise_salary` procedure increases the `emp_salary` by the given percentage.

---

### **Instantiating Objects**

Once an object type is defined, you can create and work with objects (instances) of that type.

#### **Example: Instantiating an Object**

```sql
DECLARE
   emp_obj Employee;  -- Declare an object of the Employee type
BEGIN
   -- Initialize the object with data
   emp_obj := Employee(101, 'John Doe', 50000);
   
   -- Access attributes and methods
   DBMS_OUTPUT.PUT_LINE('Employee Name: ' || emp_obj.emp_name);
   DBMS_OUTPUT.PUT_LINE('Salary: ' || emp_obj.get_salary);
   
   -- Use a method to raise the salary
   emp_obj.raise_salary(10);  -- Increase salary by 10%
   
   -- Output the updated salary
   DBMS_OUTPUT.PUT_LINE('Updated Salary: ' || emp_obj.get_salary);
END;
```

- The object `emp_obj` is instantiated with the values `101`, `'John Doe'`, and `50000`.
- You access the object's attributes (e.g., `emp_obj.emp_name`) and methods (e.g., `emp_obj.get_salary` and `emp_obj.raise_salary`).
- After raising the salary by 10%, the updated salary is printed.

---

### **Inheritance in PL/SQL**

PL/SQL allows a basic form of inheritance, where an object type can inherit the attributes and methods of another object type. You can extend an object type by creating a new object type based on an existing one.

#### **Example: Inheriting an Object Type**

Let's extend the `Employee` type to create a `Manager` type, which inherits from `Employee` and adds a new attribute (`department`).

```sql
CREATE OR REPLACE TYPE Manager AS OBJECT (
   -- Inherit all attributes and methods from Employee
   MEMBER FUNCTION get_department RETURN VARCHAR2,
   
   department VARCHAR2(50)
) UNDER Employee;
```

- The `Manager` object type inherits the attributes and methods of the `Employee` object type.
- You can also define new attributes and methods specific to the `Manager` type.

#### **Example: Using Inherited Object Types**

```sql
DECLARE
   mgr_obj Manager;  -- Declare an object of the Manager type
BEGIN
   -- Initialize the Manager object with Employee attributes and Manager-specific data
   mgr_obj := Manager(102, 'Alice Smith', 70000, 'HR');
   
   -- Access inherited attributes and methods
   DBMS_OUTPUT.PUT_LINE('Manager Name: ' || mgr_obj.emp_name);
   DBMS_OUTPUT.PUT_LINE('Salary: ' || mgr_obj.get_salary);
   DBMS_OUTPUT.PUT_LINE('Department: ' || mgr_obj.get_department);
END;
```

- The `mgr_obj` object is instantiated as a `Manager`, which is also an `Employee`.
- The `get_salary` function and `emp_name` attribute are inherited from `Employee`.

---

### **Overloading and Polymorphism**

PL/SQL supports **method overloading** (same method name with different parameter signatures) to implement polymorphism, where different methods with the same name can perform different tasks based on the number or type of arguments.

#### **Example: Method Overloading**

```sql
CREATE OR REPLACE TYPE Employee AS OBJECT (
   emp_id      NUMBER,
   emp_name    VARCHAR2(100),
   emp_salary  NUMBER,
   
   MEMBER FUNCTION get_salary RETURN NUMBER,
   MEMBER PROCEDURE raise_salary (percent IN NUMBER),
   MEMBER PROCEDURE raise_salary (amount IN NUMBER)  -- Overloaded method
);
```

Here, `raise_salary` is overloaded to accept either a **percentage** or a **fixed amount** as a parameter.

#### **Method Body for Overloading**

```sql
CREATE OR REPLACE TYPE BODY Employee AS
   MEMBER FUNCTION get_salary RETURN NUMBER IS
   BEGIN
      RETURN emp_salary;
   END get_salary;
   
   MEMBER PROCEDURE raise_salary (percent IN NUMBER) IS
   BEGIN
      emp_salary := emp_salary * (1 + percent / 100);
   END raise_salary;
   
   MEMBER PROCEDURE raise_salary (amount IN NUMBER) IS
   BEGIN
      emp_salary := emp_salary + amount;
   END raise_salary;
END;
```

- The `raise_salary` method has two versions: one for increasing the salary by a percentage and another for increasing it by a fixed amount.

---

### **Summary of Object-Oriented Concepts in PL/SQL**

1. **Object Types**: You define object types to model data and behavior, similar to classes in traditional OOP languages.
   - **Attributes** (variables) define the state of the object.
   - **Methods** (procedures/functions) define the behavior.

2. **Encapsulation**: Data and methods are encapsulated into a single unit, making it easier to manage and maintain complex systems.

3. **Inheritance**: You can create new object types based on existing ones, inheriting attributes and methods.

4. **Polymorphism**: You can use method overloading to provide different behaviors for methods with the same name.

5. **Instantiation**: Objects are instantiated using the `NEW` keyword (or implicitly) and are used to store and manipulate data.

---

### **Advantages of Object-Oriented Programming in PL/SQL**

- **Reusability**: You can reuse object types across various PL/SQL blocks and packages.
- **Modularity**: Objects encapsulate data and behavior, making code easier to organize and maintain.
- **Abstraction**: You can hide the implementation details of methods and only expose relevant functionality.
- **Code Organization**: Object-oriented techniques allow you to structure complex systems more effectively.

---

