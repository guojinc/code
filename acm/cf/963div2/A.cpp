#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt_a = 0;
    int cnt_b = 0;
    int cnt_c = 0;
    int cnt_d = 0;
    for (int i = 0; i < n * 4; i++)
    {
        if (s[i] == 'A')
        {
            cnt_a++;
        }
        if (s[i] == 'B')
        {
            cnt_b++;
        }
        if (s[i] == 'C')
        {
            cnt_c++;
        }
        if (s[i] == 'D')
        {
            cnt_d++;
        }
    }
    int ans = 0;
    if (cnt_a <= n)
    {
        ans += cnt_a;
    }
    else
    {
        ans += n;
    }
    if (cnt_b <= n)
    {
        ans += cnt_b;
    }
    else
    {
        ans += n;
    }
    if (cnt_c <= n)
    {
        ans += cnt_c;
    }
    else
    {
        ans += n;
    }
    if (cnt_d <= n)
    {
        ans += cnt_d;
    }
    else
    {
        ans += n;
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