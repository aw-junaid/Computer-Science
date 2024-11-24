### **Graph Data Structure**

A **graph** is a collection of nodes (also called vertices) and edges (also called arcs) that connect pairs of nodes. Graphs are used to model relationships and networks in a wide range of applications, including social networks, computer networks, transportation systems, and more.

---

### **Graph Terminology**

1. **Vertex (Node)**: A single point in the graph. It can represent an entity, such as a person, city, or computer.
2. **Edge (Arc)**: A connection between two vertices. It represents a relationship between two entities.
   - **Directed Edge**: An edge that has a direction, i.e., it goes from one vertex to another (e.g., A → B).
   - **Undirected Edge**: An edge that does not have a direction, i.e., it simply connects two vertices (e.g., A — B).
3. **Degree of a Vertex**: The number of edges connected to a vertex. In a directed graph, it is split into:
   - **In-degree**: The number of edges coming into the vertex.
   - **Out-degree**: The number of edges going out of the vertex.
4. **Path**: A sequence of edges that connect a sequence of vertices. A path can be directed or undirected, depending on the type of graph.
5. **Cycle**: A path that starts and ends at the same vertex, with no other vertex repeated.
6. **Adjacency**: Two vertices are adjacent if they are connected by an edge.

---

### **Types of Graphs**

1. **Undirected Graph**:
   - In an undirected graph, edges do not have a direction.
   - Example: A social network where a person is connected to others without specifying the direction of the relationship.

   ```
   A — B
   |    |
   C — D
   ```

2. **Directed Graph (Digraph)**:
   - In a directed graph, edges have a direction, i.e., an edge goes from one vertex to another.
   - Example: A website link structure, where a link from one page points to another.

   ```
   A → B
   ↑   ↓
   C ← D
   ```

3. **Weighted Graph**:
   - In a weighted graph, each edge has an associated weight (or cost).
   - Example: A transportation network where the edges represent roads, and the weights represent the distance or travel time between locations.

   ```
   A —(5)— B
   |         |
   (10)     (2)
   |         |
   C —(7)— D
   ```

4. **Unweighted Graph**:
   - An unweighted graph has edges without any associated weight or cost.

5. **Cyclic Graph**:
   - A graph that contains one or more cycles (paths that return to the starting point).
   
6. **Acyclic Graph**:
   - A graph that does not contain any cycles. A **Directed Acyclic Graph (DAG)** is a directed graph with no cycles, often used in scheduling tasks, workflows, etc.

7. **Connected Graph**:
   - A graph is connected if there is a path between every pair of vertices.
   
8. **Disconnected Graph**:
   - A graph is disconnected if there is at least one pair of vertices that do not have a path between them.

9. **Complete Graph**:
   - A graph is complete if there is an edge between every pair of vertices.

---

### **Graph Representation**

Graphs can be represented in multiple ways depending on the needs of the application. The two most common ways to represent a graph are **Adjacency Matrix** and **Adjacency List**.

---

#### 1. **Adjacency Matrix**
   - A 2D array used to represent a graph.
   - For a graph with **n** vertices, the adjacency matrix is a **n x n** matrix.
   - **Matrix[i][j] = 1** indicates an edge between vertex **i** and vertex **j**, while **Matrix[i][j] = 0** indicates no edge.
   - For a weighted graph, the matrix stores the weight of the edge instead of just 1 or 0.

   Example (Unweighted, Undirected Graph):

   ```
       A -- B
       |    |
       C -- D
   ```

   Adjacency Matrix:

   ```
       A   B   C   D
   A   0   1   1   0
   B   1   0   0   1
   C   1   0   0   1
   D   0   1   1   0
   ```

   Example (Weighted, Directed Graph):

   ```
       A → B (5)
       ↓
       C → D (2)
   ```

   Adjacency Matrix:

   ```
       A   B   C   D
   A   0   5   1   0
   B   0   0   0   0
   C   0   0   0   2
   D   0   0   0   0
   ```

#### 2. **Adjacency List**
   - A more space-efficient way of representing a graph, especially for sparse graphs.
   - Each vertex has a list of adjacent vertices (for undirected graphs, each edge is stored twice, once for each direction).
   - Each edge can also store additional information, such as a weight, in the list.

   Example (Unweighted, Undirected Graph):

   ```
       A -- B
       |    |
       C -- D
   ```

   Adjacency List:

   ```
   A: B, C
   B: A, D
   C: A, D
   D: B, C
   ```

   Example (Weighted, Directed Graph):

   ```
       A → B (5)
       ↓
       C → D (2)
   ```

   Adjacency List:

   ```
   A: (B, 5), (C, 1)
   B: 
   C: (D, 2)
   D: 
   ```

---

### **Graph Traversal Algorithms**

Graph traversal is the process of visiting all the vertices in a graph. There are two primary graph traversal algorithms:

1. **Depth-First Search (DFS)**:
   - DFS explores as far as possible along each branch before backtracking.
   - It uses a **stack** (or recursion) to visit vertices.
   - **Time Complexity**: O(V + E), where V is the number of vertices and E is the number of edges.
   
   **DFS Algorithm**:
   1. Start at the root node (or any arbitrary node).
   2. Visit the current node.
   3. Recursively visit all unvisited adjacent nodes.
   4. Backtrack when no unvisited adjacent nodes are left.

   **DFS Pseudocode**:

   ```
   DFS(Graph, vertex):
       mark vertex as visited
       for each adjacent vertex v of vertex:
           if v is not visited:
               DFS(Graph, v)
   ```

2. **Breadth-First Search (BFS)**:
   - BFS explores all the neighbors of a node before moving to the next level.
   - It uses a **queue** to manage the order of traversal.
   - **Time Complexity**: O(V + E), where V is the number of vertices and E is the number of edges.

   **BFS Algorithm**:
   1. Start at the root node (or any arbitrary node).
   2. Visit the current node and enqueue all its unvisited neighbors.
   3. Dequeue the next node from the queue and repeat the process.

   **BFS Pseudocode**:

   ```
   BFS(Graph, start_vertex):
       create a queue Q
       enqueue start_vertex into Q
       mark start_vertex as visited
       while Q is not empty:
           vertex = dequeue from Q
           visit vertex
           for each adjacent vertex v of vertex:
               if v is not visited:
                   enqueue v into Q
                   mark v as visited
   ```

---

### **Graph Algorithms**

1. **Dijkstra’s Algorithm (Shortest Path)**:
   - Used to find the shortest path between two vertices in a weighted graph.
   - **Time Complexity**: O(V²) for the naive approach or O(E + V log V) with a priority queue.

2. **Bellman-Ford Algorithm (Shortest Path)**:
   - A more general algorithm for finding the shortest path, even in graphs with negative weight edges.
   - **Time Complexity**: O(V * E).

3. **Floyd-Warshall Algorithm (All-Pairs Shortest Path)**:
   - A dynamic programming approach for finding the shortest paths between all pairs of vertices.
   - **Time Complexity**: O(V³).

4. **Kruskal’s Algorithm (Minimum Spanning Tree)**:
   - Used to find a minimum spanning tree for a graph, ensuring all vertices are connected with the minimum total edge weight.
   - **Time Complexity**: O(E log V).

5. **Prim’s Algorithm (Minimum Spanning Tree)**:
   - Similar to Kruskal’s algorithm, but it grows the minimum spanning tree starting from any arbitrary vertex.
   - **Time Complexity**: O(E + V log V).

---

### **Applications of Graphs**

1. **Social Networks**: Represent relationships between users, such as friendships or followers.
2. **Computer Networks**: Model the connections between computers and routers.
3. **Recommendation Systems**: Represent items and users, allowing

 algorithms to suggest items based on graph-based relationships.
4. **Route Finding**: Model transportation networks and find the shortest or fastest routes.
5. **Scheduling**: Directed acyclic graphs (DAGs) are used for task scheduling, such as in project management.

---

### **Conclusion**

Graphs are versatile data structures used to model complex relationships in real-world problems. Their flexibility allows them to represent a variety of different types of connections and relationships, and graph traversal and algorithms are essential tools for solving numerous computational problems.
