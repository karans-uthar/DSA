# Cycle Detection in Undirected Graph Using DFS and BFS [🔗](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/0)

# Depth-First Search (DFS) Approach

### Explanation

The DFS-based approach for cycle detection in an undirected graph involves:

1. Recursively traversing the graph using DFS.
2. Keeping track of visited nodes to avoid revisiting them.
3. Maintaining a parent node to ensure that a cycle is correctly detected by avoiding false positives caused by the bidirectional nature of edges in undirected graphs.

### C++ Code

```cpp
bool DFS(int node, int parent, vector<int> adj[], vector<bool> &visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (DFS(neighbor, node, adj, visited)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; ++i) {
        if (!visited[i] && DFS(i, -1, adj, visited)) {
            return true;
        }
    }
    return false;
}
```

### Time Complexity

- **O(V + E)**: Each vertex and edge is visited once.

### Space Complexity

- **O(V)**: Space for the visited array.
- **O(V)**: Auxiliary space for the recursion stack in the worst case.

### Example

Consider the graph:
```
  0 -- 1
  |    |
  2 -- 3
```
Adjacency list representation:
```
adj = {
    {1, 2}, // Node 0
    {0, 3}, // Node 1
    {0, 3}, // Node 2
    {1, 2}  // Node 3
}
```
DFS will detect a cycle in this graph.

# Breadth-First Search (BFS) Approach

### Explanation

The BFS-based approach for cycle detection involves:
1. Iteratively traversing the graph level-by-level using BFS.
2. Using a queue to manage the nodes to be visited, along with their parent nodes.
3. Checking for cycles by ensuring that a node is not revisited through a different path.

### Pseudocode

```cpp
bool BFS(int start, vector<int> adj[], vector<bool> &visited) {
    queue<pair<int, int>> q;
    q.push({start, -1});
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, node});
            } else if (neighbor != parent) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; ++i) {
        if (!visited[i] && BFS(i, adj, visited)) {
            return true;
        }
    }
    return false;
}
```

### Time Complexity

- **O(V + E)**: Each vertex and edge is visited once.

### Space Complexity

- **O(V)**: Space for the visited array.
- **O(V)**: Auxiliary space for the queue in the worst case.

### Example

Consider the same graph:
```
  0 -- 1
  |    |
  2 -- 3
```
Adjacency list representation:
```
adj = {
    {1, 2}, // Node 0
    {0, 3}, // Node 1
    {0, 3}, // Node 2
    {1, 2}  // Node 3
}
```
BFS will also detect a cycle in this graph.

#### Graphical Representation

For the graph:
```
  0 -- 1
  |    |
  2 -- 3
```

### DFS Traversal Example:
- Start at node 0.
- Visit node 0, mark as visited.
- Visit node 1, mark as visited, parent 0.
- Visit node 3, mark as visited, parent 1.
- Visit node 2, mark as visited, parent 3.
- Node 2 connects back to node 0 (not parent of 2), cycle detected.

### BFS Traversal Example:
- Start at node 0.
- Visit node 0, mark as visited, add {1, 0} and {2, 0} to queue.
- Visit node 1, mark as visited, add {3, 1} to queue.
- Visit node 2, mark as visited, add {3, 2} to queue.
- Visit node 3, mark as visited.
- Node 3 connects back to node 1 (not parent of 3), cycle detected.

#### Comparison
```
---------------------------------------------------------------------------------
| Aspect                | DFS                       | BFS                       |
---------------------------------------------------------------------------------
| Time Complexity       | O(V + E)                  | O(V + E)                  |
| Space Complexity      | O(V)                      | O(V)                      |
| Auxiliary Space       | O(V) (recursion stack)    | O(V) (queue)              |
| Detection Method      | Recursive                 | Iterative                 |
| Traversal             | Depth-first               | Breadth-first             |
| Use Cases             | Better for deep trees     | Better for shallow trees  |
---------------------------------------------------------------------------------
```

Both DFS and BFS are effective for cycle detection in undirected graphs, with similar time and space complexities. The choice between them can depend on the specific characteristics of the graph and implementation preferences.