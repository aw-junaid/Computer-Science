### **Hypergeometric Distribution in Statistics**

The **hypergeometric distribution** is a probability distribution that describes the likelihood of a specific number of successes in a sample drawn without replacement from a finite population. Unlike the **binomial distribution**, which assumes sampling with replacement, the hypergeometric distribution is used when the sample is drawn without replacement.

### **Key Characteristics**

- **Population Size (N)**: The total number of items in the population.
- **Number of Successes in Population (K)**: The number of items in the population that are considered "successes."
- **Sample Size (n)**: The number of items drawn (sampled) from the population.
- **Number of Successes in Sample (k)**: The number of successes observed in the sample.

The hypergeometric distribution is used to calculate the probability of getting exactly **k successes** when you draw **n items** from a population of **N** items that contains **K successes**, without replacement.

### **Probability Mass Function (PMF)**

The probability of getting exactly **k successes** in a sample of size **n** from a population of size **N** with **K successes** is given by the hypergeometric probability mass function (PMF):

$\[
P(X = k) = \frac{\binom{K}{k} \binom{N-K}{n-k}}{\binom{N}{n}}
\]$

Where:
- $\( \binom{K}{k} \)$ is the number of ways to choose **k successes** from the **K successes** in the population.
- $\( \binom{N-K}{n-k} \)$ is the number of ways to choose the remaining **n-k** items from the **N-K** non-successes.
- $\( \binom{N}{n} \)$ is the total number of ways to choose **n items** from the total population of size **N**.

### **Conditions for Hypergeometric Distribution**

1. **Finite Population**: The population is finite and has a known size.
2. **No Replacement**: The sample is drawn without replacement, meaning that once an item is selected, it cannot be selected again.
3. **Success and Failure Categories**: Each item in the population must either be a success or a failure.

### **Example of Hypergeometric Distribution**

Consider a population of 10 balls, where 4 are red (successes) and 6 are blue (failures). Suppose you randomly select 4 balls from this population without replacement. We want to find the probability of drawing exactly 2 red balls (successes) in the sample of 4.

Given:
- Total population size, \(N = 10\)
- Number of red balls (successes), \(K = 4\)
- Sample size, \(n = 4\)
- Desired number of red balls in the sample, \(k = 2\)

The probability is calculated using the hypergeometric PMF:

$\[
P(X = 2) = \frac{\binom{4}{2} \binom{6}{2}}{\binom{10}{4}}
\]$

Where:
- $\( \binom{4}{2} = \frac{4 \times 3}{2 \times 1} = 6 \)$
- $\( \binom{6}{2} = \frac{6 \times 5}{2 \times 1} = 15 \)$
- $\( \binom{10}{4} = \frac{10 \times 9 \times 8 \times 7}{4 \times 3 \times 2 \times 1} = 210 \)$

So:

$\[
P(X = 2) = \frac{6 \times 15}{210} = \frac{90}{210} = 0.4286
\]$

Therefore, the probability of drawing exactly 2 red balls in the sample is approximately **0.4286** (or **42.86%**).

### **Expected Value and Variance**

For the hypergeometric distribution, the **expected value** (mean) and **variance** are given by the following formulas:

1. **Expected Value (Mean)**:

$\[
E(X) = \frac{nK}{N}
\]$

Where:
- \(n\) = sample size
- \(K\) = number of successes in the population
- \(N\) = total population size

2. **Variance**:

$\[
Var(X) = \frac{nK(N-K)(N-n)}{N^2(N-1)}
\]$

Where:
- \(n\), \(K\), and \(N\) are as defined above.

### **Applications of Hypergeometric Distribution**

1. **Quality Control**: In quality assurance, the hypergeometric distribution is often used to model situations where items are randomly selected from a batch without replacement to check for defects.
   
2. **Ecology**: It is used in ecological studies when estimating the number of species (successes) in a sample drawn from a finite population of species.
   
3. **Card Games**: In card games, where a deck of cards is shuffled and drawn without replacement, the hypergeometric distribution can model the probability of drawing a specific combination of cards.

4. **Polling and Surveys**: It can be used in situations where a random sample is selected from a fixed population, such as in voting surveys where the individuals surveyed are not replaced after being selected.

### **Difference Between Hypergeometric and Binomial Distribution**

- **Binomial Distribution**: The binomial distribution assumes sampling with replacement, meaning each item in the sample is independent and has the same probability of being selected each time.
- **Hypergeometric Distribution**: The hypergeometric distribution assumes sampling without replacement, so the probability of selecting each item changes after each draw. It models the dependency between trials.

### **Conclusion**

The **hypergeometric distribution** is a useful tool in statistics for situations where sampling is done without replacement, and it provides the probability of a specific number of successes in a sample drawn from a finite population. It is commonly used in quality control, ecological studies, and card games, among other applications. The distribution is characterized by its parameters: population size, number of successes in the population, sample size, and the desired number of successes in the sample.
