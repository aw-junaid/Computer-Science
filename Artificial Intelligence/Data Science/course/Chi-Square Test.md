### Python - Chi-Square Test

The **Chi-Square Test** is a statistical test used to determine if there is a significant association between categorical variables. It is used when you have categorical data, and you want to test the relationship between the observed frequencies in a contingency table and the frequencies that would be expected under the assumption that the variables are independent.

#### Types of Chi-Square Tests:
1. **Chi-Square Test of Independence**: Used to determine whether two categorical variables are independent.
2. **Chi-Square Goodness of Fit Test**: Used to determine if a sample matches a population distribution.

### 1. **Chi-Square Test of Independence**
The **Chi-Square Test of Independence** is used to test if two categorical variables are independent. For example, you might want to test if there is an association between gender and voting preference.

#### Hypotheses:
- **Null Hypothesis (H₀)**: The two categorical variables are independent.
- **Alternative Hypothesis (H₁)**: The two categorical variables are dependent (associated).

### Steps to perform the Chi-Square Test of Independence:
1. Create a contingency table (cross-tabulation) of the categorical data.
2. Calculate the expected frequencies based on the assumption of independence.
3. Compute the Chi-Square statistic using the formula:
   
$\[
\chi^2 = \sum \frac{(O_i - E_i)^2}{E_i}
\]$
Where:
- $\( O_i \)$ is the observed frequency.
- $\( E_i \)$ is the expected frequency.

4. Compare the computed Chi-Square statistic with the critical value from the Chi-Square distribution table, or calculate the p-value.

### Example: Chi-Square Test of Independence

#### Data
Let's test whether there is an association between `Gender` and `Preference for Product A` (categorical variables).

|              | Product A | Product B | Total |
|--------------|-----------|-----------|-------|
| Male         | 30        | 10        | 40    |
| Female       | 20        | 30        | 50    |
| Total        | 50        | 40        | 90    |

#### Python Code:

```python
import numpy as np
import scipy.stats as stats

# Create observed data (contingency table)
observed = np.array([[30, 10],
                     [20, 30]])

# Perform Chi-Square Test of Independence
chi2_stat, p_value, dof, expected = stats.chi2_contingency(observed)

# Print the results
print(f"Chi2 Statistic: {chi2_stat}")
print(f"P-value: {p_value}")
print(f"Degrees of Freedom: {dof}")
print(f"Expected Frequencies: \n{expected}")
```

#### Explanation:
- **Chi2 Statistic**: The test statistic computed from the data.
- **P-value**: The probability of observing the data given the null hypothesis (independence).
- **Degrees of Freedom**: The number of independent values in the contingency table.
- **Expected Frequencies**: The frequencies that would be expected under the null hypothesis.

#### Output Interpretation:
- If the p-value is less than a chosen significance level (e.g., 0.05), you reject the null hypothesis, which suggests that the two variables are dependent.
- If the p-value is greater than 0.05, you fail to reject the null hypothesis, indicating that the two variables are independent.

---

### 2. **Chi-Square Goodness of Fit Test**
The **Chi-Square Goodness of Fit Test** is used to determine if the observed frequencies of a single categorical variable differ significantly from the expected frequencies under a particular hypothesis.

#### Hypotheses:
- **Null Hypothesis (H₀)**: The observed frequencies are consistent with the expected frequencies.
- **Alternative Hypothesis (H₁)**: The observed frequencies are not consistent with the expected frequencies.

### Example: Chi-Square Goodness of Fit Test

Suppose you roll a six-sided die 60 times, and the observed frequencies of each face are as follows:

| Face (1 to 6) | Observed Frequency |
|---------------|--------------------|
| 1             | 10                 |
| 2             | 12                 |
| 3             | 8                  |
| 4             | 11                 |
| 5             | 9                  |
| 6             | 10                 |

You expect each face to appear 10 times (since the die is fair).

#### Python Code:

```python
import numpy as np
import scipy.stats as stats

# Observed frequencies
observed = np.array([10, 12, 8, 11, 9, 10])

# Expected frequencies (for a fair die, we expect equal frequency for each face)
expected = np.array([10, 10, 10, 10, 10, 10])

# Perform Chi-Square Goodness of Fit Test
chi2_stat, p_value = stats.chisquare(observed, expected)

# Print the results
print(f"Chi2 Statistic: {chi2_stat}")
print(f"P-value: {p_value}")
```

#### Output Interpretation:
- If the p-value is less than the significance level (e.g., 0.05), you reject the null hypothesis and conclude that the die is biased.
- If the p-value is greater than 0.05, you fail to reject the null hypothesis and conclude that the die is fair.

---

### 3. **Chi-Square Test Assumptions**
The Chi-Square test assumes:
1. The data are in the form of counts or frequencies.
2. The observations are independent.
3. The expected frequency for each category should be at least 5 for the Chi-Square test to be valid. If the expected frequency is less than 5, consider using Fisher's Exact Test or combining categories.

---

### Conclusion

The **Chi-Square Test** is a powerful statistical tool to test the association between categorical variables and to evaluate if observed data differ significantly from expected values. In Python, you can perform both the **Chi-Square Test of Independence** and the **Chi-Square Goodness of Fit Test** using **SciPy's `chi2_contingency()`** and **`chisquare()`** functions.
