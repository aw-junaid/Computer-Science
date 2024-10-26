**Dijkstra's Algorithm: An Overview**

Dijkstra's Algorithm is a famous and efficient algorithm used to find the shortest path from a single source vertex to all other vertices in a weighted graph with non-negative edge weights. It is widely used in navigation systems, network routing protocols, and various optimization problems where finding the shortest path is essential. Dijkstra's Algorithm is a greedy algorithm that explores the graph in a systematic manner, ensuring that the shortest distances to all vertices are obtained in a step-by-step fashion. It has a time complexity of O(V^2) for a graph represented using an adjacency matrix and O(E + V log V) for a graph represented using an adjacency list, where V is the number of vertices and E is the number of edges.

**Working of Dijkstra's Algorithm**

1. **Initialization**: The algorithm starts by initializing the distance to the source vertex as 0 and the distance to all other vertices as infinity (or a very large number). It also maintains a priority queue (min-heap) to keep track of the unprocessed vertices and their tentative distances.

2. **Explore Neighbors**: The algorithm repeatedly extracts the vertex with the smallest tentative distance from the priority queue and explores its neighbors. For each unprocessed neighbor, it calculates the tentative distance from the source vertex to that neighbor through the current vertex. If this tentative distance is smaller than the previously recorded distance, it updates the distance and adds the neighbor to the priority queue.

3. **Shortest Path Tree**: The algorithm continues this process until all vertices have been processed, and the shortest distances to all vertices from the source vertex have been obtained. It also builds a Shortest Path Tree, which is a subgraph containing the shortest paths from the source vertex to all other vertices.

**Example Use Cases for Dijkstra's Algorithm**

1. **Navigation Systems**: Dijkstra's Algorithm is commonly used in GPS navigation systems to find the shortest route between two locations.

2. **Network Routing**: It is used in computer networks to find the shortest path for data packets to reach their destination.

3. **Transportation Planning**: Dijkstra's Algorithm can be applied in transportation planning to optimize routes and minimize travel time.

**Implementation of Dijkstra's Algorithm in Python, C++, Rust, and Ruby**

**Python Code for Dijkstra's Algorithm:**

```python
import heapq

def dijkstra(graph, source):
    n = len(graph)
    distances = [float('inf')] * n
    distances[source] = 0

    priority_queue = [(0, source)]

    while priority_queue:
        dist_u, u = heapq.heappop(priority_queue)

        if dist_u > distances[u]:
            continue

        for v, weight in enumerate(graph[u]):
            new_distance = distances[u] + weight

            if new_distance < distances[v]:
                distances[v] = new_distance
                heapq.heappush(priority_queue, (new_distance, v))

    return distances

# Example usage:
graph = [
    [0, 4, 2, 0, 0],
    [4, 0, 1, 5, 0],
    [2, 1, 0, 8, 10],
    [0, 5, 8, 0, 2],
    [0, 0, 10, 2, 0]
]

source_vertex = 0
shortest_distances = dijkstra(graph, source_vertex)
print(shortest_distances)
```

**C++ Code for Dijkstra's Algorithm:**

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dijkstra(vector<vector<int>>& graph, int source) {
    int n = graph.size();
    vector<int> distances(n, INT_MAX);
    distances[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int dist_u = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist_u > distances[u]) {
            continue;
        }

        for (int v = 0; v < n; v++) {
            int new_distance = distances[u] + graph[u][v];

            if (new_distance < distances[v]) {
                distances[v] = new_distance;
                pq.push({new_distance, v});
            }
        }
    }

    return distances;
}

int main() {
    vector<vector<int>> graph = {
        {0, 4, 2, 0, 0},
        {4, 0, 1, 5, 0},
        {2, 1, 0, 8, 10},
        {0, 5, 8, 0, 2},
        {0, 0, 10, 2, 0}
    };

    int source_vertex = 0;
    vector<int> shortest_distances = dijkstra(graph, source_vertex);

    for (int distance : shortest_distances) {
        cout << distance << " ";
    }

    return 0;
}
```

**Rust Code for Dijkstra's Algorithm:**

```rust
use std::collections::BinaryHeap;
use std::cmp::Ordering;

#[derive(Debug, Eq, PartialEq)]
struct State {
    cost: i32,
    vertex: usize,
}

impl Ord for State {
    fn cmp(&self, other: &State) -> Ordering {
        other.cost.cmp(&self.cost)
    }
}

impl PartialOrd for State {
    fn partial_cmp(&self, other: &State) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

fn dijkstra(graph: &Vec<Vec<i32>>, source: usize) -> Vec<i32> {
    let n = graph.len();
    let mut distances = vec![i32::MAX; n];
    distances[source] = 0;

    let mut priority_queue = BinaryHeap::new();
    priority_queue.push(State { cost: 0, vertex: source });

    while let Some(State { cost, vertex }) = priority_queue.pop() {
        if cost > distances[vertex] {
            continue;
        }

        for (v, weight) in graph[vertex].iter().enumerate() {
            if *weight == 0 {
                continue;
            }

            let new_distance = distances[vertex] + weight;
            if new_distance < distances[v] {
                distances[v] = new_distance;
                priority_queue.push(State { cost: new_distance, vertex: v });
            }
        }
    }

    distances
}

fn main() {
    let graph = vec![
        vec![0, 4, 2, 0, 0],
        vec![4, 0, 1, 5, 0],
        vec![2, 1, 0, 8, 10],
        vec![0, 5, 8, 0, 2],
        vec![0, 0, 10, 2, 0],
    ];

    let source_vertex = 0;
    let shortest_distances = dijkstra(&graph, source_vertex);
    for distance in shortest_distances {
        print!("{} ", distance);
    }
}
```

**Ruby Code for Dijkstra's Algorithm:**

```ruby
require 'priority_queue'

def di

jkstra(graph, source)
    n = graph.length
    distances = Array.new(n, Float::INFINITY)
    distances[source] = 0

    priority_queue = PriorityQueue.new
    priority_queue[source] = 0

    while !priority_queue.empty?
        u, dist_u = priority_queue.delete_min

        next if dist_u > distances[u]

        graph[u].each_with_index do |weight, v|
            next if weight == 0

            new_distance = distances[u] + weight
            if new_distance < distances[v]
                distances[v] = new_distance
                priority_queue[v] = new_distance
            end
        end
    end

    distances
end

# Example usage:
graph = [
    [0, 4, 2, 0, 0],
    [4, 0, 1, 5, 0],
    [2, 1, 0, 8, 10],
    [0, 5, 8, 0, 2],
    [0, 0, 10, 2, 0]
]

source_vertex = 0
shortest_distances = dijkstra(graph, source_vertex)
puts shortest_distances.join(' ')
```

**Conclusion**

Dijkstra's Algorithm is a powerful and widely used algorithm to find the shortest path from a single source vertex to all other vertices in a weighted graph with non-negative edge weights. Its ability to efficiently calculate shortest distances in various applications, such as navigation systems, network routing, and transportation planning, makes it an essential tool in many computer science and engineering fields. The provided code examples in Python, C++, Rust, and Ruby demonstrate the implementation of Dijkstra's Algorithm, enabling you to leverage this efficient algorithm for your graph-related projects and optimization tasks.
