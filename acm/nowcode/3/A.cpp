#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


map<int, int, greater<int>> mp;
int rem = 0;

int dfs(int l, int n)
{
    int ret = 0;
    while (mp[0] != n)
    {
        int cnt = 0;
        auto it = mp.begin();
        while (mp.size() != 1)
        {
            if (cnt + it->second >= l)
            {
                it->second -= l - cnt;
                mp[it->first - 1] += l - cnt;
                ret++;
                if (it->second == 0)
                {
                    mp.erase(it);
                }
                break;
            }
            else
            {
                cnt += it->second;
                int tmp = it->second;
                int tmp1 = it->first;
                auto it1 = it;
                int next = (++it1)->first;
                mp.erase(it);
                it = mp.find(next);
                mp[tmp1 - 1] += tmp;
            }
        }    
    }
    return ret;
}


void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        v[i] = (v[i] + 1) / 2;
        mp[v[i]]++;
    }
    // sort(v.begin() + 1, v.end());
    if (mp[1] == n)
    {
        cout << "YES" << endl;
        return;
    }
    
    // int a0 = 0;
    // int a = v[pos];
    int len = mp[1];
    int k = dfs(l, n - len);

    if (k * (r - l) >= len)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

signed main()
{
    ios
    solve();
}