### **React Hooks: `useState`, `useEffect`, and `useContext`**

React Hooks are functions that allow you to "hook into" React features like state and lifecycle methods in functional components. Introduced in React 16.8, hooks have become the standard way to manage state and side effects in functional components. Below, we'll explore the three most commonly used hooks: `useState`, `useEffect`, and `useContext`.

---

### **1. `useState`**

The `useState` hook allows you to add state to functional components. It returns an array with two elements: the current state value and a function to update it.

#### **Syntax**
```javascript
const [state, setState] = useState(initialState);
```

#### **Example: Counter Component**
```javascript
import React, { useState } from 'react';

function Counter() {
  const [count, setCount] = useState(0);

  return (
    <div>
      <p>Count: {count}</p>
      <button onClick={() => setCount(count + 1)}>Increment</button>
    </div>
  );
}
```

#### **Key Points**
- `useState` can be used multiple times in a component to manage different pieces of state.
- The initial state can be a primitive value, object, or array.
- Always use the updater function (`setCount`) to modify state.

---

### **2. `useEffect`**

The `useEffect` hook allows you to perform side effects in functional components. It replaces lifecycle methods like `componentDidMount`, `componentDidUpdate`, and `componentWillUnmount`.

#### **Syntax**
```javascript
useEffect(() => {
  // Side effect logic
  return () => {
    // Cleanup logic (optional)
  };
}, [dependencies]);
```

#### **Example: Fetching Data**
```javascript
import React, { useState, useEffect } from 'react';

function DataFetcher() {
  const [data, setData] = useState(null);

  useEffect(() => {
    fetch('https://api.example.com/data')
      .then(response => response.json())
      .then(data => setData(data))
      .catch(error => console.error('Error fetching data:', error));
  }, []); // Empty dependency array means this runs once on mount

  return (
    <div>
      {data ? <pre>{JSON.stringify(data, null, 2)}</pre> : 'Loading...'}
    </div>
  );
}
```

#### **Key Points**
- **Dependency Array**:
  - If the array is empty (`[]`), the effect runs only once (on mount and unmount).
  - If the array contains values, the effect runs when those values change.
  - If no array is provided, the effect runs on every render.
- **Cleanup**:
  - Return a cleanup function to perform tasks like unsubscribing from events or canceling network requests.

#### **Example: Cleanup**
```javascript
useEffect(() => {
  const interval = setInterval(() => {
    console.log('Tick');
  }, 1000);

  return () => clearInterval(interval); // Cleanup on unmount
}, []);
```

---

### **3. `useContext`**

The `useContext` hook allows you to access the value of a React context without wrapping your component in a `Context.Consumer`.

#### **Syntax**
```javascript
const value = useContext(MyContext);
```

#### **Example: Using Context**
```javascript
import React, { createContext, useContext } from 'react';

// Step 1: Create a context
const ThemeContext = createContext('light');

function App() {
  return (
    // Step 2: Provide a context value
    <ThemeContext.Provider value="dark">
      <Toolbar />
    </ThemeContext.Provider>
  );
}

function Toolbar() {
  return <ThemedButton />;
}

function ThemedButton() {
  // Step 3: Consume the context value
  const theme = useContext(ThemeContext);

  return <button style={{ background: theme === 'dark' ? '#333' : '#FFF' }}>Themed Button</button>;
}
```

#### **Key Points**
- `useContext` simplifies context consumption in functional components.
- It re-renders the component whenever the context value changes.

---

### **Combining Hooks**

You can combine `useState`, `useEffect`, and `useContext` to build complex and dynamic components.

#### **Example: Combining Hooks**
```javascript
import React, { useState, useEffect, useContext } from 'react';

const UserContext = createContext();

function App() {
  const [user, setUser] = useState(null);

  useEffect(() => {
    // Simulate fetching user data
    setTimeout(() => {
      setUser({ name: 'John Doe', age: 30 });
    }, 1000);
  }, []);

  return (
    <UserContext.Provider value={user}>
      <UserProfile />
    </UserContext.Provider>
  );
}

function UserProfile() {
  const user = useContext(UserContext);

  if (!user) {
    return <p>Loading user data...</p>;
  }

  return (
    <div>
      <h1>{user.name}</h1>
      <p>Age: {user.age}</p>
    </div>
  );
}
```

---

### **Best Practices for Using Hooks**

1. **Use Hooks at the Top Level**:
   - Only call hooks at the top level of your component, not inside loops, conditions, or nested functions.

2. **Name Hooks Descriptively**:
   - Use meaningful names for state variables and effects (e.g., `const [count, setCount] = useState(0)`).

3. **Optimize `useEffect` Dependencies**:
   - Include only the necessary dependencies in the dependency array to avoid unnecessary re-renders.

4. **Separate Concerns**:
   - Use multiple `useEffect` hooks to separate unrelated logic.

5. **Use Custom Hooks for Reusable Logic**:
   - Extract reusable logic into custom hooks (e.g., `useFetch`, `useLocalStorage`).

---

### **Conclusion**

React Hooks (`useState`, `useEffect`, and `useContext`) provide a powerful and flexible way to manage state, side effects, and context in functional components. By mastering these hooks, you can write cleaner, more modular, and maintainable React code. Whether you're building simple components or complex applications, hooks are an essential tool in your React toolkit.
