An extended R cheat sheet that covers essential commands, syntax, and concepts. This cheat sheet includes data types, control structures, functions, data frames, plotting, and more.

---

## **1. Basic Syntax**

### 1.1 Hello World Program

```r
print("Hello, World!")
```

**Explanation**: This command uses the `print()` function to display "Hello, World!" in the console.

---

## **2. Data Types**

### 2.1 Vectors

```r
numeric_vector <- c(1.5, 2.3, 3.1)     # Numeric vector
integer_vector <- c(1L, 2L, 3L)         # Integer vector
character_vector <- c("a", "b", "c")    # Character vector
logical_vector <- c(TRUE, FALSE, TRUE)   # Logical vector
```

**Explanation**: Vectors are a basic data structure in R that can hold elements of the same type.

### 2.2 Lists

```r
my_list <- list(name = "Alice", age = 25, scores = c(85, 90, 95))
```

**Explanation**: Lists can hold different types of elements, including vectors, other lists, or data frames.

### 2.3 Matrices

```r
my_matrix <- matrix(1:9, nrow = 3, ncol = 3)
```

**Explanation**: Matrices are two-dimensional arrays that hold elements of the same type.

### 2.4 Data Frames

```r
my_df <- data.frame(Name = c("Alice", "Bob"), Age = c(25, 30))
```

**Explanation**: Data frames are two-dimensional data structures that can hold different types of data in columns.

---

## **3. Control Structures**

### 3.1 If-Else Statement

```r
number <- 10

if (number > 0) {
    print("Positive")
} else if (number < 0) {
    print("Negative")
} else {
    print("Zero")
}
```

**Explanation**: The `if-else` statement is used for conditional branching.

### 3.2 Switch Statement

```r
fruit <- "Apple"

switch(fruit,
       "Apple" = print("It's an apple!"),
       "Banana" = print("It's a banana!"),
       print("Unknown fruit"))
```

**Explanation**: The `switch` statement evaluates an expression and matches it against multiple cases.

### 3.3 For Loop

```r
for (i in 1:5) {
    print(i)
}
```

**Explanation**: The `for` loop iterates over a sequence of values.

### 3.4 While Loop

```r
count <- 5

while (count > 0) {
    print(count)
    count <- count - 1
}
```

**Explanation**: The `while` loop continues to execute as long as its condition is true.

---

## **4. Functions**

### 4.1 Defining and Calling Functions

```r
greet <- function(name) {
    paste("Hello,", name)
}

# Calling the function
greeting <- greet("Alice")
print(greeting)  # Outputs: Hello, Alice
```

**Explanation**: Functions are defined using the `function` keyword and can take parameters.

### 4.2 Returning Values

```r
add <- function(a, b) {
    return(a + b)
}

# Using the function
sum <- add(5, 3)
print(sum)  # Outputs: 8
```

**Explanation**: Functions can return values using the `return()` statement.

### 4.3 Default Parameters

```r
multiply <- function(x, y = 2) {
    return(x * y)
}

# Using the function
result <- multiply(5)   # Uses default value for y
print(result)  # Outputs: 10
```

**Explanation**: You can set default values for function parameters.

---

## **5. Data Frames**

### 5.1 Creating Data Frames

```r
my_df <- data.frame(Name = c("Alice", "Bob"), Age = c(25, 30))
```

**Explanation**: Create a data frame using the `data.frame()` function.

### 5.2 Accessing Data Frame Elements

```r
# Accessing a column
names <- my_df$Name

# Accessing a specific row and column
age_of_alice <- my_df[1, "Age"]
```

**Explanation**: Use the `$` operator to access columns or bracket notation to access specific rows and columns.

### 5.3 Adding Columns

```r
my_df$Score <- c(90, 85)
```

**Explanation**: You can add a new column to a data frame by assigning a vector to it.

### 5.4 Filtering Data Frames

```r
filtered_df <- my_df[my_df$Age > 25, ]
```

**Explanation**: Use logical conditions to filter rows in a data frame.

---

## **6. Plotting**

### 6.1 Basic Plotting

```r
x <- c(1, 2, 3, 4, 5)
y <- c(2, 3, 5, 7, 11)

plot(x, y, type = "b", col = "blue", main = "My Plot", xlab = "X-axis", ylab = "Y-axis")
```

**Explanation**: The `plot()` function creates a basic scatter plot. The `type` parameter can specify the type of plot (e.g., `"b"` for both points and lines).

### 6.2 Adding Titles and Labels

```r
title(main = "My Plot Title")
```

**Explanation**: Use `title()` to add titles and labels to your plots.

### 6.3 Histogram

```r
hist(rnorm(100), main = "Histogram of Random Normals", xlab = "Value", col = "lightblue")
```

**Explanation**: The `hist()` function creates a histogram of data.

---

## **7. Package Management**

### 7.1 Installing Packages

```r
install.packages("ggplot2")
```

**Explanation**: Use `install.packages()` to install external packages from CRAN.

### 7.2 Loading Packages

```r
library(ggplot2)
```

**Explanation**: Use `library()` to load a package into your R session.

---

## **8. File I/O**

### 8.1 Reading CSV Files

```r
data <- read.csv("data.csv")
```

**Explanation**: Use `read.csv()` to load data from a CSV file into a data frame.

### 8.2 Writing to CSV Files

```r
write.csv(data, "output.csv", row.names = FALSE)
```

**Explanation**: Use `write.csv()` to save a data frame to a CSV file.

---

## **9. Control Flow Functions**

### 9.1 Applying Functions

```r
numbers <- c(1, 2, 3, 4, 5)

squared <- sapply(numbers, function(x) x^2)
```

**Explanation**: Use `sapply()` to apply a function over a vector or list and return a simplified result.

### 9.2 Using `lapply`

```r
list_of_numbers <- list(a = 1:3, b = 4:6)

result <- lapply(list_of_numbers, function(x) sum(x))
```

**Explanation**: Use `lapply()` to apply a function to each element of a list and return a list.

---

## **10. Regular Expressions**

### 10.1 Pattern Matching

```r
text <- "Hello, my name is Alice."
grep("Alice", text)  # Returns the index of the match
```

**Explanation**: Use `grep()` to search for patterns in text.

### 10.2 String Replacement

```r
new_text <- gsub("Alice", "Bob", text)
```

**Explanation**: Use `gsub()` to replace occurrences of a pattern in a string.

---

## **11. Statistical Functions**

### 11.1 Basic Statistics

```r
mean_value <- mean(numbers)
median_value <- median(numbers)
sd_value <- sd(numbers)
```

**Explanation**: Use `mean()`, `median()`, and `sd()` to calculate basic statistical measures.

### 11.2 T-tests

```r
t_test_result <- t.test(numbers, mu = 0)
```

**Explanation**: Use `t.test()` to perform a t-test on a vector of data.

---

## **12. Working with Dates**

### 12.1 Date Operations

```r
today <- Sys.Date()                          # Get today's date
formatted_date <- format(today, "%Y-%m-%d") # Format the date
```

**Explanation**: Use `Sys.Date()` to get the current date, and `format()` to format dates.

---

## **Conclusion**

This cheat sheet provides a comprehensive overview of essential commands and concepts in R. Regular practice with these concepts will help you become proficient in R programming.
