### **Cumulative Poisson Distribution**

The **Cumulative Poisson Distribution** is the distribution that gives the probability that a Poisson random variable takes a value less than or equal to a certain number. It is used to model the cumulative probability of events occurring in a fixed interval of time or space, given a known average rate of occurrence.

### **Poisson Distribution Overview**

The **Poisson distribution** models the number of events that occur in a fixed interval of time or space, with the following characteristics:
- Events occur independently.
- The average rate of occurrence (denoted by $\( \lambda \))$ is constant over time or space.
- The probability of more than one event occurring in an infinitesimally small interval is negligible.

The probability mass function (PMF) of the Poisson distribution for a random variable \( X \), which represents the number of events, is given by:

$\[
P(X = k) = \frac{\lambda^k e^{-\lambda}}{k!}, \quad k = 0, 1, 2, \dots
\]$

Where:
- $\( \lambda \)$ is the mean number of occurrences (the rate parameter).
- \( k \) is the number of events.
- \( e \) is Euler's number $(\( \approx 2.71828 \))$.

### **Cumulative Poisson Distribution**

The **cumulative Poisson distribution** is the probability that a Poisson random variable \( X \) takes a value less than or equal to \( k \). It is the sum of the individual Poisson probabilities up to \( k \), and it can be expressed as:

$\[
P(X \leq k) = \sum_{i=0}^{k} \frac{\lambda^i e^{-\lambda}}{i!}
\]$

Where:
- $\( P(X \leq k) \)$ is the cumulative probability that \( X \) is less than or equal to \( k \).
- $\( \lambda \)$ is the mean rate of occurrences.
- \( k \) is the maximum number of occurrences.

This cumulative probability can be used to determine how likely it is that a given number of events will occur in a Poisson process, considering all values up to \( k \).

### **Example Calculation of Cumulative Poisson Probability:**

Let's say you are modeling the number of cars that arrive at a toll booth per hour, and the average rate of arrival is \( \lambda = 3 \) cars per hour. You want to find the cumulative probability that 2 or fewer cars arrive in an hour, i.e., \( P(X \leq 2) \).

#### **Step 1: Write out the Poisson probabilities for \( k = 0, 1, 2 \)**

The Poisson PMF is:

$\[
P(X = k) = \frac{\lambda^k e^{-\lambda}}{k!}
\]$

For $\( \lambda = 3 \)$:

- $\( P(X = 0) = \frac{3^0 e^{-3}}{0!} = \frac{1 \cdot e^{-3}}{1} = e^{-3} \approx 0.0498 \)$
- $\( P(X = 1) = \frac{3^1 e^{-3}}{1!} = \frac{3 \cdot e^{-3}}{1} = 3e^{-3} \approx 0.1494 \)$
- $\( P(X = 2) = \frac{3^2 e^{-3}}{2!} = \frac{9 \cdot e^{-3}}{2} = 4.5e^{-3} \approx 0.2240 \)$

#### **Step 2: Calculate the cumulative probability \( P(X \leq 2) \)**

$\[
P(X \leq 2) = P(X = 0) + P(X = 1) + P(X = 2)
\]$

$\[
P(X \leq 2) = 0.0498 + 0.1494 + 0.2240 = 0.4232
\]$

So, the cumulative probability that 2 or fewer cars arrive at the toll booth in an hour is approximately **0.4232**, or **42.32%**.

### **Key Points About the Cumulative Poisson Distribution:**

1. **Poisson CDF (Cumulative Distribution Function)**: 
   The CDF of a Poisson random variable \( X \), given the rate parameter $\( \lambda \)$, is simply the sum of the individual probabilities from \( k = 0 \) to \( k = k \).

2. **Useful for Small Number of Events**: 
   The cumulative Poisson distribution is especially useful when you want to compute the probability of observing fewer than or equal to a certain number of events, for instance, in situations where the rate of events is low (e.g., calls to a call center, defects in a batch of products).

3. **Applications**:
   - **Queuing theory**: Modeling the number of customers in line at a service point.
   - **Traffic flow**: Modeling the number of cars passing a certain point.
   - **Call centers**: Modeling the number of incoming calls during a given time interval.
   - **Natural phenomena**: Such as the number of meteorites striking Earth within a specific area and time.

4. **Computational Tools**:
   For more complex cases, especially with larger $\( \lambda \)$ or \( k \), the cumulative Poisson distribution is often calculated using statistical software or functions like `poisson.cdf(k, lambda)` in Python (using libraries like SciPy) or Excel’s built-in `POISSON.DIST(x, mean, cumulative)` function.

### **Applications and Examples:**
1. **Example 1: Car Arrivals**
   - Suppose the average number of cars arriving at a toll booth per hour is 3. What is the probability that 0, 1, or 2 cars arrive in the next hour?
     - This would use the Cumulative Poisson Distribution as shown above.

2. **Example 2: Call Center**
   - If a call center receives an average of 5 calls per minute, what is the probability of receiving 3 or fewer calls in the next minute?
     - Here, the cumulative probability $\( P(X \leq 3) \)$ would be computed using the Poisson formula.

3. **Example 3: Defects in Manufacturing**
   - In a manufacturing process, if on average 2 defects occur per batch of products, what is the probability that there will be fewer than 3 defects in a batch?
     - You would calculate $\( P(X \leq 2) \)$, where \( X \) is the number of defects.

### **Conclusion:**
The **Cumulative Poisson Distribution** provides the cumulative probability for a Poisson-distributed random variable, helping quantify the likelihood of observing a number of events less than or equal to a given value. It is widely used in fields like queuing theory, traffic flow analysis, telecommunications, and reliability engineering. By summing the Poisson probabilities for each possible value up to \( k \), it helps answer questions about how likely it is to see a certain number of events in a given interval.
