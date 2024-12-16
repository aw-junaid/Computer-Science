Writing your first LaTeX document is easier than you might think! Here’s a step-by-step guide to help you create a basic document from scratch.

---

### **1. Set Up Your LaTeX Environment**
You’ll need a LaTeX editor and compiler. Popular options include:
- **Overleaf**: A free, browser-based editor that requires no installation.
- **TeX distributions** (if working offline):
  - **MiKTeX** (Windows)
  - **TeX Live** (Linux/Windows)
  - **MacTeX** (Mac)

---

### **2. Structure of a Basic LaTeX Document**
Every LaTeX document has a consistent structure, which includes:
1. **Preamble**: Defines document settings and loads any necessary packages.
2. **Body**: Contains the main content of your document.

---

### **3. Write Your First Document**

Here’s an example of a simple LaTeX document:

```latex
% Preamble
\documentclass{article} % Defines the document type
\usepackage[utf8]{inputenc} % Handles special characters
\usepackage{amsmath} % Adds support for advanced math

% Document body
\begin{document}

\title{My First LaTeX Document}
\author{Your Name}
\date{\today} % Automatically inserts today's date

\maketitle % Generates the title section

\section{Introduction}
Welcome to LaTeX! This is your first document.

\section{Writing Mathematics}
Here is an example of an equation:
\[
E = mc^2
\]

And here’s an inline equation: \( a^2 + b^2 = c^2 \).

\section{Conclusion}
Using LaTeX is simple once you understand the structure. Keep practicing!

\end{document}
```

---

### **4. Compile and View the Output**
- If using **Overleaf**, copy the code above into a new project, and it will compile automatically into a PDF.
- If using an offline editor, save the code as `document.tex`, then compile it with a LaTeX processor (e.g., `pdflatex document.tex`).

---

### **5. What to Expect**
The output PDF will include:
- A title with your name and today’s date.
- Three sections: Introduction, Writing Mathematics, and Conclusion.
- A formatted equation and some inline math.

---

### **6. Next Steps**
Once you’re comfortable, you can:
- Explore packages like `graphicx` (for images) and `geometry` (for custom layouts).
- Add tables, lists, and more advanced content.
- Use templates for specific purposes (e.g., resumes, theses).

