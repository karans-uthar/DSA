# [Topological Sorting](https://www.geeksforgeeks.org/problems/topological-sort/1)

Topological sorting of a Directed Acyclic Graph (DAG) is a linear ordering of its vertices such that for every directed edge u -> v , vertex (u) comes before vertex (v) in the ordering.

## DFS-Based Approach

## Explanation

1. **DFS Traversal**: Perform a DFS traversal starting from each unvisited node.
2. **Stack**: Use a stack to store the vertices in the order of their completion times.
3. **Order**: Pop vertices from the stack to get the topological order.

#### C++ Code

```cpp
void topoSortDFS(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            topoSortDFS(neighbor, adj, visited, st);
        }
    }
    st.push(node); // Push the current node after visiting its neighbors
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    stack<int> st;
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            topoSortDFS(i, adj, visited, st);
        }
    }
    vector<int> result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    return result;
}
```

### Time Complexity

- **O(V + E)**: Each vertex and edge is visited once.

### Space Complexity

- **O(V)**: Space for the visited array.
- **O(V)**: Space for the stack.

### Auxiliary Space Complexity

- **O(V)**: Due to the recursion stack in the worst case.

## Kahn's Algorithm (BFS-Based Approach)

### Explanation

1. **Indegree Calculation**: Calculate the indegree of all vertices.
2. **Queue**: Use a queue to process nodes with zero indegree.
3. **Order**: Pop nodes from the queue, append to the result, and decrease the indegree of adjacent nodes.

### C++ Code

```cpp
vector<int> getIndegreeOfVertices(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; ++i) {
        for (int neighbor : adj[i]) {
            indegree[neighbor]++;
        }
    }
    return indegree;
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> result;
    vector<int> indegree = getIndegreeOfVertices(V, adj);
    queue<int> q;
    for (int i = 0; i < V; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    return result;
}
```

### Time Complexity

- **O(V + E)**: Each vertex and edge is visited once.

### Space Complexity

- **O(V)**: Space for the indegree array.
- **O(V)**: Space for the queue.

### Auxiliary Space Complexity

- **O(V)**: Due to the queue usage.

### Comparison of Both Approaches

```
-----------------------------------------------------------------------------------
| Aspect                | DFS-Based Approach         | Kahn's Algorithm (BFS)     |
-----------------------------------------------------------------------------------
| Traversal             | Depth-first                | Breadth-first              |
| Data Structure        | Stack                      | Queue                      |
| Indegree Calculation  | Not Required               | Required                   |
| Cycle Detection       | Requires extra handling    | Detects cycle naturally    |
| Order                 | Reverse post-order         | Level-order                |
-----------------------------------------------------------------------------------
```

### Conclusion

Both algorithms are efficient for topological sorting with similar time and space complexities. The choice between them depends on specific use cases and implementation preferences. DFS-based approach is recursive and may be more intuitive for depth-first problems, while Kahn's algorithm is iterative and more natural for breadth-first scenarios.