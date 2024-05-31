#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int n = weights.size();
        int start = 0, end = 0;
        int answer;

        for (int i = 0; i < n; i++)
        {
            start = max(start, weights[i]);
            end += weights[i];
        }

        while (start <= end)
        {
            int mid = (end - start) / 2 + start;

            int count = 1, vajan = 0;
            for (int i = 0; i < n; i++)
            {
                vajan += weights[i];

                if (vajan > mid)
                {
                    count++;
                    vajan = weights[i];
                }
            }

            if (count <= days)
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