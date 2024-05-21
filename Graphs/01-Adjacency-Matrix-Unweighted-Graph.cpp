#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int vertices, edges;
    bool directed;

    cin >> vertices >> edges >> directed;

    vector < vector <bool> > adjMatrix (vertices, vector<bool>(vertices, 0));

    // Graph is directed
    if (directed) 
    {
        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cin >> u >> v;

            adjMatrix[u][v] = 1;
        }
    }
 
    // Graph is undirected
    else
    {
        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cin >> u >> v;

            adjMatrix[u][v] = adjMatrix[v][u] = 1;
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
0 1
0 2
1 2
1 3
2 4
3 4

EXPLANATION:
vertices = 5
edges = 6
directed = 1 means graph is directed
edges in graph are present between vertices (0, 1), (0, 2), (1, 2), (1, 3), (2, 4), (3, 4) 

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
0 1
0 2
1 2
1 3
2 4
3 4

EXPLANATION:
vertices = 5
edges = 6
directed = 0 means graph is not directed
edges in graph are present between vertices {0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4}, {3, 4}

OUTPUT: 
0 1 1 0 0 
1 0 1 1 0 
1 1 0 0 1 
0 1 0 0 1 
0 0 1 1 0 
*/