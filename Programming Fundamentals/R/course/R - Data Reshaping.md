In R, **data reshaping** refers to the process of changing the structure of a dataset, such as transforming it from a wide format to a long format or vice versa. This is important for preparing data for analysis, visualization, or modeling. Common reshaping tasks include:

- **Pivoting**: Changing data between long and wide formats.
- **Melting**: Converting data from a wide format to a long format.
- **Casting**: Converting data from a long format to a wide format.

Several R functions and packages, such as **`reshape()`**, **`reshape2`**, and **`tidyr`**, can be used to reshape data.

### 1. **Reshaping Data with `reshape()`**

The base R function **`reshape()`** can be used for reshaping data between wide and long formats.

#### Syntax:
```r
reshape(data, idvar, timevar, direction = c("long", "wide"), ...)
```
- **`data`**: The data frame to be reshaped.
- **`idvar`**: The variable(s) identifying each observation (row).
- **`timevar`**: The variable(s) that defines the different time points or measurement levels.
- **`direction`**: Specifies whether to reshape the data to long format ("long") or wide format ("wide").

#### Example 1: Wide to Long Format (Melting)
```r
# Example data
data <- data.frame(
  id = c(1, 2, 3),
  score_math = c(85, 90, 88),
  score_science = c(92, 94, 89)
)

# Reshape from wide to long format
long_data <- reshape(data, varying = c("score_math", "score_science"), 
                     v.names = "score", timevar = "subject", 
                     times = c("Math", "Science"), direction = "long")

print(long_data)
```

**Output:**
```
  id subject score
1   1    Math    85
2   1 Science    92
3   2    Math    90
4   2 Science    94
5   3    Math    88
6   3 Science    89
```

#### Example 2: Long to Wide Format (Casting)
```r
# Reshape from long to wide format
wide_data <- reshape(long_data, idvar = "id", timevar = "subject", 
                     direction = "wide")

print(wide_data)
```

**Output:**
```
  id score.Math score.Science
1   1          85            92
2   2          90            94
3   3          88            89
```

### 2. **Using `reshape2` Package for Reshaping**

The **`reshape2`** package provides convenient functions like **`melt()`** and **`dcast()`** for reshaping data.

#### Installing `reshape2`:
```r
install.packages("reshape2")
library(reshape2)
```

#### Example 1: Melting Data (Wide to Long Format)
```r
# Example data
data <- data.frame(
  id = c(1, 2, 3),
  score_math = c(85, 90, 88),
  score_science = c(92, 94, 89)
)

# Reshaping from wide to long format using melt()
long_data <- melt(data, id.vars = "id", variable.name = "subject", value.name = "score")
print(long_data)
```

**Output:**
```
  id     subject score
1   1   score_math    85
2   2   score_math    90
3   3   score_math    88
4   1 score_science    92
5   2 score_science    94
6   3 score_science    89
```

#### Example 2: Casting Data (Long to Wide Format)
```r
# Reshaping from long to wide format using dcast()
wide_data <- dcast(long_data, id ~ subject, value.var = "score")
print(wide_data)
```

**Output:**
```
  id score_math score_science
1   1          85            92
2   2          90            94
3   3          88            89
```

### 3. **Using `tidyr` Package for Data Reshaping**

The **`tidyr`** package, part of the **tidyverse**, provides functions like **`pivot_longer()`** and **`pivot_wider()`** for reshaping data in a more intuitive way.

#### Installing `tidyr`:
```r
install.packages("tidyr")
library(tidyr)
```

#### Example 1: Pivoting from Wide to Long Format
```r
# Example data
data <- data.frame(
  id = c(1, 2, 3),
  score_math = c(85, 90, 88),
  score_science = c(92, 94, 89)
)

# Reshape from wide to long format using pivot_longer()
long_data <- pivot_longer(data, cols = starts_with("score"),
                           names_to = "subject", values_to = "score")
print(long_data)
```

**Output:**
```
# A tibble: 6 × 3
     id subject      score
  <dbl> <chr>        <dbl>
1     1 score_math      85
2     1 score_science   92
3     2 score_math      90
4     2 score_science   94
5     3 score_math      88
6     3 score_science   89
```

#### Example 2: Pivoting from Long to Wide Format
```r
# Reshape from long to wide format using pivot_wider()
wide_data <- pivot_wider(long_data, names_from = "subject", values_from = "score")
print(wide_data)
```

**Output:**
```
# A tibble: 3 × 4
     id score_math score_science
  <dbl>      <dbl>        <dbl>
1     1         85           92
2     2         90           94
3     3         88           89
```

### 4. **Reshaping Data for Aggregation**

You can also reshape data to perform aggregations, such as summing, averaging, or counting values. The **`dplyr`** package, also part of the **tidyverse**, is commonly used for data manipulation.

#### Example 1: Aggregating with `dplyr` and `pivot_wider()`
```r
library(dplyr)

# Example data
data <- data.frame(
  id = c(1, 1, 2, 2),
  subject = c("Math", "Science", "Math", "Science"),
  score = c(85, 92, 90, 94)
)

# Aggregate data by id and pivot wider
aggregated_data <- data %>%
  group_by(id) %>%
  summarise(across(starts_with("score"), sum)) %>%
  pivot_wider(names_from = subject, values_from = score)

print(aggregated_data)
```

**Output:**
```
# A tibble: 2 × 3
     id Math Science
  <dbl> <dbl>   <dbl>
1     1    85      92
2     2    90      94
```

### 5. **Other Useful Functions for Data Reshaping**

- **`spread()`**: An older function from **`tidyr`** (before `pivot_wider()`).
- **`gather()`**: An older function from **`tidyr`** (before `pivot_longer()`).

While **`spread()`** and **`gather()`** are still available for backward compatibility, it is recommended to use **`pivot_wider()`** and **`pivot_longer()`** for new code.

### Conclusion

Data reshaping is a critical part of data preparation and analysis. In R, reshaping can be performed using various functions and packages, such as **`reshape()`**, **`reshape2`**, and **`tidyr`**. Depending on the desired output (wide or long format), you can use different functions like **`melt()`**, **`pivot_longer()`**, **`pivot_wider()`**, and **`dcast()`**. Mastering these reshaping techniques is essential for efficient data wrangling and analysis in R.
