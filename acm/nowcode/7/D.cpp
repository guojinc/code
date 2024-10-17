
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define umap unordered_map

bool is(map<int, int> a, map<int, int> &b, int k)
{
    for (auto i : b)
    {
        a[i.first] -= i.second;
    }
    for (auto i : a)
    {
        if (i.second % k != 0)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<map<int, int>> v(n + 2);
    v[0] = {};
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        v[i] = v[i - 1];
        v[i][m]++;
    }
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        int j = i + k;
        vector<int> cnt;
        int c = 0;
        while (j <= n + 1)
        {
            if (is(v[j - 1], v[i - 1], k))
            {
                if (c == 0) c++;
                else if (is(v[j - k - 1], v[i - 1], k)) c++;
                else {
                    cnt.emplace_back(c);
                    c = 1;
                    continue;
                }
            }
            if (j + k > n + 1) 
                cnt.emplace_back(c);           
            j += k;
        }
        for (int a = 0; a < cnt.size(); a++)
        {
            ans += cnt[a] * (cnt[a] + 1) / 2;
        }
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