### **Factorial in Statistics**

A **factorial** is a fundamental concept in mathematics and statistics. It is denoted by \( n! \) and represents the product of all positive integers up to a given number \( n \). Factorials are widely used in permutations, combinations, and various other statistical calculations.

### **Definition of Factorial**

The factorial of a non-negative integer \( n \), denoted as \( n! \), is defined as:

$\[
n! = n \times (n - 1) \times (n - 2) \times \cdots \times 1
\]$

- **Base Case**: \( 0! = 1 \) (by definition).
- For example:
  - $\( 5! = 5 \times 4 \times 3 \times 2 \times 1 = 120 \)$
  - $\( 4! = 4 \times 3 \times 2 \times 1 = 24 \)$

### **Factorial Properties**

1. **Recursive Relation**: Factorial can be computed recursively:
   $\[
   n! = n \times (n - 1)!
   \]$
   This allows for the definition of factorial for larger numbers by reducing it to smaller ones.

2. **Factorial of Zero**: As mentioned above, $\( 0! = 1 \)$ is a special case, and this definition ensures the consistency of various mathematical formulas, such as in combinatorics.

3. **Factorial Growth**: Factorials grow extremely quickly as \( n \) increases. For instance:
   - $\( 10! = 3,628,800 \)$
   - $\( 20! = 2,432,902,008,176,640,000 \)$

### **Factorial in Statistics**

Factorials are essential in calculating the number of ways events can occur, especially in combinatorics and probability theory. They are used in:

#### **1. Permutations**

Permutations refer to the arrangement of objects in a specific order. The number of permutations of \( n \) distinct objects taken \( r \) at a time is given by:

$\[
P(n, r) = \frac{n!}{(n - r)!}
\]$

This formula calculates the number of ways to arrange \( r \) items selected from \( n \) distinct items.

#### **Example**:
How many ways can 3 students be selected and arranged from a group of 5?

$\[
P(5, 3) = \frac{5!}{(5 - 3)!} = \frac{5!}{2!} = \frac{120}{2} = 60
\]$

#### **2. Combinations**

Combinations refer to the selection of objects without regard to the order. The number of combinations of \( n \) distinct objects taken \( r \) at a time is given by the formula:

$\[
C(n, r) = \frac{n!}{r!(n - r)!}
\]$

This formula calculates the number of ways to choose \( r \) items from \( n \) distinct items, where the order does not matter.

#### **Example**:
How many ways can 3 students be selected from a group of 5?

$\[
C(5, 3) = \frac{5!}{3!(5 - 3)!} = \frac{5!}{3!2!} = \frac{120}{6 \times 2} = 10
\]$

#### **3. Binomial Coefficients**

The **binomial coefficient** is the number of ways to choose \( r \) elements from \( n \) elements. It is given by the combination formula, and it appears in the expansion of a binomial expression.

For example, the binomial coefficient $\( \binom{n}{r} \)$ (read as "n choose r") is equal to:

$\[
\binom{n}{r} = \frac{n!}{r!(n - r)!}
\]$

### **Factorial in Probability**

In probability, factorials are used in various distributions, such as the **Poisson distribution**, the **binomial distribution**, and the **multinomial distribution**, to calculate probabilities.

#### **Example: Binomial Distribution**

In a binomial distribution, the probability of exactly \( r \) successes in \( n \) trials is given by:

$\[
P(X = r) = \binom{n}{r} p^r (1 - p)^{n - r}
\]$

Where:
- $\( \binom{n}{r} = \frac{n!}{r!(n - r)!} \)$
- \( p \) is the probability of success on a single trial.
- \( n \) is the number of trials.

### **Factorial Approximation**

Because factorials grow very quickly, calculating large factorials directly can be impractical. An approximation commonly used for large \( n \) is **Stirling's approximation**:

$\[
n! \approx \sqrt{2 \pi n} \left(\frac{n}{e}\right)^n
\]$

This formula gives a good estimate for large \( n \).

### **Factorial in Large Numbers and Computational Use**

Factorials grow so rapidly that for large numbers, they quickly exceed the limits of typical computational storage. However, special functions, such as **Gamma functions**, extend the concept of factorials to non-integer values, providing useful approximations and applications in advanced statistics and mathematics.

### **Conclusion**

The **factorial** is a key concept in statistics, combinatorics, and probability theory, used for counting arrangements and selections. It serves as the foundation for permutations, combinations, binomial coefficients, and various distributions in probability. Factorial calculations often arise in hypothesis testing, regression models, and complex statistical procedures. Understanding how factorials work is essential for solving a wide range of statistical problems.
