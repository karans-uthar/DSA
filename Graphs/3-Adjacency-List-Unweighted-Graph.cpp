#include <iostream> 
#include <vector>
using namespace std;

int main()
{
    int vertices, edges, directed;

    cin >> vertices >> edges >> directed;

    vector < vector<int> > adjList(vertices);

    // Directed Graph
    if (directed)
    {
        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cin >> u >> v;

            adjList[u].push_back(v);
        }
    }

    // Undirected Graph
    else
    {
        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cin >> u >> v;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    cout << endl;

    // Displaying Adjacency List
    for (int i = 0; i < adjList.size(); i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            if (j == adjList[i].size() - 1)
                cout << adjList[i][j];

            else
                cout << adjList[i][j] << ", ";
        }

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
0 -> 1, 2
1 -> 2, 3
2 -> 4
3 -> 4
4 ->
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
0 -> 1, 2
1 -> 0, 2, 3
2 -> 0, 1, 4
3 -> 1, 4
4 -> 2, 3
*/