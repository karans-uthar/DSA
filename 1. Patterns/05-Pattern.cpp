#include <iostream>
using namespace std;

int main()
{
    int r, c;

    cout << "Enter rows and columns: ";
    cin >> r >> c;

    cout << "\nPrinting Pattern" << endl;
    cout << "----------------" << endl;

    for (int i = 1; i <= r; i++)
    {
        for (int j = c; j >= 1; j--)
            cout << j << " ";
        
        cout << endl;
    }
}