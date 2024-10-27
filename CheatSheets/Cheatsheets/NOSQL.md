An extended NoSQL cheat sheet that covers essential commands, concepts, and examples related to different NoSQL databases. Given the diversity in NoSQL systems (e.g., document stores, key-value stores, column-family stores, and graph databases), this cheat sheet will cover some of the most popular NoSQL databases: MongoDB, Redis, Cassandra, and Neo4j.

---

## **1. MongoDB (Document Store)**

### 1.1 MongoDB Basics

#### Installation

- **Download** from the [MongoDB website](https://www.mongodb.com/try/download/community).
- **Start MongoDB**: Use the command:
  ```bash
  mongod
  ```

#### Connecting to MongoDB

```bash
mongo
```

**Explanation**: The `mongo` command opens the MongoDB shell to interact with the database.

---

### 1.2 Database Operations

#### Create a Database

```javascript
use myDatabase
```

**Explanation**: Switches to `myDatabase`. If it doesn’t exist, it will be created when you first store data.

#### List Databases

```javascript
show dbs
```

**Explanation**: Lists all databases on the server.

#### Drop a Database

```javascript
db.dropDatabase()
```

**Explanation**: Deletes the currently selected database.

---

### 1.3 Collection Operations

#### Create a Collection

```javascript
db.createCollection("myCollection")
```

**Explanation**: Explicitly creates a new collection named `myCollection`.

#### List Collections

```javascript
show collections
```

**Explanation**: Displays all collections in the current database.

#### Drop a Collection

```javascript
db.myCollection.drop()
```

**Explanation**: Deletes the specified collection.

---

### 1.4 Document Operations

#### Insert Documents

```javascript
db.myCollection.insertOne({ name: "John", age: 30 })
db.myCollection.insertMany([{ name: "Jane", age: 25 }, { name: "Mike", age: 35 }])
```

**Explanation**: Inserts one or multiple documents into `myCollection`.

#### Query Documents

```javascript
db.myCollection.find({ name: "John" })
db.myCollection.find({ age: { $gt: 30 } })  // Greater than
```

**Explanation**: The `find()` method retrieves documents from the collection.

#### Update Documents

```javascript
db.myCollection.updateOne({ name: "John" }, { $set: { age: 31 } })
db.myCollection.updateMany({ age: { $lt: 30 } }, { $set: { status: "young" } })
```

**Explanation**: Updates documents matching the criteria.

#### Delete Documents

```javascript
db.myCollection.deleteOne({ name: "John" })
db.myCollection.deleteMany({ age: { $lt: 30 } })
```

**Explanation**: Deletes documents that match the specified criteria.

---

### 1.5 Aggregation

#### Aggregation Pipeline

```javascript
db.myCollection.aggregate([
    { $match: { age: { $gte: 25 } } },
    { $group: { _id: "$name", averageAge: { $avg: "$age" } } }
])
```

**Explanation**: The aggregation pipeline processes data records and returns computed results.

---

## **2. Redis (Key-Value Store)**

### 2.1 Redis Basics

#### Installation

- **Download** from the [Redis website](https://redis.io/download).
- **Start Redis**: Use the command:
  ```bash
  redis-server
  ```

#### Connecting to Redis

```bash
redis-cli
```

**Explanation**: Opens the Redis command-line interface.

---

### 2.2 Basic Commands

#### Set a Key-Value Pair

```bash
SET name "John"
```

**Explanation**: Stores a string value "John" with the key `name`.

#### Get a Value by Key

```bash
GET name
```

**Explanation**: Retrieves the value associated with the key `name`.

#### Delete a Key

```bash
DEL name
```

**Explanation**: Deletes the specified key and its value.

---

### 2.3 Data Structures

#### Lists

```bash
LPUSH mylist "item1"      # Add to the beginning
RPUSH mylist "item2"      # Add to the end
LRANGE mylist 0 -1        # Get all items
```

**Explanation**: Operations on lists, allowing adding and retrieving items.

#### Sets

```bash
SADD myset "value1"       # Add unique value
SMEMBERS myset             # Get all unique values
```

**Explanation**: Operations on sets, ensuring all values are unique.

---

### 2.4 Pub/Sub Messaging

```bash
SUBSCRIBE mychannel
PUBLISH mychannel "Hello, Redis!"
```

**Explanation**: The Publish/Subscribe pattern allows sending messages to multiple subscribers.

---

## **3. Cassandra (Column-Family Store)**

### 3.1 Cassandra Basics

#### Installation

- **Download** from the [Apache Cassandra website](http://cassandra.apache.org/download/).
- **Start Cassandra**: Use the command:
  ```bash
  cassandra -f
  ```

#### Connecting to Cassandra

```bash
cqlsh
```

**Explanation**: Opens the Cassandra Query Language shell.

---

### 3.2 Keyspace Operations

#### Create a Keyspace

```sql
CREATE KEYSPACE mykeyspace WITH REPLICATION = {'class': 'SimpleStrategy', 'replication_factor': 1};
```

**Explanation**: Creates a keyspace with the specified replication strategy.

#### Use a Keyspace

```sql
USE mykeyspace;
```

**Explanation**: Selects the specified keyspace to work within.

---

### 3.3 Table Operations

#### Create a Table

```sql
CREATE TABLE users (id UUID PRIMARY KEY, name TEXT, age INT);
```

**Explanation**: Defines a new table with specified columns and primary key.

#### Insert Data

```sql
INSERT INTO users (id, name, age) VALUES (uuid(), 'John Doe', 30);
```

**Explanation**: Inserts a new row into the `users` table.

#### Query Data

```sql
SELECT * FROM users WHERE name = 'John Doe';
```

**Explanation**: Retrieves rows from the `users` table based on specified criteria.

#### Update Data

```sql
UPDATE users SET age = 31 WHERE name = 'John Doe';
```

**Explanation**: Modifies existing rows based on the criteria.

#### Delete Data

```sql
DELETE FROM users WHERE name = 'John Doe';
```

**Explanation**: Removes specified rows from the `users` table.

---

## **4. Neo4j (Graph Database)**

### 4.1 Neo4j Basics

#### Installation

- **Download** from the [Neo4j website](https://neo4j.com/download/).
- **Start Neo4j**: Use the command:
  ```bash
  neo4j console
  ```

#### Connecting to Neo4j

- Access via **Neo4j Browser** at `http://localhost:7474`.

---

### 4.2 Node and Relationship Operations

#### Create a Node

```cypher
CREATE (n:Person {name: 'John', age: 30});
```

**Explanation**: Creates a new node with label `Person` and specified properties.

#### Query Nodes

```cypher
MATCH (n:Person) WHERE n.name = 'John' RETURN n;
```

**Explanation**: Retrieves nodes matching the specified criteria.

#### Create a Relationship

```cypher
MATCH (a:Person), (b:Person) WHERE a.name = 'John' AND b.name = 'Jane' CREATE (a)-[:FRIENDS_WITH]->(b);
```

**Explanation**: Establishes a relationship between two nodes.

---

### 4.3 Updating and Deleting

#### Update a Node

```cypher
MATCH (n:Person {name: 'John'}) SET n.age = 31;
```

**Explanation**: Updates the properties of a node.

#### Delete a Node

```cypher
MATCH (n:Person {name: 'John'}) DELETE n;
```

**Explanation**: Deletes the specified node.

---

### 4.4 Querying Relationships

#### Query Relationships

```cypher
MATCH (a:Person)-[:FRIENDS_WITH]->(b:Person) RETURN a, b;
```

**Explanation**: Retrieves nodes connected by a specified relationship.

---

## **Conclusion**

This cheat sheet provides a comprehensive overview of essential commands and concepts across various NoSQL databases, including MongoDB, Redis, Cassandra, and Neo4j. Regular practice with these commands will help you become proficient in NoSQL database management.
