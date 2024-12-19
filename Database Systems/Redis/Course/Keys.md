### Redis Keys Overview

In Redis, **keys** are the unique identifiers used to reference values stored in the database. A key can hold data in any of Redis' supported data types (e.g., strings, lists, sets, hashes). Understanding how keys work and how to manage them effectively is crucial for designing efficient Redis-based solutions.

---

### Key Characteristics
1. **Uniqueness**: Keys must be unique within a database. Each key points to one specific value.
2. **String Format**: Keys are binary-safe strings, meaning they can contain any sequence of characters, including binary data.
3. **Maximum Size**: Keys can be up to **512 MB** in length, though shorter keys are recommended for performance reasons.
4. **Namespaces**: Keys can use patterns (e.g., `user:100`, `order:200`) to simulate namespaces or hierarchies.

---

### Common Key Operations
| **Command**         | **Description**                                      | **Example**                 |
|----------------------|------------------------------------------------------|-----------------------------|
| `SET key value`      | Sets the value of a key.                             | `SET name "Alice"`          |
| `GET key`            | Retrieves the value of a key.                        | `GET name`                  |
| `DEL key`            | Deletes one or more keys.                            | `DEL name`                  |
| `EXISTS key`         | Checks if a key exists.                              | `EXISTS name`               |
| `EXPIRE key seconds` | Sets a time-to-live (TTL) in seconds for a key.      | `EXPIRE session 300`        |
| `TTL key`            | Gets the remaining TTL for a key.                    | `TTL session`               |
| `KEYS pattern`       | Returns keys matching a pattern (not recommended for production use). | `KEYS user:*` |
| `RENAME key newkey`  | Renames a key.                                       | `RENAME oldname newname`    |
| `TYPE key`           | Returns the data type of the key’s value.            | `TYPE name`                 |
| `SCAN cursor [MATCH pattern] [COUNT count]` | Iterates keys in batches.    | `SCAN 0 MATCH user:*`       |

---

### Time-to-Live (TTL) for Keys
Keys in Redis can have an expiration time, making Redis suitable for caching and temporary data storage.

- **Set Expiration**: Use `EXPIRE key seconds` or `SETEX key seconds value`.
- **Check Expiration**: Use `TTL key` to check remaining time. `-1` indicates no expiration; `-2` means the key doesn't exist.
- **Persist Key**: Remove expiration using `PERSIST key`.

**Example**:
```bash
SET session "active"
EXPIRE session 3600      # Expires in 1 hour
TTL session              # Check TTL
PERSIST session          # Remove expiration
```

---

### Key Naming Best Practices
1. **Use Descriptive Names**: Include contextual information (e.g., `user:100`, `order:2023:5001`).
2. **Simulate Namespaces**: Use colons (`:`) to separate logical segments (e.g., `app1:session:user:123`).
3. **Keep Keys Short**: Minimize key length for faster lookups and lower memory usage.
4. **Avoid Overlapping Names**: Ensure keys are sufficiently unique to prevent accidental overwrites.
5. **Reserve Special Characters**: Avoid special characters except for structured naming conventions like `:`, `_`.

---

### Key Iteration: `SCAN`
Instead of using `KEYS`, which can block the server for large datasets, `SCAN` allows non-blocking iteration over keys.

- **Syntax**: `SCAN cursor [MATCH pattern] [COUNT count]`
  - `cursor`: A position indicator, starting at `0`.
  - `MATCH`: Filters keys by pattern.
  - `COUNT`: Suggests the number of keys to return (not guaranteed).

**Example**:
```bash
SCAN 0 MATCH user:* COUNT 10
```

---

### Key Patterns and Wildcards
Redis supports basic pattern matching for key operations.

| **Pattern** | **Matches**                     | **Example**                 |
|-------------|---------------------------------|-----------------------------|
| `*`         | Matches any sequence of characters. | `user:*` matches `user:1` and `user:abc`. |
| `?`         | Matches any single character.   | `user:?` matches `user:1`, but not `user:12`. |
| `[abc]`     | Matches one of the specified characters. | `user:[ab]*` matches `user:a1` and `user:b2`. |
| `[a-z]`     | Matches characters in a range.  | `user:[a-z]*` matches `user:abc`. |

---

### Key Deletion
Keys can be explicitly deleted using the `DEL` command or implicitly removed when they expire.

**Batch Deletion**:
- Use `DEL key1 key2 ...` for specific keys.
- For bulk deletion matching a pattern, combine `SCAN` and `DEL`:
  ```bash
  SCAN 0 MATCH user:* | xargs DEL
  ```

**Eviction Policy** (for full memory scenarios):
- Configurable eviction policies determine how Redis handles memory pressure (e.g., `allkeys-lru`, `volatile-lru`).

---

### Key Info and Statistics
- `OBJECT REFCOUNT key`: Returns the reference count of a key.
- `OBJECT ENCODING key`: Returns the internal encoding (e.g., `ziplist`, `hashtable`).
- `OBJECT IDLETIME key`: Returns the idle time in seconds since the last access.

**Example**:
```bash
SET user:1 "Alice"
OBJECT ENCODING user:1  # Check internal encoding
```

---

Redis keys are foundational to efficient data organization and access. Proper naming conventions, usage of expiration, and careful iteration strategies can maximize Redis' performance and scalability.
