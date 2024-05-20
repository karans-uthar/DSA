#include <iostream> 
#include <vector>
using namespace std;

int main()
{
    int vertices, edges, directed;

    cin >> vertices >> edges >> directed;

    vector < vector< pair<int, int> > > adjList(vertices);

    // Directed Graph
    if (directed)
    {
        for (int i = 0; i < edges; i++)
        {
            int u, v, w; // u, v = adjacent vertices and w = weight of (u, v) edge
            cin >> u >> v >> w;

            adjList[u].push_back(make_pair(v, w));
        }
    }

    // Undirected Graph
    else
    {
        for (int i = 0; i < edges; i++)
        {
            int u, v, w; // u, v = adjacent vertices and w = weight of {u, v} edge
            cin >> u >> v >> w;

            adjList[u].push_back(make_pair(v, w));
            adjList[v].push_back(make_pair(u, w));
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
                cout << "[" << adjList[i][j].first << ", " << adjList[i][j].second << "]";

            else
                cout << "[" << adjList[i][j].first << ", " << adjList[i][j].second << "], ";
        }

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
0 -> [1, 2], [2, 4]
1 -> [2, 6], [3, 8]
2 -> [4, 3]
3 -> [4, 7]
4 ->
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
0 -> [1, 2], [2, 4]
1 -> [0, 2], [2, 6], [3, 8]
2 -> [0, 4], [1, 6], [4, 3]
3 -> [1, 8], [4, 7]
4 -> [2, 3], [3, 7]
*/