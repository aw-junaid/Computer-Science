To include a **title**, **author**, and **date** in a LaTeX document, you define them in the preamble and use the `\maketitle` command in the document body to display the title page or header.

---

### **1. Adding Title Information**
In the **preamble**, use the following commands to define the title, author, and date:
```latex
\title{Your Document Title}
\author{Your Name}
\date{Your Date}
```

### **2. Displaying the Title**
In the **document body**, add `\maketitle` where you want the title, author, and date to appear.

---

### **Example**
Here’s a complete example:

```latex
\documentclass{article}
\usepackage[utf8]{inputenc} % Handles special characters

% Title information
\title{Introduction to LaTeX}
\author{Jane Doe}
\date{\today} % Automatically inserts today's date

\begin{document}

\maketitle % Displays the title, author, and date

\section{Introduction}
This is a simple LaTeX document with a title, author, and date.

\end{document}
```

---

### **3. Customizing Title Information**

#### **Changing the Date**
- To specify a custom date, replace `\today` with a specific date:
```latex
\date{December 16, 2024}
```
- To omit the date, leave the `\date` command empty:
```latex
\date{}
```

#### **Multiple Authors**
If there are multiple authors, separate their names with `\and`:
```latex
\author{Jane Doe \and John Smith}
```

#### **Formatting the Title Page**
You can customize the appearance of the title using the `\title`, `\author`, or `\date` commands:
```latex
\title{\textbf{\Huge An Introduction to LaTeX}}
\author{\textit{Jane Doe}}
```

---

### **4. Title in Other Document Classes**
- In `book` or `report` classes, the title usually appears as a separate page by default.
- For `article`, the title appears at the top of the first page.

---

### **5. Advanced Customization with Packages**
Using the `titling` package, you can gain finer control over how the title information is displayed:
```latex
\usepackage{titling}

\setlength{\droptitle}{-3cm} % Adjust vertical spacing
\pretitle{\begin{center}\Huge\bfseries} % Customize pre-title formatting
\posttitle{\end{center}}
```

---

