### **MongoDB - Drop Database**

In MongoDB, you can **drop a database** to permanently delete it along with all its collections and data. This operation cannot be undone, so it’s important to be sure you want to remove the database before proceeding.

Here’s a step-by-step guide on how to drop a database in MongoDB.

---

### **Step 1: Connect to MongoDB**

Open your terminal and connect to your MongoDB instance using the **Mongo shell** by typing:

```bash
mongosh
```

This will connect you to the default `test` database. You can switch to the database you want to drop.

### **Step 2: Switch to the Database You Want to Drop**

Use the `use` command to switch to the database you want to drop. For example, if you want to drop a database called `myNewDatabase`, run:

```javascript
use myNewDatabase
```

### **Step 3: Drop the Database**

To drop the database, use the `dropDatabase()` method. This will delete the entire database, including all collections and documents within it.

```javascript
db.dropDatabase()
```

This command will remove the `myNewDatabase` along with all of its data. MongoDB will return a confirmation message like:

```javascript
{ "dropped" : "myNewDatabase", "ok" : 1 }
```

This confirms that the database has been successfully dropped.

### **Step 4: Verify the Database is Dropped**

To check that the database has been deleted, list all databases:

```javascript
show databases
```

The dropped database (`myNewDatabase`) should no longer appear in the list.

### **Important Notes**

- **Permanent Action**: Dropping a database is permanent. All collections and documents in the database will be lost, so be careful before executing this operation.
- **No Undo**: There is no "undo" for dropping a database in MongoDB. Once dropped, the data cannot be recovered unless you have a backup.
- **Only the Current Database**: The `dropDatabase()` method only affects the currently selected database. Be sure you are in the correct database before dropping it.

### **Example Workflow**

Here’s a complete example of how to drop a MongoDB database:

1. **Start Mongo shell**:

   ```bash
   mongosh
   ```

2. **Switch to the database you want to drop**:

   ```javascript
   use myNewDatabase
   ```

3. **Drop the database**:

   ```javascript
   db.dropDatabase()
   ```

4. **Verify the database is gone**:

   ```javascript
   show databases
   ```

---

### **Conclusion**

Dropping a database in MongoDB is straightforward using the `dropDatabase()` method. Just ensure that you're in the right database before running the command, as the action is irreversible.
