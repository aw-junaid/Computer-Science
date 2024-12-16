In LaTeX, mathematical expressions are written in **math mode**. LaTeX provides a wide range of tools to format and display mathematical formulas clearly. Below is a breakdown of how to handle various mathematical expressions in LaTeX:

---

### **1. Subscripts and Superscripts**

- **Subscripts**: Use the underscore (`_`) for subscripts.
- **Superscripts**: Use the caret (`^`) for superscripts.

#### **Example:**
```latex
a_i \quad x^2
```
- This renders as: \( a_i \quad x^2 \)

If you need both a subscript and superscript, enclose the entire expression in curly braces `{}`.

```latex
a_{i,j} \quad x^{2n}
```
- This renders as: \( a_{i,j} \quad x^{2n} \)

---

### **2. Brackets and Parentheses**

You can use various types of brackets and parentheses in LaTeX, including `()`, `[]`, `{}`, and `||`.

#### **Example:**
```latex
( a + b ) \quad \left[ \frac{x}{y} \right] \quad \{ x + y \}
```
- This renders as: \( ( a + b ) \quad \left[ \frac{x}{y} \right] \quad \{ x + y \} \)

Use `\left` and `\right` to automatically scale the brackets to the size of the enclosed expression.

---

### **3. Fractions and Binomials**

- **Fractions**: Use `\frac{numerator}{denominator}` for fractions.
- **Binomials**: Use `\binom{n}{k}` for binomial coefficients.

#### **Example:**
```latex
\frac{a}{b} \quad \binom{n}{k}
```
- This renders as: \( \frac{a}{b} \quad \binom{n}{k} \)

---

### **4. Aligning Equations**

To align equations in LaTeX, use the `align` environment from the `amsmath` package. Each equation or part of the equation is separated by `&`, and the line breaks are created using `\\`.

#### **Example:**
```latex
\usepackage{amsmath}

\begin{align}
a + b &= c \\
x + y &= z
\end{align}
```
- This renders as:
\[
a + b = c
\]
\[
x + y = z
\]

You can align at multiple points within the equations by adding more `&` symbols.

---

### **5. Operators**

In LaTeX, operators such as summation, product, and integral signs are written using commands like `\sum`, `\prod`, `\int`, etc.

#### **Example:**
```latex
\sum_{i=1}^{n} i \quad \int_{0}^{\infty} e^{-x} \, dx
```
- This renders as: 
\[
\sum_{i=1}^{n} i \quad \int_{0}^{\infty} e^{-x} \, dx
\]

You can adjust the limits of these operators using subscripts and superscripts.

---

### **6. Spacing in Math Mode**

LaTeX allows you to add space between terms in math mode using commands like `\quad`, `\qquad`, `\,`, `\:`, etc.

- **`\,`**: Thin space
- **`\:`**: Medium space
- **`\;`**: Thick space
- **`\quad`**: Larger space
- **`\qquad`**: Extra large space

#### **Example:**
```latex
a + b \quad \text{and} \quad x + y
```
- This renders as: \( a + b \quad \text{and} \quad x + y \)

---

### **7. Integrals, Sums, and Limits**

- **Integrals**: Use `\int`, and you can specify the limits with subscripts and superscripts.
- **Sums and Limits**: Use `\sum`, `\prod`, `\lim`, etc.

#### **Example:**
```latex
\int_{0}^{\infty} x^2 \, dx \quad \sum_{n=1}^{\infty} \frac{1}{n^2}
```
- This renders as:
\[
\int_{0}^{\infty} x^2 \, dx \quad \sum_{n=1}^{\infty} \frac{1}{n^2}
\]

To display limits at the top and bottom (like summation and integrals), use the display style `\displaystyle`:

```latex
\displaystyle \sum_{n=1}^{\infty} \frac{1}{n^2}
```

---

### **8. Display Style in Math Mode**

The **display style** in LaTeX makes equations larger and center them on their own line. To use display style outside of a block, use the `\[ \]` or `equation` environment.

#### **Example:**
```latex
\[
E = mc^2
\]
```
- This renders as:
\[
E = mc^2
\]

For inline equations, use the `$` signs:

```latex
This is an inline equation: $E = mc^2$
```

---

### **9. List of Greek Letters and Math Symbols**

Here’s a list of commonly used Greek letters and math symbols in LaTeX:

#### **Greek Letters:**
- Lowercase: `\alpha`, `\beta`, `\gamma`, `\delta`, `\epsilon`, `\zeta`, `\eta`, `\theta`, `\iota`, `\kappa`, `\lambda`, `\mu`, `\nu`, `\xi`, `\pi`, `\rho`, `\sigma`, `\tau`, `\upsilon`, `\phi`, `\chi`, `\psi`, `\omega`
- Uppercase: `\Gamma`, `\Delta`, `\Theta`, `\Lambda`, `\Xi`, `\Pi`, `\Sigma`, `\Upsilon`, `\Phi`, `\Psi`, `\Omega`

#### **Math Symbols:**
- Plus-minus: `\pm`
- Infinity: `\infty`
- Not equal: `\neq`
- Greater than: `\gt`
- Less than: `\lt`
- Element of: `\in`
- Set notation: `\cup`, `\cap`, `\subset`, `\supset`

---

### **10. Mathematical Fonts**

To change the font style of the text in math mode:

- **Normal math font**: Just type as usual.
- **Bold math**: `\mathbf{}` for bold text.
- **Italic math**: `\mathit{}` for italic text (this is usually the default).
- **Sans-serif math**: `\mathsf{}` for sans-serif font.
- **Typewriter (monospace) math**: `\mathtt{}` for typewriter font.

#### **Example:**
```latex
\mathbf{A} + \mathit{b} \quad \mathsf{X} \quad \mathtt{y}
```
- This renders as: \( \mathbf{A} + \mathit{b} \quad \mathsf{X} \quad \mathtt{y} \)

---

### **Conclusion**

LaTeX provides powerful tools for writing complex mathematical expressions. Using the above commands, you can handle a wide range of mathematical notation, from simple subscripts and superscripts to advanced symbols and operators.
