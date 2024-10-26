In Dart, strings, numbers, booleans, lists, and maps are fundamental data types that you will frequently use in your programs. Below is a detailed overview of each of these data types, including their features, methods, and examples.

### 1. **Strings**

Strings are sequences of characters and are used to represent text. You can create strings using single quotes (`'`) or double quotes (`"`). Dart also supports multi-line strings using triple quotes (`'''` or `"""`).

#### Example:

```dart
void main() {
  // Creating strings
  String singleLine = 'Hello, Dart!';
  String doubleLine = "Welcome to Dart programming.";
  String multiLine = '''This is a
multi-line string.''';

  // String interpolation
  String name = 'Alice';
  String greeting = 'Hello, $name!'; // Using interpolation

  print(singleLine);
  print(doubleLine);
  print(multiLine);
  print(greeting);
}
```

#### Common String Methods:

- **`length`**: Returns the length of the string.
- **`toUpperCase()`**: Converts the string to uppercase.
- **`toLowerCase()`**: Converts the string to lowercase.
- **`substring(start, end)`**: Returns a substring from the string.
- **`split(String delimiter)`**: Splits the string into a list using the given delimiter.

### 2. **Numbers**

Dart supports two main types of numbers:

- **`int`**: Represents integer values (whole numbers).
- **`double`**: Represents floating-point values (decimal numbers).

#### Example:

```dart
void main() {
  int integer = 42;
  double decimal = 3.14;

  // Arithmetic operations
  int sum = integer + 10; 
  double product = decimal * 2.5;

  print('Integer: $integer, Sum: $sum');
  print('Decimal: $decimal, Product: $product');
}
```

#### Common Number Methods:

- **`toString()`**: Converts the number to a string.
- **`round()`**: Rounds the number to the nearest integer.
- **`abs()`**: Returns the absolute value.
- **`compareTo(num other)`**: Compares this number with another number.

### 3. **Booleans**

Booleans represent truth values: `true` or `false`. They are used in conditional statements and logical operations.

#### Example:

```dart
void main() {
  bool isStudent = true;
  bool isEmployed = false;

  // Logical operations
  bool isAvailable = isStudent && !isEmployed; // AND, NOT

  print('Is student: $isStudent');
  print('Is employed: $isEmployed');
  print('Is available: $isAvailable');
}
```

#### Common Boolean Operations:

- **Logical AND**: `&&`
- **Logical OR**: `||`
- **Logical NOT**: `!`

### 4. **Lists**

Lists are ordered collections of items. You can define lists using square brackets (`[]`). Lists can contain elements of the same type or different types.

#### Example:

```dart
void main() {
  // Creating a list
  List<String> fruits = ['Apple', 'Banana', 'Cherry'];
  
  // Adding an element
  fruits.add('Date');

  // Accessing elements
  String firstFruit = fruits[0];

  print('Fruits: $fruits');
  print('First fruit: $firstFruit');
}
```

#### Common List Methods:

- **`add(element)`**: Adds an element to the end of the list.
- **`insert(index, element)`**: Inserts an element at the specified index.
- **`remove(element)`**: Removes the first occurrence of the element from the list.
- **`length`**: Returns the number of elements in the list.
- **`contains(element)`**: Checks if the list contains the specified element.

### 5. **Maps**

Maps are collections of key-value pairs. They are similar to dictionaries in other programming languages. You can define maps using curly braces (`{}`).

#### Example:

```dart
void main() {
  // Creating a map
  Map<String, int> scores = {
    'Alice': 90,
    'Bob': 85,
    'Charlie': 88,
  };

  // Adding a key-value pair
  scores['David'] = 92;

  // Accessing values
  int alicesScore = scores['Alice']!; // Using null assertion

  print('Scores: $scores');
  print("Alice's score: $alicesScore");
}
```

#### Common Map Methods:

- **`putIfAbsent(key, value)`**: Adds a key-value pair if the key does not exist.
- **`remove(key)`**: Removes the entry for the specified key.
- **`containsKey(key)`**: Checks if the map contains the specified key.
- **`keys`**: Returns an iterable of the keys in the map.
- **`values`**: Returns an iterable of the values in the map.

### Conclusion

Understanding strings, numbers, booleans, lists, and maps is crucial for effective programming in Dart. These data types form the backbone of most Dart applications, enabling you to store, manipulate, and retrieve data easily. With this foundational knowledge, you can build more complex structures and algorithms in your Dart programs!
