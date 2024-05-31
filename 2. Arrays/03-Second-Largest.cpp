#include <bits/stdc++.h>
using namespace std;

//User function template for C++
class Solution{
public:	

    // Function return the largest element in the array
    int printLargest(int arr[], int n)
    {
        int maxEle = -1;
	    for(int i = 0; i < n; i++)
	    {
	        if(arr[i] > maxEle)
	            maxEle = arr[i];
	    }
	    
	    return maxEle;
    }
    
	// Function returns the second largest element in the array
	int print2largest(int arr[], int n) 
	{
	    // code here
	    int maxElement = printLargest(arr, n);
	    int secondMax = -1;
	    
	    for(int i = 0; i < n; i++)
	    {
	        if(arr[i] != maxElement)
	        {
	            secondMax = max(secondMax, arr[i]);
	        }
	        
	        /*
	        if(arr[i] != maxElement && arr[i] > secondMax)
	        {
	            secondMax = arr[i];
	        }
	        */
	    }
	    
	    return secondMax;
	}
};