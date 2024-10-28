Creating custom data structures in JavaScript allows you to organize and manipulate data in specialized ways tailored to your application's requirements. Here's a guide to creating custom data structures using JavaScript:

## 1. Object-Based Data Structures

JavaScript's object literal syntax allows you to create custom data structures easily. You can define properties and methods directly within an object.

### Example: Stack Data Structure

```javascript
// Stack data structure using an object
class Stack {
  constructor() {
    this.items = [];
  }

  push(item) {
    this.items.push(item);
  }

  pop() {
    if (this.items.length === 0) return null;
    return this.items.pop();
  }

  peek() {
    return this.items.length > 0 ? this.items[this.items.length - 1] : null;
  }

  isEmpty() {
    return this.items.length === 0;
  }

  size() {
    return this.items.length;
  }
}

// Usage
const stack = new Stack();
stack.push(1);
stack.push(2);
console.log(stack.peek()); // Output: 2
console.log(stack.pop()); // Output: 2
console.log(stack.isEmpty()); // Output: false
console.log(stack.size()); // Output: 1
```

## 2. Class-Based Data Structures

JavaScript classes provide a more structured and object-oriented approach to defining custom data structures. You can use classes to encapsulate data and behavior within a single entity.

### Example: Queue Data Structure

```javascript
// Queue data structure using a class
class Queue {
  constructor() {
    this.items = [];
  }

  enqueue(item) {
    this.items.push(item);
  }

  dequeue() {
    if (this.items.length === 0) return null;
    return this.items.shift();
  }

  peek() {
    return this.items.length > 0 ? this.items[0] : null;
  }

  isEmpty() {
    return this.items.length === 0;
  }

  size() {
    return this.items.length;
  }
}

// Usage
const queue = new Queue();
queue.enqueue(1);
queue.enqueue(2);
console.log(queue.peek()); // Output: 1
console.log(queue.dequeue()); // Output: 1
console.log(queue.isEmpty()); // Output: false
console.log(queue.size()); // Output: 1
```

## 3. Using Arrays and Maps

JavaScript arrays and maps provide built-in data structures that can be customized and extended to suit specific needs. You can combine arrays, maps, and objects to create more complex data structures.

### Example: Graph Data Structure

```javascript
// Graph data structure using a map
class Graph {
  constructor() {
    this.vertices = new Map();
  }

  addVertex(vertex) {
    if (!this.vertices.has(vertex)) {
      this.vertices.set(vertex, []);
    }
  }

  addEdge(vertex1, vertex2) {
    this.vertices.get(vertex1).push(vertex2);
    this.vertices.get(vertex2).push(vertex1);
  }

  getNeighbors(vertex) {
    return this.vertices.get(vertex);
  }

  hasVertex(vertex) {
    return this.vertices.has(vertex);
  }

  size() {
    return this.vertices.size;
  }
}

// Usage
const graph = new Graph();
graph.addVertex('A');
graph.addVertex('B');
graph.addEdge('A', 'B');
console.log(graph.getNeighbors('A')); // Output: ['B']
console.log(graph.hasVertex('C')); // Output: false
console.log(graph.size()); // Output: 2
```

## Conclusion

Creating custom data structures in JavaScript allows you to organize and manipulate data efficiently for various use cases. Whether using object-based structures, classes, or built-in data structures, understanding how to design and implement custom data structures is essential for developing complex applications.
