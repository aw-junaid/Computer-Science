The **`case_sensitive_like`** PRAGMA in SQLite is used to control whether the `LIKE` operator is case-sensitive or case-insensitive when performing string pattern matching. By default, the `LIKE` operator in SQLite is **case-insensitive** (except when using a `BINARY` operator or specifying case-sensitive collation). Setting this PRAGMA to `ON` makes the `LIKE` operator case-sensitive.

### Syntax of `case_sensitive_like` PRAGMA

```sql
PRAGMA case_sensitive_like = { ON | OFF };
```

- **`ON`**: This enables **case-sensitive** behavior for the `LIKE` operator. When set to `ON`, the `LIKE` operator will distinguish between uppercase and lowercase letters.
  
- **`OFF`**: This is the default setting, which enables **case-insensitive** behavior for the `LIKE` operator. When set to `OFF`, the `LIKE` operator ignores case when matching string patterns.

### Default Behavior

- By default, **`case_sensitive_like`** is **`OFF`**, meaning `LIKE` comparisons are case-insensitive. This is consistent with the behavior of `LIKE` in many SQL implementations, where:
  - `LIKE 'apple'` matches `'APPLE'`, `'ApPlE'`, `'apple'`, etc.
  
### Example 1: Using `case_sensitive_like` with `OFF` (default)

```sql
PRAGMA case_sensitive_like = OFF;

-- This will match any case variation of 'apple'
SELECT * FROM fruits WHERE name LIKE 'apple';
```

- If `name` contains `'APPLE'`, `'apple'`, or `'ApPlE'`, the query will return the row, since the default `LIKE` operator is case-insensitive.

### Example 2: Using `case_sensitive_like` with `ON`

```sql
PRAGMA case_sensitive_like = ON;

-- This will only match 'apple' exactly as it is (lowercase 'a', 'p', 'l', 'e')
SELECT * FROM fruits WHERE name LIKE 'apple';
```

- In this case, only rows where `name` is exactly `'apple'` will be returned. If `name` contains `'APPLE'`, `'ApPlE'`, or any other case variation, it will not match.

### How `case_sensitive_like` Affects Queries

- **When `case_sensitive_like = ON`**:
  - `LIKE 'apple'` will match only strings that are exactly `'apple'`, respecting case sensitivity.
  - `LIKE 'apple%'` will match strings that start with `'apple'` (e.g., `'applepie'`), but only if the case is exactly as specified.
  
- **When `case_sensitive_like = OFF`** (the default):
  - `LIKE 'apple'` will match strings like `'APPLE'`, `'apple'`, `'ApPlE'`, etc., because case is ignored.

### Example 3: Setting `case_sensitive_like` to `ON` Temporarily

You can also change this setting temporarily for the current session:

```sql
PRAGMA case_sensitive_like = ON;
-- Now LIKE is case-sensitive for this session

SELECT * FROM fruits WHERE name LIKE 'apple';  -- Only exact matches with 'apple'
```

After running the above query, the `LIKE` operator will become case-sensitive for all queries during this session.

### Important Notes

- **Session-Specific**: The setting for **`case_sensitive_like`** is session-specific. This means that once you close the connection to the SQLite database, the setting will be reset to the default (`OFF`). You will need to set it to `ON` again if you want case-sensitive `LIKE` comparisons in a new session.
  
- **Comparison Example**: 
   - With **`case_sensitive_like = OFF`**, `LIKE 'apple'` matches `'APPLE'`, `'apple'`, `'ApPlE'`, etc.
   - With **`case_sensitive_like = ON`**, `LIKE 'apple'` only matches `'apple'` and nothing else.

---

### Summary of `case_sensitive_like` PRAGMA

- **Purpose**: Controls the case-sensitivity of the `LIKE` operator in SQLite.
- **Syntax**: `PRAGMA case_sensitive_like = { ON | OFF };`
  - **`ON`**: Makes `LIKE` case-sensitive.
  - **`OFF`**: Makes `LIKE` case-insensitive (default).
- **Session-Specific**: The setting only affects the current session and is reset to the default when the connection is closed.
- **Use Case**: Use `case_sensitive_like` when you need precise control over string matching, especially in cases where the case of letters should matter.
