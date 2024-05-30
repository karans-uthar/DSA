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