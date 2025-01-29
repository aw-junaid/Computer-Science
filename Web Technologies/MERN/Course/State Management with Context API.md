**State Management with Context API in React**

The **Context API** is a built-in React feature for managing global state without prop drilling. It allows you to share data (e.g., themes, user authentication) across components without passing props manually at every level.

---

### **1. When to Use Context API**
- **Global State**: Data needed by many components (e.g., theme, user info).  
- **Avoid Prop Drilling**: Passing props through multiple intermediate components.  
- **Simple Use Cases**: For smaller apps or when Redux is overkill.

---

### **2. Key Concepts**
1. **`React.createContext`**: Creates a context object.  
2. **`Provider`**: Supplies the context value to its children.  
3. **`Consumer`**: Accesses the context value (use `useContext` hook in functional components).  

---

### **3. Steps to Use Context API**

#### **Step 1: Create a Context**
```javascript
import React from 'react';

const MyContext = React.createContext(defaultValue);
```
- `defaultValue`: Used when a component doesn’t have a matching `Provider` above it.

---

#### **Step 2: Provide Context Value**
Wrap your component tree with the `Provider` to pass down the value.

```javascript
function App() {
  const [theme, setTheme] = React.useState('light');

  return (
    <MyContext.Provider value={{ theme, setTheme }}>
      <ChildComponent />
    </MyContext.Provider>
  );
}
```

---

#### **Step 3: Consume Context Value**
Use the `useContext` hook or `Consumer` to access the context value.

##### **Using `useContext` (Functional Components)**
```javascript
import React, { useContext } from 'react';

function ChildComponent() {
  const { theme, setTheme } = useContext(MyContext);

  return (
    <div style={{ background: theme === 'light' ? '#fff' : '#333' }}>
      <p>Current Theme: {theme}</p>
      <button onClick={() => setTheme('dark')}>Toggle Theme</button>
    </div>
  );
}
```

##### **Using `Consumer` (Class Components)**
```javascript
class ChildComponent extends React.Component {
  render() {
    return (
      <MyContext.Consumer>
        {({ theme, setTheme }) => (
          <div style={{ background: theme === 'light' ? '#fff' : '#333' }}>
            <p>Current Theme: {theme}</p>
            <button onClick={() => setTheme('dark')}>Toggle Theme</button>
          </div>
        )}
      </MyContext.Consumer>
    );
  }
}
```

---

### **4. Advanced Usage**

#### **Separate Context and Provider**
Create a separate file for the context and provider to keep your code modular.

```javascript
// ThemeContext.js
import React, { useState } from 'react';

const ThemeContext = React.createContext();

export const ThemeProvider = ({ children }) => {
  const [theme, setTheme] = useState('light');

  return (
    <ThemeContext.Provider value={{ theme, setTheme }}>
      {children}
    </ThemeContext.Provider>
  );
};

export default ThemeContext;
```

#### **Consume in Components**
```javascript
import React, { useContext } from 'react';
import ThemeContext, { ThemeProvider } from './ThemeContext';

function App() {
  return (
    <ThemeProvider>
      <ChildComponent />
    </ThemeProvider>
  );
}

function ChildComponent() {
  const { theme, setTheme } = useContext(ThemeContext);

  return (
    <div style={{ background: theme === 'light' ? '#fff' : '#333' }}>
      <p>Current Theme: {theme}</p>
      <button onClick={() => setTheme('dark')}>Toggle Theme</button>
    </div>
  );
}
```

---

### **5. Best Practices**
1. **Avoid Overusing Context**: Use it for truly global state; local state is fine for component-specific data.  
2. **Optimize Performance**: Use memoization (`React.memo`) or split contexts to avoid unnecessary re-renders.  
3. **Combine with Hooks**: Use `useReducer` for complex state logic.  
4. **Type Safety**: Use TypeScript or PropTypes for better type checking.  

---

### **6. Example: Theme Toggler**
```javascript
import React, { useState, useContext } from 'react';

// Create Context
const ThemeContext = React.createContext();

// Provider Component
export const ThemeProvider = ({ children }) => {
  const [theme, setTheme] = useState('light');

  const toggleTheme = () => {
    setTheme(theme === 'light' ? 'dark' : 'light');
  };

  return (
    <ThemeContext.Provider value={{ theme, toggleTheme }}>
      {children}
    </ThemeContext.Provider>
  );
};

// Custom Hook for Context
export const useTheme = () => useContext(ThemeContext);

// App Component
function App() {
  return (
    <ThemeProvider>
      <Header />
      <Content />
    </ThemeProvider>
  );
}

// Child Components
function Header() {
  const { theme, toggleTheme } = useTheme();

  return (
    <header style={{ background: theme === 'light' ? '#fff' : '#333', color: theme === 'light' ? '#000' : '#fff' }}>
      <h1>Header</h1>
      <button onClick={toggleTheme}>Toggle Theme</button>
    </header>
  );
}

function Content() {
  const { theme } = useTheme();

  return (
    <main style={{ background: theme === 'light' ? '#f5f5f5' : '#222', color: theme === 'light' ? '#000' : '#fff' }}>
      <p>This is the content area.</p>
    </main>
  );
}

export default App;
```

---

### **7. Context API vs Redux**
| **Feature**            | **Context API**                          | **Redux**                              |
|-------------------------|------------------------------------------|----------------------------------------|
| **Use Case**            | Simple global state                     | Complex state management               |
| **Boilerplate**         | Minimal                                 | High                                   |
| **Middleware**          | Not built-in                            | Supports middleware (e.g., Thunk, Saga) |
| **DevTools**            | No built-in tools                       | Advanced debugging tools               |
| **Performance**         | Can cause re-renders if not optimized   | Optimized for large apps               |

---

The Context API is a lightweight and effective solution for state management in React, especially for smaller applications or when you want to avoid third-party libraries. For larger apps, consider combining it with `useReducer` or using Redux.
