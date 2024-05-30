#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "\nPrinting Pattern" << endl;
    cout << "----------------" << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        cout << j << " ";
        
        cout << endl;
    }
}