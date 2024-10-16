#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define pii pair<int, int>
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(),a.end()
#define bg begin()
#define ed end()
#define mod 998244353
#define mod7 1e9 + 7
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int a[3];
    int b[3];
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    int ans = 0;
    ans += min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
    a[0] -= b[1];
    a[1] -= b[2];
    a[2] -= b[0];
    for (int i = 0; i < 3; i++)
    {
        if (a[i] < 0 && a[(i + 2) % 3] > 0)
        {
            ans -= min(abs(a[i]), a[(i + 2) % 3]);
        }
    }
    cout << ans << endl;
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