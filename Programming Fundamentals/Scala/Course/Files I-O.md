### Scala - Files I/O

In Scala, file input/output (I/O) is handled through the `java.io` and `scala.io` libraries, which provide various utilities for reading from and writing to files. You can perform file I/O using both low-level and high-level APIs.

### 1. **File Operations in Scala**

#### Using `java.io.File`

The `java.io.File` class in Scala is used for interacting with the file system. You can use it to create, delete, rename, and check properties of files and directories.

```scala
import java.io.File

val file = new File("example.txt")

// Check if the file exists
if (file.exists()) {
  println("File exists")
} else {
  println("File does not exist")
}

// Create a new file
file.createNewFile()

// Delete the file
file.delete()
```

### 2. **Reading Files in Scala**

#### 2.1. **Using `Source` from `scala.io`**

`scala.io.Source` is a convenient way to read files in Scala. It supports reading files line by line or as a whole.

- **Reading Entire File:**

```scala
import scala.io.Source

val fileName = "example.txt"
val fileContent = Source.fromFile(fileName).getLines().mkString("\n")

println(fileContent)
```

- **Reading Line by Line:**

```scala
import scala.io.Source

val file = Source.fromFile("example.txt")

for (line <- file.getLines()) {
  println(line)
}

file.close()  // Don't forget to close the file
```

- **Reading File as a String:**

```scala
import scala.io.Source

val content = Source.fromFile("example.txt").mkString

println(content)
```

#### 2.2. **Handling Exceptions**

You should handle exceptions when reading files. For instance, a file may not exist, or there could be an I/O error.

```scala
import scala.io.Source
import java.io.FileNotFoundException

try {
  val source = Source.fromFile("example.txt")
  source.getLines().foreach(println)
  source.close()
} catch {
  case e: FileNotFoundException => println("File not found")
  case e: Exception => println(s"Error reading file: ${e.getMessage}")
}
```

### 3. **Writing Files in Scala**

#### 3.1. **Using `java.io.PrintWriter`**

To write text to a file in Scala, you can use the `PrintWriter` class. It’s a convenient way to write strings to a file.

- **Writing to a File:**

```scala
import java.io.PrintWriter

val writer = new PrintWriter("output.txt")
writer.write("Hello, World!")
writer.close()
```

- **Writing Multiple Lines:**

```scala
import java.io.PrintWriter

val writer = new PrintWriter("output.txt")
val lines = List("First line", "Second line", "Third line")

for (line <- lines) {
  writer.println(line)
}

writer.close()
```

#### 3.2. **Using `BufferedWriter`**

`BufferedWriter` is more efficient than `PrintWriter` for writing large files, as it buffers the data before writing it to the file.

```scala
import java.io.{BufferedWriter, FileWriter}

val writer = new BufferedWriter(new FileWriter("output.txt"))
writer.write("Hello, BufferedWriter!")
writer.close()
```

### 4. **File I/O Using `Files` in Java NIO**

The `java.nio.file` package in Java provides a more modern and efficient approach to file I/O. You can use the `Files` class for reading and writing files as well as handling paths.

#### 4.1. **Reading Files Using `Files.readAllLines`**

```scala
import java.nio.file.{Files, Paths}

val path = Paths.get("example.txt")
val lines = Files.readAllLines(path)

lines.forEach(println)
```

#### 4.2. **Writing Files Using `Files.write`**

```scala
import java.nio.file.{Files, Paths}

val path = Paths.get("output.txt")
val content = "Hello, Scala NIO!"

Files.write(path, content.getBytes)
```

### 5. **Appending Data to a File**

To append data to a file instead of overwriting it, you can use `FileWriter` with the `append` parameter set to `true`.

```scala
import java.io.FileWriter

val writer = new FileWriter("output.txt", true)
writer.write("\nThis is appended text.")
writer.close()
```

### 6. **Working with Directories**

You can also perform operations on directories, such as creating, listing files, and deleting directories.

#### 6.1. **Creating a Directory**

```scala
import java.io.File

val directory = new File("newDirectory")
if (!directory.exists()) {
  directory.mkdir()  // Creates the directory
  println("Directory created.")
} else {
  println("Directory already exists.")
}
```

#### 6.2. **Listing Files in a Directory**

```scala
import java.io.File

val directory = new File("path/to/directory")
if (directory.exists() && directory.isDirectory) {
  val files = directory.listFiles()
  files.foreach(file => println(file.getName))
} else {
  println("Directory does not exist.")
}
```

#### 6.3. **Deleting a Directory**

```scala
import java.io.File

val directory = new File("newDirectory")
if (directory.exists()) {
  directory.delete()  // Deletes the directory (must be empty)
  println("Directory deleted.")
} else {
  println("Directory does not exist.")
}
```

### 7. **Temporary Files**

Scala provides methods for creating and managing temporary files using the `java.nio.file.Files` API.

#### 7.1. **Creating a Temporary File**

```scala
import java.nio.file.{Files, Path}

val tempFile: Path = Files.createTempFile("temp", ".txt")
println(s"Temporary file created: $tempFile")
```

#### 7.2. **Deleting Temporary File**

```scala
import java.nio.file.Files

val tempFile = Files.createTempFile("temp", ".txt")
Files.delete(tempFile)  // Deletes the temporary file
println(s"Temporary file deleted: $tempFile")
```

### 8. **File I/O with `scala.io.StdIn` for Interactive Input**

If you want to interactively read data from the user (like reading input from the console), Scala provides the `scala.io.StdIn` object.

```scala
import scala.io.StdIn

val name = StdIn.readLine("Enter your name: ")
println(s"Hello, $name!")
```

### 9. **Handling Large Files (Buffered I/O)**

For reading and writing large files efficiently, it's recommended to use buffered I/O streams to reduce the number of read/write operations and improve performance.

```scala
import java.io.{BufferedReader, FileReader}

val reader = new BufferedReader(new FileReader("largefile.txt"))
var line: String = null

while ({ line = reader.readLine(); line != null }) {
  println(line)
}

reader.close()
```

### Summary

- **File I/O** in Scala can be done using both `java.io` and `java.nio.file` APIs.
- `scala.io.Source` is used for reading files, while `java.io.PrintWriter` or `BufferedWriter` is used for writing files.
- Regular file operations include creating, deleting, renaming, and listing files and directories.
- Modern file I/O can be done with the `java.nio.file` package, which provides efficient file handling and path manipulation.
- For interactive input/output, `scala.io.StdIn` can be used for reading user input from the console.
- **Buffered I/O** is recommended for working with large files to improve performance.

By leveraging Scala’s file I/O capabilities, you can efficiently read, write, and manipulate files and directories, enabling your applications to handle file-based data effectively.
