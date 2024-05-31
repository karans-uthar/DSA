#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int search(int A[], int l, int h, int key) 
    {
        // l: The starting index
        // h: The ending index, you have to search the key in this range

        // complete the function here
        int start = l, end = h;
        
        while (start <= end)
        {
            int mid = (end - start) / 2 + start;
            
            if (A[mid] == key)
            return mid;
            
            else if (A[mid] >= A[0])
            {
                if (A[l] <= key and key <= A[mid])
                end = mid - 1;
                
                else
                start = mid + 1;
            }
            
            else
            {
                if (A[mid] <= key and key <= A[h])
                start = mid + 1;
                
                else
                end = mid - 1;
            }
        }
        
        return -1;
    }
};