LaTeX is widely known for its ability to handle complex mathematical notation. It provides several ways to display math, including **inline math mode** for expressions within text and **display math mode** for equations on their own lines.

---

### **1. Inline Math Mode**
Inline math mode allows you to insert mathematical expressions within a paragraph of text.

#### **Basic Syntax**
To enter inline math mode, enclose your mathematical expression with **dollar signs** (`$ ... $`).

**Example:**
```latex
This is an inline equation: $E = mc^2$.
```

**Output:**
This is an inline equation: \( E = mc^2 \).

---

### **2. Display Math Mode**
Display math mode is used for equations that should be centered on their own line, typically used for longer or more complex equations.

#### **Basic Syntax**
To enter display math mode, enclose your expression with double dollar signs (`$$ ... $$`), or more commonly, use the `\[ ... \]` environment (preferred for better compatibility with other LaTeX packages).

**Example:**
```latex
\[
E = mc^2
\]
```

**Output:**
\[
E = mc^2
\]

---

### **3. More Complete Examples**

#### **1. Simple Inline and Display Math**
```latex
\documentclass{article}
\usepackage{amsmath} % For advanced math features

\begin{document}

Here is an inline equation: $a^2 + b^2 = c^2$.

And here is the same equation displayed:
\[
a^2 + b^2 = c^2
\]

\end{document}
```

#### **2. Adding Fractions, Exponents, and Subscripts**
Math mode allows you to easily typeset fractions, exponents, and subscripts.

**Example:**
```latex
\documentclass{article}
\usepackage{amsmath}

\begin{document}

Inline math example: $y = \frac{1}{x^2 + 1}$.

Display math example:
\[
y = \frac{1}{x^2 + 1}
\]

\end{document}
```

**Output:**
Inline: \( y = \frac{1}{x^2 + 1} \)  
Display:
\[
y = \frac{1}{x^2 + 1}
\]

---

#### **3. Aligning Multiple Equations**
For aligning multiple equations, the `align` environment from the `amsmath` package is useful.

**Example:**
```latex
\documentclass{article}
\usepackage{amsmath}

\begin{document}

\begin{align}
    x &= 3y + 4 \\
    y &= 2x - 1
\end{align}

\end{document}
```

**Output:**
\[
x = 3y + 4
\]
\[
y = 2x - 1
\]
The `&` symbol is used to align equations at the equal signs.

---

#### **4. Displaying Sums, Integrals, and More**
You can also display summations, integrals, and other math symbols.

**Example:**
```latex
\documentclass{article}
\usepackage{amsmath}

\begin{document}

Here is an inline summation: $\sum_{n=1}^{\infty} \frac{1}{n^2}$.

Here is a display-style integral:
\[
\int_{0}^{\infty} e^{-x^2} dx
\]

\end{document}
```

**Output:**
Inline: \( \sum_{n=1}^{\infty} \frac{1}{n^2} \)  
Display:
\[
\int_{0}^{\infty} e^{-x^2} dx
\]

---

### **5. Additional Math Elements**

#### **Greek Letters**
You can use Greek letters for variables, constants, and functions in LaTeX.

**Example:**
```latex
\documentclass{article}
\usepackage{amsmath}

\begin{document}

Inline math: $\alpha + \beta = \gamma$.

Display math:
\[
\Delta x = \frac{1}{2} \cdot \omega t^2
\]

\end{document}
```

**Output:**
Inline: \( \alpha + \beta = \gamma \)  
Display:  
\[
\Delta x = \frac{1}{2} \cdot \omega t^2
\]

---

### **6. Common Math Symbols and Notations**
- **Fractions**: `\frac{numerator}{denominator}`
- **Superscripts (Exponents)**: `x^2`, `x^{n+1}`
- **Subscripts**: `a_i`, `x_{i,j}`
- **Sums**: `\sum_{i=1}^{n} x_i`
- **Integrals**: `\int_a^b f(x) dx`
- **Square Roots**: `\sqrt{x}`

---

### **7. Full Example**
Here’s a LaTeX document with inline and display math, including several common symbols:

```latex
\documentclass{article}
\usepackage{amsmath}

\begin{document}

Here is an inline equation: $a^2 + b^2 = c^2$.

Now a more complex example with fractions, sums, and exponents:

\[
f(x) = \sum_{i=1}^{n} \frac{x_i^2}{\left( \sum_{i=1}^{n} x_i \right)^2}
\]

For the integral of a Gaussian function:
\[
\int_{-\infty}^{\infty} e^{-x^2} dx = \sqrt{\pi}
\]

\end{document}
```

---

### **8. Tips and Best Practices**
- Use `\left` and `\right` for automatically resizing parentheses, brackets, and other delimiters:
  ```latex
  \left( \frac{a}{b} \right)
  ```

- Use `amsmath` for advanced math features like `align`, `gather`, `multline`, and more.

- Keep math expressions concise in inline mode; for complex equations, use display math for better readability.

