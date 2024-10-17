#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    map<int, int> mp;
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[arr[i]] = x;
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
            int a = i.second;
            int x = i.first;
            int b = 0;
            if (mp.find(i.first + 1) != mp.end())
            {
                b = mp[i.first + 1];
            }
            if (x * a >= k)
            {
                int re = k % x;
                int rema = k / x;
                int redu = min({re, rema, b});
                ans = max(ans, k - re + redu);
            }
            else {
                int rem = k - x * a;
                int re = rem % (x + 1);
                int remb = b - rem / (x + 1);
                int redu = min({re, remb, a});
                ans = max(ans, k - re + redu);
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