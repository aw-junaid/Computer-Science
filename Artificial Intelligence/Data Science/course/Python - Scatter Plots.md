### Python - Scatter Plots

**Scatter plots** are one of the most commonly used types of plots in data visualization. They show the relationship between two continuous variables by plotting individual data points on a two-dimensional graph. Each point represents a pair of values, where one variable is plotted on the x-axis and the other on the y-axis. Scatter plots are useful for identifying correlations, trends, and patterns in data.

In Python, **Matplotlib** and **Seaborn** are two popular libraries to create and customize scatter plots.

---

### 1. **Creating Scatter Plots with Matplotlib**

**Matplotlib** provides the `scatter()` function to create scatter plots.

#### Example: Basic Scatter Plot

```python
import matplotlib.pyplot as plt
import numpy as np

# Example data
x = np.random.rand(100)  # 100 random numbers for x-axis
y = np.random.rand(100)  # 100 random numbers for y-axis

# Create scatter plot
plt.scatter(x, y)

# Add title and labels
plt.title('Basic Scatter Plot')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')

# Display the plot
plt.show()
```

In this example:
- `x` and `y`: Data points for the x and y axes.
- `plt.scatter(x, y)`: Creates the scatter plot.

#### Customizing Scatter Plots in Matplotlib

You can customize scatter plots in many ways, including modifying colors, sizes, and adding markers.

```python
# Customizing scatter plot
plt.scatter(x, y, color='red', s=50, marker='o', alpha=0.6)

# Add title and labels
plt.title('Customized Scatter Plot')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')

plt.show()
```

- `color='red'`: Changes the color of the points.
- `s=50`: Adjusts the size of the points.
- `marker='o'`: Changes the marker style (other options: 'x', '+', '*', etc.).
- `alpha=0.6`: Adjusts the transparency of the points (0 = transparent, 1 = fully opaque).

#### Scatter Plot with Multiple Data Series

You can plot multiple data series in the same scatter plot by calling `scatter()` multiple times.

```python
x1 = np.random.rand(100)
y1 = np.random.rand(100)

x2 = np.random.rand(100)
y2 = np.random.rand(100)

plt.scatter(x1, y1, color='blue', label='Dataset 1', alpha=0.6)
plt.scatter(x2, y2, color='green', label='Dataset 2', alpha=0.6)

# Add title and labels
plt.title('Multiple Data Series in Scatter Plot')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.legend()

plt.show()
```

- `label`: Adds a legend entry for each dataset.
- `plt.legend()`: Displays the legend on the plot.

#### Scatter Plot with Regression Line (Best Fit Line)

You can add a regression line (a line of best fit) to the scatter plot by using `numpy.polyfit()` to calculate the line's slope and intercept.

```python
# Fit a line (polynomial of degree 1)
slope, intercept = np.polyfit(x, y, 1)
line = slope * x + intercept

# Create scatter plot
plt.scatter(x, y, color='purple', alpha=0.6)

# Plot the regression line
plt.plot(x, line, color='black', linewidth=2, label='Best Fit Line')

# Add title and labels
plt.title('Scatter Plot with Best Fit Line')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.legend()

plt.show()
```

- `np.polyfit(x, y, 1)`: Fits a polynomial of degree 1 (a straight line) to the data.
- `plt.plot(x, line)`: Plots the best fit line.

---

### 2. **Creating Scatter Plots with Seaborn**

**Seaborn** simplifies the creation of scatter plots and adds more powerful features like automatic color mapping, regression lines, and better integration with Pandas DataFrames.

#### Example: Basic Scatter Plot

```python
import seaborn as sns
import matplotlib.pyplot as plt

# Example dataset: Seaborn's 'tips' dataset
tips = sns.load_dataset('tips')

# Create a basic scatter plot
sns.scatterplot(x='total_bill', y='tip', data=tips)

# Add title and labels
plt.title('Scatter Plot of Total Bill vs Tip')
plt.show()
```

In this example:
- `x='total_bill'` and `y='tip'`: Columns from the `tips` DataFrame.
- `data=tips`: Specifies the dataset.

#### Customizing Scatter Plots in Seaborn

You can customize scatter plots in Seaborn using the `hue`, `size`, and `style` parameters to add more dimensions to the plot.

```python
sns.scatterplot(x='total_bill', y='tip', data=tips, hue='time', size='size', style='sex')

# Add title and labels
plt.title('Scatter Plot with Hue, Size, and Style')
plt.show()
```

- `hue='time'`: Color points based on the 'time' column (Lunch/Dinner).
- `size='size'`: Adjust the size of points based on the 'size' column (number of people).
- `style='sex'`: Use different markers for male/female.

#### Adding a Regression Line to Scatter Plot

You can add a regression line to a scatter plot using the `sns.regplot()` function.

```python
sns.regplot(x='total_bill', y='tip', data=tips, scatter_kws={'color': 'blue'}, line_kws={'color': 'red'})

# Add title and labels
plt.title('Scatter Plot with Regression Line')
plt.show()
```

- `sns.regplot()`: Creates a scatter plot with a regression line (best fit line).
- `scatter_kws={'color': 'blue'}`: Customizes the scatter plot points.
- `line_kws={'color': 'red'}`: Customizes the regression line.

#### Scatter Plot with a Custom Palette

You can use Seaborn’s color palettes to change the color scheme of the plot.

```python
sns.scatterplot(x='total_bill', y='tip', data=tips, palette='coolwarm', hue='sex')

# Add title and labels
plt.title('Scatter Plot with Custom Color Palette')
plt.show()
```

- `palette='coolwarm'`: Specifies a color palette for the plot.
- `hue='sex'`: Colors the points based on the 'sex' column.

---

### 3. **3D Scatter Plot with Matplotlib**

If you need to visualize relationships between three variables, you can create a 3D scatter plot using **Matplotlib’s `Axes3D`** module.

```python
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import matplotlib.pyplot as plt

# Generate random data
x = np.random.rand(100)
y = np.random.rand(100)
z = np.random.rand(100)

# Create 3D scatter plot
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(x, y, z)

# Add title and labels
ax.set_title('3D Scatter Plot')
ax.set_xlabel('X-axis')
ax.set_ylabel('Y-axis')
ax.set_zlabel('Z-axis')

plt.show()
```

- `projection='3d'`: Specifies that the plot should be in 3D.
- `ax.scatter(x, y, z)`: Plots the points in 3D space.

---

### 4. **Scatter Plot with Different Marker Sizes and Colors**

Scatter plots can use **different marker sizes** and **colors** to represent additional dimensions of the data.

```python
# Example dataset
x = np.random.rand(100)
y = np.random.rand(100)
sizes = np.random.rand(100) * 100  # Marker sizes
colors = np.random.rand(100)  # Marker colors

# Create scatter plot with varying marker sizes and colors
plt.scatter(x, y, s=sizes, c=colors, cmap='viridis', alpha=0.7)

# Add title and labels
plt.title('Scatter Plot with Varying Marker Sizes and Colors')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')

plt.colorbar()  # Show color scale
plt.show()
```

- `s=sizes`: Changes the size of the markers.
- `c=colors`: Changes the color of the markers.
- `cmap='viridis'`: Specifies the color map for the plot.
- `alpha=0.7`: Adjusts transparency.

---

### Conclusion

**Scatter plots** are a powerful way to visualize the relationship between two continuous variables. In Python, both **Matplotlib** and **Seaborn** provide flexible options to create and customize scatter plots:
- **Matplotlib** offers fine-grained control over markers, colors, and other plot elements.
- **Seaborn** simplifies the creation of scatter plots and adds additional features like color mapping, regression lines, and easy integration with Pandas DataFrames.

These plots are essential tools for exploring data, identifying correlations, and uncovering patterns or trends.
