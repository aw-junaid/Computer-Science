### **Capstone Project: Real-World Implementation of OOP in JavaScript**

In this capstone project, we will build a **task management application** to demonstrate the real-world application of Object-Oriented Programming (OOP) principles in JavaScript. The application will allow users to manage tasks, categorize them, and track progress. We will focus on the key OOP concepts: **Encapsulation**, **Inheritance**, **Polymorphism**, and **Abstraction**, and implement them in a functional, modular application.

---

### **Project Overview: Task Manager Application**

The **Task Manager** will allow users to:
- Create, update, and delete tasks.
- Categorize tasks (e.g., Work, Personal, etc.).
- Track task completion (e.g., Not Started, In Progress, Completed).
- Prioritize tasks (e.g., High, Medium, Low).
- Assign deadlines and set reminders for tasks.

We will build the application using JavaScript and demonstrate **OOP principles** for maintainability, flexibility, and scalability.

---

### **1. Define the Project Structure**

We'll break the project into the following components:

- **Task**: Representing an individual task with its attributes and methods.
- **TaskList**: Managing a collection of tasks (CRUD operations).
- **Category**: Categorizing tasks.
- **Priority**: Assigning priority levels to tasks.
- **User**: Managing user-specific data.

---

### **2. OOP Principles Applied**

#### **Encapsulation**
Encapsulation will be used to hide task details and only expose necessary methods for interacting with tasks, such as creating, updating, and changing the task’s status.

#### **Inheritance**
We will create a base class (`Task`) and extend it to create more specialized task types, such as `DeadlineTask`, which inherits from `Task` and adds additional functionality like handling deadlines.

#### **Polymorphism**
We will use polymorphism to allow different task types (e.g., `DeadlineTask`, `PriorityTask`) to override methods like `getDescription()` to display different information depending on the task type.

#### **Abstraction**
Abstract methods will be defined in base classes, ensuring that derived classes must implement them. For example, an abstract method `updateStatus()` can be defined in a base `Task` class and implemented in specific types of tasks.

---

### **3. Create the Task Management Classes**

#### **Task Class** (Base Class)

This class will encapsulate the properties of a task and provide methods for interacting with them.

```javascript
class Task {
  constructor(title, description) {
    this.title = title;
    this.description = description;
    this.status = 'Not Started'; // Default status
  }

  // Method to update the status of the task
  updateStatus(newStatus) {
    if (['Not Started', 'In Progress', 'Completed'].includes(newStatus)) {
      this.status = newStatus;
    } else {
      console.log('Invalid status');
    }
  }

  // Method to display task description
  getDescription() {
    return `${this.title}: ${this.description} (Status: ${this.status})`;
  }
}
```

#### **DeadlineTask Class** (Inherits from Task)

This class will extend the `Task` class and add a deadline property and methods to handle deadlines.

```javascript
class DeadlineTask extends Task {
  constructor(title, description, deadline) {
    super(title, description);
    this.deadline = deadline; // Deadline property
  }

  // Overriding the getDescription method to include the deadline
  getDescription() {
    return `${super.getDescription()} | Deadline: ${this.deadline}`;
  }

  // Method to check if the task is overdue
  isOverdue() {
    const currentDate = new Date();
    const taskDeadline = new Date(this.deadline);
    return taskDeadline < currentDate;
  }
}
```

#### **PriorityTask Class** (Inherits from Task)

This class will extend the `Task` class and add a priority property to handle task prioritization.

```javascript
class PriorityTask extends Task {
  constructor(title, description, priority) {
    super(title, description);
    this.priority = priority; // Priority property
  }

  // Overriding the getDescription method to include priority
  getDescription() {
    return `${super.getDescription()} | Priority: ${this.priority}`;
  }
}
```

---

### **4. TaskList Class**

The `TaskList` class will manage a collection of tasks and provide methods for adding, removing, and retrieving tasks.

```javascript
class TaskList {
  constructor() {
    this.tasks = [];
  }

  // Add a task to the list
  addTask(task) {
    if (task instanceof Task) {
      this.tasks.push(task);
    } else {
      console.log('Only instances of Task or its subclasses can be added.');
    }
  }

  // Remove a task from the list
  removeTask(taskTitle) {
    this.tasks = this.tasks.filter(task => task.title !== taskTitle);
  }

  // Get all tasks
  getTasks() {
    return this.tasks;
  }

  // Find tasks by status
  findByStatus(status) {
    return this.tasks.filter(task => task.status === status);
  }
}
```

---

### **5. Category Class**

The `Category` class will categorize tasks into predefined categories (e.g., Work, Personal) and filter tasks by category.

```javascript
class Category {
  constructor(name) {
    this.name = name;
    this.tasks = [];
  }

  // Add a task to this category
  addTask(task) {
    if (task instanceof Task) {
      this.tasks.push(task);
    } else {
      console.log('Only instances of Task can be added to a category.');
    }
  }

  // Get all tasks in this category
  getTasks() {
    return this.tasks;
  }
}
```

---

### **6. Implementing the Application**

Now that we have our classes, let’s integrate them into the task manager application:

```javascript
const taskList = new TaskList();

// Create some tasks
const task1 = new Task('Task 1', 'Complete coding assignment');
const task2 = new DeadlineTask('Task 2', 'Submit report', '2025-01-10');
const task3 = new PriorityTask('Task 3', 'Prepare presentation', 'High');

// Add tasks to the task list
taskList.addTask(task1);
taskList.addTask(task2);
taskList.addTask(task3);

// Update task status
task2.updateStatus('In Progress');

// Display tasks
console.log(taskList.getTasks().map(task => task.getDescription()));

// Remove a task
taskList.removeTask('Task 1');

// Find tasks by status
console.log(taskList.findByStatus('In Progress').map(task => task.getDescription()));
```

---

### **7. Enhancing the Application with Additional Features**

To further enhance the task manager, we can add more features:
- **User Authentication**: A `User` class to manage users and their tasks.
- **Notifications**: Sending notifications for upcoming deadlines or changes in task status.
- **Task Sorting and Filtering**: Sorting tasks by deadline or priority and filtering tasks by category or status.
- **Persistence**: Saving tasks to local storage or a database.

---

### **8. Best Practices Applied**
- **Encapsulation**: Task details and methods are encapsulated within classes.
- **Inheritance**: Different types of tasks inherit from the base `Task` class.
- **Polymorphism**: Methods like `getDescription()` are overridden in derived classes to provide different behavior based on the task type.
- **Abstraction**: Task management and filtering are abstracted within methods, hiding implementation details.

---

### **Conclusion**

This capstone project demonstrates how to implement OOP principles in a real-world JavaScript application. By organizing your code into classes and using inheritance, polymorphism, encapsulation, and abstraction, you can create maintainable, flexible, and scalable applications. The **Task Manager** is just one example of how these principles can be applied to solve practical problems effectively in JavaScript.
