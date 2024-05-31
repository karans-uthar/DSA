#include <bits/stdc++.h>
using namespace std;

//* Method 1 *//
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        long long int start = 0, end = x;
        
        while (start <= end)
        {
            long long int mid = (end - start) / 2 + start;
            
            if (mid * mid == x)
            return mid;
            
            else if (mid * mid < x)
            start = mid + 1;
            
            else
            end = mid - 1;
        }
        
        return start - 1;
    }
};

//* Method 2 *//
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        long long int start = 0, end = x;
        int answer = 0;
        
        while (start <= end)
        {
            long long int mid = (end - start) / 2 + start;
            
            if (mid * mid == x)
            {
                answer = mid;
                break;
            }
            
            else if (mid * mid < x)
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