#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
typedef pair<int, int> pii;
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int row, col;
    row = col = 0;
    int n, m;
    cin >> n >> m;
    bool isrow, iscol;
    isrow = iscol = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == 'x' && !iscol)
            {
                col++;
            }
            if (c == 'x' && !isrow)
            {
                row++;
                isrow = true;
            }
        }
        if (col > 0)
        {
            iscol = true;
        }
        isrow = false;
    }
    int fact = __gcd(row, col);
    for (int i = 0; i < row / fact; i++)
    {
        for (int j = 0; j < col / fact; j++)
        {
            cout << "x";
        }
        cout << endl;
    }
}

signed main()
{
    ios
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}