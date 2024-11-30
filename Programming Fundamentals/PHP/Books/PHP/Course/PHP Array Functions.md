### PHP Array Functions

PHP provides a wide range of functions to work with arrays, allowing you to manipulate, modify, and analyze arrays in different ways. Below is a comprehensive guide to the most commonly used PHP array functions.

---

### 1. **Creating Arrays**

- **`array()`**: Creates an array.

  ```php
  $arr = array(1, 2, 3);
  ```

- **`range()`**: Creates an array of elements based on a specified range.

  ```php
  $arr = range(1, 5);  // Output: [1, 2, 3, 4, 5]
  ```

---

### 2. **Array Information**

- **`count()`**: Returns the number of elements in an array.

  ```php
  $arr = [1, 2, 3];
  echo count($arr);  // Output: 3
  ```

- **`sizeof()`**: Alias of `count()`, returns the number of elements.

  ```php
  echo sizeof($arr);  // Output: 3
  ```

- **`array_key_exists()`**: Checks if a specific key exists in an array.

  ```php
  $arr = ["name" => "John", "age" => 25];
  echo array_key_exists("age", $arr);  // Output: 1 (true)
  ```

- **`array_keys()`**: Returns all the keys of an array.

  ```php
  $arr = ["a" => "apple", "b" => "banana"];
  print_r(array_keys($arr));  // Output: ["a", "b"]
  ```

- **`array_values()`**: Returns all the values of an array, discarding the keys.

  ```php
  $arr = ["a" => "apple", "b" => "banana"];
  print_r(array_values($arr));  // Output: ["apple", "banana"]
  ```

- **`is_array()`**: Checks if a variable is an array.

  ```php
  $arr = [1, 2, 3];
  echo is_array($arr);  // Output: 1 (true)
  ```

---

### 3. **Array Manipulation**

- **`array_push()`**: Adds one or more elements to the end of an array.

  ```php
  $arr = [1, 2];
  array_push($arr, 3, 4);
  print_r($arr);  // Output: [1, 2, 3, 4]
  ```

- **`array_pop()`**: Removes the last element of an array.

  ```php
  $arr = [1, 2, 3];
  array_pop($arr);
  print_r($arr);  // Output: [1, 2]
  ```

- **`array_shift()`**: Removes the first element of an array.

  ```php
  $arr = [1, 2, 3];
  array_shift($arr);
  print_r($arr);  // Output: [2, 3]
  ```

- **`array_unshift()`**: Adds one or more elements to the beginning of an array.

  ```php
  $arr = [2, 3];
  array_unshift($arr, 1);
  print_r($arr);  // Output: [1, 2, 3]
  ```

- **`array_splice()`**: Removes or replaces elements in an array.

  ```php
  $arr = [1, 2, 3, 4];
  array_splice($arr, 2, 1, [5, 6]);
  print_r($arr);  // Output: [1, 2, 5, 6, 4]
  ```

- **`array_merge()`**: Merges two or more arrays.

  ```php
  $arr1 = [1, 2];
  $arr2 = [3, 4];
  $merged = array_merge($arr1, $arr2);
  print_r($merged);  // Output: [1, 2, 3, 4]
  ```

- **`array_merge_recursive()`**: Merges arrays recursively.

  ```php
  $arr1 = ["a" => "apple", "b" => "banana"];
  $arr2 = ["b" => "berry", "c" => "cherry"];
  $merged = array_merge_recursive($arr1, $arr2);
  print_r($merged);  
  // Output: ["a" => "apple", "b" => ["banana", "berry"], "c" => "cherry"]
  ```

- **`array_slice()`**: Extracts a portion of an array.

  ```php
  $arr = [1, 2, 3, 4, 5];
  $slice = array_slice($arr, 2, 2);
  print_r($slice);  // Output: [3, 4]
  ```

- **`array_chunk()`**: Splits an array into chunks.

  ```php
  $arr = [1, 2, 3, 4, 5];
  $chunks = array_chunk($arr, 2);
  print_r($chunks);  // Output: [[1, 2], [3, 4], [5]]
  ```

- **`array_diff()`**: Compares arrays and returns the elements that are not in the other arrays.

  ```php
  $arr1 = [1, 2, 3];
  $arr2 = [2, 3, 4];
  $diff = array_diff($arr1, $arr2);
  print_r($diff);  // Output: [1]
  ```

- **`array_intersect()`**: Compares arrays and returns the common elements.

  ```php
  $arr1 = [1, 2, 3];
  $arr2 = [2, 3, 4];
  $intersect = array_intersect($arr1, $arr2);
  print_r($intersect);  // Output: [2, 3]
  ```

- **`array_flip()`**: Flips the keys and values of an array.

  ```php
  $arr = ["a" => "apple", "b" => "banana"];
  $flipped = array_flip($arr);
  print_r($flipped);  // Output: ["apple" => "a", "banana" => "b"]
  ```

---

### 4. **Array Sorting**

- **`sort()`**: Sorts an array in ascending order.

  ```php
  $arr = [3, 1, 2];
  sort($arr);
  print_r($arr);  // Output: [1, 2, 3]
  ```

- **`rsort()`**: Sorts an array in descending order.

  ```php
  $arr = [1, 2, 3];
  rsort($arr);
  print_r($arr);  // Output: [3, 2, 1]
  ```

- **`asort()`**: Sorts an array in ascending order while maintaining the association between keys and values.

  ```php
  $arr = ["a" => 1, "b" => 2, "c" => 3];
  asort($arr);
  print_r($arr);  // Output: ["a" => 1, "b" => 2, "c" => 3]
  ```

- **`ksort()`**: Sorts an array by its keys in ascending order.

  ```php
  $arr = ["c" => 3, "b" => 2, "a" => 1];
  ksort($arr);
  print_r($arr);  // Output: ["a" => 1, "b" => 2, "c" => 3]
  ```

- **`usort()`**: Sorts an array by using a user-defined comparison function.

  ```php
  $arr = [1, 3, 2];
  usort($arr, function($a, $b) { return $a - $b; });
  print_r($arr);  // Output: [1, 2, 3]
  ```

---

### 5. **Searching Arrays**

- **`in_array()`**: Checks if a value exists in an array.

  ```php
  $arr = [1, 2, 3];
  echo in_array(2, $arr);  // Output: 1 (true)
  ```

- **`array_search()`**: Searches for a value in an array and returns the corresponding key.

  ```php
  $arr = ["a" => "apple", "b" => "banana"];
  echo array_search("banana", $arr);  // Output: b
  ```

- **`array_key_exists()`**: Checks if a key exists in an array.

  ```php
  $arr = ["name" => "John", "age" => 25];
  echo array_key_exists("age", $arr);  // Output: 1 (true)
  ```

---

### 6. **Array Combining and Chunking**

- **`array_combine()`**: Combines two arrays into a new array, using the first array's values as keys and the second array's values as values.

  ```php


  $keys = ["a", "b"];
  $values = [1, 2];
  $arr = array_combine($keys, $values);
  print_r($arr);  // Output: ["a" => 1, "b" => 2]
  ```

- **`array_chunk()`**: Splits an array into chunks.

  ```php
  $arr = [1, 2, 3, 4, 5];
  $chunks = array_chunk($arr, 2);
  print_r($chunks);  // Output: [[1, 2], [3, 4], [5]]
  ```

---

### 7. **Array Filtering**

- **`array_filter()`**: Filters elements of an array using a callback function.

  ```php
  $arr = [1, 2, 3, 4];
  $filtered = array_filter($arr, function($value) {
    return $value % 2 == 0;  // Only even numbers
  });
  print_r($filtered);  // Output: [2, 4]
  ```

---

### Conclusion

PHP provides a comprehensive set of array functions that make it easy to work with arrays. These functions allow you to manipulate arrays, search through them, sort them, and more. By mastering these functions, you can efficiently handle and process array data in PHP.
