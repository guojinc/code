
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int n, s, m;
    cin >> n >> s >> m;
    int Max = 0;
    int ll = 0;
    int lr = 0;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        Max = max(Max, l - lr);
        ll = l;
        lr = r;
    }
    int l = m;
    Max = max(Max, l - lr);
    if (Max >= s)
    {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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