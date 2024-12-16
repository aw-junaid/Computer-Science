Adding **comments** in a LaTeX document is simple and useful for including notes or reminders that do not appear in the final output. In LaTeX, comments start with a `%` symbol.

---

### **How to Add Comments**
1. **Single-Line Comment**: Use `%` to comment out a single line.
   ```latex
   % This is a comment. It will not appear in the output.
   \documentclass{article} % Sets the document type
   ```

2. **End-of-Line Comments**: Anything after `%` on a line is treated as a comment.
   ```latex
   \title{Introduction to LaTeX} % The title of the document
   ```

3. **Commenting Out Multiple Lines**: Add `%` at the start of each line.
   ```latex
   % This is a multi-line comment.
   % Each line begins with a percent symbol.
   % These comments will not appear in the output.
   ```

---

### **Block Comments**
LaTeX doesn’t natively support block comments like in some programming languages, but you can simulate it using the `comment` package.

#### **Using the `comment` Package**
The `comment` package allows you to easily comment out large blocks of code.
1. Add `\usepackage{comment}` to the preamble.
2. Use the `\begin{comment}` and `\end{comment}` environment to enclose the block.

**Example:**
```latex
\documentclass{article}
\usepackage{comment}

\begin{document}

% This is a single-line comment.

\begin{comment}
This entire block of text
will be ignored during compilation.
You can use it to comment out large sections.
\end{comment}

This text will appear in the document.

\end{document}
```

---

### **Best Practices for Comments**
1. **Explanatory Comments**: Use comments to clarify complex code or settings.
   ```latex
   % Define the margins of the document
   \usepackage[margin=1in]{geometry}
   ```
2. **Temporarily Disabling Content**: Comment out parts of the document for testing or debugging.
   ```latex
   % \section{Conclusion}
   % This section is currently hidden for revisions.
   ```
3. **Document Collaboration**: Leave notes for collaborators using comments.

---

### **Tips**
- Avoid excessive commenting that clutters your document.
- Use comments to track changes, explain configurations, or plan sections.

