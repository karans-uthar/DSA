# Covid Spread 

### Problem Explanation

1. **Input**: A 2D grid `hospital` where:
   - `0` represents an empty room.
   - `1` represents a healthy patient.
   - `2` represents an infected patient.
   
2. **Output**: The minimum time (in units) required for all healthy patients to become infected. If it's impossible to infect all patients, return `-1`.

### Algorithm

The algorithm uses Breadth-First Search (BFS) to simulate the spread of the infection. BFS is suitable here as it processes nodes layer by layer, which corresponds to processing the spread of infection step by step.

1. **Initialization**:
   - Use a queue to store the coordinates of all initially infected patients.
   - Track the size of the grid.
   
2. **BFS Process**:
   - For each infected patient, check its adjacent cells.
   - If an adjacent cell contains a healthy patient, mark it as infected and add it to the queue.
   - Increment the timer after processing all currently infected patients for the current step.
   
3. **Termination**:
   - The process continues until there are no more patients to infect (i.e., the queue is empty).
   - After the BFS completes, check if there are any remaining healthy patients. If so, return `-1`.
   - Otherwise, return the timer minus one (since the timer is incremented one extra time after the last infection).

### Complexity Analysis

#### `Time Complexity`
- **Initialization**: \(O(r \times c)\), where \(r\) is the number of rows and \(c\) is the number of columns, for scanning the grid to find initially infected patients.
- **BFS Traversal**: Each cell is processed at most once, leading to \(O(r \times c)\) complexity for the BFS traversal.

Overall, the time complexity is \(O(r \times c)\).

#### `Space Complexity`
- **Queue**: At most \(O(r \times c)\) elements (worst case if all cells are infected or become infected).
- **Grid Storage**: The grid itself occupies \(O(r \times c)\) space.

Overall, the space complexity is \(O(r \times c)\).

#### `Auxiliary Space Complexity`
Auxiliary space refers to the extra space used by the algorithm excluding the input:
- The queue, used for BFS traversal, can hold up to \(r \times c\) elements.
- Additional space for the direction arrays and possibly recursion stack (if a recursive version were used).

Overall, the auxiliary space complexity is \(O(r \times c)\).

### C++ Code

``` C++
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
```

### Code Comparison

Both methods (Method 1 and Method 2) implement the BFS approach with slight differences in handling directions and boundary checks:

- **Method 1**: Directly checks each of the four possible directions within the BFS loop.
- **Method 2**: Uses helper functions and direction arrays to streamline boundary checks and movement logic.

Both methods have similar time and space complexities and efficiently solve the problem using BFS. The choice between them may come down to code readability and preference for using helper functions to encapsulate logic.