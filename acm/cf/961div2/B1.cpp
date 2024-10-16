#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    map<int, int> mp;
    int n, k;
    cin >> n >> k;
    while (n--)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    int ans = 0;
    int cnt = 0;
    for (auto i : mp)
    {
        if (mp.find(i.first + 1) == mp.end())
        {
            cnt = i.second * i.first;
        }
        else{
            cnt = i.second * i.first + mp[i.first + 1] * (i.first + 1);
        }
        if (cnt <= k)
        {
            ans = max(ans, cnt);
        }
        else {
            int len = i.second + mp[i.first + 1];
            int arr[len];
            for (int j = 0; j < len; j++)
            {
                arr[j] = i.first;
                if (j >= i.second)
                {
                    arr[j] = i.first + 1;
                }
            }
            int l = 0;
            int r = 0;
            int cal = 0;
            while (l < len)
            {
                while (r < len && cal < k)
                {
                    cal += arr[r];
                    r++;
                }
                if (cal == k)
                {
                    ans = k;
                    cout << k << endl;
                    return;
                }
                cal -= arr[l];
                ans = max(ans, cal);
                l++;
            }
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