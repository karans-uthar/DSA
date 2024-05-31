#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int start = 0, end = nums.size() - 1;

        while (start <= end)
        {
            int mid = (end - start) / 2 + start;

            // If targeted element is found
            if (nums[mid] == target)
            return mid;

            // If targeted element is present at right of mid
            else if (nums[mid] < target)
            start = mid + 1;

            // If targeted element is present at left of mid
            else // nums[mid] > target
            end = mid - 1;
        }

        return -1;
    }
};