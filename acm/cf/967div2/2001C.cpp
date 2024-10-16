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

int query(int a, int b)
{
    cout << "? " << a << " " << b << endl;
    cout.flush();
    int x;
    cin >> x;
    if (x == -1)
    {
        exit(0);
    }
    return x;
}

void dfs(int l, int r, set<pii>& g, set<pii>& q)
{
    // if (l == r)
    // {
    //     return;
    // }
    if (q.find({l, r}) != q.end())
    {
        return;
    }
    if (q.find({r, l}) != q.end())
    {
        return;
    }
    q.insert({l, r});
    q.insert({r, l});
    int ret = query(l, r);
    if (ret == l)
    {
        g.insert({l, r});
        return;
    }
    // dfs(l, ret, g, q);
    dfs(ret, r, g, q);
}

void solve()
{
    int n;
    cin >> n;
    set<pii> g, q;
    for (int i = 2; i <= n; i++)
    {
        dfs(1, i, g, q);
    }
    cout << "! ";
    for (auto p : g)
    {
        cout << p.first << " " << p.second << " ";
    }
    // for (int i = 1; i < n; i++)
    // {
    //     cout << g[i - 1].first << " " << g[i - 1].second << " ";
    // }
    cout << endl;
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