#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) 
    {
        // BFS (Kahn's ALgorithm)
        int count = 0;
        vector<int> indegree(V, 0);
        queue<int> q;
        
        // Step 1: Count indegree of all the vertices in the graph
        for (int i = 0; i < V; i++)
            for (int j = 0; j < adj[i].size(); j++)
                indegree[adj[i][j]]++;
                
        // Step 2: Push all the vertices into the queue whose indegree = 0
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                count++;
            }
        }
                
        // Step 3: BFS
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            
            for (int i = 0; i < adj[temp].size(); i++)
            {
                indegree[adj[temp][i]]--;
                
                if (!indegree[adj[temp][i]])
                {
                    q.push(adj[temp][i]);
                    count++;
                }
            }
        }
        
        return count != V;
    }
};