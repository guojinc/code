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
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, a[i]);
    }
    cout << n - ans << endl;
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