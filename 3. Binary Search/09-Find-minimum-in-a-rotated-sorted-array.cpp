#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findMin(int arr[], int n)
    {
        int start = 0, end = n - 1;
        int answer = arr[0];
        
        while (start <= end)
        {
            int mid = (end - start) / 2 + start;
            
            if (arr[mid] > arr[n - 1])
            start = mid + 1;
            
            else if (arr[mid] <= arr[n - 1])
            {
                answer = arr[mid];
                end = mid - 1;
            }
        }
        
        return answer;
    }
};