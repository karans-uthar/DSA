#include <bits/stdc++.h>
using namespace std;

//* Method 1 *//
class Solution 
{
    public:

    int helpaterp(vector<vector<int>> hospital)
    {
        // BFS
        queue< pair<int, int> > q;
        int timer = 0;
        
        // Pushing all infected patients
        int rows = hospital.size();
        int columns = hospital[0].size();
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (hospital[i][j] == 2)
                    q.push(make_pair(i, j));
            }
        }
        
        // Determining units of time
        while (!q.empty())
        {
            int n = q.size(); // n = Current Patients
            
            while (n--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if (x > 0 and hospital[x - 1][y] == 1)
                {
                    hospital[x - 1][y] = 2;
                    q.push(make_pair(x - 1, y));
                }
                
                if (y < columns - 1 and hospital[x][y + 1] == 1)
                {
                    hospital[x][y + 1] = 2;
                    q.push(make_pair(x, y + 1));
                }
                
                if (x < rows - 1 and hospital[x + 1][y] == 1)
                {
                    hospital[x + 1][y] = 2;
                    q.push(make_pair(x + 1, y));
                }
                
                if (y > 0 and hospital[x][y - 1] == 1)
                {
                    hospital[x][y - 1] = 2;
                    q.push(make_pair(x, y - 1));
                }
            }
            
            timer++;
        }
        
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                if (hospital[i][j] == 1)
                    return -1;
        
        return timer - 1;
    }
};

//* Method 2 *//
class Solution 
{
    public:
    
    // Data Members
    int r;
    int c;

    // Member Functions
    bool valid(int i, int j)
    {
        return (i >= 0 and i < r) && (j >= 0 and j < c);
    }

    int helpaterp(vector<vector<int>> hospital)
    {
        // BFS
        queue< pair<int, int> > q;
        int timer = 0;
        
        // r and c both declared globally
        r = hospital.size();
        c = hospital[0].size();
        
        // Boundaries
        int row[4] = {-1, 0, 1, 0};
        int column[4] = {0, 1, 0, -1};
        
        // Pushing all infected patients
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (hospital[i][j] == 2)
                    q.push(make_pair(i, j));
            }
        }
        
        // Determining units of time
        while (!q.empty())
        {
            int n = q.size(); // n = Current Patients
            
            while (n--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for (int k = 0; k < 4; k++)
                {
                    if (valid(x + row[k], y + column[k]) and hospital[x + row[k]][y + column[k]] == 1)
                    {
                        hospital[x + row[k]][y + column[k]] = 2;
                        q.push(make_pair(x + row[k], y + column[k]));
                    }
                }
            }
            
            timer++;
        }
        
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (hospital[i][j] == 1)
                    return -1;
        
        return timer - 1;
    }
};