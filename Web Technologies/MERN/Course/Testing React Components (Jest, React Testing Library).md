# **Testing React Components with Jest & React Testing Library** 🧪

**Testing React components** is essential to ensure that your app behaves as expected. **Jest** is a popular JavaScript testing framework, and **React Testing Library** provides tools to test React components in a way that focuses on how users interact with them.

### **Key Concepts:**
- **Jest**: A test runner that executes your tests and provides assertions.
- **React Testing Library (RTL)**: A library for testing React components, focusing on their behavior from the user's perspective.

---

## **1. Setting Up Jest and React Testing Library**

If you're using **create-react-app**, Jest and React Testing Library are already set up for you. If you're using a custom setup, you can install these libraries:

```bash
npm install --save-dev jest @testing-library/react @testing-library/jest-dom
```

- **@testing-library/react** provides the functions to render and interact with your components.
- **@testing-library/jest-dom** adds custom matchers (like `toBeInTheDocument()`) to Jest for easier assertions.

---

## **2. Basic Test Structure**

Tests are written using Jest's `test()` or `it()` functions and assertions like `expect()`.

Example:

```javascript
test('checks if component renders correctly', () => {
  render(<MyComponent />);
  const element = screen.getByText(/hello world/i);
  expect(element).toBeInTheDocument();
});
```

---

## **3. Writing Tests for React Components**

### **Step 1: Test a Simple Component**

Let’s create a simple **Button** component and write a unit test for it.

**Button.js** (React Component)
```javascript
import React from 'react';

const Button = ({ label, onClick }) => {
  return (
    <button onClick={onClick}>{label}</button>
  );
};

export default Button;
```

**Button.test.js** (Unit Test for Button)
```javascript
import { render, screen, fireEvent } from '@testing-library/react';
import Button from './Button';

test('renders button with correct label and calls onClick when clicked', () => {
  const mockClick = jest.fn();
  
  render(<Button label="Click Me" onClick={mockClick} />);
  
  // Check if the button renders correctly
  const button = screen.getByText(/click me/i);
  expect(button).toBeInTheDocument();

  // Simulate a click event
  fireEvent.click(button);

  // Check if the click handler was called
  expect(mockClick).toHaveBeenCalledTimes(1);
});
```

- **`render(<Button />)`**: Renders the `Button` component.
- **`screen.getByText('Click Me')`**: Selects the button by its text content.
- **`fireEvent.click()`**: Simulates a click event on the button.
- **`expect(mockClick).toHaveBeenCalledTimes(1)`**: Asserts that the `onClick` function was called once.

---

### **Step 2: Test Component with State**

React components often contain state. Let's test a component that interacts with state.

**Counter.js** (Component with State)
```javascript
import React, { useState } from 'react';

const Counter = () => {
  const [count, setCount] = useState(0);

  const increment = () => setCount(count + 1);
  const decrement = () => setCount(count - 1);

  return (
    <div>
      <p>Count: {count}</p>
      <button onClick={increment}>Increment</button>
      <button onClick={decrement}>Decrement</button>
    </div>
  );
};

export default Counter;
```

**Counter.test.js** (Unit Test for Counter Component)
```javascript
import { render, screen, fireEvent } from '@testing-library/react';
import Counter from './Counter';

test('renders Counter and interacts with buttons', () => {
  render(<Counter />);

  // Get the buttons and count element
  const incrementButton = screen.getByText(/increment/i);
  const decrementButton = screen.getByText(/decrement/i);
  const countDisplay = screen.getByText(/count: 0/i);

  // Check initial count
  expect(countDisplay).toBeInTheDocument();

  // Simulate clicking increment button
  fireEvent.click(incrementButton);
  expect(screen.getByText(/count: 1/i)).toBeInTheDocument();

  // Simulate clicking decrement button
  fireEvent.click(decrementButton);
  expect(screen.getByText(/count: 0/i)).toBeInTheDocument();
});
```

- **`screen.getByText()`**: Selects elements based on their text.
- **`fireEvent.click()`**: Simulates a user clicking on the button.

---

### **Step 3: Test Asynchronous Components**

If your component fetches data from an API or uses asynchronous actions, you can test it with **async** functions in Jest.

**UserProfile.js** (Component that fetches data)
```javascript
import React, { useState, useEffect } from 'react';

const UserProfile = () => {
  const [user, setUser] = useState(null);

  useEffect(() => {
    const fetchUser = async () => {
      const response = await fetch('/api/user');
      const data = await response.json();
      setUser(data);
    };
    fetchUser();
  }, []);

  if (!user) return <div>Loading...</div>;
  return <div>{user.name}</div>;
};

export default UserProfile;
```

**UserProfile.test.js** (Test for Asynchronous Component)
```javascript
import { render, screen, waitFor } from '@testing-library/react';
import UserProfile from './UserProfile';

test('fetches and displays user profile', async () => {
  // Mock API response
  global.fetch = jest.fn().mockResolvedValue({
    json: jest.fn().mockResolvedValue({ name: 'John Doe' }),
  });

  render(<UserProfile />);

  // Check that loading is displayed initially
  expect(screen.getByText(/loading/i)).toBeInTheDocument();

  // Wait for the user name to appear
  await waitFor(() => screen.getByText(/john doe/i));

  // Check if the user name is rendered
  expect(screen.getByText(/john doe/i)).toBeInTheDocument();
});
```

- **`jest.fn()`**: Mocks the `fetch` function.
- **`mockResolvedValue`**: Mocks a successful response from the API.
- **`await waitFor()`**: Waits for the async operation to complete and ensures that the element appears on the screen.

---

### **Step 4: Testing Form Components**

For testing form components, you will often simulate user interactions like typing into inputs and submitting forms.

**LoginForm.js** (Component with Form)
```javascript
import React, { useState } from 'react';

const LoginForm = ({ onSubmit }) => {
  const [email, setEmail] = useState('');

  const handleChange = (e) => setEmail(e.target.value);
  const handleSubmit = (e) => {
    e.preventDefault();
    onSubmit(email);
  };

  return (
    <form onSubmit={handleSubmit}>
      <input
        type="email"
        value={email}
        onChange={handleChange}
        placeholder="Enter email"
      />
      <button type="submit">Submit</button>
    </form>
  );
};

export default LoginForm;
```

**LoginForm.test.js** (Unit Test for LoginForm)
```javascript
import { render, screen, fireEvent } from '@testing-library/react';
import LoginForm from './LoginForm';

test('calls onSubmit with email when form is submitted', () => {
  const mockSubmit = jest.fn();
  
  render(<LoginForm onSubmit={mockSubmit} />);
  
  // Type in the input field
  fireEvent.change(screen.getByPlaceholderText(/enter email/i), {
    target: { value: 'test@example.com' },
  });
  
  // Simulate form submission
  fireEvent.click(screen.getByText(/submit/i));
  
  // Check if onSubmit was called with the correct argument
  expect(mockSubmit).toHaveBeenCalledWith('test@example.com');
});
```

- **`fireEvent.change()`**: Simulates typing into an input field.
- **`fireEvent.click()`**: Simulates clicking the submit button.

---

## **4. Mocking External Modules and API Calls**

Sometimes, you need to mock external dependencies like modules or API calls to isolate your tests.

### **Mocking a Module**
If you're using an external module like **axios** for API calls, you can mock it:

```javascript
jest.mock('axios');
```

Then you can specify mock implementations for the functions:
```javascript
import axios from 'axios';
import { fetchData } from './api';

jest.mock('axios');

test('fetches data and updates state', async () => {
  axios.get.mockResolvedValue({ data: 'some data' });

  // Your test logic here
});
```

---

## **5. Running Tests**

To run your tests, you can simply execute:

```bash
npm test
```

This will start Jest and run all tests in your project.

---

## **Conclusion**

- **Unit Testing**: Focuses on testing individual components and their logic in isolation.
- **React Testing Library**: Encourages testing from the user's perspective (e.g., using `screen.getByText()` instead of testing implementation details).
- **Jest**: Provides the test runner, assertions, and mocks.

With **Jest** and **React Testing Library**, you can ensure that your components behave as expected and that your application remains reliable as it grows. 
