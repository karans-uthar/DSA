#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:	
    
    // First Position of Element in Sorted Array
    int firstOccurrence(int *Arr, int n, int key)
    {
        int low = 0, high = n - 1, first = -1;
        while(low <= high)
        {
            int mid = (high - low) / 2 + low;

            if (Arr[mid] == key)
            {
                first = mid;
                high = mid - 1;
            }

            else if(Arr[mid] < key)
                low = mid + 1;

            else 
                high = mid - 1;
        }

        return first;
    }
    
    // Last Position of Element in Sorted Array
    int lastOccurrence(int *Arr, int n, int key)
    {
        int low = 0, high = n - 1, last = -1;
        while(low <= high)
        {
            int mid = (high - low) / 2 + low;
            
            if (Arr[mid] == key)
            {
                last = mid;
                low = mid + 1;
            }

            else if(Arr[mid] < key)
                low = mid + 1;

            else // Arr[mid] > key
                high = mid - 1;
        }

        return last;
    }
    
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) 
	{
	    // Code Here
	    int first = firstOccurrence(arr, n, x);
	    int last = lastOccurrence(arr, n, x);
	    
	   // if(first == -1)
	   //     return 0;
	    
	   // return last - first + 1;
	   
	   return first != -1 ? last - first + 1 : 0;
	}
};