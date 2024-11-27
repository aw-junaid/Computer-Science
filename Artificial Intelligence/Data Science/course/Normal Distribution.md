### Python - Normal Distribution

The **normal distribution** (also known as the Gaussian distribution) is one of the most important probability distributions in statistics. It is often used in the natural and social sciences to represent real-valued random variables whose distributions are not known. The normal distribution is characterized by its **bell-shaped curve** and is defined by two parameters:
- **Mean (µ)**: The center of the distribution (the peak).
- **Standard Deviation (σ)**: The spread of the distribution (how wide or narrow the curve is).

The probability density function (PDF) of a normal distribution is given by the formula:

$\[
f(x | \mu, \sigma) = \frac{1}{\sigma \sqrt{2 \pi}} e^{-\frac{(x-\mu)^2}{2\sigma^2}}
\]$

Where:
- $\( \mu \)$ is the mean.
- $\( \sigma \)$ is the standard deviation.
- $\( x \)$ is the value at which the function is evaluated.

---

### 1. **Normal Distribution in Python**

Python has several libraries, such as **NumPy**, **SciPy**, and **Matplotlib**, which make it easy to work with normal distributions. These libraries can help you generate random data that follows a normal distribution, visualize it, and calculate probabilities.

---

### 2. **Generating Random Data from a Normal Distribution**

#### Using NumPy

NumPy provides a function `numpy.random.normal()` to generate random samples from a normal distribution. It requires the mean, standard deviation, and number of samples.

```python
import numpy as np

# Parameters
mu = 0        # Mean
sigma = 1     # Standard deviation
size = 1000   # Number of random samples

# Generate random data from a normal distribution
data = np.random.normal(mu, sigma, size)

# Print the first 10 samples
print(data[:10])
```

---

### 3. **Visualizing the Normal Distribution**

You can visualize the normal distribution using a **histogram** and plot the **probability density function (PDF)** using **Matplotlib**.

#### Plotting the Histogram

```python
import matplotlib.pyplot as plt

# Plot histogram of the random data
plt.hist(data, bins=30, density=True, alpha=0.6, color='b')

# Add a title and labels
plt.title('Histogram of Normally Distributed Data')
plt.xlabel('Value')
plt.ylabel('Frequency')

# Show the plot
plt.show()
```

#### Plotting the Probability Density Function (PDF)

To plot the PDF, we can use the formula of the normal distribution and plot it using **Matplotlib**:

```python
import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm

# Create a range of values for x
x = np.linspace(-5, 5, 1000)

# Calculate the PDF for a normal distribution
pdf = norm.pdf(x, mu, sigma)

# Plot the PDF
plt.plot(x, pdf, label="Normal Distribution", color="r")
plt.title('Normal Distribution - PDF')
plt.xlabel('Value')
plt.ylabel('Density')
plt.legend()

# Show the plot
plt.show()
```

---

### 4. **Calculating Probabilities and Percentiles**

You can also calculate probabilities and percentiles from the normal distribution using functions from **SciPy**.

#### Cumulative Distribution Function (CDF)

The **CDF** of a normal distribution gives the probability that a random variable is less than or equal to a given value. You can calculate this using `scipy.stats.norm.cdf()`.

```python
from scipy.stats import norm

# Calculate the cumulative probability for a value
value = 1.0
cdf_value = norm.cdf(value, mu, sigma)
print(f"CDF at x = {value}: {cdf_value}")
```

This will give you the probability that a random variable from the normal distribution is less than or equal to 1.0.

#### Inverse CDF (Percentile Function)

You can calculate the **inverse CDF** (also known as the **percentile function**) using `scipy.stats.norm.ppf()` to find the value corresponding to a given cumulative probability.

```python
# Calculate the value corresponding to a cumulative probability (percentile)
probability = 0.95
percentile_value = norm.ppf(probability, mu, sigma)
print(f"Percentile value at P = {probability}: {percentile_value}")
```

This will give you the value \( x \) such that the probability of observing a value less than or equal to \( x \) is 95%.

---

### 5. **Z-Score**

The **Z-score** measures how many standard deviations a data point is from the mean. A Z-score of 0 indicates that the data point is exactly at the mean, while positive and negative values indicate how far the data point is from the mean in terms of standard deviations.

The Z-score formula is:

$\[
Z = \frac{X - \mu}{\sigma}
\]$

Where:
- \( X \) is the data point.
- $\( \mu \)$ is the mean.
- $\( \sigma \)$ is the standard deviation.

#### Calculating the Z-Score

```python
# Calculate the Z-score for a value
X = 1.5
z_score = (X - mu) / sigma
print(f"Z-score for X = {X}: {z_score}")
```

---

### 6. **Applications of Normal Distribution**

Normal distributions are widely used in many fields:
- **Finance**: In finance, the normal distribution is often used to model stock returns and asset prices.
- **Quality Control**: Many manufacturing processes assume a normal distribution of defects or variations in product measurements.
- **Psychometrics**: Intelligence test scores, such as IQ scores, are often assumed to follow a normal distribution.
- **Natural Sciences**: In physics and biology, many measurements (like heights, weights, or test results) are assumed to follow a normal distribution.

---

### 7. **Example: Real-World Data Simulation**

Let's say you are simulating test scores for a class. You can assume the scores follow a normal distribution with a mean of 75 and a standard deviation of 10.

```python
# Parameters
mu = 75        # Mean of test scores
sigma = 10     # Standard deviation of test scores
size = 500     # Number of students

# Generate random test scores
test_scores = np.random.normal(mu, sigma, size)

# Plot the histogram of test scores
plt.hist(test_scores, bins=30, density=True, alpha=0.6, color='g')

# Add a title and labels
plt.title('Test Scores Distribution (Normal Distribution)')
plt.xlabel('Test Score')
plt.ylabel('Density')

# Show the plot
plt.show()
```

This will simulate 500 test scores that follow a normal distribution and display a histogram of the distribution.

---

### Conclusion

The **normal distribution** is a fundamental concept in statistics, and Python provides powerful libraries like **NumPy**, **SciPy**, and **Matplotlib** to easily generate, analyze, and visualize normally distributed data. Key operations you can perform with a normal distribution in Python include:
- Generating random data following a normal distribution.
- Visualizing the distribution using histograms and PDFs.
- Calculating probabilities and percentiles using the CDF and inverse CDF.
- Working with Z-scores for standardization and comparison of data points.

The normal distribution plays a critical role in many real-world applications, including finance, quality control, and the natural and social sciences.
