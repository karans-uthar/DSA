#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long start = arr[0], end = 0;
        long long answer;
        
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > start)
            start = arr[i];
            
            end += arr[i];
        }
        
        while (start <= end)
        {
            long long mid = (end - start) / 2 + start;
            
            long long count = 1, boards = 0;
            for (int i = 0; i < n; i++)
            {
                boards += arr[i];
                
                if (boards > mid)
                {
                    count++;
                    boards = arr[i];
                }
            }
            
            if (count <= k)
            {
                answer = mid;
                end = mid - 1;
            }
            
            else
            start = mid + 1;
        }
        
        return answer;
    }
};