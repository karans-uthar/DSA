#include <iostream>
using namespace std;

int main()
{
    int r, c;

    cout << "Enter rows: ";
    cin >> r;

    cout << "Enter columns: ";
    cin >> c;

    cout << "\nPrinting Pattern" << endl;
    cout << "----------------" << endl;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << "* ";
        
        cout << endl;
    }
}