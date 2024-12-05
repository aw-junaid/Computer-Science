### **Geometric Probability Distribution in Statistics**

The **Geometric Probability Distribution** is a discrete probability distribution that models the number of trials needed before the first success in a sequence of independent Bernoulli trials. In other words, it describes the number of failures before the first success in a series of identical, independent trials.

The **Geometric Distribution** is a special case of the negative binomial distribution, where the number of successes is fixed at 1.

### **Key Properties and Parameters**
The geometric distribution has the following characteristics:
- **Success probability**: \( p \), which is the probability of success on a single trial.
- **Failure probability**: $\( 1 - p \)$, which is the probability of failure on a single trial.
- **Random variable**: \( X \), representing the number of trials needed until the first success.
  
The variable \( X \) can take values $\( 1, 2, 3, \dots \)$, i.e., the number of trials needed is always a positive integer.

### **Probability Mass Function (PMF)**

The probability mass function (PMF) of a geometric distribution, for a given \( p \) (the probability of success on any trial) and \( X = k \) (the number of trials until the first success), is given by:

$\[
P(X = k) = (1 - p)^{k-1} p, \quad k = 1, 2, 3, \dots
\]$

Where:
- \( p \) is the probability of success on any given trial.
- $\( (1 - p)^{k-1} \)$ is the probability of having \( k-1 \) failures before the first success.
- \( p \) is the probability of success on the \( k \)-th trial.

### **Cumulative Distribution Function (CDF)**

The cumulative distribution function (CDF) of the geometric distribution gives the probability that the number of trials until the first success is less than or equal to \( k \):

$\[
F(k) = P(X \leq k) = 1 - (1 - p)^k, \quad k = 1, 2, 3, \dots
\]$

### **Expected Value (Mean)**

The expected value (mean) of a geometric distribution represents the average number of trials required to get the first success. The expected value is given by:

$\[
E(X) = \frac{1}{p}
\]$

This means that, on average, it will take $\( \frac{1}{p} \)$ trials to get the first success.

### **Variance**

The variance of a geometric distribution represents how spread out the number of trials until the first success is. It is given by:

$\[
\text{Var}(X) = \frac{1 - p}{p^2}
\]$
### **Standard Deviation**

The standard deviation is the square root of the variance, and it gives a measure of how much the number of trials until the first success is likely to vary from the expected value:

$\[
\text{SD}(X) = \sqrt{\frac{1 - p}{p^2}}
\]$

### **Moment-Generating Function (MGF)**

The moment-generating function (MGF) of the geometric distribution is:

$\[
M_X(t) = \frac{p}{1 - (1 - p)e^t}, \quad \text{for} \ t < -\ln(1 - p)
\]$

### **Applications of the Geometric Distribution**

The **Geometric Distribution** is used in various fields to model situations where we are interested in the number of trials required for the first success:

1. **Quality Control**: In manufacturing, the geometric distribution can model the number of defective products produced before finding the first non-defective one.
  
2. **Customer Service**: In customer service scenarios, it can be used to model the number of customer calls answered before the first call that requires a supervisor’s attention.
  
3. **Medical Studies**: In clinical trials, it can model the number of patients treated before observing the first patient with a specific medical outcome.

4. **Gambling**: In gambling scenarios, the geometric distribution can model the number of attempts (e.g., coin flips, dice rolls) needed before a win is observed.

### **Example**

Suppose a factory produces light bulbs, and the probability that a light bulb is defective is 0.1. If we want to know the probability that the first non-defective light bulb is found on the 5th trial, we use the geometric distribution.

Given:
- The probability of success (non-defective bulb) \( p = 0.9 \)
- The number of trials until the first success is \( k = 5 \)

The probability that the first non-defective bulb is found on the 5th trial is:

$\[
P(X = 5) = (1 - 0.9)^{5-1} \times 0.9 = (0.1)^4 \times 0.9 = 0.0001 \times 0.9 = 0.00009
\]$

So, the probability of finding the first non-defective light bulb on the 5th trial is \( 0.00009 \).

### **Conclusion**

The **Geometric Distribution** is a useful model for counting the number of trials until the first success in a sequence of independent Bernoulli trials. It has broad applications in fields ranging from quality control and customer service to medical studies and gambling. The distribution is defined by the success probability \( p \) and its mean, variance, and standard deviation provide useful insights into the behavior of the number of trials required to achieve the first success.
