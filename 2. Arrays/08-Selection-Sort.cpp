#include <bits/stdc++.h>
using namespace std;

//* Method 1 *//
class Solution
{
    public:
    
    int n; // Declaring variable n globally
    
    // Function to find index of minimum element in an unsorted array
    int select(int arr[], int i)
    {
        // To select index of minimum element in the unsorted array
        int minIndex = i - 1;
        
        for (; i < n; i++)
        if (arr[i] < arr[minIndex])
        minIndex = i;
        
        return minIndex;
    }
    
    void selectionSort(int arr[], int n)
    {
        // Code Here
        this -> n = n;
        
        // Total number of passes = n - 1
        for (int i = 0; i < n; i++)
        {
            int minIndex = select(arr, i + 1);

            swap(arr[i], arr[minIndex]);
        }
        
        return;
    }
};

//* Method 2 *//
class Solution
{
    public: 
    
    void selectionSort(int arr[], int n)
    {
        // Total number of passes = n - 1
        for (int i = 0; i < n - 1; i++)
        {
            int minIndex = i;
            
            // Loop to find index of minimum element in an unsorted array
            for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
            minIndex = j;
            
            swap(arr[i], arr[minIndex]);
        }
    }
};