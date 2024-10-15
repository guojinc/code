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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int hold = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= k)
        {
            hold += a[i];
        }
        if (a[i] == 0 && hold > 0)
        {
            hold--;
            cnt++;
        }

    }
    cout << cnt << endl;
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