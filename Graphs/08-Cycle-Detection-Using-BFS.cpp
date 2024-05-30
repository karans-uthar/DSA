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