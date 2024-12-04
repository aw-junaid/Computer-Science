### **Cumulative Frequency**

**Cumulative frequency** is a concept in statistics used to describe the running total of frequencies in a dataset, showing how the frequency accumulates as you move through class intervals. It is particularly useful when working with grouped data, as it helps to understand the distribution of the data and locate measures like the median, quartiles, and percentiles.

### **Definition:**
The **cumulative frequency** of a class is the sum of the frequencies of that class and all preceding classes. It represents the total number of data points that fall within or below a particular class interval.

### **How to Calculate Cumulative Frequency:**

1. **List the Frequency Distribution**: Begin with the frequency distribution, where the data is grouped into class intervals.
2. **Start with the First Class**: The cumulative frequency for the first class interval is simply its frequency.
3. **Add the Frequency of the Next Class**: The cumulative frequency for each subsequent class is the sum of the frequency of that class and the cumulative frequency of the previous class.
4. **Repeat for All Classes**: Continue the process until you have cumulative frequencies for all class intervals.

### **Formula:**
For a class \( i \), the cumulative frequency \( CF_i \) is given by:

$\[
CF_i = f_1 + f_2 + \dots + f_i
\]$

Where:
- \( f_i \) is the frequency of the \( i \)-th class.
- \( CF_i \) is the cumulative frequency for the \( i \)-th class.

### **Example Calculation:**

Consider the following data showing the frequency distribution of students' scores in an exam:

| Class Interval (Scores) | Frequency \( f_i \) |
|-------------------------|---------------------|
| 0 - 10                  | 5                   |
| 10 - 20                 | 8                   |
| 20 - 30                 | 12                  |
| 30 - 40                 | 10                  |
| 40 - 50                 | 5                   |

#### **Step 1: List the Frequency Distribution**

| Class Interval | Frequency \( f_i \) | Cumulative Frequency (CF) |
|-----------------|---------------------|---------------------------|
| 0 - 10          | 5                   | 5                         |
| 10 - 20         | 8                   | 5 + 8 = 13                |
| 20 - 30         | 12                  | 13 + 12 = 25              |
| 30 - 40         | 10                  | 25 + 10 = 35              |
| 40 - 50         | 5                   | 35 + 5 = 40               |

#### **Step 2: Calculate Cumulative Frequency**

- For the first class (0 - 10), the cumulative frequency is \( 5 \).
- For the second class (10 - 20), the cumulative frequency is \( 5 + 8 = 13 \).
- For the third class (20 - 30), the cumulative frequency is \( 13 + 12 = 25 \).
- For the fourth class (30 - 40), the cumulative frequency is \( 25 + 10 = 35 \).
- For the fifth class (40 - 50), the cumulative frequency is \( 35 + 5 = 40 \).

Thus, the cumulative frequencies are:

| Class Interval | Frequency \( f_i \) | Cumulative Frequency (CF) |
|-----------------|---------------------|---------------------------|
| 0 - 10          | 5                   | 5                         |
| 10 - 20         | 8                   | 13                        |
| 20 - 30         | 12                  | 25                        |
| 30 - 40         | 10                  | 35                        |
| 40 - 50         | 5                   | 40                        |

### **Applications of Cumulative Frequency:**

1. **Graphing the Cumulative Frequency**:  
   Cumulative frequencies can be used to create **ogives**, which are graphs that show the cumulative distribution of a dataset. In an ogive, the cumulative frequency is plotted against the upper boundary of each class interval.

2. **Locating Percentiles and Quartiles**:  
   Cumulative frequency is essential for calculating percentiles (e.g., 25th, 50th, 75th percentiles) and quartiles. For example, to find the median (which corresponds to the 50th percentile), you can look for the class interval where the cumulative frequency is closest to half the total number of data points.

3. **Finding Median, Quartiles, and Other Measures**:  
   In a grouped frequency distribution, cumulative frequencies help in determining key statistics like the median, lower quartile (Q1), upper quartile (Q3), and other percentiles. For example:
   - To find the median class, locate the class where the cumulative frequency is closest to $\( \frac{N}{2} \)$, where \( N \) is the total frequency.

4. **Summarizing Data Distribution**:  
   Cumulative frequency tables provide a quick overview of the data distribution, making it easier to understand the number of data points less than or equal to a certain value. This is useful for summarizing large datasets.

### **Conclusion:**

Cumulative frequency provides valuable insight into the distribution of data. It is particularly helpful for understanding the cumulative count of observations as you progress through the data. This tool is widely used in statistics for calculating percentiles, medians, and other measures of central tendency, as well as for creating visual representations such as ogives.
