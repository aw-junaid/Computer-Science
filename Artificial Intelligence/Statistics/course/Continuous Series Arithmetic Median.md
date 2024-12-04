### **Continuous Series Arithmetic Median**

The **arithmetic median** for a **continuous series** is the value that separates the data into two equal parts: half of the observations fall below the median, and half fall above it. Unlike the mean, which is calculated using all the data points, the median is based on the position of the data points when the data is ordered.

For a **continuous frequency distribution**, the median is calculated using the cumulative frequency distribution, and it requires finding the class interval in which the median lies.

### **Steps to Calculate the Median for a Continuous Series:**

1. **Organize the Data**:
   - The data should be in the form of class intervals, each with an associated frequency. The class intervals should ideally be sorted in ascending order.

2. **Calculate the Cumulative Frequency**:
   - The **cumulative frequency** is the running total of the frequencies. This helps identify the position of the median class.

3. **Find the Median Class**:
   - The **median class** is the class interval where the cumulative frequency exceeds half of the total number of observations (i.e., $\( \frac{N}{2} \)$, where \( N \) is the total number of observations).

4. **Use the Median Formula**:
   Once the median class is identified, the median is calculated using the following formula:

   $\[
   \text{Median} = L + \left( \frac{\frac{N}{2} - CF}{f} \right) \cdot h
   \]$

   Where:
   - \( L \) = Lower boundary of the median class.
   - \( N \) = Total number of observations (sum of all frequencies).
   - \( CF \) = Cumulative frequency of the class before the median class.
   - \( f \) = Frequency of the median class.
   - \( h \) = Class width (difference between the upper and lower limits of any class).

### **Example Calculation:**

Consider the following continuous frequency distribution of the scores of 30 students in an exam:

| Class Interval (Scores) | Frequency (\( f_i \)) |
|-------------------------|-----------------------|
| 0 - 10                  | 4                     |
| 10 - 20                 | 6                     |
| 20 - 30                 | 8                     |
| 30 - 40                 | 5                     |
| 40 - 50                 | 7                     |

#### **Step 1: Calculate the Cumulative Frequency**

Start by calculating the cumulative frequencies:

| Class Interval | Frequency \( f_i \) | Cumulative Frequency (CF) |
|-----------------|---------------------|---------------------------|
| 0 - 10          | 4                   | 4                         |
| 10 - 20         | 6                   | 10                        |
| 20 - 30         | 8                   | 18                        |
| 30 - 40         | 5                   | 23                        |
| 40 - 50         | 7                   | 30                        |

#### **Step 2: Find the Median Class**

The total number of observations \( N \) is:

$\[
N = 4 + 6 + 8 + 5 + 7 = 30
\]$

Now, we find $\( \frac{N}{2} \)$:

$\[
\frac{N}{2} = \frac{30}{2} = 15
\]$

The median class is the class where the cumulative frequency exceeds \( 15 \). From the table, we can see that the cumulative frequency first exceeds 15 in the **20 - 30** class (CF = 18). Therefore, the **median class** is the interval **20 - 30**.

#### **Step 3: Apply the Median Formula**

Now that we know the median class, we can apply the formula:

$\[
\text{Median} = L + \left( \frac{\frac{N}{2} - CF}{f} \right) \cdot h
\]$

Where:
- \( L = 20 \) (lower boundary of the median class).
- \( N = 30 \) (total number of observations).
- \( CF = 10 \) (cumulative frequency of the class before the median class, which is the 10 - 20 class).
- \( f = 8 \) (frequency of the median class, which is the 20 - 30 class).
- \( h = 10 \) (class width, since \( 30 - 20 = 10 \)).

Substitute the values into the formula:

$\[
\text{Median} = 20 + \left( \frac{15 - 10}{8} \right) \cdot 10
\]$

$\[
\text{Median} = 20 + \left( \frac{5}{8} \right) \cdot 10
\]$

$\[
\text{Median} = 20 + 6.25 = 26.25
\]$

So, the median score is **26.25**.

### **Conclusion:**

The **arithmetic median** for a continuous series is found by:
1. Identifying the **median class** based on the cumulative frequency.
2. Using the **median formula** to compute the median value.

This method allows you to estimate the median even when the data is grouped into class intervals, providing a reliable central value for continuous distributions.
