#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        if (arr[i] > b) cnt1++;
        if (arr[i] == b) cnt2++;
    }
    ans = cnt1 + ceil(cnt2 / 2.0);
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