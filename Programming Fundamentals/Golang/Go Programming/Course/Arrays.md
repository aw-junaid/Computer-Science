In Go, **arrays** are a fixed-size, ordered collection of elements of the same data type. Arrays have a specific length, which is determined at the time of creation and cannot be changed. They are not as commonly used in Go as slices, but understanding arrays is essential for working effectively with data collections in Go.

### 1. **Declaring Arrays**

Arrays are declared by specifying the number of elements and the data type.

#### Syntax:
```go
var arrayName [size]Type
```

#### Example:
```go
package main

import "fmt"

func main() {
    var arr [5]int           // Declares an integer array with 5 elements
    fmt.Println(arr)          // Output: [0 0 0 0 0] (zero-values for int)

    arr[0] = 10               // Set the first element to 10
    fmt.Println(arr)          // Output: [10 0 0 0 0]
}
```

### 2. **Array Initialization**

You can initialize arrays during declaration with specific values.

#### Example:
```go
package main

import "fmt"

func main() {
    arr := [5]int{1, 2, 3, 4, 5}         // Array with all elements initialized
    fmt.Println(arr)                      // Output: [1 2 3 4 5]

    arrPartial := [5]int{1, 2}            // Partial initialization (rest are zero-values)
    fmt.Println(arrPartial)               // Output: [1 2 0 0 0]

    arrAutoSize := [...]int{1, 2, 3}      // Array with inferred size
    fmt.Println(arrAutoSize)              // Output: [1 2 3]
}
```

### 3. **Accessing Array Elements**

Elements are accessed using the index, which starts at 0.

#### Example:
```go
package main

import "fmt"

func main() {
    arr := [3]string{"Go", "Python", "Java"}
    fmt.Println(arr[0])                   // Output: "Go"
    fmt.Println(arr[2])                   // Output: "Java"
}
```

If you try to access an index that is out of bounds, Go will throw a runtime error.

### 4. **Array Length**

The `len` function returns the length of the array.

#### Example:
```go
package main

import "fmt"

func main() {
    arr := [5]int{10, 20, 30, 40, 50}
    fmt.Println(len(arr))                 // Output: 5
}
```

### 5. **Iterating Over Arrays**

You can iterate over arrays using a `for` loop or a `for range` loop.

#### Example with `for` loop:
```go
package main

import "fmt"

func main() {
    arr := [3]string{"Go", "Python", "Java"}
    for i := 0; i < len(arr); i++ {
        fmt.Println(arr[i])
    }
}
```

#### Example with `for range` loop:
```go
package main

import "fmt"

func main() {
    arr := [3]string{"Go", "Python", "Java"}
    for index, value := range arr {
        fmt.Printf("Index: %d, Value: %s\n", index, value)
    }
}
```

### 6. **Multi-dimensional Arrays**

Go supports multi-dimensional arrays. The syntax is similar to single-dimensional arrays, but you specify multiple sizes.

#### Example:
```go
package main

import "fmt"

func main() {
    var matrix [2][3]int               // 2 rows and 3 columns
    matrix[0][0] = 1
    matrix[1][2] = 5
    fmt.Println(matrix)                // Output: [[1 0 0] [0 0 5]]

    // Initialization
    matrixInit := [2][2]int{{1, 2}, {3, 4}}
    fmt.Println(matrixInit)            // Output: [[1 2] [3 4]]
}
```

### 7. **Copying Arrays**

In Go, arrays are **value types**. Assigning one array to another copies all elements of the array.

#### Example:
```go
package main

import "fmt"

func main() {
    arr1 := [3]int{1, 2, 3}
    arr2 := arr1            // Copy of arr1 is made
    arr2[0] = 100           // Modify arr2
    fmt.Println(arr1)       // Output: [1 2 3] (unchanged)
    fmt.Println(arr2)       // Output: [100 2 3]
}
```

### 8. **Passing Arrays to Functions**

When you pass an array to a function, it is passed by value, meaning a copy is made. To modify the original array, you can pass a pointer to the array.

#### Example of passing by value:
```go
package main

import "fmt"

func modifyArray(arr [3]int) {
    arr[0] = 10
}

func main() {
    arr := [3]int{1, 2, 3}
    modifyArray(arr)
    fmt.Println(arr)         // Output: [1 2 3] (original array unchanged)
}
```

#### Example of passing by reference:
```go
package main

import "fmt"

func modifyArray(arr *[3]int) {
    arr[0] = 10
}

func main() {
    arr := [3]int{1, 2, 3}
    modifyArray(&arr)
    fmt.Println(arr)         // Output: [10 2 3] (original array changed)
}
```

### 9. **Comparing Arrays**

In Go, you can compare two arrays of the same type and length directly using `==` or `!=`. This compares elements one-by-one.

#### Example:
```go
package main

import "fmt"

func main() {
    arr1 := [3]int{1, 2, 3}
    arr2 := [3]int{1, 2, 3}
    arr3 := [3]int{4, 5, 6}
    
    fmt.Println(arr1 == arr2)   // Output: true
    fmt.Println(arr1 == arr3)   // Output: false
}
```

### 10. **Limitations of Arrays and Use of Slices**

Arrays in Go have a fixed length, which makes them somewhat limited for dynamic data structures. Slices, which are more commonly used in Go, are built on top of arrays and offer a flexible length. Slices allow dynamic resizing, whereas arrays cannot be resized after creation.

### Summary

- **Immutable Length**: Arrays have a fixed size and cannot be resized.
- **Value Type**: Assigning or passing arrays creates a copy.
- **Multi-dimensional**: Arrays can be nested.
- **Direct Comparison**: Arrays of the same type and size can be directly compared.
- **Slices**: Often preferred for dynamic-sized collections.
