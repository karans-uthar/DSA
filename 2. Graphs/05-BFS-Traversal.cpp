#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution 
{
    public:
    
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
        queue<int> q;
        vector<bool> visited(V, 0);
        vector<int> answer;
        
        q.push(0);
        visited[0] = 1;
        
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            
            answer.push_back(temp);
            
            for (int i = 0; i < adj[temp].size(); i++)
            {
                if (!visited[adj[temp][i]])
                {
                    visited[adj[temp][i]] = 1;
                    q.push(adj[temp][i]);
                }
            }
        }
        
        return answer;
    }
};