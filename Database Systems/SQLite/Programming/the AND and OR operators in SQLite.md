In SQLite, the **`AND`** and **`OR`** operators are logical operators used to combine multiple conditions in a `WHERE` clause. These operators allow you to filter rows based on more than one condition, enabling more complex queries.

### **`AND` Operator**

The **`AND`** operator is used when you want to filter records that satisfy **all** conditions. Both conditions must be true for the row to be included in the result set.

#### Syntax:

```sql
SELECT columns
FROM table
WHERE condition1 AND condition2;
```

- **Condition1 AND Condition2**: Both conditions must be true for the row to be returned.

#### Example:

```sql
SELECT * FROM employees
WHERE age >= 30 AND department = 'Sales';
```

This query selects employees who are **30 years or older** **and** work in the **Sales** department. Both conditions must be true for the row to be included.

#### Example with Multiple Conditions:

```sql
SELECT * FROM products
WHERE price > 50 AND stock > 100 AND category = 'Electronics';
```

This query selects products that have a **price greater than 50**, a **stock greater than 100**, and belong to the **Electronics** category. All three conditions must be met.

---

### **`OR` Operator**

The **`OR`** operator is used when you want to filter records that satisfy **at least one** of the conditions. If **any one condition** is true, the row is included in the result set.

#### Syntax:

```sql
SELECT columns
FROM table
WHERE condition1 OR condition2;
```

- **Condition1 OR Condition2**: Only one condition needs to be true for the row to be returned.

#### Example:

```sql
SELECT * FROM employees
WHERE department = 'HR' OR department = 'Marketing';
```

This query selects employees who work in either the **HR** or **Marketing** department. Only one of the conditions needs to be true for a row to be included.

#### Example with Multiple Conditions:

```sql
SELECT * FROM products
WHERE price < 50 OR category = 'Toys';
```

This query selects products that either have a **price less than 50** or belong to the **Toys** category. If either condition is true, the row is included.

---

### **Combining `AND` and `OR`**

You can combine **`AND`** and **`OR`** operators in a single query to create more complex filtering logic. When you combine both, it's important to use **parentheses** `()` to control the order of evaluation and ensure the conditions are applied correctly.

#### Example:

```sql
SELECT * FROM employees
WHERE (age >= 30 AND department = 'Sales') OR (age <= 25 AND department = 'Marketing');
```

This query selects employees who meet **one of the two conditions**:
1. **Age greater than or equal to 30** **and** works in the **Sales** department.
2. **Age less than or equal to 25** **and** works in the **Marketing** department.

The parentheses ensure that the `AND` conditions are evaluated before the `OR` condition.

#### Example with Nested Conditions:

```sql
SELECT * FROM products
WHERE (price < 50 OR category = 'Toys') AND stock > 100;
```

This query selects products that meet two conditions:
1. The product has a **price less than 50** **or** belongs to the **Toys** category.
2. The product must have a **stock greater than 100**.

In this case, the `OR` condition is evaluated first due to the parentheses, and then the result is combined with the `AND` condition.

---

### **Precedence of `AND` and `OR`**

When both `AND` and `OR` operators are used in a query, the **`AND`** operator has **higher precedence** than the **`OR`** operator. This means that `AND` conditions are evaluated before `OR` conditions unless parentheses are used to change the order of evaluation.

#### Example:

```sql
SELECT * FROM users
WHERE age > 18 AND gender = 'M' OR city = 'New York';
```

In this query:
- **`age > 18 AND gender = 'M'`** is evaluated first because `AND` has higher precedence than `OR`.
- The query will return all male users over 18 **or** users who live in New York, regardless of their age or gender.

To change the order of evaluation, you can use parentheses:

```sql
SELECT * FROM users
WHERE (age > 18 AND gender = 'M') OR city = 'New York';
```

This query will return users who are **either** male and over 18 **or** live in New York.

---

### **Summary of `AND` and `OR` Usage**

- **`AND`**: Combines conditions where **both** must be true for a row to be included.
  - Example: `WHERE age >= 18 AND city = 'New York'`
- **`OR`**: Combines conditions where **either** can be true for a row to be included.
  - Example: `WHERE age <= 25 OR department = 'HR'`
- **Combining `AND` and `OR`**: Use parentheses `()` to control the order of evaluation and combine logical operators for more complex queries.
  - Example: `WHERE (age >= 18 AND city = 'New York') OR department = 'Sales'`

These logical operators enable you to build more refined and sophisticated queries that filter data based on multiple conditions.
