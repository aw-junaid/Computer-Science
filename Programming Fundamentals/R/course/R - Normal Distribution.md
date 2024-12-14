### Normal Distribution in R

The **normal distribution** (also called the **Gaussian distribution**) is one of the most widely used probability distributions in statistics. It is a continuous probability distribution that is symmetric around the mean. The graph of the normal distribution forms a bell-shaped curve, where the highest point corresponds to the mean (µ), and the spread of the distribution is determined by the standard deviation (σ).

The **normal distribution** has several important properties:
- The mean, median, and mode of the distribution are all equal.
- The total area under the curve is 1.
- The distribution is symmetric about the mean.
- The empirical rule (68-95-99.7 rule) states that approximately:
  - 68% of the data falls within one standard deviation of the mean.
  - 95% of the data falls within two standard deviations.
  - 99.7% of the data falls within three standard deviations.

The probability density function (PDF) of the normal distribution is given by:

$\[
f(x) = \frac{1}{\sigma \sqrt{2\pi}} e^{-\frac{(x-\mu)^2}{2\sigma^2}}
\]$

Where:
- $\( \mu \)$ is the mean,
- $\( \sigma \)$ is the standard deviation,
- \( x \) is a point in the distribution.

### Steps for Working with Normal Distribution in R

R provides several functions for working with normal distribution. These functions are part of R's base package.

1. **Generating Random Numbers from a Normal Distribution**:
   Use the `rnorm()` function to generate random numbers from a normal distribution.
   
2. **Calculating the Probability Density**:
   Use the `dnorm()` function to compute the probability density (value of the PDF) at a specific point.

3. **Calculating Cumulative Probability**:
   Use the `pnorm()` function to calculate the cumulative probability (area under the curve to the left of a value).

4. **Quantiles of the Distribution**:
   Use the `qnorm()` function to find the value (quantile) corresponding to a given cumulative probability.

### 1. **Generating Random Numbers from a Normal Distribution**

To generate random numbers from a normal distribution, you can use the **`rnorm()`** function. The syntax is:

```r
rnorm(n, mean = 0, sd = 1)
```

Where:
- `n` is the number of random numbers to generate,
- `mean` is the mean of the distribution,
- `sd` is the standard deviation of the distribution.

#### Example:

```r
# Generate 1000 random numbers from a normal distribution with mean = 50 and sd = 10
random_numbers <- rnorm(1000, mean = 50, sd = 10)

# View the first few generated numbers
head(random_numbers)
```

This will generate 1000 random numbers with a mean of 50 and a standard deviation of 10.

### 2. **Plotting the Normal Distribution**

You can visualize the normal distribution using a histogram along with a density curve. For example, using the `random_numbers` from the previous example:

```r
# Plot the histogram of the generated random numbers
hist(random_numbers, probability = TRUE, col = "lightblue", border = "white", main = "Normal Distribution", xlab = "Value")

# Add the density curve
lines(density(random_numbers), col = "red", lwd = 2)
```

This will plot the histogram of the random numbers, and overlay a red density curve that approximates the normal distribution.

### 3. **Calculating the Probability Density**

To calculate the probability density of a given value from the normal distribution, use the **`dnorm()`** function. The syntax is:

```r
dnorm(x, mean = 0, sd = 1)
```

Where:
- `x` is the value for which you want to calculate the density,
- `mean` is the mean of the distribution,
- `sd` is the standard deviation of the distribution.

#### Example:

```r
# Calculate the probability density at x = 50 for a normal distribution with mean = 50 and sd = 10
prob_density <- dnorm(50, mean = 50, sd = 10)
prob_density
```

### 4. **Calculating the Cumulative Probability**

The **`pnorm()`** function is used to calculate the cumulative probability (i.e., the area under the normal curve to the left of a value). The syntax is:

```r
pnorm(q, mean = 0, sd = 1)
```

Where:
- `q` is the value for which you want to find the cumulative probability,
- `mean` is the mean of the distribution,
- `sd` is the standard deviation of the distribution.

#### Example:

```r
# Calculate the cumulative probability up to x = 50 for a normal distribution with mean = 50 and sd = 10
cumulative_prob <- pnorm(50, mean = 50, sd = 10)
cumulative_prob
```

This gives the probability that a randomly chosen value from the distribution is less than or equal to 50.

### 5. **Finding Quantiles of the Distribution**

The **`qnorm()`** function is used to find the quantile corresponding to a given cumulative probability. The syntax is:

```r
qnorm(p, mean = 0, sd = 1)
```

Where:
- `p` is the cumulative probability,
- `mean` is the mean of the distribution,
- `sd` is the standard deviation of the distribution.

#### Example:

```r
# Find the value that corresponds to the cumulative probability of 0.95 for a normal distribution with mean = 50 and sd = 10
quantile_value <- qnorm(0.95, mean = 50, sd = 10)
quantile_value
```

This will give the value corresponding to the 95th percentile of the normal distribution.

### 6. **Normal Distribution in Hypothesis Testing**

One of the common uses of the normal distribution is in hypothesis testing. For example, you might use it in a **Z-test** to compare the sample mean to a population mean. The Z-test assumes that the data is normally distributed.

To perform a Z-test in R:
- Calculate the **Z-score**: \( Z = \frac{X - \mu}{\sigma} \), where \( X \) is the sample mean, \( \mu \) is the population mean, and \( \sigma \) is the population standard deviation.
- Use the **`pnorm()`** function to find the cumulative probability associated with the Z-score.

#### Example of Z-test:

```r
# Suppose the population mean is 50, and the standard deviation is 10. A sample mean of 55
# We want to test if the sample mean is significantly different from the population mean.

population_mean <- 50
population_sd <- 10
sample_mean <- 55
sample_size <- 30

# Calculate the Z-score
z_score <- (sample_mean - population_mean) / (population_sd / sqrt(sample_size))

# Calculate the cumulative probability (p-value)
p_value <- 1 - pnorm(z_score)  # For a one-tailed test
p_value
```

### 7. **Normal Distribution and the Empirical Rule**

The **Empirical Rule** states that:
- 68% of the data falls within 1 standard deviation of the mean,
- 95% falls within 2 standard deviations,
- 99.7% falls within 3 standard deviations.

In R, you can verify this using the **`pnorm()`** function:

```r
# Calculate cumulative probability within 1, 2, and 3 standard deviations of the mean
prob_1_sd <- pnorm(50 + 1*10, mean = 50, sd = 10) - pnorm(50 - 1*10, mean = 50, sd = 10)
prob_2_sd <- pnorm(50 + 2*10, mean = 50, sd = 10) - pnorm(50 - 2*10, mean = 50, sd = 10)
prob_3_sd <- pnorm(50 + 3*10, mean = 50, sd = 10) - pnorm(50 - 3*10, mean = 50, sd = 10)

prob_1_sd  # Should be approximately 0.68
prob_2_sd  # Should be approximately 0.95
prob_3_sd  # Should be approximately 0.997
```

### 8. **Conclusion**

The normal distribution is a fundamental concept in statistics and is used in many fields for analysis and inference. In R, you can easily generate random data, compute probabilities, and visualize the normal distribution using built-in functions like **`rnorm()`**, **`dnorm()`**, **`pnorm()`**, and **`qnorm()`**. These tools are essential for hypothesis testing, data modeling, and understanding the underlying structure of real-world data that often follows a normal distribution.
