In LaTeX, you can easily apply **bold**, *italics*, and underlining to text using specific commands. Here's how:

---

### **1. Bold Text**
To make text bold, use the `\textbf{}` command:
```latex
\textbf{This text is bold.}
```

---

### **2. Italic Text**
To italicize text, use the `\textit{}` command:
```latex
\textit{This text is italicized.}
```

---

### **3. Underlined Text**
To underline text, use the `\underline{}` command:
```latex
\underline{This text is underlined.}
```

---

### **4. Combining Styles**
You can combine bold, italics, and underlining by nesting commands:
```latex
\textbf{\textit{This text is bold and italicized.}}
\underline{\textbf{This text is bold and underlined.}}
```

---

### **5. Example Usage**
Here’s how you might use these styles in a LaTeX document:
```latex
\documentclass{article}
\begin{document}

Here is some \textbf{bold text}, some \textit{italic text}, and some \underline{underlined text}.

You can also combine them, like \textbf{\textit{bold and italicized}}, or \underline{\textbf{bold and underlined}}.

\end{document}
```

---

### **6. Advanced Options**

#### **Using Custom Fonts for Emphasis**
In addition to basic bold and italic styles, LaTeX supports other font styles:
- **Sans-serif Bold**: Use the `\textsf{\textbf{}}` command.
  ```latex
  \textsf{\textbf{This is sans-serif bold text.}}
  ```
- **Monospace Bold**: Use the `\texttt{\textbf{}}` command.
  ```latex
  \texttt{\textbf{This is monospace bold text.}}
  ```

#### **Avoid Overusing Underlining**
Underlining is less common in modern typesetting. Instead of underlining for emphasis, consider bold or italics.

#### **Adding Color**
You can also add color using the `xcolor` package:
```latex
\usepackage{xcolor}

\textbf{\textcolor{red}{This is bold and red.}}
\textit{\textcolor{blue}{This is italicized and blue.}}
```

---

