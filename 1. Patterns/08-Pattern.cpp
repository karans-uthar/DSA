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
        for (int j = 1; j <= c; j++)
            cout << char('a' + j - 1) << " ";
        
        cout << endl;
    }
}