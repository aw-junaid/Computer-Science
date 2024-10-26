**Bellman-Ford Algorithm: An Overview**

The Bellman-Ford Algorithm is a popular single-source shortest path algorithm that can handle graphs with both positive and negative edge weights, making it more versatile than Dijkstra's Algorithm. It is used to find the shortest path from a single source vertex to all other vertices in a weighted graph. The algorithm is also capable of detecting negative-weight cycles in the graph, which makes it suitable for applications where negative cycles need to be identified.

**Working of Bellman-Ford Algorithm**

1. **Initialization**: The algorithm starts by initializing the distance to the source vertex as 0 and the distance to all other vertices as infinity (or a very large number). It also keeps track of the predecessor of each vertex on the shortest path.

2. **Relaxation Step**: The algorithm then performs a relaxation step for each edge in the graph. The relaxation step means updating the distance of each adjacent vertex if a shorter path is found from the source vertex through the current vertex.

3. **Repeat Relaxation**: The relaxation step is repeated (V-1) times, where V is the number of vertices in the graph. This ensures that the shortest distances are correctly calculated, even in the presence of negative edge weights.

4. **Detecting Negative Cycles**: After (V-1) relaxation steps, the algorithm checks for negative-weight cycles. It performs one more relaxation step, and if any distance changes occur, it indicates the presence of a negative-weight cycle in the graph.

**Example Use Cases for Bellman-Ford Algorithm**

1. **Routing in Computer Networks**: The Bellman-Ford Algorithm is used in routing protocols to find the shortest path for data packets to reach their destination in computer networks.

2. **Financial Applications**: In financial applications, the algorithm can be used to calculate the most profitable path considering both positive and negative costs.

3. **Game Development**: The algorithm can be used in game development to find optimal paths for characters or agents to reach their targets.

**Implementation of Bellman-Ford Algorithm in Python, C++, Rust, and Ruby**

**Python Code for Bellman-Ford Algorithm:**

```python
def bellman_ford(graph, source):
    n = len(graph)
    distances = [float('inf')] * n
    distances[source] = 0
    predecessors = [None] * n

    for _ in range(n - 1):
        for u in range(n):
            for v in range(n):
                weight = graph[u][v]
                if weight != 0 and distances[u] + weight < distances[v]:
                    distances[v] = distances[u] + weight
                    predecessors[v] = u

    # Check for negative cycles
    for u in range(n):
        for v in range(n):
            weight = graph[u][v]
            if weight != 0 and distances[u] + weight < distances[v]:
                raise ValueError("Negative-weight cycle detected")

    return distances, predecessors

# Example usage:
graph = [
    [0, 4, 0, 0, 0],
    [0, 0, 1, 5, 0],
    [0, 0, 0, 0, 3],
    [0, 0, 0, 0, 0],
    [0, 0, 0, -4, 0]
]

source_vertex = 0
shortest_distances, predecessors = bellman_ford(graph, source_vertex)
print(shortest_distances)
print(predecessors)
```

**C++ Code for Bellman-Ford Algorithm:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> bellman_ford(vector<vector<int>>& graph, int source) {
    int n = graph.size();
    vector<int> distances(n, INT_MAX);
    distances[source] = 0;
    vector<int> predecessors(n, -1);

    for (int i = 1; i < n; i++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                int weight = graph[u][v];
                if (weight != 0 && distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                    predecessors[v] = u;
                }
            }
        }
    }

    // Check for negative cycles
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            int weight = graph[u][v];
            if (weight != 0 && distances[u] + weight < distances[v]) {
                throw runtime_error("Negative-weight cycle detected");
            }
        }
    }

    return distances;
}

int main() {
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0},
        {0, 0, 1, 5, 0},
        {0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0},
        {0, 0, 0, -4, 0}
    };

    int source_vertex = 0;
    vector<int> shortest_distances = bellman_ford(graph, source_vertex);
    for (int distance : shortest_distances) {
        cout << distance << " ";
    }

    return 0;
}
```

**Rust Code for Bellman-Ford Algorithm:**

```rust
use std::i32;

fn bellman_ford(graph: &Vec<Vec<i32>>, source: usize) -> Result<(Vec<i32>, Vec<Option<usize>>), &'static str> {
    let n = graph.len();
    let mut distances = vec![i32::MAX; n];
    let mut predecessors = vec![None; n];
    distances[source] = 0;

    for _ in 0..n - 1 {
        for u in 0..n {
            for v in 0..n {
                let weight = graph[u][v];
                if weight != 0 && distances[u] + weight < distances[v] {
                    distances[v] = distances[u] + weight;
                    predecessors[v] = Some(u);
                }
            }
        }
    }

    // Check for negative cycles
    for u in 0..n {
        for v in 0..n {
            let weight = graph[u][v];
            if weight != 0 && distances[u] + weight < distances[v] {
                return Err("Negative-weight cycle detected");
            }
        }
    }

    Ok((distances, predecessors))
}

fn main() {
    let graph = vec![
        vec![0, 4, 0, 0, 0],
        vec![0, 0, 1, 5, 0],
        vec![0, 0, 0, 0, 3],
        vec![0, 0, 0, 0, 0],
        vec![0, 0, 0, -4, 0],
    ];

    let source_vertex = 0;
    match bellman_ford(&graph, source_vertex) {


        Ok((shortest_distances, predecessors)) => {
            for distance in shortest_distances {
                print!("{} ", distance);
            }
            println!();
            for predecessor in predecessors {
                if let Some(p) = predecessor {
                    print!("{} ", p);
                } else {
                    print!("None ");
                }
            }
        }
        Err(err) => println!("{}", err),
    }
}
```

**Ruby Code for Bellman-Ford Algorithm:**

```ruby
def bellman_ford(graph, source)
    n = graph.length
    distances = Array.new(n, Float::INFINITY)
    distances[source] = 0
    predecessors = Array.new(n)

    for i in 1..n - 1
        for u in 0..n - 1
            for v in 0..n - 1
                weight = graph[u][v]
                if weight != 0 && distances[u] + weight < distances[v]
                    distances[v] = distances[u] + weight
                    predecessors[v] = u
                end
            end
        end
    end

    # Check for negative cycles
    for u in 0..n - 1
        for v in 0..n - 1
            weight = graph[u][v]
            if weight != 0 && distances[u] + weight < distances[v]
                raise "Negative-weight cycle detected"
            end
        end
    end

    return distances, predecessors
end

# Example usage:
graph = [
    [0, 4, 0, 0, 0],
    [0, 0, 1, 5, 0],
    [0, 0, 0, 0, 3],
    [0, 0, 0, 0, 0],
    [0, 0, 0, -4, 0]
]

source_vertex = 0
shortest_distances, predecessors = bellman_ford(graph, source_vertex)
puts shortest_distances.join(' ')
puts predecessors.join(' ')
```

**Conclusion**

The Bellman-Ford Algorithm is a versatile and powerful algorithm used to find the shortest path from a single source vertex to all other vertices in a weighted graph with both positive and negative edge weights. Its ability to handle negative-weight cycles makes it suitable for various real-world applications, such as network routing, financial planning, and game development. The provided code examples in Python, C++, Rust, and Ruby demonstrate the implementation of the Bellman-Ford Algorithm, allowing you to efficiently find shortest paths and identify negative cycles in your graph-based projects and optimization tasks.
