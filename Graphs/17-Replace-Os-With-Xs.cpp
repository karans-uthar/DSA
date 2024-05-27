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