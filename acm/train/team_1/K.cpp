#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin >> t;
    t -= 1;
    ll ans = 1;
    const ll mod = 998244353;
    ll a = 2;
    while (t > 0)
    {
        if (t & 1)
        {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        t >>= 1;
    }
    printf("%lld", ans);
}