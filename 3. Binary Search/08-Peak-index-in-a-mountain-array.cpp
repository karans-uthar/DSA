#include <bits/stdc++.h>
using namespace std;

//* LeetCode *//
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int n = arr.size();
        int start = 0, end = n - 1;

        while (start <= end)
        {
            // int mid = (end - start) / 2 + start; // Runtime Error
            int mid = (start - end) / 2 + end;

            if (arr[mid - 1] < arr[mid] and arr[mid] > arr[mid + 1])
            return mid;

            else if (arr[mid - 1] < arr[mid]) // arr[mid] <= arr[mid + 1]
            start = mid + 1;

            else
            end = mid - 1;
        }

        return -1;
    }
};