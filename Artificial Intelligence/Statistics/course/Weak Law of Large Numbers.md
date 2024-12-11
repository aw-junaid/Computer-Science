### **Statistics - Weak Law of Large Numbers (WLLN)**

The **Weak Law of Large Numbers (WLLN)** is a fundamental theorem in probability and statistics that describes the behavior of sample averages as the sample size increases. It states that as the size of a sample drawn from a population increases, the sample mean will tend to get closer to the population mean.

### **Statement of the Weak Law of Large Numbers:**

For a sequence of independent, identically distributed (i.i.d.) random variables $\( X_1, X_2, X_3, \dots \)$ with a finite expected value $\( \mu = E[X_i] \)$, the sample mean $\( \bar{X}_n \)$ (average of the first \( n \) observations) converges in probability to the population mean \( \mu \) as \( n \) approaches infinity. Mathematically, this is expressed as:

$\[
P\left( \left| \bar{X}_n - \mu \right| \geq \epsilon \right) \to 0 \quad \text{as} \quad n \to \infty
\]$

Where:
- $\( \bar{X}_n = \frac{1}{n} \sum_{i=1}^{n} X_i \)$ is the sample mean of the first \( n \) observations.
- $\( \mu = E[X_i] \)$ is the population mean (expected value) of the random variable.
- $\( \epsilon \)$ is any positive number.
- \( n \) is the sample size.

### **Interpretation:**
- The WLLN tells us that as the sample size \( n \) increases, the probability that the sample mean $\( \bar{X}_n \)$ deviates from the true population mean $\( \mu \)$ by a large amount becomes smaller.
- In other words, the sample mean will get closer and closer to the population mean as the number of observations increases.
- This convergence is **in probability**, meaning that for any $\( \epsilon > 0 \)$, the probability that the difference between the sample mean and the population mean exceeds $\( \epsilon \)$ becomes arbitrarily small as \( n \) grows.

### **Key Characteristics:**
- **Independence and Identical Distribution**: The variables in the sample must be independent and come from the same distribution with the same mean and variance.
- **Convergence in Probability**: The WLLN describes **convergence in probability** rather than **almost sure convergence**, which means that the sample mean does not necessarily equal the population mean, but it gets closer as the sample size increases.
- **Finite Mean**: The theorem applies when the population has a finite mean (and variance, though variance is not strictly required for the WLLN).

### **Example of Weak Law of Large Numbers:**

Suppose we flip a fair coin and define a random variable \( X_i \) such that:
- $\( X_i = 1 \)$ if the coin lands heads.
- $\( X_i = 0 \)$ if the coin lands tails.

The expected value (population mean) $\( \mu \)$ of $\( X_i \)$ is:

$\[
\mu = E[X_i] = 0.5
\]$

Now, let's consider a sample of size \( n \) (e.g., flipping the coin \( n \) times). The sample mean $\( \bar{X}_n \)$ is the proportion of heads observed in the \( n \) flips.

- According to the Weak Law of Large Numbers, as \( n \) increases, the sample mean $\( \bar{X}_n \)$ will approach the true probability of landing heads, which is 0.5.
- For example, after 10 flips, the proportion of heads might be 0.6, but as you flip the coin more times (e.g., 100 or 1,000 flips), the sample mean will get closer to 0.5.

### **Why "Weak" Law?**

The **"weak"** in the Weak Law of Large Numbers refers to **convergence in probability** rather than **almost sure convergence** (which is the concept behind the Strong Law of Large Numbers). While the WLLN ensures that the sample mean will be close to the population mean with high probability as the sample size grows, it does not guarantee that the sample mean will always converge to the population mean (as the Strong Law would).

### **Comparison with Strong Law of Large Numbers (SLLN):**

- **Weak Law of Large Numbers**: Convergence of the sample mean to the population mean happens in probability. The sample mean can still deviate from the population mean by some margin, but the probability of large deviations decreases as the sample size increases.
- **Strong Law of Large Numbers**: Convergence is almost sure, meaning that with probability 1, the sample mean will eventually equal the population mean as the sample size becomes large.

### **Conclusion:**

The Weak Law of Large Numbers is an essential result in probability theory that helps explain why, in practice, increasing the size of a sample will lead to more accurate estimates of the population mean. The WLLN assures that as more data is collected, the sample mean will likely get closer to the true mean of the population. This is a key concept in fields such as statistics, economics, and data science, where large sample sizes are often used to make reliable predictions and inferences.
