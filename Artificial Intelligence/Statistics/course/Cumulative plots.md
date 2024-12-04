### **Cumulative Plots**

A **cumulative plot** (or **cumulative distribution plot**) is a graphical representation of cumulative frequencies or cumulative relative frequencies. It helps visualize the cumulative data and is often used in the analysis of distributions, to show how values accumulate over a given range. These plots are particularly useful for understanding the distribution and spread of data, and for identifying key percentiles, medians, and other measures of central tendency.

### **Types of Cumulative Plots:**
1. **Cumulative Frequency Plot** (or **Ogive**): A plot of the cumulative frequency against the upper boundaries of the class intervals.
2. **Cumulative Relative Frequency Plot**: Similar to a cumulative frequency plot, but instead of actual frequencies, the relative frequencies (proportions or percentages) are plotted.

### **Creating a Cumulative Plot:**

Here’s how you can create a cumulative plot from a frequency distribution:

1. **Prepare the Data**:
   - List the class intervals and the frequencies.
   - Compute the cumulative frequency for each class.

2. **Plot the Data**:
   - On the **x-axis**, plot the upper boundaries of the class intervals.
   - On the **y-axis**, plot the cumulative frequency or cumulative relative frequency.
   - Mark the points for each class interval and connect them with lines to form the cumulative plot.

### **Steps to Create a Cumulative Frequency Plot (Ogive):**

1. **Calculate the Cumulative Frequency**:
   - Start with the first frequency and add subsequent frequencies cumulatively as you move through the dataset.

2. **Plot the Points**:
   - Plot the cumulative frequency at the upper boundary of each class interval.

3. **Connect the Points**:
   - Connect the points to form a smooth curve (or a stepped curve in the case of a discrete cumulative frequency plot).

### **Example Calculation of Cumulative Frequency Plot:**

Consider the following data representing the number of hours studied and the number of students:

| Class Interval (Hours) | Frequency (f) |
|------------------------|---------------|
| 0 - 2                  | 5             |
| 2 - 4                  | 8             |
| 4 - 6                  | 12            |
| 6 - 8                  | 10            |
| 8 - 10                 | 5             |

#### **Step 1: Calculate Cumulative Frequency**

| Class Interval (Hours) | Frequency (f) | Cumulative Frequency (CF) |
|------------------------|---------------|---------------------------|
| 0 - 2                  | 5             | 5                         |
| 2 - 4                  | 8             | 5 + 8 = 13                |
| 4 - 6                  | 12            | 13 + 12 = 25              |
| 6 - 8                  | 10            | 25 + 10 = 35              |
| 8 - 10                 | 5             | 35 + 5 = 40               |

#### **Step 2: Plot the Points**
- Plot the upper boundary of each class interval (2, 4, 6, 8, 10) on the x-axis.
- Plot the cumulative frequency (5, 13, 25, 35, 40) on the y-axis.

#### **Step 3: Draw the Cumulative Plot (Ogive)**

1. Start at the point (2, 5), representing the class interval 0 - 2.
2. Plot the next point (4, 13), then (6, 25), (8, 35), and finally (10, 40).
3. Connect the points with a smooth curve or straight lines.

### **Types of Cumulative Plots:**
1. **Cumulative Frequency Plot (Ogive)**:
   - The ogive is a **non-decreasing curve** that shows the cumulative frequency or cumulative percentage as the data increases.
   - It helps visualize the distribution, showing how the data accumulates.
   - The **steepness** of the curve indicates the density of data in that interval.

2. **Cumulative Relative Frequency Plot**:
   - Instead of absolute frequencies, this plot uses **relative frequencies** (proportions or percentages), which makes it useful when comparing datasets of different sizes.
   - The y-axis represents the cumulative proportion of the data (from 0 to 1 or 0% to 100%).

### **Example of Cumulative Relative Frequency Plot:**
For the same dataset, instead of cumulative frequency, we calculate cumulative relative frequency:

$\[
\text{Relative Frequency of Class Interval} = \frac{\text{Frequency of Class Interval}}{N}
\]$

Where \( N \) is the total number of data points. In this case, \( N = 40 \).

| Class Interval (Hours) | Frequency (f) | Cumulative Frequency (CF) | Relative Frequency | Cumulative Relative Frequency |
|------------------------|---------------|---------------------------|--------------------|------------------------------|
| 0 - 2                  | 5             | 5                         | 5/40 = 0.125       | 0.125                        |
| 2 - 4                  | 8             | 13                        | 8/40 = 0.2         | 0.125 + 0.2 = 0.325          |
| 4 - 6                  | 12            | 25                        | 12/40 = 0.3        | 0.325 + 0.3 = 0.625          |
| 6 - 8                  | 10            | 35                        | 10/40 = 0.25       | 0.625 + 0.25 = 0.875         |
| 8 - 10                 | 5             | 40                        | 5/40 = 0.125       | 0.875 + 0.125 = 1.0          |

The **cumulative relative frequency plot** will show how the cumulative percentage increases, reaching 100% (or 1) at the last class.

### **Applications of Cumulative Plots:**

1. **Identifying Percentiles**: 
   - Cumulative plots are useful for locating specific percentiles, such as the median (50th percentile), quartiles (25th and 75th percentiles), and other percentiles (e.g., 90th percentile).
   - You can draw a horizontal line at the desired percentile (e.g., 50% for the median) and find the corresponding value on the x-axis.

2. **Analyzing Distribution**:
   - Cumulative plots help visualize the shape of the distribution (e.g., symmetric, skewed). A steep rise indicates a high frequency in that interval, while a gradual rise indicates fewer observations.

3. **Comparing Datasets**:
   - You can use cumulative plots to compare the distributions of multiple datasets, looking at which dataset accumulates more quickly and how the distributions differ.

4. **Determining the Proportion of Data Below a Certain Value**:
   - Cumulative plots provide a clear way to find the proportion of data points less than or equal to a specific value.

### **Conclusion:**
Cumulative plots (like **ogives**) are essential tools for visualizing the distribution and spread of data. They help in understanding how data accumulates across intervals, making it easier to identify key features such as percentiles, medians, and distributions. Whether using cumulative frequencies or cumulative relative frequencies, these plots are valuable for comparing datasets and drawing insights from the data.
