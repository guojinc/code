#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAXN 200020
map<pair<int, int>, vector<int>> mp;

pair<int, int> sum[MAXN];
pair<int, int> next(pair<int, int> cur, char op)
{
    if (op == 'W')
    {
        cur.second++;
    }
    else if (op == 'S')
    {
        cur.second--;
    }
    else if (op == 'A')
    {
        cur.first--;
    }
    else if (op == 'D')
    {
        cur.first++;
    }
    return cur;
}

signed main()
{
    ios
    string s;
    int n, x, y;
    cin >> n >> x >> y;
    cin >> s;
    sum[0] = {0, 0};
    s = ' ' + s;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = next(sum[i - 1], s[i]);
        mp[sum[i]].push_back(i);
    }
    mp[{0, 0}].push_back(0);
    pair<int, int> cur = {0, 0};
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        pair<int, int> target = {cur.first + x, cur.second + y};
        if (mp.find(target) != mp.end())
        {
            auto pos = lower_bound(mp[target].begin(), mp[target].end(), i);
            if (pos != mp[target].end())
                ans += n - *pos + 1;
        }
        cur = next(cur, s[i]);
    }
    if (x == 0 && y == 0)
    {
        ans = n * (n + 1) / 2;
        cout << ans << endl;
        return 0;
    }
    cout << ans << endl;
}