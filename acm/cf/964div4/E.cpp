
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector <int> powof3(16, 0);

void solve()
{
    int l, r;
    cin >> l >> r;
    int low = lower_bound(powof3.begin(), powof3.end(), l) - powof3.begin();
    int up = upper_bound(powof3.begin(), powof3.end(), r) - powof3.begin() - 1;
    int ans = 0;
    for (int i = low; i < up; i++)
    {
        ans += (powof3[i + 1] - powof3[i]) * i;
    }
    if (low > up)
    {
        ans += (r - l + 2) * up;
        cout << ans << endl;
        return;
    }
    if (l < powof3[low])
    {
        ans += (powof3[low] - l + 1) * (low - 1);
    }
    else{
        ans += low;
    }
    if (r >= powof3[up])
    {
        ans += (r - powof3[up] + 1) * up;
    }
    cout << ans << endl;
}

signed main()
{
    ios
    int t;
    cin >> t;
    powof3[1] = 1;
    for (int i = 2; i < powof3.size(); i++)
    {
        powof3[i] = powof3[i - 1] * 3;
    }
    while (t--)
    {
        solve();
    }
}