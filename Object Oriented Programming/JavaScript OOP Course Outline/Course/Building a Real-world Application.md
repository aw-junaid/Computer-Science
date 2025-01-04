### **Building a Real-world Application Using Design Patterns in JavaScript**

When building a real-world application, you can apply various design patterns to organize and structure your code efficiently. In this section, we will build a simple **task management** application, applying several key design patterns to demonstrate how to structure real-world applications.

---

### **Project Overview**

We will create a **Task Management Application** where users can:
- Add tasks to a to-do list.
- Mark tasks as completed.
- Delete tasks.
- Filter tasks based on their status (completed or pending).

We'll implement several design patterns to make the application extensible, maintainable, and scalable. The key design patterns we'll use are:

- **MVC (Model-View-Controller)** for separating concerns and managing application flow.
- **Observer Pattern** for notifying components of state changes.
- **Factory Pattern** for creating different types of tasks.
- **Singleton Pattern** for managing the task list instance.

---

### **1. Project Setup**

We will structure our app using these main components:

- **Model**: Represents the data and business logic.
- **View**: Responsible for rendering the UI.
- **Controller**: Handles the input and controls the interaction between the Model and View.

---

### **2. Implementing the MVC Pattern**

#### **Model (TaskModel.js)**

The model is responsible for maintaining the task list and notifying the controller of state changes.

```javascript
// TaskModel.js
class TaskModel {
  constructor() {
    this.tasks = [];
    this.observers = [];
  }

  addTask(task) {
    this.tasks.push(task);
    this.notifyObservers();
  }

  removeTask(taskId) {
    this.tasks = this.tasks.filter(task => task.id !== taskId);
    this.notifyObservers();
  }

  toggleTaskStatus(taskId) {
    const task = this.tasks.find(task => task.id === taskId);
    if (task) {
      task.completed = !task.completed;
      this.notifyObservers();
    }
  }

  getTasks() {
    return this.tasks;
  }

  addObserver(observer) {
    this.observers.push(observer);
  }

  removeObserver(observer) {
    this.observers = this.observers.filter(obs => obs !== observer);
  }

  notifyObservers() {
    this.observers.forEach(observer => observer.update());
  }
}
```

---

#### **View (TaskView.js)**

The view will render the list of tasks and update the UI when the model changes. It will be updated via the observer pattern.

```javascript
// TaskView.js
class TaskView {
  constructor() {
    this.taskList = document.getElementById("task-list");
  }

  render(tasks) {
    this.taskList.innerHTML = "";
    tasks.forEach(task => {
      const taskElement = document.createElement("li");
      taskElement.textContent = `${task.name} - ${task.completed ? "Completed" : "Pending"}`;
      taskElement.dataset.id = task.id;
      this.taskList.appendChild(taskElement);
    });
  }

  update() {
    const tasks = appController.getTasks();
    this.render(tasks);
  }
}
```

---

#### **Controller (TaskController.js)**

The controller will handle user input and manage communication between the model and view.

```javascript
// TaskController.js
class TaskController {
  constructor(model, view) {
    this.model = model;
    this.view = view;
    this.view.render(this.model.getTasks());
  }

  addTask(taskName) {
    const task = TaskFactory.createTask(taskName);
    this.model.addTask(task);
  }

  removeTask(taskId) {
    this.model.removeTask(taskId);
  }

  toggleTaskStatus(taskId) {
    this.model.toggleTaskStatus(taskId);
  }

  getTasks() {
    return this.model.getTasks();
  }
}
```

---

### **3. Implementing the Factory Pattern**

We will use the factory pattern to create different types of tasks. In our case, we’ll just have a simple task, but using a factory pattern allows for easy future extensions.

```javascript
// TaskFactory.js
class TaskFactory {
  static createTask(taskName) {
    return new Task(taskName);
  }
}

class Task {
  constructor(name) {
    this.id = Date.now();
    this.name = name;
    this.completed = false;
  }
}
```

---

### **4. Implementing the Singleton Pattern**

We will use the Singleton pattern for the `TaskModel` class, ensuring only one instance of the task list is created and used throughout the application.

```javascript
// Singleton TaskModel
class TaskModel {
  constructor() {
    if (TaskModel.instance) {
      return TaskModel.instance;
    }
    this.tasks = [];
    this.observers = [];
    TaskModel.instance = this;
  }

  // ... other methods (addTask, removeTask, etc.)
}
```

---

### **5. Implementing the Observer Pattern**

The **TaskModel** class already implements the observer pattern, where the view (observer) gets notified whenever the model’s state changes. This allows the view to update automatically when a task is added, removed, or toggled.

In this case:
- **Model** notifies the **View**.
- The **View** updates the UI accordingly.

---

### **6. Putting It All Together**

Finally, we can tie everything together in the main application file.

```javascript
// app.js
const appModel = new TaskModel();
const appView = new TaskView();
const appController = new TaskController(appModel, appView);

// Adding observers (views) to the model
appModel.addObserver(appView);

// Example UI Interaction (e.g., using HTML buttons)
document.getElementById("add-task-btn").addEventListener("click", () => {
  const taskName = document.getElementById("task-input").value;
  appController.addTask(taskName);
});

document.getElementById("task-list").addEventListener("click", (event) => {
  if (event.target.tagName === "LI") {
    const taskId = parseInt(event.target.dataset.id);
    appController.toggleTaskStatus(taskId);
  }
});
```

### **HTML Structure**

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Task Management App</title>
</head>
<body>
  <input type="text" id="task-input" placeholder="Add new task">
  <button id="add-task-btn">Add Task</button>

  <ul id="task-list"></ul>

  <script src="TaskModel.js"></script>
  <script src="TaskView.js"></script>
  <script src="TaskController.js"></script>
  <script src="TaskFactory.js"></script>
  <script src="app.js"></script>
</body>
</html>
```

---

### **Summary of Design Patterns Used**

1. **MVC (Model-View-Controller)**:
   - The Model represents the application's data.
   - The View is responsible for rendering the UI.
   - The Controller manages user input and updates the Model and View.
   
2. **Observer Pattern**:
   - The Model notifies the View whenever the state changes, ensuring the UI stays in sync with the data.
   
3. **Factory Pattern**:
   - We use a factory to create task instances, which helps in managing the task creation process.
   
4. **Singleton Pattern**:
   - The TaskModel is a singleton to ensure there is only one instance managing all tasks in the application.

---

### **Benefits of Using Design Patterns**

- **Scalability**: The application is easily extendable. You can add more types of tasks or behaviors with minimal changes to existing code.
- **Maintainability**: The separation of concerns (MVC) makes the code easier to maintain and debug.
- **Reusability**: Components like the Task model and Task view are modular and reusable.
- **Flexibility**: Design patterns like Factory and Observer allow dynamic behavior changes and enhancements.

---

By following design patterns like MVC, Observer, and Factory, we’ve built a flexible and maintainable task management application that can easily be extended to add more features, such as different task priorities, due dates, or notifications.
