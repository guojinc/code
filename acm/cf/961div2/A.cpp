#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k == 0)
    {
        cout << 0 << endl;
        return;
    }
    int arr[n * 2];
    arr[0] = n;
    for (int i = 1; i < n * 2 - 1; i++)
    {
        arr[i] = (n - (i + 1) / 2);
    }
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n * 2 - 1; i++)
    {
        sum += arr[i];
        if (sum >= k)
        {
            ans = i;
            break;
        }
    }
    cout << ans + 1 << endl;
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