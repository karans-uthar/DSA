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