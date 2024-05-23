Certainly! Let's dive into both the DFS-based and BFS-based cycle detection algorithms for directed graphs, and compare their time complexity, space complexity, and auxiliary space complexity.

### [DFS-Based Cycle Detection]()

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool DFS(int temp, vector<int> *adj, vector<bool> &path, vector<bool> &visited) {
        path[temp] = visited[temp] = true;

        for (int i = 0; i < adj[temp].size(); i++) {
            if (path[adj[temp][i]])
                return true;

            if (!visited[adj[temp][i]] && DFS(adj[temp][i], adj, path, visited))
                return true;
        }

        path[temp] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> path(V, false); // path also known as DFS Stack
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!path[i] && DFS(i, adj, path, visited))
                return true;
        }

        return false;
    }
};
```

**Explanation:**

- **DFS Function:** 
  - `path[temp] = visited[temp] = true;` marks the current node as being in the current DFS path and visited.
  - The function then iterates through all adjacent vertices of the current node.
  - If an adjacent vertex is already in the current DFS path (`path[adj[temp][i]]`), a cycle is detected.
  - If an adjacent vertex is not visited, the DFS function is called recursively.
  - After exploring all neighbors, `path[temp]` is set to false, indicating that the current node is no longer in the DFS path.

- **isCyclic Function:**
  - Initializes two vectors `path` and `visited` to track nodes in the current DFS path and all visited nodes, respectively.
  - Iterates over all vertices to ensure that each connected component is checked.
  - If a cycle is found during the DFS call, it returns true.

**Time Complexity:**
- The DFS traversal visits each vertex once and explores each edge once.
- Time complexity is \(O(V + E)\), where \(V\) is the number of vertices and \(E\) is the number of edges.

**Space Complexity:**
- The `visited` and `path` vectors each use \(O(V)\) space.
- Stack space for the recursive calls can be up to \(O(V)\) in the worst case.

**Auxiliary Space Complexity:**
- Auxiliary space is \(O(V)\) for the recursion stack in the worst case.

# BFS-Based Cycle Detection (Kahn's Algorithm)

**Code Explanation:**
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCyclic(int V, vector<int> adj[]) {
        int count = 0;
        vector<int> indegree(V, 0);
        queue<int> q;

        // Count indegree of all vertices
        for (int i = 0; i < V; i++)
            for (int j = 0; j < adj[i].size(); j++)
                indegree[adj[i][j]]++;

        // Push vertices with indegree 0 to the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                count++;
            }
        }

        // BFS
        while (!q.empty()) {
            int temp = q.front();
            q.pop();

            for (int i = 0; i < adj[temp].size(); i++) {
                indegree[adj[temp][i]]--;

                if (indegree[adj[temp][i]] == 0) {
                    q.push(adj[temp][i]);
                    count++;
                }
            }
        }

        return count != V;
    }
};
```

**Explanation:**
- **Indegree Calculation:**
  - Calculates the indegree of each vertex (the number of incoming edges).

- **Initialization:**
  - Adds all vertices with zero indegree to the queue.

- **BFS Traversal:**
  - Processes nodes in the queue, reduces the indegree of their neighbors.
  - Adds neighbors to the queue if their indegree becomes zero.
  - Tracks the count of processed nodes.

- **Cycle Detection:**
  - If the count of processed nodes does not equal the number of vertices, a cycle exists.

**Time Complexity:**
- Similar to DFS, each vertex and edge is processed once.
- Time complexity is \(O(V + E)\).

**Space Complexity:**
- The `indegree` vector uses \(O(V)\) space.
- The queue can store up to \(O(V)\) vertices in the worst case.

**Auxiliary Space Complexity:**
- BFS uses \(O(V)\) space for the queue in the worst case.

### Comparison

**Time Complexity:**
- Both DFS and BFS approaches have the same time complexity of \(O(V + E)\).

**Space Complexity:**
- Both approaches have similar space complexities, \(O(V)\), due to the storage of visited states and the current DFS path or indegree counts.

**Auxiliary Space Complexity:**
- DFS has an auxiliary space complexity of \(O(V)\) due to the recursion stack.
- BFS has an auxiliary space complexity of \(O(V)\) due to the queue.

### Summary
- Both methods efficiently detect cycles in a directed graph.
- **DFS** is straightforward with recursion but can lead to deeper recursion stacks.
- **BFS (Kahn's Algorithm)** uses a queue and is iterative, which can be easier to manage in some scenarios without risking stack overflow.
- Choice of method may depend on specific constraints and preferences for iterative vs. recursive approaches.