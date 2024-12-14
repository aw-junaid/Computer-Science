### Binomial Distribution in R

The **binomial distribution** is a discrete probability distribution that models the number of successes in a fixed number of independent trials of a binary experiment (i.e., where each trial has two possible outcomes, often termed "success" and "failure"). It is widely used in statistics, particularly for modeling scenarios like coin tosses, quality control, and clinical trials.

The binomial distribution is defined by two parameters:
1. **n**: The number of trials (experiments).
2. **p**: The probability of success on each trial.

The probability mass function (PMF) for the binomial distribution is given by:

$\[
P(X = k) = \binom{n}{k} p^k (1-p)^{n-k}
\]$

Where:
- \( X \) is the number of successes,
- \( k \) is the number of successes observed (from 0 to n),
- $\( \binom{n}{k} \)$ is the binomial coefficient, also known as "n choose k," calculated as $\( \frac{n!}{k!(n-k)!} \)$,
- \( p \) is the probability of success on a single trial,
- $\( (1-p) \)$ is the probability of failure on a single trial.

### Functions for Working with Binomial Distribution in R

R provides several functions to work with the binomial distribution:
1. **`dbinom()`**: Probability mass function (PMF), to calculate the probability of observing exactly k successes.
2. **`pbinom()`**: Cumulative distribution function (CDF), to calculate the probability of observing up to k successes.
3. **`qbinom()`**: Quantile function, to find the number of successes corresponding to a given cumulative probability.
4. **`rbinom()`**: Random number generation, to simulate random outcomes from a binomial distribution.

### 1. **Probability Mass Function (PMF) using `dbinom()`**

The **`dbinom()`** function calculates the probability of getting exactly \( k \) successes in \( n \) trials. Its syntax is:

```r
dbinom(x, size, prob)
```

Where:
- `x`: The number of successes (can be a vector of values),
- `size`: The number of trials \( n \),
- `prob`: The probability of success on each trial \( p \).

#### Example:

Suppose we conduct an experiment with 10 trials (n = 10), and the probability of success on each trial is 0.5. We want to find the probability of getting exactly 3 successes.

```r
# Calculate the probability of getting exactly 3 successes
prob_3_successes <- dbinom(3, size = 10, prob = 0.5)
prob_3_successes
```

### 2. **Cumulative Distribution Function (CDF) using `pbinom()`**

The **`pbinom()`** function calculates the cumulative probability of observing up to \( k \) successes in \( n \) trials. The syntax is:

```r
pbinom(q, size, prob)
```

Where:
- `q`: The number of successes (up to which cumulative probability is calculated),
- `size`: The number of trials \( n \),
- `prob`: The probability of success on each trial \( p \).

#### Example:

Calculate the probability of getting **at most 3 successes** in 10 trials (with \( p = 0.5 \)):

```r
# Calculate the cumulative probability of getting at most 3 successes
cumulative_prob_3_successes <- pbinom(3, size = 10, prob = 0.5)
cumulative_prob_3_successes
```

### 3. **Quantile Function using `qbinom()`**

The **`qbinom()`** function finds the number of successes corresponding to a given cumulative probability. The syntax is:

```r
qbinom(p, size, prob)
```

Where:
- `p`: The cumulative probability,
- `size`: The number of trials \( n \),
- `prob`: The probability of success on each trial \( p \).

#### Example:

Suppose we want to find the smallest number of successes where the cumulative probability is at least 0.8 in 10 trials with \( p = 0.5 \):

```r
# Find the number of successes corresponding to the cumulative probability of 0.8
quantile_80 <- qbinom(0.8, size = 10, prob = 0.5)
quantile_80
```

### 4. **Random Number Generation using `rbinom()`**

The **`rbinom()`** function generates random numbers from a binomial distribution. Its syntax is:

```r
rbinom(n, size, prob)
```

Where:
- `n`: The number of random samples to generate,
- `size`: The number of trials \( n \),
- `prob`: The probability of success on each trial \( p \).

#### Example:

Generate 5 random values from a binomial distribution with 10 trials and a success probability of 0.5:

```r
# Generate 5 random numbers from a binomial distribution
random_values <- rbinom(5, size = 10, prob = 0.5)
random_values
```

### 5. **Plotting the Binomial Distribution**

You can visualize the binomial distribution by plotting the probability mass function (PMF) or by simulating a large number of trials and visualizing the outcomes.

#### Example: Plotting PMF

Let's plot the probability mass function (PMF) for a binomial distribution with \( n = 10 \) and \( p = 0.5 \) for the values of \( k \) from 0 to 10.

```r
# Set parameters
n <- 10
p <- 0.5

# Values of k
k <- 0:n

# Calculate probabilities using dbinom()
probabilities <- dbinom(k, size = n, prob = p)

# Plot the PMF
barplot(probabilities, names.arg = k, col = "skyblue", border = "white", main = "Binomial Distribution PMF", xlab = "Number of Successes", ylab = "Probability")
```

#### Example: Plotting CDF

To plot the cumulative distribution function (CDF), we can use the **`pbinom()`** function to calculate cumulative probabilities.

```r
# Calculate cumulative probabilities using pbinom()
cumulative_probabilities <- pbinom(k, size = n, prob = p)

# Plot the CDF
plot(k, cumulative_probabilities, type = "s", col = "red", main = "Binomial Distribution CDF", xlab = "Number of Successes", ylab = "Cumulative Probability")
```

### 6. **Example: Using the Binomial Distribution for a Real-World Scenario**

#### Scenario:
A factory produces light bulbs, and 95% of the light bulbs are good, while 5% are defective. A quality control inspector tests a batch of 20 bulbs. We want to calculate the probability that:
1. Exactly 2 bulbs are defective,
2. At most 3 bulbs are defective,
3. More than 5 bulbs are defective.

#### Solution:

```r
# Parameters
n <- 20  # Number of bulbs
p <- 0.05  # Probability of a defective bulb

# 1. Probability of exactly 2 defective bulbs
prob_2_defective <- dbinom(2, size = n, prob = p)

# 2. Probability of at most 3 defective bulbs
prob_at_most_3_defective <- pbinom(3, size = n, prob = p)

# 3. Probability of more than 5 defective bulbs (1 - P(X <= 5))
prob_more_than_5_defective <- 1 - pbinom(5, size = n, prob = p)

# Print results
prob_2_defective
prob_at_most_3_defective
prob_more_than_5_defective
```

### 7. **Binomial Distribution and the Central Limit Theorem**

As the number of trials increases, the binomial distribution starts to resemble a normal distribution (according to the Central Limit Theorem), especially when both \( n \) and \( p \) are not too close to 0 or 1. In such cases, the binomial distribution can be approximated by a normal distribution with:
- Mean $\( \mu = n \cdot p \)$
- Standard deviation $\( \sigma = \sqrt{n \cdot p \cdot (1 - p)} \)$

You can approximate a binomial distribution using a normal distribution in R when \( n \) is large enough.

### Conclusion

The binomial distribution is useful in modeling scenarios involving binary outcomes. In R, you can easily generate probabilities, simulate random outcomes, and visualize the distribution using functions like **`dbinom()`**, **`pbinom()`**, **`qbinom()`**, and **`rbinom()`**. It is especially useful in quality control, clinical trials, and various real-world scenarios involving fixed numbers of independent trials with binary outcomes.
