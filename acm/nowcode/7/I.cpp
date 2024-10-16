
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int s(int x, int m, int k)
{
    int now = x;
    int mod = x % m;
    int div = x / m;
    int ret = 0;
    ret += x;
    ret += div * k;
    now = div * k + mod;
    while (now > m)
    {
        div = now / m;
        mod = now % m;
        ret += div * k;
        now = div * k + mod;
    }
    return ret;
}

void solve()
{
    double m, k, h;
    cin >> m >> k >> h;
    int ans = (h - k * h / m + k / m);
    int l = 0;
    int r = m;
    if (h == 0)
    {
        cout << 0 << endl;
        return;
    }
    while (1)
    {
        int tmp = ans;
        int add = (l + r) / 2;
        tmp += add;
        if (l == r || l + 1 == r)
        {
            cout << tmp << endl;
            return;
        }
        if (s(tmp, m, k) == h)
        {
            cout << tmp << endl;
            return;
        }
        else if (s(tmp, m, k) < h)
        {
            l = add;
        }
        else
        {
            r = add;
        }
        
    }
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