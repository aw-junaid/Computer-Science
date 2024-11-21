### **MongoDB - Create Database**

In MongoDB, you don't need to explicitly create a database using a command like in relational databases. A database is created when you first store data in it. Here’s a step-by-step guide to creating and using a database in MongoDB:

---

### **Step 1: Connect to MongoDB**

First, you need to connect to the MongoDB instance using the **Mongo shell**. Open a terminal and type:

```bash
mongosh
```

This will start the MongoDB shell, and you'll be connected to the default database (`test`).

### **Step 2: Switch to or Create a New Database**

To create a new database, use the `use` command. If the database doesn't exist, MongoDB will create it when you insert data into it. To switch to or create a new database, run the following command:

```bash
use myNewDatabase
```

This command switches to a database named `myNewDatabase`. If this database doesn't already exist, MongoDB will create it once you insert data into it.

### **Step 3: Create a Collection and Insert Data**

Since MongoDB creates the database only when data is inserted, you need to add some data to a collection in order to officially create the database.

For example, let's create a collection called `users` and insert a document into it:

```javascript
db.users.insertOne({ name: "John Doe", age: 30, email: "johndoe@example.com" })
```

After running this command, MongoDB will automatically create the database (`myNewDatabase`) and the `users` collection within it. You can verify that the database was created by running:

```javascript
show databases
```

This will display all databases, including `myNewDatabase`, which is now created because it contains the `users` collection.

### **Step 4: Verify the Database**

You can verify that you are working with the new database by checking the name of the current database:

```javascript
db
```

This will return the name of the currently selected database, which should be `myNewDatabase` if you switched to it earlier.

### **Step 5: Listing All Databases**

To see all the databases in your MongoDB instance, run the following command:

```javascript
show databases
```

This will list all the databases, including the one you just created, `myNewDatabase`.

---

### **Step 6: Drop the Database (Optional)**

If you want to delete the database, use the `dropDatabase()` method:

```javascript
use myNewDatabase
db.dropDatabase()
```

This will permanently remove the `myNewDatabase` along with all of its collections.

---

### **Example Workflow**

Here’s the full workflow to create a new database, insert a document, and verify it:

1. Start Mongo shell:

   ```bash
   mongosh
   ```

2. Switch to the new database:

   ```javascript
   use myNewDatabase
   ```

3. Insert a document into a collection:

   ```javascript
   db.users.insertOne({ name: "John Doe", age: 30, email: "johndoe@example.com" })
   ```

4. List all databases to confirm the new database is created:

   ```javascript
   show databases
   ```

5. If you want to delete the database:

   ```javascript
   db.dropDatabase()
   ```

---

### **Conclusion**

In MongoDB, databases are created implicitly when you insert data into them. Simply use the `use` command to switch to a database, and MongoDB will create it automatically once you add a collection and data. There's no explicit command to create a database, and it’s only "created" when there’s data in it.
