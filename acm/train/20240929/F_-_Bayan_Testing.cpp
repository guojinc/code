#include <bits/stdc++.h>
#include <algorithm>
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

struct seg
{
    int len;
    pii p;
    bool operator<(const seg &a) const
    {
        return len > a.len;
    }
};


void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> ans(n + 1, 0);
    vector<seg> v;
    int cnt = 0;
    for (int i = 0; i < m * 2; i++)
    {
        int l, r;
        cin >> l >> r;
        if (l == r)
        {
            cnt++;
            continue;
        }
        int len = r - l + 1;
        seg s;
        s.len = len;
        s.p = {l, r};
        v.push_back(s);
    }
    
    if (cnt > m)
    {
        cout << -1 << endl;
        return;
    }
    // if (cnt == m)
    // {
    //     for (int i = 1; i <= n; i++)
    //     {
    //         cout << 1 << " ";
    //     }
    //     cout << endl;
    //     return;
    // }
    sort(all(v));

    int len = v.size();
    int k = 1;
    map<int, vector<int>> mp;
    int arr[n + 1][2] = {0};
    for (int i = 0; i < m; i++)
    {
        int l = v[i].p.first;
        int r = v[i].p.second;
        if (ans[l] == 0 && ans[r] == 0){
            ans[l] = k;
            ans[r] = k;
            mp[k].push_back(l);
            mp[k].push_back(r);
            arr[l][0] = r;
            arr[r][1] = l;
            k++;
        } else if (ans[l] != 0 && ans[r] == 0){
            ans[r] = ans[l];
            ans[arr[l][0]] = 0;
            arr[l][0] = r;
            mp[ans[l]].push_back(r);
        } else if (ans[l] == 0 && ans[r] != 0){
            ans[l] = ans[r];
            ans[arr[r][1]] = 0;
            arr[r][1] = l;
            mp[ans[r]].push_back(l);
        } else if (ans[l] == ans[r] && ans[l] != 0){
            continue;
        } else {
            int x = ans[l];
            int y = ans[r];
            if (arr[l][0] != 0 && arr[l][0] > r)
            {
                ans[arr[l][0]] = 0;
                arr[l][0] = r;
            }
            if (arr[r][1] != 0 && arr[r][1] < l)
            {
                ans[arr[r][1]] = 0;
                arr[r][1] = l;
            }

            for (int j = 0; j < mp[y].size(); j++)
            {
                if (ans[mp[y][j]] == 0)
                    continue;
                ans[mp[y][j]] = x;
                mp[x].push_back(mp[y][j]);
            }
            for (auto& iter : mp[x])
            {
                if (iter == 0)
                {
                    remove(mp[x].begin(), mp[x].end(), iter);
                    break;
                }
            }
            mp[y].clear();
        }
        
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == 0)
        {
            ans[i] = ++k;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
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