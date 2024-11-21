### **MongoDB - Capped Collections**

A **capped collection** in MongoDB is a special type of collection with fixed-size storage. Unlike standard collections, capped collections automatically overwrite the oldest documents when they reach their maximum size. This feature is beneficial for applications requiring a circular or rolling data storage approach, such as logs, cache, or real-time data feeds.

### **Characteristics of Capped Collections**

- **Fixed Size**: The collection has a pre-defined maximum size in bytes. Once it reaches this size, it will automatically start deleting the oldest documents to make room for new ones.
- **Insertion Order**: Documents are stored in insertion order, and querying based on insertion order is optimized.
- **No Document Deletions or Updates to Change Size**: Individual documents cannot be deleted from a capped collection. Updates are only allowed if they don’t change the document size.
- **High Performance**: Capped collections are optimized for high-speed inserts and retrieval in insertion order.

### **Creating a Capped Collection**

To create a capped collection, use the `createCollection` command with the `capped` option set to `true` and specify the maximum size:

```js
db.createCollection("log", { capped: true, size: 100000 });
```

In this example:
- `"log"` is the name of the capped collection.
- `capped: true` specifies that the collection should be capped.
- `size: 100000` sets the maximum size of the collection to 100,000 bytes (approximately 100 KB).

Optionally, you can also specify the maximum number of documents:

```js
db.createCollection("log", { capped: true, size: 100000, max: 500 });
```

Here, in addition to the size constraint, the collection can hold a maximum of 500 documents. If the collection reaches this limit, it will remove the oldest document when a new one is inserted.

### **Example: Inserting Data into a Capped Collection**

When you insert documents into a capped collection, MongoDB will automatically remove the oldest document to make room if the collection is full.

```js
db.log.insertOne({ message: "System started", timestamp: new Date() });
db.log.insertOne({ message: "User logged in", timestamp: new Date() });
```

In this case, if the capped collection size or document limit is reached, the oldest document in the `log` collection will be removed to accommodate new entries.

### **Querying Capped Collections**

Capped collections maintain insertion order, and queries that return documents in this order are optimized.

To retrieve documents in insertion order, you can use a simple `find()`:

```js
db.log.find();
```

To retrieve documents in reverse order, use `.sort({ $natural: -1 })`:

```js
db.log.find().sort({ $natural: -1 });
```

The `$natural` sort order returns documents based on the order they are stored.

### **Advantages of Capped Collections**

- **Efficient for High-Volume Data**: Ideal for data that constantly changes, like logs or real-time data, where only the latest data is required.
- **Fixed Storage**: Since the size is fixed, capped collections prevent unbounded growth, making it easy to control storage usage.
- **High Performance**: Optimized for high-speed inserts and reads, as MongoDB doesn’t need to search for empty space within the collection.
- **Automatic Data Purging**: Older data is automatically removed, reducing the need for manual deletion.

### **Limitations of Capped Collections**

- **No Deletion of Individual Documents**: You cannot delete individual documents, which can limit their usage for applications requiring dynamic data removal.
- **No Document Size Updates**: Document updates that increase the document size are not allowed. If an update increases the size of a document, it will fail.
- **Fixed Document Count (Optional)**: If you specify a `max` document count, it will strictly enforce this limit along with the size limit.

### **Use Cases for Capped Collections**

1. **Log Storage**: Store application logs, server logs, or audit logs with automatic deletion of old logs.
2. **Message Queues**: Store a fixed number of messages with automatic removal of old messages to make room for new ones.
3. **Sensor Data**: For IoT applications, store a rolling window of sensor data.
4. **Real-Time Analytics**: Store recent events or activity, providing a snapshot of recent data without persisting old data.

### **Converting an Existing Collection to a Capped Collection**

If you want to convert an existing collection into a capped collection, use the `convertToCapped` command:

```js
db.runCommand({ convertToCapped: "myCollection", size: 50000 });
```

This command converts the `myCollection` collection to a capped collection with a maximum size of 50,000 bytes.

### **Example: Using a Capped Collection for Logs**

1. **Create a Capped Collection**:

   ```js
   db.createCollection("logs", { capped: true, size: 500000 });
   ```

2. **Insert Log Entries**:

   ```js
   db.logs.insertOne({ level: "INFO", message: "Application started", timestamp: new Date() });
   db.logs.insertOne({ level: "ERROR", message: "Failed to connect to database", timestamp: new Date() });
   ```

3. **Query the Latest Logs**:

   ```js
   db.logs.find().sort({ $natural: -1 }).limit(10);
   ```

This example maintains a capped collection of recent log entries, providing a rotating log storage system with automatic removal of old logs.

### **Conclusion**

Capped collections in MongoDB provide an efficient, fixed-size data structure suited to applications where a rolling data window is useful, such as logging, caching, and real-time analytics. By managing the data lifecycle automatically, capped collections optimize storage and performance for use cases requiring only the most recent data.
