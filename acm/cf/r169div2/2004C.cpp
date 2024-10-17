#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define pii pair<int, int>
#define umap unordered_map
#define uset unordered_set
#define mod 998244353
#define mod7 1e9 + 7
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>());
    int ans = 0;
    int turn = 1;
    for (int i = 0; i < n - n % 2; i++)
    {
       ans += turn * arr[i];
       turn *= -1;
    }
    if (ans - k < 0)
    {
        ans = 0;
    }
    else {
        ans -= k;
    }
    if (n % 2)
    {
        ans += arr.back();
    }
    cout << ans << endl;
}

signed main()
{
    ios
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}