**Depth-First Search (DFS) Algorithm: An Overview**

Depth-First Search (DFS) is a popular graph traversal algorithm used to explore and visit all the vertices of a graph in a systematic manner. It starts at a source node and explores as far as possible along each branch before backtracking. This algorithm employs a stack to keep track of visited nodes and the nodes that are yet to be explored. DFS is commonly used for tasks like pathfinding, cycle detection, and connected component analysis in graphs.

**Working of Depth-First Search Algorithm**

1. **Initialization**: Choose a starting node as the source and mark it as visited. Push the source node onto the stack.

2. **Exploration**: While the stack is not empty, perform the following steps:
   a. Pop the top node from the stack.
   b. Visit the node and process it as needed (e.g., record the path or check for specific conditions).
   c. Explore all the unvisited neighbors (adjacent nodes) of the current node.
   d. Mark each visited neighbor and push them onto the stack.

3. **Backtracking**: If the current node has no unvisited neighbors or after exploring all neighbors, backtrack by popping the previous node from the stack.

4. **Repeat**: Continue the process until the stack is empty, which indicates that all reachable nodes have been visited.

**Example Use Cases for Depth-First Search Algorithm**

1. **Pathfinding**: DFS can be used to find a path between two nodes in a graph.

2. **Connected Components**: DFS helps identify connected components in an undirected graph.

3. **Cycle Detection**: It can be used to detect cycles in directed graphs.

**Implementation of Depth-First Search in Python, C++, Rust, and Ruby**

**Python Code for Depth-First Search:**

```python
def dfs(graph, start):
    stack = [start]
    visited = set()

    while stack:
        node = stack.pop()
        if node not in visited:
            visited.add(node)
            print(node)  # Process the node as needed

            # Explore the unvisited neighbors
            for neighbor in graph[node]:
                if neighbor not in visited:
                    stack.append(neighbor)

# Example usage:
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F', 'G'],
    'D': ['B'],
    'E': ['B'],
    'F': ['C'],
    'G': ['C']
}
dfs(graph, 'A')
```

**C++ Code for Depth-First Search:**

```cpp
#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
using namespace std;

void dfs(vector<vector<int>>& graph, int start) {
    stack<int> st;
    unordered_set<int> visited;

    st.push(start);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            cout << node << " ";  // Process the node as needed

            // Explore the unvisited neighbors
            for (int neighbor : graph[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    st.push(neighbor);
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},     // Node 0 (A)
        {0, 3, 4},  // Node 1 (B)
        {0, 5, 6},  // Node 2 (C)
        {1},        // Node 3 (D)
        {1},        // Node 4 (E)
        {2},        // Node 5 (F)
        {2}         // Node 6 (G)
    };
    dfs(graph, 0); // Starting from Node 0 (A)

    return 0;
}
```

**Rust Code for Depth-First Search:**

```rust
use std::collections::{HashSet, VecDeque};

fn dfs(graph: &Vec<Vec<usize>>, start: usize) {
    let mut stack = VecDeque::new();
    let mut visited = HashSet::new();

    stack.push_front(start);

    while let Some(node) = stack.pop_front() {
        if !visited.contains(&node) {
            visited.insert(node);
            print!("{} ", node); // Process the node as needed

            // Explore the unvisited neighbors
            for &neighbor in &graph[node] {
                if !visited.contains(&neighbor) {
                    stack.push_front(neighbor);
                }
            }
        }
    }
}

fn main() {
    let graph = vec![
        vec![1, 2],     // Node 0 (A)
        vec![0, 3, 4],  // Node 1 (B)
        vec![0, 5, 6],  // Node 2 (C)
        vec![1],        // Node 3 (D)
        vec![1],        // Node 4 (E)
        vec![2],        // Node 5 (F)
        vec![2],        // Node 6 (G)
    ];
    dfs(&graph, 0); // Starting from Node 0 (A)
}
```

**Ruby Code for Depth-First Search:**

```ruby
def dfs(graph, start)
    stack = [start]
    visited = Set.new

    while !stack.empty?
        node = stack.pop

        unless visited.include?(node)
            visited.add(node)
            print "#{node} " # Process the node as needed

            # Explore the unvisited neighbors
            graph[node].each do |neighbor|
                unless visited.include?(neighbor)
                    stack.push(neighbor)
                end
            end
        end
    end
end

# Example usage:
graph = {
    0 => [1, 2],     # Node 0 (A)
    1 => [0, 3, 4],  # Node 1 (B)
    2 => [0, 5, 6],  # Node 2 (C)
    3 => [1],        # Node 3 (D)
    4 => [1],        # Node 4 (E)
    5 => [2],        # Node 5 (F)
    6 => [2],        # Node 6 (G)
}
dfs(graph, 0) # Starting from Node 0 (A)
```

**Conclusion**

Depth-First Search (DFS) is a fundamental graph traversal algorithm that efficiently explores and visits all the vertices of a graph. By using a stack to manage the order of exploration, DFS can provide valuable insights into a graph's structure and connectivity. It is widely used for pathfinding, cycle detection, and connected component analysis in various applications. The provided code examples in Python, C++, Rust, and Ruby showcase the implementation of DFS, allowing you to apply the algorithm in your projects as needed.
