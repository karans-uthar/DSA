#include <iostream>
using namespace std;

int main ()
{
    int A[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int n = sizeof(A) / sizeof(int); // size of an array

    cout << "Before Reversal: ";
    for (int i = 0; i < n; i++)
    cout << A[i] << " ";

    // Reverse an Array
    int i = 0, j = n - 1;

    while (i < j)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;

        i++;
        j--;
    }

    cout << "\nAfter Reversal: ";
    for (int i = 0; i < n; i++)
    cout << A[i] << " ";
}