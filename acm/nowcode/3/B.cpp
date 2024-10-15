#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}

void solve()
{
    int n, d;
    cin >> n >> d;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int min_gcd = arr[0];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            min_gcd = min(min_gcd, gcd(arr[i], arr[j]));
        }
    }
    int ans = d % min_gcd;
    cout << min(ans, min_gcd - ans) << endl;
}

signed main()
{
    ios
    solve();
}