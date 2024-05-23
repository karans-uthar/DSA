#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//* Recursive Version *//
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

//* Iterative Version *//
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        // Iterative Version
        stack<int> st; // Stack for DFS
        vector<bool> visited(V, 0); // Vector to keep track of visited nodes
        vector<int> answer; // Vector to store the DFS traversal order
        
        st.push(0); // Start DFS from node 0
        
        while (!st.empty()) 
        {
            int temp = st.top();
            st.pop();
            
            if (!visited[temp]) // If the node is not visited
            {
                visited[temp] = true; // Mark as visited
                answer.push_back(temp); // Add to the traversal order
                
                /*
                Push all unvisited neighbors onto the stack
                Iterate in reverse order to maintain the natural order
                */
                for (int i = adj[temp].size() - 1; i >= 0; i--) 
                    if (!visited[adj[temp][i]])
                        st.push(adj[temp][i]);
            }
        }
        
        return answer;
    }
};