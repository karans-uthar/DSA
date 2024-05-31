#include <bits/stdc++.h>
using namespace std;

//* Method 1 *//
class Solution
{
    public:
    // Find first occurence of element in an sorted array
    int firstOccurence(int arr[], int n, int x)
    {
        int start = 0, end = n - 1;
        
        while (start <= end)
        {
            int mid = (end - start) / 2 + start;
            
            if (arr[mid] == x)
            {
                if (mid == 0 or arr[mid - 1] != arr[mid])
                return mid;
                
                else
                end = mid - 1;
            }
            
            else if (arr[mid] < x)
            start = mid + 1;
            
            else
            end = mid - 1;
        }
        
        return -1;
    }
    
    // Find last occurence of element in an sorted array
    int lastOccurence(int arr[], int n, int x)
    {
        int start = 0, end = n - 1;
        
        while (start <= end)
        {
            int mid = (end - start) / 2 + start;
            
            if (arr[mid] == x)
            {
                if (mid == n - 1 or arr[mid + 1] != arr[mid])
                return mid;
                
                else
                start = mid + 1;
            }
            
            else if (arr[mid] < x)
            start = mid + 1;
            
            else
            end = mid - 1;
        }
        
        return -1;
    }
    
    // Function to find both first and last occurence of element in an sorted array
    vector<int> find(int arr[], int n , int x)
    {
        // Code Here
        int first = firstOccurence(arr, n, x);
        int last = lastOccurence(arr, n, x);
        
        vector<int> answer;
        answer.push_back(first);
        answer.push_back(last);
        
        return answer;
    }
};

//* Method 2 *//
class Solution
{
    public:
    // Find first occurence of element in an sorted array
    int firstOccurence(int arr[], int n, int x)
    {
        int start = 0, end = n - 1;
        int first = -1;
        
        while (start <= end)
        {
            int mid = (end - start) / 2 + start;
            
            if (arr[mid] == x)
            {
                first = mid;
                end = mid - 1;
            }
            
            else if (arr[mid] < x)
            start = mid + 1;
            
            else
            end = mid - 1;
        }
        
        return first;
    }
    
    // Find last occurence of element in an sorted array
    int lastOccurence(int arr[], int n, int x)
    {
        int start = 0, end = n - 1;
        int last = -1;
        
        while (start <= end)
        {
            int mid = (end - start) / 2 + start;
            
            if (arr[mid] == x)
            {
                last = mid;
                start = mid + 1;
            }
            
            else if (arr[mid] < x)
            start = mid + 1;
            
            else
            end = mid - 1;
        }
        
        return last;
    }
    
    // Function to find both first and last occurence of element in an sorted array
    vector<int> find(int arr[], int n , int x)
    {
        // Code Here
        int first = firstOccurence(arr, n, x);
        int last = lastOccurence(arr, n, x);
        
        vector<int> answer;
        answer.push_back(first);
        answer.push_back(last);
        
        return answer;
    }
};