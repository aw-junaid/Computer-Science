**Component Lifecycle Methods in React (Class Components)**

React class components have lifecycle methods that execute during specific phases: **Mounting**, **Updating**, **Unmounting**, and **Error Handling**. These methods allow you to control component behavior at different stages.

---

### **1. Mounting Phase**
Called when a component is created and inserted into the DOM.

1. **`constructor(props)`**  
   - Initializes state and binds event handlers.  
   - **Note**: Call `super(props)` before using `this.props`.

2. **`static getDerivedStateFromProps(props, state)`**  
   - Rarely used. Updates state based on initial or subsequent props.  
   - Returns an object to update state or `null` for no change.

3. **`render()`**  
   - **Required**. Returns JSX or `null`.  
   - Prepares the UI structure (avoid side effects here).

4. **`componentDidMount()`**  
   - Runs after the component mounts.  
   - Ideal for **API calls**, DOM manipulations, or subscriptions.

---

### **2. Updating Phase**
Triggered by changes in `props`/`state` or parent re-renders.

1. **`static getDerivedStateFromProps(props, state)`**  
   - Same as in mounting. Updates state before rendering.

2. **`shouldComponentUpdate(nextProps, nextState)`**  
   - Returns `true` (default) to allow re-render or `false` to block it.  
   - **Performance optimization** (e.g., using `React.PureComponent`).

3. **`render()`**  
   - Re-renders the UI with updated `props`/`state`.

4. **`getSnapshotBeforeUpdate(prevProps, prevState)`**  
   - Captures pre-update info (e.g., scroll position).  
   - Returned value is passed to `componentDidUpdate`.

5. **`componentDidUpdate(prevProps, prevState, snapshot)`**  
   - Runs after updates. Handle side effects like network requests.  
   - Use conditions to avoid infinite loops.

---

### **3. Unmounting Phase**
Occurs when a component is removed from the DOM.

1. **`componentWillUnmount()`**  
   - Cleanup tasks: invalidate timers, cancel requests, or remove subscriptions.

---

### **4. Error Handling**
Catches errors in child components.

1. **`static getDerivedStateFromError(error)`**  
   - Updates state to display a fallback UI.  
   - Must return an updated state object.

2. **`componentDidCatch(error, info)`**  
   - Logs errors (e.g., to analytics tools).

---

### **Deprecated Methods (Avoid)**
- `UNSAFE_componentWillMount()`
- `UNSAFE_componentWillReceiveProps()`
- `UNSAFE_componentWillUpdate()`

---

### **Functional Components & Hooks**
- **`useEffect`**: Combines `componentDidMount`, `componentDidUpdate`, and `componentWillUnmount`.  
- **`useState`/`useContext`**: Manage state and context without lifecycle methods.

---

**Common Use Cases**  
- **`componentDidMount`**: Fetch data, add event listeners.  
- **`componentDidUpdate`**: Update DOM based on prop changes.  
- **`componentWillUnmount`**: Prevent memory leaks.  
- **`shouldComponentUpdate`**: Optimize rendering performance.  

**Best Practices**  
- Avoid overusing `getDerivedStateFromProps`; prefer controlled components.  
- Use error boundaries to gracefully handle crashes.  
- Migrate to functional components with hooks for new code.  

Understanding these methods helps manage side effects, optimize performance, and ensure clean component behavior.
