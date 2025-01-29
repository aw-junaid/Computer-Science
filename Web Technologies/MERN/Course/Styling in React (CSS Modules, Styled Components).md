Styling in React can be done in multiple ways, but **CSS Modules** and **Styled Components** are two popular approaches that provide better scoping and maintainability compared to regular CSS files.  

---

# **1. CSS Modules**  
CSS Modules allow you to scope styles locally to a specific component, preventing conflicts with global styles.

### **Setting Up CSS Modules**  
Make sure your project supports CSS Modules (Create React App and Vite support it out of the box).  

### **Example: Using CSS Modules**  
#### **Step 1: Create a CSS Module file**  
📂 `Button.module.css`  
```css
.button {
  background-color: #007bff;
  color: white;
  padding: 10px 20px;
  border: none;
  border-radius: 5px;
  font-size: 16px;
  cursor: pointer;
}

.button:hover {
  background-color: #0056b3;
}
```

#### **Step 2: Import and Use in React Component**  
📂 `Button.js`  
```jsx
import styles from "./Button.module.css";

const Button = ({ text }) => {
  return <button className={styles.button}>{text}</button>;
};

export default Button;
```

### **Benefits of CSS Modules**  
✅ **Scoped Styles** (No global conflicts)  
✅ **Better Performance** (Regular CSS, no runtime overhead)  
✅ **Works with Preprocessors** (SASS, LESS)  

---

# **2. Styled Components**  
Styled Components is a CSS-in-JS library that lets you write component-scoped styles inside JavaScript files.  

### **Installation**  
```sh
npm install styled-components
```

### **Example: Using Styled Components**  
📂 `Button.js`  
```jsx
import styled from "styled-components";

const StyledButton = styled.button`
  background-color: #007bff;
  color: white;
  padding: 10px 20px;
  border: none;
  border-radius: 5px;
  font-size: 16px;
  cursor: pointer;

  &:hover {
    background-color: #0056b3;
  }
`;

const Button = ({ text }) => {
  return <StyledButton>{text}</StyledButton>;
};

export default Button;
```

### **Benefits of Styled Components**  
✅ **Scoped Styles** (No global conflicts)  
✅ **Dynamic Styling** (Use props to change styles)  
✅ **Conditional Styling** (Apply different styles based on props)  

#### **Example: Dynamic Styling with Props**
```jsx
const StyledButton = styled.button`
  background-color: ${(props) => (props.primary ? "#007bff" : "#6c757d")};
  color: white;
  padding: 10px 20px;
  border: none;
  border-radius: 5px;
  font-size: 16px;
  cursor: pointer;

  &:hover {
    background-color: ${(props) => (props.primary ? "#0056b3" : "#5a6268")};
  }
`;

const Button = ({ text, primary }) => {
  return <StyledButton primary={primary}>{text}</StyledButton>;
};
```

---

# **CSS Modules vs. Styled Components: Which One to Choose?**  
| Feature            | CSS Modules  | Styled Components |
|--------------------|-------------|------------------|
| **Scoped Styles**  | ✅ Yes      | ✅ Yes |
| **Performance**    | ✅ Faster (CSS file) | ❌ Slightly slower (JS-based styling) |
| **Dynamic Styling** | ❌ No | ✅ Yes (Props-based styling) |
| **Global Styles**  | ❌ No (Scoped by default) | ✅ Yes (Supports global styles) |
| **Ease of Use**    | ✅ Simple | ❌ Requires learning CSS-in-JS |

### **When to Use?**
- **Use CSS Modules** if you prefer regular CSS but want to avoid global conflicts.  
- **Use Styled Components** if you need **dynamic styles** and **CSS-in-JS** for more flexibility.  
