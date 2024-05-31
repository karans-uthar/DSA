// kth missing positive number

#include <bits/stdc++.h>
using namespace std;

// Method 1
class Solution {
public:
    /// Method 1: Brute Force
    //* TC: O(N)
    //* SC: O(1)
    int findKthPositive1(vector<int>& arr, int k) {
        int i = 0, j = 1, missing = 0, count = 0;
        //? i = Index of arr
        //? j = Natural number
        //? count = Count of missing number
        //? missing = Current missing number

        while(true)
        {
            if(j == arr[i]) {
                j++;
                i++;
            } else {
                count++;
                missing = j;
                j++;
            }

            if(count == k)
                break;
        }

        return missing;
    }

    /// Method 2: Brute Force
    //* TC: O(N)
    //* SC: O(1)
    int findKthPositive2(vector<int>& arr, int k) {
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] <= k)
                k++;
            else //? arr[i] > k
                break;
        }

        return k;
    }

    /// Method 3: Binary Search
    //* TC: O(logN)
    //* SC: O(1)
    int findKthPositive3(vector<int>& arr, int k) 
    {
        //* natural no.s    [1   2   3   4   5   6   7   8   9  10  11  12  13  14  15]
        //! ----------------------------------------
        //? index            0   1   2   3   4   5 
        //? arr[]           [2   3   4   7  11  12]    (k = 5)
        //? position        [1   2   3   4   5   6]
        //? ----------------------------------------
        //? missing         [1   1   1   3   6   6]    (Total missing number till position)
        //! ----------------------------------------
        //* missing number  [2   5   6   8   9  10  13  14  ...] 
        //* position 'j'    [1   2   3   4   5   6   7   8  ...] (jth missing number)

        int low = 0, high = arr.size() - 1, mid, ans = arr.size();

        while(low <= high)
        {
            mid = low + (high - low) / 2;

            if(arr[mid] - (mid + 1) >= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else 
                low = mid + 1;
        }

        //* return ans + k; (How ans + k?)

        int index = ans;
        return arr[index] - ((arr[index] - (index + 1)) - k + 1);
        //? arr[index]                       = Array element at index
        //? arr[index] - (index + 1)         = Total missing number till index
        //? arr[index] - (index + 1) - k + 1 = Required missing number
        //? -------------------------------------------------------------------
        //? arr[index] - ((arr[index] - (index + 1)) - k + 1)
        //? arr[index] - arr[index] + index + 1 + k - 1
        //? index + k
        //? ans + k 

        /*
        k = 5
        index = ans = 4
        arr[index] = 11
        arr[index] - (index + 1) = 6
        arr[index] - (index + 1) - k + 1 = 11 - 5 - 5 + 1
                                         = 2
        arr[index] - 1 = 11 - 2
                       = 9
        */     
    }
};

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of array: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cout << "Enter the kth missing positive number: ";
    cin >> k;

    Solution obj;
    cout << "\nThe kth missing positive number is," << endl;
    cout << "\tMethod 1:" << obj.findKthPositive1(arr, k) << endl;
    cout << "\tMethod 2:" << obj.findKthPositive2(arr, k) << endl;
    cout << "\tMethod 3:" << obj.findKthPositive3(arr, k) << endl;
}