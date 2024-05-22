# Depth-First Search (DFS) Approach [🔗](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/0)

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

# Breadth-First Search (BFS) Approach [🔗](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/0)

### Explanation

The BFS-based approach for cycle detection involves:
1. Iteratively traversing the graph level-by-level using BFS.
2. Using a queue to manage the nodes to be visited, along with their parent nodes.
3. Checking for cycles by ensuring that a node is not revisited through a different path.

### C++ Code

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

### Comparison
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