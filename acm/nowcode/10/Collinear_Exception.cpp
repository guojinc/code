#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define uint unsigned long long
#define pii pair<int, int>
#define umap unordered_map
#define uset unordered_set
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int n;
bool arr[1000 + 1][1000 + 1];
void check(vector<pii>& ps, pii p)
{
    if (arr[p.first][p.second])
    {
        cout << 0;
        return;
    }
    for (auto i : ps)
    {
        pii slope = {i.first - p.first, i.second - p.second};
        int g = __gcd(slope.first, slope.second);
        slope.first /= g;
        slope.second /= g;
        int x = p.first;
        int y = p.second;
        while (x <= n && x > 0 && y <= n && y > 0)
        {
            arr[x][y] = true;
            x += slope.first;
            y += slope.second;
        }
        x = p.first;
        y = p.second;
        while (x <= n && x > 0 && y <= n && y > 0)
        {
            arr[x][y] = true;
            x -= slope.first;
            y -= slope.second;
        }
    }
    ps.push_back(p);
    cout << 1;
}

void solve()
{
    cin >> n;
    vector<pii> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x, y;
            cin >> x >> y;
            check(mp, {x, y});
        }
    }
    cout << endl;
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