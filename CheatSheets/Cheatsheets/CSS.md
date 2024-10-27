An extended CSS cheat sheet that covers essential properties, selectors, and concepts used in CSS (Cascading Style Sheets). This cheat sheet provides examples and explanations for each item, making it easier to understand and implement CSS in web development.

---

## **1. Basic Syntax**

### 1.1 CSS Rule Set

```css
selector {
    property: value;
}
```

**Explanation**: A CSS rule set consists of a selector that targets HTML elements and a declaration block containing property-value pairs.

---

## **2. Selectors**

### 2.1 Type Selector

```css
h1 {
    color: blue;
}
```

**Explanation**: Selects all `<h1>` elements and applies the styles.

### 2.2 Class Selector

```css
.button {
    background-color: green;
}
```

**Explanation**: Selects all elements with the class `button`. Classes are prefixed with a dot (`.`).

### 2.3 ID Selector

```css
#header {
    font-size: 24px;
}
```

**Explanation**: Selects the element with the ID `header`. IDs are prefixed with a hash (`#`).

### 2.4 Descendant Selector

```css
div p {
    margin: 10px;
}
```

**Explanation**: Selects all `<p>` elements that are descendants of `<div>` elements.

### 2.5 Attribute Selector

```css
input[type="text"] {
    border: 1px solid black;
}
```

**Explanation**: Selects `<input>` elements with a `type` attribute of `text`.

### 2.6 Pseudo-classes

```css
a:hover {
    color: red;
}
```

**Explanation**: Applies styles when the user hovers over `<a>` elements.

### 2.7 Pseudo-elements

```css
p::first-line {
    font-weight: bold;
}
```

**Explanation**: Styles the first line of each `<p>` element.

---

## **3. Colors**

### 3.1 Color Values

```css
body {
    background-color: #f0f0f0;  /* Hex color */
    color: rgb(0, 0, 0);        /* RGB color */
    color: rgba(255, 0, 0, 0.5); /* RGBA color */
    color: hsl(120, 100%, 50%); /* HSL color */
}
```

**Explanation**: Different formats to define colors in CSS.

---

## **4. Text Styles**

### 4.1 Text Properties

```css
h1 {
    font-size: 2em;
    font-family: Arial, sans-serif;
    font-weight: bold;
    text-align: center;
    text-decoration: underline;
    color: navy;
}
```

**Explanation**: Common text properties include `font-size`, `font-family`, `font-weight`, `text-align`, `text-decoration`, and `color`.

---

## **5. Box Model**

### 5.1 Box Model Properties

```css
.box {
    width: 300px;
    height: 200px;
    margin: 20px;    /* Space outside the box */
    padding: 10px;   /* Space inside the box */
    border: 5px solid black; /* Border around the box */
}
```

**Explanation**: The box model consists of `margin`, `border`, `padding`, and `width/height`.

### 5.2 Box Sizing

```css
* {
    box-sizing: border-box; /* Includes padding and border in the element's total width and height */
}
```

**Explanation**: The `box-sizing` property alters how the width and height are calculated.

---

## **6. Layout**

### 6.1 Display Property

```css
div {
    display: block; /* Other options: inline, inline-block, flex, grid, none */
}
```

**Explanation**: The `display` property defines how an element is displayed on the page.

### 6.2 Positioning

```css
.positioned {
    position: relative; /* Other options: absolute, fixed, sticky */
    top: 10px;
    left: 20px;
}
```

**Explanation**: The `position` property determines how an element is positioned relative to its normal position, its closest positioned ancestor, or the viewport.

### 6.3 Flexbox

```css
.container {
    display: flex;
    justify-content: center; /* Aligns items horizontally */
    align-items: center;     /* Aligns items vertically */
}
```

**Explanation**: Flexbox allows for responsive layout design by distributing space along a single axis.

### 6.4 Grid

```css
.grid-container {
    display: grid;
    grid-template-columns: repeat(3, 1fr);
    gap: 10px; /* Space between grid items */
}
```

**Explanation**: The CSS Grid Layout provides a two-dimensional grid-based layout.

---

## **7. Backgrounds**

### 7.1 Background Properties

```css
body {
    background-color: white;
    background-image: url('background.jpg');
    background-size: cover; /* Other options: contain, auto */
    background-position: center;
    background-repeat: no-repeat;
}
```

**Explanation**: The `background` property sets the background color, image, size, position, and repeat behavior.

---

## **8. Borders and Shadows**

### 8.1 Border Properties

```css
.box {
    border: 2px solid black;
    border-radius: 10px; /* Rounds the corners */
}
```

**Explanation**: The `border` property specifies the width, style, and color of an element's border. `border-radius` creates rounded corners.

### 8.2 Box Shadow

```css
.box {
    box-shadow: 5px 5px 10px rgba(0, 0, 0, 0.5); /* Horizontal offset, vertical offset, blur radius, color */
}
```

**Explanation**: The `box-shadow` property adds shadow effects around an element.

---

## **9. Transitions and Animations**

### 9.1 Transitions

```css
.button {
    transition: background-color 0.3s ease;
}

.button:hover {
    background-color: blue;
}
```

**Explanation**: The `transition` property allows for smooth changes to CSS properties over a specified duration.

### 9.2 Animations

```css
@keyframes slide {
    from {
        transform: translateX(0);
    }
    to {
        transform: translateX(100px);
    }
}

.box {
    animation: slide 2s infinite; /* Animation name, duration, repetition */
}
```

**Explanation**: The `@keyframes` rule defines animations, and the `animation` property applies them to elements.

---

## **10. Media Queries**

### 10.1 Responsive Design with Media Queries

```css
@media (max-width: 600px) {
    body {
        background-color: lightblue;
    }
}
```

**Explanation**: Media queries apply styles based on the viewport size, enabling responsive design.

---

## **11. Comments**

### 11.1 CSS Comments

```css
/* This is a comment */
```

**Explanation**: Comments are used to explain CSS code and are not rendered in the browser.

---

## **12. CSS Variables**

### 12.1 Custom Properties (CSS Variables)

```css
:root {
    --primary-color: blue;
}

.button {
    background-color: var(--primary-color);
}
```

**Explanation**: CSS variables are defined using `--` and can be reused throughout the stylesheet using the `var()` function.

---

## **13. Specificity and Inheritance**

### 13.1 Specificity

```css
/* Specificity hierarchy */
p { color: red; } /* Low specificity */
#myId { color: blue; } /* Medium specificity */
.container p { color: green; } /* High specificity */
```

**Explanation**: Specificity determines which styles are applied when multiple rules target the same element. ID selectors are more specific than class selectors, which are more specific than type selectors.

### 13.2 Inheritance

```css
body {
    color: black; /* Text color inherited by child elements */
}

h1 {
    font-size: 2em; /* Not inherited */
}
```

**Explanation**: Some CSS properties are inherited by child elements (e.g., `color`), while others are not (e.g., `font-size`).

---

## **14. Vendor Prefixes**

### 14.1 Using Vendor Prefixes

```css
.box {
    -webkit-transform: rotate(45deg); /* Chrome, Safari */
    -moz-transform: rotate(45deg);    /* Firefox */
    transform: rotate(45deg);         /* Standard */
}
```

**Explanation**: Vendor prefixes are used for experimental features that may not be fully supported across all browsers.

---

## **Conclusion**

This cheat sheet provides a comprehensive overview of essential CSS properties, selectors, and concepts. Regular practice with these concepts will help you become proficient in CSS and web development.
