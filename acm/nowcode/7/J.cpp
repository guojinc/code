
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int l, x, y;
    cin >> l >> x >> y;
    if (x * x + y * y > l * l)
    {
        cout << "No" << endl;
        return;
    }
    else{
        cout << "Yes" << endl << "0" << endl;
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