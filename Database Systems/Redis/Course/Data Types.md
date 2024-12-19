### Redis Data Types

Redis supports a variety of data types that allow developers to model their data efficiently and handle diverse use cases. These data types are stored in memory and provide specific commands for manipulation and querying.

---

### 1. **String**
The simplest and most common data type in Redis. Strings can hold text, numbers, or binary data such as serialized objects, images, or videos.

- **Size Limit**: Up to **512 MB**.
- **Use Cases**:
  - Caching simple key-value pairs.
  - Counting operations (atomic increment/decrement).
  - Storing serialized objects.

**Commands**:
- `SET key value` – Sets the value of a key.
- `GET key` – Gets the value of a key.
- `INCR key` – Increments the value of a key by 1 (assumes numeric value).
- `DECR key` – Decrements the value of a key by 1.
- `APPEND key value` – Appends data to the existing value of a key.

**Example**:
```bash
SET user:1 "Alice"
GET user:1
INCR page_views
```

---

### 2. **List**
Lists are ordered collections of strings. They allow push and pop operations from both ends, making them ideal for queue-like or stack-like behavior.

- **Max Size**: 2^32 - 1 elements (approximately 4 billion).
- **Use Cases**:
  - Message queues.
  - Activity logs.
  - Real-time feeds.

**Commands**:
- `LPUSH key value` – Adds an element to the beginning of the list.
- `RPUSH key value` – Adds an element to the end of the list.
- `LPOP key` – Removes and returns the first element.
- `RPOP key` – Removes and returns the last element.
- `LRANGE key start stop` – Gets a range of elements.

**Example**:
```bash
RPUSH tasks "task1" "task2"
LPUSH tasks "task0"
LRANGE tasks 0 -1  # Get all elements
```

---

### 3. **Set**
Sets are unordered collections of unique strings. They are efficient for operations like intersections, unions, and differences.

- **Max Size**: 2^32 - 1 elements.
- **Use Cases**:
  - Tagging systems.
  - Unique visitor tracking.
  - Membership checks.

**Commands**:
- `SADD key value` – Adds a member to the set.
- `SREM key value` – Removes a member from the set.
- `SISMEMBER key value` – Checks if a value is a member of the set.
- `SMEMBERS key` – Returns all members.
- `SUNION key1 key2` – Returns the union of two sets.

**Example**:
```bash
SADD users "Alice" "Bob"
SADD admins "Bob" "Charlie"
SINTER users admins  # Intersection of users and admins
```

---

### 4. **Sorted Set (ZSet)**
Sorted sets are similar to sets but with an associated score for each element. Elements are ordered by their scores.

- **Max Size**: 2^32 - 1 elements.
- **Use Cases**:
  - Leaderboards.
  - Ranking systems.
  - Task scheduling (with scores as timestamps).

**Commands**:
- `ZADD key score value` – Adds a member with a score.
- `ZRANGE key start stop` – Gets members in a specified range (by index).
- `ZRANGEBYSCORE key min max` – Gets members in a range (by score).
- `ZREM key value` – Removes a member.
- `ZCOUNT key min max` – Counts members in a score range.

**Example**:
```bash
ZADD leaderboard 100 "Alice" 200 "Bob"
ZRANGE leaderboard 0 -1 WITHSCORES  # Get all members with scores
ZRANK leaderboard "Alice"  # Get rank of a member
```

---

### 5. **Hash**
Hashes are key-value pairs within a single Redis key. They are like dictionaries or objects in programming languages.

- **Max Size**: 2^32 - 1 fields per hash.
- **Use Cases**:
  - Storing user profiles.
  - Storing configurations.
  - Caching structured data.

**Commands**:
- `HSET key field value` – Sets a field in the hash.
- `HGET key field` – Gets the value of a field.
- `HGETALL key` – Gets all fields and values in the hash.
- `HDEL key field` – Deletes a field.

**Example**:
```bash
HSET user:1 name "Alice" age "30"
HGET user:1 name
HGETALL user:1
```

---

### 6. **Bitmap**
Bitmaps allow you to perform bit-level operations on strings. They are useful for compact storage of binary data.

- **Use Cases**:
  - Tracking user activity (e.g., which days a user was online).
  - Efficient counting of unique events.

**Commands**:
- `SETBIT key offset value` – Sets or clears a bit at a specific offset.
- `GETBIT key offset` – Gets the value of a bit at a specific offset.
- `BITCOUNT key` – Counts the number of set bits.

**Example**:
```bash
SETBIT user:active 1 1
SETBIT user:active 2 1
GETBIT user:active 1
BITCOUNT user:active
```

---

### 7. **HyperLogLog**
A probabilistic data structure used to estimate the cardinality (number of unique elements) of a dataset with low memory usage.

- **Use Cases**:
  - Unique visitor counting.
  - Counting unique events in real-time.

**Commands**:
- `PFADD key element` – Adds an element to the HyperLogLog.
- `PFCOUNT key` – Estimates the cardinality of the set.
- `PFMERGE destkey sourcekey1 sourcekey2` – Merges multiple HyperLogLogs.

**Example**:
```bash
PFADD unique_visitors "user1" "user2"
PFCOUNT unique_visitors
```

---

### 8. **Streams**
Streams are a log-like data structure for managing real-time data. They are used for message queues and event streaming.

- **Use Cases**:
  - Chat systems.
  - Real-time logs or feeds.
  - Task queues.

**Commands**:
- `XADD key * field value` – Appends an entry to the stream.
- `XRANGE key start end` – Gets entries in a range.
- `XREAD COUNT count STREAMS key ID` – Reads new entries.

**Example**:
```bash
XADD mystream * name "Alice" action "login"
XRANGE mystream - +
```

---

### 9. **Geospatial Data**
Redis supports geospatial data, allowing you to store and query locations based on latitude and longitude.

- **Use Cases**:
  - Location-based services.
  - Proximity search.
  - Mapping.

**Commands**:
- `GEOADD key longitude latitude member` – Adds a geospatial point.
- `GEODIST key member1 member2 [unit]` – Gets the distance between two points.
- `GEORADIUS key longitude latitude radius [unit]` – Gets points within a radius.

**Example**:
```bash
GEOADD locations 13.361389 38.115556 "Palermo"
GEOADD locations 15.087269 37.502669 "Catania"
GEODIST locations "Palermo" "Catania" km
```

---

### Summary of Redis Data Types
| Data Type      | Use Case Examples                              | Key Commands        |
|-----------------|-----------------------------------------------|---------------------|
| **String**      | Caching, counters, serialized objects         | `SET`, `GET`, `INCR`|
| **List**        | Message queues, real-time feeds               | `LPUSH`, `LRANGE`   |
| **Set**         | Tagging, unique visitors, membership checks   | `SADD`, `SMEMBERS`  |
| **Sorted Set**  | Leaderboards, ranking systems                 | `ZADD`, `ZRANGE`    |
| **Hash**        | User profiles, structured data                | `HSET`, `HGETALL`   |
| **Bitmap**      | User activity tracking, bit-level operations  | `SETBIT`, `BITCOUNT`|
| **HyperLogLog** | Approximate unique counts                     | `PFADD`, `PFCOUNT`  |
| **Stream**      | Logs, event streams, chat applications        | `XADD`, `XRANGE`    |
| **Geo**         | Location-based services                       | `GEOADD`, `GEODIST` |

Redis' diverse data types make it highly versatile, capable of addressing a wide range of application needs.
