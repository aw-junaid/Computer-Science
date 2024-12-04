### **Continuous Series Arithmetic Mean**

The **arithmetic mean** for a **continuous series** is a measure of central tendency that represents the average of a set of data points. In a continuous series, the data is grouped into classes or intervals, and the mean is calculated using the midpoints of those classes.

For a continuous series, the data is presented in the form of class intervals, and each interval has a frequency associated with it. To calculate the arithmetic mean for such a series, you need to follow a systematic procedure.

### **Steps to Calculate the Arithmetic Mean for a Continuous Series:**

1. **Find the Midpoint of Each Class Interval**:
   The midpoint of each class interval is the average of the lower and upper limits of that class. It is denoted as \( x_i \) for the $\( i^{th} \)$ class, and is calculated as:

   $\[
   x_i = \frac{{L_i + U_i}}{2}
   \]$

   Where:
   - \( L_i \) is the lower limit of the $\( i^{th} \)$ class.
   - \( U_i \) is the upper limit of the $\( i^{th} \)$ class.
   
   The midpoint represents the "typical" value of all the data points within that interval.

2. **Multiply the Midpoint by the Frequency**:
   For each class, multiply the midpoint \( x_i \) by the frequency \( f_i \) of that class. This gives the weighted value of each class in terms of its midpoint. The result is $\( f_i \cdot x_i \)$.

3. **Sum the Products**:
   Sum the values obtained by multiplying the midpoints by the corresponding frequencies. This is the total of all the weighted values:

   $\[
   \sum f_i \cdot x_i
   \]$

4. **Sum the Frequencies**:
   Sum all the frequencies \( f_i \) across all classes. This gives the total number of observations in the data set:

   $\[
   \sum f_i
   \]$

5. **Calculate the Arithmetic Mean**:
   Finally, the arithmetic mean is calculated by dividing the sum of the products of the frequencies and midpoints by the total frequency:

   $\[
   \text{Mean} (\mu) = \frac{{\sum f_i \cdot x_i}}{{\sum f_i}}
   \]$

   Where:
   - $\( \mu \)$ is the arithmetic mean.
   - $\( \sum f_i \cdot x_i \)$ is the sum of the products of frequencies and midpoints.
   - $\( \sum f_i \)$ is the total frequency.

### **Example Calculation:**

Suppose we have the following continuous frequency distribution of students' scores on a test:

| Class Interval (Scores) | Frequency (\( f_i \)) |
|-------------------------|-----------------------|
| 0 - 10                  | 3                     |
| 10 - 20                 | 5                     |
| 20 - 30                 | 8                     |
| 30 - 40                 | 4                     |
| 40 - 50                 | 2                     |

#### **Step 1: Calculate the Midpoint for Each Class Interval**

The midpoint of each class interval is calculated as:

- For the class interval \( 0 - 10 \), $\( x_1 = \frac{0 + 10}{2} = 5 \)$
- For the class interval \( 10 - 20 \), $\( x_2 = \frac{10 + 20}{2} = 15 \)$
- For the class interval \( 20 - 30 \), $\( x_3 = \frac{20 + 30}{2} = 25 \)$
- For the class interval \( 30 - 40 \), $\( x_4 = \frac{30 + 40}{2} = 35 \)$
- For the class interval \( 40 - 50 \), $\( x_5 = \frac{40 + 50}{2} = 45 \)$

#### **Step 2: Multiply the Midpoint by the Frequency**

Now multiply each midpoint by the corresponding frequency:

| Class Interval | Midpoint \( x_i \) | Frequency \( f_i \) | \( f_i \cdot x_i \) |
|-----------------|--------------------|---------------------|---------------------|
| 0 - 10          | 5                  | 3                   | 15                  |
| 10 - 20         | 15                 | 5                   | 75                  |
| 20 - 30         | 25                 | 8                   | 200                 |
| 30 - 40         | 35                 | 4                   | 140                 |
| 40 - 50         | 45                 | 2                   | 90                  |

#### **Step 3: Sum the Products of \( f_i \) and \( x_i \)**

Now sum all the values of $\( f_i \cdot x_i \)$:

$\[
\sum f_i \cdot x_i = 15 + 75 + 200 + 140 + 90 = 520
\]$

#### **Step 4: Sum the Frequencies**

Sum the frequencies:

$\[
\sum f_i = 3 + 5 + 8 + 4 + 2 = 22
\]$

#### **Step 5: Calculate the Mean**

Finally, calculate the arithmetic mean:

$\[
\text{Mean} (\mu) = \frac{{520}}{{22}} = 23.64
\]$

So, the arithmetic mean of the scores is approximately **23.64**.

### **Conclusion:**

The arithmetic mean for a continuous series is a measure of central tendency that is calculated using the midpoints of the class intervals and their corresponding frequencies. The process involves finding the midpoints, multiplying them by the frequencies, summing the products, and then dividing by the total frequency. This method provides a reliable average for grouped continuous data.
