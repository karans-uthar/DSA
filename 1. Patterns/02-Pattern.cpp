#include <iostream>
using namespace std;

int main()
{
    int r, c, num;

    cout << "Enter rows and columns: ";
    cin >> r >> c;

    cout << "Enter the number: ";
    cin >> num;

    cout << "\nPrinting Pattern" << endl;
    cout << "----------------" << endl;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
            cout << num << " ";
        
        cout << endl;
    }
}