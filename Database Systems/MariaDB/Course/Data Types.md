### MariaDB - Data Types

MariaDB supports a wide range of data types to store different kinds of data. These types can be broadly categorized into several categories:

1. **Numeric Data Types**
2. **Date and Time Data Types**
3. **String (Character) Data Types**
4. **Binary Data Types**
5. **JSON Data Type**

Each data type is optimized for specific kinds of data, and selecting the appropriate data type is important for both performance and storage efficiency.

---

### 1. **Numeric Data Types**

These data types are used for storing numbers. MariaDB supports both integer and floating-point types.

#### 1.1. **Integer Types**
- **TINYINT**: A very small integer. Storage: 1 byte.
  - Range: `-128` to `127` (signed) or `0` to `255` (unsigned).
- **SMALLINT**: A small integer. Storage: 2 bytes.
  - Range: `-32,768` to `32,767` (signed) or `0` to `65,535` (unsigned).
- **MEDIUMINT**: A medium-sized integer. Storage: 3 bytes.
  - Range: `-8,388,608` to `8,388,607` (signed) or `0` to `16,777,215` (unsigned).
- **INT** (or **INTEGER**): A standard integer. Storage: 4 bytes.
  - Range: `-2,147,483,648` to `2,147,483,647` (signed) or `0` to `4,294,967,295` (unsigned).
- **BIGINT**: A large integer. Storage: 8 bytes.
  - Range: `-9,223,372,036,854,775,808` to `9,223,372,036,854,775,807` (signed) or `0` to `18,446,744,073,709,551,615` (unsigned).

#### 1.2. **Floating-Point Types**
- **FLOAT**: A single-precision floating point number. Storage: 4 bytes.
  - Range: `-3.402823466E+38` to `3.402823466E+38`.
- **DOUBLE** (or **REAL**): A double-precision floating point number. Storage: 8 bytes.
  - Range: `-1.7976931348623157E+308` to `1.7976931348623157E+308`.
- **DECIMAL** (or **NUMERIC**): A fixed-point number. Storage: Varies based on the precision and scale.
  - Example: `DECIMAL(10,2)` can store numbers up to 10 digits, with 2 digits after the decimal point.

---

### 2. **Date and Time Data Types**

These data types are used for storing date and time-related information.

- **DATE**: A date in the format `YYYY-MM-DD`. Storage: 3 bytes.
  - Example: `'2024-12-16'`.
- **DATETIME**: A combination of date and time in the format `YYYY-MM-DD HH:MM:SS`. Storage: 8 bytes.
  - Example: `'2024-12-16 12:30:00'`.
- **TIMESTAMP**: A timestamp that records the date and time, stored as the number of seconds since `1970-01-01 00:00:00 UTC`. Storage: 4 bytes.
  - Example: `'2024-12-16 12:30:00'`.
- **TIME**: A time in the format `HH:MM:SS`. Storage: 3 bytes.
  - Example: `'12:30:00'`.
- **YEAR**: A 4-digit year. Storage: 1 byte.
  - Example: `2024`.

---

### 3. **String (Character) Data Types**

These data types are used for storing text and string data.

#### 3.1. **Fixed-Length Strings**
- **CHAR(n)**: A fixed-length string with a length of `n`. Storage: `n` bytes.
  - Example: `CHAR(10)` will store a string of exactly 10 characters. If the string is shorter than 10 characters, the remaining space is padded with spaces.

#### 3.2. **Variable-Length Strings**
- **VARCHAR(n)**: A variable-length string with a maximum length of `n`. Storage: 1 or 2 bytes + actual string length.
  - Example: `VARCHAR(255)` can store strings up to 255 characters in length.
- **TEXT**: A string of variable length. Storage: 2 bytes + actual string length.
  - Maximum length: `65,535` characters.
  - Example: `TEXT` is suitable for storing large amounts of text, such as articles or descriptions.
  
#### 3.3. **Other String Types**
- **TINYTEXT**: A smaller version of the `TEXT` type. Storage: 1 byte + actual string length.
  - Maximum length: `255` characters.
- **MEDIUMTEXT**: A medium-sized string. Storage: 3 bytes + actual string length.
  - Maximum length: `16,777,215` characters.
- **LONGTEXT**: A very large string. Storage: 4 bytes + actual string length.
  - Maximum length: `4,294,967,295` characters.

#### 3.4. **Binary Strings**
- **BINARY(n)**: A fixed-length binary string. Storage: `n` bytes.
  - Example: `BINARY(10)` stores 10 bytes of binary data.
- **VARBINARY(n)**: A variable-length binary string. Storage: 1 or 2 bytes + actual length.
  - Example: `VARBINARY(255)` stores binary data up to 255 bytes.
- **BLOB**: A binary large object. Storage: 2 bytes + actual binary length.
  - Example: `BLOB` is used for storing large binary data such as images or files.
  - Maximum length: `65,535` bytes.
- **TINYBLOB**: A smaller binary large object. Storage: 1 byte + actual binary length.
  - Maximum length: `255` bytes.
- **MEDIUMBLOB**: A medium-sized binary large object. Storage: 3 bytes + actual binary length.
  - Maximum length: `16,777,215` bytes.
- **LONGBLOB**: A very large binary object. Storage: 4 bytes + actual binary length.
  - Maximum length: `4,294,967,295` bytes.

---

### 4. **JSON Data Type**

MariaDB supports a native **JSON** data type to store JSON-formatted data.

- **JSON**: A data type used to store JSON documents. Storage: Varies based on the content.
  - Example: `{"name": "John", "age": 30, "city": "New York"}`.

---

### 5. **Spatial Data Types**

MariaDB also supports spatial data types for geographic information systems (GIS).

- **POINT**: Represents a single point in space (2D coordinates).
- **LINESTRING**: Represents a sequence of points forming a line.
- **POLYGON**: Represents a polygon defined by multiple points.
- **GEOMETRY**: A generic spatial type that can represent various geometric shapes.

---

### 6. **ENUM and SET Data Types**

- **ENUM**: A string object with a predefined list of values. Only one value from the list can be chosen.
  - Example: `ENUM('small', 'medium', 'large')` stores a value that is either 'small', 'medium', or 'large'.
- **SET**: A string object that can store multiple values from a predefined list.
  - Example: `SET('a', 'b', 'c')` can store one or more of the values 'a', 'b', or 'c'.

---

### 7. **Other Data Types**

- **BOOLEAN**: A type that represents true/false values. Internally, it's stored as `TINYINT(1)`.
  - Example: `BOOLEAN` can store `TRUE` or `FALSE`.
- **AUTO_INCREMENT**: Used to automatically generate a unique number for a column, often used for primary keys. This is not a data type by itself but a property of a column.

---

### Summary Table

| Category               | Data Type(s)                                         | Description                                      |
|------------------------|------------------------------------------------------|--------------------------------------------------|
| **Numeric**            | `TINYINT`, `SMALLINT`, `INT`, `BIGINT`, `FLOAT`, `DOUBLE`, `DECIMAL` | Integer and floating-point numbers.             |
| **Date & Time**        | `DATE`, `DATETIME`, `TIMESTAMP`, `TIME`, `YEAR`      | Date and time-related values.                    |
| **String**             | `CHAR`, `VARCHAR`, `TEXT`, `TINYTEXT`, `MEDIUMTEXT`, `LONGTEXT`, `BINARY`, `VARBINARY`, `BLOB` | Textual and binary data.                        |
| **JSON**               | `JSON`                                               | Stores JSON data.                               |
| **Spatial**            | `POINT`, `LINESTRING`, `POLYGON`, `GEOMETRY`         | Geospatial data types.                          |
| **Other**              | `ENUM`, `SET`, `BOOLEAN`, `AUTO_INCREMENT`           | Special types like enumerated, sets, and booleans. |

---

### Conclusion

MariaDB offers a variety of data types to support different kinds of data storage needs, from numeric values to large text or binary data. When creating tables and structuring databases, it's important to select the most appropriate data type for each column based on the kind of

 data it will store. Proper use of data types ensures better performance, efficient storage, and easier data manipulation.
