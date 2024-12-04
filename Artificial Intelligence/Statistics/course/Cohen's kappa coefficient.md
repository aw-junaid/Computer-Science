### **Cohen's Kappa Coefficient**

**Cohen's Kappa (κ)** is a statistical measure used to assess the level of agreement between two raters or judges who are classifying items into mutually exclusive categories. It is particularly useful in situations where the raters might disagree, and it takes into account the possibility of agreement occurring by chance. Cohen's Kappa is commonly used in **inter-rater reliability studies**.

Unlike simple percent agreement (which is the number of times the raters agree divided by the total number of items), Cohen's Kappa adjusts for the agreement that could occur by chance, making it a more robust measure of agreement.

### **Formula for Cohen's Kappa:**

The formula for Cohen's Kappa coefficient is given by:
$\[
\kappa = \frac{P_o - P_e}{1 - P_e}
\]$
Where:
- **\( P_o \)** is the **observed agreement**: the proportion of times the two raters agree on the classification.
- **\( P_e \)** is the **expected agreement**: the proportion of times the raters would be expected to agree by chance.

### **Step-by-Step Calculation of Cohen's Kappa:**

1. **Construct a Confusion Matrix**: Create a table that shows the counts of how the two raters agree and disagree. For two raters classifying items into two categories (e.g., "Yes" and "No"), the confusion matrix looks like this:

|               | Rater 2: Yes | Rater 2: No | **Total** |
|---------------|--------------|-------------|-----------|
| **Rater 1: Yes** | a            | b           | a + b     |
| **Rater 1: No**  | c            | d           | c + d     |
| **Total**        | a + c        | b + d       | N         |

Where:
- **a** = number of items both raters agree on as "Yes"
- **b** = number of items Rater 1 classifies as "Yes" and Rater 2 classifies as "No"
- **c** = number of items Rater 1 classifies as "No" and Rater 2 classifies as "Yes"
- **d** = number of items both raters agree on as "No"
- **N** = total number of items

2. **Calculate Observed Agreement (Pₒ)**: This is the proportion of items that the raters agree on (i.e., the diagonal of the confusion matrix):
$\[
P_o = \frac{a + d}{N}
\]$

3. **Calculate Expected Agreement (Pₑ)**: This is the proportion of agreement that we would expect by chance. It is based on the assumption that both raters are classifying the items independently. The formula for \( P_e \) is:
$\[
P_e = \left( \frac{(a + b)(a + c)}{N^2} \right) + \left( \frac{(c + d)(b + d)}{N^2} \right)
\]$

4. **Calculate Cohen's Kappa (κ)**:
$\[
\kappa = \frac{P_o - P_e}{1 - P_e}
\]$

### **Interpretation of Cohen's Kappa:**

Cohen’s Kappa ranges from **-1 to 1**, with the following general guidelines for interpreting the value:

- **κ = 1**: Perfect agreement (both raters agree completely).
- **κ = 0**: No agreement beyond what would be expected by chance.
- **κ < 0**: Less agreement than would be expected by chance (negative value indicates systematic disagreement).
- **κ > 0**: Positive agreement; the closer it is to 1, the stronger the agreement.

General guidelines for interpreting Cohen's Kappa (κ):

| **Kappa (κ)** | **Interpretation**        |
|---------------|---------------------------|
| 0.81–1.00     | Almost perfect agreement  |
| 0.61–0.80     | Substantial agreement     |
| 0.41–0.60     | Moderate agreement        |
| 0.21–0.40     | Fair agreement            |
| 0.00–0.20     | Poor agreement            |
| < 0.00         | Less than chance agreement|

### **Example of Cohen's Kappa Calculation:**

Let’s assume two raters were classifying 100 items into two categories: “Yes” or “No”. The confusion matrix is as follows:

|               | Rater 2: Yes | Rater 2: No | **Total** |
|---------------|--------------|-------------|-----------|
| **Rater 1: Yes** | 40           | 10          | 50        |
| **Rater 1: No**  | 5            | 45          | 50        |
| **Total**        | 45           | 55          | 100       |

- **Observed agreement (Pₒ)**:
  $\[
  P_o = \frac{40 + 45}{100} = 0.85
  \]$

- **Expected agreement (Pₑ)**:
  $\[
  P_e = \left( \frac{(40 + 10)(40 + 5)}{100^2} \right) + \left( \frac{(5 + 45)(10 + 45)}{100^2} \right)
  \]$
  
  $\[
  P_e = \left( \frac{50 \times 45}{100^2} \right) + \left( \frac{50 \times 55}{100^2} \right)
  \]$
  
  $\[
  P_e = \frac{2250}{10000} + \frac{2750}{10000} = 0.5
  \]$

- **Cohen's Kappa (κ)**:
  $\[
  \kappa = \frac{0.85 - 0.5}{1 - 0.5} = \frac{0.35}{0.5} = 0.7
  \]$

In this example, Cohen's Kappa is **0.7**, which indicates **substantial agreement** between the two raters.

### **Advantages of Cohen's Kappa:**

1. **Adjusts for Chance**: Unlike percent agreement, Cohen's Kappa adjusts for the possibility of agreement occurring by chance.
2. **Widely Used**: It is commonly used in fields such as psychology, medicine, and social sciences to measure inter-rater reliability.
3. **Generalizable**: It can be used for both nominal and ordinal data.

### **Limitations of Cohen's Kappa:**

1. **Kappa can be influenced by prevalence**: If one category is much more frequent than the other, Kappa may underestimate the agreement. This can be addressed using **prevalence-adjusted Kappa** or **bias-adjusted Kappa**.
2. **Not suitable for more than two raters**: Cohen's Kappa is specifically designed for comparing two raters. For more than two raters, an alternative measure like **Fleiss’ Kappa** is used.

### **Conclusion:**

Cohen’s Kappa coefficient is an important tool for assessing the reliability of agreement between two raters, especially when the classifications are categorical. It provides a more accurate measure than simple percent agreement by accounting for chance agreement, making it a more robust method for evaluating inter-rater reliability.
