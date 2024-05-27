# [Replace O's with X's](https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1?page=2&difficulty%5B%5D=1&category%5B%5D=Graph&sortBy=submissions)

The problem you're addressing involves modifying a given matrix such that all 'O's that are not connected to the boundary are changed to 'X'. An 'O' is considered connected to the boundary if it is adjacent (horizontally or vertically) to an 'O' on the boundary or connected through a chain of adjacent 'O's.

### C++ Code

``` C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    int r;
    int c;
    
    int row[4] = {-1, 0, 1, 0};
    int column[4] = {0, 1, 0, -1};
    
    bool valid (int i, int j)
    {
        return (i >= 0 and i < r) && (j >= 0 and j < c);
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        r = n, c = m;
        queue< pair<int, int> > q;
        
        // First Row
        for (int j = 0; j < c; j++)
        {
            if (mat[0][j] == 'O')
            {
                q.push(make_pair(0, j));
                mat[0][j] = 'Y';
            }
        }
        
        // Last Column
        for (int i = 1; i < r; i++)
        {
            if (mat[i][c - 1] == 'O')
            {
                q.push(make_pair(i, c - 1));
                mat[i][c - 1] = 'Y';
            }
        }
        
        // Last Row
        for (int j = c - 1; j >= 0; j--)
        {
            if (mat[r - 1][j] == 'O')
            {
                q.push(make_pair(r - 1, j));
                mat[r - 1][j] = 'Y';
            }
        }
        
        // First Column
        for (int i = r - 2; i >= 1; i--)
        {
            if (mat[i][0] == 'O')
            {
                q.push(make_pair(i, 0));
                mat[i][0] = 'Y';
            }
        }
                
        // BFS Traversal
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            mat[i][j] = 'Y';
            
            for (int k = 0; k < 4; k++)
            {
                if (valid(i + row[k], j + column[k]) and mat[i + row[k]][j + column[k]] == 'O')
                {
                    q.push(make_pair(i + row[k], j + column[k]));
                    mat[i + row[k]][j + column[k]] = 'Y';
                }
            }
        }
        
        // Replace all 'O' with 'X' and all 'Y' with 'O'
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (mat[i][j] == 'Y')
                    mat[i][j] = 'O';
                
                else if (mat[i][j] == 'O')
                    mat[i][j] = 'X';
            }
        }
        
        return mat;
    }
};
```

### Code Explanation

The solution utilizes BFS to traverse and mark the 'O's connected to the boundary. These 'O's are temporarily marked as 'Y' to differentiate them from the 'O's that need to be changed to 'X'. After the BFS traversal, the marked 'Y's are converted back to 'O', and the remaining 'O's are changed to 'X'.

#### Detailed Steps

1. **Initialization**:
   - The number of rows (`r`) and columns (`c`) are set.
   - Two arrays, `row` and `column`, are defined to represent the four possible directions (up, down, left, right).

2. **Mark Boundary-Connected 'O's**:
   - Iterate through the first row, last column, last row, and first column to find 'O's. For each 'O' found, push its coordinates into the queue and mark it as 'Y'.

3. **BFS Traversal**:
   - Perform BFS starting from each 'Y' marked boundary 'O'. For each cell, check its four neighbors. If a neighbor is valid and is 'O', mark it as 'Y' and push its coordinates into the queue.

4. **Final Replacement**:
   - After BFS, iterate through the matrix. Change all 'Y's back to 'O' and change all remaining 'O's to 'X'.

### Time Complexity

The time complexity of this algorithm is O(n x m), where n is the number of rows and m is the number of columns. This is because:
- Each cell is visited once when marking boundary 'O's.
- Each cell is visited again during the BFS traversal.
- Each cell is visited one last time during the final replacement step.

### Space Complexity

The space complexity is also O(n x m) due to the space used by the queue in BFS, which in the worst case can hold all the cells in the matrix if they are all 'O's and connected to the boundary.

### Auxiliary Space Complexity

The auxiliary space complexity, excluding the input matrix, is O(n x m) due to:
- The queue used for BFS.

### Summary

Your code effectively transforms the matrix by identifying and protecting the 'O's connected to the boundary, ensuring that only the enclosed 'O's are changed to 'X'. The BFS ensures that each relevant 'O' is checked and marked in linear time, making the solution efficient for the given problem.