#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A[10] = {2, 4, 5, 1, 10, 3, 7, 6, 9, 8}; // Array 'A' of size 10

    int minElement = INT_MAX;
    int maxElement = INT_MIN;

    for (int i = 0; i < 10; i++)
    {
        if (A[i] < minElement)
            minElement = A[i];

        if (A[i] > maxElement)
            maxElement = A[i];
    }

    cout << "Minimun element in an array: " << minElement << endl;
    cout << "Maximum element in an array: " << maxElement << endl;
}