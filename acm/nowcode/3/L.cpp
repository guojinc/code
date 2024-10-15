#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int n, m;
    n = -1;
    m = -1;
    char c;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            c = getchar();
            if (c == '8' && n == -1 && m == -1 && i > 0 && j > 0 && i < 8 && j < 8)
            {
                n = i;
                m = j;
            }
        }
        getchar();
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (i == n && j == m)
            {
                cout << 8;
            }
            else
            {
                cout << '*';
            }
        }
        cout << endl;
    }
}

signed main()
{
    ios
    solve();
}