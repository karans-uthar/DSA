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