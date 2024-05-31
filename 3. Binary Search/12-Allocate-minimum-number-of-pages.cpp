#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        // If number of students > number of books
        if (M > N) return -1;
        
        // Initial Range = [start, end]
        int start = 0, end = 0;
        int answer;
        
        for (int i = 0; i < N; i++)
        {
            start = max(start, A[i]);
            end += A[i];
        }
        
        // Binary Search
        while (start <= end)
        {
            int mid = (end - start) / 2 + start;
            
            int count = 1, pages = 0;
            for (int i = 0; i < N; i++)
            {
                pages += A[i];
                
                if (pages > mid)
                {
                    count++;
                    pages = A[i];
                }
            }
            
            if (count <= M)
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