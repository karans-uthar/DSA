#include <bits/stdc++.h>
using namespace std;

// User function template for C++

class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        // Your code goes here
        int originalSum = 0, expectedSum = n * (n + 1) / 2;
        
        for(int i = 0; i < n - 1; i++)
        {
            originalSum += array[i];
        }
        
        return (expectedSum - originalSum);
    }
};