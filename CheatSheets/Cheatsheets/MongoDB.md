An extended MongoDB cheat sheet that covers various commands, how to use them, and explanations. This cheat sheet includes operations for both the MongoDB shell and drivers in different programming languages.

---

# **MongoDB Extended Cheat Sheet**

## **1. MongoDB Basics**

### 1.1 Connecting to MongoDB

**Command:**
```bash
mongo
```
**Explanation**: Connects to the MongoDB server running on `localhost` at the default port `27017`. You can specify a URI for remote connections.

### 1.2 Show Databases

**Command:**
```javascript
show dbs
```
**Explanation**: Lists all databases on the MongoDB server along with their sizes.

### 1.3 Switch Database

**Command:**
```javascript
use database_name
```
**Explanation**: Switches to the specified database. If the database does not exist, it will be created when a document is inserted.

---

## **2. Working with Databases**

### 2.1 Create Database

**Command:**
```javascript
use new_database
```
**Explanation**: Creates a new database. The database is not created until a document is inserted.

### 2.2 Drop Database

**Command:**
```javascript
db.dropDatabase()
```
**Explanation**: Deletes the current database and all its collections.

---

## **3. Collections**

### 3.1 Show Collections

**Command:**
```javascript
show collections
```
**Explanation**: Lists all collections in the current database.

### 3.2 Create Collection

**Command:**
```javascript
db.createCollection("collection_name")
```
**Explanation**: Explicitly creates a new collection. However, collections are created automatically when the first document is inserted.

### 3.3 Drop Collection

**Command:**
```javascript
db.collection_name.drop()
```
**Explanation**: Deletes the specified collection and all its documents.

---

## **4. CRUD Operations**

### 4.1 Insert Documents

**Command (Single Document):**
```javascript
db.collection_name.insertOne({ key: "value" })
```
**Explanation**: Inserts a single document into the specified collection.

**Command (Multiple Documents):**
```javascript
db.collection_name.insertMany([{ key1: "value1" }, { key2: "value2" }])
```
**Explanation**: Inserts multiple documents into the specified collection.

### 4.2 Query Documents

**Command:**
```javascript
db.collection_name.find({ key: "value" })
```
**Explanation**: Retrieves documents that match the specified criteria.

### 4.3 Query All Documents

**Command:**
```javascript
db.collection_name.find().pretty()
```
**Explanation**: Retrieves all documents in the collection and formats the output for better readability.

### 4.4 Update Documents

**Command (Single Document):**
```javascript
db.collection_name.updateOne({ key: "old_value" }, { $set: { key: "new_value" } })
```
**Explanation**: Updates a single document that matches the filter.

**Command (Multiple Documents):**
```javascript
db.collection_name.updateMany({ key: "old_value" }, { $set: { key: "new_value" } })
```
**Explanation**: Updates multiple documents that match the filter.

### 4.5 Delete Documents

**Command (Single Document):**
```javascript
db.collection_name.deleteOne({ key: "value" })
```
**Explanation**: Deletes a single document that matches the filter.

**Command (Multiple Documents):**
```javascript
db.collection_name.deleteMany({ key: "value" })
```
**Explanation**: Deletes all documents that match the filter.

---

## **5. Indexing**

### 5.1 Create Index

**Command:**
```javascript
db.collection_name.createIndex({ key: 1 })  // 1 for ascending, -1 for descending
```
**Explanation**: Creates an index on the specified field to improve query performance.

### 5.2 List Indexes

**Command:**
```javascript
db.collection_name.getIndexes()
```
**Explanation**: Lists all indexes on the specified collection.

### 5.3 Drop Index

**Command:**
```javascript
db.collection_name.dropIndex("index_name")
```
**Explanation**: Deletes the specified index from the collection.

---

## **6. Aggregation**

### 6.1 Basic Aggregation

**Command:**
```javascript
db.collection_name.aggregate([{ $match: { key: "value" } }])
```
**Explanation**: Performs aggregation operations such as filtering, grouping, and sorting. In this example, it filters documents based on the key.

### 6.2 Grouping

**Command:**
```javascript
db.collection_name.aggregate([
    { $group: { _id: "$key", total: { $sum: "$value" } } }
])
```
**Explanation**: Groups documents by the specified field (`key`) and calculates the sum of another field (`value`).

---

## **7. Data Validation**

### 7.1 Schema Validation

**Command:**
```javascript
db.createCollection("collection_name", {
    validator: {
        $jsonSchema: {
            bsonType: "object",
            required: ["key"],
            properties: {
                key: {
                    bsonType: "string",
                    description: "must be a string and is required"
                }
            }
        }
    }
})
```
**Explanation**: Creates a collection with a JSON Schema validator to enforce data structure.

---

## **8. Transactions**

### 8.1 Start a Transaction

**Command:**
```javascript
session = db.getMongo().startSession();
session.startTransaction();
```
**Explanation**: Initiates a session for transaction operations.

### 8.2 Commit a Transaction

**Command:**
```javascript
session.commitTransaction();
session.endSession();
```
**Explanation**: Commits the transaction, making all changes permanent.

### 8.3 Abort a Transaction

**Command:**
```javascript
session.abortTransaction();
session.endSession();
```
**Explanation**: Aborts the transaction, rolling back any changes made during the transaction.

---

## **9. Backup and Restore**

### 9.1 Backup

**Command:**
```bash
mongodump --db database_name --out /path/to/backup
```
**Explanation**: Creates a binary export of the specified database.

### 9.2 Restore

**Command:**
```bash
mongorestore --db database_name /path/to/backup/database_name
```
**Explanation**: Restores a database from a backup created with `mongodump`.

---

## **10. Replication and Sharding**

### 10.1 Set Up Replica Set

**Command:**
```javascript
rs.initiate()
```
**Explanation**: Initializes a new replica set. Must be run on the primary member.

### 10.2 Add Member to Replica Set

**Command:**
```javascript
rs.add("hostname:port")
```
**Explanation**: Adds a new member to the existing replica set.

### 10.3 Set Up Sharding

**Command:**
```javascript
sh.enableSharding("database_name")
```
**Explanation**: Enables sharding on a database.

---

## **11. Users and Roles**

### 11.1 Create User

**Command:**
```javascript
db.createUser({
    user: "username",
    pwd: "password",
    roles: [{ role: "readWrite", db: "database_name" }]
})
```
**Explanation**: Creates a new user with specified roles in the database.

### 11.2 Drop User

**Command:**
```javascript
db.dropUser("username")
```
**Explanation**: Deletes a specified user from the database.

### 11.3 List Users

**Command:**
```javascript
db.getUsers()
```
**Explanation**: Lists all users in the current database.

---

## **12. Common Queries**

### 12.1 Find with Projection

**Command:**
```javascript
db.collection_name.find({}, { key1: 1, key2: 1 })
```
**Explanation**: Retrieves all documents but only includes `key1` and `key2` in the output.

### 12.2 Find with Sorting

**Command:**
```javascript
db.collection_name.find().sort({ key: 1 }) // 1 for ascending, -1 for descending
```
**Explanation**: Retrieves all documents sorted by the specified key.

### 12.3 Count Documents

**Command:**
```javascript
db.collection_name.countDocuments({ key: "value" })
```
**Explanation**: Counts the number of documents that match the specified filter.

---

This cheat sheet provides an overview of common MongoDB commands and their explanations, helping you navigate and utilize MongoDB effectively.
