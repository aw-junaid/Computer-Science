### **MongoDB - Query Document**

In MongoDB, querying documents allows you to retrieve data from collections based on specified criteria. MongoDB provides a powerful query language that supports a variety of operators and methods to filter, sort, and project documents.

### **Step 1: Connect to MongoDB**

Open your terminal and start the Mongo shell by typing:

```bash
mongosh
```

This will connect you to the default database (`test`). Switch to the desired database using the `use` command:

```javascript
use myDatabase
```

### **Step 2: Basic Query to Retrieve Documents**

To retrieve all documents from a collection, use the `find()` method. By default, `find()` retrieves all documents.

#### **Example:**

```javascript
db.users.find()
```

This will return all documents in the `users` collection. If there are many documents, MongoDB may paginate the output. You can use `pretty()` to format the output for easier readability.

```javascript
db.users.find().pretty()
```

---

### **Step 3: Query with Specific Criteria**

You can add query conditions inside the `find()` method to retrieve documents that match specific criteria. The criteria are specified using a JavaScript object.

#### **Example 1: Find Users by Name**

To find all users with the name `"John"`:

```javascript
db.users.find({ name: "John" })
```

This query will return all documents in the `users` collection where the `name` field is equal to `"John"`.

#### **Example 2: Find Users by Age**

To find all users who are older than 25:

```javascript
db.users.find({ age: { $gt: 25 } })
```

This query uses the `$gt` (greater than) operator to match documents where the `age` field is greater than 25.

#### **Example 3: Find Users by Age and Name**

To find users named `"John"` who are older than 25:

```javascript
db.users.find({ name: "John", age: { $gt: 25 } })
```

This query returns documents that meet both conditions: `name` equals `"John"` and `age` is greater than 25.

---

### **Step 4: Query Operators**

MongoDB supports various query operators for more advanced queries. Below are some of the most commonly used operators:

#### **1. Comparison Operators:**

- **$eq**: Equal to (default operator if no operator is provided).
  
  ```javascript
  db.users.find({ age: { $eq: 30 } })
  ```

- **$gt**: Greater than.
  
  ```javascript
  db.users.find({ age: { $gt: 30 } })
  ```

- **$gte**: Greater than or equal to.
  
  ```javascript
  db.users.find({ age: { $gte: 30 } })
  ```

- **$lt**: Less than.
  
  ```javascript
  db.users.find({ age: { $lt: 30 } })
  ```

- **$lte**: Less than or equal to.
  
  ```javascript
  db.users.find({ age: { $lte: 30 } })
  ```

- **$ne**: Not equal to.
  
  ```javascript
  db.users.find({ age: { $ne: 30 } })
  ```

#### **2. Logical Operators:**

- **$and**: Combine multiple conditions using AND.
  
  ```javascript
  db.users.find({ $and: [{ age: { $gt: 20 } }, { name: "John" }] })
  ```

- **$or**: Combine multiple conditions using OR.
  
  ```javascript
  db.users.find({ $or: [{ name: "John" }, { age: { $lt: 25 } }] })
  ```

- **$not**: Negates the query.
  
  ```javascript
  db.users.find({ age: { $not: { $gt: 30 } } })
  ```

#### **3. Element Operators:**

- **$exists**: Check if a field exists.

  ```javascript
  db.users.find({ email: { $exists: true } })
  ```

- **$type**: Check the type of a field.

  ```javascript
  db.users.find({ age: { $type: "int" } })
  ```

---

### **Step 5: Limiting and Sorting the Results**

#### **1. Limit the Number of Results**

You can limit the number of documents returned by using the `limit()` method.

```javascript
db.users.find().limit(5)
```

This will return the first 5 documents from the `users` collection.

#### **2. Sort the Results**

You can sort the results by using the `sort()` method. Pass a JavaScript object that specifies the field(s) to sort by. For example, to sort by `age` in ascending order:

```javascript
db.users.find().sort({ age: 1 })
```

For descending order, use `-1`:

```javascript
db.users.find().sort({ age: -1 })
```

#### **3. Limit and Sort Together**

You can combine `limit()` and `sort()` methods to both limit and sort the query results:

```javascript
db.users.find().sort({ age: 1 }).limit(5)
```

This will return the first 5 documents sorted by `age` in ascending order.

---

### **Step 6: Projecting Specific Fields**

You can control which fields are returned by using the projection option in the `find()` method. Set the fields you want to include or exclude.

#### **Example 1: Include Specific Fields**

To include only the `name` and `age` fields:

```javascript
db.users.find({}, { name: 1, age: 1 })
```

Here, `{ name: 1, age: 1 }` means "include the `name` and `age` fields in the result." The `_id` field is included by default, but you can exclude it if you don't need it:

```javascript
db.users.find({}, { name: 1, age: 1, _id: 0 })
```

#### **Example 2: Exclude Specific Fields**

To exclude the `email` field from the result:

```javascript
db.users.find({}, { email: 0 })
```

This will exclude the `email` field from the results.

---

### **Step 7: Using Regular Expressions**

MongoDB supports regular expressions for querying string fields.

#### **Example: Find Users with a Specific Pattern in the Name**

To find all users whose name starts with `"John"`:

```javascript
db.users.find({ name: { $regex: "^John" } })
```

This uses the `$regex` operator to match names that begin with `"John"`.

---

### **Step 8: Aggregation Queries**

For more complex queries, such as grouping, counting, or performing calculations, you can use the **aggregation framework** with the `aggregate()` method.

#### **Example: Count Users by Age Group**

```javascript
db.users.aggregate([
  { $group: { _id: "$age", count: { $sum: 1 } } }
])
```

This will group users by their `age` and return the count of users in each age group.

---

### **Conclusion**

MongoDB provides powerful querying capabilities that allow you to retrieve, filter, sort, and manipulate documents based on various conditions. The `find()` method is the primary way to query documents, but MongoDB also supports advanced operators and aggregation features for more complex use cases. Understanding these features helps you efficiently retrieve the data you need from your MongoDB database.
