#include <bits/stdc++.h>
using namespace std;

//* Method 1 *//
class Solution 
{
    public: 
    void insert(int arr[], int i)
    {
        int temp = arr[i--]; // Temporarily storing element in a variable
        
        // Putting temp variable at it's correct position
        while (i >= 0 and arr[i] > temp)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        
        arr[i + 1] = temp;
    }
    
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        // Total number of passes = n - 1
        for (int i = 1; i < n; i++)
        {
            insert(arr, i);
        }
    }
};

//* Method 2 *//
class Solution
{
    public:

    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        // Total number of passes = n - 1
        for (int i = 1; i < n; i++)
        {
            int temp = arr[i]; // Temporarily storing element in a variable
            
            int j = i - 1; 
            
            // Putting temp variable at it's correct position
            while (j >= 0 and arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            
            arr[j + 1] = temp;
        }
    }
};