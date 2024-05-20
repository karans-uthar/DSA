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