### **MongoDB - PHP**

MongoDB can be easily integrated with PHP applications using the official MongoDB PHP driver. The driver allows you to interact with MongoDB databases, perform CRUD operations, and use advanced features like aggregation, indexing, and transactions.

Below is a guide on how to get started with MongoDB in PHP:

---

### **1. Installing MongoDB PHP Driver**

Before you can start working with MongoDB in PHP, you need to install the MongoDB PHP driver. There are two primary methods for installing the driver: using **PECL** (PHP Extension and Application Repository) or **Composer** (PHP's dependency manager).

#### **Using PECL** (Preferred for Ubuntu/Linux):

1. First, make sure you have the necessary dependencies installed:

```bash
sudo apt-get install php-pear php-dev libmongoc-1.0-0
```

2. Install the MongoDB extension via PECL:

```bash
sudo pecl install mongodb
```

3. Add the extension to your PHP configuration file (`php.ini`):

```bash
echo "extension=mongodb.so" | sudo tee -a /etc/php/7.x/cli/php.ini
echo "extension=mongodb.so" | sudo tee -a /etc/php/7.x/apache2/php.ini
```

4. Restart the Apache server (if you're using Apache):

```bash
sudo service apache2 restart
```

#### **Using Composer** (Preferred for managing dependencies in PHP projects):

1. Install the MongoDB package using Composer:

```bash
composer require mongodb/mongodb
```

2. Composer will automatically download and install the necessary MongoDB PHP driver along with its dependencies.

---

### **2. Connecting to MongoDB in PHP**

Once the MongoDB driver is installed, you can connect to your MongoDB server. Below is a simple example of how to connect to MongoDB using PHP.

#### **Connecting to MongoDB:**

```php
<?php
require 'vendor/autoload.php'; // Include Composer's autoloader

$client = new MongoDB\Client("mongodb://localhost:27017"); // Connect to local MongoDB server

// Select database and collection
$database = $client->mydb;
$collection = $database->users;

echo "Connected to MongoDB successfully!";
?>
```

- Here, `MongoDB\Client` is the main entry point to interact with the MongoDB server.
- `"mongodb://localhost:27017"` is the default connection URI for a MongoDB instance running locally.

---

### **3. CRUD Operations in MongoDB Using PHP**

Now that you have connected to MongoDB, you can perform **Create**, **Read**, **Update**, and **Delete** operations on MongoDB collections.

#### **Create (Insert) a Document:**

```php
<?php
require 'vendor/autoload.php';

$client = new MongoDB\Client("mongodb://localhost:27017");
$database = $client->mydb;
$collection = $database->users;

// Insert a new document into the collection
$result = $collection->insertOne([
    'name' => 'John Doe',
    'age' => 30,
    'city' => 'New York'
]);

echo "Inserted document with ID: " . $result->getInsertedId();
?>
```

#### **Read (Find) Documents:**

```php
<?php
require 'vendor/autoload.php';

$client = new MongoDB\Client("mongodb://localhost:27017");
$database = $client->mydb;
$collection = $database->users;

// Find one document
$user = $collection->findOne(['name' => 'John Doe']);
echo "Name: " . $user['name'] . ", Age: " . $user['age'] . ", City: " . $user['city'];

// Find all documents
$cursor = $collection->find(); 
foreach ($cursor as $document) {
    echo $document['name'] . "\n";
}
?>
```

#### **Update a Document:**

```php
<?php
require 'vendor/autoload.php';

$client = new MongoDB\Client("mongodb://localhost:27017");
$database = $client->mydb;
$collection = $database->users;

// Update a document
$updateResult = $collection->updateOne(
    ['name' => 'John Doe'],  // Filter
    ['$set' => ['age' => 31]] // Update
);

echo "Matched " . $updateResult->getMatchedCount() . " document(s)\n";
echo "Modified " . $updateResult->getModifiedCount() . " document(s)\n";
?>
```

#### **Delete a Document:**

```php
<?php
require 'vendor/autoload.php';

$client = new MongoDB\Client("mongodb://localhost:27017");
$database = $client->mydb;
$collection = $database->users;

// Delete a document
$deleteResult = $collection->deleteOne(['name' => 'John Doe']);

echo "Deleted " . $deleteResult->getDeletedCount() . " document(s)\n";
?>
```

---

### **4. Aggregation Example**

MongoDB's aggregation framework allows you to process data in sophisticated ways. You can use the `aggregate()` method in PHP to run aggregation pipelines.

#### **Aggregation Example:**

```php
<?php
require 'vendor/autoload.php';

$client = new MongoDB\Client("mongodb://localhost:27017");
$database = $client->mydb;
$collection = $database->users;

// Aggregation pipeline to group by city and count users
$pipeline = [
    ['$group' => ['_id' => '$city', 'userCount' => ['$sum' => 1]]]
];

$cursor = $collection->aggregate($pipeline);

foreach ($cursor as $document) {
    echo "City: " . $document['_id'] . ", User Count: " . $document['userCount'] . "\n";
}
?>
```

In this example, the aggregation groups documents by `city` and counts the number of users in each city.

---

### **5. Working with Indexes**

Indexes in MongoDB are essential for optimizing query performance. You can create and manage indexes using the MongoDB PHP driver.

#### **Creating an Index:**

```php
<?php
require 'vendor/autoload.php';

$client = new MongoDB\Client("mongodb://localhost:27017");
$database = $client->mydb;
$collection = $database->users;

// Create an index on the 'name' field
$result = $collection->createIndex(['name' => 1]);

echo "Index created: " . $result . "\n";
?>
```

In this example, the index is created on the `name` field in ascending order (denoted by `1`).

#### **List Indexes:**

```php
<?php
require 'vendor/autoload.php';

$client = new MongoDB\Client("mongodb://localhost:27017");
$database = $client->mydb;
$collection = $database->users;

// List all indexes in the collection
$indexes = $collection->listIndexes();
foreach ($indexes as $index) {
    print_r($index);
}
?>
```

---

### **6. Transactions in MongoDB (PHP)**

Starting from MongoDB 4.0, multi-document ACID transactions are supported. In PHP, you can use transactions with replica sets.

#### **Transaction Example:**

```php
<?php
require 'vendor/autoload.php';

$client = new MongoDB\Client("mongodb://localhost:27017");
$database = $client->mydb;

$session = $client->startSession();

try {
    // Start a transaction
    $session->startTransaction();

    $collection = $database->users;

    // Perform multiple operations inside the transaction
    $collection->insertOne(['name' => 'Alice', 'age' => 25], ['session' => $session]);
    $collection->updateOne(['name' => 'Alice'], ['$set' => ['age' => 26]], ['session' => $session]);

    // Commit the transaction
    $session->commitTransaction();
    echo "Transaction committed successfully!";
} catch (Exception $e) {
    // Abort the transaction in case of an error
    $session->abortTransaction();
    echo "Transaction aborted: " . $e->getMessage();
} finally {
    $session->endSession();
}
?>
```

In this example:
- We start a transaction using `$session->startTransaction()`.
- We perform the `insertOne()` and `updateOne()` operations.
- If all operations are successful, we commit the transaction using `$session->commitTransaction()`.
- If an error occurs, we abort the transaction using `$session->abortTransaction()`.

---

### **Conclusion**

Integrating MongoDB with PHP is simple using the official MongoDB PHP driver. Once the driver is set up, you can easily perform CRUD operations, use advanced features like aggregation and indexing, and manage transactions. Whether you are building a small application or a complex, data-heavy web application, MongoDB's flexible document-based model can easily fit into your PHP-based projects.
