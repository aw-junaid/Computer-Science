### **Quartile Deviation (QD)**

The **Quartile Deviation** (QD), also known as the **semi-interquartile range (SIQR)**, is a measure of statistical dispersion that quantifies the spread or variability of data by focusing on the middle 50% of the data. It is the half of the difference between the **third quartile (Q₃)** and the **first quartile (Q₁)**, which represent the values below which 75% and 25% of the data fall, respectively.

#### **Formula for Quartile Deviation:**
$\[
QD = \frac{Q_3 - Q_1}{2}
\]$
Where:
- **Q₁ (First Quartile)**: The value below which 25% of the data falls (also known as the lower quartile).
- **Q₃ (Third Quartile)**: The value below which 75% of the data falls (also known as the upper quartile).

Thus, the **Quartile Deviation** is the "half-range" of the interquartile range (IQR), which is the difference between Q₃ and Q₁.

### **Steps to Calculate Quartile Deviation**

1. **Arrange the data in ascending order**.
2. **Find the first quartile (Q₁)**:
   - Q₁ is the median of the lower half of the data.
3. **Find the third quartile (Q₃)**:
   - Q₃ is the median of the upper half of the data.
4. **Calculate the Quartile Deviation** using the formula:
   $\[
   QD = \frac{Q_3 - Q_1}{2}
   \]$

### **Example Calculation:**

Let's say we have the following data set of 9 numbers:

$\[
2, 4, 6, 8, 10, 12, 14, 16, 18
\]$

1. **Arrange the data in ascending order** (already done).
2. **Find Q₁** (First Quartile):
   - The lower half of the data is: 2, 4, 6, 8.
   - The median of this lower half is $\( Q₁ = \frac{4 + 6}{2} = 5 \)$.
3. **Find Q₃** (Third Quartile):
   - The upper half of the data is: 12, 14, 16, 18.
   - The median of this upper half is $\( Q₃ = \frac{14 + 16}{2} = 15 \)$.
4. **Calculate the Quartile Deviation**:
   $\[
   QD = \frac{15 - 5}{2} = \frac{10}{2} = 5
   \]$

So, the **Quartile Deviation (QD)** is 5.

### **Interpretation of Quartile Deviation:**

- The **Quartile Deviation** represents the spread of the middle 50% of the data. A higher QD indicates greater variability or spread in the middle of the data, while a lower QD suggests less spread.
- It is less sensitive to extreme values (outliers) than the range or standard deviation, as it only considers the central portion of the data (the interquartile range).

### **Advantages of Quartile Deviation:**
- **Robust to Outliers**: Unlike the range or standard deviation, the quartile deviation is not significantly affected by outliers or extreme values, as it only considers the data within the interquartile range.
- **Simple to Compute**: It is relatively easy to compute, especially when the data is already arranged in order.

### **Disadvantages of Quartile Deviation:**
- **Limited Information**: The quartile deviation only considers the central portion of the data (Q₁ to Q₃) and ignores the rest of the data distribution, which may lead to loss of information about the data's overall spread.
  
### **Conclusion:**

The **Quartile Deviation** is a useful measure of the spread or variability in a data set, focusing on the central portion (the interquartile range). It is particularly valuable when dealing with skewed distributions or data with outliers, as it is not influenced by extreme values.
