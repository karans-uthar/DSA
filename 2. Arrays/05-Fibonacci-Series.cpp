#include <bits/stdc++.h>
using namespace std;

// nth fibonacci series
int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    int arr[1000] = {0};

    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i < n; i++)
    arr[i] = arr[i - 1] + arr[i - 2];

    cout << "nth fibonacci series: " << arr[n - 1] << endl;
}