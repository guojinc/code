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
    vector<int> arr(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    sort(all(arr));
    while (q--)
    {
        int pos;
        cin >> pos;
        auto it = lower_bound(all(arr), pos);
        if (it == arr.end())
        {
            cout << n - arr.back() << endl;
            continue;
        }
        if (it == arr.begin())
        {
            cout << *it - 1 << endl;
            continue;
        }
        cout << (*it - *(it - 1)) / 2 << endl;
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