#include <bits/stdc++.h>
using namespace std;

//* Method 1: Bubble Sort *//
class Solution 
{
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n) 
    {
        // Total number of passes = n - 1
        for (int i = 0; i < n - 1; i++)
        {
            // Putting largest element in the end of the unsorted array or beginning of the sorted array
            for (int j = 0; j < n - 1 - i; j++)
            if (arr[j] > arr[j + 1])
            swap(arr[j], arr[j + 1]);
        }
    }
};

//* Method 2: Modified Bubble Sort *//
class Solution 
{
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n) 
    {
        // Total number of passes = n - 1
        for (int i = 0; i < n - 1; i++)
        {
            bool sorted = true;
             
            // Putting largest element in the end of the unsorted array or beginning of the sorted array
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    sorted = false;
                }
            }
            
            // If array if already sorted then stop everything
            if (sorted == true)
                break;
        }
    }
};