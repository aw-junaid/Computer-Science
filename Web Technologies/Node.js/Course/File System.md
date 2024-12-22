### **Node.js - File System (fs)**

Node.js provides a module called **`fs`** (File System) that allows you to interact with the file system on your computer. Using this module, you can perform operations like reading, writing, updating, and deleting files or directories. The `fs` module supports both **synchronous** and **asynchronous** methods for handling file operations, enabling developers to choose between ease of use (with synchronous) and performance (with asynchronous).

---

### **File System Methods in Node.js**

Node.js provides several methods in the `fs` module to perform various file system operations. These can be divided into synchronous and asynchronous versions.

#### **1. Reading Files**

- **`fs.readFile()`** (Asynchronous)

Reads the contents of a file asynchronously. Once the file is read, it triggers a callback function.

```javascript
const fs = require('fs');

fs.readFile('example.txt', 'utf8', (err, data) => {
  if (err) {
    console.log('Error reading file:', err);
  } else {
    console.log('File content:', data);
  }
});
```

- **`fs.readFileSync()`** (Synchronous)

Reads the contents of a file synchronously. It blocks the event loop until the file is completely read.

```javascript
const fs = require('fs');

try {
  const data = fs.readFileSync('example.txt', 'utf8');
  console.log('File content:', data);
} catch (err) {
  console.log('Error reading file:', err);
}
```

#### **2. Writing Files**

- **`fs.writeFile()`** (Asynchronous)

Writes data to a file asynchronously. If the file does not exist, it is created; if it exists, it is overwritten.

```javascript
const fs = require('fs');

fs.writeFile('output.txt', 'Hello, Node.js!', 'utf8', (err) => {
  if (err) {
    console.log('Error writing file:', err);
  } else {
    console.log('File written successfully!');
  }
});
```

- **`fs.writeFileSync()`** (Synchronous)

Writes data to a file synchronously. Similar to `fs.writeFile()`, it overwrites the file if it exists or creates a new one if it doesn’t.

```javascript
const fs = require('fs');

try {
  fs.writeFileSync('output.txt', 'Hello, Node.js!', 'utf8');
  console.log('File written successfully!');
} catch (err) {
  console.log('Error writing file:', err);
}
```

#### **3. Appending Data to Files**

- **`fs.appendFile()`** (Asynchronous)

Appends data to a file asynchronously. If the file doesn't exist, it will be created.

```javascript
const fs = require('fs');

fs.appendFile('output.txt', 'Appended data!', 'utf8', (err) => {
  if (err) {
    console.log('Error appending data:', err);
  } else {
    console.log('Data appended successfully!');
  }
});
```

- **`fs.appendFileSync()`** (Synchronous)

Appends data to a file synchronously. If the file doesn't exist, it will be created.

```javascript
const fs = require('fs');

try {
  fs.appendFileSync('output.txt', 'Appended data!', 'utf8');
  console.log('Data appended successfully!');
} catch (err) {
  console.log('Error appending data:', err);
}
```

#### **4. Deleting Files**

- **`fs.unlink()`** (Asynchronous)

Deletes a file asynchronously.

```javascript
const fs = require('fs');

fs.unlink('output.txt', (err) => {
  if (err) {
    console.log('Error deleting file:', err);
  } else {
    console.log('File deleted successfully!');
  }
});
```

- **`fs.unlinkSync()`** (Synchronous)

Deletes a file synchronously.

```javascript
const fs = require('fs');

try {
  fs.unlinkSync('output.txt');
  console.log('File deleted successfully!');
} catch (err) {
  console.log('Error deleting file:', err);
}
```

#### **5. Renaming Files**

- **`fs.rename()`** (Asynchronous)

Renames a file or directory asynchronously.

```javascript
const fs = require('fs');

fs.rename('oldname.txt', 'newname.txt', (err) => {
  if (err) {
    console.log('Error renaming file:', err);
  } else {
    console.log('File renamed successfully!');
  }
});
```

- **`fs.renameSync()`** (Synchronous)

Renames a file or directory synchronously.

```javascript
const fs = require('fs');

try {
  fs.renameSync('oldname.txt', 'newname.txt');
  console.log('File renamed successfully!');
} catch (err) {
  console.log('Error renaming file:', err);
}
```

#### **6. File Information**

- **`fs.stat()`** (Asynchronous)

Retrieves information about a file asynchronously (e.g., size, creation date).

```javascript
const fs = require('fs');

fs.stat('example.txt', (err, stats) => {
  if (err) {
    console.log('Error retrieving file stats:', err);
  } else {
    console.log('File Stats:', stats);
    console.log('Is file:', stats.isFile());
    console.log('File size:', stats.size, 'bytes');
  }
});
```

- **`fs.statSync()`** (Synchronous)

Retrieves information about a file synchronously.

```javascript
const fs = require('fs');

try {
  const stats = fs.statSync('example.txt');
  console.log('File Stats:', stats);
  console.log('Is file:', stats.isFile());
  console.log('File size:', stats.size, 'bytes');
} catch (err) {
  console.log('Error retrieving file stats:', err);
}
```

---

### **Working with Directories**

#### **1. Creating Directories**

- **`fs.mkdir()`** (Asynchronous)

Creates a new directory asynchronously.

```javascript
const fs = require('fs');

fs.mkdir('newDirectory', (err) => {
  if (err) {
    console.log('Error creating directory:', err);
  } else {
    console.log('Directory created successfully!');
  }
});
```

- **`fs.mkdirSync()`** (Synchronous)

Creates a new directory synchronously.

```javascript
const fs = require('fs');

try {
  fs.mkdirSync('newDirectory');
  console.log('Directory created successfully!');
} catch (err) {
  console.log('Error creating directory:', err);
}
```

#### **2. Reading Directories**

- **`fs.readdir()`** (Asynchronous)

Reads the contents of a directory asynchronously, returning an array of filenames.

```javascript
const fs = require('fs');

fs.readdir('someDirectory', (err, files) => {
  if (err) {
    console.log('Error reading directory:', err);
  } else {
    console.log('Directory contents:', files);
  }
});
```

- **`fs.readdirSync()`** (Synchronous)

Reads the contents of a directory synchronously, returning an array of filenames.

```javascript
const fs = require('fs');

try {
  const files = fs.readdirSync('someDirectory');
  console.log('Directory contents:', files);
} catch (err) {
  console.log('Error reading directory:', err);
}
```

#### **3. Deleting Directories**

- **`fs.rmdir()`** (Asynchronous)

Deletes an empty directory asynchronously.

```javascript
const fs = require('fs');

fs.rmdir('emptyDirectory', (err) => {
  if (err) {
    console.log('Error deleting directory:', err);
  } else {
    console.log('Directory deleted successfully!');
  }
});
```

- **`fs.rmdirSync()`** (Synchronous)

Deletes an empty directory synchronously.

```javascript
const fs = require('fs');

try {
  fs.rmdirSync('emptyDirectory');
  console.log('Directory deleted successfully!');
} catch (err) {
  console.log('Error deleting directory:', err);
}
```

---

### **File System Streams**

In addition to basic file operations, Node.js also supports **streams** for file handling, which is especially useful for large files or real-time processing. For example:

- **`fs.createReadStream()`**: Used to read a file as a stream.

```javascript
const fs = require('fs');
const readableStream = fs.createReadStream('largeFile.txt', 'utf8');

readableStream.on('data', (chunk) => {
  console.log('Chunk received:', chunk);
});
```

- **`fs.createWriteStream()`**: Used to write to a file as a stream.

```javascript
const fs = require('fs');
const writableStream = fs.createWriteStream('output.txt');

writableStream.write('Hello, Node.js!\n');
writableStream.end();
```

---

### **Conclusion**

The **`fs`** module in Node.js is essential for interacting with the file system, allowing you to perform a variety of operations such as reading, writing, appending, deleting files, and managing directories. With both synchronous and asynchronous methods, you can choose the best approach for your application's performance needs. Additionally, streams allow you to handle large files and real-time data efficiently, making the `fs` module a versatile tool for many use cases in Node.js.
