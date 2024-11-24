### **Kruskal’s Algorithm for Minimum Spanning Tree (MST)**

**Kruskal's Algorithm** is another greedy algorithm used to find the **Minimum Spanning Tree (MST)** of a connected, undirected graph. Unlike **Prim's algorithm**, which grows the MST by starting with an arbitrary vertex and adding edges, **Kruskal's algorithm** works by sorting all edges of the graph by weight and then adding edges one by one, ensuring that no cycle is formed. 

Kruskal’s algorithm is well-suited for sparse graphs with fewer edges, and it works efficiently when using a **disjoint-set** (also known as a **union-find**) data structure to detect cycles.

### **Problem Statement:**
Given a connected, undirected graph with weighted edges, find the **minimum spanning tree** (MST) that connects all vertices with the minimum total edge weight.

### **Key Concepts:**
1. **Spanning Tree**: A tree that connects all the vertices of the graph without cycles.
2. **Minimum Spanning Tree (MST)**: A spanning tree that has the minimum sum of edge weights among all possible spanning trees of the graph.
3. **Disjoint Set / Union-Find**: A data structure used to manage the disjoint sets of vertices and helps to check whether adding an edge creates a cycle.

### **Steps of Kruskal’s Algorithm:**
1. **Sort all edges** in the graph by their weights in non-decreasing order.
2. **Initialize the MST** as an empty set of edges.
3. **Iterate over the sorted edges** and for each edge:
   - If adding the edge does **not create a cycle** (i.e., the two vertices of the edge belong to different sets), include the edge in the MST.
   - If adding the edge **creates a cycle**, discard it.
4. **Repeat the process** until the MST contains exactly **V - 1 edges**, where **V** is the number of vertices in the graph.

### **Pseudocode for Kruskal's Algorithm:**

```python
class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])
        return self.parent[u]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        
        if root_u != root_v:
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1

def kruskal(graph, V):
    # graph is a list of edges in the form (weight, u, v)
    # V is the number of vertices
    mst_edges = []
    total_weight = 0

    # Step 1: Sort edges by weight
    graph.sort(key=lambda x: x[0])  # Sorting based on edge weight

    # Step 2: Initialize Disjoint Set (Union-Find)
    disjoint_set = DisjointSet(V)

    # Step 3: Process edges in sorted order
    for weight, u, v in graph:
        # Step 3a: Check if adding this edge creates a cycle
        if disjoint_set.find(u) != disjoint_set.find(v):
            # Step 3b: If no cycle, add this edge to the MST
            disjoint_set.union(u, v)
            mst_edges.append((u, v, weight))
            total_weight += weight
    
    return mst_edges, total_weight
```

### **Explanation of the Pseudocode:**

1. **DisjointSet Class**: The **DisjointSet** class implements the **Union-Find** data structure to manage disjoint sets. It supports:
   - **Find(u)**: Finds the representative (or root) of the set containing vertex `u`.
   - **Union(u, v)**: Merges the sets containing `u` and `v` if they are different.

2. **Kruskal's Algorithm**:
   - Sort all edges of the graph in non-decreasing order of their weights.
   - Use a **DisjointSet** to track the connected components of the graph.
   - For each edge, check whether it forms a cycle by comparing the sets of the two vertices. If they are in the same set, ignore the edge. If they are in different sets, add the edge to the MST and unite the sets.
   - Repeat this process until **V-1 edges** are included in the MST.

### **Example of Kruskal’s Algorithm:**

Consider the following weighted graph:

```
         1      4
    A ----------- B
     |           |
     |  3        | 2
     |           |
    D ----------- C
         5
```

#### Adjacency List Representation of Edges:
```python
edges = [
    (1, 'A', 'B'),
    (3, 'A', 'D'),
    (2, 'B', 'C'),
    (5, 'C', 'D'),
    (4, 'B', 'D')
]
```

#### Step-by-Step Execution of Kruskal's Algorithm:

1. **Sort edges by weight**:
   ```
   (1, 'A', 'B'), (2, 'B', 'C'), (3, 'A', 'D'), (4, 'B', 'D'), (5, 'C', 'D')
   ```

2. **Initialize the Disjoint Set**:
   Initially, all vertices are in separate sets:
   - `A`: {A}, `B`: {B}, `C`: {C}, `D`: {D}

3. **Process edges**:
   - First edge: `(1, 'A', 'B')`:
     - `A` and `B` are in different sets, so add this edge to the MST.
     - Union the sets of `A` and `B`.
     - Current MST: `[(A, B, 1)]`, Total weight: `1`

   - Second edge: `(2, 'B', 'C')`:
     - `B` and `C` are in different sets, so add this edge to the MST.
     - Union the sets of `B` and `C`.
     - Current MST: `[(A, B, 1), (B, C, 2)]`, Total weight: `3`

   - Third edge: `(3, 'A', 'D')`:
     - `A` and `D` are in different sets, so add this edge to the MST.
     - Union the sets of `A` and `D`.
     - Current MST: `[(A, B, 1), (B, C, 2), (A, D, 3)]`, Total weight: `6`

   - Fourth edge: `(4, 'B', 'D')`:
     - `B` and `D` are already in the same set (they are connected through `A` and `C`), so discard this edge.

   - Fifth edge: `(5, 'C', 'D')`:
     - `C` and `D` are already in the same set, so discard this edge.

4. **Final MST**:
   The final MST contains the edges:
   - `(A, B)` with weight `1`
   - `(B, C)` with weight `2`
   - `(A, D)` with weight `3`

   The total weight of the MST is `1 + 2 + 3 = 6`.

### **Time Complexity of Kruskal’s Algorithm:**

1. **Sorting edges**: Sorting the edges takes **O(E log E)**, where **E** is the number of edges.
2. **Union-Find Operations**: Each **find** and **union** operation takes nearly constant time, **O(α(V))**, where **α** is the inverse Ackermann function and **V** is the number of vertices. This is very efficient for practical inputs.
3. **Total Time Complexity**: The overall time complexity is **O(E log E)**, which is dominated by the sorting step.

### **Advantages of Kruskal’s Algorithm**:
1. **Simple to implement**: Kruskal’s algorithm is conceptually simpler than Prim's algorithm.
2. **Efficient for sparse graphs**: It works well with sparse graphs where **E << V²** (much fewer edges than vertices).
3. **Does not require a starting vertex**: Unlike Prim's algorithm, Kruskal’s algorithm doesn’t need a starting vertex.

### **Disadvantages of Kruskal’s Algorithm**:
1. **Requires sorting**: Sorting all the edges can be slow for graphs with a large number of edges.
2. **Efficiency depends on sorting**: For very dense graphs, Kruskal’s algorithm may not be as efficient as Prim’s algorithm.

### **Conclusion**:
Kruskal’s algorithm is an efficient greedy algorithm for finding the Minimum Spanning Tree of a graph, especially for sparse graphs. It sorts the edges and adds the smallest edges to the MST, avoiding cycles using the Union-Find data structure. It is widely used in network design and other applications where the MST is crucial.
