### **Travelling Salesman Problem (TSP) – Greedy Approach**

The **Travelling Salesman Problem (TSP)** is a classic optimization problem in which a salesman is required to visit a set of cities, each exactly once, and return to the origin city, while minimizing the total distance traveled. It is a well-known NP-hard problem, meaning that finding the optimal solution is computationally expensive, especially as the number of cities increases.

In the **Greedy Approach** to TSP, the goal is to make the locally optimal choice at each step in hopes of finding the globally optimal solution. The greedy algorithm doesn’t necessarily guarantee the best possible solution for TSP, but it often provides a good (though approximate) solution in a relatively short time.

### **Greedy Approach for TSP**

The greedy approach for the **Travelling Salesman Problem** works as follows:

1. **Start at an arbitrary city**: Choose any city to start the journey.
2. **At each step, visit the nearest unvisited city**: From the current city, find the nearest city that has not been visited yet, and move to it.
3. **Repeat the process until all cities have been visited**: Continue the process of visiting the nearest city until all cities are visited exactly once.
4. **Return to the starting city**: After visiting all the cities, return to the starting city to complete the tour.

This greedy strategy can be described as the **Nearest Neighbor Algorithm**, where at each step, the nearest city is chosen.

### **Steps of the Greedy TSP Algorithm**

1. **Initialization**:
   - Start at an arbitrary city, let’s say city **S**.
   - Mark the starting city as visited.
   - Set the initial tour distance to 0.

2. **Iterate over each city**:
   - From the current city, find the nearest unvisited city (i.e., the city that has the minimum distance to the current city).
   - Mark that city as visited and add the distance between the current city and the next city to the tour distance.
   
3. **Repeat until all cities are visited**:
   - Continue this process of selecting the nearest unvisited city until all cities are visited.

4. **Return to the start**:
   - Once all cities are visited, return to the starting city to complete the cycle.

5. **Output**:
   - The algorithm outputs the path taken and the total distance of the path.

### **Pseudocode for Greedy TSP**

```python
def greedy_tsp(distance_matrix):
    n = len(distance_matrix)  # number of cities
    visited = [False] * n  # array to keep track of visited cities
    path = []  # list to store the path
    total_distance = 0  # variable to store the total distance traveled

    # Start at an arbitrary city, for example city 0
    current_city = 0
    visited[current_city] = True
    path.append(current_city)

    # Repeat for all cities except the start city
    for _ in range(n - 1):
        min_distance = float('inf')
        next_city = None

        # Find the nearest unvisited city
        for city in range(n):
            if not visited[city] and distance_matrix[current_city][city] < min_distance:
                min_distance = distance_matrix[current_city][city]
                next_city = city

        # Visit the next city
        visited[next_city] = True
        path.append(next_city)
        total_distance += min_distance
        current_city = next_city

    # Add the distance to return to the starting city
    total_distance += distance_matrix[current_city][path[0]]
    path.append(path[0])  # Return to the starting city

    return path, total_distance
```

### **Example of Greedy TSP**

Suppose we have 4 cities with the following distance matrix:

| City | 0  | 1  | 2  | 3  |
|------|----|----|----|----|
| 0    | 0  | 10 | 15 | 20 |
| 1    | 10 | 0  | 35 | 25 |
| 2    | 15 | 35 | 0  | 30 |
| 3    | 20 | 25 | 30 | 0  |

1. **Starting from City 0**:
   - Nearest city: City 1 (distance 10)
   - New path: [0, 1], Total distance = 10

2. **From City 1**:
   - Nearest city: City 3 (distance 25)
   - New path: [0, 1, 3], Total distance = 10 + 25 = 35

3. **From City 3**:
   - Nearest city: City 2 (distance 30)
   - New path: [0, 1, 3, 2], Total distance = 35 + 30 = 65

4. **Return to City 0**:
   - Distance to return: 15 (from City 2 to City 0)
   - Final path: [0, 1, 3, 2, 0], Total distance = 65 + 15 = 80

Thus, the greedy algorithm results in the path **[0, 1, 3, 2, 0]** with a total distance of **80**.

### **Time Complexity of Greedy TSP**
The greedy TSP algorithm involves the following steps:
1. For each city, we find the nearest unvisited city, which requires checking each of the remaining cities.
2. This process is repeated for each city, leading to a time complexity of **O(n²)**, where **n** is the number of cities.

### **Advantages of the Greedy TSP Approach**
1. **Simplicity**: The greedy algorithm is simple to implement and easy to understand.
2. **Efficiency**: The time complexity is relatively efficient, **O(n²)**, especially for small to medium-sized datasets.

### **Disadvantages of the Greedy TSP Approach**
1. **Not optimal**: The greedy algorithm does not always find the optimal solution. It often results in a suboptimal path.
   - Example: In some cases, a global optimal solution may require a less greedy choice at some point, but the greedy algorithm doesn't consider this.
2. **Local minimum**: The algorithm can get stuck in local optima, where a better solution exists, but the algorithm never explores it because of the greedy choices made at each step.

### **Conclusion**
While the **Greedy Algorithm** provides a simple and fast solution to the Travelling Salesman Problem, it is not guaranteed to find the optimal solution. For many practical cases, the greedy approach can give a good approximation, but for optimal solutions, more sophisticated algorithms like **Dynamic Programming**, **Branch and Bound**, or **Genetic Algorithms** may be required. The greedy approach is useful for solving TSP when an approximate solution is sufficient and computational efficiency is a priority.
