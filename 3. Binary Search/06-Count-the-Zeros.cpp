#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    // First occurence of zero in an array
    int firstOccurenceOfZero(int arr[], int n)
    {
        int start = 0, end = n - 1;
        int first = -1;
        
        while (start <= end)
        {
            int mid = (end - start) / 2 + start;
            
            if (arr[mid] == 0)
            {
                first = mid;
                end = mid - 1;
            }
            
            else if (arr[mid] == 1)
            start = mid + 1;
        }
        
        return first;
    }
    
    int countZeroes(int arr[], int n) 
    {
        // code here
        int first = firstOccurenceOfZero(arr, n);
        
        return first != -1 ? n - first : 0;
    }
};