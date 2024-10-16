#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int l = n / 4;
    int init[4][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
        {12, 13, 14, 15}
    };
    int res[n][n];
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                for (int m = 0; m < 4; m++)
                {
                    res[i * 4 + k][j * 4 + m] = init[k][m] + 16 * (i * l + j);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}