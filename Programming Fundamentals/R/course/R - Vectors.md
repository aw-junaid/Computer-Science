In R, a **vector** is a basic data structure that holds an ordered collection of elements, which must all be of the same type. Vectors are one of the most fundamental data structures in R and are used to represent simple data such as numbers, characters, or logical values.

### 1. **Creating Vectors**

You can create vectors in R using the **`c()`** function, which combines individual elements into a vector.

#### Example of Numeric Vector:
```r
numeric_vector <- c(1, 2, 3, 4, 5)
```

#### Example of Character Vector:
```r
char_vector <- c("apple", "banana", "cherry")
```

#### Example of Logical Vector:
```r
logical_vector <- c(TRUE, FALSE, TRUE)
```

### 2. **Types of Vectors**

R supports different types of vectors based on the data they contain. These types include:

- **Numeric Vectors**: Contains numbers (integers or floating-point).
- **Character Vectors**: Contains strings.
- **Logical Vectors**: Contains boolean values (`TRUE` or `FALSE`).
- **Integer Vectors**: A subset of numeric vectors specifically containing integer values.
- **Complex Vectors**: Vectors that contain complex numbers (e.g., `1 + 2i`).

You can explicitly create integer and complex vectors using the **`L`** suffix and the **`complex()`** function, respectively.

#### Example of Integer Vector:
```r
int_vector <- c(1L, 2L, 3L)  # The L suffix specifies integer type
```

#### Example of Complex Vector:
```r
complex_vector <- c(1+2i, 3+4i, 5+6i)
```

### 3. **Accessing Elements of a Vector**

You can access elements of a vector using the **indexing operator `[ ]`**, where the index starts at 1 (unlike many other programming languages that start at 0). 

#### Example:
```r
x <- c(10, 20, 30, 40, 50)
x[1]  # Output: 10 (first element)
x[3]  # Output: 30 (third element)
```

To access multiple elements, you can specify a vector of indices.

```r
x[c(1, 3, 5)]  # Output: 10 30 50 (first, third, and fifth elements)
```

### 4. **Modifying Elements of a Vector**

You can modify the elements of a vector by assigning new values to the corresponding indices.

#### Example:
```r
x <- c(10, 20, 30, 40, 50)
x[2] <- 100  # Change the second element
print(x)  # Output: 10 100 30 40 50
```

### 5. **Vectorized Operations**

One of the key features of vectors in R is **vectorized operations**. This means that arithmetic operations can be performed on entire vectors without the need for explicit loops. R automatically applies the operation element-wise to the vectors.

#### Example of Vectorized Arithmetic:
```r
x <- c(1, 2, 3, 4)
y <- c(10, 20, 30, 40)
sum_vector <- x + y  # Element-wise addition
print(sum_vector)  # Output: 11 22 33 44
```

#### Example of Vectorized Functions:
```r
x <- c(1, 2, 3, 4)
squared <- x^2  # Element-wise squaring
print(squared)  # Output: 1 4 9 16
```

### 6. **Indexing with Logical Vectors**

You can use logical vectors to index and extract elements of a vector that meet certain conditions.

#### Example:
```r
x <- c(1, 2, 3, 4, 5)
logical_index <- c(TRUE, FALSE, TRUE, FALSE, TRUE)
result <- x[logical_index]
print(result)  # Output: 1 3 5
```

You can also create logical vectors dynamically by applying conditions to a vector.

#### Example with Condition:
```r
x <- c(10, 20, 30, 40, 50)
result <- x[x > 25]  # Extract elements greater than 25
print(result)  # Output: 30 40 50
```

### 7. **Common Vector Functions**

R provides several functions that are useful for working with vectors:

- **`length()`**: Returns the length of the vector (i.e., the number of elements).
  
  ```r
  length(x)  # Output: 5 (for a vector with 5 elements)
  ```

- **`sum()`**: Returns the sum of the elements in a vector.
  
  ```r
  sum(x)  # Output: 150 (sum of elements)
  ```

- **`mean()`**: Computes the mean of the elements in a vector.
  
  ```r
  mean(x)  # Output: 30 (average of elements)
  ```

- **`min()` and `max()`**: Find the minimum and maximum values in a vector.
  
  ```r
  min(x)  # Output: 10
  max(x)  # Output: 50
  ```

- **`sort()`**: Sorts the elements of a vector in ascending order.
  
  ```r
  sort(x)  # Output: 10 20 30 40 50
  ```

- **`rev()`**: Reverses the order of elements in a vector.
  
  ```r
  rev(x)  # Output: 50 40 30 20 10
  ```

- **`unique()`**: Removes duplicate elements from a vector.
  
  ```r
  y <- c(1, 2, 2, 3, 3, 4)
  unique(y)  # Output: 1 2 3 4
  ```

- **`which()`**: Returns the indices of elements that satisfy a given condition.
  
  ```r
  which(x > 25)  # Output: 3 4 5 (positions of elements greater than 25)
  ```

### 8. **Concatenating Vectors**

You can combine multiple vectors using the **`c()`** function. This is useful for creating larger vectors from smaller ones.

#### Example:
```r
x <- c(1, 2, 3)
y <- c(4, 5, 6)
z <- c(x, y)  # Concatenate x and y
print(z)  # Output: 1 2 3 4 5 6
```

### 9. **Other Vector Operations**

- **Recycling**: When performing operations between vectors of unequal lengths, R automatically "recycles" the shorter vector to match the length of the longer one. This may result in a warning if the lengths are not compatible.

  #### Example:
  ```r
  x <- c(1, 2, 3, 4)
  y <- c(10, 20)
  result <- x + y  # y is recycled to match the length of x
  print(result)  # Output: 11 22 13 24
  ```

- **`rep()`**: Replicates the elements of a vector.

  #### Example:
  ```r
  rep(x, times = 2)  # Repeats the vector twice
  # Output: 1 2 3 4 1 2 3 4
  ```

### 10. **Special Vectors**

- **`seq()`**: Creates a sequence of numbers. This is useful for generating a regular sequence of numbers for loops or plotting.

  #### Example:
  ```r
  seq(1, 10, by = 2)  # Output: 1 3 5 7 9
  ```

- **`rep()`**: Repeats elements of a vector.

  #### Example:
  ```r
  rep(1:3, each = 2)  # Output: 1 1 2 2 3 3
  ```

### Summary

| Function         | Description                                                        | Example Usage                                   |
|------------------|--------------------------------------------------------------------|-------------------------------------------------|
| **`c()`**        | Combine elements into a vector                                     | `c(1, 2, 3)`                                    |
| **`length()`**   | Get the length of a vector                                          | `length(x)`                                     |
| **`sum()`**      | Calculate the sum of vector elements                                | `sum(x)`                                        |
| **`mean()`**     | Calculate the mean of vector elements                               | `mean(x)`                                       |
| **`sort()`**     | Sort elements of a vector in ascending order                       | `sort(x)`                                       |
| **`rev()`**      | Reverse the order of a vector                                      | `rev(x)`                                        |
| **`unique()`**   | Return unique elements of a vector                                  | `unique(x)`                                     |
| **`seq()`**      | Generate a sequence of numbers                                     | `seq(1, 10, by = 2)`                            |
| **`rep()`**      | Repeat elements of a vector                                        | `rep(x, times = 2)`                             |

### Conclusion

Vectors are one of the most important data structures in R

, allowing you to store and manipulate ordered collections of elements efficiently. Understanding how to create, manipulate, and perform operations on vectors is key to working effectively in R.
