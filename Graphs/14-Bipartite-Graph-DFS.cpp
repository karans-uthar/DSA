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