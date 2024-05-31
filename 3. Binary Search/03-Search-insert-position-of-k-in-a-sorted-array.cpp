#include <bits/stdc++.h>
using namespace std;

//* Method 1 *//
class Solution
{
    public:
    
    int searchInsertK(vector<int>arr, int n, int k)
    {
        // Code Here
        int start = 0, end = n - 1;
        
        while (start <= end)
        {
            int mid = (end - start) / 2 + start;
            
            if (arr[mid] == k)
            return mid;
                
            else if (arr[mid] < k)
            start = mid + 1;
            
            else
            end = mid - 1;
        }
        
        return start;
    }
};

//* Method 2 *//
class Solution
{
    public:
    
    int searchInsertK(vector<int>arr, int n, int k)
    {
        // Code Here
        int start = 0, end = n - 1;
        int answer = n;
        
        while (start <= end)
        {
            int mid = (end - start) / 2 + start;
            
            if (arr[mid] == k)
            {
                answer = mid;
                break;
            }
                
            else if (arr[mid] < k)
            start = mid + 1;
            
            else
            {
                answer = mid;
                end = mid - 1;
            }
        }
        
        return answer;
    }
};