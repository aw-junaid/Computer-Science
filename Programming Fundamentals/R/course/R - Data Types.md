In R, data types define the kind of values a variable can hold. The language provides several built-in data types to handle different kinds of data, ranging from numbers to characters and logical values. Here’s an overview of the primary data types in R:

### 1. **Numeric**
- **Definition**: Numeric data types represent numbers, which can be either integers or real numbers (floating point).
- **Examples**:
  ```r
  x <- 10         # Integer (numeric)
  y <- 3.14       # Floating point (numeric)
  ```

- **Operations**: You can perform arithmetic operations on numeric types:
  ```r
  sum <- x + y    # Adding numeric values
  product <- x * y  # Multiplying numeric values
  ```

### 2. **Integer**
- **Definition**: Integers are whole numbers without decimals. In R, integers can be explicitly created using the `L` suffix.
- **Examples**:
  ```r
  a <- 5L   # Integer value
  b <- 3L   # Another integer value
  ```

- **Note**: By default, numbers without the `L` suffix are treated as numeric (i.e., double precision floating point numbers). Adding `L` ensures the value is stored as an integer.

### 3. **Character (String)**
- **Definition**: Character data types represent text (strings of characters). These values are enclosed in either single (`'`) or double (`"`) quotes.
- **Examples**:
  ```r
  name <- "John"
  city <- 'New York'
  ```

- **Operations**: You can concatenate strings using the `paste()` or `paste0()` functions:
  ```r
  full_name <- paste(name, "Doe")   # John Doe
  ```

### 4. **Logical (Boolean)**
- **Definition**: Logical data types hold Boolean values: `TRUE` or `FALSE`.
- **Examples**:
  ```r
  is_active <- TRUE
  is_completed <- FALSE
  ```

- **Operations**: Logical operators can be used to compare values and return `TRUE` or `FALSE`:
  ```r
  x <- 5
  y <- 10
  result <- x < y   # TRUE, since 5 is less than 10
  ```

- Logical values are commonly used in control flow statements (`if`, `while`) and in filtering data.

### 5. **Complex**
- **Definition**: Complex numbers are numbers that have both a real and an imaginary part. They are expressed as `a + bi`, where `a` is the real part and `b` is the imaginary part.
- **Examples**:
  ```r
  z <- 2 + 3i   # Complex number: 2 + 3i
  ```

- **Operations**: You can perform mathematical operations on complex numbers, such as addition and multiplication:
  ```r
  complex_sum <- (2 + 3i) + (1 + 4i)  # Complex addition
  ```

### 6. **Raw**
- **Definition**: The **raw** type is used to store raw bytes (binary data), which are not interpreted by R as specific types (e.g., numbers or characters).
- **Example**:
  ```r
  raw_data <- charToRaw("Hello")   # Convert a string to raw bytes
  ```

- **Usage**: Raw values are typically used in situations that require low-level data manipulation, such as in file reading/writing or cryptographic functions.

### 7. **Factors**
- **Definition**: Factors are used to represent categorical data. They store both the values and the corresponding levels (unique values). Factors are particularly useful for statistical modeling.
- **Examples**:
  ```r
  gender <- factor(c("male", "female", "female", "male"))
  ```

- **Levels**: You can view the unique levels of a factor:
  ```r
  levels(gender)   # Returns: "female", "male"
  ```

- **Usage**: Factors are often used in regression models or other statistical analyses where categorical variables need to be handled efficiently.

### 8. **Lists**
- **Definition**: A list is an ordered collection of elements, which can be of different types. Lists are more flexible than vectors because they can hold data of different types (e.g., a mix of numbers, characters, and other objects).
- **Examples**:
  ```r
  my_list <- list(1, "apple", TRUE, 3.14)
  ```

- **Accessing List Elements**: You can access list elements using double square brackets `[[ ]]` or the `$` operator for named list components:
  ```r
  my_list[[2]]   # Accesses the 2nd element (i.e., "apple")
  ```

### 9. **Data Frames**
- **Definition**: A data frame is a two-dimensional, tabular data structure where each column can contain data of different types (numeric, character, factor, etc.). It is one of the most commonly used structures in R for storing and working with datasets.
- **Examples**:
  ```r
  df <- data.frame(Name = c("John", "Jane", "Doe"),
                   Age = c(28, 34, 22),
                   Salary = c(50000, 60000, 45000))
  ```

- **Accessing Data Frame Elements**: You can access individual columns of a data frame using the `$` operator:
  ```r
  df$Name    # Access the "Name" column
  df[1, 2]   # Access the element at row 1, column 2
  ```

- **Subsetting**: You can subset a data frame based on conditions:
  ```r
  df[df$Age > 30, ]   # Select rows where Age > 30
  ```

### 10. **Matrices**
- **Definition**: A matrix is a two-dimensional data structure where all elements are of the same data type. It is essentially an extension of a vector, where the vector is arranged in rows and columns.
- **Examples**:
  ```r
  m <- matrix(1:6, nrow = 2, ncol = 3)
  ```

- **Accessing Matrix Elements**:
  ```r
  m[1, 2]  # Access element in the first row, second column
  ```

- **Operations**: Matrices support element-wise operations, similar to numeric vectors, and also matrix multiplication using `%*%`.

---

### Summary of R Data Types

| Data Type   | Description                                    | Example                                |
|-------------|------------------------------------------------|----------------------------------------|
| **Numeric** | Real numbers or decimals                       | `x <- 3.14`                            |
| **Integer** | Whole numbers                                  | `y <- 5L`                              |
| **Character**| Text or string data                           | `name <- "Alice"`                      |
| **Logical** | Boolean values (`TRUE` or `FALSE`)             | `flag <- TRUE`                         |
| **Complex** | Numbers with real and imaginary parts          | `z <- 3 + 4i`                          |
| **Raw**     | Raw binary data (rarely used)                  | `raw_data <- charToRaw("data")`        |
| **Factor**  | Categorical data with levels                   | `status <- factor(c("low", "high"))`   |
| **List**    | Ordered collection of different data types     | `my_list <- list(1, "hello", TRUE)`    |
| **Data Frame**| Table-like structure with columns of different data types | `df <- data.frame(Name = c("John", "Jane"), Age = c(28, 34))` |
| **Matrix**  | Two-dimensional array of the same data type    | `m <- matrix(1:6, nrow = 2, ncol = 3)` |

By understanding and working with these basic data types, you’ll be able to manipulate and analyze data effectively in R.
