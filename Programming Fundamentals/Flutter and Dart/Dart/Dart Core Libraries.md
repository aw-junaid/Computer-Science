Dart's core libraries provide a rich set of built-in functionalities that are essential for developing applications. These libraries cover a wide range of functionalities, from data manipulation and file I/O to networking and asynchronous programming. Here’s an overview of the key Dart core libraries, along with their primary features and use cases.

### 1. **Dart:core Library**

The `dart:core` library is automatically imported into every Dart program and contains fundamental classes and functions that are essential for programming in Dart.

#### Key Features:
- **Basic Types**: Includes primitive types such as `int`, `double`, `String`, `bool`, and `Null`.
- **Collections**: Provides collection classes such as `List`, `Set`, and `Map`.
- **Exceptions**: Defines the base class for all exceptions in Dart.
- **Other Utilities**: Includes utility classes such as `Duration`, `DateTime`, and `Uri`.

#### Example Usage:

```dart
void main() {
  // Working with List
  List<String> fruits = ['Apple', 'Banana', 'Cherry'];
  print(fruits.length); // Output: 3

  // Using DateTime
  DateTime now = DateTime.now();
  print('Current time: $now');
}
```

### 2. **Dart:async Library**

The `dart:async` library provides support for asynchronous programming, allowing you to work with `Future` and `Stream`.

#### Key Features:
- **Future**: Represents a potential value or error that will be available at some point in the future.
- **Stream**: A sequence of asynchronous events. Streams can be single-subscription or broadcast.

#### Example Usage:

```dart
import 'dart:async';

Future<String> fetchData() async {
  return Future.delayed(Duration(seconds: 2), () => 'Data fetched');
}

void main() async {
  String data = await fetchData();
  print(data); // Output: Data fetched
}
```

### 3. **Dart:io Library**

The `dart:io` library provides access to input and output operations, including file and network I/O.

#### Key Features:
- **File Operations**: Read and write files, directories, and paths.
- **Socket Programming**: Create TCP and UDP sockets.
- **HTTP Client**: Make HTTP requests.

#### Example Usage:

```dart
import 'dart:io';

void main() async {
  // Writing to a file
  File file = File('example.txt');
  await file.writeAsString('Hello, Dart!');

  // Reading from a file
  String contents = await file.readAsString();
  print(contents); // Output: Hello, Dart!
}
```

### 4. **Dart:convert Library**

The `dart:convert` library provides utilities for encoding and decoding data in different formats, such as JSON, UTF-8, and base64.

#### Key Features:
- **JSON Encoding/Decoding**: Easily convert Dart objects to JSON and vice versa.
- **Base64 Encoding/Decoding**: Encode and decode data in base64 format.

#### Example Usage:

```dart
import 'dart:convert';

void main() {
  // Encoding to JSON
  Map<String, dynamic> user = {'name': 'Alice', 'age': 25};
  String jsonString = jsonEncode(user);
  print(jsonString); // Output: {"name":"Alice","age":25}

  // Decoding from JSON
  Map<String, dynamic> decodedUser = jsonDecode(jsonString);
  print(decodedUser['name']); // Output: Alice
}
```

### 5. **Dart:math Library**

The `dart:math` library provides mathematical constants and functions, making it easier to perform complex calculations.

#### Key Features:
- **Mathematical Constants**: Access to constants like `pi` and `e`.
- **Mathematical Functions**: Functions for trigonometry, logarithms, and random number generation.

#### Example Usage:

```dart
import 'dart:math';

void main() {
  // Using math constants
  print('Value of pi: $pi'); // Output: Value of pi: 3.141592653589793

  // Generating a random number
  var random = Random();
  int randomNumber = random.nextInt(100);
  print('Random number: $randomNumber');
}
```

### 6. **Dart:html Library**

The `dart:html` library provides APIs for web applications to interact with the browser and manipulate the DOM.

#### Key Features:
- **Document Object Model (DOM)**: Access and manipulate HTML elements.
- **Events**: Handle user events like clicks and key presses.

#### Example Usage:

```dart
import 'dart:html';

void main() {
  querySelector('#myButton')?.onClick.listen((event) {
    print('Button clicked!');
  });
}
```

### 7. **Dart:isolate Library**

The `dart:isolate` library provides support for concurrent programming through isolates, which are independent workers that can run in parallel.

#### Key Features:
- **Isolates**: Allow for concurrent execution, providing a way to run code in parallel without shared memory.
- **Message Passing**: Communicate between isolates using message passing.

#### Example Usage:

```dart
import 'dart:isolate';

void isolateFunction(SendPort sendPort) {
  sendPort.send('Hello from isolate!');
}

void main() async {
  final receivePort = ReceivePort();
  Isolate.spawn(isolateFunction, receivePort.sendPort);
  
  receivePort.listen((message) {
    print(message); // Output: Hello from isolate!
  });
}
```

### 8. **Dart:ffi Library**

The `dart:ffi` library provides interoperability with C code, allowing you to call C functions and use C libraries from Dart.

#### Key Features:
- **Foreign Function Interface (FFI)**: Call C functions directly from Dart code.
- **C Data Types**: Use C types in Dart.

#### Example Usage:

```dart
import 'dart:ffi';
import 'dart:io';

// Assuming you have a C library that exposes a function `int add(int a, int b)`
typedef AddFunction = Int32 Function(Int32 a, Int32 b);
typedef DartAddFunction = int Function(int a, int b);

void main() {
  final dylib = DynamicLibrary.open('libexample.so');
  final add = dylib
      .lookup<NativeFunction<AddFunction>>('add')
      .asFunction<DartAddFunction>();

  print('Sum: ${add(3, 4)}'); // Output: Sum: 7
}
```

### 9. **Conclusion**

Dart's core libraries provide a robust foundation for building applications by offering essential functionalities and tools for various tasks. Understanding how to utilize these libraries effectively can significantly enhance your productivity and enable you to write more efficient and cleaner code. Whether you're working on a web, server, or mobile application, the core libraries have you covered!
