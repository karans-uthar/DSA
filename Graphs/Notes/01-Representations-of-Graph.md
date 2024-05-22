Sure, let's easily explain the representation of a graph in C++ using both Adjacency List and Adjacency Matrix. We'll provide algorithms for both representations, examples, and analyze their complexities.

# 1. Adjacency List

**`Defination:`** An adjacency list represents a graph as an array of lists. Each index of the array corresponds to a vertex, and the list at each index contains all vertices adjacent to that vertex.

**Example** : Consider a graph with 4 vertices (0, 1, 2, 3) and the edges: 0-1, 0-2, 1-2, 2-3.

          0
         / \
        1---2
             \
              3

**Adjacency List representation**:

    ``` 

        0 -> 1, 2
        1 -> 0, 2
        2 -> 0, 1, 3
        3 -> 2

    ```

**C++ Code:**

```cpp

    #include <iostream>
    #include <vector>
    using namespace std;

    void addEdge(vector<int> adj[], int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    void printGraph(const vector<int> adj[], int V) {
        for (int v = 0; v < V; ++v) {
            cout << "Adjacency list of vertex " << v << ": ";
            for (int x : adj[v])
                cout << x << " ";
            cout << endl;
        }
    }

    int main() {
        int V = 4;
        vector<int> adj[V];

        addEdge(adj, 0, 1);
        addEdge(adj, 0, 2);
        addEdge(adj, 1, 2);
        addEdge(adj, 2, 3);

        printGraph(adj, V);

        return 0;
    }

```

**Complexities** :

- `Time Complexity`: Adding an edge takes O(1) time. Thus, for E edges, it’s O(E).

- `Space Complexity`: The total space is O(V + E), where V is the number of vertices and E is the number of edges. Each vertex stores its neighbors, contributing to the space complexity.

- `Auxiliary Space Complexity`: Additional space used by the algorithm, excluding input space, is minimal (constant), i.e., O(1).

# 2. Adjacency Matrix

**`Definition`** : An adjacency matrix is a 2D array of size VxV where V is the number of vertices. The cell (i, j) is true (or 1) if there is an edge from vertex i to vertex j, otherwise, it’s false (or 0).

**Example** : For the same graph.

**Adjacency Matrix**:

    ```

       0 1 2 3
    0 [0 1 1 0]
    1 [1 0 1 0]
    2 [1 1 0 1]
    3 [0 0 1 0]

    ```

**C++ Code:**

```cpp

    #include <iostream>
    using namespace std;

    void addEdge(int adjMatrix[][4], int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // For undirected graph
    }

    void printGraph(int adjMatrix[][4], int V) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    int main() {
        int V = 4;
        int adjMatrix[4][4] = {0};

        addEdge(adjMatrix, 0, 1);
        addEdge(adjMatrix, 0, 2);
        addEdge(adjMatrix, 1, 2);
        addEdge(adjMatrix, 2, 3);

        printGraph(adjMatrix, V);

        return 0;
    }

```

**Complexities** :

- `Time Complexity`: Adding an edge takes O(1) time. Thus, for E edges, it’s O(E).

- `Space Complexity`: The total space is O(V^2) because we need to store V * V elements.

- `Auxiliary Space Complexity`: Additional space used by the algorithm, excluding input space, is minimal (constant), i.e., O(1).

# Mathematical Proofs and Comparisons

> Adjacency List:

- **`Space Proof`** : For an adjacency list

    Space Complexity = O(V) **for the array of lists** + O(E) *for storing all neighbors* = O(V + E)

    Space Complexity = O(V) *in best case where E = V in cycle graph*
    Space Complexity = O(V^2) *in worst case where E = V(V-1)/2 in complete graph*
    Space Complexity = O(V^2) *in average case*

- **`Time for Adding Edge Proof`** :  Each edge is added to the list of its two endpoints in O(1) time.

    Time Complexity= E x O(1) = O(E) *in every case*

> Adjacency Matrix:

- **`Space Proof`** : For an adjacency matrix
  
    Space Complexity = O(V^2) *in every case*

- **`Time for Adding Edge Proof`** : Each edge is added in O(1) time in the matrix.
  
    Time Complexity = E x O(1) = O(E) *in every case*

# Comparison:

- `Space Efficiency`: Adjacency list is more space-efficient, especially for sparse graphs where E is much less than V^2.

- `Access Time`: Adjacency matrix allows O(1) time complexity to check if there is an edge between any two vertices, whereas adjacency list requires O(V) in the worst case.

- `Insertion and Deletion`: Inserting or deleting edges is more straightforward in an adjacency matrix with O(1) time, while in an adjacency list, it takes O(1) for insertion but O(V) for deletion in the worst case.

```
    ------------------------------------------------------------
    |      Criteria        | Adjacency List | Adjacency Matrix |
    ------------------------------------------------------------
    | Time Complexity      | O(E)           | O(E)             |
    | Space Complxity      | O(V + E)       | O(V^2)           |
    | Access Time          | O(V)           | O(1)             |
    | Insertion Time       | O(1)           | O(1)             |
    | Deletion Time        | O(V)           | O(1)             |
    ------------------------------------------------------------

```

# Summary

The choice of graph representation depends on the specific requirements of the application and the properties of the graph (sparse vs dense).
