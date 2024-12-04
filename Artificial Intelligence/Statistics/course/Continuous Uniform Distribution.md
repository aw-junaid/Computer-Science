### **Continuous Uniform Distribution**

The **continuous uniform distribution** is a type of probability distribution where all outcomes are equally likely to occur within a specified range. In other words, the probability of the random variable taking any value within a given interval is the same for all values in that interval.

### **Definition:**

For a continuous random variable \( X \) that follows a uniform distribution over an interval \([a, b]\), the probability density function (PDF) is defined as:

```math
f(x) =
\begin{cases}
\frac{1}{b - a} & \text{if } a \leq x \leq b \\
0 & \text{otherwise}
\end{cases}
```

Where:
- \( a \) and \( b \) are the lower and upper bounds of the distribution, respectively.
- The term $\( \frac{1}{b - a} \)$ ensures that the total area under the curve (the integral of the PDF) equals 1, which is a requirement for any probability distribution.

### **Key Properties:**

1. **Mean (Expected Value)**:
   The expected value (mean) of a continuous uniform distribution is the midpoint of the interval \([a, b]\), given by:

   $\[
   \mu = \frac{a + b}{2}
   \]$

2. **Variance**:
   The variance of a continuous uniform distribution measures how spread out the values are. It is calculated as:

   $\[
   \sigma^2 = \frac{(b - a)^2}{12}
   \]$

3. **Standard Deviation**:
   The standard deviation, which is the square root of the variance, is:

   $\[
   \sigma = \frac{b - a}{\sqrt{12}}
   \]$

4. **Cumulative Distribution Function (CDF)**:
   The cumulative distribution function (CDF) for a continuous uniform distribution is given by:

```math
   F(x) =
   \begin{cases}
   0 & \text{if } x < a \\
   \frac{x - a}{b - a} & \text{if } a \leq x \leq b \\
   1 & \text{if } x > b
   \end{cases}
```

   The CDF gives the probability that the random variable \( X \) takes a value less than or equal to \( x \).

5. **Probability Calculation**:
   To calculate the probability that the random variable falls within a specific range, say between \( x_1 \) and \( x_2 \) (where $\( a \leq x_1 < x_2 \leq b \)$), we can use the CDF:

   $\[
   P(x_1 \leq X \leq x_2) = F(x_2) - F(x_1) = \frac{x_2 - x_1}{b - a}
   \]$

   This is a straightforward calculation since the probability is uniformly distributed across the interval.

### **Example of Continuous Uniform Distribution:**

Suppose a random variable \( X \) is uniformly distributed between 0 and 10, i.e., \( a = 0 \) and \( b = 10 \).

- **PDF**: The probability density function would be:

  $\[
  f(x) = \frac{1}{10 - 0} = \frac{1}{10} \quad \text{for} \quad 0 \leq x \leq 10
  \]$

- **Mean (Expected Value)**:

  $\[
  \mu = \frac{0 + 10}{2} = 5
  \]$

- **Variance**:

  $\[
  \sigma^2 = \frac{(10 - 0)^2}{12} = \frac{100}{12} \approx 8.33
  \]$

- **Standard Deviation**:

  $\[
  \sigma = \sqrt{\frac{100}{12}} \approx 2.89
  \]$

- **CDF**: The CDF would be:

```math
  F(x) =
  \begin{cases}
  0 & \text{if } x < 0 \\
  \frac{x}{10} & \text{if } 0 \leq x \leq 10 \\
  1 & \text{if } x > 10
  \end{cases}
```

### **Visualizing the Continuous Uniform Distribution:**

The graph of the PDF of a continuous uniform distribution is a **rectangle** (constant height) over the interval $\([a, b]\)$. The height of the rectangle is $\( \frac{1}{b - a} \)$, and it spans from \( a \) to \( b \).

- The CDF, on the other hand, is a straight line starting from 0 at \( x = a \), increasing linearly to 1 at \( x = b \).

### **Applications of Continuous Uniform Distribution:**

1. **Random Number Generation**: A common use of the continuous uniform distribution is in the generation of random numbers. For example, if you need to generate random numbers between \( a \) and \( b \), you can use a uniform distribution.

2. **Simulation and Modeling**: In simulations where outcomes are equally likely over a specified range, the continuous uniform distribution is often used as a basic model.

3. **Decision Making and Uncertainty**: In situations where there is no reason to favor one outcome over another within a given range (e.g., making a random selection from a continuous range), a uniform distribution is appropriate.

4. **Game Theory and Random Sampling**: When outcomes in a game or experiment are equally probable, or in sampling techniques where each outcome has an equal chance of being selected, the continuous uniform distribution may be applied.

### **Conclusion:**

The continuous uniform distribution is one of the simplest and most fundamental probability distributions, with applications in various fields such as simulation, random number generation, and decision-making. Its key characteristic is that all outcomes within a specified interval are equally likely, making it a useful model in situations of complete randomness.
