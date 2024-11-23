Data structures are ways of organizing and storing data in a computer so that it can be accessed and modified efficiently. Different data structures are used for different types of tasks, depending on the nature of the data and the operations required. Here are some common data structures:

### 1. **Arrays**
   - A collection of elements, all of the same type, stored in contiguous memory locations.
   - **Operations**: Access by index, insert, delete, iterate.
   - **Time Complexity**:
     - Access: O(1)
     - Insertion/Deletion: O(n) (worst case)

### 2. **Linked Lists**
   - A linear collection of elements, where each element (node) points to the next one.
   - **Types**: 
     - Singly Linked List
     - Doubly Linked List
     - Circular Linked List
   - **Operations**:
     - Insertion and deletion at the beginning or end: O(1)
     - Access by index: O(n)
   
### 3. **Stacks**
   - A collection of elements that follows the **LIFO** (Last In, First Out) principle.
   - **Operations**: Push (add element), Pop (remove element), Peek (view top element).
   - **Time Complexity**:
     - Push/Pop: O(1)
     - Peek: O(1)
   
### 4. **Queues**
   - A collection of elements that follows the **FIFO** (First In, First Out) principle.
   - **Types**:
     - Simple Queue
     - Circular Queue
     - Priority Queue
   - **Operations**: Enqueue (add element), Dequeue (remove element), Peek (view front element).
   - **Time Complexity**:
     - Enqueue/Dequeue: O(1)
   
### 5. **Hash Tables (Hash Maps)**
   - A collection of key-value pairs, where each key is unique and maps to a value.
   - **Operations**:
     - Insert, Search, Delete: O(1) on average, but can be O(n) in worst cases (e.g., when hash collisions occur).
   
### 6. **Trees**
   - A hierarchical structure consisting of nodes, where each node has a value and zero or more child nodes.
   - **Types**:
     - Binary Trees (each node has at most two children)
     - Binary Search Trees (BST)
     - AVL Trees (self-balancing BST)
     - Red-Black Trees (another type of balanced BST)
   - **Operations**:
     - Insertion/Deletion/Search: O(log n) in balanced trees, O(n) in unbalanced trees.
   
### 7. **Heaps**
   - A special tree-based structure that satisfies the **heap property**.
   - **Types**:
     - Max-Heap (parent nodes are greater than child nodes)
     - Min-Heap (parent nodes are smaller than child nodes)
   - **Operations**:
     - Insert: O(log n)
     - Delete (removing the root): O(log n)
   
### 8. **Graphs**
   - A collection of nodes (vertices) and edges that connect pairs of nodes.
   - **Types**:
     - Directed vs. Undirected
     - Weighted vs. Unweighted
   - **Representation**:
     - Adjacency Matrix
     - Adjacency List
   - **Operations**:
     - Traverse (DFS/BFS): O(V + E) where V is vertices and E is edges.
     - Search: O(V) in a basic graph.

### 9. **Tries**
   - A tree-like data structure used for efficient retrieval of a key in a dataset of strings, mainly used in applications like dictionaries and autocomplete.
   - **Operations**: Insert, Search, and Delete take O(k) time, where k is the length of the key.
   
### 10. **Disjoint Set (Union-Find)**
   - A data structure used for partitioning a set into disjoint (non-overlapping) subsets.
   - **Operations**:
     - Union (combine two subsets): O(α(n))
     - Find (find the representative of a subset): O(α(n))
   - **Applications**: Used in network connectivity, Kruskal’s algorithm, etc.

### Choosing the Right Data Structure:
- The choice of data structure depends on the problem's requirements, such as speed of access, frequency of modifications, and memory usage.
- For example:
  - Use an **array** if you need fast access by index.
  - Use a **linked list** if you frequently insert or delete elements.
  - Use a **hash table** if you need fast search operations with unique keys.
  - Use a **tree** or **heap** if you need efficient searching, inserting, and deleting sorted data.

