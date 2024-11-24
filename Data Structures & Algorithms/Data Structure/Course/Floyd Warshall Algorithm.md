### **Floyd-Warshall Algorithm**

The **Floyd-Warshall algorithm** is a classic algorithm for finding the shortest paths between all pairs of vertices in a weighted graph. It is a dynamic programming algorithm that works for both directed and undirected graphs, and it can handle graphs with positive or negative edge weights (but no negative weight cycles).

### **Problem Definition:**
Given a weighted graph \( G = (V, E) \) where \( V \) is the set of vertices and \( E \) is the set of edges, the task of the Floyd-Warshall algorithm is to find the shortest paths between every pair of vertices.

### **Key Concepts:**
- **Shortest Path**: A shortest path between two vertices is the path that minimizes the sum of the edge weights.
- **Weighted Graph**: A graph where each edge has a weight (or cost) associated with it, which may be positive or negative.
- **Adjacency Matrix Representation**: The graph is usually represented using an adjacency matrix where each element $\( \text{dist}[i][j] \)$ represents the weight of the edge between vertices \( i \) and \( j \), or $\( \infty \)$ if no edge exists between them.

### **Algorithm Overview:**

The Floyd-Warshall algorithm is based on the idea of **dynamic programming**, where we gradually improve our knowledge of the shortest paths between pairs of vertices. The algorithm uses three nested loops to update the shortest paths. The main idea is that for each pair of vertices $\( (i, j) \)$, we check if a shorter path exists by going through an intermediate vertex \( k \).

- **Initialization**: Start with a distance matrix initialized to the edge weights. If there is no edge between two vertices, initialize the distance as infinity.

- **Relaxation**: The algorithm tries to relax the distances by considering all vertices as intermediate vertices. For each pair of vertices \( (i, j) \), it checks if the path through vertex \( k \) provides a shorter path than the direct edge between \( i \) and \( j \).

### **Steps in the Algorithm**:

1. **Initialize**: Set the distance from each vertex to itself as 0 and the distance between vertices \( i \) and \( j \) as the weight of the edge between them. If there is no edge, set the distance to infinity.
   
   $\( \text{dist}[i][j] = \infty \)$ if there is no edge, otherwise $\( \text{dist}[i][j] = \text{weight of the edge between i and j} \)$.

2. **Iterative Update**: For each possible intermediate vertex \( k \), and for each pair of vertices \( (i, j) \), update the distance as follows:
   $\[
   \text{dist}[i][j] = \min(\text{dist}[i][j], \text{dist}[i][k] + \text{dist}[k][j])
   \]$
   This formula checks if the shortest path from vertex \( i \) to vertex \( j \) can be improved by passing through vertex \( k \).

3. **Repeat**: The algorithm repeats the above update for all possible intermediate vertices \( k \) in the graph.

4. **Final Distance Matrix**: After the algorithm completes, the matrix $\( \text{dist}[i][j] \)$ will contain the shortest distance from vertex \( i \) to vertex \( j \) for all pairs of vertices.

### **Floyd-Warshall Algorithm Pseudocode**:

```python
def floyd_warshall(graph):
    n = len(graph)  # Number of vertices
    dist = [row[:] for row in graph]  # Initialize distance matrix

    # Main loop for all pairs (i, j) considering each vertex k as intermediate
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

    return dist
```

### **Explanation of Pseudocode**:
1. **Initialization**: Create a copy of the input graph as the initial distance matrix \( \text{dist} \).
2. **Triple Nested Loops**:
   - The outer loop iterates over all possible intermediate vertices \( k \).
   - The middle loop iterates over all starting vertices \( i \).
   - The inner loop iterates over all destination vertices \( j \), checking if a shorter path from \( i \) to \( j \) exists through the intermediate vertex \( k \).
3. **Final Matrix**: The matrix $\( dist[i][j] \)$ will contain the shortest path from vertex \( i \) to vertex \( j \) after all iterations.

### **Time Complexity**:

- The algorithm uses three nested loops, each iterating over \( n \) vertices (where \( n \) is the number of vertices in the graph). Therefore, the time complexity is:
  $\[
  O(n^3)
  \]$
  where \( n \) is the number of vertices.

### **Space Complexity**:

- The space complexity is $\( O(n^2) \)$ because we need to store the distance matrix for all pairs of vertices.

### **Example:**

Let’s consider a graph with 4 vertices and the following adjacency matrix (where \( \infty \) represents no direct edge):

|         | 0   | 1   | 2   | 3   |
|---------|-----|-----|-----|-----|
| **0**   | 0   | 5   | ∞   | 10  |
| **1**   | ∞   | 0   | 3   | ∞   |
| **2**   | ∞   | ∞   | 0   | 1   |
| **3**   | ∞   | ∞   | ∞   | 0   |

Now we run the Floyd-Warshall algorithm:

1. Initialize the distance matrix as the input adjacency matrix.
2. Iteratively update the matrix by considering each vertex as an intermediate vertex.

After applying the Floyd-Warshall algorithm, the final distance matrix will be:

|         | 0   | 1   | 2   | 3   |
|---------|-----|-----|-----|-----|
| **0**   | 0   | 5   | 8   | 9   |
| **1**   | 7   | 0   | 3   | 4   |
| **2**   | 4   | 9   | 0   | 1   |
| **3**   | 5   | 10  | 13  | 0   |

### **Key Points to Note**:
- **Negative Weight Edges**: The Floyd-Warshall algorithm can handle negative weight edges, but it cannot handle negative weight cycles (i.e., cycles where the total sum of edge weights is negative). If there is a negative weight cycle, it will be detected by checking if any distance $\( \text{dist}[i][i] \)$ becomes negative after applying the algorithm.
- **All-Pairs Shortest Path**: This algorithm computes the shortest path between all pairs of vertices, which makes it different from Dijkstra's algorithm (which finds the shortest path from a single source vertex to all other vertices).
- **Applications**:
  - **Network Routing**: Determining the shortest path between all pairs of nodes in a communication network.
  - **Transitive Closure**: Used in graph theory to find if there is a path between any two vertices.
  - **Optimization Problems**: Used in problems involving multi-source, multi-destination shortest path problems.

### **Conclusion**:
The Floyd-Warshall algorithm is a simple and efficient dynamic programming solution for finding the shortest paths between all pairs of vertices in a weighted graph. It works well for dense graphs and graphs with negative weights but cannot handle negative weight cycles. The time complexity of $\( O(n^3) \)$ makes it less suitable for large graphs but highly efficient for smaller graphs or situations where multiple shortest path queries are needed.
