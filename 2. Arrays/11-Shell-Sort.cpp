#include <bits/stdc++.h>
using namespace std;

void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Number of passes = n - 1
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i]; // Temporarily storing in a variable

            int j = i - gap;

            // Putting temp variable at it's correct position
            while (j >= 0 and arr[j] > temp)
            {
                arr[j + gap] = arr[j];
                j = j - gap;
            }

            arr[j + gap] = temp;
        }
    }
}

int main()
{
    int A[10] = {10, 1, 9, 2, 7, 3, 8, 4, 6, 5};
    int n = sizeof(A) / sizeof(int);

    shellSort(A, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    cout << A[i] << " ";
}