In Go, `range` is a keyword used in `for` loops to iterate over various data structures like arrays, slices, maps, and channels. It provides a convenient way to get both the index/key and the value for each element in the collection.

### 1. **Using `range` with Slices and Arrays**

When using `range` with slices and arrays, it returns two values:
- **Index**: The current index in the array or slice.
- **Value**: The value at that index.

#### Example:
```go
package main

import "fmt"

func main() {
    nums := []int{2, 4, 6, 8}

    // Looping through the slice with range
    for index, value := range nums {
        fmt.Printf("Index: %d, Value: %d\n", index, value)
    }

    // Output:
    // Index: 0, Value: 2
    // Index: 1, Value: 4
    // Index: 2, Value: 6
    // Index: 3, Value: 8
}
```

If you only need the **value** and not the **index**, use an underscore `_` to ignore the index.

```go
for _, value := range nums {
    fmt.Println(value)
}
```

### 2. **Using `range` with Maps**

When iterating over maps with `range`, it returns:
- **Key**: The current key in the map.
- **Value**: The value associated with that key.

Since map elements are unordered, the order of iteration is not guaranteed to be consistent.

#### Example:
```go
package main

import "fmt"

func main() {
    colors := map[string]string{
        "red":   "#FF0000",
        "green": "#00FF00",
        "blue":  "#0000FF",
    }

    // Looping through the map with range
    for key, value := range colors {
        fmt.Printf("Key: %s, Value: %s\n", key, value)
    }

    // Output (order may vary):
    // Key: red, Value: #FF0000
    // Key: green, Value: #00FF00
    // Key: blue, Value: #0000FF
}
```

If you only need the **keys** and not the **values**, you can ignore the value by using `_`.

```go
for key := range colors {
    fmt.Println(key)
}
```

### 3. **Using `range` with Strings**

When using `range` with a string, it iterates over the string as Unicode code points, returning:
- **Index**: The byte index of the start of each rune.
- **Rune**: The Unicode code point value of each character.

This is useful for handling multi-byte characters in strings.

#### Example:
```go
package main

import "fmt"

func main() {
    str := "hello"

    for index, char := range str {
        fmt.Printf("Index: %d, Character: %c\n", index, char)
    }

    // Output:
    // Index: 0, Character: h
    // Index: 1, Character: e
    // Index: 2, Character: l
    // Index: 3, Character: l
    // Index: 4, Character: o
}
```

### 4. **Using `range` with Channels**

When iterating over a channel using `range`, it retrieves values from the channel until it is closed. This is a common pattern when reading values from channels in concurrent programming.

#### Example:
```go
package main

import "fmt"

func main() {
    ch := make(chan int, 3)
    ch <- 1
    ch <- 2
    ch <- 3
    close(ch)

    // Range over the channel to retrieve values
    for value := range ch {
        fmt.Println(value)
    }

    // Output:
    // 1
    // 2
    // 3
}
```

### 5. **Ignoring Values in `range`**

When iterating, you might only need one of the values (`index`, `key`, `value`, etc.). Use `_` to ignore any value you don’t need.

- **Ignore index** in arrays, slices, or strings:
  ```go
  for _, value := range nums {
      fmt.Println(value)
  }
  ```

- **Ignore value** in maps:
  ```go
  for key := range colors {
      fmt.Println(key)
  }
  ```

### Summary

- **Slices and Arrays**: Returns index and value.
- **Maps**: Returns key and value.
- **Strings**: Returns index and rune (Unicode character).
- **Channels**: Returns values until the channel is closed.

Using `range` makes code concise and clear, particularly when working with collections or channels in Go.
