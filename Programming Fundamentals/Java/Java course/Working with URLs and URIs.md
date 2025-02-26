In Java, working with **URLs (Uniform Resource Locators)** and **URIs (Uniform Resource Identifiers)** is essential for handling web resources, such as web pages, files, and APIs. The `java.net` package provides classes like `URL` and `URI` to manipulate and interact with these resources.

---

### **URL vs URI**

1. **URL**:
   - A URL is a specific type of URI that specifies the location of a resource on the internet.
   - Example: `https://www.example.com:8080/path/to/resource?query=param#fragment`
   - Components:
     - Protocol (`https`)
     - Host (`www.example.com`)
     - Port (`8080`)
     - Path (`/path/to/resource`)
     - Query (`?query=param`)
     - Fragment (`#fragment`)

2. **URI**:
   - A URI is a broader term that identifies a resource by name, location, or both.
   - It can be a URL (location) or a URN (Uniform Resource Name, which identifies a resource by name).
   - Example: `urn:isbn:0451450523` (a URN) or `https://www.example.com` (a URL).

---

### **Working with URLs in Java**

The `java.net.URL` class represents a URL and provides methods to access its components and open connections to the resource.

#### **Creating a URL**
```java
import java.net.URL;

public class URLExample {
    public static void main(String[] args) throws Exception {
        // Create a URL object
        URL url = new URL("https://www.example.com:8080/path/to/resource?query=param#fragment");

        // Access URL components
        System.out.println("Protocol: " + url.getProtocol()); // https
        System.out.println("Host: " + url.getHost());         // www.example.com
        System.out.println("Port: " + url.getPort());         // 8080
        System.out.println("Path: " + url.getPath());         // /path/to/resource
        System.out.println("Query: " + url.getQuery());       // query=param
        System.out.println("Fragment: " + url.getRef());      // fragment
    }
}
```

#### **Reading Data from a URL**
You can use the `URL` class to open a connection and read data from the resource.

```java
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;

public class URLReader {
    public static void main(String[] args) throws Exception {
        URL url = new URL("https://www.example.com");
        BufferedReader in = new BufferedReader(new InputStreamReader(url.openStream()));

        String inputLine;
        while ((inputLine = in.readLine()) != null) {
            System.out.println(inputLine);
        }
        in.close();
    }
}
```

---

### **Working with URIs in Java**

The `java.net.URI` class represents a URI and provides methods to manipulate and resolve URIs.

#### **Creating a URI**
```java
import java.net.URI;

public class URIExample {
    public static void main(String[] args) throws Exception {
        // Create a URI object
        URI uri = new URI("https://www.example.com/path/to/resource?query=param#fragment");

        // Access URI components
        System.out.println("Scheme: " + uri.getScheme());       // https
        System.out.println("Host: " + uri.getHost());           // www.example.com
        System.out.println("Path: " + uri.getPath());          // /path/to/resource
        System.out.println("Query: " + uri.getQuery());        // query=param
        System.out.println("Fragment: " + uri.getFragment());  // fragment
    }
}
```

#### **Resolving URIs**
You can resolve a relative URI against a base URI.

```java
import java.net.URI;

public class URIResolveExample {
    public static void main(String[] args) throws Exception {
        URI baseUri = new URI("https://www.example.com/path/");
        URI relativeUri = new URI("to/resource");

        URI resolvedUri = baseUri.resolve(relativeUri);
        System.out.println("Resolved URI: " + resolvedUri); // https://www.example.com/path/to/resource
    }
}
```

---

### **Key Differences Between URL and URI**

| Feature               | URL                                      | URI                                      |
|-----------------------|------------------------------------------|------------------------------------------|
| **Purpose**           | Specifies the location of a resource.    | Identifies a resource by name or location. |
| **Scope**             | A subset of URI.                         | A superset of URL.                       |
| **Example**           | `https://www.example.com`                | `https://www.example.com` or `urn:isbn:0451450523` |
| **Use Case**          | Accessing web resources.                 | Identifying resources (both by name and location). |

---

### **Common Use Cases**

1. **Parsing URLs/URIs**:
   - Extract components like protocol, host, path, query, and fragment.

2. **Opening Connections**:
   - Use `URL.openStream()` or `URL.openConnection()` to read data from a web resource.

3. **Resolving Relative Paths**:
   - Use `URI.resolve()` to resolve relative URIs against a base URI.

4. **Building URLs/URIs**:
   - Use `URI` or `URL` constructors to create and manipulate URIs/URLs programmatically.

---

### **Example: Building a URL Dynamically**
```java
import java.net.URI;
import java.net.URISyntaxException;

public class BuildURLExample {
    public static void main(String[] args) throws URISyntaxException {
        String scheme = "https";
        String host = "www.example.com";
        String path = "/search";
        String query = "q=java+programming";

        URI uri = new URI(scheme, host, path, query, null);
        System.out.println("Built URI: " + uri); // https://www.example.com/search?q=java+programming
    }
}
```

---

### **Best Practices**

1. **Validate Input**:
   - Always validate user input when constructing URLs or URIs to avoid malformed URIs.

2. **Handle Exceptions**:
   - Use try-catch blocks to handle `MalformedURLException` and `URISyntaxException`.

3. **Use HTTPS**:
   - Prefer HTTPS over HTTP for secure communication.

4. **Encode Special Characters**:
   - Use `URLEncoder` and `URLDecoder` to encode and decode URL components.

---

### **Encoding and Decoding URLs**

Java provides the `URLEncoder` and `URLDecoder` classes to handle special characters in URLs.

#### **Encoding**
```java
import java.net.URLEncoder;
import java.nio.charset.StandardCharsets;

public class URLEncoderExample {
    public static void main(String[] args) throws Exception {
        String query = "Java Programming & Networking";
        String encodedQuery = URLEncoder.encode(query, StandardCharsets.UTF_8.toString());
        System.out.println("Encoded Query: " + encodedQuery); // Java+Programming+%26+Networking
    }
}
```

#### **Decoding**
```java
import java.net.URLDecoder;
import java.nio.charset.StandardCharsets;

public class URLDecoderExample {
    public static void main(String[] args) throws Exception {
        String encodedQuery = "Java+Programming+%26+Networking";
        String decodedQuery = URLDecoder.decode(encodedQuery, StandardCharsets.UTF_8.toString());
        System.out.println("Decoded Query: " + decodedQuery); // Java Programming & Networking
    }
}
```

---

By mastering URLs and URIs in Java, you can effectively work with web resources, build dynamic URLs, and handle network communication in your applications.
