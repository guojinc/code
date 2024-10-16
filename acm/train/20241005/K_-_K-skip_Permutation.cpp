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
    vector<int> a;
    if (k >= n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << i + 1;
            if (i != n - 1)
                cout << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= k; i++)
    {
        int j = i;
        a.push_back(j);
        j += k;
        while (j <= n)
        {
            a.push_back(j);
            j += k;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (i != n - 1)
            cout << " ";
    }
}

signed main()
{
    ios
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}