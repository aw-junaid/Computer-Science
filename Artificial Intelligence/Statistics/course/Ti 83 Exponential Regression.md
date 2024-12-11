### **TI-83 Exponential Regression**

The **TI-83** calculator is a powerful tool for performing various statistical analyses, including **exponential regression**. Exponential regression is used to model relationships where data can be best described by an exponential function of the form:

$\[
y = ab^x
\]$
Where:
- \( y \) is the dependent variable
- \( x \) is the independent variable
- \( a \) is the initial value (the value of \( y \) when \( x = 0 \))
- \( b \) is the base of the exponential function (growth or decay factor)

### **Steps to Perform Exponential Regression on the TI-83**

To perform exponential regression on the TI-83, follow these steps:

#### **1. Enter the Data**
- Press the **`STAT`** button.
- Choose **`1:Edit`** to enter the data into lists. 
- Enter your **x-values** in **List 1 (L1)** and your **y-values** in **List 2 (L2)**.
  - For example:
    - L1: \( 1, 2, 3, 4, 5 \)
    - L2: \( 3, 6, 12, 24, 48 \)

#### **2. Set Up the Regression**
- Press the **`STAT`** button again.
- Use the **right arrow key** to scroll to the **`CALC`** menu.
- Choose **`0: ExpReg`** (Exponential Regression) from the list.

#### **3. Perform the Regression**
- After selecting **`ExpReg`**, the calculator will ask for the list of x-values (L1) and y-values (L2).
  - Confirm that **L1** and **L2** are correct. If not, type the appropriate list names.
- Press **`ENTER`** to perform the regression.

#### **4. View the Results**
- The TI-83 will display the regression equation in the form:
  $\[
  y = a \cdot b^x
  \]$
  - It will also show the values of **a** and **b** along with the **correlation coefficient (r)**, which indicates how well the model fits the data.
  - For example, the output may look like:
    $\[
    y = 3.000 \cdot 2.000^x
    \]$
    This means that the exponential function modeling the data is $\( y = 3 \cdot 2^x \)$, with **a = 3** and **b = 2**.

#### **5. Optional: Plot the Data and Regression Curve**
- To plot the data and the regression curve on the same graph:
  - Press **`Y=`** to access the function editor.
  - Enter the exponential regression equation (using the values for \( a \) and \( b \) that you just found) in **Y1**.
  - To plot the data points, press **`STAT PLOT`** by pressing **`2nd`** then **`Y=`**.
  - Choose **Plot 1**, and select the type of plot (scatter plot is usually the best for data points).
  - Ensure that the **Xlist** and **Ylist** are set to **L1** and **L2** respectively.
  - Press **`GRAPH`** to display the data and the fitted exponential curve.

---

### **Example:**

Let’s say you have the following data for the number of bacteria in a culture at different time points:

| Time (hours) | Number of Bacteria |
|--------------|--------------------|
| 1            | 4                  |
| 2            | 8                  |
| 3            | 16                 |
| 4            | 32                 |
| 5            | 64                 |

#### **Step-by-Step on the TI-83:**
1. **Enter the data**:
   - In **L1**, enter: `1, 2, 3, 4, 5`
   - In **L2**, enter: `4, 8, 16, 32, 64`

2. **Select Exponential Regression**:
   - Press **`STAT`**, then arrow to **`CALC`**, and select **`ExpReg`**.
   
3. **View the results**:
   - The calculator will give an equation like:
     $\[
     y = 4.000 \cdot 2^x
     \]$
   This means the number of bacteria grows exponentially, with an initial population of **4** and a growth factor of **2**.

4. **Plot the data and curve**:
   - Go to **`Y=`**, enter `4 * 2^X` in **Y1**.
   - Set up the plot and graph to see the data points and the regression curve.

---

### **Interpreting the Results:**

- **\( a \)** (initial value): This is the value of \( y \) when \( x = 0 \). In our example, \( a = 4 \), meaning the bacteria population starts at 4.
- **\( b \)** (growth/decay factor): This value determines the rate of growth (if \( b > 1 \)) or decay (if \( 0 < b < 1 \)). In the example, \( b = 2 \), which indicates the population doubles every hour.
- **\( r \)** (correlation coefficient): This tells you how well the exponential model fits the data. A value close to 1 means the model fits the data well.

---

### **Conclusion:**

Using **Exponential Regression** on the **TI-83** is a simple way to model data that grows or decays exponentially. Once you have your regression equation, you can use it for predictions, analyzing trends, or making further statistical inferences.
