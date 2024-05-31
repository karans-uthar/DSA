#include <bits/stdc++.h>
using namespace std;

//* Method 1 *//
class Solution {
    public:
    int cubeRoot(int N) 
    {
        // code here
        int start = 0, end = N;
        int answer = 0;
        
        while (start <= end)
        {
            long long int mid = (end - start) / 2 + start;
            
            if (mid * mid * mid == N)
            {
                answer = mid;
                break;
            }
            
            else if (mid * mid * mid < N)
            {
                answer = mid;
                start = mid + 1;
            }
            
            else
            end = mid - 1;
        }
        
        return answer;
    }
};

//* Method 2 *//
class Solution {
    public: 
    int cubeRoot(int N)
    {
        return cbrt(N);
    }
};