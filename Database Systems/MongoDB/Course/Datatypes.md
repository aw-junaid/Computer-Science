### **MongoDB - Datatypes**

MongoDB stores data in a flexible, schema-less format using documents (which are similar to JSON objects). The values within documents can be of various data types. Below are the key data types supported by MongoDB.

---

### **1. String**

- **Description**: Used to store text data.
- **Syntax**: Enclosed in double quotes (`""`).
- **Example**:
  
  ```json
  { "name": "John Doe" }
  ```

### **2. Integer**

- **Description**: Represents numerical values.
- **Syntax**: Stored as 32-bit or 64-bit integers depending on the size.
- **Example**:
  
  ```json
  { "age": 30 }
  ```

- **Note**: MongoDB supports both 32-bit and 64-bit integers depending on the system. For large integer values, you can use the `NumberLong` type for 64-bit integers.

  ```json
  { "bigNumber": NumberLong(1234567890123456789) }
  ```

### **3. Double**

- **Description**: Represents floating-point numbers.
- **Syntax**: For storing decimal numbers.
- **Example**:
  
  ```json
  { "price": 99.99 }
  ```

### **4. Boolean**

- **Description**: Represents true or false values.
- **Syntax**: `true` or `false`.
- **Example**:

  ```json
  { "isActive": true }
  ```

### **5. Null**

- **Description**: Represents the absence of a value.
- **Syntax**: `null`.
- **Example**:

  ```json
  { "email": null }
  ```

### **6. Array**

- **Description**: Represents an ordered list of values.
- **Syntax**: Values enclosed in square brackets (`[]`).
- **Example**:

  ```json
  { "tags": ["mongodb", "database", "NoSQL"] }
  ```

### **7. Object (Embedded Document)**

- **Description**: Used for nested documents or subdocuments within a document. An embedded document is essentially a JSON object within another JSON object.
- **Syntax**: Enclosed in curly braces (`{}`).
- **Example**:

  ```json
  { 
    "address": { 
      "street": "123 Main St", 
      "city": "Springfield" 
    }
  }
  ```

### **8. Date**

- **Description**: Represents dates and times.
- **Syntax**: Stored in the `ISODate` format. MongoDB stores dates as 64-bit integers representing milliseconds since the Unix epoch (1970-01-01).
- **Example**:

  ```json
  { "createdAt": ISODate("2024-11-11T10:30:00Z") }
  ```

  You can also use `new Date()` in JavaScript.

  ```json
  { "updatedAt": new Date() }
  ```

### **9. ObjectId**

- **Description**: A special 12-byte identifier used to uniquely identify documents within a collection. MongoDB automatically generates an `_id` field with an `ObjectId` for every document, unless specified otherwise.
- **Syntax**: ObjectId is created by MongoDB or manually specified.
- **Example**:

  ```json
  { "_id": ObjectId("507f191e810c19729de860ea") }
  ```

### **10. Binary Data (BinData)**

- **Description**: Used to store binary data, such as images, files, or any other non-textual data.
- **Syntax**: Stored as binary data in MongoDB, using the `BinData` type.
- **Example**:

  ```json
  { "fileData": BinData(0, "somebinarydata") }
  ```

### **11. Regular Expression (Regex)**

- **Description**: Used to store regular expressions for pattern matching.
- **Syntax**: Regular expressions are represented using `/pattern/` syntax.
- **Example**:

  ```json
  { "username": { "$regex": "^john" } }
  ```

### **12. JavaScript**

- **Description**: Used to store JavaScript code.
- **Syntax**: Stored as a `JavaScript` object or function.
- **Example**:

  ```json
  { "func": new DBPointer("myFunction") }
  ```

### **13. DBRef**

- **Description**: A special reference to another document in another collection, useful for creating references between documents across collections.
- **Syntax**: `{ "$ref": "<collection>", "$id": <ObjectId>, "$db": "<database>" }`
- **Example**:

  ```json
  { 
    "$ref": "users", 
    "$id": ObjectId("507f191e810c19729de860ea"),
    "$db": "mydatabase"
  }
  ```

### **14. MinKey and MaxKey**

- **Description**: Special types used for sorting in MongoDB. 
  - **MinKey** is less than all other BSON types.
  - **MaxKey** is greater than all other BSON types.
- **Example**:

  ```json
  { "minKeyField": MinKey }
  ```

---

### **Summary of MongoDB Datatypes**

| Data Type       | Example/Use Case                                    |
|-----------------|------------------------------------------------------|
| **String**      | `"name": "Alice"`                                    |
| **Integer**     | `"age": 30`                                          |
| **Double**      | `"price": 19.99`                                     |
| **Boolean**     | `"isActive": true`                                   |
| **Null**        | `"email": null`                                      |
| **Array**       | `"tags": ["db", "mongodb", "noSQL"]`                 |
| **Object**      | `"address": { "city": "NYC", "zip": 10001 }`         |
| **Date**        | `"createdAt": ISODate("2024-11-11T10:30:00Z")`       |
| **ObjectId**    | `"userId": ObjectId("507f191e810c19729de860ea")`     |
| **Binary Data** | `"fileData": BinData(0, "binarydata")`               |
| **Regex**       | `"username": { "$regex": "^john" }`                  |
| **JavaScript**  | `"func": new Function("return true;")`                |
| **DBRef**       | `{ "$ref": "users", "$id": ObjectId("...") }`        |
| **MinKey**      | `{ "key": MinKey }`                                  |
| **MaxKey**      | `{ "key": MaxKey }`                                  |

---

### **Conclusion**

MongoDB supports a variety of data types, from simple strings and integers to more complex types like embedded documents, arrays, binary data, and even JavaScript code. By utilizing these data types, you can design flexible, powerful data models that meet the needs of your application. Understanding the different data types will help you store and query data more effectively in MongoDB.
