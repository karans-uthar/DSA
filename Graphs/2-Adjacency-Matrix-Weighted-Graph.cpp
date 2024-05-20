#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int vertices, edges;
    bool directed;

    cin >> vertices >> edges >> directed;

    // vector < vector <bool> > adjMatrix (vertices, vector<bool>(vertices, 0)); // Unweighted Graph
    vector < vector <int> > adjMatrix (vertices, vector<int>(vertices, 0)); // Weighted Graph

    // Graph is directed
    if (directed) 
    {
        for (int i = 0; i < edges; i++)
        {
            int u, v, w; // u, v = adjacent vertices and w = weight of (u, v) edge
            cin >> u >> v >> w;

            adjMatrix[u][v] = w;
        }
    }
 
    // Graph is undirected
    else
    {
        for (int i = 0; i < edges; i++)
        {
            int u, v, w; // u, v = adjacent vertices and w = weight of {u, v} edge
            cin >> u >> v >> w;

            adjMatrix[u][v] = adjMatrix[v][u] = w;
        }
    }

    // Printing adjacency matrix
    for (int i = 0; i < adjMatrix.size(); i++)
    {
        for (int j = 0; j < adjMatrix[i].size(); j++)
            cout << adjMatrix[i][j] << " ";

        cout << endl;
    }
}

/*
//* Test Case 1
INPUT:
5 6 1
0 1 2
0 2 4
1 2 6
1 3 8
2 4 3
3 4 7

EXPLANATION:
vertices = 5
edges = 6
directed = 0 means graph is not directed
edges in graph are present between vertices (0, 1), (0, 2), (1, 2), (1, 3), (2, 4), (3, 4) 
weight on edge (0, 1) = 2
weight on edge (0, 2) = 4
weight on edge (1, 2) = 6
weight on edge (1, 3) = 8
weight on edge (2, 4) = 3
weight on edge (3, 4) = 7

OUTPUT: 
0 1 1 0 0
0 0 1 1 0
0 0 0 0 1
0 0 0 0 1
0 0 0 0 0 
*/

/*
//* Test Case 2
INPUT:
5 6 0
0 1 2
0 2 4
1 2 6
1 3 8
2 4 3
3 4 7

EXPLANATION:
vertices = 5
edges = 6
directed = 0 means graph is not directed
edges in graph are present between vertices {0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4}, {3, 4}
weight on edge {0, 1} = 2
weight on edge {0, 2} = 4
weight on edge {1, 2} = 6
weight on edge {1, 3} = 8
weight on edge {2, 4} = 3
weight on edge {3, 4} = 7

OUTPUT: 
0 1 1 0 0 
1 0 1 1 0 
1 1 0 0 1 
0 1 0 0 1 
0 0 1 1 0 
*/