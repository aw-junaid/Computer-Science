### **Shannon-Wiener Diversity Index**

The **Shannon-Wiener Diversity Index** (or **Shannon Entropy Index**) is a statistical measure used in ecology and other fields to quantify the diversity of a community based on species abundance or proportional representation. It accounts for both **richness** (the number of species) and **evenness** (the distribution of individuals among the species). The index is derived from information theory and reflects the uncertainty in predicting the species of a randomly chosen individual from a dataset.

---

### **Formula**

The Shannon-Wiener Diversity Index \( H' \) is calculated as:

$\[
H' = - \sum_{i=1}^S p_i \ln(p_i)
\]$

Where:
- \( S \): Total number of species (species richness).
- $\( p_i \)$: Proportion of individuals belonging to species \( i \), calculated as $\( p_i = \frac{n_i}{N} \)$, where:
  - \( n_i \): Number of individuals in species \( i \).
  - \( N \): Total number of individuals across all species.
- $\( \ln \)$: Natural logarithm (base \( e \)).

---

### **Interpretation**

- **Higher \( H' \)**: Indicates greater species diversity.
- **Lower \( H' \)**: Indicates lower diversity, which may suggest dominance by one or a few species.
- **Range**: 
  - \( H' \) is typically positive and ranges from 0 (only one species is present) to a theoretical maximum when all species are equally abundant.

---

### **Example**

Suppose you have the following data for a community:

| Species | Count $(\( n_i \))$ |
|---------|-------------------|
| A       | 50                |
| B       | 30                |
| C       | 20                |

1. Total number of individuals $\( N = 50 + 30 + 20 = 100 \)$.
2. Proportions \( p_i \):
   - For A: $\( p_A = \frac{50}{100} = 0.5 \)$
   - For B: $\( p_B = \frac{30}{100} = 0.3 \)$
   - For C: $\( p_C = \frac{20}{100} = 0.2 \)$
3. Apply the formula:
   $\[
   H' = - \left[ (0.5 \ln 0.5) + (0.3 \ln 0.3) + (0.2 \ln 0.2) \right]
   \]$
   
   $\[
   H' = - \left[ (0.5 \times -0.693) + (0.3 \times -1.204) + (0.2 \times -1.609) \right]
   \]$
   
   $\[
   H' = - \left[ -0.347 - 0.361 - 0.322 \right] = 1.03
   \]$

Thus, the Shannon-Wiener Index for this community is \( H' = 1.03 \).

---

### **Advantages**

1. **Incorporates both richness and evenness**: It provides a more nuanced view of diversity than simple species counts.
2. **Widely used**: Applicable in ecology, genetics, and other fields to assess diversity.

---

### **Limitations**

1. **Sensitive to sample size**: Larger datasets tend to have higher \( H' \).
2. **Non-comparability**: Difficult to compare across studies with different scales or definitions of a "species."

---

The Shannon-Wiener Index is a powerful tool for understanding community structure and ecological health, offering insight into species distribution and abundance in a single metric.
