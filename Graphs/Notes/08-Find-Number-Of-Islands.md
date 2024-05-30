# [Find Number Of Islands](https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1)

The problem you're tackling is to find the number of islands in a given grid of '1's (land) and '0's (water). An island is surrounded by water and is formed by connecting adjacent lands horizontally, vertically, or diagonally. The goal is to count these distinct islands.

### C++ Code

``` C++
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Data Members
    int r;
    int c; 
    int row[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int column[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
  
    // Member Functions
    bool valid(int i, int j)
    {
        return (i >= 0 and i < r) && (j >= 0 and j < c);
    }
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // BFS
        int island = 0;
        r = grid.size();
        c = grid[0].size();
        queue< pair<int, int> > q;
        
        // Finding one in the grid
        for (int i = 0; i < r; i++) 
        {
            for (int j = 0; j < c; j++) 
            {
                if (grid[i][j] == '1')
                {
                    island++;
                    
                    // Make all one in an island convert to zero
                    q.push(make_pair(i, j));
                    grid[i][j] = '0';
                    
                    while (!q.empty())
                    {
                        int new_i = q.front().first;
                        int new_j = q.front().second;
                        q.pop();
                        
                        for (int k = 0; k < 8; k++)
                        {
                            if (valid(new_i + row[k], new_j + column[k]) and grid[new_i + row[k]][new_j + column[k]] == '1')
                            {
                                q.push(make_pair(new_i + row[k], new_j + column[k]));
                                grid[new_i + row[k]][new_j + column[k]] = '0';
                            }
                        }
                    }
                }
            }
        }
        
        return island;
    }
};
```

### Code Explanation

#### Data Members

1. **`r` and `c`**: These are integers representing the number of rows and columns in the grid, respectively.
2. **`row` and `column`**: These arrays are used to explore all 8 possible directions (up, down, left, right, and the 4 diagonals) from any given cell.

#### Member Functions

1. **`bool valid(int i, int j)`**:
   - This function checks if the coordinates `(i, j)` are within the boundaries of the grid.

2. **`int numIslands(vector<vector<char>>& grid)`**:
   - This function implements a BFS approach to find and count the number of islands in the grid.
   - **Initialization**:
     - `island` is initialized to 0 to keep track of the number of islands.
     - `r` and `c` are set to the number of rows and columns in the grid.
     - A queue `q` is used for BFS traversal.
   - **Grid Traversal**:
     - The outer loop iterates over each cell in the grid.
     - When a '1' (land) is found, it indicates the start of a new island.
     - Increment the `island` count and push the coordinates of this cell into the queue.
     - Mark the cell as visited by setting it to '0'.
   - **BFS**:
     - For each cell in the queue, explore all 8 possible directions.
     - If an adjacent cell is valid (within grid bounds) and is '1', push its coordinates into the queue and mark it as visited.
   - The process continues until all cells have been checked, and the total number of islands is returned.

### Time Complexity

The time complexity of the algorithm is O(r x c), where r is the number of rows and c is the number of columns in the grid. This is because:
- Each cell is visited once.
- Each cell's neighbors are checked a constant number of times (8 directions).

### Space Complexity

The space complexity is also O(r x c) due to the space required for the queue used in BFS. In the worst case, the queue can hold all the cells of the grid if they are part of the same island.

### Auxiliary Space Complexity

The auxiliary space complexity, which excludes the input grid, is also O(r x c). This is due to:
- The queue used for BFS.
- The recursive stack in a BFS implementation (though here we use an iterative approach, avoiding stack space issues).

In summary, your code efficiently counts the number of islands in the grid using BFS, ensuring each cell is processed in constant time with respect to its neighbors, leading to a linear time complexity with respect to the size of the grid. The space usage is linear due to the queue used in BFS, matching the problem's constraints.