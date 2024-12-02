The **Arithmetic Median** (or simply the **Median**) is another measure of central tendency, representing the middle value in a sorted dataset. It divides the data into two equal halves, making it less sensitive to outliers than the arithmetic mean. This makes the median a better measure of central tendency when the data contains extreme values or is skewed.

### How to Calculate the Median:
The method for calculating the median depends on whether the number of data points (n) is odd or even.

1. **For an Odd Number of Data Points**:
   - Arrange the data in ascending or descending order.
   - The median is the middle value (the value at position $\(\frac{n+1}{2}\))$.

2. **For an Even Number of Data Points**:
   - Arrange the data in ascending or descending order.
   - The median is the average of the two middle values (the values at positions $\(\frac{n}{2}\)$ and $\(\frac{n}{2} + 1\))$.

### Example of Calculating the Median:

#### Case 1: Odd Number of Data Points
Consider the dataset:
\[ 70, 85, 90, 75, 80 \]

1. **Sort the data**:
   \[ 70, 75, 80, 85, 90 \]
2. **Find the middle value**:
   Since there are 5 data points (an odd number), the middle value is the 3rd number in the sorted list.
   - **Median** = 80

#### Case 2: Even Number of Data Points
Consider the dataset:
\[ 50, 60, 100, 500 \]

1. **Sort the data**:
   \[ 50, 60, 100, 500 \]
2. **Find the two middle values**:
   There are 4 data points (an even number), so the median is the average of the 2nd and 3rd values.
   - Median = $\(\frac{60 + 100}{2} = 80\)$

### Key Properties of the Median:
1. **Resistant to Outliers**: The median is **not affected by extreme values** or outliers in the same way the mean is. This makes the median a better measure of central tendency in skewed distributions or when there are outliers.
   
2. **Works for Ordinal Data**: The median can be used for **ordinal data** (data with a natural order) as well as interval or ratio data.

3. **Better for Skewed Distributions**: In skewed distributions, the median better represents the "typical" value in the dataset than the mean, which can be pulled in the direction of the skew.

### Comparison Between Mean and Median:
- **Mean**: Sensitive to extreme values (outliers), reflects the true average of the dataset if the data is symmetrically distributed.
- **Median**: Not influenced by outliers, provides a better measure of the center of the data when the dataset is skewed.

### Example with Outliers:
Consider the dataset:
\[ 50, 60, 100, 500 \]

- The **mean** is:
  $\[
  \frac{50 + 60 + 100 + 500}{4} = \frac{710}{4} = 177.5
  \]$
- The **median** is:
  $\[
  \text{Median} = \frac{60 + 100}{2} = 80
  \]$

In this case, the mean (177.5) is heavily influenced by the outlier (500), while the median (80) provides a better representation of the typical value in the dataset.

### When to Use the Median:
- When the dataset contains **outliers** or is **skewed**.
- When you are dealing with **ordinal data**, where you cannot calculate the mean.
- When you want a **more robust measure of central tendency** that is not affected by extreme values.

