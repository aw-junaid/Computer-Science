In **Matplotlib**, **colormap normalization** is used to control how data values are mapped to colors within a colormap. By normalizing data, you can specify which value ranges correspond to specific colors, allowing you to highlight or compress specific parts of your data.

Normalization is particularly useful for:
- **Enhancing contrasts** in certain data ranges.
- Mapping **outliers** to more distinct colors.
- **Standardizing** the color mapping when comparing multiple datasets.

### Normalization Classes in Matplotlib

Matplotlib provides several classes to normalize data values:

1. **Normalize**: The most common normalization class, which linearly scales data to a range of [0, 1].
2. **LogNorm**: For logarithmic scaling, useful when data spans several orders of magnitude.
3. **SymLogNorm**: For symmetric logarithmic scaling, useful when data contains both positive and negative values with large ranges.
4. **PowerNorm**: Scales data using a power-law normalization, where you can specify the exponent.
5. **BoundaryNorm**: Maps data values to specific colors in non-uniform ways, suitable for categorical data or data with predefined intervals.

### Using `Normalize` for Linear Normalization

The `Normalize` class linearly scales data to fit within a colormap range of 0 to 1.

```python
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.colors as mcolors

# Generate random data
data = np.random.rand(10, 10) * 10  # Data ranging from 0 to 10

# Set normalization range
norm = mcolors.Normalize(vmin=2, vmax=8)  # Map values between 2 and 8 to colormap range

# Plot heatmap
plt.imshow(data, cmap='viridis', norm=norm)
plt.colorbar()
plt.title("Heatmap with Linear Normalization (2-8)")
plt.show()
```

In this example:
- `Normalize(vmin=2, vmax=8)` maps values between 2 and 8 to the colormap range of [0, 1]. Values outside this range are clipped to the nearest boundary.

### Using `LogNorm` for Logarithmic Scaling

The `LogNorm` class is useful for data with a large dynamic range, particularly when values span several orders of magnitude.

```python
from matplotlib.colors import LogNorm

# Generate data with large dynamic range
data = np.random.rand(10, 10) * 1000  # Data from 0 to 1000

# Apply logarithmic normalization
norm = LogNorm(vmin=1, vmax=1000)

# Plot heatmap
plt.imshow(data, cmap='plasma', norm=norm)
plt.colorbar()
plt.title("Heatmap with Logarithmic Normalization")
plt.show()
```

In this example:
- `LogNorm(vmin=1, vmax=1000)` applies a logarithmic scale, making it easier to visualize both small and large values.

### Using `SymLogNorm` for Symmetric Logarithmic Scaling

`SymLogNorm` is helpful for data that has both positive and negative values with a large range, allowing for logarithmic scaling around zero.

```python
from matplotlib.colors import SymLogNorm

# Generate data with positive and negative values
data = np.random.randn(10, 10) * 100  # Data centered around 0

# Apply symmetric logarithmic normalization
norm = SymLogNorm(linthresh=10, vmin=-100, vmax=100)

# Plot heatmap
plt.imshow(data, cmap='coolwarm', norm=norm)
plt.colorbar()
plt.title("Heatmap with Symmetric Logarithmic Normalization")
plt.show()
```

In this example:
- `SymLogNorm(linthresh=10)` applies linear scaling near zero (between -10 and 10) and logarithmic scaling for values outside this range, making both positive and negative data easier to interpret.

### Using `PowerNorm` for Power-Law Scaling

The `PowerNorm` class scales data using a power-law relationship, with an exponent that you can specify.

```python
from matplotlib.colors import PowerNorm

# Generate random data
data = np.random.rand(10, 10) ** 3  # Cubed data, enhancing low values

# Apply power-law normalization
norm = PowerNorm(gamma=0.5)  # Gamma < 1 enhances low values; gamma > 1 compresses them

# Plot heatmap
plt.imshow(data, cmap='inferno', norm=norm)
plt.colorbar()
plt.title("Heatmap with Power-Law Normalization (gamma=0.5)")
plt.show()
```

In this example:
- `PowerNorm(gamma=0.5)` makes low values more visible by using a gamma value less than 1, applying a power-law transformation to emphasize smaller data values.

### Using `BoundaryNorm` for Custom Binned Normalization

`BoundaryNorm` is used to map specific data ranges to colors in a colormap. This is useful for categorical data or when you want specific intervals to have distinct colors.

```python
from matplotlib.colors import BoundaryNorm

# Generate random data
data = np.random.rand(10, 10) * 10  # Data from 0 to 10

# Define color boundaries and colormap
bounds = [0, 2, 4, 6, 8, 10]
norm = BoundaryNorm(bounds, ncolors=5, clip=True)  # 5 colors for 5 intervals

# Plot heatmap
plt.imshow(data, cmap='viridis', norm=norm)
plt.colorbar(ticks=bounds)
plt.title("Heatmap with Binned Normalization")
plt.show()
```

In this example:
- `BoundaryNorm(bounds, ncolors=5)` maps each interval (0–2, 2–4, etc.) to a distinct color, making it suitable for binned data or discrete categories.

### Combining Normalization with Colormaps in Subplots

You can apply different normalizations to subplots for better comparison of data distributions.

```python
# Generate random data
data1 = np.random.rand(10, 10) * 10
data2 = np.random.rand(10, 10) * 100

# Create figure and subplots
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 5))

# Linear normalization for the first subplot
norm1 = mcolors.Normalize(vmin=0, vmax=10)
im1 = ax1.imshow(data1, cmap='viridis', norm=norm1)
ax1.set_title("Linear Normalization")
fig.colorbar(im1, ax=ax1)

# Logarithmic normalization for the second subplot
norm2 = LogNorm(vmin=1, vmax=100)
im2 = ax2.imshow(data2, cmap='plasma', norm=norm2)
ax2.set_title("Logarithmic Normalization")
fig.colorbar(im2, ax=ax2)

plt.show()
```

In this example:
- Linear normalization is applied to `data1`, and logarithmic normalization is applied to `data2`, making it easy to compare the data distributions across subplots.

### Summary

1. **Normalize**: Scales data linearly between specified min and max values.
2. **LogNorm**: Applies a logarithmic scale for data with large ranges.
3. **SymLogNorm**: Uses linear scaling near zero and logarithmic scaling for larger magnitudes, ideal for positive and negative data.
4. **PowerNorm**: Applies power-law scaling to emphasize small or large values depending on the gamma exponent.
5. **BoundaryNorm**: Maps data to discrete colors based on intervals, suitable for categorical or binned data.

Normalization in Matplotlib gives you powerful control over how data is represented visually, enhancing the interpretability of your plots based on the distribution of your data.
