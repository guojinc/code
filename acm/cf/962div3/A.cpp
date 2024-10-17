#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    ans += n / 4;
    if (n % 4 == 2)
    {
        ans++;
    }
    cout << ans << endl;
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