#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define inf 0x3f3f3f3f
#define MAXN 200050
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = n * (n + 1) / 2;
    int sum = 0;
    int red = 0;
    for (int i = n; i >= 1; i--)
    {
        sum += a[i];
        if (sum > k)
        {
            red += i;
            sum = 0;
        }
    }

    cout << ans - red << endl;
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