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
    int n, m, q;
    cin >> n >> m >> q;
    int arr[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    int MIN = min(arr[0], arr[1]);
    int MAX = max(arr[0], arr[1]);
    int pos;
    cin >> pos;
    if (pos < MIN)
    {
        cout << MIN - 1 << endl;
        return;
    }
    if (pos > MAX)
    {
        cout << n - MAX << endl;
        return;
    }
    cout << (MAX - MIN) / 2 << endl;
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