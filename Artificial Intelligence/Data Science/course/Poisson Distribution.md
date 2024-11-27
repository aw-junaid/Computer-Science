### Python - Poisson Distribution

The **Poisson distribution** is a discrete probability distribution that models the number of events that occur within a fixed interval of time or space, given that these events happen with a known constant mean rate and are independent of each other. It is particularly useful in situations where events are rare or infrequent.

The Poisson distribution is characterized by a single parameter:
- **λ (lambda)**: The average number of events in the given interval (mean rate).

The probability mass function (PMF) of the Poisson distribution is given by:

$\[
P(X = k) = \frac{\lambda^k e^{-\lambda}}{k!}
\]$

Where:
- \( k \) is the number of events (successes) that occurred in the interval.
- $\( \lambda \)$ is the average number of events (mean).
- $\( e \)$ is Euler's number (approximately 2.71828).

### Key Properties of the Poisson Distribution:
- **Mean**: $\( \mu = \lambda \)$
- **Variance**: $\( \sigma^2 = \lambda \)$
- **Standard Deviation**: $\( \sigma = \sqrt{\lambda} \)$

---

### 1. **Poisson Distribution in Python**

Python provides libraries such as **NumPy**, **SciPy**, and **Matplotlib** for working with Poisson distributions. These libraries allow you to generate random data, calculate probabilities, and visualize the Poisson distribution.

---

### 2. **Generating Random Data from a Poisson Distribution**

You can generate random data that follows a Poisson distribution using `numpy.random.poisson()` or `scipy.stats.poisson`.

#### Example: Generating Poisson Data

```python
import numpy as np

# Parameters
lambda_ = 4   # Average number of events
size = 1000   # Number of random samples

# Generate random data from a Poisson distribution
data = np.random.poisson(lambda_, size)

# Print the first 10 samples
print(data[:10])
```

This will generate 1000 random samples where the average number of events (λ) is 4.

---

### 3. **Visualizing the Poisson Distribution**

You can visualize the Poisson distribution using a histogram and compare it to the theoretical Poisson distribution using **Matplotlib**.

#### Example: Plotting the Histogram of Poisson Data

```python
import matplotlib.pyplot as plt

# Plot histogram of Poisson data
plt.hist(data, bins=range(min(data), max(data) + 1), density=True, alpha=0.6, color='b')

# Add labels and title
plt.title('Poisson Distribution - Histogram')
plt.xlabel('Number of Events')
plt.ylabel('Probability')

# Show the plot
plt.show()
```

This code will create a histogram of the Poisson data, showing the number of events on the x-axis and the probability on the y-axis.

---

### 4. **Poisson Probability Mass Function (PMF)**

You can calculate the probability of exactly \( k \) events occurring using the **Poisson PMF** from **SciPy**. The `poisson.pmf(k, lambda_)` function calculates the probability of exactly \( k \) events for a given \( \lambda \).

#### Example: Calculating the Probability of Exactly 3 Events

```python
from scipy.stats import poisson

# Calculate the probability of exactly 3 events for lambda = 4
k = 3
pmf_value = poisson.pmf(k, lambda_)
print(f"Probability of exactly {k} events: {pmf_value}")
```

This will give you the probability of observing exactly 3 events when the average number of events is 4.

---

### 5. **Poisson Cumulative Distribution Function (CDF)**

The **cumulative distribution function (CDF)** gives the probability of having \( k \) or fewer events. You can calculate this using `poisson.cdf(k, lambda_)`.

#### Example: Calculating the CDF for 3 or Fewer Events

```python
# Calculate the probability of 3 or fewer events for lambda = 4
cdf_value = poisson.cdf(k, lambda_)
print(f"Probability of 3 or fewer events: {cdf_value}")
```

This will return the cumulative probability of observing 3 or fewer events.

---

### 6. **Inverse CDF (Percentile Function)**

You can use the **inverse CDF** (percentile function) to find the smallest number of events \( k \) such that the cumulative probability is greater than or equal to a given probability. This can be done using `poisson.ppf()`.

#### Example: Finding the Number of Events for a Given Cumulative Probability

```python
# Calculate the number of events corresponding to the 90th percentile
probability = 0.90
percentile_value = poisson.ppf(probability, lambda_)
print(f"Number of events for 90th percentile: {percentile_value}")
```

This will return the smallest number of events \( k \) such that the cumulative probability is greater than or equal to 90%.

---

### 7. **Mean and Variance of Poisson Distribution**

The **mean** and **variance** of a Poisson distribution are both equal to \( \lambda \). You can compute these values directly from the parameter.

#### Example: Calculating Mean and Variance

```python
# Calculate the mean and variance
mean = lambda_
variance = lambda_

print(f"Mean: {mean}")
print(f"Variance: {variance}")
```

This will print the mean and variance for the Poisson distribution.

---

### 8. **Applications of Poisson Distribution**

The Poisson distribution is commonly used to model rare events and counting problems in various fields:
- **Queuing Theory**: It can model the number of customers arriving at a service desk or the number of calls received at a call center.
- **Traffic Flow**: Used in traffic engineering to model the number of cars arriving at a toll booth or passing a checkpoint.
- **Epidemiology**: Models the occurrence of rare diseases or the number of cases of a particular illness in a specific time period.
- **Physics**: Models the number of particles detected in a given time interval in particle physics experiments.
- **Telecommunications**: Models the number of packet arrivals or failures in a network.

---

### Example: Real-World Use Case

Suppose you are studying the number of calls received by a customer service center every hour, and on average, 5 calls are received per hour. You can model this scenario using the Poisson distribution.

```python
# Parameters
lambda_ = 5   # Average number of calls per hour
size = 1000   # Number of random samples

# Generate random data for number of calls per hour
calls = np.random.poisson(lambda_, size)

# Plot the histogram of the number of calls
plt.hist(calls, bins=range(min(calls), max(calls) + 1), density=True, alpha=0.6, color='r')

# Add labels and title
plt.title('Poisson Distribution - Calls per Hour')
plt.xlabel('Number of Calls')
plt.ylabel('Probability')

# Show the plot
plt.show()
```

This simulates 1000 hourly observations of call arrivals at a customer service center where the average number of calls per hour is 5. The histogram visualizes the distribution of the number of calls.

---

### Conclusion

The **Poisson distribution** is a useful model for rare events or events that occur with a known average rate over a fixed interval of time or space. Python's libraries, such as **NumPy**, **SciPy**, and **Matplotlib**, make it easy to generate random Poisson data, calculate probabilities, and visualize the distribution. Key operations you can perform with the Poisson distribution include:
- Generating random data from a Poisson distribution.
- Calculating probabilities using the PMF and CDF.
- Visualizing the distribution with histograms.
- Working with the inverse CDF (percentiles).
  
The Poisson distribution is widely used in various fields, including telecommunications, healthcare, traffic engineering, and more, to model the occurrence of rare events.
