In Java, you can read and write files using various classes from the `java.io` and `java.nio.file` packages. Here’s a breakdown of different approaches:

---

## **Reading Files in Java**
### **1. Using `BufferedReader` (Efficient for large text files)**
```java
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class ReadFileExample {
    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new FileReader("example.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```
**Explanation:**
- Uses `BufferedReader` for efficient reading line-by-line.
- `try-with-resources` ensures automatic resource closing.

---

### **2. Using `Files.readAllLines()` (For small files)**
```java
import java.nio.file.Files;
import java.nio.file.Path;
import java.io.IOException;
import java.util.List;

public class ReadFileNIO {
    public static void main(String[] args) {
        try {
            List<String> lines = Files.readAllLines(Path.of("example.txt"));
            lines.forEach(System.out::println);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```
**Explanation:**
- Reads all lines into a `List<String>`.
- Suitable for small files.

---

### **3. Using `Files.readString()` (Java 11+)**
```java
import java.nio.file.Files;
import java.nio.file.Path;
import java.io.IOException;

public class ReadFileString {
    public static void main(String[] args) {
        try {
            String content = Files.readString(Path.of("example.txt"));
            System.out.println(content);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```
**Explanation:**
- Reads the entire file content as a single `String`.
- Introduced in Java 11.

---

## **Writing Files in Java**
### **1. Using `BufferedWriter` (Efficient for large text files)**
```java
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class WriteFileExample {
    public static void main(String[] args) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("example.txt"))) {
            writer.write("Hello, World!");
            writer.newLine(); // Adds a new line
            writer.write("This is a Java file writing example.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```
**Explanation:**
- `BufferedWriter` ensures efficient writing.
- `newLine()` helps in writing new lines.

---

### **2. Using `Files.write()` (For small files)**
```java
import java.nio.file.Files;
import java.nio.file.Path;
import java.io.IOException;
import java.util.List;

public class WriteFileNIO {
    public static void main(String[] args) {
        try {
            Files.write(Path.of("example.txt"), List.of("Hello, World!", "Java file writing example."));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```
**Explanation:**
- Writes a `List<String>` to the file.
- Overwrites the file if it exists.

---

### **3. Using `Files.writeString()` (Java 11+)**
```java
import java.nio.file.Files;
import java.nio.file.Path;
import java.io.IOException;

public class WriteFileString {
    public static void main(String[] args) {
        try {
            Files.writeString(Path.of("example.txt"), "Hello, World!\nJava 11 file writing!");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```
**Explanation:**
- Writes a `String` to the file.
- Introduced in Java 11.

---

### **Binary File Handling (`FileInputStream` and `FileOutputStream`)**
For handling binary files (images, videos, etc.), use `FileInputStream` and `FileOutputStream`.

#### **Reading a Binary File**
```java
import java.io.FileInputStream;
import java.io.IOException;

public class ReadBinaryFile {
    public static void main(String[] args) {
        try (FileInputStream inputStream = new FileInputStream("image.png")) {
            byte[] data = inputStream.readAllBytes();
            System.out.println("File read successfully, size: " + data.length + " bytes");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

#### **Writing a Binary File**
```java
import java.io.FileOutputStream;
import java.io.IOException;

public class WriteBinaryFile {
    public static void main(String[] args) {
        byte[] data = {65, 66, 67, 68}; // Example binary data

        try (FileOutputStream outputStream = new FileOutputStream("output.bin")) {
            outputStream.write(data);
            System.out.println("File written successfully.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

---

## **Summary**
| Method | Read | Write | Notes |
|--------|------|-------|-------|
| `BufferedReader` / `BufferedWriter` | ✅ | ✅ | Best for large files, efficient |
| `Files.readAllLines()` / `Files.write()` | ✅ | ✅ | Good for small files |
| `Files.readString()` / `Files.writeString()` | ✅ | ✅ | Java 11+, simple approach |
| `FileInputStream` / `FileOutputStream` | ✅ | ✅ | Best for binary files |

---
