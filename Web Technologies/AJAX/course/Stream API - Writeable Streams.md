### **Stream API - Writable Streams**

**Writable Streams** are another fundamental part of the **Stream API** in JavaScript. While **Readable Streams** allow you to consume data incrementally, **Writable Streams** allow you to send or write data incrementally to a destination, such as a file, network socket, or another process.

Writable streams are particularly useful when you need to send large amounts of data in chunks, without needing to load the entire dataset into memory. This makes it more memory-efficient, especially for operations like file uploads, streaming media, or real-time data transmission.

### **Key Characteristics of Writable Streams**
- **Data is written incrementally**: Instead of sending all the data at once, you can write data to the stream in smaller chunks.
- **Can be consumed asynchronously**: You can write data asynchronously and non-blocking, allowing the application to remain responsive while data is being written.
- **Can handle backpressure**: If the consumer (e.g., a server or file system) cannot keep up with the producer (e.g., data being uploaded), writable streams can manage backpressure and pause the flow of data until the consumer is ready.

### **Basic Components of Writable Streams**
1. **Sink**: The destination where data is written, such as a file or network.
2. **Writer**: The writer is used to push chunks of data into the writable stream.
3. **Controller**: The internal controller manages the flow of data, including handling backpressure and signaling when the stream is finished.

### **Creating a Writable Stream**

A **WritableStream** is created using the `WritableStream` constructor. This constructor accepts an object with methods for controlling how the data is written:

- **`write(chunk)`**: This method writes a chunk of data to the destination.
- **`close()`**: This method signals that no more data will be written to the stream.
- **`abort()`**: This method allows you to terminate the stream early (e.g., if an error occurs).

### **Basic Example: Creating a Writable Stream**

Here’s an example of creating a simple writable stream that writes chunks of data:

```javascript
const writableStream = new WritableStream({
  write(chunk) {
    console.log('Writing chunk:', chunk);
  },
  close() {
    console.log('Stream finished');
  },
  abort(err) {
    console.log('Stream aborted due to:', err);
  }
});

// Create a writer to write data to the stream
const writer = writableStream.getWriter();

// Write some chunks of data
writer.write('Hello');
writer.write(' World!');
writer.close();  // Close the stream after writing
```

### **Explanation of the Example**
- The **`WritableStream`** constructor creates a writable stream.
- The **`write()`** method is called to write data into the stream.
- The **`close()`** method signals that no more data will be written, and the stream is finished.
- The **`abort()`** method can be called if an error occurs and you need to terminate the stream early.
- **`getWriter()`** is used to get a writer for the writable stream, and the **`write()`** method is used to push data into it.

### **Writing Data to a Writable Stream**

Writable streams allow you to write data incrementally. To do this, you use the **`write()`** method provided by the writable stream's writer. Each time **`write()`** is called, a chunk of data is written to the stream.

```javascript
const writableStream = new WritableStream({
  write(chunk) {
    console.log('Chunk written:', chunk);
  }
});

const writer = writableStream.getWriter();
writer.write('Chunk 1');
writer.write('Chunk 2');
```

Each call to **`write()`** pushes a chunk of data into the writable stream. You can call **`write()`** multiple times to write multiple chunks.

### **Handling Backpressure in Writable Streams**

Backpressure occurs when the consumer of the stream (e.g., a file system or a network service) can't keep up with the rate at which data is being written. Writable streams handle backpressure automatically by using the internal **queue**.

The `write()` method may return a **promise** that resolves when the data has been successfully written, allowing you to control the flow of data. If the stream is overwhelmed, the system can pause the writing process until the consumer is ready to accept more data.

For example, you can use **`writer.write()`** with a **promise**:

```javascript
const writableStream = new WritableStream({
  write(chunk) {
    return new Promise((resolve) => {
      setTimeout(() => {
        console.log('Written:', chunk);
        resolve();
      }, 1000); // Simulate a delay in writing
    });
  }
});

const writer = writableStream.getWriter();
writer.write('Chunk 1').then(() => {
  writer.write('Chunk 2');
});
```

In this case, each chunk is written with a simulated delay, and the next chunk won't be written until the current one is successfully processed.

### **Writable Stream with Backpressure Handling**

If you need to handle backpressure manually, you can use the **`writableStream.getWriter().write()`** method with a custom logic to pause and resume writing based on the state of the consumer.

```javascript
const writableStream = new WritableStream({
  write(chunk) {
    return new Promise((resolve, reject) => {
      if (shouldPauseWriting()) {
        // Pause writing if necessary
        setTimeout(() => {
          console.log('Paused writing, resuming...');
          resolve();
        }, 1000);
      } else {
        console.log('Writing chunk:', chunk);
        resolve();
      }
    });
  }
});

const writer = writableStream.getWriter();
writer.write('First chunk');
writer.write('Second chunk');
```

In this case, **`shouldPauseWriting()`** is a custom function that determines whether the stream should pause based on some external condition.

### **Writable Streams with File Uploads**

Writable streams are commonly used for file uploads, where data is sent to a server incrementally, chunk by chunk. This avoids loading the entire file into memory and makes the upload more efficient.

#### **Example: Uploading a File Using a Writable Stream**

```javascript
const fileInput = document.querySelector('input[type="file"]');

fileInput.addEventListener('change', (event) => {
  const file = event.target.files[0];
  const writableStream = new WritableStream({
    write(chunk) {
      // Send the chunk to the server
      console.log('Uploading chunk:', chunk);
      // Here you can use fetch or other methods to send the chunk to the server
    },
    close() {
      console.log('Upload complete');
    }
  });

  const writer = writableStream.getWriter();
  const reader = file.stream().getReader();
  let chunk;

  // Read the file in chunks and write to the stream
  function processFile() {
    reader.read().then(({ done, value }) => {
      if (done) {
        writer.close(); // Finish the stream when the file is fully uploaded
        return;
      }
      writer.write(value);  // Write the chunk to the writable stream
      processFile();  // Continue reading and writing the next chunk
    });
  }

  processFile();
});
```

In this example:
- A file input (`input[type="file"]`) is used to select a file for upload.
- The file's stream is read in chunks using **`file.stream().getReader()`**.
- Each chunk is written to the writable stream using **`writer.write()`**.
- The **`close()`** method is called when all chunks have been uploaded.

### **Conclusion**

**Writable Streams** provide an efficient way to send or write data incrementally. By handling data in chunks, writable streams help you:
- Manage large datasets without consuming too much memory.
- Efficiently upload data, send network requests, or write to files in a non-blocking manner.
- Handle backpressure to ensure that data is written at a rate the consumer can handle.

Writable streams are especially useful for real-time data streaming, file uploads, and any scenario where you need to send data incrementally rather than all at once.
