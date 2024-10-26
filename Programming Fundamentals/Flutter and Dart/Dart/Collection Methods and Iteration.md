In Dart, collections such as **Lists**, **Sets**, and **Maps** come with a variety of built-in methods for manipulation, searching, and iteration. These methods make it easy to perform common operations on collections without having to write complex code. Here’s an overview of common collection methods and how to iterate through these collections.

### 1. **Common Collection Methods**

#### List Methods

- **`add(element)`**: Adds an element to the end of the list.
- **`addAll(Iterable<E> iterable)`**: Adds all elements from the iterable to the list.
- **`insert(int index, E element)`**: Inserts an element at the specified index.
- **`remove(element)`**: Removes the first occurrence of the specified element.
- **`removeAt(int index)`**: Removes the element at the specified index.
- **`clear()`**: Removes all elements from the list.
- **`contains(element)`**: Checks if the list contains the specified element.
- **`indexOf(element)`**: Returns the index of the first occurrence of the specified element.
- **`sort()`**: Sorts the list in ascending order.

#### Set Methods

- **`add(element)`**: Adds an element to the set.
- **`addAll(Iterable<E> elements)`**: Adds all elements from the iterable.
- **`remove(element)`**: Removes the specified element.
- **`contains(element)`**: Checks if the set contains the specified element.
- **`clear()`**: Removes all elements from the set.
- **`intersection(Set<E> other)`**: Returns a set containing elements common to both sets.
- **`union(Set<E> other)`**: Returns a set containing all elements from both sets.
- **`difference(Set<E> other)`**: Returns a set containing elements in the first set but not in the second.

#### Map Methods

- **`putIfAbsent(K key, V Function() ifAbsent)`**: Adds a key-value pair if the key does not already exist.
- **`remove(K key)`**: Removes the specified key and its corresponding value.
- **`clear()`**: Removes all key-value pairs from the map.
- **`containsKey(K key)`**: Checks if the map contains the specified key.
- **`containsValue(V value)`**: Checks if the map contains the specified value.
- **`update(K key, V Function(V value) update, {V Function()? ifAbsent})`**: Updates the value for the specified key.
- **`keys`**: Returns an iterable of the map’s keys.
- **`values`**: Returns an iterable of the map’s values.

### 2. **Iterating Over Collections**

#### Iterating Through a List

You can iterate through a list using various methods, such as a `for` loop, a `for-in` loop, or the `forEach` method.

**Using a For Loop:**

```dart
void main() {
  List<String> fruits = ['Apple', 'Banana', 'Cherry'];

  for (int i = 0; i < fruits.length; i++) {
    print(fruits[i]); // Output: Apple, Banana, Cherry
  }
}
```

**Using a For-In Loop:**

```dart
void main() {
  List<String> fruits = ['Apple', 'Banana', 'Cherry'];

  for (String fruit in fruits) {
    print(fruit); // Output: Apple, Banana, Cherry
  }
}
```

**Using ForEach Method:**

```dart
void main() {
  List<String> fruits = ['Apple', 'Banana', 'Cherry'];

  fruits.forEach((fruit) {
    print(fruit); // Output: Apple, Banana, Cherry
  });
}
```

#### Iterating Through a Set

You can iterate through a set using similar methods.

**Using a For-In Loop:**

```dart
void main() {
  Set<String> fruits = {'Apple', 'Banana', 'Cherry'};

  for (String fruit in fruits) {
    print(fruit); // Output: Apple, Banana, Cherry (order may vary)
  }
}
```

**Using ForEach Method:**

```dart
void main() {
  Set<String> fruits = {'Apple', 'Banana', 'Cherry'};

  fruits.forEach((fruit) {
    print(fruit); // Output: Apple, Banana, Cherry (order may vary)
  });
}
```

#### Iterating Through a Map

When iterating through a map, you can access keys and values using the `entries` property.

**Using a For-In Loop:**

```dart
void main() {
  Map<String, String> capitals = {
    'USA': 'Washington, D.C.',
    'France': 'Paris',
    'Germany': 'Berlin'
  };

  for (var entry in capitals.entries) {
    print('Country: ${entry.key}, Capital: ${entry.value}');
  }
}
```

**Using ForEach Method:**

```dart
void main() {
  Map<String, String> capitals = {
    'USA': 'Washington, D.C.',
    'France': 'Paris',
    'Germany': 'Berlin'
  };

  capitals.forEach((country, capital) {
    print('Country: $country, Capital: $capital');
  });
}
```

### 3. **Conclusion**

Dart's collection types (Lists, Sets, and Maps) provide a rich set of methods for data manipulation and iteration. Understanding these methods and how to effectively iterate over collections is essential for writing efficient and clean Dart code. Whether you need to store ordered data, unique items, or key-value pairs, Dart collections offer the tools necessary for effective data management. By leveraging these capabilities, you can simplify your code and enhance its readability and maintainability.
