### Python - Bernoulli Distribution

The **Bernoulli distribution** is a discrete probability distribution that models a random experiment with exactly two outcomes: "success" (often labeled as 1) and "failure" (often labeled as 0). The Bernoulli distribution is a special case of the binomial distribution where only one trial is conducted.

The Bernoulli distribution is characterized by a single parameter:
- **p**: The probability of success (the probability of getting a 1).
- The probability of failure (getting a 0) is $\( 1 - p \)$.

The probability mass function (PMF) of the Bernoulli distribution is given by:

```math
P(X = x) = 
\begin{cases} 
p & \text{if } x = 1 \\
1 - p & \text{if } x = 0
\end{cases}
```

Where:
- \( x \) is the random variable, which can either be 0 (failure) or 1 (success).
- \( p \) is the probability of success (getting a 1).

### Key Properties of the Bernoulli Distribution:
- **Mean**: $\( \mu = p \)$
- **Variance**: $\( \sigma^2 = p(1 - p) \)$
- **Standard Deviation**: $\( \sigma = \sqrt{p(1 - p)} \)$

### Applications of Bernoulli Distribution:
- **Coin toss**: A simple example of a Bernoulli distribution is flipping a coin, where the outcome can be either heads (success) or tails (failure), and the probability of heads (success) is \( p = 0.5 \).
- **Quality control**: In manufacturing, it can be used to model whether a product is defective (failure) or non-defective (success).
- **Binary classification**: In machine learning, Bernoulli distribution is used when the target variable has two possible classes (e.g., yes/no, true/false).

---

### 1. **Bernoulli Distribution in Python**

Python provides libraries such as **NumPy**, **SciPy**, and **Matplotlib** to work with the Bernoulli distribution. The most common function for working with Bernoulli data is `numpy.random.binomial()` with \( n = 1 \), or `scipy.stats.bernoulli()`.

---

### 2. **Generating Random Data from a Bernoulli Distribution**

You can generate random data from a Bernoulli distribution using `numpy.random.binomial()` with \( n = 1 \) (since it's just one trial) or `scipy.stats.bernoulli()`.

#### Example: Generating Bernoulli Data with NumPy

```python
import numpy as np

# Parameters
p = 0.7    # Probability of success
size = 1000 # Number of random samples

# Generate random data from a Bernoulli distribution
data = np.random.binomial(1, p, size)

# Print the first 10 samples
print(data[:10])
```

This will generate 1000 random samples where each sample represents the outcome of a Bernoulli trial with a success probability \( p = 0.7 \).

---

### 3. **Visualizing the Bernoulli Distribution**

You can visualize the Bernoulli distribution by plotting a bar chart showing the proportion of successes (1s) and failures (0s) in the generated data.

#### Example: Plotting the Distribution of Bernoulli Data

```python
import matplotlib.pyplot as plt

# Plot the distribution of Bernoulli data
plt.hist(data, bins=2, density=True, alpha=0.6, color='g')

# Add labels and title
plt.title('Bernoulli Distribution - Histogram')
plt.xlabel('Outcome (0 or 1)')
plt.ylabel('Probability')

# Show the plot
plt.show()
```

This will display a bar chart showing the probability of success (1) and failure (0).

---

### 4. **Bernoulli Probability Mass Function (PMF)**

You can calculate the probability of observing either a success or a failure using the **Bernoulli PMF**. The PMF can be computed directly using the formula:

- $\( P(X = 1) = p \)$
- $\( P(X = 0) = 1 - p \)$

Alternatively, you can use `scipy.stats.bernoulli.pmf()` to calculate the PMF for a specific outcome.

#### Example: Calculating the Probability of Success (1)

```python
from scipy.stats import bernoulli

# Calculate the probability of success (X=1)
p_success = bernoulli.pmf(1, p)
print(f"Probability of success (X=1): {p_success}")

# Calculate the probability of failure (X=0)
p_failure = bernoulli.pmf(0, p)
print(f"Probability of failure (X=0): {p_failure}")
```

This will give you the probability of success (1) and failure (0) for the Bernoulli distribution.

---

### 5. **Cumulative Distribution Function (CDF)**

The **cumulative distribution function (CDF)** gives the probability of having 0 or fewer successes. You can calculate the CDF using `bernoulli.cdf()`.

#### Example: Calculating the CDF for \( X = 0 \) and \( X = 1 \)

```python
# Calculate the cumulative probability for X = 0 (failure)
cdf_failure = bernoulli.cdf(0, p)
print(f"Probability of failure (CDF for X=0): {cdf_failure}")

# Calculate the cumulative probability for X = 1 (success)
cdf_success = bernoulli.cdf(1, p)
print(f"Probability of success (CDF for X=1): {cdf_success}")
```

This will give you the cumulative probability for observing up to 0 or 1 success.

---

### 6. **Inverse CDF (Percentile Function)**

The **inverse CDF** (percentile function) can be used to find the smallest value of \( X \) such that the cumulative probability is greater than or equal to a specified value. This is available using `bernoulli.ppf()`.

#### Example: Finding the Smallest \( X \) for a Given Probability

```python
# Find the value of X corresponding to the 70th percentile
percentile_value = bernoulli.ppf(0.70, p)
print(f"Smallest X corresponding to the 70th percentile: {percentile_value}")
```

Since the Bernoulli distribution only has two possible outcomes, this function will return either 0 or 1 based on the given probability.

---

### 7. **Mean and Variance of Bernoulli Distribution**

The **mean** and **variance** of a Bernoulli distribution can be calculated using the formulas:
- Mean: $\( \mu = p \)$
- Variance: $\( \sigma^2 = p(1 - p) \)$

#### Example: Calculating Mean and Variance

```python
# Calculate the mean and variance of the Bernoulli distribution
mean = p
variance = p * (1 - p)

print(f"Mean: {mean}")
print(f"Variance: {variance}")
```

This will print the mean and variance for the given Bernoulli distribution.

---

### 8. **Applications of Bernoulli Distribution**

The **Bernoulli distribution** is used in various applications, especially in situations involving binary outcomes:
- **Coin Toss**: A standard example of a Bernoulli trial where the outcome is either heads (success) or tails (failure).
- **Machine Learning**: Used for binary classification problems, where the target variable has two possible classes (e.g., 0 or 1, true or false).
- **Quality Control**: In manufacturing, where the outcome is either a defective product (failure) or a non-defective product (success).
- **Finance**: In risk modeling, where an event such as a default (failure) or no default (success) is modeled.
- **Epidemiology**: Modeling the presence or absence of a disease or condition in a population.

---

### Example: Real-World Use Case

Suppose you are studying the success rate of a new marketing campaign where the probability of success (a customer purchasing a product) is 0.3. You can model the outcome of a single trial (whether the customer makes a purchase or not) using a Bernoulli distribution.

```python
# Parameters
p = 0.3  # Probability of success (customer makes a purchase)
size = 1000  # Number of trials

# Generate random data for the Bernoulli trials
purchases = np.random.binomial(1, p, size)

# Plot the histogram of the number of purchases
plt.hist(purchases, bins=2, density=True, alpha=0.6, color='orange')

# Add labels and title
plt.title('Bernoulli Distribution - Marketing Campaign')
plt.xlabel('Outcome (0: No Purchase, 1: Purchase)')
plt.ylabel('Probability')

# Show the plot
plt.show()
```

This will simulate 1000 trials of the marketing campaign and display the distribution of successes (purchases) and failures (no purchases).

---

### Conclusion

The **Bernoulli distribution** is a simple yet fundamental probability distribution used to model binary outcomes in various fields such as quality control, machine learning, and finance. Python's libraries, such as **NumPy**, **SciPy**, and **Matplotlib**, provide powerful tools for generating, analyzing, and visualizing Bernoulli data. Key operations include:
- Generating Bernoulli data using `numpy.random.binomial()` or `scipy

.stats.bernoulli()`.
- Calculating probabilities using the PMF and CDF.
- Visualizing the distribution with histograms.
- Calculating mean and variance.

The Bernoulli distribution serves as the foundation for more complex probability distributions, such as the **binomial distribution**.
