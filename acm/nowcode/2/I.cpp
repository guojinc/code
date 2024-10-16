#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MaxN 3030


int arr[MaxN << 1];
struct{
    int val;
    vector<pair<int, int>> region;
} dp[MaxN << 1][MaxN << 1];
map<int, pair<int, int>> mp;

pair<bool, int> inRegion(vector<pair<int, int>>& region, int x)
{
    pair<bool, int> ret = {false, 0};
    int R = 0;
    for (auto [l, r] : region)
    {
        if (x >= l && x <= r)
        {
            ret.first = true;
            return ret;
        }
        if (x < l)
        {
            R += r - l + 1;
        }
    }
    for (auto it = region.rbegin(); it != region.rend(); it++)
    {
        if (x < it->first)
        {
            region.erase(it.base(), region.end());
            break;
        }
    }
    ret.second = R;
    return ret;
}

signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n * 2; i++)
    {
        cin >> arr[i];
        if (mp.find(arr[i]) == mp.end())
        {
            mp[arr[i]] = {i, -1};
        }
        else {
            mp[arr[i]].second = i;
        }
    }
    for (int i = 1; i <= n * 2; i++)
    {
        dp[i][i].val = 0;
    }
    int res = 0;
    for (int i = 1; i <= n * 2; i++)
    {
        for (int j = i + 1; j <= n * 2; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (mp[arr[j]].first < j && mp[arr[j]].first >= i)
            {
                int out1 = dp[i][mp[arr[j]].first - 1].val + arr[j] * (j - mp[arr[j]].first + 1);
                auto region = dp[i][j - 1].region;
                auto [flag, r] = inRegion(dp[i][j - 1].region, mp[arr[j]].first);
                int out2 = dp[i][j - 1].val + arr[j] + arr[j] * (j - mp[arr[j]].first + 1 - r);
                // if (dp[i][j].val < dp[i][mp[arr[j]].first - 1].val + arr[j] * (j - mp[arr[j]].first + 1))
                if (out1 >= out2)
                {
                    dp[i][j].val = dp[i][mp[arr[j]].first - 1].val + arr[j] * (j - mp[arr[j]].first + 1);
                    dp[i][j].region = dp[i][mp[arr[j]].first - 1].region;
                    dp[i][j].region.push_back({mp[arr[j]].first, j});
                }
                //else if (dp[i][j].val >= dp[i][mp[arr[j]].first - 1].val + arr[j] * (j - mp[arr[j]].first + 1))
                else {
                    if (!flag)
                    {
                        dp[i][j].val = dp[i][j - 1].val + arr[j] + arr[j] * (j - mp[arr[j]].first + 1 - r);
                        dp[i][j].region = dp[i][j - 1].region;
                        dp[i][j].region.push_back({mp[arr[j]].first, j});
                    }
                    else {
                        dp[i][j].val = out1;
                        dp[i][j].region = dp[i][mp[arr[j]].first - 1].region;
                        dp[i][j].region.push_back({mp[arr[j]].first, j});
                    }
                    dp[i][j - 1].region = region;
                }
            }
        }
        res = max(res, dp[i][n * 2].val);
    }
    cout << res << endl;
}
