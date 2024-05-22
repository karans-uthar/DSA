# [Topological Sorting](https://www.geeksforgeeks.org/problems/topological-sort/1)

Topological sorting of a Directed Acyclic Graph (DAG) is a linear ordering of its vertices such that for every directed edge u -> v , vertex (u) comes before vertex (v) in the ordering.

## DFS-Based Approach

### Explanation

1. **DFS Traversal**: Perform a DFS traversal starting from each unvisited node.
2. **Stack**: Use a stack to store the vertices in the order of their completion times.
3. **Order**: Pop vertices from the stack to get the topological order.

### C++ Code
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	void topoSortDFS(int temp, vector<int> *adj, vector<bool> &visited, stack<int> &st)
	{
	    visited[temp] = 1;
	    
	    for (int i = 0; i < adj[temp].size(); i++)
	    {
	        if (!visited[adj[temp][i]])
	            topoSortDFS(adj[temp][i], adj, visited, st);
	    }
	            
	    st.push(temp);
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // DFS
	    vector<bool> visited(V, 0);
	    vector<int> answer;
	    stack<int> st;
	    
	    // Call the recursive helper function to store Topological Sort starting from all vertices one by one
	    for (int i = 0; i < V; i++)
	    {
	        if (!visited[i])
	            topoSortDFS(i, adj, visited, st);
	    }
	    
	    // Retrieve the topological order from the stack
	    while (!st.empty())
	    {
	        answer.push_back(st.top());
	        st.pop();
	    }
	    
	    return answer;
	}
};
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
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	vector<int> getIndegreeOfVertices(int V, vector<int> *adj)
	{
	    vector<int> answer(V, 0);
	    
	    for (int i = 0; i < V; i++)
	        for (int j = 0; j < adj[i].size(); j++)
	            answer[adj[i][j]]++;
	            
	    return answer;
	}
	
	// Kahn's Algorithm
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> answer;
	    
        // Step 1: Calculate indegree of all the vertices in the graph
	    vector<int> indegree = getIndegreeOfVertices(V, adj);
	        
	    // Step 2: Push all nodes in queue whose indegree is zero
	    queue<int> q;
	    
	    for (int i = 0; i < indegree.size(); i++)
	        if (indegree[i] == 0)
	            q.push(i);
	   
	    // Step 3: Pop nodes from the queue and decrease the indegree of adjacent nodes and if indegree of any of the node becomes zero push it into the queue
	    while (!q.empty())
	    {
	        int temp = q.front();
	        q.pop();
	        
	        answer.push_back(temp);
	        
	        for (int i = 0; i < adj[temp].size(); i++)
	        {
	            indegree[adj[temp][i]]--;
	            
	            if (indegree[adj[temp][i]] == 0)
	                q.push(adj[temp][i]);
	        }
	    }
	    
	    return answer;
	}
};
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