### **MongoDB - Covered Queries**

In MongoDB, **covered queries** refer to queries where all the fields required for a query and the result are included in an index. In other words, MongoDB can use an index to satisfy the entire query without needing to scan the actual documents in the collection. This leads to faster query execution since MongoDB doesn't have to load the documents from disk.

A **covered query** can be achieved when:
1. The query only accesses fields that are part of an index.
2. The projection in the query also includes only the indexed fields.

Since the index contains all the information required to answer the query, MongoDB can return the results directly from the index without needing to fetch the full documents, which significantly reduces the time and I/O overhead.

---

### **How Covered Queries Work**

1. **Index-Only Querying**: MongoDB can return results directly from the index because all the necessary fields for the query (including those for filtering and projection) are stored within the index.
2. **Avoiding Document Fetching**: With covered queries, MongoDB does not need to perform an additional **fetch** operation, which would otherwise involve retrieving documents from disk.

#### **Covered Query Scenario**:

Consider a `users` collection that has the following index:

```js
db.users.createIndex({ age: 1, name: 1 });
```

Now, let's say you run the following query:

```js
db.users.find({ age: 30 }, { name: 1 });
```

In this case, the query is **covered** because:
- The query filters by the `age` field, which is part of the index.
- The projection requests only the `name` field, which is also part of the index.

Since both the `age` and `name` fields are part of the index, MongoDB can retrieve the results directly from the index without needing to access the actual documents.

---

### **When is a Query Covered?**

A query will be covered if:
1. **All Fields in the Query** (both the filter and projection) are part of an index.
2. **No Fields in the Projection** are missing from the index.

#### **Example 1: Covered Query**

```js
db.users.createIndex({ age: 1, name: 1 });  // Creating index on age and name

// Query is covered because both the query and projection are on indexed fields
db.users.find({ age: 30 }, { name: 1 }).explain("executionStats");
```

Here, the query only uses the `age` and `name` fields, which are part of the index. MongoDB can fulfill the query using the index, resulting in a covered query.

**`explain()` Output for Covered Query:**

```json
{
  "queryPlanner": {
    "plannerVersion": 1,
    "namespace": "test.users",
    "indexFilterSet": false,
    "parsedQuery": { "age": 30 },
    "winningPlan": {
      "stage": "IXSCAN",
      "keyPattern": { "age": 1, "name": 1 },
      "inputStage": {
        "stage": "RETURN",
        "docsExamined": 0,
        "keysExamined": 10
      }
    }
  },
  "executionStats": {
    "nReturned": 10,
    "executionTimeMillis": 1,
    "totalDocsExamined": 0,
    "totalKeysExamined": 10
  }
}
```

Notice that no documents are examined (`docsExamined: 0`), as the results are returned directly from the index (`keysExamined: 10`).

---

#### **Example 2: Not a Covered Query**

```js
// Query that is NOT covered because the projection includes the _id field, which is not part of the index
db.users.find({ age: 30 }, { name: 1, _id: 1 }).explain("executionStats");
```

Even though the query filters on `age`, the projection asks for `_id`, which is not part of the index (`age`, `name`). Therefore, MongoDB cannot fully satisfy the query with the index, and it will need to perform a fetch operation.

**`explain()` Output for Non-Covered Query:**

```json
{
  "queryPlanner": {
    "plannerVersion": 1,
    "namespace": "test.users",
    "indexFilterSet": false,
    "parsedQuery": { "age": 30 },
    "winningPlan": {
      "stage": "IXSCAN",
      "keyPattern": { "age": 1, "name": 1 },
      "inputStage": {
        "stage": "FETCH",
        "inputStage": {
          "stage": "IXSCAN",
          "keyPattern": { "age": 1, "name": 1 }
        }
      }
    }
  },
  "executionStats": {
    "nReturned": 10,
    "executionTimeMillis": 3,
    "totalDocsExamined": 10,
    "totalKeysExamined": 10
  }
}
```

In this case, MongoDB has to examine the documents because the `_id` field is not covered by the index. Therefore, **10 documents** are examined and fetched from disk, which makes the query slower.

---

### **Benefits of Covered Queries**

1. **Improved Performance**: Covered queries are faster because they avoid the need to access actual documents. The data is returned directly from the index.
2. **Lower I/O Overhead**: Since MongoDB doesn't have to retrieve documents from disk, it saves on I/O operations, reducing query execution time.
3. **Efficient for Read-Heavy Workloads**: Covered queries can be particularly effective in read-heavy applications where the query involves common fields that can be indexed.

---

### **Creating Indexes for Covered Queries**

To ensure that queries can be covered by an index, you need to:
1. Create an index that includes all the fields used in the query filter and projection.
2. Consider compound indexes when queries involve multiple fields.

#### **Example: Creating Compound Indexes**

If you frequently run queries that filter by `age` and `name`, and also request the `name` field in the projection, you can create a compound index:

```js
db.users.createIndex({ age: 1, name: 1 });
```

This index will cover any query that filters by `age` and projects `name`, and vice versa.

---

### **Limitations of Covered Queries**

1. **Limited to Indexed Fields**: A query can only be covered if all necessary fields (filter and projection) are part of the index. If you need fields that are not in the index, the query will not be covered.
2. **Projection Restrictions**: The projection cannot include fields that are not part of the index. For example, if the projection requires the `_id` field and it’s not included in the index, the query will not be covered.
3. **Memory Usage**: Covered queries can sometimes increase memory usage, as the entire index must be stored in memory for retrieval. 

---

### **Covered Queries and Compound Indexes**

Using **compound indexes** (indexes that include multiple fields) is one of the most common ways to create covered queries. For instance, if you frequently query for `age` and `name`, creating a compound index on `{ age: 1, name: 1 }` can ensure that the query is covered.

#### **Example of a Compound Index for Covered Queries**

```js
db.users.createIndex({ age: 1, name: 1 });
```

With this compound index, the following query is **covered**:

```js
db.users.find({ age: 30 }, { name: 1 });
```

In this case, the index contains both `age` (for filtering) and `name` (for projection), making the query a covered query.

---

### **Conclusion**

Covered queries are an important optimization technique in MongoDB that can drastically improve query performance by allowing MongoDB to use an index to return results without needing to access the full documents. To create covered queries, ensure that the query filter and projection are fully covered by an index. Using compound indexes strategically can make queries faster and reduce the load on the server. Understanding how and when to use covered queries is key to optimizing MongoDB performance, particularly for read-heavy applications.
