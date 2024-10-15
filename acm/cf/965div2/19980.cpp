#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define pair<signed, signed> pii
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    if (k == 1)
    {
        cout << x << " " << y << endl;
        return;
    }
    if (k % 2)
    {
        cout << x << " " << y << endl;
        for (int i = 1; i < k; i += 2)
        {
            cout << x - i << " " <<  y << endl;
            cout << x + i << " " <<  y << endl;
        }
    }
    else
    {
        for (int i = 1; i < k; i += 2)
        {
            cout << x - i << " " <<  y << endl;
            cout << x + i << " " <<  y << endl;
        }
    }
}

signed main()
{
    ios
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}