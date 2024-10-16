#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int mod = 1e9 + 7;

void solve()
{
    string s;
    cin >> s;
    map<int, vector<int>> mp;
    map<int, vector<int>> mps;
    int x = 0;
    int arr[s.size()];
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            x++;
        }
        if (s[i] == '0')
        {
            x--;
        }
        arr[i] = x;
        mp[x].push_back(i);
        if (mps[x].size() == 0)
        {
            mps[x].push_back(0);
        }
        mps[x].push_back(s.size() - i);
    }
    for (auto& i : mps)
    {
        for (int j = i.second.size() - 2; j > 0; j--)
        {
            i.second[j] += i.second[j + 1];
        }
    }
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int cnt = 0;
        if (s[i] == '1')
        {
            int find = arr[i] - 1;
            auto it = lower_bound(mp[find].begin(), mp[find].end(), i) - mp[find].begin();
            // for (int j = it; j < mp[find].size(); j++)
            // {
            //     cnt += s.size() - mp[find][j];
            // }
            // cnt = mps[find][it];
            if (it == mp[find].size())
            {
                continue;
            }
            cnt = mps[find][it + 1];
            ans += (cnt * (i + 1)) % mod;
            ans %= mod;
        }
        if (s[i] == '0')
        {
            int find = arr[i] + 1;
            auto it = lower_bound(mp[find].begin(), mp[find].end(), i) - mp[find].begin();
            // for (int j = it; j < mp[find].size(); j++)
            // {
            //     cnt += s.size() - mp[find][j];
            // }
            if (it == mp[find].size())
            {
                continue;
            }
            cnt = mps[find][it + 1];
            ans += (cnt * (i + 1)) % mod;
            ans %= mod;
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