CSS (Cascading Style Sheets) is used to style and layout web pages. It controls the visual presentation of HTML elements, including colors, fonts, spacing, and positioning. Mastering CSS fundamentals like **Flexbox**, **Grid**, and **Responsive Design** is essential for creating modern, user-friendly web layouts.

---

### **1. CSS Basics**
CSS is applied to HTML elements using **selectors** and **declarations**. A declaration consists of a **property** and a **value**.

#### **Example**:
```css
/* Selector */
h1 {
    /* Declaration */
    color: blue; /* Property: Value */
    font-size: 24px;
}
```

---

### **2. Flexbox**
Flexbox is a one-dimensional layout model that allows you to align and distribute space among items in a container. It is ideal for creating flexible and responsive layouts.

#### **Key Concepts**:
- **Flex Container**: The parent element that holds flex items.
- **Flex Items**: The child elements inside the flex container.

#### **Properties for Flex Container**:
- **`display: flex;`**: Defines the container as a flex container.
- **`flex-direction`**: Sets the direction of the flex items (row, column, row-reverse, column-reverse).
- **`justify-content`**: Aligns items along the main axis (flex-start, flex-end, center, space-between, space-around).
- **`align-items`**: Aligns items along the cross axis (flex-start, flex-end, center, stretch, baseline).
- **`flex-wrap`**: Controls whether items wrap to the next line (nowrap, wrap, wrap-reverse).

#### **Properties for Flex Items**:
- **`flex-grow`**: Defines how much an item can grow relative to others.
- **`flex-shrink`**: Defines how much an item can shrink relative to others.
- **`flex-basis`**: Sets the initial size of an item.
- **`align-self`**: Overrides the `align-items` value for a specific item.

#### **Example**:
```css
.container {
    display: flex;
    flex-direction: row;
    justify-content: space-between;
    align-items: center;
}

.item {
    flex: 1; /* Grow and shrink equally */
}
```

---

### **3. CSS Grid**
CSS Grid is a two-dimensional layout system that allows you to create complex grid-based layouts. It is more powerful than Flexbox for creating layouts with rows and columns.

#### **Key Concepts**:
- **Grid Container**: The parent element that holds grid items.
- **Grid Items**: The child elements inside the grid container.
- **Grid Lines**: The lines that define the grid's structure.
- **Grid Tracks**: The rows and columns of the grid.

#### **Properties for Grid Container**:
- **`display: grid;`**: Defines the container as a grid container.
- **`grid-template-columns`**: Defines the columns of the grid.
- **`grid-template-rows`**: Defines the rows of the grid.
- **`gap`**: Sets the spacing between grid items (row-gap and column-gap).
- **`justify-items`**: Aligns items along the row axis (start, end, center, stretch).
- **`align-items`**: Aligns items along the column axis (start, end, center, stretch).

#### **Properties for Grid Items**:
- **`grid-column`**: Defines the start and end positions of an item in the grid columns.
- **`grid-row`**: Defines the start and end positions of an item in the grid rows.
- **`justify-self`**: Aligns an item along the row axis (start, end, center, stretch).
- **`align-self`**: Aligns an item along the column axis (start, end, center, stretch).

#### **Example**:
```css
.container {
    display: grid;
    grid-template-columns: 1fr 1fr 1fr; /* Three equal columns */
    grid-template-rows: 100px 200px; /* Two rows */
    gap: 10px; /* Spacing between items */
}

.item {
    grid-column: 1 / 3; /* Span two columns */
    grid-row: 1; /* Place in the first row */
}
```

---

### **4. Responsive Design**
Responsive design ensures that web pages look good and function well on all devices (desktops, tablets, and mobile phones). It involves using flexible layouts, media queries, and responsive units.

#### **Key Techniques**:
1. **Fluid Layouts**:
   - Use percentages or `fr` units instead of fixed widths.
   - Example:
     ```css
     .container {
         width: 100%;
         max-width: 1200px;
         margin: 0 auto;
     }
     ```

2. **Media Queries**:
   - Apply different styles based on screen size.
   - Example:
     ```css
     @media (max-width: 768px) {
         .container {
             flex-direction: column;
         }
     }
     ```

3. **Responsive Units**:
   - Use relative units like `em`, `rem`, `%`, `vh`, and `vw`.
   - Example:
     ```css
     h1 {
         font-size: 2rem; /* Relative to root font size */
     }
     ```

4. **Flexible Images**:
   - Ensure images scale with the layout.
   - Example:
     ```css
     img {
         max-width: 100%;
         height: auto;
     }
     ```

#### **Example of a Responsive Layout**:
```css
.container {
    display: flex;
    flex-wrap: wrap;
    gap: 10px;
}

.item {
    flex: 1 1 200px; /* Grow, shrink, and base width */
}

@media (max-width: 768px) {
    .item {
        flex: 1 1 100%; /* Full width on small screens */
    }
}
```

---

### **5. Combining Flexbox and Grid**
Flexbox and Grid can be used together to create complex, responsive layouts. For example:
- Use **Grid** for the overall page layout.
- Use **Flexbox** for aligning items within grid cells.

#### **Example**:
```css
.container {
    display: grid;
    grid-template-columns: 1fr 2fr;
    gap: 20px;
}

.header {
    grid-column: 1 / -1;
    display: flex;
    justify-content: space-between;
    align-items: center;
}

.sidebar {
    display: flex;
    flex-direction: column;
    gap: 10px;
}
```

---

### **Conclusion**
- **Flexbox** is ideal for one-dimensional layouts (rows or columns).
- **Grid** is perfect for two-dimensional layouts (rows and columns).
- **Responsive Design** ensures your layouts adapt to different screen sizes.

By mastering these CSS fundamentals, you can create modern, flexible, and responsive web designs that work seamlessly across all devices.
