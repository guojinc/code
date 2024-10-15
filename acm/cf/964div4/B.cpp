
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int cnt = 0;
    if (a > c && b > d)
        cnt++;
    else if (a == c && b > d)
        cnt++;
    else if (a > c && b == d)
        cnt++;

    if (a > d && b > c)
        cnt++;
    else if (a == d && b > c)
        cnt++;
    else if (a > d && b == c)
        cnt++;
    
    cout << cnt * 2 << endl;
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