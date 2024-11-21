### **MongoDB - Aggregation**

Aggregation in MongoDB is the process of transforming data in the database to get a desired result. It involves processing data records and returning computed results. Aggregation operations are essential for performing tasks such as summing values, filtering data, grouping records, or calculating averages. MongoDB provides a powerful **Aggregation Framework** that allows complex data manipulations and transformations.

The aggregation framework in MongoDB is expressed using **aggregation pipelines**, which consist of stages that process the data in a sequence.

### **Step 1: Aggregation Pipeline**

An **aggregation pipeline** is a series of stages that process the documents in a collection. Each stage performs a specific operation on the data, and the output of one stage is passed as input to the next stage.

The basic structure of an aggregation pipeline looks like this:

```javascript
db.collection.aggregate([
  { $stage1 },
  { $stage2 },
  { $stage3 },
  ...
])
```

Each stage in the pipeline uses a special operator to perform a specific transformation or operation on the data.

### **Step 2: Common Aggregation Operators**

Here are some of the most commonly used aggregation operators in MongoDB:

#### **$match**
- Filters the documents that pass through the pipeline, similar to the `find()` method.
- Can be used for querying specific fields or applying conditions.
  
```javascript
{ $match: { age: { $gt: 30 } } }
```

This will match documents where the `age` field is greater than 30.

#### **$group**
- Groups documents by a specified identifier and performs aggregation operations (like sum, average, count) on each group.

```javascript
{ $group: { _id: "$age", totalUsers: { $sum: 1 } } }
```

This will group the documents by the `age` field and count the total number of users in each age group.

#### **$project**
- Reshapes each document in the pipeline by adding, removing, or changing the value of fields.
- It can be used to create new fields, rename existing fields, or exclude fields from the output.

```javascript
{ $project: { name: 1, age: 1, _id: 0 } }
```

This will project only the `name` and `age` fields, excluding the `_id` field.

#### **$sort**
- Sorts the documents in the pipeline in ascending or descending order.

```javascript
{ $sort: { age: -1 } }
```

This will sort the documents by the `age` field in **descending** order.

#### **$limit**
- Limits the number of documents that pass through the pipeline.

```javascript
{ $limit: 5 }
```

This will return only the first 5 documents.

#### **$skip**
- Skips the first N documents in the pipeline.

```javascript
{ $skip: 10 }
```

This will skip the first 10 documents in the result.

#### **$unwind**
- Deconstructs an array field from the input documents and outputs a document for each element in the array.

```javascript
{ $unwind: "$tags" }
```

This will "unwind" the `tags` array, so each element of the array will appear as a separate document.

#### **$count**
- Counts the number of documents in the pipeline.

```javascript
{ $count: "total" }
```

This will return a single document with the total count of documents.

#### **$addFields**
- Adds new fields or modifies existing fields in the pipeline.

```javascript
{ $addFields: { fullName: { $concat: ["$firstName", " ", "$lastName"] } } }
```

This adds a new field `fullName` by concatenating the `firstName` and `lastName` fields.

#### **$facet**
- Allows multiple pipelines to be run within a single aggregation stage, useful for complex analysis.

```javascript
{ $facet: {
    "ageGroup": [{ $group: { _id: "$age", count: { $sum: 1 } } }],
    "cityGroup": [{ $group: { _id: "$city", count: { $sum: 1 } } }]
}}
```

This runs two pipelines in parallel: one for grouping by `age` and one for grouping by `city`.

---

### **Step 3: Common Aggregation Examples**

#### **Example 1: Total Number of Users by Age Group**

This example groups the documents by `age` and counts the total number of users in each age group.

```javascript
db.users.aggregate([
  { $group: { _id: "$age", totalUsers: { $sum: 1 } } }
])
```

**Output:**

```json
[
  { "_id": 25, "totalUsers": 100 },
  { "_id": 30, "totalUsers": 80 },
  { "_id": 35, "totalUsers": 60 }
]
```

#### **Example 2: Average Age of Users**

This example calculates the average age of users in the collection.

```javascript
db.users.aggregate([
  { $group: { _id: null, averageAge: { $avg: "$age" } } }
])
```

**Output:**

```json
[
  { "_id": null, "averageAge": 28.5 }
]
```

#### **Example 3: Filtering and Sorting Data**

This example filters users older than 30 and sorts them by `name` in ascending order.

```javascript
db.users.aggregate([
  { $match: { age: { $gt: 30 } } },
  { $sort: { name: 1 } }
])
```

**Output:**

```json
[
  { "_id": ObjectId("..."), "name": "Alice", "age": 35 },
  { "_id": ObjectId("..."), "name": "Bob", "age": 40 }
]
```

#### **Example 4: Unwind and Group Data**

This example unwinds an array field `tags` and counts how many times each tag appears.

```javascript
db.products.aggregate([
  { $unwind: "$tags" },
  { $group: { _id: "$tags", count: { $sum: 1 } } }
])
```

**Output:**

```json
[
  { "_id": "electronics", "count": 50 },
  { "_id": "furniture", "count": 30 }
]
```

#### **Example 5: Projecting Fields and Renaming Them**

This example projects only specific fields (`name`, `age`), renaming `age` to `yearsOld`.

```javascript
db.users.aggregate([
  { $project: { name: 1, yearsOld: "$age" } }
])
```

**Output:**

```json
[
  { "_id": ObjectId("..."), "name": "Alice", "yearsOld": 30 },
  { "_id": ObjectId("..."), "name": "Bob", "yearsOld": 25 }
]
```

---

### **Step 4: Aggregation Performance Considerations**

- **Indexes**: Aggregation operations can be faster if proper indexes are applied. For example, indexing the fields that you use in the `$match` or `$sort` stages can significantly improve performance.
- **Pipeline Optimization**: MongoDB optimizes the pipeline stages, but careful ordering can improve performance. For instance, placing `$match` as early as possible can reduce the number of documents processed in later stages.
- **Memory Usage**: Some aggregation operations, such as `$group`, require significant memory, especially if they involve large datasets. MongoDB will store temporary data in RAM, so be mindful of the memory available when performing large aggregations.

---

### **Step 5: Using Explain with Aggregation**

You can use the `explain()` method to analyze the performance of an aggregation pipeline:

```javascript
db.users.aggregate([
  { $match: { age: { $gt: 30 } } },
  { $sort: { name: 1 } }
]).explain("executionStats")
```

This provides detailed information on how MongoDB executed the aggregation, including the time spent and whether indexes were used.

---

### **Conclusion**

MongoDB’s aggregation framework is powerful for transforming and processing data. With operators like `$match`, `$group`, `$sort`, `$project`, and `$unwind`, you can perform complex data manipulations in a simple and efficient manner. Using the aggregation pipeline, you can filter, sort, group, and reshape your data to generate insights and reports. However, performance considerations such as indexing and memory usage are important to optimize when working with large datasets.
