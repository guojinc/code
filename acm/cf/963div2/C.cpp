#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int n, k;
    cin >> n >> k;
    int l;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] < arr[0])
        {
            swap(arr[i], arr[0]);
        }
    }
    l = arr[0];
    int ans = 0;
    int L = 0;
    int R = k;
    for (int i = 1; i < n; i++)
    {
        int x = arr[i];
        x -= l;
        int mod = x % k;
        int div = x / k;
        if (div % 2)
        {
            if (mod == 0 && x != 0)
            {
                cout << -1 << endl;
                return;
            }
            if (mod == 0 && x == 0)
            {
                continue;
            }
            R = min(R, mod - 1);
            div++;
        }
        else
        {
            L = max(L, mod);
        }
        if (L > R)
        {
            cout << -1 << endl;
            return;
        }
        ans = max(ans, div);
    }
    cout << ans * k + l + L << endl;
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