# K Shortest Path Algorithm: Finding Multiple Shortest Paths

The K Shortest Path algorithm is a graph traversal technique used to find the K shortest paths between two vertices in a weighted graph. Unlike other shortest path algorithms that find a single optimal path, the K shortest path algorithm explores multiple paths ranked by their lengths. This algorithm is crucial in scenarios where there may be multiple feasible routes with different costs. In this article, we will delve into the concept of the K shortest path algorithm, its working principles, real-world applications, and provide Python and C++ code examples to demonstrate its implementation.

## Understanding the K Shortest Path Algorithm

The K Shortest Path algorithm extends the concept of shortest path algorithms by finding a set of K paths, each of which is optimal with respect to its length. These paths are sorted in ascending order of length, allowing users to select the most suitable path based on their preferences or requirements.

## Working Principles of the K Shortest Path Algorithm

1. **Initialization**: The algorithm starts by finding the shortest path between the source and target vertices using a standard shortest path algorithm, such as Dijkstra's or Bellman-Ford.

2. **Path Generation**: Once the shortest path is found, the algorithm generates alternative paths by iteratively relaxing edges along the current path. Each iteration aims to find a path that is longer than the previous paths but still feasible.

3. **Ranking Paths**: The algorithm ranks the generated paths based on their lengths. The paths with shorter lengths are given higher priority.

4. **Iterative Process**: The algorithm continues generating and ranking paths until K paths are found or until no more feasible paths can be generated.

## Example Applications of the K Shortest Path Algorithm

1. **Routing in Transportation Networks**: The K Shortest Path algorithm is used in transportation systems to find multiple feasible routes for vehicles, considering factors such as traffic congestion and toll costs.

2. **Communication Networks**: It is employed in communication networks to discover multiple paths for data packets, improving fault tolerance and network reliability.

## Python Implementation of the K Shortest Path Algorithm

```python
import heapq
from collections import defaultdict

def k_shortest_paths(graph, source, target, k):
    shortest_path = dijkstra(graph, source, target)
    if not shortest_path:
        return []

    paths = [shortest_path]
    potential_paths = []

    for _ in range(k):
        for i in range(len(paths[-1]) - 1):
            spur_node = paths[-1][i]
            root_path = paths[-1][:i + 1]

            graph_without_root_path = defaultdict(dict)
            for u, neighbors in graph.items():
                if u not in root_path:
                    graph_without_root_path[u] = {v: w for v, w in neighbors.items() if v not in root_path}

            spur_path = dijkstra(graph_without_root_path, spur_node, target)
            if spur_path:
                potential_path = root_path + spur_path[1:]
                potential_paths.append(potential_path)

        if not potential_paths:
            break

        potential_paths.sort(key=lambda path: sum(graph[u][v] for u, v in zip(path, path[1:])))
        paths.append(potential_paths.pop(0))

    return paths

def dijkstra(graph, source, target):
    distances = {vertex: float('infinity') for vertex in graph}
    distances[source] = 0

    priority_queue = [(0, source)]

    while priority_queue:
        current_distance, current_vertex = heapq.heappop(priority_queue)

        if current_vertex == target:
            path = []
            while current_vertex is not None:
                path.insert(0, current_vertex)
                current_vertex = previous_vertices[current_vertex]
            return path

        if current_distance > distances[current_vertex]:
            continue

        for neighbor, weight in graph[current_vertex].items():
            distance = current_distance + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                previous_vertices[neighbor] = current_vertex
                heapq.heappush(priority_queue, (distance, neighbor))

    return []

# Example graph using dictionaries (weighted directed graph)
graph = {
    'A': {'B': 2, 'C': 4},
    'B': {'C': 1, 'D': 7},
    'C': {'D': 3},
    'D': {}
}

source_vertex = 'A'
target_vertex = 'D'
k_value = 3

previous_vertices = {}
k_shortest_paths_list = k_shortest_paths(graph, source_vertex, target_vertex, k_value)
print("K Shortest Paths:")
for i, path in enumerate(k_shortest_paths_list, start=1):
    print(f"Path {i}: {' -> '.join(path)}")
```

## C++ Implementation of the K Shortest Path Algorithm

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <functional>
#include <algorithm>
#include <limits>

class KShortestPath {
public:
    KShortestPath(int num_vertices) : num_vertices(num_vertices) {
        graph.resize(num_vertices);
        distances.resize(num_vertices, std::numeric_limits<int>::max());
    }

    void addEdge(int u, int v, int weight) {
        graph[u][v] = weight;
    }

    std::vector<std::vector<int>> findKShortestPaths(int source, int target, int k) {
        std::vector<std::vector<int>> paths;

        std::vector<int> shortest_path = dijkstra(source, target);
        if (shortest_path.empty()) {
            return paths;
        }

        paths.push_back(shortest_path);
        std::vector<std::vector<int>> potential_paths;

        for (int count = 0; count < k; ++count) {
            for (int i = 0; i < paths.back().size() - 1; ++i) {
                int spur_node = paths.back()[i];
                std::vector<int> root_path(paths.back().begin(), paths.back().begin() + i + 1);

                std::map<int, std::map<int, int>> graph_without_root_path = graph;
                for (const auto& vertex : root_path) {
                    graph_without_root_path.erase(vertex);
                    for (auto& neighbor : graph_without_root_path) {
                        neighbor.second.erase(vertex);
                    }
                }

                std::vector<int> spur_path = dijkstra(spur_node, target, graph_without_root_path);
                if (!spur_path.empty()) {
                    std::vector<int> potential_path = root_path;
                    potential_path.insert(potential_path.end(), spur_path.begin() + 1, spur_path.end());
                    potential_paths.push_back(potential_path);
                }
            }

            if (potential_paths.empty()) {
                break;
            }

            std::sort(potential_paths.begin(), potential_paths.end(),
                      [this](const std::vector<int>& path1, const std::vector<int>& path2) {
                          return computePathWeight(path1) < computePathWeight(path2);
                      });

            paths.push_back(potential_paths.front());
            potential_paths.erase(potential_paths.begin());
        }

        return paths;
    }

private:
    int num_vertices;
    std::vector<std::map<int, int>> graph;
    std::vector<int> distances;

    std::

vector<int> dijkstra(int source, int target, const std::map<int, std::map<int, int>>& graph_without_root) {
        distances.assign(num_vertices, std::numeric_limits<int>::max());
        distances[source] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        pq.push(std::make_pair(0, source));

        std::vector<int> previous_vertices(num_vertices, -1);

        while (!pq.empty()) {
            int current_distance = pq.top().first;
            int current_vertex = pq.top().second;
            pq.pop();

            if (current_distance > distances[current_vertex]) {
                continue;
            }

            for (const auto& neighbor : graph_without_root.at(current_vertex)) {
                int neighbor_vertex = neighbor.first;
                int weight = neighbor.second;

                int distance = current_distance + weight;
                if (distance < distances[neighbor_vertex]) {
                    distances[neighbor_vertex] = distance;
                    previous_vertices[neighbor_vertex] = current_vertex;
                    pq.push(std::make_pair(distance, neighbor_vertex));
                }
            }
        }

        std::vector<int> path;
        int current = target;
        while (current != -1) {
            path.push_back(current);
            current = previous_vertices[current];
        }

        std::reverse(path.begin(), path.end());
        return path;
    }

    int computePathWeight(const std::vector<int>& path) {
        int weight = 0;
        for (int i = 0; i < path.size() - 1; ++i) {
            weight += graph[path[i]].at(path[i + 1]);
        }
        return weight;
    }
};

int main() {
    KShortestPath ksp(4);
    ksp.addEdge(0, 1, 2);
    ksp.addEdge(0, 2, 4);
    ksp.addEdge(1, 2, 1);
    ksp.addEdge(1, 3, 7);
    ksp.addEdge(2, 3, 3);

    int source_vertex = 0;
    int target_vertex = 3;
    int k_value = 2;

    std::vector<std::vector<int>> k_shortest_paths_list = ksp.findKShortestPaths(source_vertex, target_vertex, k_value);

    std::cout << "K Shortest Paths:" << std::endl;
    for (int i = 0; i < k_shortest_paths_list.size(); ++i) {
        std::cout << "Path " << i + 1 << ": ";
        for (int vertex : k_shortest_paths_list[i]) {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```

In both the Python and C++ implementations, the K Shortest Path algorithm is demonstrated. The examples showcase how to find multiple shortest paths between two vertices in a weighted graph. The K Shortest Path algorithm plays a critical role in optimization scenarios where multiple feasible routes with varying costs need to be considered. It is employed in transportation networks, communication systems, and other domains where route flexibility is essential.
