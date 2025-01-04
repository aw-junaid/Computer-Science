Improving existing code using **Object-Oriented Programming (OOP)** principles involves restructuring the code to better adhere to OOP concepts like **Encapsulation**, **Inheritance**, **Polymorphism**, and **Abstraction**. Let's improve a simple example application by refactoring it using these principles.

### **Example: A Basic Task Manager**

Let's assume we have a basic task manager application with the following features:
- Tasks can be added, completed, or removed.
- Each task has a name and a completion status.

We'll refactor this code by applying **OOP principles** to make it more modular, extensible, and maintainable.

---

### **1. Encapsulation**

**Encapsulation** is the principle of bundling data (properties) and methods (functions) that operate on the data into a single unit called a class. We will refactor the code to hide the internal state of tasks and only expose necessary methods for interacting with the task data.

#### **Before:**

```javascript
let tasks = [];

function addTask(name) {
  tasks.push({ name: name, completed: false });
}

function completeTask(name) {
  const task = tasks.find(task => task.name === name);
  if (task) {
    task.completed = true;
  }
}

function removeTask(name) {
  tasks = tasks.filter(task => task.name !== name);
}

function getTasks() {
  return tasks;
}
```

#### **After (Encapsulation):**

```javascript
class Task {
  constructor(name) {
    this.name = name;
    this.completed = false;
  }

  complete() {
    this.completed = true;
  }

  toString() {
    return `${this.name} - ${this.completed ? 'Completed' : 'Pending'}`;
  }
}

class TaskManager {
  constructor() {
    this.tasks = [];
  }

  addTask(name) {
    const task = new Task(name);
    this.tasks.push(task);
  }

  removeTask(name) {
    this.tasks = this.tasks.filter(task => task.name !== name);
  }

  getTasks() {
    return this.tasks;
  }
}
```

**Changes:**
- The `Task` class encapsulates the task's properties and behavior.
- The `TaskManager` class manages the collection of tasks, making it easier to add, remove, and retrieve tasks.

---

### **2. Inheritance**

**Inheritance** allows one class to inherit the properties and methods of another class. This enables code reuse and extension. Let's say we want to add two types of tasks: **HighPriorityTask** and **LowPriorityTask**, which have different behaviors (e.g., high-priority tasks should be completed faster).

#### **Before:**

```javascript
function addTask(name, priority) {
  tasks.push({ name: name, completed: false, priority: priority });
}

function getTasks() {
  return tasks.sort((a, b) => a.priority - b.priority);  // Sorting by priority
}
```

#### **After (Inheritance):**

```javascript
class Task {
  constructor(name) {
    this.name = name;
    this.completed = false;
  }

  complete() {
    this.completed = true;
  }

  toString() {
    return `${this.name} - ${this.completed ? 'Completed' : 'Pending'}`;
  }
}

class HighPriorityTask extends Task {
  constructor(name) {
    super(name);
    this.priority = 'High';
  }

  complete() {
    console.log("High-priority task is completed faster!");
    super.complete();
  }
}

class LowPriorityTask extends Task {
  constructor(name) {
    super(name);
    this.priority = 'Low';
  }
}

class TaskManager {
  constructor() {
    this.tasks = [];
  }

  addTask(name, priority) {
    if (priority === 'High') {
      this.tasks.push(new HighPriorityTask(name));
    } else {
      this.tasks.push(new LowPriorityTask(name));
    }
  }

  removeTask(name) {
    this.tasks = this.tasks.filter(task => task.name !== name);
  }

  getTasks() {
    return this.tasks.sort((a, b) => a.priority === 'High' ? -1 : 1);  // Sort by priority
  }
}
```

**Changes:**
- Created `HighPriorityTask` and `LowPriorityTask` classes that inherit from `Task`.
- Overrode the `complete()` method in `HighPriorityTask` to add custom behavior.
- The `TaskManager` now supports adding tasks with different priorities and sorting them accordingly.

---

### **3. Polymorphism**

**Polymorphism** allows objects of different classes to be treated as objects of a common superclass. It enables different objects to respond to the same method call in a way that is appropriate for their type.

#### **Before:**

```javascript
function completeTask(name) {
  const task = tasks.find(task => task.name === name);
  if (task) {
    task.completed = true;
  }
}
```

#### **After (Polymorphism):**

```javascript
class Task {
  constructor(name) {
    this.name = name;
    this.completed = false;
  }

  complete() {
    this.completed = true;
  }

  toString() {
    return `${this.name} - ${this.completed ? 'Completed' : 'Pending'}`;
  }
}

class HighPriorityTask extends Task {
  complete() {
    console.log("High-priority task completed faster!");
    super.complete();
  }
}

class LowPriorityTask extends Task {}

class TaskManager {
  constructor() {
    this.tasks = [];
  }

  addTask(name, priority) {
    const task = priority === 'High' ? new HighPriorityTask(name) : new LowPriorityTask(name);
    this.tasks.push(task);
  }

  completeTask(name) {
    const task = this.tasks.find(t => t.name === name);
    if (task) {
      task.complete();  // Polymorphism: different behavior depending on task type
    }
  }

  getTasks() {
    return this.tasks;
  }
}
```

**Changes:**
- The `complete()` method is overridden in `HighPriorityTask` to provide specific behavior.
- The `completeTask()` method calls the `complete()` method on all tasks, but each task type responds differently due to polymorphism.

---

### **4. Abstraction**

**Abstraction** is the process of hiding the complex implementation details and exposing only essential features. We'll refactor the code to provide a clean interface while hiding the internal workings.

#### **Before:**

```javascript
let tasks = [];

function addTask(name) {
  tasks.push({ name: name, completed: false });
}

function getTasks() {
  return tasks;
}
```

#### **After (Abstraction):**

```javascript
class Task {
  constructor(name) {
    this.name = name;
    this.completed = false;
  }

  complete() {
    this.completed = true;
  }

  toString() {
    return `${this.name} - ${this.completed ? 'Completed' : 'Pending'}`;
  }
}

class TaskManager {
  constructor() {
    this.tasks = [];
  }

  addTask(name) {
    const task = new Task(name);
    this.tasks.push(task);
  }

  completeTask(name) {
    const task = this.tasks.find(t => t.name === name);
    if (task) {
      task.complete();
    }
  }

  getTasks() {
    return this.tasks.map(task => task.toString());  // Abstracted implementation
  }
}
```

**Changes:**
- The `TaskManager` class hides the internal data structure (`tasks`) and exposes a clean interface for interacting with tasks.
- The `getTasks()` method returns a simple string representation of each task, abstracting away the details of how tasks are stored and managed.

---

### **Final Improved Code**

By applying OOP principles, the improved code structure is much cleaner, more modular, and easier to extend:

```javascript
class Task {
  constructor(name) {
    this.name = name;
    this.completed = false;
  }

  complete() {
    this.completed = true;
  }

  toString() {
    return `${this.name} - ${this.completed ? 'Completed' : 'Pending'}`;
  }
}

class HighPriorityTask extends Task {
  complete() {
    console.log("High-priority task completed faster!");
    super.complete();
  }
}

class LowPriorityTask extends Task {}

class TaskManager {
  constructor() {
    this.tasks = [];
  }

  addTask(name, priority = 'Low') {
    const task = priority === 'High' ? new HighPriorityTask(name) : new LowPriorityTask(name);
    this.tasks.push(task);
  }

  completeTask(name) {
    const task = this.tasks.find(t => t.name === name);
    if (task) {
      task.complete();
    }
  }

  getTasks() {
    return this.tasks.map(task => task.toString());
  }
}
```

### **Summary of OOP Principles Applied:**

1. **Encapsulation**: Task and TaskManager classes encapsulate related properties and methods, hiding internal states.
2. **Inheritance**: `HighPriorityTask` and `LowPriorityTask` inherit from `Task` to reuse code and extend behavior.
3. **Polymorphism**: Different types of tasks respond differently to the `complete()` method, depending on their class.
4. **Abstraction**: The `TaskManager` exposes only necessary methods like `addTask`, `completeTask`, and `getTasks`, hiding internal details.

This refactoring improves the structure, maintainability, and scalability of the code, making it more aligned with OOP best practices.
