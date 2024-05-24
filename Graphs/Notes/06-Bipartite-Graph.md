Sure, let's dive deeper into the concept of bipartite graphs, their properties, how to determine if a graph is bipartite using BFS and DFS, and how this relates to recommendation systems and the stable marriage problem.

# [Bipartite Graphs](https://www.geeksforgeeks.org/problems/bipartite-graph/1)

A **bipartite graph** is a graph whose vertices can be divided into two disjoint sets U and V such that no edge connects vertices within the same set. Formally, a graph G = (V, E) is bipartite if V can be partitioned into two sets U and V such that every edge e in E has one endpoint in U and the other endpoint in V.

### Key Properties

1. **Two-Colorable**: You can color the graph using two colors such that no two adjacent vertices share the same color. This is equivalent to saying the graph is bipartite.

2. **No Odd-Length Cycles**: A graph is bipartite if and only if it contains no odd-length cycles. This property is useful for checking if a graph is bipartite.

### Checking for Bipartiteness

We can check if a graph is bipartite using two graph traversal techniques: Breadth-First Search (BFS) and Depth-First Search (DFS).

## `BFS Approach`

In the BFS approach, we attempt to color the graph using two colors while traversing it level by level. If we find a vertex that needs to be the same color as an adjacent vertex, the graph is not bipartite.

**Algorithm Steps**:

1. Initialize a color array with -1 (uncolored).
2. For each vertex, if it is uncolored, start a BFS traversal.
3. Assign the starting vertex a color (say 0).
4. For each vertex processed, color all its adjacent vertices with the opposite color.
5. If an adjacent vertex is already colored with the same color as the current vertex, return false (the graph is not bipartite).
6. If all vertices can be colored without conflicts, return true (the graph is bipartite).

**Code**:

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isBipartite(int V, vector<int>adj[])
	{
	    // BFS Traversal
	    vector<int> color(V, -1); // Red = 0, Blue = 1, None = -1
	    queue<int> q;
	    
	    for (int i = 0; i < V; i++)
	    {
	        if (color[i] == -1)
	        {
	            q.push(i);
        	    color[i] = 0;
        	    
        	    while (!q.empty())
        	    {
        	        int temp = q.front();
        	        q.pop();
        	        
        	        for (int i = 0; i < adj[temp].size(); i++)
        	        {
        	            // If color to the neighbouring node is not assigned 
        	            if (color[adj[temp][i]] == -1)
        	            {
        	                color[adj[temp][i]] = (color[temp] + 1) % 2;
        	                q.push(adj[temp][i]);
        	            }
        	            
        	            // If color to the neighbouring node is already assigned
        	            else
        	            {
        	                if (color[temp] == color[adj[temp][i]])
        	                    return false;
        	            }
        	        }
        	    }
	        }
	    }
	    
	    return true;
	}

};
```

## `DFS Approach`

In the DFS approach, we use a recursive function to attempt to color the graph. The same conflict check is performed: if an adjacent vertex needs to be the same color as the current vertex, the graph is not bipartite.

**Algorithm Steps**:

1. Initialize a color array with -1 (uncolored).
2. For each vertex, if it is uncolored, start a DFS traversal.
3. Assign the starting vertex a color (say 0).
4. For each vertex processed, recursively color all its adjacent vertices with the opposite color.
5. If an adjacent vertex is already colored with the same color as the current vertex, return false (the graph is not bipartite).
6. If all vertices can be colored without conflicts, return true (the graph is bipartite).

**Code**:

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool DFS(int temp, vector<int> *adj, vector<int> &color)
    {
        for (int i = 0; i < adj[temp].size(); i++)
        {
            // If color of neighbouring node is not assigned
            if (color[adj[temp][i]] == -1)
            {
                color[adj[temp][i]] = (color[temp] + 1) % 2;
                
                if (!DFS(adj[temp][i], adj, color))
                    return false;
            }
            
            // If color of neighbouring node is already assigned
            else
            {
                if (color[adj[temp][i]] == color[temp])
                    return false;
            }
        }
        
        return true;
    }

	bool isBipartite(int V, vector<int>adj[])
	{
	    // DFS
	    vector<int> color(V, -1);
	    
	    for (int i = 0; i < V; i++)
	    {
	        if (color[i] == -1)
	        {
	            color[i] = 0;
	            
                if (!DFS(i, adj, color))
                    return false;
	        }
	    }
	    
	    return true;
	}
};
```

### Complexity Analysis

- **Time Complexity**: 
  - Both algorithms visit each vertex once and check each edge once.
  - Thus, the time complexity for both BFS and DFS approaches is O(V + E).

- **Space Complexity**:
  - The space complexity is O(V) for the color array.
  - In the BFS approach, the queue can hold up to O(V) elements in the worst case.
  - In the DFS approach, the recursion stack can hold up to O(V) elements in the worst case.
  - Thus, the overall space complexity for both approaches is O(V).

### Visualization

Consider the following graph:

```
0 -- 1
|    |
3 -- 2
```

This graph is bipartite because we can color it as follows:

- Vertex 0: Red
- Vertex 1: Blue
- Vertex 2: Red
- Vertex 3: Blue

This forms two sets {0, 2} and {1, 3}, with no edges within each set.

However, consider this graph:

```
0 -- 1
|    |
3 -- 2
 \  /
  4
```

This graph is not bipartite because it contains an odd-length cycle (0-1-2-4-3-0), which cannot be 2-colored without conflicts.

## Relationship to Recommendation Systems and Stable Marriage Problem

### Recommendation Systems

In recommendation systems, bipartite graphs model relationships between two types of entities, such as users and items (movies, products). Each user is connected to items they have interacted with (e.g., rated). This model helps in collaborative filtering, where recommendations for a user are made based on the preferences of similar users.

For example:

```
Users: A, B, C
Items: X, Y, Z

Edges: 
A -- X
A -- Y
B -- Y
C -- X
C -- Z
```

This bipartite graph helps identify which items might interest users based on their connections and the connections of similar users.

### Stable Marriage Problem

The stable marriage problem can be represented using a bipartite graph where one set represents one group (e.g., men) and the other set represents another group (e.g., women). Each edge represents a possible match. The goal is to find a matching such that no two pairs would prefer each other over their current matches. The Gale-Shapley algorithm, used to solve this problem, can be visualized as iteratively improving matchings on a bipartite graph.

For example:

```
Men: M1, M2
Women: W1, W2

Preferences:
M1: W1 > W2
M2: W2 > W1
W1: M1 > M2
W2: M2 > M1

Edges represent preferences:
M1 -- W1
M1 -- W2
M2 -- W1
M2 -- W2
```

The goal is to find a stable matching where no man and woman pair prefer each other over their current partners.

## Conclusion

Bipartite graphs are fundamental in many areas of computer science and applied mathematics. Understanding their properties and how to determine bipartiteness is crucial for solving problems like recommendation systems and the stable marriage problem. The BFS and DFS approaches provide efficient ways to check for bipartiteness, with both having a time complexity of O(V + E) and space complexity of O(V).