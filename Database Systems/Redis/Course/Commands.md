### Redis Commands Overview

Redis provides a rich set of commands to interact with its different data types and manage the database. Commands are categorized based on their functionality and the data types they operate on. Here’s a categorized list of commonly used Redis commands:

---

### 1. **String Commands**
Strings are the simplest Redis data type, used for key-value operations.

| Command         | Description                                  | Example                   |
|------------------|----------------------------------------------|---------------------------|
| `SET key value` | Set a key to hold a value.                  | `SET name "Alice"`        |
| `GET key`       | Get the value of a key.                     | `GET name`                |
| `DEL key`       | Delete a key.                               | `DEL name`                |
| `INCR key`      | Increment the integer value of a key.       | `INCR counter`            |
| `DECR key`      | Decrement the integer value of a key.       | `DECR counter`            |
| `APPEND key value` | Append a value to the existing value.    | `APPEND greeting "World"` |
| `MSET key value [key value ...]` | Set multiple keys.         | `MSET key1 val1 key2 val2`|
| `MGET key [key ...]` | Get values of multiple keys.           | `MGET key1 key2`          |

---

### 2. **List Commands**
Lists are ordered collections of strings with push and pop operations.

| Command           | Description                                     | Example                  |
|--------------------|------------------------------------------------|--------------------------|
| `LPUSH key value` | Insert value at the beginning of the list.      | `LPUSH tasks "task1"`    |
| `RPUSH key value` | Insert value at the end of the list.            | `RPUSH tasks "task2"`    |
| `LPOP key`        | Remove and return the first element.            | `LPOP tasks`             |
| `RPOP key`        | Remove and return the last element.             | `RPOP tasks`             |
| `LRANGE key start stop` | Get a range of elements.                  | `LRANGE tasks 0 -1`      |
| `LLEN key`        | Get the length of the list.                    | `LLEN tasks`             |
| `LSET key index value` | Set the element at the specified index.    | `LSET tasks 0 "newtask"` |
| `LINDEX key index` | Get the element at the specified index.        | `LINDEX tasks 1`         |

---

### 3. **Set Commands**
Sets are unordered collections of unique elements.

| Command           | Description                                     | Example                  |
|--------------------|------------------------------------------------|--------------------------|
| `SADD key value`  | Add one or more members to a set.              | `SADD myset "item1"`     |
| `SREM key value`  | Remove one or more members from a set.         | `SREM myset "item1"`     |
| `SMEMBERS key`    | Get all members of the set.                    | `SMEMBERS myset`         |
| `SISMEMBER key value` | Check if a value is a member of the set.    | `SISMEMBER myset "item1"`|
| `SUNION key [key ...]` | Get the union of multiple sets.            | `SUNION set1 set2`       |
| `SINTER key [key ...]` | Get the intersection of multiple sets.     | `SINTER set1 set2`       |
| `SDIFF key [key ...]` | Get the difference between sets.            | `SDIFF set1 set2`        |

---

### 4. **Sorted Set Commands**
Sorted sets are sets where each element has a score for sorting.

| Command                 | Description                                 | Example                  |
|--------------------------|---------------------------------------------|--------------------------|
| `ZADD key score member` | Add a member with a score to a sorted set. | `ZADD leaderboard 100 "Alice"` |
| `ZRANGE key start stop` | Get members in a range by rank.            | `ZRANGE leaderboard 0 -1` |
| `ZREVRANGE key start stop` | Get members in reverse rank order.       | `ZREVRANGE leaderboard 0 -1` |
| `ZRANK key member`      | Get the rank of a member.                  | `ZRANK leaderboard "Alice"` |
| `ZREM key member`       | Remove a member.                           | `ZREM leaderboard "Alice"` |
| `ZCOUNT key min max`    | Count members in a score range.            | `ZCOUNT leaderboard 50 200` |
| `ZSCORE key member`     | Get the score of a member.                 | `ZSCORE leaderboard "Alice"`|

---

### 5. **Hash Commands**
Hashes are key-value pairs stored within a single key.

| Command            | Description                                     | Example                  |
|---------------------|------------------------------------------------|--------------------------|
| `HSET key field value` | Set a field in the hash.                    | `HSET user:1 name "Alice"` |
| `HGET key field`    | Get the value of a field in the hash.          | `HGET user:1 name`       |
| `HGETALL key`       | Get all fields and values in the hash.         | `HGETALL user:1`         |
| `HDEL key field`    | Delete one or more fields.                     | `HDEL user:1 name`       |
| `HLEN key`          | Get the number of fields in the hash.          | `HLEN user:1`            |
| `HKEYS key`         | Get all field names in the hash.               | `HKEYS user:1`           |
| `HVALS key`         | Get all field values in the hash.              | `HVALS user:1`           |

---

### 6. **HyperLogLog Commands**
Used for approximate cardinality estimation.

| Command            | Description                                     | Example                  |
|---------------------|------------------------------------------------|--------------------------|
| `PFADD key value`  | Add an element to the HyperLogLog.             | `PFADD unique_visitors "user1"` |
| `PFCOUNT key`      | Get the approximate number of unique elements. | `PFCOUNT unique_visitors` |
| `PFMERGE destkey sourcekey1 sourcekey2` | Merge multiple HyperLogLogs. | `PFMERGE combined hll1 hll2` |

---

### 7. **Stream Commands**
Streams are used for handling real-time event data.

| Command            | Description                                     | Example                  |
|---------------------|------------------------------------------------|--------------------------|
| `XADD key * field value` | Add an entry to a stream.                 | `XADD mystream * user "Alice"` |
| `XRANGE key start end` | Get entries in a range.                     | `XRANGE mystream - +`    |
| `XREAD STREAMS key ID` | Read new entries starting from an ID.       | `XREAD STREAMS mystream 0` |
| `XDEL key ID`      | Delete an entry by ID.                         | `XDEL mystream 123456789`|

---

### 8. **Geospatial Commands**
Used for geospatial data like locations.

| Command                 | Description                                   | Example                  |
|--------------------------|-----------------------------------------------|--------------------------|
| `GEOADD key lon lat member` | Add a geospatial point.                   | `GEOADD locations 13.36 38.11 "Palermo"` |
| `GEODIST key member1 member2` | Get the distance between two points.     | `GEODIST locations "Palermo" "Catania" km` |
| `GEORADIUS key lon lat radius unit` | Get members within a radius.      | `GEORADIUS locations 15 37 100 km` |

---

### 9. **Key Management Commands**
General commands for managing keys.

| Command           | Description                                    | Example                  |
|--------------------|------------------------------------------------|--------------------------|
| `DEL key`         | Delete a key.                                 | `DEL key1`               |
| `EXPIRE key seconds` | Set a timeout on a key.                    | `EXPIRE session 3600`    |
| `TTL key`         | Get the remaining time-to-live of a key.      | `TTL session`            |
| `KEYS pattern`    | Find keys matching a pattern.                 | `KEYS user:*`            |
| `FLUSHALL`        | Delete all keys in all databases.             | `FLUSHALL`               |

---

### Summary

Redis commands are intuitive and categorized based on their use case and data type. Mastering these commands allows for efficient data modeling and retrieval, making Redis a powerful tool for in-memory data storage and processing.
