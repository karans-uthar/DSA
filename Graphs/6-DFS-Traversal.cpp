#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void DFSGraph(int temp, vector<int> adj[], vector<bool> &visited, vector<int> &answer)
    {
        visited[temp] = 1;
        answer.push_back(temp);
        
        for (int i = 0; i < adj[temp].size(); i++)
            if (!visited[adj[temp][i]])
                DFSGraph(adj[temp][i], adj, visited, answer);
    }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        // Code here
        vector<bool> visited (V, 0);
        vector<int> answer;
        
        DFSGraph(0, adj, visited, answer);
        
        return answer;
    }
};