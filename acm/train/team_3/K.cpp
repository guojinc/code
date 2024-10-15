#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int t;
        cin >> t;
        if ((t / 2) % 2 == 1)
        {
            cout << "Pinkie Pie" << endl;
        }
        else
        {
            cout << "Fluttershy" << endl;
        }
    }
}