### **Discrete Series Arithmetic Median**

The **median** is another measure of central tendency, which represents the middle value in a dataset when the data points are arranged in ascending order. For a **discrete series**, where data is given as distinct values with corresponding frequencies, the **arithmetic median** is the value that divides the data into two equal halves.

In a discrete series, the median is determined by finding the point at which the cumulative frequency reaches or exceeds half the total number of data points.

#### **Steps to Calculate the Median in a Discrete Series**

To calculate the median in a discrete series, follow these steps:

1. **Organize the Data**: List the distinct values $(\(x_i\))$ and their corresponding frequencies $(\(f_i\))$ in ascending order of the values.
   
2. **Calculate the Total Frequency (\(N\))**: 
   - Sum all the frequencies to find the total number of data points, $\(N = \sum f_i\)$.
   
3. **Find the Cumulative Frequency**:
   - Calculate the cumulative frequency for each class, which is the running total of the frequencies from the start to that class.
   
4. **Determine the Median Class**:
   - Identify the class where the cumulative frequency first reaches or exceeds $\( \frac{N}{2} \)$. This is called the **median class**.
   
5. **Calculate the Median**:
   - Use the formula for the median for a discrete series:
     $\[
     \text{Median} = L + \left( \frac{\frac{N}{2} - CF}{f} \right) \cdot h
     \]$
     Where:
     - **L** is the lower boundary of the median class.
     - **N** is the total frequency (sum of all \(f_i\)).
     - **CF** is the cumulative frequency of the class before the median class.
     - **f** is the frequency of the median class.
     - **h** is the class width (difference between the upper and lower boundaries of the class).

#### **Example Calculation**

Let’s consider the following discrete data representing the number of books sold and their frequencies:

| Number of Books Sold (x) | Frequency (f) |
|---------------------------|---------------|
| 1                         | 2             |
| 2                         | 4             |
| 3                         | 6             |
| 4                         | 8             |
| 5                         | 10            |

1. **Step 1: Organize the Data**
   - Data is already organized in ascending order of \(x\).

2. **Step 2: Calculate Total Frequency \(N\)**
   $\[
   N = 2 + 4 + 6 + 8 + 10 = 30
   \]$

3. **Step 3: Find the Cumulative Frequency**
   - Cumulative frequencies:
     - For \(x = 1\), \(CF = 2\)
     - For \(x = 2\), \(CF = 2 + 4 = 6\)
     - For \(x = 3\), \(CF = 6 + 6 = 12\)
     - For \(x = 4\), \(CF = 12 + 8 = 20\)
     - For \(x = 5\), \(CF = 20 + 10 = 30\)

4. **Step 4: Determine the Median Class**
   - We need to find the cumulative frequency that first reaches or exceeds \( \frac{N}{2} = \frac{30}{2} = 15 \).
   - From the cumulative frequencies, the median class is the one where \(CF\) first exceeds 15, which is the class with \(x = 4\), since the cumulative frequency reaches 20 for this value.

5. **Step 5: Calculate the Median**
   - From the formula:
     $\[
     \text{Median} = L + \left( \frac{\frac{N}{2} - CF}{f} \right) \cdot h
     \]$
     Where:
     - **L = 3.5** (lower boundary of the median class, \( x = 4 \)).
     - **N = 30**.
     - **CF = 12** (cumulative frequency before the median class).
     - **f = 8** (frequency of the median class).
     - **h = 1** (class width, since the values are discrete and the difference between consecutive \(x_i\) is 1).

   Now, calculate the median:
   $\[
   \text{Median} = 3.5 + \left( \frac{15 - 12}{8} \right) \cdot 1
   \]$
   
   $\[
   \text{Median} = 3.5 + \left( \frac{3}{8} \right)
   \]$
   
   $\[
   \text{Median} = 3.5 + 0.375 = 3.875
   \]$

Thus, the **arithmetic median** of the dataset is **3.875**.

### **Uses of the Arithmetic Median in a Discrete Series**

- **Descriptive Statistics**: The median gives a better idea of the "middle" of the data, especially when there are outliers or skewed distributions.
- **Robust to Outliers**: Unlike the mean, the median is less affected by extreme values. This makes it a preferred measure of central tendency for skewed or heavily skewed distributions.
- **Data Summary**: It provides a central reference point that divides the dataset into two equal halves, making it useful for summarizing the distribution of data.
- **Comparing Data Distributions**: The median is often used to compare the central tendencies of different datasets, particularly when the data is not normally distributed.

### **Advantages of the Arithmetic Median**
- **Less Sensitive to Extreme Values**: The median is not influenced by very high or very low values (outliers), making it a more reliable measure of central tendency in skewed distributions.
- **Easy to Interpret**: It divides the data into two equal halves, making it an intuitive measure of the "center" of the dataset.
- **Usefulness in Skewed Distributions**: It is particularly useful when the data is not symmetrically distributed or when there are outliers.

### **Limitations of the Arithmetic Median**
- **Not Sensitive to All Data Points**: The median only considers the position of the data points and not their actual values, which means it may not fully reflect the distribution if the data points are spread out.
- **Not Suitable for Interval Data**: For interval or ratio-level data, the median may not always provide the most informative summary compared to the mean, especially when the data is symmetrical.

### **Conclusion**

The **arithmetic median** of a discrete series is an essential tool in statistics for summarizing the central tendency of data, especially when the data is not normally distributed or when outliers are present. By dividing the dataset into two equal halves, the median provides a useful reference point for understanding the data's distribution.
