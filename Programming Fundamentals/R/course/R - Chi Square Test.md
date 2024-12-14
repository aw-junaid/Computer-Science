### Chi-Square Test in R

The **Chi-Square Test** is a statistical test used to examine the association between categorical variables. It compares the observed frequencies in each category to the expected frequencies if there were no association. The Chi-Square test can be used in two main scenarios:
1. **Chi-Square Test of Independence**: To test whether two categorical variables are independent (no association).
2. **Chi-Square Goodness of Fit Test**: To test whether a sample data matches an expected distribution.

In R, you can perform Chi-Square tests using the `chisq.test()` function, which can handle both types of Chi-Square tests.

### 1. Chi-Square Test of Independence

This test is used to determine if two categorical variables are independent of each other.

#### Example: Testing Independence Between Gender and Smoking Status

Suppose you have data on gender and smoking status (smoker or non-smoker) for a group of people. You want to know if smoking status is independent of gender.

```r
# Sample data: Gender (Male/Female) and Smoking Status (Smoker/Non-smoker)
data <- matrix(c(30, 10, 20, 40), nrow = 2, byrow = TRUE)

# Create a table with row and column names
dimnames(data) <- list(Gender = c("Male", "Female"), Smoking = c("Smoker", "Non-smoker"))

# View the data
data
```

This creates the following contingency table:

|        | Smoker | Non-smoker |
|--------|--------|------------|
| Male   | 30     | 10         |
| Female | 20     | 40         |

#### Conducting the Chi-Square Test

```r
# Perform the Chi-Square Test of Independence
chi_square_result <- chisq.test(data)

# View the results
print(chi_square_result)
```

Output will include:
- **Chi-squared statistic**: The value of the test statistic.
- **Degrees of freedom**: The number of independent pieces of information.
- **P-value**: The p-value indicates whether the result is statistically significant.

If the **p-value** is less than the significance level (commonly 0.05), you reject the null hypothesis, concluding that the two variables are dependent (associated).

### 2. Chi-Square Goodness of Fit Test

The **Goodness of Fit Test** is used to determine whether a sample comes from a population with a specific distribution. For example, testing whether a die is fair (each outcome is equally likely).

#### Example: Testing the Fairness of a Die

Suppose you roll a die 60 times, and you observe the following frequencies for each face:

- 1: 10
- 2: 12
- 3: 8
- 4: 9
- 5: 11
- 6: 10

You want to test whether the die is fair, meaning each face should appear 10 times.

```r
# Observed frequencies
observed <- c(10, 12, 8, 9, 11, 10)

# Expected frequencies for a fair die (each face should appear 10 times)
expected <- rep(10, 6)

# Perform the Chi-Square Goodness of Fit Test
chi_square_goodness_fit <- chisq.test(observed, p = expected / sum(expected))

# View the results
print(chi_square_goodness_fit)
```

Output will include:
- **Chi-squared statistic**: The calculated value of the test statistic.
- **Degrees of freedom**: Calculated as the number of categories minus 1.
- **P-value**: Indicates whether the observed frequencies significantly differ from the expected frequencies.

### Chi-Square Test Assumptions
- The data should be categorical (nominal or ordinal).
- The expected frequency in each category should be at least 5 for the Chi-Square approximation to be valid. If the expected frequencies are too low, you might need to combine some categories or use an alternative test (e.g., Fisher’s exact test).

### 3. Example: Multiple Chi-Square Tests on Real Data

Let's use the **`mtcars`** dataset to examine the association between the number of cylinders (`cyl`) and the number of gears (`gear`). We want to know if there is an association between these two categorical variables.

```r
# Convert 'cyl' and 'gear' into factors
mtcars$cyl <- factor(mtcars$cyl)
mtcars$gear <- factor(mtcars$gear)

# Create a contingency table
contingency_table <- table(mtcars$cyl, mtcars$gear)

# View the contingency table
print(contingency_table)

# Perform the Chi-Square Test of Independence
chi_square_result <- chisq.test(contingency_table)

# View the result
print(chi_square_result)
```

### Conclusion

The Chi-Square test in R is a useful tool for analyzing categorical data. Depending on the type of analysis, you can use:
- **Chi-Square Test of Independence** for testing if two categorical variables are independent.
- **Chi-Square Goodness of Fit Test** for testing if a sample matches a given distribution.

You perform these tests using the `chisq.test()` function, which provides a test statistic and p-value to evaluate the null hypothesis.
