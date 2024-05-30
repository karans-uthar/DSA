#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool DFS(int temp, vector<int> *adj, vector<bool> &path, vector<bool> &visited)
    {
        path[temp] = visited[temp] = 1;
        
        for (int i = 0; i < adj[temp].size(); i++)
        {
            if (path[adj[temp][i]])
                return true;
                
            if (!visited[adj[temp][i]] and DFS(adj[temp][i], adj, path, visited))
                return true;
        }
        
        path[temp] = 0;
        
        return false;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) 
    {
        vector<bool> path(V, 0); // path also known as DFS Stack
        vector<bool> visited(V, 0);
    
        for (int i = 0; i < V; i++)
        {
            if (!path[i] and DFS(i, adj, path, visited))
                return true;
        }
        
        return false;
    }
};