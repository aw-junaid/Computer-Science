**Topological Sort Algorithm: An Overview**

Topological sorting is a well-known algorithm used to find a linear ordering of vertices in a directed acyclic graph (DAG). In a topological sort, for every directed edge (u, v), vertex u comes before vertex v in the ordering. This linear ordering is valuable in various scenarios, especially when dealing with dependencies or precedence relationships between tasks or events.

**Working of Topological Sort Algorithm**

1. **Step 1: Identify Sources**: The algorithm starts by identifying vertices with no incoming edges (sources) and adds them to a queue or stack. These vertices have no dependencies and can be placed at the beginning of the topological ordering.

2. **Step 2: Process Sources**: While there are vertices in the queue (or stack), the algorithm dequeues (or pops) a vertex and adds it to the topological ordering. Then, for each of its outgoing edges (v, where v is the destination), the algorithm decrements the incoming edge count of vertex v. If the incoming edge count of vertex v becomes zero after decrementing, it means that all its dependencies have been processed, and v can now be added to the queue (or stack) of sources.

3. **Step 3: Repeat**: The algorithm repeats Step 2 until all vertices have been processed. If the graph contains a cycle (i.e., it is not a DAG), it will not be possible to find a topological ordering, as there will be vertices with non-zero incoming edge counts that cannot be processed.

**Example Use Cases for Topological Sort Algorithm**

1. **Task Scheduling**: In project management or task scheduling, topological sort can be used to determine the order in which tasks should be executed based on their dependencies.

2. **Course Prerequisites**: In academic course planning, topological sort can help determine the correct sequence of courses, ensuring that prerequisites are fulfilled before enrolling in advanced courses.

3. **Package Dependencies**: In package management systems, topological sort can be used to resolve package dependencies, ensuring that packages are installed in the correct order.

**Implementation of Topological Sort Algorithm in Python, C++, Rust, and Ruby**

**Python Code for Topological Sort Algorithm:**

```python
from collections import defaultdict

def topological_sort(graph):
    n = len(graph)
    indegree = [0] * n
    sources = []

    for u in graph:
        for v in graph[u]:
            indegree[v] += 1

    for u in range(n):
        if indegree[u] == 0:
            sources.append(u)

    topological_ordering = []
    while sources:
        u = sources.pop(0)
        topological_ordering.append(u)

        for v in graph[u]:
            indegree[v] -= 1
            if indegree[v] == 0:
                sources.append(v)

    if len(topological_ordering) != n:
        raise ValueError("The graph contains a cycle (not a DAG)")

    return topological_ordering

# Example usage:
graph = {
    0: [1, 2],
    1: [3],
    2: [3],
    3: []
}

topological_order = topological_sort(graph)
print(topological_order)
```

**C++ Code for Topological Sort Algorithm:**

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topological_sort(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> indegree(n, 0);
    queue<int> sources;

    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            indegree[v]++;
        }
    }

    for (int u = 0; u < n; u++) {
        if (indegree[u] == 0) {
            sources.push(u);
        }
    }

    vector<int> topological_ordering;
    while (!sources.empty()) {
        int u = sources.front();
        sources.pop();
        topological_ordering.push_back(u);

        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                sources.push(v);
            }
        }
    }

    if (topological_ordering.size() != n) {
        throw runtime_error("The graph contains a cycle (not a DAG)");
    }

    return topological_ordering;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {3},
        {3},
        {},
    };

    vector<int> topological_order = topological_sort(graph);
    for (int vertex : topological_order) {
        cout << vertex << " ";
    }

    return 0;
}
```

**Rust Code for Topological Sort Algorithm:**

```rust
use std::collections::{HashMap, VecDeque};

fn topological_sort(graph: HashMap<usize, Vec<usize>>) -> Result<Vec<usize>, &'static str> {
    let n = graph.len();
    let mut indegree = vec![0; n];
    let mut sources = VecDeque::new();

    for edges in graph.values() {
        for &v in edges {
            indegree[v] += 1;
        }
    }

    for (u, &indeg) in indegree.iter().enumerate() {
        if indeg == 0 {
            sources.push_back(u);
        }
    }

    let mut topological_ordering = Vec::with_capacity(n);
    while let Some(u) = sources.pop_front() {
        topological_ordering.push(u);

        if let Some(edges) = graph.get(&u) {
            for &v in edges {
                indegree[v] -= 1;
                if indegree[v] == 0 {
                    sources.push_back(v);
                }
            }
        }
    }

    if topological_ordering.len() != n {
        return Err("The graph contains a cycle (not a DAG)");
    }

    Ok(topological_ordering)
}

fn main() {
    let mut graph = HashMap::new();
    graph.insert(0, vec![1, 2]);
    graph.insert(1, vec![3]);
    graph.insert(2, vec![3]);
    graph.insert(3, vec![]);

    match topological_sort(graph) {
        Ok(topological_ordering) => {
            for vertex in &topological_ordering {
                print!("{} ", vertex);
            }
        }
        Err(err) => println!("{}", err),
    }
}
```

**Ruby Code for Topological Sort Algorithm:**

```ruby
def topological_sort(graph)
    n = graph.length
    indegree = Array.new(n, 0)
    sources = []

    graph.each do |edges|
        edges.each do |v|
            indegree[v] += 1
        end
    end

    indegree.each_with_index do |indeg, u|
        sources << u if indeg == 0
    end

    topological_ordering = []
    while !sources.empty?
        u = sources.shift
        topological_ordering << u

        if graph[u]
            graph[u].each do |v|
                indegree[v] -= 1
                sources << v if indegree[v] == 0
            end
        end
    end

   

 if topological_ordering.length != n
        raise "The graph contains a cycle (not a DAG)"
    end

    topological_ordering
end

# Example usage:
graph = [
    [1, 2],
    [3],
    [3],
    []
]

topological_order = topological_sort(graph)
puts topological_order.join(' ')
```

**Conclusion**

The Topological Sort Algorithm is a powerful and efficient algorithm used to find a linear ordering of vertices in a directed acyclic graph (DAG). Its ability to handle task dependencies, course prerequisites, and package dependencies makes it an essential tool in project management, academic planning, and package management systems. The provided code examples in Python, C++, Rust, and Ruby demonstrate the implementation of the Topological Sort Algorithm, allowing you to efficiently find the linear ordering of vertices in your graph-based projects and optimization tasks.
