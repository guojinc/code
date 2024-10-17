#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (n * m % 2)
    {
        cout << "No" << endl;
        return;
    }
    if (b)
    {
        cout << "Yes" << endl;
    }
    else {
        if (a == 1 && (n == 1 || m == 1))
        {
            cout << "Yes" << endl;
            return;
        }
        if (a == 0 && n * m == 2)
        {
            cout << "Yes" << endl;
            return;
        }
        cout << "No" << endl;
    }
}

signed main()
{
    ios
    int t;
    cin >> t;
    while (t--)
    {
        solve();       
    }
}