**Floyd-Warshall Algorithm: An Overview**

The Floyd-Warshall Algorithm is a widely used all-pairs shortest path algorithm that efficiently finds the shortest distances between all pairs of vertices in a weighted graph. Unlike Dijkstra's Algorithm and the Bellman-Ford Algorithm, which focus on finding the shortest path from a single source vertex to all other vertices, the Floyd-Warshall Algorithm considers all possible paths between pairs of vertices. It can handle graphs with both positive and negative edge weights, but it does not handle negative-weight cycles.

**Working of Floyd-Warshall Algorithm**

1. **Initialization**: The algorithm starts by initializing a distance matrix that stores the shortest distances between all pairs of vertices. Initially, the matrix is filled with the direct edge weights between the vertices, and for non-existing edges, the value is set to infinity (or a very large number). Also, the diagonal elements are set to zero, as the distance from a vertex to itself is zero.

2. **Dynamic Programming**: The algorithm uses dynamic programming to update the distance matrix. For each intermediate vertex k (i.e., a vertex that can be used as an intermediate stop between two other vertices), the algorithm checks whether the distance between the two vertices (i and j) can be reduced by including vertex k. If it is possible, the distance matrix is updated with the new shorter distance.

3. **Path Reconstruction (Optional)**: If required, the shortest paths can be reconstructed using an additional "predecessor" matrix, which keeps track of the intermediate vertices used to find the shortest path.

**Example Use Cases for Floyd-Warshall Algorithm**

1. **Network Routing**: The algorithm is commonly used in computer networks to find the shortest paths between all pairs of nodes in the network.

2. **Traffic Planning**: Floyd-Warshall can be used in urban planning and traffic management to find the optimal routes between various locations.

3. **Flight Scheduling**: In the aviation industry, the algorithm can be used to optimize flight schedules and connections between airports.

**Implementation of Floyd-Warshall Algorithm in Python, C++, Rust, and Ruby**

**Python Code for Floyd-Warshall Algorithm:**

```python
def floyd_warshall(graph):
    n = len(graph)

    # Initialize distance matrix
    distances = [row[:] for row in graph]

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if distances[i][j] > distances[i][k] + distances[k][j]:
                    distances[i][j] = distances[i][k] + distances[k][j]

    return distances

# Example usage:
inf = float('inf')
graph = [
    [0, inf, -2, inf],
    [4, 0, 3, inf],
    [inf, inf, 0, 2],
    [inf, -1, inf, 0]
]

all_pairs_shortest_distances = floyd_warshall(graph)
for row in all_pairs_shortest_distances:
    print(row)
```

**C++ Code for Floyd-Warshall Algorithm:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> floyd_warshall(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> distances(graph);

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (distances[i][j] > distances[i][k] + distances[k][j]) {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }

    return distances;
}

int main() {
    vector<vector<int>> graph = {
        {0, INT_MAX, -2, INT_MAX},
        {4, 0, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, 2},
        {INT_MAX, -1, INT_MAX, 0}
    };

    vector<vector<int>> all_pairs_shortest_distances = floyd_warshall(graph);
    for (const auto& row : all_pairs_shortest_distances) {
        for (int distance : row) {
            if (distance == INT_MAX) {
                cout << "INF ";
            } else {
                cout << distance << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
```

**Rust Code for Floyd-Warshall Algorithm:**

```rust
use std::i32;

fn floyd_warshall(graph: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let n = graph.len();
    let mut distances = graph.clone();

    for k in 0..n {
        for i in 0..n {
            for j in 0..n {
                if distances[i][j] > distances[i][k] + distances[k][j] {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }

    distances
}

fn main() {
    let graph = vec![
        vec![0, i32::MAX, -2, i32::MAX],
        vec![4, 0, 3, i32::MAX],
        vec![i32::MAX, i32::MAX, 0, 2],
        vec![i32::MAX, -1, i32::MAX, 0],
    ];

    let all_pairs_shortest_distances = floyd_warshall(&graph);
    for row in &all_pairs_shortest_distances {
        for distance in row {
            if *distance == i32::MAX {
                print!("INF ");
            } else {
                print!("{} ", distance);
            }
        }
        println!();
    }
}
```

**Ruby Code for Floyd-Warshall Algorithm:**

```ruby
def floyd_warshall(graph)
    n = graph.length

    # Initialize distance matrix
    distances = Array.new(n) { |i| Array.new(n, graph[i][i]) }

    for k in 0...n
        for i in 0...n
            for j in 0...n
                if distances[i][j] > distances[i][k] + distances[k][j]
                    distances[i][j] = distances[i][k] + distances[k][j]
                end
            end
        end
    end

    distances
end

# Example usage:
inf = Float::INFINITY
graph = [
    [0, inf, -2, inf],
    [4, 0, 3, inf],
    [inf, inf, 0, 2],
    [inf, -1, inf, 0]
]

all_pairs_shortest_distances = floyd_warshall(graph)
all_pairs_shortest_distances.each do |row|
    puts row.map { |distance| distance == inf ? 'INF' : distance }.join(' ')
end
```

**Conclusion**

The Floyd-Warshall Algorithm is an efficient and versatile algorithm that can find the shortest distances between all pairs of vertices in a weighted graph. Its ability to handle graphs with both positive and negative edge weights makes it suitable for various real-world applications, such as network routing, traffic planning, and flight scheduling. The provided code examples

 in Python, C++, Rust, and Ruby demonstrate the implementation of the Floyd-Warshall Algorithm, enabling you to efficiently find all-pairs shortest distances and optimize your graph-based projects and optimization tasks.
