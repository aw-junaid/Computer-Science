Object-Oriented Programming (OOP) is widely used in JavaScript frameworks like **React**, **Angular**, and **Vue**. Each of these frameworks can leverage OOP principles to manage state, enhance component reusability, and improve code organization. However, these frameworks often emphasize component-based architectures, where **composition** is commonly used alongside OOP concepts.

Let's explore how OOP is applied in **React**, **Angular**, and **Vue**:

---

### **1. OOP in React**
React is primarily based on **functional components** and **hooks**, but it also allows for **class components**, which make use of traditional OOP concepts.

#### **Class Components**
Class components in React allow you to use OOP principles like **encapsulation**, **inheritance**, and **polymorphism**. You can define state, lifecycle methods, and methods within classes.

- **Example of a Class Component**:
  ```javascript
  class Counter extends React.Component {
    constructor(props) {
      super(props);
      this.state = { count: 0 };
    }

    increment = () => {
      this.setState({ count: this.state.count + 1 });
    }

    render() {
      return (
        <div>
          <p>Count: {this.state.count}</p>
          <button onClick={this.increment}>Increment</button>
        </div>
      );
    }
  }
  ```

#### **State Management in React**
React's state and props also reflect OOP principles. **Encapsulation** can be achieved by managing component state locally, while **composition** allows you to combine smaller components to create complex user interfaces.

- **Encapsulation with Hooks Example** (Functional Component):
  ```javascript
  import React, { useState } from 'react';

  function Counter() {
    const [count, setCount] = useState(0);

    const increment = () => setCount(count + 1);

    return (
      <div>
        <p>Count: {count}</p>
        <button onClick={increment}>Increment</button>
      </div>
    );
  }
  ```

#### **Component Inheritance in React**
While React does not natively use inheritance, you can simulate **inheritance** using **higher-order components (HOCs)**, which allow you to extend or enhance the functionality of existing components.

- **HOC Example** (Simulating Inheritance):
  ```javascript
  function withLogger(Component) {
    return function EnhancedComponent(props) {
      console.log('Component rendered');
      return <Component {...props} />;
    };
  }

  const MyComponent = (props) => <div>Hello, {props.name}</div>;
  const MyComponentWithLogger = withLogger(MyComponent);
  ```

---

### **2. OOP in Angular**
Angular is a **TypeScript-based framework** that heavily uses OOP principles. TypeScript adds **static typing**, **classes**, and **interfaces** to Angular, enabling developers to structure applications more effectively with OOP concepts.

#### **Classes and Components**
In Angular, components are defined as classes. You can use **encapsulation** with component state, **inheritance** with base classes, and **polymorphism** with interfaces.

- **Class-based Component Example**:
  ```typescript
  import { Component } from '@angular/core';

  @Component({
    selector: 'app-counter',
    template: `
      <div>
        <p>Count: {{ count }}</p>
        <button (click)="increment()">Increment</button>
      </div>
    `
  })
  export class CounterComponent {
    count: number = 0;

    increment() {
      this.count++;
    }
  }
  ```

#### **Encapsulation in Angular**
Angular's **services** are often used for state management, providing an encapsulated state that can be shared across components using **dependency injection**.

- **Service Example (Encapsulation)**:
  ```typescript
  import { Injectable } from '@angular/core';

  @Injectable({
    providedIn: 'root',
  })
  export class CounterService {
    private count: number = 0;

    increment() {
      this.count++;
    }

    getCount(): number {
      return this.count;
    }
  }
  ```

#### **Interfaces and Inheritance**
Angular encourages the use of **interfaces** to define contracts for components or services, simulating **abstract classes**. You can also use **base classes** for shared logic across components.

- **Interface Example**:
  ```typescript
  interface ICounter {
    increment(): void;
    getCount(): number;
  }

  class BasicCounter implements ICounter {
    private count: number = 0;

    increment() {
      this.count++;
    }

    getCount() {
      return this.count;
    }
  }
  ```

---

### **3. OOP in Vue.js**
Vue.js, like React, is a **component-based framework** but offers **two main ways** to define components: using the **Options API** (using object syntax) and the **Composition API** (introduced in Vue 3). Vue is more oriented toward composition rather than traditional inheritance, but you can still apply OOP principles.

#### **Class Components in Vue**
While Vue doesn’t use classes by default, you can use **Vue Class Component** to define components as ES6 classes.

- **Class-based Component Example** (using Vue Class Component):
  ```javascript
  import { Vue } from 'vue-property-decorator';

  @Component
  export default class Counter extends Vue {
    count = 0;

    increment() {
      this.count++;
    }
  }
  ```

#### **Encapsulation in Vue**
Vue's **reactivity system** can help encapsulate and manage state within individual components. The **data** function in Vue’s Options API provides encapsulation for the component's state.

- **Encapsulation in Vue** (Options API):
  ```javascript
  new Vue({
    el: '#app',
    data() {
      return { count: 0 };
    },
    methods: {
      increment() {
        this.count++;
      }
    }
  });
  ```

#### **Composition API and Reusability**
Vue's **Composition API** promotes the use of **composables** (functions) to encapsulate logic. This allows for greater flexibility and reusability, but doesn't follow traditional OOP inheritance.

- **Composition API Example**:
  ```javascript
  import { ref } from 'vue';

  export default {
    setup() {
      const count = ref(0);

      const increment = () => {
        count.value++;
      };

      return { count, increment };
    }
  };
  ```

#### **Mixins and Composition**
Vue supports **mixins**, which allow you to mix functionality from multiple sources into a single component, resembling **composition** in OOP.

- **Mixin Example**:
  ```javascript
  const counterMixin = {
    data() {
      return { count: 0 };
    },
    methods: {
      increment() {
        this.count++;
      }
    }
  };

  new Vue({
    mixins: [counterMixin],
    template: `<div>{{ count }} <button @click="increment">Increment</button></div>`
  });
  ```

---

### **Comparison of OOP in React, Angular, and Vue**

| **Aspect**                | **React**                          | **Angular**                       | **Vue.js**                        |
|---------------------------|------------------------------------|-----------------------------------|-----------------------------------|
| **OOP Support**            | Class Components, Composition      | TypeScript, Classes, Interfaces   | Class-based components (optional), Composition API |
| **Encapsulation**          | Local state with classes or hooks  | Services for state management     | Component state, Reactive system  |
| **Inheritance**            | Simulated via HOCs and Mixins     | Base classes, Interfaces          | Mixins, Class components (optional) |
| **Polymorphism**           | Higher-order components, Function props | Interfaces for polymorphism       | Mixins and Composition API       |
| **Reusability**            | Components, HOCs, Hooks           | Services, Directives, Components  | Components, Mixins, Composition API |
| **Component Structure**    | Functional & Class Components      | Class-based, Modules              | Options API & Composition API    |

---

### **Conclusion**

- **React** is more flexible, using both **functional** and **class components**. It supports **composition** and **higher-order components** as a way to simulate inheritance and polymorphism.
- **Angular** follows a **TypeScript-based OOP** approach, emphasizing **class-based components**, **services**, and **dependency injection**, making it ideal for larger, more structured applications.
- **Vue** primarily emphasizes **composition** with its **Options API** and **Composition API**, while also supporting **class-based components** and **mixins** to leverage OOP principles.

In all three frameworks, **composition** is often preferred over **inheritance**, and OOP principles like **encapsulation**, **polymorphism**, and **reusability** can be applied in a variety of ways depending on the framework's architecture and features.
