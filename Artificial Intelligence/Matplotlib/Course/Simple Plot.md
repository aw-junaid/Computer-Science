Creating a **simple plot** in **Matplotlib** is very easy and involves just a few lines of code. Below, I'll show you how to create a basic line plot, a scatter plot, and a bar plot, using **Matplotlib**.

### 1. **Basic Line Plot**

A line plot is the most common type of plot. It shows data points connected by a line, ideal for visualizing trends over time or continuous data.

```python
import matplotlib.pyplot as plt
import numpy as np

# Data
x = np.linspace(0, 10, 100)  # 100 points from 0 to 10
y = np.sin(x)  # Sine of x

# Create the plot
plt.plot(x, y)

# Add title and labels
plt.title("Simple Line Plot")
plt.xlabel("X-axis")
plt.ylabel("Y-axis")

# Show the plot
plt.show()
```

#### Explanation:
- **`np.linspace(0, 10, 100)`** creates 100 equally spaced points from 0 to 10.
- **`np.sin(x)`** calculates the sine of each point in `x`.
- **`plt.plot(x, y)`** plots the values of `x` vs `y`.

### 2. **Simple Scatter Plot**

A scatter plot is useful for showing the relationship between two variables by plotting individual data points.

```python
import matplotlib.pyplot as plt
import numpy as np

# Data
x = np.random.rand(50)  # 50 random values for x
y = np.random.rand(50)  # 50 random values for y

# Create a scatter plot
plt.scatter(x, y)

# Add title and labels
plt.title("Simple Scatter Plot")
plt.xlabel("X-axis")
plt.ylabel("Y-axis")

# Show the plot
plt.show()
```

#### Explanation:
- **`np.random.rand(50)`** generates 50 random numbers between 0 and 1 for `x` and `y`.
- **`plt.scatter(x, y)`** creates the scatter plot using `x` and `y` as coordinates.

### 3. **Simple Bar Plot**

A bar plot is typically used for categorical data and displays data as rectangular bars.

```python
import matplotlib.pyplot as plt

# Data
categories = ['A', 'B', 'C', 'D']
values = [3, 7, 2, 5]

# Create a bar plot
plt.bar(categories, values)

# Add title and labels
plt.title("Simple Bar Plot")
plt.xlabel("Categories")
plt.ylabel("Values")

# Show the plot
plt.show()
```

#### Explanation:
- **`categories`** is a list of category names.
- **`values`** is a list of corresponding values for each category.
- **`plt.bar(categories, values)`** creates the bar chart with the categories on the x-axis and values on the y-axis.

### 4. **Simple Histogram**

A histogram is used to show the distribution of data, typically useful for continuous data.

```python
import matplotlib.pyplot as plt
import numpy as np

# Data
data = np.random.randn(1000)  # 1000 random numbers from a normal distribution

# Create a histogram
plt.hist(data, bins=30)

# Add title and labels
plt.title("Simple Histogram")
plt.xlabel("Value")
plt.ylabel("Frequency")

# Show the plot
plt.show()
```

#### Explanation:
- **`np.random.randn(1000)`** generates 1000 random numbers from a normal distribution (mean = 0, std deviation = 1).
- **`plt.hist(data, bins=30)`** creates the histogram with 30 bins.

### Summary:
- **Line Plot**: Ideal for visualizing continuous data.
- **Scatter Plot**: Used to visualize relationships between two variables.
- **Bar Plot**: Typically used for categorical data.
- **Histogram**: Useful for showing data distribution.

These are the basic types of plots that you can create with **Matplotlib**. As you advance, you can add more customizations, such as different line styles, colors, markers, and annotations.
