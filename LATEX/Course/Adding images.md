Adding images to a LaTeX document is straightforward using the `graphicx` package. Here's a step-by-step guide to include and customize images in your document.

---

### **1. Load the `graphicx` Package**
Add the following line in the preamble:
```latex
\usepackage{graphicx}
```

---

### **2. Include an Image**
Use the `\includegraphics` command to insert an image.

**Syntax:**
```latex
\includegraphics[options]{filename}
```

- **`filename`**: The name of the image file (e.g., `image.png`). Ensure the image file is in the same directory as your `.tex` file or provide the full path.
- Supported formats: `.png`, `.jpg`, `.pdf`, `.eps`.

**Example:**
```latex
\includegraphics{example.png}
```

---

### **3. Scaling and Resizing Images**
You can control the size of the image using optional parameters.

#### **Width and Height**
Specify the width, height, or both:
```latex
\includegraphics[width=0.5\textwidth]{example.png} % 50% of the text width
\includegraphics[height=5cm]{example.png}         % 5 cm height
```

#### **Scaling**
Scale the image proportionally:
```latex
\includegraphics[scale=0.5]{example.png} % Reduces the size to 50%
```

---

### **4. Positioning Images**
Use the `figure` environment to place the image and add captions or labels.

**Example:**
```latex
\begin{figure}[h]
    \centering
    \includegraphics[width=0.5\textwidth]{example.png} % Centered image, half the text width
    \caption{This is an example image.}
    \label{fig:example}
\end{figure}
```

- `[h]`: Suggests placing the figure *here* in the document.
  - Other options: `[t]` (top), `[b]` (bottom), `[p]` (on a separate page).
- `\caption{}`: Adds a caption below the image.
- `\label{}`: Creates a label for referencing the figure.

---

### **5. Referencing Images**
To reference an image in your document, use the `\ref{}` command with the label:
```latex
As shown in Figure~\ref{fig:example}, the image illustrates...
```

---

### **6. Full Example**
Here’s a complete LaTeX document with an image:
```latex
\documentclass{article}
\usepackage[utf8]{inputenc}
\usepackage{graphicx}

\begin{document}

\section{Including an Image}
Here is an example of an image:

\begin{figure}[h]
    \centering
    \includegraphics[width=0.5\textwidth]{example.png}
    \caption{An example image.}
    \label{fig:example}
\end{figure}

As shown in Figure~\ref{fig:example}, the image demonstrates...

\end{document}
```

---

### **7. Advanced Options**

#### **Adjusting Image Alignment**
You can align images using commands like `\raggedleft`, `\raggedright`, or `\centering`:
```latex
\raggedright
\includegraphics[width=0.3\textwidth]{example.png} % Left-aligned
```

#### **Rotating Images**
Rotate an image using the `angle` option:
```latex
\includegraphics[angle=90, width=0.5\textwidth]{example.png} % Rotate 90 degrees
```

#### **Adding Borders**
Add borders around the image using the `fbox` command:
```latex
\fbox{\includegraphics[width=0.5\textwidth]{example.png}}
```

---

### **8. Troubleshooting**
- **File Not Found**: Ensure the image file is in the same folder as your `.tex` file or provide the full path.
- **Unsupported Format**: Convert the image to a compatible format like `.png`, `.jpg`, or `.pdf`.

