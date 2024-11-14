The **`LIKE`** clause in SQLite is used to search for a specified pattern in a column. It's commonly used in `SELECT`, `UPDATE`, and `DELETE` queries to filter rows based on a partial match with a string. The `LIKE` operator supports pattern matching using two special wildcard characters:

- **`%`**: Represents zero or more characters.
- **`_`**: Represents exactly one character.

### Syntax of the `LIKE` Clause

```sql
SELECT columns
FROM table
WHERE column_name LIKE pattern;
```

- **`column_name`**: The column you want to search within.
- **`pattern`**: The pattern you are searching for. The pattern can include `%` and `_` as wildcards.

### Wildcard Characters

- **`%`**: Matches **any sequence** of zero or more characters.
- **`_`**: Matches **exactly one character**.

---

### Example 1: Using `LIKE` with the `%` Wildcard

If you want to search for rows where the column contains a certain substring, you can use the `%` wildcard. For example, to find all employees whose names start with "J":

```sql
SELECT * FROM employees
WHERE name LIKE 'J%';
```

This query will return all employees whose `name` begins with the letter "J". The `%` matches any number of characters after "J", including zero characters.

---

### Example 2: Using `LIKE` with the `_` Wildcard

If you want to match a pattern where a specific number of characters are present, use the `_` wildcard. For example, to find all employees whose names have exactly four letters and start with "J":

```sql
SELECT * FROM employees
WHERE name LIKE 'J___';
```

This query will return all employees whose `name` has exactly four characters, starting with "J" (the `_` wildcard matches exactly one character).

---

### Example 3: Using `LIKE` to Find Substrings

You can also use `%` on both sides of the pattern to find any rows containing a particular substring. For example, to find all employees whose name contains "an" anywhere:

```sql
SELECT * FROM employees
WHERE name LIKE '%an%';
```

This query will return all employees whose `name` contains the substring "an", regardless of where it appears in the name.

---

### Example 4: Using `LIKE` with a Pattern at the End

If you want to search for values that end with a specific substring, you can place the `%` at the beginning of the pattern. For example, to find all employees whose names end with "son":

```sql
SELECT * FROM employees
WHERE name LIKE '%son';
```

This query will return all employees whose `name` ends with "son".

---

### Example 5: Case Sensitivity in `LIKE`

By default, the `LIKE` operator is **case-insensitive** in SQLite when applied to **ASCII characters**. However, for **non-ASCII** characters or when explicitly set, it can be case-sensitive.

For case-sensitive searches, you can use the `COLLATE` clause to specify case-sensitivity behavior:

```sql
SELECT * FROM employees
WHERE name LIKE 'J%' COLLATE NOCASE;
```

This query performs a case-insensitive search, even though the default behavior is usually case-insensitive for ASCII characters. To make the search case-sensitive, you can use:

```sql
SELECT * FROM employees
WHERE name LIKE 'J%' COLLATE BINARY;
```

This query performs a **case-sensitive** search for names starting with "J".

---

### Example 6: Using `NOT LIKE` for Exclusion

The `NOT LIKE` operator can be used to exclude rows that match a certain pattern. For example, to find all employees whose names do not start with "J":

```sql
SELECT * FROM employees
WHERE name NOT LIKE 'J%';
```

This query will return all employees whose `name` does not start with the letter "J".

---

### Summary of `LIKE` Usage

- **`LIKE`**: Used to search for a pattern in a column.
- **Wildcard Characters**:
  - **`%`**: Matches zero or more characters.
  - **`_`**: Matches exactly one character.
- **Case Sensitivity**: By default, `LIKE` is case-insensitive for ASCII characters, but this can be controlled using the `COLLATE` clause.
- **`NOT LIKE`**: Can be used to exclude records that match the pattern.

#### Examples:
- `LIKE 'J%'`: Matches any value starting with "J".
- `LIKE 'J___'`: Matches any value starting with "J" and has exactly three more characters.
- `LIKE '%an%'`: Matches any value containing "an".
- `NOT LIKE 'J%'`: Matches any value that does not start with "J".

The `LIKE` clause is very useful for pattern-based string searching, allowing you to filter and refine your queries based on partial matches.
