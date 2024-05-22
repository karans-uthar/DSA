# [Depth-First Search (DFS)](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/0)

### Explanation

The DFS-based approach for cycle detection in an undirected graph involves:

1. Recursively traversing the graph using DFS.
2. Keeping track of visited nodes to avoid revisiting them.
3. Maintaining a parent node to ensure that a cycle is correctly detected by avoiding false positives caused by the bidirectional nature of edges in undirected graphs.

### C++ Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool DFS(int temp, int tempParent, vector<int> *adj, vector<bool> &visited)
    {
        visited[temp] = 1;
        
        for (int i = 0; i < adj[temp].size(); i++)
        {
            /*
            *This will give me wrong output*

            if (!visited[adj[temp][i]] and DFS(adj[temp][i], temp, adj, visited) == 1)
                return 1;
                    
            else if (adj[temp][i] != tempParent)
                return 1;
            */
            
            if (!visited[adj[temp][i]])
            {
                if (DFS(adj[temp][i], temp, adj, visited))  // If the adjacent node is not visited, perform DFS on it
                    return 1; 
            }
                
            else if (adj[temp][i] != tempParent) // If the adjacent node is visited and it is not equal to the tempParent, a cycle is detected
                    return 1; 
        }
        
        return 0;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // DFS Traversal
        vector<bool> visited(V, 0);
        
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] and DFS(i, -1, adj, visited))
                    return true; // If cycle found in any of the component of the graph
        }
        
        return false; // If no cycle found in any component of the graph
    }
};
```

### Time Complexity

- **O(V + E)**: Each vertex and edge is visited once.

### Space Complexity

- **O(V)**: Space for the visited array.
- **O(V)**: Auxiliary space for the recursion stack in the worst case.

# [Breadth-First Search (BFS)](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/0)

### Explanation

The BFS-based approach for cycle detection involves:
1. Iteratively traversing the graph level-by-level using BFS.
2. Using a queue to manage the nodes to be visited, along with their parent nodes.
3. Checking for cycles by ensuring that a node is not revisited through a different path.

### C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool BFS(vector<int> *adj, vector<bool> &visited, int i)
    {
        queue< pair<int, int> > q; // temp, tempParent will be stored in pair
         
        q.push(make_pair(i, -1));
        visited[i] = 1;
        
        while (!q.empty())
        {
            int temp = q.front().first;
            int parentTemp = q.front().second;
            q.pop();
            
            for (int i = 0; i < adj[temp].size(); i++)
            {
                if (!visited[adj[temp][i]]) // If the adjacent node is not visited
                {
                    visited[adj[temp][i]] = 1;
                    q.push(make_pair(adj[temp][i], temp));
                }
                
                else if (adj[temp][i] != parentTemp) // If the adjacent node is visited and it is not equal to the tempParent, a cycle is detected
                    return true;
            }
        }
        
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, 0);
        
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] and BFS(adj, visited, i))
                return 1; // If cycle found in any of the component of the graph
        }
        
        return 0; // If no cycle found in any component of the graph
    }
};
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