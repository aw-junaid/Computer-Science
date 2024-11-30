In **Matplotlib**, a **figure** represents the entire area in which one or more **subplots** (or axes) can be placed. It is essentially the "canvas" on which all your plots, including axes, titles, labels, and other elements, are drawn.

A **figure** can contain multiple **axes** (plots) arranged in various layouts. You can also adjust the figure size, resolution (DPI), and add extra elements like legends, text, and annotations.

### Key Concepts:
- **Figure**: The overall container for a plot or multiple plots (axes).
- **Axes**: The area within the figure where data is plotted, including the x-axis, y-axis, and the actual plot.

### Creating a Figure

In **Matplotlib**, you typically create a figure implicitly by calling `plt.plot()` or other plotting functions. However, you can also create a figure explicitly using the `plt.figure()` function, which provides more control over the figure's properties.

### Basic Syntax to Create a Figure:
```python
import matplotlib.pyplot as plt

# Create a new figure
fig = plt.figure(figsize=(8, 6))  # width, height in inches
```

### Example: Creating a Figure

```python
import matplotlib.pyplot as plt
import numpy as np

# Create a figure
fig = plt.figure(figsize=(8, 6))  # Set the figure size

# Add a single subplot (axes) to the figure
ax = fig.add_subplot(111)  # 1 row, 1 column, 1st subplot

# Data
x = np.linspace(0, 10, 100)
y = np.sin(x)

# Plot data on the axes
ax.plot(x, y)

# Add title and labels
ax.set_title("Sine Wave")
ax.set_xlabel("X-axis")
ax.set_ylabel("Y-axis")

# Show the plot
plt.show()
```

### Understanding `plt.figure()` Parameters
- **`figsize`**: Specifies the size of the figure in inches as a tuple `(width, height)`.
- **`dpi`**: Dots per inch, controls the resolution of the figure (default is 100).
- **`facecolor`**: Background color of the figure (default is `'w'`, white).
- **`edgecolor`**: Color of the border surrounding the figure (default is `'w'`).
- **`tight_layout`**: Automatically adjust subplot parameters to give specified padding (useful to avoid overlapping).

```python
fig = plt.figure(figsize=(8, 6), dpi=200, facecolor='lightgray')
```

### Creating Multiple Subplots in a Figure

A figure can contain multiple **subplots** (or axes). This is done using the `add_subplot()` method or the `plt.subplots()` function. The `add_subplot()` method places a subplot in a grid defined by the number of rows and columns.

#### Example: Multiple Subplots with `add_subplot()`

```python
import matplotlib.pyplot as plt
import numpy as np

# Create a figure
fig = plt.figure(figsize=(10, 6))

# First subplot (1 row, 2 columns, 1st subplot)
ax1 = fig.add_subplot(121)
x = np.linspace(0, 10, 100)
y1 = np.sin(x)
ax1.plot(x, y1, label="Sine Wave")
ax1.set_title("Sine Wave")

# Second subplot (1 row, 2 columns, 2nd subplot)
ax2 = fig.add_subplot(122)
y2 = np.cos(x)
ax2.plot(x, y2, label="Cosine Wave", color='r')
ax2.set_title("Cosine Wave")

# Show the plot
plt.show()
```

#### Explanation:
- **`add_subplot(121)`**: Adds a subplot in a grid with 1 row and 2 columns, placing the plot in the first position.
- **`add_subplot(122)`**: Adds a subplot in the second position.

#### Example: Using `plt.subplots()`

The `plt.subplots()` function provides an easier and more flexible way to create multiple subplots.

```python
import matplotlib.pyplot as plt
import numpy as np

# Create a 2x2 grid of subplots
fig, axes = plt.subplots(2, 2, figsize=(10, 8))

# Data
x = np.linspace(0, 10, 100)
y1 = np.sin(x)
y2 = np.cos(x)

# First subplot (top-left)
axes[0, 0].plot(x, y1, label="Sine")
axes[0, 0].set_title("Sine Wave")

# Second subplot (top-right)
axes[0, 1].plot(x, y2, label="Cosine", color='r')
axes[0, 1].set_title("Cosine Wave")

# Third subplot (bottom-left)
axes[1, 0].plot(x, y1**2, label="Sine Squared", color='g')
axes[1, 0].set_title("Sine Squared")

# Fourth subplot (bottom-right)
axes[1, 1].plot(x, np.sqrt(x), label="Square Root", color='b')
axes[1, 1].set_title("Square Root")

# Show the plot
plt.tight_layout()
plt.show()
```

#### Explanation:
- **`plt.subplots(2, 2)`** creates a grid of 2 rows and 2 columns, and returns the figure and an array of axes (`axes`).
- **`axes[0, 0]`** accesses the subplot in the first row, first column.
- **`tight_layout()`** adjusts the subplots to ensure that labels and titles don’t overlap.

### Adjusting the Figure Size and DPI

You can adjust the size and DPI of the figure when creating it or later in the script.

#### Example: Changing Figure Size and DPI

```python
# Create a figure with custom size and resolution
fig = plt.figure(figsize=(12, 8), dpi=200)

# Add a single subplot
ax = fig.add_subplot(111)

# Data
x = np.linspace(0, 10, 100)
y = np.sin(x)

# Plot
ax.plot(x, y)

# Show the plot
plt.show()
```

### Saving the Figure

Once you have created your figure, you can save it using the `savefig()` method.

```python
# Save the figure as a PNG file
fig.savefig('my_figure.png', dpi=300)
```

### Summary

- **Figure**: The overall container for your plot(s). A figure can contain multiple axes (subplots).
- **Creating Figures**: Use `plt.figure()` to create a new figure or `plt.subplots()` for creating multiple subplots.
- **Subplots**: Add subplots to a figure using `add_subplot()` or `plt.subplots()`.
- **Customization**: You can control the size, DPI, background color, and other properties of a figure.
- **Saving**: Save the figure to a file using `savefig()`.

The ability to manage figures and subplots efficiently is a key feature of Matplotlib, allowing for complex and organized visualizations.
