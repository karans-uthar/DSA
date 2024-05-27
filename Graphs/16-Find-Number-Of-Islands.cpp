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