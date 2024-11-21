### **MongoDB - Java**

MongoDB can be easily integrated with Java applications using the official MongoDB Java Driver. The Java Driver allows you to interact with MongoDB databases, perform CRUD operations, and use advanced features like aggregation, indexing, and transactions within Java applications.

Below is an overview of how to get started with MongoDB in Java:

---

### **1. MongoDB Java Driver Setup**

Before you start writing Java code, you need to set up the MongoDB Java Driver. You can use **Maven** or **Gradle** for dependency management.

#### **Using Maven:**

Add the following dependency to your `pom.xml` file:

```xml
<dependency>
    <groupId>org.mongodb</groupId>
    <artifactId>mongo-java-driver</artifactId>
    <version>4.9.0</version> <!-- Use the latest version -->
</dependency>
```

#### **Using Gradle:**

Add the following dependency to your `build.gradle` file:

```gradle
dependencies {
    implementation 'org.mongodb:mongo-java-driver:4.9.0' // Use the latest version
}
```

---

### **2. Connecting to MongoDB**

Once you have the MongoDB Java driver set up, the first thing you need to do is connect to the MongoDB server.

#### **Simple MongoDB Connection Example**:

```java
import com.mongodb.MongoClient;
import com.mongodb.MongoClientURI;
import com.mongodb.client.MongoDatabase;

public class MongoDBJavaExample {
    public static void main(String[] args) {
        // Connection URI
        String uri = "mongodb://localhost:27017"; // Localhost MongoDB instance

        // Create MongoClient
        MongoClient mongoClient = new MongoClient(new MongoClientURI(uri));

        // Get database
        MongoDatabase database = mongoClient.getDatabase("mydb");

        System.out.println("Connected to database successfully");

        // Close the connection
        mongoClient.close();
    }
}
```

In this example:
- `MongoClientURI` specifies the MongoDB connection string.
- `MongoClient` establishes the connection to the MongoDB server.
- `getDatabase()` retrieves a MongoDB database.

---

### **3. CRUD Operations in MongoDB using Java**

Now that you have established a connection, you can perform **Create**, **Read**, **Update**, and **Delete** operations on the MongoDB collections.

#### **Create Document (Insert)**:

```java
import com.mongodb.client.MongoCollection;
import org.bson.Document;

public class MongoDBInsert {
    public static void main(String[] args) {
        MongoClient mongoClient = new MongoClient("localhost", 27017);
        MongoDatabase database = mongoClient.getDatabase("mydb");
        MongoCollection<Document> collection = database.getCollection("users");

        // Create a new document
        Document user = new Document("name", "John Doe")
                .append("age", 30)
                .append("city", "New York");

        // Insert the document into the collection
        collection.insertOne(user);

        System.out.println("Document inserted successfully");
        mongoClient.close();
    }
}
```

#### **Read Document**:

```java
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoCursor;
import org.bson.Document;

public class MongoDBFind {
    public static void main(String[] args) {
        MongoClient mongoClient = new MongoClient("localhost", 27017);
        MongoDatabase database = mongoClient.getDatabase("mydb");
        MongoCollection<Document> collection = database.getCollection("users");

        // Find all documents in the collection
        MongoCursor<Document> cursor = collection.find().iterator();

        while (cursor.hasNext()) {
            System.out.println(cursor.next().toJson());
        }

        mongoClient.close();
    }
}
```

#### **Update Document**:

```java
import com.mongodb.client.MongoCollection;
import org.bson.Document;
import com.mongodb.client.model.Filters;
import com.mongodb.client.model.Updates;

public class MongoDBUpdate {
    public static void main(String[] args) {
        MongoClient mongoClient = new MongoClient("localhost", 27017);
        MongoDatabase database = mongoClient.getDatabase("mydb");
        MongoCollection<Document> collection = database.getCollection("users");

        // Update a document where name is 'John Doe'
        collection.updateOne(Filters.eq("name", "John Doe"),
                Updates.set("age", 31));

        System.out.println("Document updated successfully");
        mongoClient.close();
    }
}
```

#### **Delete Document**:

```java
import com.mongodb.client.MongoCollection;
import com.mongodb.client.model.Filters;
import org.bson.Document;

public class MongoDBDelete {
    public static void main(String[] args) {
        MongoClient mongoClient = new MongoClient("localhost", 27017);
        MongoDatabase database = mongoClient.getDatabase("mydb");
        MongoCollection<Document> collection = database.getCollection("users");

        // Delete document where name is 'John Doe'
        collection.deleteOne(Filters.eq("name", "John Doe"));

        System.out.println("Document deleted successfully");
        mongoClient.close();
    }
}
```

---

### **4. MongoDB Aggregation Example**

MongoDB provides powerful aggregation features, which can be used to process and analyze data.

```java
import com.mongodb.client.AggregateIterable;
import com.mongodb.client.MongoCollection;
import org.bson.Document;
import java.util.Arrays;

public class MongoDBAggregation {
    public static void main(String[] args) {
        MongoClient mongoClient = new MongoClient("localhost", 27017);
        MongoDatabase database = mongoClient.getDatabase("mydb");
        MongoCollection<Document> collection = database.getCollection("users");

        // Aggregation pipeline to group by city and count users
        AggregateIterable<Document> result = collection.aggregate(Arrays.asList(
                new Document("$group", new Document("_id", "$city")
                        .append("userCount", new Document("$sum", 1)))
        ));

        for (Document doc : result) {
            System.out.println(doc.toJson());
        }

        mongoClient.close();
    }
}
```

This example uses an aggregation pipeline to group users by their `city` field and count how many users are in each city.

---

### **5. MongoDB Transactions in Java**

MongoDB supports multi-document ACID transactions. To use transactions in MongoDB with Java, ensure you are using a replica set or sharded cluster.

#### **Transaction Example**:

```java
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import com.mongodb.client.ClientSession;
import org.bson.Document;
import com.mongodb.MongoException;

public class MongoDBTransaction {
    public static void main(String[] args) {
        MongoClient mongoClient = new MongoClient("localhost", 27017);
        MongoDatabase database = mongoClient.getDatabase("mydb");

        // Start a session for the transaction
        ClientSession session = mongoClient.startSession();

        try {
            session.startTransaction();

            MongoCollection<Document> collection = database.getCollection("users");

            // Perform some write operations inside the transaction
            collection.insertOne(session, new Document("name", "Alice").append("age", 25));
            collection.updateOne(session, new Document("name", "Alice"),
                    new Document("$set", new Document("age", 26)));

            // Commit the transaction
            session.commitTransaction();
            System.out.println("Transaction committed successfully");
        } catch (MongoException e) {
            session.abortTransaction();
            System.out.println("Transaction aborted");
        } finally {
            session.close();
            mongoClient.close();
        }
    }
}
```

---

### **6. MongoDB Java Driver for Async Operations**

MongoDB Java also provides an **asynchronous** driver, which is useful for high-performance applications. The **MongoDB Reactive Streams Java Driver** uses the **Reactor** and **RxJava** libraries to handle asynchronous data operations.

To use the asynchronous driver, you would use the following dependencies (for **Reactive Streams**):

```xml
<dependency>
    <groupId>org.mongodb</groupId>
    <artifactId>mongo-reactive-streams-driver</artifactId>
    <version>4.9.0</version> <!-- Use the latest version -->
</dependency>
```

The usage for asynchronous operations is quite different and leverages reactive programming paradigms.

---

### **Conclusion**

Integrating MongoDB with Java is straightforward, thanks to the official MongoDB Java Driver. By following the steps above, you can easily perform CRUD operations, work with aggregation pipelines, manage transactions, and set up asynchronous operations. Whether you're building small applications or large-scale systems, MongoDB’s Java driver provides the flexibility and features you need to interact with your database effectively.
