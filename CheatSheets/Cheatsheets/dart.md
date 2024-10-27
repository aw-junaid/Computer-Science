An extended Dart cheat sheet that covers essential commands, syntax, and concepts. This cheat sheet includes variables, data types, control structures, functions, classes, collections, async programming, and more.

---

## **Basic Syntax**

### 1. **Hello World Program**

```dart
void main() {
  print('Hello, World!');
}
```

**Explanation**: Every Dart program starts with a `main()` function, which is the entry point. The `print()` function is used to display output to the console.

---

## **Variables**

### 2. **Declaring Variables**

```dart
var a = 10;                  // Declaring a variable with inferred type
int b = 20;                  // Declaring a variable with explicit type
final c = 30;                // Final variable (cannot be reassigned)
const d = 40;                // Compile-time constant
```

**Explanation**: Use `var` for type inference, `final` for variables that can only be assigned once, and `const` for compile-time constants.

---

## **Data Types**

### 3. **Primitive Data Types**

```dart
int age = 25;                // Integer
double height = 5.9;        // Double
String name = 'Alice';       // String
bool isStudent = true;       // Boolean
```

**Explanation**: Dart supports various primitive data types, including integers, doubles, strings, and booleans.

### 4. **Lists**

```dart
List<String> fruits = ['Apple', 'Banana', 'Cherry']; // List of strings
```

**Explanation**: Lists are ordered collections of items and can hold any type.

---

## **Control Structures**

### 5. **If-Else Statement**

```dart
if (a > b) {
  print('a is greater than b');
} else if (a < b) {
  print('a is less than b');
} else {
  print('a is equal to b');
}
```

**Explanation**: Dart uses `if`, `else if`, and `else` for conditional branching.

### 6. **Switch Statement**

```dart
switch (a) {
  case 1:
    print('One');
    break;
  case 2:
    print('Two');
    break;
  default:
    print('Other');
}
```

**Explanation**: The `switch` statement evaluates an expression and matches it against multiple cases. Use `break` to prevent fall-through.

### 7. **For Loop**

```dart
for (var i = 0; i < 5; i++) {
  print(i);
}

for (var fruit in fruits) {      // For-in loop
  print(fruit);
}
```

**Explanation**: Dart provides traditional `for` loops and `for-in` loops for iterating over collections.

---

## **Functions**

### 8. **Defining Functions**

```dart
int add(int a, int b) {
  return a + b;
}

var result = add(5, 3);         // Calling the function
```

**Explanation**: Functions are defined with a return type and can accept parameters.

### 9. **Arrow Functions**

```dart
int add(int a, int b) => a + b; // Arrow function
var result = add(5, 3);
```

**Explanation**: Arrow functions provide a more concise syntax for single-expression functions.

### 10. **Optional Parameters**

```dart
void greet(String name, [String greeting = 'Hello']) {
  print('$greeting, $name!');
}

greet('Alice');                 // Outputs: Hello, Alice!
greet('Bob', 'Hi');            // Outputs: Hi, Bob!
```

**Explanation**: Use square brackets `[]` to denote optional positional parameters with default values.

### 11. **Named Parameters**

```dart
void greet({String name, String greeting = 'Hello'}) {
  print('$greeting, $name!');
}

greet(name: 'Alice');          // Outputs: Hello, Alice!
greet(name: 'Bob', greeting: 'Hi'); // Outputs: Hi, Bob!
```

**Explanation**: Use curly braces `{}` for named parameters, allowing more flexible function calls.

---

## **Classes and Objects**

### 12. **Defining a Class**

```dart
class Person {
  String name;
  int age;

  Person(this.name, this.age); // Constructor
}

var person = Person('Alice', 25); // Create an instance
```

**Explanation**: Classes are blueprints for objects, and you can define constructors to initialize object properties.

### 13. **Getters and Setters**

```dart
class Rectangle {
  double _width;  // Private variable
  double _height;

  Rectangle(this._width, this._height);

  double get area => _width * _height; // Getter
  set width(double value) => _width = value; // Setter
}
```

**Explanation**: Use getters and setters to control access to class properties.

---

## **Collections**

### 14. **Using Maps**

```dart
Map<String, int> scores = {
  'Alice': 90,
  'Bob': 85,
};

print(scores['Alice']); // Accessing a value by key
```

**Explanation**: Maps are collections of key-value pairs, where keys are unique.

### 15. **Sets**

```dart
Set<String> uniqueFruits = {'Apple', 'Banana', 'Apple'};
print(uniqueFruits); // Outputs: {Apple, Banana}
```

**Explanation**: Sets are unordered collections of unique items.

---

## **Async Programming**

### 16. **Future and Async/Await**

```dart
Future<String> fetchData() async {
  // Simulating a network request
  await Future.delayed(Duration(seconds: 2));
  return 'Data loaded';
}

void main() async {
  print('Loading...');
  String data = await fetchData();
  print(data); // Outputs: Data loaded
}
```

**Explanation**: Use `Future` for asynchronous operations. The `async` keyword allows you to use `await` to pause execution until the future is completed.

### 17. **Streams**

```dart
Stream<int> countStream() async* {
  for (var i = 0; i < 5; i++) {
    await Future.delayed(Duration(seconds: 1));
    yield i; // Yielding values to the stream
  }
}

void main() async {
  await for (var count in countStream()) {
    print(count); // Outputs: 0, 1, 2, 3, 4 (each second)
  }
}
```

**Explanation**: Streams allow you to handle asynchronous data flows. Use `async*` to create a stream and `yield` to send data.

---

## **Error Handling**

### 18. **Try-Catch**

```dart
try {
  var result = riskyFunction(); // Function that might throw
} catch (e) {
  print('Error: $e');
} finally {
  print('This runs regardless of error.');
}
```

**Explanation**: Use `try-catch` for exception handling. The `finally` block executes after the try and catch, regardless of an error.

---

## **Libraries and Packages**

### 19. **Importing Libraries**

```dart
import 'dart:math';  // Importing a built-in library
import 'my_library.dart'; // Importing a local library
```

**Explanation**: Use the `import` statement to include libraries and modules in your Dart code.

---

## **JSON**

### 20. **Working with JSON**

```dart
import 'dart:convert';

void main() {
  String jsonString = '{"name": "Alice", "age": 25}';
  Map<String, dynamic> jsonObject = jsonDecode(jsonString); // Parse JSON string to object

  String newJsonString = jsonEncode(jsonObject); // Convert object to JSON string
}
```

**Explanation**: Use `jsonDecode()` to convert JSON strings to Dart objects and `jsonEncode()` to convert Dart objects to JSON strings.

---

## **Conclusion**

This cheat sheet provides a comprehensive overview of essential commands and concepts in Dart. Regular practice with these concepts will help you become proficient in Dart programming.
