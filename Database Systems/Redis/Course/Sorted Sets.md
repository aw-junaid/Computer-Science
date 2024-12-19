### Redis Sorted Sets Overview

Redis **sorted sets** are similar to regular sets, but each element is associated with a **score**, which determines the order of elements in the set. The elements are unique, but scores can be repeated. Sorted sets are ideal for use cases that require sorted data retrieval, like leaderboards, ranking systems, or scheduling.

---

### Key Features of Redis Sorted Sets

1. **Ordered by Score**: Elements are sorted by their score in ascending order.
2. **Unique Elements**: Each member in a sorted set is unique, but scores can be duplicated.
3. **Efficient Access**: Provides fast insertion, deletion, and range queries based on scores or ranks.
4. **Double Precision**: Scores are floating-point values with double-precision.

---

### Common Sorted Set Commands

| **Command**                   | **Description**                                                   | **Example**                           |
|--------------------------------|-------------------------------------------------------------------|---------------------------------------|
| `ZADD key [NX|XX] [CH] [INCR] score member [score member ...]` | Add one or more members with scores to a sorted set. | `ZADD scores 10 "Alice" 20 "Bob"`     |
| `ZSCORE key member`            | Get the score of a member in the sorted set.                     | `ZSCORE scores "Alice"`               |
| `ZRANGE key start stop [WITHSCORES]` | Get members in the range by rank (index) in ascending order. | `ZRANGE scores 0 -1 WITHSCORES`       |
| `ZREVRANGE key start stop [WITHSCORES]` | Get members in the range by rank in descending order.      | `ZREVRANGE scores 0 -1 WITHSCORES`    |
| `ZRANK key member`             | Get the rank (index) of a member in ascending order.             | `ZRANK scores "Bob"`                  |
| `ZREVRANK key member`          | Get the rank of a member in descending order.                    | `ZREVRANK scores "Alice"`             |
| `ZREM key member [member ...]` | Remove one or more members from the sorted set.                  | `ZREM scores "Alice"`                 |
| `ZRANGEBYSCORE key min max [WITHSCORES] [LIMIT offset count]` | Get members with scores in a given score range.         | `ZRANGEBYSCORE scores 10 20`          |
| `ZREVRANGEBYSCORE key max min [WITHSCORES] [LIMIT offset count]` | Get members with scores in descending order.           | `ZREVRANGEBYSCORE scores 20 10`       |
| `ZINCRBY key increment member` | Increment the score of a member by a specified value.            | `ZINCRBY scores 5 "Alice"`            |
| `ZCARD key`                    | Get the number of members in the sorted set.                     | `ZCARD scores`                        |
| `ZCOUNT key min max`           | Count the members with scores within a given range.              | `ZCOUNT scores 10 20`                 |
| `ZRANGEBYLEX key min max [LIMIT offset count]` | Get members in a lexicographical range.               | `ZRANGEBYLEX scores [A [Z`            |
| `ZREM_RANGE_BY_SCORE key min max` | Remove members by a score range.                              | `ZREMRANGEBYSCORE scores 10 20`       |
| `ZREM_RANGE_BY_RANK key start stop` | Remove members by a rank range.                            | `ZREMRANGEBYRANK scores 0 1`          |

---

### Use Cases for Sorted Sets

1. **Leaderboards**:
   Track scores and rankings for players in games.
   ```bash
   ZADD leaderboard 1500 "Alice" 2000 "Bob"
   ZRANGE leaderboard 0 -1 WITHSCORES  # Get rankings in ascending order
   ```

2. **Task Scheduling**:
   Use scores as timestamps to implement priority queues or delayed tasks.
   ```bash
   ZADD tasks 1672531200 "task1" 1672534800 "task2"
   ZRANGEBYSCORE tasks -inf 1672531200  # Get tasks up to a certain time
   ```

3. **Ranked Searches**:
   Store search results with relevance scores for ranked retrieval.
   ```bash
   ZADD search_results 0.9 "result1" 0.7 "result2"
   ZREVRANGE search_results 0 -1 WITHSCORES  # Get results by highest relevance
   ```

4. **Event Logging**:
   Use scores as timestamps for chronological storage of events.
   ```bash
   ZADD events 1672531200 "event1" 1672534800 "event2"
   ZRANGE events 0 -1 WITHSCORES
   ```

5. **Popularity Tracking**:
   Track the popularity of items by incrementing scores.
   ```bash
   ZINCRBY popularity 1 "item1"
   ZREVRANGE popularity 0 -1 WITHSCORES  # Get most popular items
   ```

---

### Examples of Sorted Set Commands in Action

1. **Adding and Retrieving Members**:
   ```bash
   ZADD scores 100 "Alice" 200 "Bob" 150 "Charlie"
   ZRANGE scores 0 -1 WITHSCORES      # Output: [Alice, 100, Charlie, 150, Bob, 200]
   ZREVRANGE scores 0 -1 WITHSCORES   # Output: [Bob, 200, Charlie, 150, Alice, 100]
   ```

2. **Updating Scores**:
   ```bash
   ZINCRBY scores 50 "Alice"
   ZSCORE scores "Alice"              # Output: 150
   ```

3. **Query by Rank or Score**:
   ```bash
   ZRANK scores "Charlie"             # Output: 1
   ZRANGEBYSCORE scores 100 200       # Output: [Alice, Charlie, Bob]
   ZCOUNT scores 150 200              # Output: 2 (Charlie and Bob)
   ```

4. **Removing Members**:
   ```bash
   ZREM scores "Alice"
   ZRANGE scores 0 -1                 # Output: [Charlie, Bob]
   ```

5. **Storing Results**:
   ```bash
   ZADD set1 1 "a" 2 "b"
   ZADD set2 2 "b" 3 "c"
   ZUNIONSTORE result 2 set1 set2 WEIGHTS 1 1
   ZRANGE result 0 -1 WITHSCORES      # Output: [a, 1, b, 4, c, 3]
   ```

---

### Best Practices for Sorted Sets

1. **Optimize for Large Datasets**:
   - Use range queries (`ZRANGE`, `ZRANGEBYSCORE`) instead of fetching entire sets.
   - Limit query results using `LIMIT` for better performance.

2. **Use Scores for Ordering**:
   - Encode timestamps or priorities as scores for dynamic ordering.

3. **Periodic Cleanup**:
   - Remove outdated or unnecessary elements using `ZREMRANGEBYSCORE` or `ZREMRANGEBYRANK`.

4. **Avoid Overloading with Too Many Elements**:
   - If a sorted set grows too large, consider archiving older data.

---

### Performance Considerations

- Sorted sets use a **combination of skip lists and hash tables** for efficient range queries and fast access.
- Operations like `ZADD`, `ZREM`, and `ZRANK` have logarithmic time complexity (\(O(\log N)\)).
- Memory usage can grow significantly with larger datasets. Use appropriate eviction policies or set TTLs on sorted sets.

---

### Summary

Redis sorted sets are a powerful tool for managing ordered data efficiently. They are especially useful in scenarios where ranking, scoring, or prioritization is required. By leveraging their unique features and efficient commands, you can build scalable applications like leaderboards, task schedulers, and ranked data retrieval systems.
